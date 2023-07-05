/**************************************************************************//**
*
* @copyright (C) 2019 Nuvoton Technology Corp. All rights reserved.
*
* SPDX-License-Identifier: Apache-2.0
*
* Change Logs:
* Date            Author       Notes
* 2022-8-16       Wayne        First version
*
******************************************************************************/

#include <rtthread.h>

#if defined(BSP_USING_CCAP)

#include "drv_ccap.h"
#include "ccap_demo.h"
#include <dfs_posix.h>

#define DBG_ENABLE
#define DBG_LEVEL DBG_LOG
#define DBG_SECTION_NAME  "ccap.demo"
#define DBG_COLOR
#include <rtdbg.h>

#define THREAD_PRIORITY   5
#define THREAD_STACK_SIZE 4096
#define THREAD_TIMESLICE  5

#define DEF_CROP_PACKET_RECT

#define DEF_DURATION         10
#if defined(BSP_USING_CCAP0) && defined(BSP_USING_CCAP1)
    #define DEF_GRID_VIEW          1
    #define DEF_BINARIZATION_VIEW  DEF_GRID_VIEW
#elif defined(BSP_USING_CCAP0) || defined(BSP_USING_CCAP1)
    #define DEF_GRID_VIEW          0
    #define DEF_BINARIZATION_VIEW  DEF_GRID_VIEW
#endif

#define DEF_ENABLE_PLANAR_PIPE  DEF_BINARIZATION_VIEW

typedef struct
{
    char *thread_name;
    char *devname_ccap;
    char *devname_sensor;
    char *devname_lcd;

    uint32_t ccap_binarization;
    uint32_t ccap_y_threshold;

    ccap_view_info_t ccap_viewinfo_planar;
    ccap_view_info_t ccap_viewinfo_packet;
    ccap_view_info_t ccap_viewinfo_binarization;
} ccap_grabber_param;
typedef ccap_grabber_param *ccap_grabber_param_t;

typedef struct
{
    ccap_config    sCcapConfig;
    struct rt_device_graphic_info sLcdInfo;
    uint32_t       u32CurFBPointer;
    uint32_t       u32FrameEnd;
    rt_sem_t       semFrameEnd;
    ccap_view_info viewinfo_binarization;

} ccap_grabber_context;
typedef ccap_grabber_context *ccap_grabber_context_t;

static ccap_grabber_param ccap_grabber_param_array[evCCAP_Cnt] =
{
#if defined(BSP_USING_CCAP0)
    {
        .thread_name = "grab0",
        .devname_ccap = "ccap0",
        .devname_sensor = "sensor0",
        .devname_lcd = "lcd",
        .ccap_y_threshold = 128,
        .ccap_binarization = 1
    }
#endif
#if defined(BSP_USING_CCAP1)
    , {
        .thread_name = "grab1",
        .devname_ccap = "ccap1",
        .devname_sensor = "sensor1",
        .devname_lcd = "lcd",
        .ccap_y_threshold = 128,
        .ccap_binarization = 1
    }
#endif
};
static uint32_t s_u32LCDToggle = 0;

static void nu_ccap_event_hook(void *pvData, uint32_t u32EvtMask)
{
    ccap_grabber_context_t psGrabberContext = (ccap_grabber_context_t)pvData;

    if (u32EvtMask & NU_CCAP_FRAME_END)
    {
        rt_sem_release(psGrabberContext->semFrameEnd);
    }

    if (u32EvtMask & NU_CCAP_ADDRESS_MATCH)
    {
        LOG_I("Address matched");
    }

    if (u32EvtMask & NU_CCAP_MEMORY_ERROR)
    {
        LOG_E("Access memory error");
    }
}

