/**************************************************************************//**
* @copyright (C) 2019 Nuvoton Technology Corp. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
*   1. Redistributions of source code must retain the above copyright notice,
*      this list of conditions and the following disclaimer.
*   2. Redistributions in binary form must reproduce the above copyright notice,
*      this list of conditions and the following disclaimer in the documentation
*      and/or other materials provided with the distribution.
*   3. Neither the name of Nuvoton Technology Corp. nor the names of its contributors
*      may be used to endorse or promote products derived from this software
*      without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************************/

/* Standard includes. */
#include <stdlib.h>

/* Nuvoton includes. */
#include "NVTMedia_SAL_OS.h"
#include "NVTMedia_SAL_FS.h"
#include "NVTMedia.h"
#include "Render.h"

#include "FileList.h"
#include "Player.h"

#define DEF_NM_ENGINE_BLOCKING true
#define DEF_MEDIA_FOLDER     "/mnt/sd0/"

typedef struct
{
    HPLAY              m_hPlay;
    uint64_t           u64CurTimeInMs;
    int                m_i32FileListIdx;
    S_NM_PLAY_IF       m_sPlayIF;
    S_NM_PLAY_CONTEXT  m_sPlayCtx;
    S_NM_PLAY_INFO     m_sPlayInfo;
    void              *m_OpenRes;
} S_PLAYER;

static S_PLAYER g_sPlayer =
{
    .m_hPlay = (HPLAY)eNM_INVALID_HANDLE,
    0
};

void Render_VideoFlush(S_NM_VIDEO_CTX   *psVideoCtx);
void Render_AudioFlush(S_NM_AUDIO_CTX   *psAudioCtx);
int nvtmedia_stop(void);

static uint64_t s_u64ShowTime  = 0;

#if defined (__GNUC__) && !(__CC_ARM)
static char *ulltoStr(uint64_t val)
{
    static char buf[34] = { [0 ... 33] = 0 };
    char *out = &buf[32];
    uint64_t hval = val;
    unsigned int hbase = 10;

    do
    {
        *out = "0123456789abcdef"[hval % hbase];
        --out;
        hval /= hbase;
    }
    while (hval);

    out ++;
    return out;
}
#endif


static void ShowPlayingTime(void)
{
    char szInfo[128];

    if (NMUtil_GetTimeMilliSec() > s_u64ShowTime)
    {

#if defined (__GNUC__) && !(__CC_ARM)
        sprintf(szInfo, "Current playing time %s \n", ulltoStr(g_sPlayer.u64CurTimeInMs));
#else
        sprintf(szInfo, "Current playing time %lld \n", g_sPlayer.u64CurTimeInMs);
#endif
        printf("%s", szInfo);

        s_u64ShowTime = NMUtil_GetTimeMilliSec() + 1000;
    }

}

static void UpdateInfo_VideoFlush(S_NM_VIDEO_CTX   *psVideoCtx)
{
    g_sPlayer.u64CurTimeInMs = psVideoCtx->u64DataTime;
    //ShowPlayingTime();
    Render_VideoFlush(psVideoCtx);
}

static void UpdateInfo_AudioFlush(S_NM_AUDIO_CTX   *psAudioCtx)
{
    g_sPlayer.u64CurTimeInMs = psAudioCtx->u64DataTime;
    //ShowPlayingTime();
    Render_AudioFlush(psAudioCtx);
}

uint64_t Player_playtime_current(void)
{
    return g_sPlayer.u64CurTimeInMs;
}

uint64_t Player_playtime_total(void)
{
    return (uint64_t)g_sPlayer.m_sPlayInfo.u32Duration;
}

