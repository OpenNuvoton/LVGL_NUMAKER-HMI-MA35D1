/**************************************************************************//**
*
* @copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
*
* SPDX-License-Identifier: Apache-2.0
*
* Change Logs:
* Date            Author           Notes
* 2021-07-14      Wayne            First version
*
******************************************************************************/

#include <rtthread.h>

#if defined(USE_MA35D1_AARCH64)

#include <rthw.h>
#include <stdio.h>

#include <mmu.h>
#include <psci.h>
#include <gicv3.h>
#include <gtimer.h>
#include <cpuport.h>
#include <interrupt.h>

#include "drv_common.h"
#include "board.h"
#include "drv_uart.h"
#include "drv_sspcc.h"
#include "drv_ssmcc.h"
#include "drv_umctl2.h"

#define LOG_TAG    "drv.common"
#undef  DBG_ENABLE
#define DBG_SECTION_NAME   LOG_TAG
#define DBG_LEVEL      LOG_LVL_DBG
#define DBG_COLOR
#include <rtdbg.h>

#define NORMAL_MEM_UNCACHED        (SHARED|AP_RW|DOMAIN0|STRONGORDER|DESC_SEC)

#define IRQ_ARM_IPI_KICK    0
#define IRQ_ARM_IPI_CALL    1

/*
MMU TLB setting:
0xFFFFFFFF  ----------------------------
            |  1GB DDR(non-cacheable)  |
0xC0000000  ----------------------------
            |    1GB DDR(cacheable)    |
0x80000000  ----------------------------
            |      DEVICE_MEM          |
            |                          |
0x00000000  ----------------------------
*/
struct mem_desc platform_mem_desc[] =
{
    {0x00000000,   0x7FFFFFFF, 0x00000000, DEVICE_MEM},          // Peripherals
    {0x80000000,   DDR_LIMIT_SIZE - 1, 0x80000000, NORMAL_MEM},  // 1GB DDR, cacheable
};
const rt_uint32_t platform_mem_desc_size = sizeof(platform_mem_desc) / sizeof(platform_mem_desc[0]);

extern void nu_clock_dump(void);
extern void nu_clock_raise(void);
extern void nu_clock_init(void);

#if 0
void rt_hw_us_delay(rt_uint32_t us)
{
    rt_uint32_t ticks;
    volatile rt_uint32_t told, tnow, tcnt = 0;
    rt_uint32_t cmp = timerStep;    // 12000 count / 1ms

    ticks = us * (cmp / 1000);      // us * 12(count/1us)
    told = gtimer_get_current_value();

    while (1)
    {
        /* Timer counter is increment. */
        tnow = gtimer_get_current_value();
        if (tnow != told)
        {
            /* 0 -- now === old -------- cmp */
            if (tnow < told)
            {
                tcnt += (told - tnow);
            }
            else
            {
                /* 0 == old --- new ======== cmp */
                tcnt += (cmp - tnow + told);
            }
            told = tnow;

            /* Timeout */
            if (tcnt >= ticks)
            {
                break;
            }
        }
        __NOP();
    }
} /* rt_hw_us_delay */
#endif

void idle_wfi(void)
{
    asm volatile("wfi");
}

RT_WEAK void nutool_pincfg_init(void)
{
}

/**
 * This function will initial board.
 */
RT_WEAK void rt_hw_board_init(void)
{
    /* Unlock protected registers */
    //SYS_UnlockReg();

    /* initialize SSPCC */
    //nu_sspcc_init();

    /* initialize SSMCC */
    //nu_ssmcc_init();

    /* initialize UMCTL2 */
    //nu_umctl2_init();

    /* initialize base clock */
    nu_clock_init();

    /* initialize peripheral pin function */
    nutool_pincfg_init();

    /* initialize hardware interrupt */
    rt_hw_interrupt_init();

    /* initialize MMU */
    rt_hw_init_mmu_table(platform_mem_desc, platform_mem_desc_size);
    rt_hw_mmu_init();

    arm_psci_init(PSCI_METHOD_SMC, RT_NULL, RT_NULL);

#if defined(RT_USING_HEAP)
    rt_system_heap_init((void *)BOARD_HEAP_START, (void *)BOARD_HEAP_END);
#endif

    /* initialize uart */
    rt_hw_uart_init();

#if defined(RT_USING_CONSOLE)
    rt_console_set_device(RT_CONSOLE_DEVICE_NAME);
#endif

    //TOFIX
    //nu_clock_raise();

#if defined(RT_USING_HEAP)
    /* Dump heap information */
    rt_kprintf("Heap: Begin@%08x, END@%08x, SIZE: %d KiB\n", BOARD_HEAP_START, BOARD_HEAP_END, ((rt_uint32_t)BOARD_HEAP_END - (rt_uint32_t)BOARD_HEAP_START) / 1024);
#endif

    /* initialize timer for os tick */
    rt_hw_gtimer_init();
    rt_thread_idle_sethook(idle_wfi);

#if defined(RT_USING_COMPONENTS_INIT)
    rt_components_board_init();
#endif

    nu_chipcfg_dump();
    nu_clock_dump();

#ifdef RT_USING_SMP
    /* install IPI handle */
    rt_hw_ipi_handler_install(RT_SCHEDULE_IPI, rt_scheduler_ipi_handler);
    arm_gic_umask(0, IRQ_ARM_IPI_KICK);
#endif
}

#if defined(RT_USING_SMP)
void rt_hw_secondary_cpu_up(void)
{
    int i;
    extern void secondary_cpu_start(void);
    extern rt_uint64_t rt_cpu_mpidr_early[];

    for (i = 1; i < RT_CPUS_NR; ++i)
    {
        arm_psci_cpu_on(rt_cpu_mpidr_early[i], (uint64_t)(secondary_cpu_start));
    }
}

void secondary_cpu_c_start(void)
{
    rt_hw_mmu_init();
    rt_hw_spin_lock(&_cpus_lock);

    arm_gic_cpu_init(0, platform_get_gic_cpu_base());
    rt_hw_vector_init();
    rt_hw_gtimer_local_enable();
    arm_gic_umask(0, IRQ_ARM_IPI_KICK);

    rt_kprintf("\rcall cpu %d on success\n", rt_hw_cpu_id());

    rt_system_scheduler_start();
}

void rt_hw_secondary_cpu_idle_exec(void)
{
    __WFE();
}
#endif

#endif /* #if defined(USE_MA35D1_AARCH64) */