static rt_device_t ccap_sensor_init(ccap_grabber_context_t psGrabberContext, ccap_grabber_param_t psGrabberParam)
{
    rt_err_t ret;
    ccap_view_info_t psViewInfo;
    sensor_mode_info *psSensorModeInfo;
    rt_device_t psDevSensor = RT_NULL;
    rt_device_t psDevCcap = RT_NULL;
    struct rt_device_graphic_info *psLcdInfo = &psGrabberContext->sLcdInfo;
    ccap_config_t    psCcapConfig = &psGrabberContext->sCcapConfig;

    psDevCcap = rt_device_find(psGrabberParam->devname_ccap);
    if (psDevCcap == RT_NULL)
    {
        LOG_E("Can't find %s", psGrabberParam->devname_ccap);
        goto exit_ccap_sensor_init;
    }

    psDevSensor = rt_device_find(psGrabberParam->devname_sensor);
    if (psDevSensor == RT_NULL)
    {
        LOG_E("Can't find %s", psGrabberParam->devname_sensor);
        goto exit_ccap_sensor_init;
    }

    /* Packet pipe for preview */
    if (DEF_GRID_VIEW)
    {
        psCcapConfig->sPipeInfo_Packet.u32Width    = psLcdInfo->width / 2;
        psCcapConfig->sPipeInfo_Packet.u32Height   = psLcdInfo->height / 2;
        psCcapConfig->sPipeInfo_Packet.u32PixFmt   = (psLcdInfo->pixel_format == RTGRAPHIC_PIXEL_FORMAT_RGB565) ? CCAP_PAR_OUTFMT_RGB565 : 0;
        psCcapConfig->u32Stride_Packet             = psLcdInfo->width;
        if (!rt_strcmp(psGrabberParam->devname_ccap, "ccap1"))
            psCcapConfig->sPipeInfo_Packet.pu8FarmAddr = psLcdInfo->framebuffer + (psCcapConfig->sPipeInfo_Packet.u32Width * 2);
        else
            psCcapConfig->sPipeInfo_Packet.pu8FarmAddr = psLcdInfo->framebuffer;
    }
    else
    {
        psCcapConfig->sPipeInfo_Packet.pu8FarmAddr = psLcdInfo->framebuffer;
        psCcapConfig->sPipeInfo_Packet.u32Height   = psLcdInfo->height;
        psCcapConfig->sPipeInfo_Packet.u32Width    = psLcdInfo->width;
        psCcapConfig->sPipeInfo_Packet.u32PixFmt   = (psLcdInfo->pixel_format == RTGRAPHIC_PIXEL_FORMAT_RGB565) ? CCAP_PAR_OUTFMT_RGB565 : 0;
        psCcapConfig->u32Stride_Packet             = psLcdInfo->width;
    }

    /* Planar pipe for encoding */
#if DEF_ENABLE_PLANAR_PIPE
    psCcapConfig->sPipeInfo_Planar.u32Width    = psLcdInfo->width / 2;
    psCcapConfig->sPipeInfo_Planar.u32Height   = psLcdInfo->height / 2;
    psCcapConfig->sPipeInfo_Planar.pu8FarmAddr = rt_malloc_align(psCcapConfig->sPipeInfo_Planar.u32Height * psCcapConfig->sPipeInfo_Planar.u32Width * 2, 32);
    psCcapConfig->sPipeInfo_Planar.u32PixFmt   = CCAP_PAR_PLNFMT_YUV420; //CCAP_PAR_PLNFMT_YUV422;
    psCcapConfig->u32Stride_Planar             = psCcapConfig->sPipeInfo_Planar.u32Width;

    if (psCcapConfig->sPipeInfo_Planar.pu8FarmAddr == RT_NULL)
    {
        psCcapConfig->sPipeInfo_Planar.u32Height = 0;
        psCcapConfig->sPipeInfo_Planar.u32Width  = 0;
        psCcapConfig->sPipeInfo_Planar.u32PixFmt = 0;
        psCcapConfig->u32Stride_Planar           = 0;
    }

    LOG_I("Planar.FarmAddr@0x%08X", psCcapConfig->sPipeInfo_Planar.pu8FarmAddr);
    LOG_I("Planar.FarmWidth: %d", psCcapConfig->sPipeInfo_Planar.u32Width);
    LOG_I("Planar.FarmHeight: %d", psCcapConfig->sPipeInfo_Planar.u32Height);
#endif

    /* open CCAP */
    ret = rt_device_open(psDevCcap, 0);
    if (ret != RT_EOK)
    {
        LOG_E("Can't open %s", psGrabberParam->devname_ccap);
        goto exit_ccap_sensor_init;
    }

    /* Find suit mode for packet pipe */
    if (psCcapConfig->sPipeInfo_Packet.pu8FarmAddr != RT_NULL)
    {
        /* Check view window of packet pipe */
        psViewInfo = &psCcapConfig->sPipeInfo_Packet;

        if ((rt_device_control(psDevSensor, CCAP_SENSOR_CMD_GET_SUIT_MODE, (void *)&psViewInfo) != RT_EOK)
                || (psViewInfo == RT_NULL))
        {
            LOG_E("Can't get suit mode for packet.");
            goto fail_ccap_init;
        }
    }

    /* Find suit mode for planner pipe */
    if (psCcapConfig->sPipeInfo_Planar.pu8FarmAddr != RT_NULL)
    {
        int recheck = 1;

        if (psViewInfo != RT_NULL)
        {
            if ((psCcapConfig->sPipeInfo_Planar.u32Width <= psViewInfo->u32Width) ||
                    (psCcapConfig->sPipeInfo_Planar.u32Height <= psViewInfo->u32Height))
                recheck = 0;
        }

        if (recheck)
        {
            /* Check view window of planner pipe */
            psViewInfo = &psCcapConfig->sPipeInfo_Planar;

            /* Find suit mode */
            if ((rt_device_control(psDevSensor, CCAP_SENSOR_CMD_GET_SUIT_MODE, (void *)&psViewInfo) != RT_EOK)
                    || (psViewInfo == RT_NULL))
            {
                LOG_E("Can't get suit mode for planner.");
                goto exit_ccap_sensor_init;
            }
        }
    }

#if defined(DEF_CROP_PACKET_RECT)
    /* Set cropping rectangle */
    if (psViewInfo->u32Width >= psCcapConfig->sPipeInfo_Packet.u32Width)
    {
        /* sensor.width >= preview.width */
        psCcapConfig->sRectCropping.x = (psViewInfo->u32Width - psCcapConfig->sPipeInfo_Packet.u32Width) / 2;
        psCcapConfig->sRectCropping.width  = psCcapConfig->sPipeInfo_Packet.u32Width;
    }
    else
    {
        /* sensor.width < preview.width */
        psCcapConfig->sRectCropping.x = 0;
        psCcapConfig->sRectCropping.width  = psViewInfo->u32Width;
    }

    if (psViewInfo->u32Height >= psCcapConfig->sPipeInfo_Packet.u32Height)
    {
        /* sensor.height >= preview.height */
        psCcapConfig->sRectCropping.y = (psViewInfo->u32Height - psCcapConfig->sPipeInfo_Packet.u32Height) / 2;
        psCcapConfig->sRectCropping.height = psCcapConfig->sPipeInfo_Packet.u32Height;
    }
    else
    {
        /* sensor.height < preview.height */
        psCcapConfig->sRectCropping.y = 0;
        psCcapConfig->sRectCropping.height = psViewInfo->u32Height;
    }
#else
    /* Set cropping rectangle */
    psCcapConfig->sRectCropping.x      = 0;
    psCcapConfig->sRectCropping.y      = 0;
    psCcapConfig->sRectCropping.width  = psViewInfo->u32Width;
    psCcapConfig->sRectCropping.height = psViewInfo->u32Height;
#endif

    /* ISR Hook */
    psCcapConfig->pfnEvHndler = nu_ccap_event_hook;
    psCcapConfig->pvData      = (void *)psGrabberContext;

    /* Get Suitable mode. */
    psSensorModeInfo = (sensor_mode_info *)psViewInfo;

    /* Feed CCAP configuration */
    ret = rt_device_control(psDevCcap, CCAP_CMD_CONFIG, (void *)psCcapConfig);
    if (ret != RT_EOK)
    {
        LOG_E("Can't feed configuration %s", psGrabberParam->devname_ccap);
        goto fail_ccap_init;
    }

    {
        int i32SenClk = psSensorModeInfo->u32SenClk;
        if (DEF_GRID_VIEW && DEF_ENABLE_PLANAR_PIPE)
            i32SenClk = 45000000; /* Bandwidth limitation: Slow down sensor clock */

        /* speed up pixel clock */
        if (rt_device_control(psDevCcap, CCAP_CMD_SET_SENCLK, (void *)&i32SenClk) != RT_EOK)
        {
            LOG_E("Can't feed setting.");
            goto fail_ccap_init;
        }
    }

    /* Initial CCAP sensor */
    if (rt_device_open(psDevSensor, 0) != RT_EOK)
    {
        LOG_E("Can't open sensor.");
        goto fail_sensor_init;
    }

    /* Feed settings to sensor */
    if (rt_device_control(psDevSensor, CCAP_SENSOR_CMD_SET_MODE, (void *)psSensorModeInfo) != RT_EOK)
    {
        LOG_E("Can't feed setting.");
        goto fail_sensor_init;
    }

    ret = rt_device_control(psDevCcap, CCAP_CMD_SET_PIPES, (void *)psViewInfo);
    if (ret != RT_EOK)
    {
        LOG_E("Can't set pipes %s", psGrabberParam->devname_ccap);
        goto fail_ccap_init;
    }

    return psDevCcap;

fail_sensor_init:

    if (psDevSensor)
        rt_device_close(psDevSensor);

fail_ccap_init:

    if (psDevCcap)
        rt_device_close(psDevCcap);

exit_ccap_sensor_init:

    psDevCcap = psDevSensor = RT_NULL;

    return psDevCcap;
}