static void dump_media_info(const char *szAVIFileName)
{
    printf(" Fn:%s AT:%d, MF: %d, VT:%d, Duration:%ld, AC:%ld, VC:%ld\n",
           szAVIFileName,
           g_sPlayer.m_sPlayInfo.eAudioType,
           g_sPlayer.m_sPlayInfo.eMediaFormat,
           g_sPlayer.m_sPlayInfo.eVideoType,
           g_sPlayer.m_sPlayInfo.u32Duration,
           g_sPlayer.m_sPlayInfo.u32AudioChunks,
           g_sPlayer.m_sPlayInfo.u32VideoChunks);
}

int nvtmedia_start(
    const char *szFileName
)
{
    E_NM_ERRNO eNMRet = eNM_ERRNO_NONE;
    int32_t i32Ret;

    if (g_sPlayer.m_hPlay == (HPLAY)eNM_INVALID_HANDLE)
    {
        memset((void *)&g_sPlayer.m_sPlayIF, 0, sizeof(S_NM_PLAY_IF));
        memset((void *)&g_sPlayer.m_sPlayCtx, 0, sizeof(S_NM_PLAY_CONTEXT));
        memset((void *)&g_sPlayer.m_sPlayInfo, 0, sizeof(S_NM_PLAY_INFO));
        g_sPlayer.m_OpenRes = NULL;
        g_sPlayer.m_hPlay = (HPLAY)eNM_INVALID_HANDLE;

        //Open media
        eNMRet = NMPlay_Open((char *)szFileName, &g_sPlayer.m_sPlayIF, &g_sPlayer.m_sPlayCtx, &g_sPlayer.m_sPlayInfo, &g_sPlayer.m_OpenRes);
        if (eNMRet != eNM_ERRNO_NONE)
        {
            goto exit_player_start;
        }

        //Show media information
        // dump_media_info((const char *)szFileName);

        //Setup audio and video flush callback
        if (g_sPlayer.m_sPlayIF.psVideoCodecIF)
            g_sPlayer.m_sPlayIF.pfnVideoFlush = UpdateInfo_VideoFlush;

        if (g_sPlayer.m_sPlayIF.psAudioCodecIF && !g_sPlayer.m_sPlayIF.pfnVideoFlush)
            g_sPlayer.m_sPlayIF.pfnAudioFlush = UpdateInfo_AudioFlush;
        else if (g_sPlayer.m_sPlayIF.psAudioCodecIF)
            g_sPlayer.m_sPlayIF.pfnAudioFlush = Render_AudioFlush;

        //Setup audio flush context
        g_sPlayer.m_sPlayCtx.sFlushAudioCtx.eAudioType = eNM_CTX_AUDIO_PCM_L16;
        g_sPlayer.m_sPlayCtx.sFlushAudioCtx.u32SampleRate = g_sPlayer.m_sPlayCtx.sMediaAudioCtx.u32SampleRate;
        g_sPlayer.m_sPlayCtx.sFlushAudioCtx.u32Channel = g_sPlayer.m_sPlayCtx.sMediaAudioCtx.u32Channel;
        g_sPlayer.m_sPlayCtx.sFlushAudioCtx.u32SamplePerBlock = g_sPlayer.m_sPlayCtx.sMediaAudioCtx.u32SamplePerBlock;
        g_sPlayer.m_sPlayCtx.sFlushAudioCtx.pvParamSet = g_sPlayer.m_sPlayCtx.sMediaAudioCtx.pvParamSet;

        //Init display
        i32Ret = Render_Init(g_sPlayer.m_sPlayCtx.sFlushAudioCtx.u32SampleRate,
                             g_sPlayer.m_sPlayCtx.sFlushAudioCtx.u32Channel,
                             &g_sPlayer.m_sPlayCtx.sFlushVideoCtx);
        if (i32Ret != 0)
        {
            eNMRet = eNM_ERRNO_IO;
            nvtmedia_stop();
            goto exit_player_start;
        }

    }

exit_player_start:

    return -(eNMRet);
}

