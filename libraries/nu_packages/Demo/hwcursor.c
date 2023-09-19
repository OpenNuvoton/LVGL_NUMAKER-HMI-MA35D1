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

#if defined(DISP_USING_CURSOR)

#include <dfs_file.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/statfs.h>

//#undef DBG_ENABLE
#define DBG_LEVEL   LOG_LVL_INFO
#define DBG_COLOR
#define DBG_SECTION_NAME  "hwcursor"
#include <rtdbg.h>

/* Link to rtthread.bin in ma35-rtp folder. */
#define PATH_ICON_INCBIN          ".//default.ico"
INCBIN(cursor, PATH_ICON_INCBIN);

typedef struct
{
    uint16_t  u16Reserved;  // Reserved. Must always be 0.
    uint16_t  u16ImageType; // Specifies image type: 1 for icon (.ICO) image, 2 for cursor (.CUR) image. Other values are invalid.
    uint16_t  u16ImgNum;    // Specifies number of images in the file.
} S_ICON_HEADER;

typedef struct
{
    uint8_t  u8Width;  // Width, should be 0 if 256 pixels
    uint8_t  u8Height; // Height, should be 0 if 256 pixels
    uint8_t  u8ColorCount; // Color count, should be 0 if more than 256 colors
    uint8_t  u8Reserved; // Reserved, should be 0
    uint16_t u16ColorPlanes_HotSpotX; // Color planes when in .ICO format, should be 0 or 1, or the X hotspot when in .CUR format
    uint16_t u16BitPerPixel_HotSpotY; // Bits per pixel when in .ICO format, or the Y hotspot when in .CUR format
    uint32_t u32DataSize; // Size of the bitmap data in bytes.
    uint32_t u32DataOffsetOfFile; // Offset in the file.
} S_ICON_DIRECTORY;

typedef struct
{
    uint32_t  u32HeaderSize;
    uint32_t  u32Width;
    uint32_t  u32Height;
    uint16_t  u16Planes;
    uint16_t  u16BitPerPixel;
    uint32_t  u32Compression;
    uint32_t  u32DataSize;
    uint32_t  u32HResolution;
    uint32_t  u32VResolution;
    uint32_t  u32UsedColors;
    uint32_t  u32ImportantColors;
} S_BMP_INFO;

static void icon_dump(int index, uint16_t u16ImageType, S_ICON_DIRECTORY *psIconDirectory)
{
    LOG_I("Image[%d] width: %d", index, psIconDirectory->u8Width);
    LOG_I("Image[%d] height: %d", index, psIconDirectory->u8Height);
    LOG_I("Image[%d] color count: %d", index, (psIconDirectory->u8ColorCount == 0) ? 256 : psIconDirectory->u8ColorCount);
    switch (u16ImageType)
    {
    case 1:
        LOG_I("Image[%d] ICON bit per pixel: %d", index, psIconDirectory->u16BitPerPixel_HotSpotY);
        LOG_I("Image[%d] ICON color planes: %d", index, psIconDirectory->u16ColorPlanes_HotSpotX);
        break;

    case 2:
        LOG_I("Image[%d] CUR HotSpotX: %d", index, psIconDirectory->u16ColorPlanes_HotSpotX);
        LOG_I("Image[%d] CUR HotSpotY: %d", index, psIconDirectory->u16BitPerPixel_HotSpotY);
        break;

    default:
        break;
    }
    LOG_I("Image[%d] data size: %d", index, psIconDirectory->u32DataSize);
    LOG_I("Image[%d] offset: %d", index, psIconDirectory->u32DataOffsetOfFile);
}

void icon_data_copy(uint8_t *d, uint8_t *s)
{
    int y;
    /* Reverse Y */
    for (y = 31; y >= 0; y--)
    {
        rt_memcpy(&d[4 * 32 * (31 - y)], &s[4 * 32 * y], 32 * 4);
    }
}

static int icon_file_parse(const char *filepath, uint8_t *puFb)
{
    int fd = -1, ret = -1;
    S_ICON_HEADER sIconHeader;

    S_ICON_DIRECTORY  sFirstIconDirectory;

    fd = open(filepath, O_RDWR | O_SYNC);
    if (fd < 0)
    {
        goto exit_icon_file_parse;
    }

    /*read data from file*/
    if (read(fd, &sIconHeader, sizeof(S_ICON_HEADER)) != sizeof(S_ICON_HEADER))
    {
        goto exit_icon_file_parse;
    }

    if ((sIconHeader.u16Reserved == 0) && ((sIconHeader.u16ImageType == 1) || (sIconHeader.u16ImageType == 2)))
    {
        int i = 0;

        LOG_I("Image type: %d", sIconHeader.u16ImageType);
        LOG_I("Image number: %d", sIconHeader.u16ImgNum);

        for (i = 0; i < sIconHeader.u16ImgNum; i++)
        {
            S_ICON_DIRECTORY  sIconDirectory;

            if (read(fd, &sIconDirectory, sizeof(S_ICON_DIRECTORY)) != sizeof(S_ICON_DIRECTORY))
            {
                goto exit_icon_file_parse;
            }
            icon_dump(i + 1, sIconHeader.u16ImageType, &sIconDirectory);

            if ((i == 0) && puFb)
                rt_memcpy(&sFirstIconDirectory, &sIconDirectory, sizeof(S_ICON_DIRECTORY));

        } // for (i = 0; i < sIconHeader.u16ImgNum; i++)
    }

    if (puFb &&
            (sFirstIconDirectory.u8Width == 32) &&
            (sFirstIconDirectory.u8Height == 32))
    {
#define DEF_ICONS_SIZE (32 * 32 * 4)
        uint8_t *puTmpBuf = rt_malloc(DEF_ICONS_SIZE);
        if (puTmpBuf)
        {
            lseek(fd, (sFirstIconDirectory.u32DataOffsetOfFile + sizeof(S_BMP_INFO)), SEEK_SET);

            if (read(fd, puTmpBuf, DEF_ICONS_SIZE) != DEF_ICONS_SIZE)
            {
                rt_free(puTmpBuf);
                goto exit_icon_file_parse;
            }

            /* Reverse Y */
            icon_data_copy(puFb, puTmpBuf);
            rt_free(puTmpBuf);
        }
    }

    ret = 0;

exit_icon_file_parse:

    if (fd >= 0)
        close(fd);

    return ret;
}