static void ccap_sensor_fini(rt_device_t psDevCcap, rt_device_t psDevSensor)
{
    if (psDevSensor)
        rt_device_close(psDevSensor);

    if (psDevCcap)
        rt_device_close(psDevCcap);
}

#if DEF_BINARIZATION_VIEW
/* Software rendering. */
static void ccap_binarization_draw(rt_device_t psDevCcap, ccap_grabber_context_t psGrabberContext, uint32_t u32Thd)
{
    rt_err_t ret;
    ccap_bin_config sBinConf;

    rt_memcpy(&sBinConf.sPipeInfo_Src, &psGrabberContext->sCcapConfig.sPipeInfo_Planar, sizeof(ccap_view_info));
    rt_memcpy(&sBinConf.sPipeInfo_Dst, &psGrabberContext->sCcapConfig.sPipeInfo_Packet, sizeof(ccap_view_info));
    sBinConf.sPipeInfo_Dst.pu8FarmAddr = psGrabberContext->sCcapConfig.sPipeInfo_Packet.pu8FarmAddr +
                                         psGrabberContext->sCcapConfig.u32Stride_Packet *
                                         psGrabberContext->sCcapConfig.sPipeInfo_Packet.u32Height * 2;
    sBinConf.u32Threshold = u32Thd;
    sBinConf.u32Stride_Dst = psGrabberContext->sCcapConfig.u32Stride_Packet;

    ret = rt_device_control(psDevCcap, CCAP_CMD_BINARIZATION_FLUSH, &sBinConf);
    if (ret != RT_EOK)
    {
        LOG_E("Can't do binarization flush");
    }
}