int nvtmedia_seek(int argc, char *argv[])
{
    // seek
    E_NM_ERRNO eNMErr = eNM_ERRNO_BAD_PARAM;
    uint32_t u32SeekTime;

    if (argc != 2)
        goto exit_player_seek;

    u32SeekTime = (uint32_t)atoi(argv[1]);

    printf("Seek to %ldms\n", u32SeekTime);

    eNMErr = NMPlay_Seek(g_sPlayer.m_hPlay,
                         u32SeekTime,
                         g_sPlayer.m_sPlayInfo.u32VideoChunks,
                         g_sPlayer.m_sPlayInfo.u32AudioChunks,
                         DEF_NM_ENGINE_BLOCKING);
    if (eNMErr != eNM_ERRNO_NONE)
    {
        printf("Unable seek media %x\n", eNMErr);
        goto exit_player_seek;
    }

exit_player_seek:

    return (eNMErr != eNM_ERRNO_NONE) ? -1 : 0;
}
MSH_CMD_EXPORT(nvtmedia_seek, seek to start);

int nvtmedia_stop(void)
{
    if (g_sPlayer.m_hPlay != (HPLAY)eNM_INVALID_HANDLE)
    {
        //Close media
        NMPlay_Close(g_sPlayer.m_hPlay, &g_sPlayer.m_OpenRes);
        Render_Final();
    }

    g_sPlayer.m_hPlay = (HPLAY)eNM_INVALID_HANDLE;

    return 0;
}
MSH_CMD_EXPORT(nvtmedia_stop, stop player);

int nvtmedia_status(void)
{
    // get status
    if (g_sPlayer.m_hPlay != (HPLAY)eNM_INVALID_HANDLE)
    {
        E_NM_PLAY_STATUS evStatus = NMPlay_Status(g_sPlayer.m_hPlay);

        switch (evStatus)
        {
        case eNM_PLAY_STATUS_ERROR:
            printf("ERROR.\n");
            break;
        case eNM_PLAY_STATUS_PAUSE:
            printf("PAUSED.\n");
            break;
        case eNM_PLAY_STATUS_PLAYING:
            printf("PLAYING.\n");
            break;
        case eNM_PLAY_STATUS_EOM:
            printf("EOM.\n");
            break;
        default:
            break;
        }
    }
    return 0;
}
MSH_CMD_EXPORT(nvtmedia_status, get status);

int nvtmedia_pause(void)
{
    if (g_sPlayer.m_hPlay != (HPLAY)eNM_INVALID_HANDLE)
        NMPlay_Pause(g_sPlayer.m_hPlay,
                     DEF_NM_ENGINE_BLOCKING);

    return 0;
}
MSH_CMD_EXPORT(nvtmedia_pause, pause player);

int nvtmedia_play(void)
{
    // play media
    E_NM_ERRNO eNMErr = NMPlay_Play(&g_sPlayer.m_hPlay,
                                    &g_sPlayer.m_sPlayIF,
                                    &g_sPlayer.m_sPlayCtx,
                                    DEF_NM_ENGINE_BLOCKING);
    if (eNMErr != eNM_ERRNO_NONE)
    {
        printf("Unable play media %x\n", eNMErr);
        goto exit_player_play;
    }

    return eNMErr;

exit_player_play:

    nvtmedia_stop();

    return eNMErr;
}
MSH_CMD_EXPORT(nvtmedia_play, play / resume);

int nvtmedia_playfile(int argc, char *argv[])
{
    if (argc == 2)
    {
        nvtmedia_stop();

        if (nvtmedia_start((const char *)argv[1]) == eNM_ERRNO_NONE)
        {
            return nvtmedia_play();
        }
        else
        {
            return -1;
        }
    }

    return -1;
}
MSH_CMD_EXPORT(nvtmedia_playfile, play specified file name);

#define DEF_NVTMEDIA_PLAYER "nvtmedia"
#define DEF_NVTMEDIA_FOLDER "/mnt/sd1p0/"

static int bNvtmediaWorkerRunning = 0;