static int icon_membuf_parse(const uint8_t *puIconMemBuf, uint8_t *puFb)
{
    S_ICON_HEADER *psIconHeader = (S_ICON_HEADER *)puIconMemBuf;

    S_ICON_DIRECTORY *psFirstIconDirectory = (S_ICON_DIRECTORY *)(puIconMemBuf + sizeof(S_ICON_HEADER));

    if ((psIconHeader->u16Reserved == 0) &&
            ((psIconHeader->u16ImageType == 1) ||
             (psIconHeader->u16ImageType == 2)))
    {
        int i = 0;

        LOG_I("Image type: %d", psIconHeader->u16ImageType);
        LOG_I("Image number: %d", psIconHeader->u16ImgNum);

        for (i = 0; i < psIconHeader->u16ImgNum; i++)
        {
            S_ICON_DIRECTORY *psIconDirectory = (S_ICON_DIRECTORY *)(puIconMemBuf + sizeof(S_ICON_HEADER) + (i * sizeof(S_ICON_DIRECTORY)));

            icon_dump(i + 1, psIconHeader->u16ImageType, psIconDirectory);

        } // for (i = 0; i < psIconHeader->u16ImgNum; i++)
    }

    if (puFb &&
            (psFirstIconDirectory->u8Width == 32) &&
            (psFirstIconDirectory->u8Height == 32))
    {
#define DEF_ICONS_SIZE (32 * 32 * 4)
        uint8_t *puTmpBuf = (uint8_t *)(puIconMemBuf + (psFirstIconDirectory->u32DataOffsetOfFile + sizeof(S_BMP_INFO)));

        /* Reverse Y */
        icon_data_copy(puFb, puTmpBuf);
    }

    return 0;
}

rt_err_t hwcursor_file_init(const char *filepath)
{
    rt_err_t ret = -RT_ERROR;
    rt_device_t dev = rt_device_find("cursor");
    if (dev != RT_NULL)
    {
        struct rt_device_graphic_info info;

        ret = rt_device_control(dev, RTGRAPHIC_CTRL_GET_INFO, &info);
        if (ret != RT_EOK)
            goto exit_hwcurson_init;

        ret = icon_file_parse(filepath, info.framebuffer);
        if (ret < 0)
        {
            LOG_E("Fail to parse %s", filepath);
            goto exit_hwcurson_init;
        }
    }

    ret = RT_EOK;

exit_hwcurson_init:

    return ret;
}

rt_err_t hwcursor_membuf_init(void)
{
    rt_err_t ret = -RT_ERROR;
    rt_device_t dev = rt_device_find("cursor");
    if (dev != RT_NULL)
    {
        struct rt_device_graphic_info info;

        int cursor_size = (int)((char *)&incbin_cursor_end - (char *)&incbin_cursor_start);
        LOG_I("INCBIN CURSOR Start = %p", &incbin_cursor_start);
        LOG_I("INCBIN CURSOR Size = %p", cursor_size);

        ret = rt_device_control(dev, RTGRAPHIC_CTRL_GET_INFO, &info);
        if (ret != RT_EOK)
            goto exit_hwcursor_membuf_init;

        ret = icon_membuf_parse((const uint8_t *)&incbin_cursor_start, info.framebuffer);
        if (ret < 0)
        {
            LOG_E("Fail to parse membuf");
            goto exit_hwcursor_membuf_init;
        }
    }

    ret = RT_EOK;

exit_hwcursor_membuf_init:

    return ret;
}

static int nu_hwcursor_init(void)
{

    if ( hwcursor_membuf_init() == RT_EOK)
    {
        /* Enable cursor */
        // rt_device_t dev = rt_device_find("cursor");
        // rt_device_open(dev, RT_DEVICE_FLAG_RDWR);
    }
    else
    {
        LOG_E("Fail to init cursor\n");
    }

    return 0;
}
INIT_COMPONENT_EXPORT(nu_hwcursor_init);

static int nu_icon_file_parse(int argc, char **argv)
{
    if (argc < 2)
    {
        LOG_I("Usage: %s <icon's file path>", __func__);
        return -1;
    }

    return icon_file_parse(argv[1], RT_NULL);
}
MSH_CMD_EXPORT(nu_icon_file_parse, parse an icon file);

static rt_err_t nu_icon_load(int argc, char **argv)
{
    rt_err_t ret = -RT_ERROR;

    if (argc < 2)
    {
        LOG_I("Usage: %s <icon's file path>", __func__);
        goto exit_nu_icon_load;
    }

    ret = hwcursor_file_init(argv[1]);

exit_nu_icon_load:

    return ret;
}
MSH_CMD_EXPORT(nu_icon_load, load an icon);

#endif