static ccap_view_info_t ccap_binarization_update(rt_device_t psDevCcap, ccap_view_info_t bin, ccap_view_info_t planar, uint32_t u32Thd)
{
    rt_err_t ret;
    ccap_bin_config sBinConf;

    bin->u32Width = planar->u32Width;
    bin->u32Height = planar->u32Height;
    bin->u32PixFmt = CCAP_PAR_OUTFMT_ONLY_Y;

    rt_memcpy(&sBinConf.sPipeInfo_Src, planar, sizeof(ccap_view_info));
    rt_memcpy(&sBinConf.sPipeInfo_Dst, bin, sizeof(ccap_view_info));
    sBinConf.u32Threshold = u32Thd;
    sBinConf.u32Stride_Dst = bin->u32Width;

    ret = rt_device_control(psDevCcap, CCAP_CMD_BINARIZATION_FLUSH, &sBinConf);
    if (ret != RT_EOK)
    {
        LOG_E("Can't do binarization flush");
    }

    return bin;
}

ccap_view_info_t ccap_get_binarization(E_CCAP_INDEX evCCAPIdx)
{
    if (evCCAP_Cnt < 0 || evCCAPIdx >= evCCAP_Cnt)
        return RT_NULL;

    return ccap_grabber_param_array[evCCAPIdx].ccap_viewinfo_binarization;
}

int ccap_set_y_threshold(E_CCAP_INDEX evCCAPIdx, int i32YThd)
{
    if (evCCAP_Cnt < 0 || evCCAPIdx >= evCCAP_Cnt)
        return -1;

    if ((i32YThd >= 0) && (i32YThd < 256))
    {
        ccap_grabber_param_array[evCCAPIdx].ccap_y_threshold = i32YThd & 0xFF;
        return 0;
    }

    return -2;
}

int ccap_enable_binarization(E_CCAP_INDEX evCCAPIdx, int bOnOff)
{
    if (evCCAP_Cnt < 0 || evCCAPIdx >= evCCAP_Cnt)
        return -1;

    ccap_grabber_param_array[evCCAPIdx].ccap_binarization = (bOnOff > 0) ? 1 : 0;

    return 0;
}

// 0: Line offset=0, others: Line offset=LCDHeight/2
int ccap_lcd_toggle(uint32_t u32LCDToggle)
{
    s_u32LCDToggle = (u32LCDToggle > 0) ? 1 : 0;
    return s_u32LCDToggle;
}

int ccap_binarization_config(int argc, char *argv[])
{
// argc=1: thd value
    int index, y_thd, b_onoff, lcd_toggle;
    if (argc != 5)
    {
        rt_kprintf("ccap_binarization_config <E_CCAP_INDEX> <y_threshold> <bOnOff> <toggle>\n");
        return -1;
    }

    index   = atoi(argv[1]);
    y_thd   = atoi(argv[2]);
    b_onoff = atoi(argv[3]);
    lcd_toggle = atoi(argv[4]);

    ccap_set_y_threshold(index, y_thd);
    ccap_enable_binarization(index, b_onoff);
    ccap_lcd_toggle(lcd_toggle);

    return 0;
}
MSH_CMD_EXPORT(ccap_binarization_config, config binarization);

#endif