void nvtmedia_worker(void *data)
{
    char *pcDirPath = (char *)data;
    int n;

    if ((n = filelist_create(pcDirPath)) < 0)
    {
        printf("[%s]Can't find media file in %s\n", __func__, pcDirPath);
        return;
    }
    else if ( filelist_getInstance()->m_i32UsedNum != 0)
    {
        filelist_dump();

        bNvtmediaWorkerRunning = 1;

        while (bNvtmediaWorkerRunning)
        {
            for (int i = 0; i < n; i++)
            {
                nvtmedia_stop();

                printf("[%lld] Will start %s ...\n", NMUtil_GetTimeMilliSec(), filelist_getFileName(i));
                if (nvtmedia_start(filelist_getFileName(i)) == eNM_ERRNO_NONE)
                {
                    if (nvtmedia_play() != eNM_ERRNO_NONE)
                        continue;

                    while (bNvtmediaWorkerRunning)
                    {
                        E_NM_PLAY_STATUS evStatus = NMPlay_Status(g_sPlayer.m_hPlay);
                        if ((evStatus == eNM_PLAY_STATUS_EOM) ||
                                (evStatus == eNM_PLAY_STATUS_ERROR))
                        {
                            break;
                        }

                        rt_thread_mdelay(1000);

                    } //while

                    nvtmedia_stop();

                    if (!bNvtmediaWorkerRunning)
                        break;
                }

            }//for

        } //while

        filelist_destroy();
    }

    free(pcDirPath);
}

int nvtmedia_auto_play(int argc, char *argv[])
{
    char *dir = NULL;
    rt_thread_t tid = rt_thread_find(DEF_NVTMEDIA_PLAYER);

    if (tid == RT_NULL)
    {
        struct stat sb;
        if (argc == 2)
        {
            rt_size_t len;

            /* Trailing char is slash? */
            len = strlen(argv[1]);
            if (argv[1][len - 1] != (char)'/')
            {
                dir = malloc(len + 1) ;
                rt_strcpy(dir, argv[1]);
                dir[len] = '/';
            }
            else
            {
                dir = rt_strdup(argv[1]);
            }

        }
        else
        {
            dir = rt_strdup(DEF_NVTMEDIA_FOLDER);
        }

        /* check if path exists and is a directory */
        if (stat(dir, &sb) == 0)
        {
            if (!S_ISDIR(sb.st_mode))
            {
                goto exit_nvtmedia_auto_play;
            }
        }

        tid = rt_thread_create(DEF_NVTMEDIA_PLAYER,
                               nvtmedia_worker,
                               dir,
                               4096,
                               20,
                               10);

        if (tid != RT_NULL)
            rt_thread_startup(tid);
    }

    return 0;

exit_nvtmedia_auto_play:

    if (dir)
        free(dir);

    return -1;
}
MSH_CMD_EXPORT(nvtmedia_auto_play, nvtmedia_auto_play);

int nvtmedia_auto_stop(void)
{
    bNvtmediaWorkerRunning = 0;
    nvtmedia_stop();

    return 0;
}
MSH_CMD_EXPORT(nvtmedia_auto_stop, nvtmedia_auto_stop);


static void nvtmedia_auto_start_idlehook(void)
{
    static rt_tick_t last_tickcount = 0;

    if ((rt_tick_get() - last_tickcount) > 500)
    {
        char *argv[2];

        argv[1] = DEF_MEDIA_FOLDER;

        if (nvtmedia_auto_play(2, argv) == 0)
            rt_thread_idle_delhook(nvtmedia_auto_start_idlehook);

        last_tickcount = rt_tick_get();
    }
}

int nvtmedia_auto_start()
{
    rt_err_t err = rt_thread_idle_sethook(nvtmedia_auto_start_idlehook);
    if (err != RT_EOK)
    {
        printf("set idle hook failed!\n");
        return -1;
    }

    return 0;
}
//INIT_APP_EXPORT(nvtmedia_auto_start);
MSH_CMD_EXPORT(nvtmedia_auto_start, nvtmedia_auto_start);
