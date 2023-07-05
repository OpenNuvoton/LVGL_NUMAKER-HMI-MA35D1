//      Copyright (c) 2019 Nuvoton Technology Corp. All rights reserved.
//
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either m_uiVersion 2 of the License, or
//      (at your option) any later m_uiVersion.
//
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.

/* Standard includes. */
#include <stdio.h>

#include <rtthread.h>
#include <rtdevice.h>

#include "Render.h"
#include "drv_disp.h"

#define SOUND_DEVICE_NAME "sound0"
#define LCD_DEVICE_NAME "lcd"

static rt_device_t s_psSndDev = RT_NULL;
static rt_device_t s_psLcdDev = RT_NULL;

void
Render_VideoFlush(
    S_NM_VIDEO_CTX  *psVideoCtx
)
{
    if (s_psLcdDev && psVideoCtx && psVideoCtx->pu8DataBuf)
    {
        rt_device_control(s_psLcdDev, RTGRAPHIC_CTRL_PAN_DISPLAY, psVideoCtx->pu8DataBuf);
        //rt_device_control(s_psLcdDev, RTGRAPHIC_CTRL_WAIT_VSYNC, RT_NULL);
    }
}

void
Render_AudioFlush(
    S_NM_AUDIO_CTX  *psAudioCtx
)
{
    uint64_t u64CurTime = NMUtil_GetTimeMilliSec();

    //printf("[%s] %lld, %lld, %ld\n", __func__, u64CurTime, psAudioCtx->u64DataTime, psAudioCtx->u32DataSize);

    if (s_psSndDev  && psAudioCtx && psAudioCtx->pu8DataBuf && psAudioCtx->u32DataSize)
        rt_device_write(s_psSndDev, 0, (const void *)psAudioCtx->pu8DataBuf, psAudioCtx->u32DataSize);
}

void
Render_Final(void)
{
    if (s_psSndDev)
    {
        rt_device_close(s_psSndDev);
    }

    if (s_psLcdDev)
    {
        rt_device_close(s_psLcdDev);
    }

    s_psSndDev = RT_NULL;
    s_psLcdDev = RT_NULL;
}

int
Render_Init(
    uint32_t u32AudioSampleRate,
    uint32_t u32AudioChannel,
    S_NM_VIDEO_CTX *psFlushVideoCtx
)
{
    rt_err_t ret;
    struct rt_audio_caps caps;
    struct rt_device_graphic_info gfx_info;

    s_psLcdDev = rt_device_find(LCD_DEVICE_NAME);
    s_psSndDev = rt_device_find(SOUND_DEVICE_NAME);
    if (s_psSndDev == RT_NULL || s_psLcdDev == RT_NULL)
        return -1;

    /* Get LCD Info */
    if (rt_device_control(s_psLcdDev, RTGRAPHIC_CTRL_GET_INFO, &gfx_info) != RT_EOK)
    {
        printf("Can't get LCD info %s\n", "lcd");
        goto exit_Render_Init;
    }

#if 0
    printf("LCD Width: %d\n",   gfx_info.width);
    printf("LCD Height: %d\n",  gfx_info.height);
    printf("LCD bpp:%d\n",   gfx_info.bits_per_pixel);
    printf("LCD pixel format:%d\n",   gfx_info.pixel_format);
    printf("LCD frame buffer@0x%08x\n",   gfx_info.framebuffer);
    printf("LCD frame buffer size:%d\n",   gfx_info.smem_len);
#endif

    //Setup video flush context
    //psFlushVideoCtx->eVideoType = eNM_CTX_VIDEO_RGB888;
    //psFlushVideoCtx->u32DataSize = gfx_info.width * gfx_info.height * 4; // for ARGB

    psFlushVideoCtx->eVideoType = eNM_CTX_VIDEO_NV12;
    psFlushVideoCtx->u32DataSize = gfx_info.width * gfx_info.height * 2; // for NV12

    psFlushVideoCtx->u32Width = gfx_info.width;
    psFlushVideoCtx->u32Height = gfx_info.height;
    psFlushVideoCtx->pu8DataBuf = gfx_info.framebuffer;
    psFlushVideoCtx->u32DataLimit = gfx_info.smem_len;

    int pixfmt = RTGRAPHIC_PIXEL_FORMAT_NV12;

    if (rt_device_control(s_psLcdDev, RTGRAPHIC_CTRL_SET_MODE, &pixfmt) != RT_EOK)
    {
        printf("Can't get LCD info %s\n", "lcd");
        goto exit_Render_Init;
    }

    /* open lcd */
    if (rt_device_open(s_psLcdDev, 0) != RT_EOK)
    {
        s_psLcdDev = NULL;
        goto exit_Render_Init;
    }

    // Just play sound, so set write only.
    ret = rt_device_open(s_psSndDev, RT_DEVICE_OFLAG_WRONLY);
    if (ret != RT_EOK)
    {
        s_psSndDev = NULL;
        goto exit_Render_Init;
    }

    caps.main_type               = AUDIO_TYPE_OUTPUT;
    caps.sub_type                = AUDIO_DSP_PARAM;
    caps.udata.config.samplerate = u32AudioSampleRate;
    caps.udata.config.channels   = u32AudioChannel;
    caps.udata.config.samplebits = 16;

    ret = rt_device_control(s_psSndDev, AUDIO_CTL_CONFIGURE, &caps);
    if (ret != RT_EOK)
    {
        goto exit_Render_Init;
    }

    return 0;

exit_Render_Init:

    Render_Final();

    return -1;
}

int nvtmedia_volume(int argc, char *argv[])
{
    if (s_psSndDev)
    {
        struct rt_audio_caps caps;
        rt_err_t ret ;

        caps.main_type   = AUDIO_TYPE_MIXER;
        caps.sub_type    = AUDIO_MIXER_VOLUME;
        caps.udata.value = atoi(argv[1]);

        if (caps.udata.value > 99)
            return -1;

        ret = rt_device_control(s_psSndDev, AUDIO_CTL_CONFIGURE, &caps);
        if (ret != RT_EOK)
        {
            return -1;
        }
    }

    return 0;
}
MSH_CMD_EXPORT(nvtmedia_volume, set the volume 0 99);