#if ( DEF_ENABLE_PLANAR_PIPE )
static int ccap_save_file(char *filepath, const void *data, size_t size)
{
    int fd;
    int wrote_size = 0;

    if (!size || !data)
        return -1;

    fd = open(filepath, O_WRONLY | O_CREAT);
    if (fd < 0)
    {
        LOG_E("Could not open %s for writing.", filepath);
        goto exit_ccap_save_file;
    }

    if ((wrote_size = write(fd, data, size)) != size)
    {
        LOG_E("Could not write to %s (%d != %d).", filepath, wrote_size, size);
        goto exit_ccap_save_file;
    }

    wrote_size = size;

exit_ccap_save_file:

    if (fd >= 0)
        close(fd);

    return wrote_size;
}

int ccap_save_image(E_CCAP_INDEX evCCAPIdx, const char *szSavedFileFolderPath, E_SAVE_PIPE evSavePipe)
{
    char szFilename[128];
    ccap_view_info_t psCCAPViewInfo;
    int  filesize = 0;

    if (evCCAP_Cnt < 0 || evCCAPIdx >= evCCAP_Cnt)
        return -1;

    switch (evSavePipe)
    {
    case evSP_BINARIZATION:
    {
        psCCAPViewInfo = ccap_grabber_param_array[evCCAPIdx].ccap_viewinfo_binarization;

        rt_snprintf(szFilename, sizeof(szFilename), "/%s/%08d_binarization.bin", szSavedFileFolderPath, rt_tick_get());
        filesize = psCCAPViewInfo->u32Width * psCCAPViewInfo->u32Height;
    }
    break;

    case evSP_PACKET:
    {
        psCCAPViewInfo = ccap_grabber_param_array[evCCAPIdx].ccap_viewinfo_packet;
        filesize = psCCAPViewInfo->u32Width * psCCAPViewInfo->u32Height * 2;

        switch (psCCAPViewInfo->u32PixFmt)
        {
        case CCAP_PAR_OUTFMT_ONLY_Y:
            filesize = psCCAPViewInfo->u32Width * psCCAPViewInfo->u32Height;
            rt_snprintf(szFilename, sizeof(szFilename), "/%s/%08d_only_y.bin", szSavedFileFolderPath, rt_tick_get());
            break;

        case CCAP_PAR_OUTFMT_RGB555:
            rt_snprintf(szFilename, sizeof(szFilename), "/%s/%08d_rgb555.bin", szSavedFileFolderPath, rt_tick_get());
            break;

        case CCAP_PAR_OUTFMT_RGB565:
            rt_snprintf(szFilename, sizeof(szFilename), "/%s/%08d_rgb565.bin", szSavedFileFolderPath, rt_tick_get());
            break;

        case CCAP_PAR_OUTFMT_YUV422:
            rt_snprintf(szFilename, sizeof(szFilename), "/%s/%08d_yuv422.bin", szSavedFileFolderPath, rt_tick_get());
            break;

        default:
            return -1;
        }
    }
    break;

    case evSP_PLANAR:
    {
        uint32_t u32Factor = 0;
        psCCAPViewInfo = ccap_grabber_param_array[evCCAPIdx].ccap_viewinfo_planar;

        switch (psCCAPViewInfo->u32PixFmt)
        {
        case CCAP_PAR_PLNFMT_YUV420:
        {
            u32Factor = 3;
            rt_snprintf(szFilename, sizeof(szFilename), "/%s/%08d_yuv420p.bin", szSavedFileFolderPath, rt_tick_get());
        }
        break;

        case CCAP_PAR_PLNFMT_YUV422:
        {
            u32Factor = 4;
            rt_snprintf(szFilename, sizeof(szFilename), "/%s/%08d_yuv422p.bin", szSavedFileFolderPath, rt_tick_get());
        }
        break;

        default:
            return -1;
        }

        filesize = psCCAPViewInfo->u32Width * psCCAPViewInfo->u32Height * u32Factor / 2;
    }
    break;

    default:
        return -1;
    }

    rt_kprintf("Will write %s %d @%08x\n", szFilename, filesize, psCCAPViewInfo->pu8FarmAddr);

    return ccap_save_file(szFilename,
                          (const void *)psCCAPViewInfo->pu8FarmAddr,
                          filesize);
}

int ccap_save_image_test(void)
{
#if defined(BSP_USING_CCAP0)
    ccap_save_image(evCCAP0, "/", evSP_BINARIZATION);
    ccap_save_image(evCCAP0, "/", evSP_PACKET);
    ccap_save_image(evCCAP0, "/", evSP_PLANAR);
#endif
#if defined(BSP_USING_CCAP1)
    ccap_save_image(evCCAP1, "/", evSP_BINARIZATION);
    ccap_save_image(evCCAP1, "/", evSP_PACKET);
    ccap_save_image(evCCAP1, "/", evSP_PLANAR);
#endif

    return 0;
}
MSH_CMD_EXPORT(ccap_save_image_test, test ccap_save_image);

