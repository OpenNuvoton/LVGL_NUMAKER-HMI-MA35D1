/**************************************************************************//**
*
* @copyright (C) 2019 Nuvoton Technology Corp. All rights reserved.
*
* SPDX-License-Identifier: Apache-2.0
*
* Change Logs:
* Date            Author       Notes
* 2022-9-19       Wayne        First version
*
******************************************************************************/

#include <rtthread.h>

#if defined(RT_USING_CAN)

#include "rtdevice.h"

#define DBG_TAG  "canutil"
#define DBG_LVL DBG_INFO
#include <rtdbg.h>

#include <stdlib.h>
#include <string.h>

static struct rt_semaphore rx_sem;
static rt_err_t canutils_msg_rx_cb(rt_device_t dev, rt_size_t size)
{
    rt_sem_release(&rx_sem);

    return RT_EOK;
}

static void canutils_worker(void *parameter)
{
    int i;
    rt_err_t res;
    rt_device_t dev = (rt_device_t)parameter;

    rt_sem_init(&rx_sem, "rx_sem", 0, RT_IPC_FLAG_FIFO);

    res = rt_device_control(dev, RT_CAN_CMD_SET_BAUD, (void *)CAN500kBaud);
    RT_ASSERT(res == RT_EOK);

    res = rt_device_control(dev, RT_CAN_CMD_SET_MODE, (void *)RT_CAN_MODE_NORMAL);
    RT_ASSERT(res == RT_EOK);

    rt_device_set_rx_indicate(dev, canutils_msg_rx_cb);

#ifdef RT_CAN_USING_HDR
    struct rt_can_filter_item items[5] =
    {
        RT_CAN_FILTER_ITEM_INIT(0x100, 0, 0, 1, 0x700, RT_NULL, RT_NULL),
        RT_CAN_FILTER_ITEM_INIT(0x300, 0, 0, 1, 0x700, RT_NULL, RT_NULL),
        RT_CAN_FILTER_ITEM_INIT(0x211, 0, 0, 1, 0x7ff, RT_NULL, RT_NULL),
        RT_CAN_FILTER_STD_INIT(0x486, RT_NULL, RT_NULL),
        {0x555, 0, 0, 1, 0x7ff, 7,}
    };
    struct rt_can_filter_config cfg = {5, 1, items};

    res = rt_device_control(dev, RT_CAN_CMD_SET_FILTER, &cfg);
    RT_ASSERT(res == RT_EOK);
#endif

    while (1)
    {
        struct rt_can_msg rxmsg = {0};
        rxmsg.hdr_index  = -1;

        if (rt_sem_take(&rx_sem, RT_WAITING_FOREVER) != RT_EOK)
            continue;

        if (rt_device_read(dev, 0, &rxmsg, sizeof(rxmsg)) == sizeof(rxmsg))
        {
            rt_kprintf("[%s]ID:%02x Data:", dev->parent.name, rxmsg.id);
            for (i = 0; i < 8; i++)
            {
                rt_kprintf("%02x ", rxmsg.data[i]);
            }
            rt_kprintf("\n");
        }
    }

}

static rt_thread_t canutils_worker_new(rt_device_t dev)
{
    rt_thread_t thread = rt_thread_create("can_rx", canutils_worker, (void *)dev, 2048, 25, 10);
    if (thread != RT_NULL)
    {
        rt_thread_startup(thread);
        rt_kprintf("create can_rx thread ok!\n");
    }
    else
    {
        rt_kprintf("create can_rx thread failed!\n");
    }

    return thread;
}

static int canutils_sendmsg(rt_device_t dev, int msg_size)
{
    int i;

    for (i = 0; i < msg_size; i++)
    {
        struct rt_can_msg msg;
        int ret;

        msg.id = (0x78 + i) % 0x800;
        msg.ide = RT_CAN_STDID;
        msg.rtr = RT_CAN_DTR;
        msg.len = 8;

        msg.data[0] = 0x00;
        msg.data[1] = 0x11;
        msg.data[2] = 0x22;
        msg.data[3] = 0x33;
        msg.data[4] = 0x44;
        msg.data[5] = 0x55;
        msg.data[6] = 0x66;
        msg.data[7] = 0x77;

        if ((ret = rt_device_write(dev, 0, &msg, sizeof(msg))) != sizeof(msg))
        {
            rt_kprintf("[%s][%d] send failure! %d\n", dev->parent.name , i, ret);
        }
        else
        {
            rt_kprintf("[%s][%d] send success!\n", dev->parent.name, i);
        }
    }

    return i;
}

static void canutils(int argc, char **argv)
{
    static rt_device_t dev = RT_NULL;
    static rt_thread_t thread = RT_NULL;

    /* If the number of arguments less than 2 */
    if (argc < 2)
    {
        rt_kprintf("\n");
        rt_kprintf("can     [OPTION] [PARAM]\n");
        rt_kprintf("         probe <dev_name>      Probe sensor by given name\n");
        rt_kprintf("         send                  Read [num] times sensor (default 5)\n");
        return ;
    }
    else if (!strcmp(argv[1], "send"))
    {
        rt_uint16_t num = 1;

        if (dev == RT_NULL)
        {
            LOG_W("Please probe sensor device first!");
            return ;
        }

        if (argc == 3)
        {
            num = atoi(argv[2]);
        }

        canutils_sendmsg(dev, num);
    }
    else if (argc == 3)
    {
        if (!strcmp(argv[1], "probe"))
        {
            rt_device_t new_dev;
            rt_thread_t new_thread;

            new_dev = rt_device_find(argv[2]);
            if (new_dev == RT_NULL)
            {
                LOG_E("Can't find device:%s", argv[2]);
                return;
            }

            if (rt_device_open(new_dev, RT_DEVICE_FLAG_INT_TX | RT_DEVICE_FLAG_INT_RX) != RT_EOK)
            {
                LOG_E("open device failed!");
                return;
            }

            new_thread = canutils_worker_new(new_dev);

            if (thread)
            {
                // Suspend thread;
            }
            thread = new_thread;

            if (dev)
            {
                rt_device_close(dev);
            }
            dev = new_dev;
        }
        else if (dev == RT_NULL)
        {
            LOG_W("Please probe can device first!");
            return ;
        }
    }
    else
    {
        LOG_W("Unknown command, please enter 'canutils' get help information!");
    }

}
#ifdef RT_USING_FINSH
    MSH_CMD_EXPORT(canutils, can test function);
#endif

#endif
