/**************************************************************************//**
*
* @copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
*
* SPDX-License-Identifier: Apache-2.0
*
* Change Logs:
* Date            Author       Notes
* 2023-04-26      Wayne        First version
*
******************************************************************************/

#include <rtconfig.h>

#if defined(BSP_USING_VDE)
#include "rtdevice.h"

#include "drv_common.h"

#define DBG_ENABLE
#define DBG_LEVEL DBG_LOG
#define DBG_SECTION_NAME  "vde"
#define DBG_COLOR
#include <rtdbg.h>

#include "vc8000_lib.h"

#define DEF_VDE_BUFFER_SIZE    0x4000000

static int rt_hw_vde_init(void)
{
    int ret;

    void *pvVDEBuf = rt_malloc_align(DEF_VDE_BUFFER_SIZE, 4096);
    if (pvVDEBuf == RT_NULL)
    {
        LOG_E("Failed to allocate memory.");
        return -RT_ERROR;
    }

    nu_sys_ip_reset(VDEC_RST);

    ret = VC8000_DrvInit((uint32_t)pvVDEBuf, DEF_VDE_BUFFER_SIZE);
    if (ret < 0)
    {
        LOG_E("VC8000_DrvInit failed! (%d)", ret);
        return -RT_ERROR;
    }

    LOG_I("VDE working buffer@0x%08x, length: %d", pvVDEBuf, DEF_VDE_BUFFER_SIZE);

    return RT_EOK;
}
INIT_DEVICE_EXPORT(rt_hw_vde_init);

#endif //#if defined(BSP_USING_VDE)