#endif

int ccap_sensor_read_register(E_CCAP_INDEX evCCAPIdx, sensor_reg_val_t psSenorRegVal)
{
    rt_device_t dev;

    if (evCCAP_Cnt < 0 || evCCAPIdx >= evCCAP_Cnt)
        return -1;

    dev = rt_device_find(ccap_grabber_param_array[evCCAPIdx].devname_sensor);
    if (!dev || !psSenorRegVal)
    {
        return -2;
    }
    else if (rt_device_control(dev, CCAP_SENSOR_CMD_READ_REG, psSenorRegVal) != RT_EOK)
    {
        return -3;
    }

    return 0;
}

int ccap_sensor_write_register(E_CCAP_INDEX evCCAPIdx, sensor_reg_val_t psSenorRegVal)
{
    rt_device_t dev;

    if (evCCAP_Cnt < 0 || evCCAPIdx >= evCCAP_Cnt)
        return -1;

    dev = rt_device_find(ccap_grabber_param_array[evCCAPIdx].devname_sensor);
    if (!dev || !psSenorRegVal)
    {
        return -2;
    }
    else if (rt_device_control(dev, CCAP_SENSOR_CMD_WRITE_REG, psSenorRegVal) != RT_EOK)
    {
        return -3;
    }

    return 0;
}

int ccap_sensor_set_register(int argc, char *argv[])
{
// argc=1: thd value
    int index, addr, value, mode = 0;

    if (!((argc == 3) || (argc == 4)))
    {
        rt_kprintf("Read: ccap_sensor_register <E_CCAP_INDEX> <addr_in_hex>\n");
        rt_kprintf("Write: ccap_sensor_register <E_CCAP_INDEX> <addr_in_hex> <value_in_hex>\n");
        return -1;
    }

    if (argc == 4)
        mode = 1; //write mode

    if (sscanf(argv[1], "%d", &index) != 1)
        goto exit_ccap_sensor_register;

    if (sscanf(argv[2], "0x%x", &addr) != 1)
        goto exit_ccap_sensor_register;

    if (mode)
    {
        sensor_reg_val sSensorRegVal = {0};

        if (sscanf(argv[3], "0x%x", &value) != 1)
            goto exit_ccap_sensor_register;

        sSensorRegVal.u16Addr = (uint16_t)addr;
        sSensorRegVal.u16Val  = (uint16_t)value;

        if (!ccap_sensor_write_register((E_CCAP_INDEX)index, &sSensorRegVal))
            rt_kprintf("Wrote %04x@%04x!\n", sSensorRegVal.u16Val, addr);
    }
    else
    {
        sensor_reg_val sSensorRegVal = {0};

        sSensorRegVal.u16Addr = (uint16_t)addr;

        if (!ccap_sensor_read_register((E_CCAP_INDEX)index, &sSensorRegVal))
            rt_kprintf("Read %04x@%04x\n", sSensorRegVal.u16Val, addr);
    }

    return 0;

exit_ccap_sensor_register:

    return -1;
}
MSH_CMD_EXPORT(ccap_sensor_set_register, set ccap sensor register);

static void ccap_grabber(void *parameter)
{
    rt_err_t ret;
    ccap_grabber_param_t psGrabberParam = (ccap_grabber_param_t)parameter;
    ccap_grabber_context sGrabberContext;

    rt_device_t psDevCcap = RT_NULL;
    rt_device_t psDevLcd = RT_NULL;

    rt_tick_t last, now;
    rt_bool_t bDrawDirect;

    rt_memset((void *)&sGrabberContext, 0, sizeof(ccap_grabber_context));

    psDevLcd = rt_device_find(psGrabberParam->devname_lcd);
    if (psDevLcd == RT_NULL)
    {
        LOG_E("Can't find %s", psGrabberParam->devname_lcd);
        goto exit_ccap_grabber;
    }

    /* Get LCD Info */
    ret = rt_device_control(psDevLcd, RTGRAPHIC_CTRL_GET_INFO, &sGrabberContext.sLcdInfo);
    if (ret != RT_EOK)
    {
        LOG_E("Can't get LCD info %s", psGrabberParam->devname_lcd);
        goto exit_ccap_grabber;
    }

    /* Check panel type */
    if (rt_device_control(psDevLcd, RTGRAPHIC_CTRL_PAN_DISPLAY, (void *)sGrabberContext.sLcdInfo.framebuffer) == RT_EOK)
    {
        /* Sync-type LCD panel, will draw to VRAM directly. */
        int pixfmt = RTGRAPHIC_PIXEL_FORMAT_RGB565;
        bDrawDirect = RT_TRUE;
        rt_device_control(psDevLcd, RTGRAPHIC_CTRL_SET_MODE, (void *)&pixfmt);
    }
    else
    {
        /* MPU-type LCD panel, draw to shadow RAM, then flush. */
        bDrawDirect = RT_FALSE;
    }

    sGrabberContext.u32CurFBPointer = (uint32_t)sGrabberContext.sLcdInfo.framebuffer;

    ret = rt_device_control(psDevLcd, RTGRAPHIC_CTRL_GET_INFO, &sGrabberContext.sLcdInfo);
    if (ret != RT_EOK)
    {
        LOG_E("Can't get LCD info %s", psGrabberParam->devname_lcd);
        goto exit_ccap_grabber;
    }

    LOG_I("LCD Type: %s-type",   bDrawDirect ? "Sync" : "MPU");
    LOG_I("LCD Width: %d",   sGrabberContext.sLcdInfo.width);
    LOG_I("LCD Height: %d",  sGrabberContext.sLcdInfo.height);
    LOG_I("LCD bpp:%d",   sGrabberContext.sLcdInfo.bits_per_pixel);
    LOG_I("LCD pixel format:%d",   sGrabberContext.sLcdInfo.pixel_format);
    LOG_I("LCD frame buffer@0x%08x",   sGrabberContext.sLcdInfo.framebuffer);
    LOG_I("LCD frame buffer size:%d",   sGrabberContext.sLcdInfo.smem_len);

    sGrabberContext.semFrameEnd = rt_sem_create(psGrabberParam->devname_ccap, 0, RT_IPC_FLAG_FIFO);
    if (sGrabberContext.semFrameEnd == RT_NULL)
    {
        LOG_E("Can't allocate sem resource %s", psGrabberParam->devname_ccap);
        goto exit_ccap_grabber;
    }

    /* initial ccap & sensor*/
    psDevCcap = ccap_sensor_init(&sGrabberContext, psGrabberParam);
    if (psDevCcap == RT_NULL)
    {
        LOG_E("Can't init %s and %s", psGrabberParam->devname_ccap, psGrabberParam->devname_sensor);
        goto exit_ccap_grabber;
    }

    /* Start to capture */
    if (rt_device_control(psDevCcap, CCAP_CMD_START_CAPTURE, RT_NULL) != RT_EOK)
    {
        LOG_E("Can't start %s", psGrabberParam->devname_ccap);
        goto exit_ccap_grabber;
    }

    /* open lcd */
    ret = rt_device_open(psDevLcd, 0);
    if (ret != RT_EOK)
    {
        LOG_E("Can't open %s", psGrabberParam->devname_lcd);
        goto exit_ccap_grabber;
    }

    psGrabberParam->ccap_viewinfo_packet = &sGrabberContext.sCcapConfig.sPipeInfo_Packet;

#if DEF_ENABLE_PLANAR_PIPE
    psGrabberParam->ccap_viewinfo_binarization = &sGrabberContext.viewinfo_binarization;
    psGrabberParam->ccap_viewinfo_planar = &sGrabberContext.sCcapConfig.sPipeInfo_Planar;

    if (psGrabberParam->ccap_viewinfo_binarization->pu8FarmAddr == RT_NULL)
        psGrabberParam->ccap_viewinfo_binarization->pu8FarmAddr = rt_malloc_align(psGrabberParam->ccap_viewinfo_planar->u32Width * psGrabberParam->ccap_viewinfo_planar->u32Height, 32);

    if (psGrabberParam->ccap_viewinfo_binarization->pu8FarmAddr == RT_NULL)
    {
        LOG_E("Can't allocate buffer");
        goto exit_ccap_grabber;
    }
#endif

    last = now = rt_tick_get();
    while (1)
    {
        if (sGrabberContext.semFrameEnd)
        {
            rt_sem_take(sGrabberContext.semFrameEnd, RT_WAITING_FOREVER);
        }

#if DEF_BINARIZATION_VIEW
        {
            static uint32_t u32LastToggle = 0;
            if (s_u32LCDToggle != u32LastToggle)
            {
                uint32_t u32ToggleBufPtr = (uint32_t)sGrabberContext.u32CurFBPointer + s_u32LCDToggle *
                                           ((sGrabberContext.sLcdInfo.width *
                                             sGrabberContext.sLcdInfo.height *
                                             sGrabberContext.sLcdInfo.bits_per_pixel / 8) / 2) ;

                rt_device_control(psDevLcd, RTGRAPHIC_CTRL_PAN_DISPLAY, (void *)u32ToggleBufPtr);

                u32LastToggle = s_u32LCDToggle;
            }

            if (psGrabberParam->ccap_binarization)
            {
                ccap_binarization_draw(psDevCcap, &sGrabberContext, psGrabberParam->ccap_y_threshold);
            }

            {
                ccap_binarization_update(psDevCcap,
                                         psGrabberParam->ccap_viewinfo_binarization,
                                         psGrabberParam->ccap_viewinfo_planar,
                                         psGrabberParam->ccap_y_threshold);
            }

        }
#endif
        if (!bDrawDirect)
        {
            //MPU type
            struct rt_device_rect_info sRectInfo;

            /* Update fullscreen region. */
            sRectInfo.x = 0;
            sRectInfo.y = 0;
            sRectInfo.height = sGrabberContext.sLcdInfo.height;
            sRectInfo.width = sGrabberContext.sLcdInfo.width;

            rt_device_control(psDevLcd, RTGRAPHIC_CTRL_RECT_UPDATE, &sRectInfo);
        }
        else if (!DEF_GRID_VIEW)
        {
            int i32FBSize = sGrabberContext.sLcdInfo.width * sGrabberContext.sLcdInfo.height * (sGrabberContext.sLcdInfo.bits_per_pixel >> 3);
            int i32VRAMPiece = sGrabberContext.sLcdInfo.smem_len / i32FBSize;
            ccap_config sCcapConfig = {0};

            uint32_t u32BufPtr = (uint32_t)sGrabberContext.sCcapConfig.sPipeInfo_Packet.pu8FarmAddr
                                 + (sGrabberContext.u32FrameEnd % i32VRAMPiece) * i32FBSize;

            /* Pan to valid frame address. */
            rt_device_control(psDevLcd, RTGRAPHIC_CTRL_PAN_DISPLAY, (void *)u32BufPtr);

            sCcapConfig.sPipeInfo_Packet.pu8FarmAddr = sGrabberContext.sCcapConfig.sPipeInfo_Packet.pu8FarmAddr
                    + ((sGrabberContext.u32FrameEnd + 1) % i32VRAMPiece) * i32FBSize ;

#if DEF_ENABLE_PLANAR_PIPE
            sCcapConfig.sPipeInfo_Planar.pu8FarmAddr = sGrabberContext.sCcapConfig.sPipeInfo_Planar.pu8FarmAddr;
            sCcapConfig.sPipeInfo_Planar.u32Width = sGrabberContext.sCcapConfig.sPipeInfo_Planar.u32Width;
            sCcapConfig.sPipeInfo_Planar.u32Height = sGrabberContext.sCcapConfig.sPipeInfo_Planar.u32Height;
            sCcapConfig.sPipeInfo_Planar.u32PixFmt = sGrabberContext.sCcapConfig.sPipeInfo_Planar.u32PixFmt;
#endif

            rt_device_control(psDevCcap, CCAP_CMD_SET_BASEADDR, &sCcapConfig);

#if DEF_ENABLE_PLANAR_PIPE
            {
                int OpModeShutter = 1;
                /* One-shot mode, trigger next frame */
                rt_device_control(psDevCcap, CCAP_CMD_SET_OPMODE, &OpModeShutter);
            }
#endif
        }

        sGrabberContext.u32FrameEnd++;

        /* FPS */
        now = rt_tick_get();
        if ((now - last) >= (DEF_DURATION * 1000))
        {
            LOG_I("%s: %d FPS", psGrabberParam->devname_ccap, sGrabberContext.u32FrameEnd / DEF_DURATION);
            sGrabberContext.u32FrameEnd = 0;
            last = now;
        }
    }
exit_ccap_grabber:

    ccap_sensor_fini(rt_device_find(psGrabberParam->devname_ccap), rt_device_find(psGrabberParam->devname_sensor));

    if (psDevLcd != RT_NULL)
        rt_device_close(psDevLcd);

    return;
}

static void ccap_grabber_create(ccap_grabber_param_t psGrabberParam)
{
    rt_thread_t ccap_thread = rt_thread_find(psGrabberParam->thread_name);
    if (ccap_thread == RT_NULL)
    {
        ccap_thread = rt_thread_create(psGrabberParam->thread_name,
                                       ccap_grabber,
                                       psGrabberParam,
                                       THREAD_STACK_SIZE,
                                       THREAD_PRIORITY,
                                       THREAD_TIMESLICE);

        if (ccap_thread != RT_NULL)
            rt_thread_startup(ccap_thread);
    }
}

int ccap_demo(void)
{
#if defined(BSP_USING_CCAP0)
    ccap_grabber_create(&ccap_grabber_param_array[0]);
#endif
#if defined(BSP_USING_CCAP1)
    ccap_grabber_create(&ccap_grabber_param_array[1]);
#endif
    return 0;
}
MSH_CMD_EXPORT(ccap_demo, camera capture demo);
//INIT_ENV_EXPORT(ccap_demo);

#endif // #if defined(BSP_USING_CCAP)
