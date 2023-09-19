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

/*

1. IBR compares S_BOOT_INFO_T.m_u32Version of both header0 and header1 and load newer version firmware to run.
2. Dual-headers must be placed in various storage device as below:

[SD/EMMC]
- Sector size is 512B
-- header0 in sector 2,     @0x400
-- header1 in sector 3,     @0x600

[NAND/QSPI-NAND] 2048+64, PPB=64
- Block size(erase size) equals (page size) * (page per block)
-- header0 in block 0, page 0, @0x0
-- header1 in block 1, page 0, @0x20000

[QSPI-NOR]
- Sector size(erase size) is 4096B
-- header0 in offset 0,      @0x0
-- header1 in offset 0x1000, @0x1000

*/

#include <rtthread.h>

#if defined(SOC_SERIES_MA35D1)

#include <dfs_posix.h>
#include <sys/stat.h>
#include <sys/statfs.h>
#include <optparse.h>
#include <string.h>
#include <rtdevice.h>
#if defined(RT_USING_FAL)
    #include <fal.h>
#endif
#include "nuwriter.h"
#include "drv_sys.h"

#define DBG_LEVEL   DBG_INFO
#define DBG_SECTION_NAME  "nuwriter"
#define DBG_COLOR
#include <rtdbg.h>

/* Structure of NuWriter Packfile Header */
typedef struct
{
    uint32_t m_ui32Marker;           // 'N', 'V', 'T'
    uint32_t m_ui32CRC32;            // CRC32 calculates the checksum starting from offset 0x8.
    uint32_t m_ui32TotalImageCount;  // Count of total image
    uint32_t m_ui32Reserve;
} S_NUWRITER_PACK_HDR;

/* Structure of NuWriter Child in pack Header */
typedef struct
{
    uint64_t m_ui64ImageLength;
    uint64_t m_ui64FlashAddress;
    uint32_t m_ui32ImageType;
    uint32_t m_ui32Reserve;
    uint8_t  m_au8Data[0];
} S_NUWRITER_PACK_CHILD;

#define IMAGE_BOUNDARY_SIZE    16
#define PACK_ALIGN(size)       (((size) + (IMAGE_BOUNDARY_SIZE) - 1) & ~((IMAGE_BOUNDARY_SIZE) - 1))
#define NVT_MARKER             0x4E565420   //" NVT"

typedef struct
{
    uint16_t  m_u16PageSize;     //The SPI NAND flash size.
    uint16_t  m_u16SpareArea;    //The SPI NAND spare area size of each page.
    uint16_t  m_u16PagePerBlock; //The SPI NAND page count per block.
    uint8_t   m_u8QuadReadCmd;   //This is the quad read command of SPI flash.
    uint8_t   m_u8ReadStatusCmd; //The command used to read flash status.
    uint8_t   m_u8WriteStatusCmd; //The command used to write flash status.
    uint8_t   m_u8StatusValue; //This value defines the status register bit to control SPI NOR flash enter and exit quad mode.
    uint8_t   m_u8Dummybyte1; //This attribute is used to store the dummy byte count between command and address.
    uint8_t   m_u8Dummybyte2; //This attribute is used to store the dummy byte count between and data.
    uint8_t   m_u8SuspendInterval; //This attribute defines the suspend interval between two successive transmit/receive transaction in a transfer. Valid values are between 0~15.
    uint8_t   m_au8Reserved[3]; //These three bytes are used to make following entry in boot_info word aligned.
} S_SPI_INFO_T;

typedef struct
{

    uint32_t   m_u32Offset; //The offset this image is stored in storage device.
    uint32_t   m_u32LoadAddr; //The image load address in DDR or SRAM.
    uint32_t   m_u32Size; //The image size in byte.
    uint32_t   m_u32Type; //Image type.
    //Valid values are
    //1: stands for TSI image,
    //2: System setting image,
    //3: Data image,
    //4: Loader image.

    uint8_t  m_au8SignatureR[32];    //These fields store the ECDSA signature of the image.
    uint8_t  m_au8SignatureS[32];    //These fields store the ECDSA signature of the image.

} S_IMAGE_INFO_T;

typedef struct
{

    uint32_t        m_u32BootMarker; //A marker which should be string value ??NVT??
    uint32_t        m_u32CheckSum;   //The CRC32 checksum of boot_info structure except marker.
    uint32_t        m_u32Length;     //Total header length
    uint32_t        m_u32Version;    //Boot information version number.
    S_SPI_INFO_T    m_sSpiInfo;      //A structure holds the SPI flash information.
    uint32_t        m_u32EntryPoint; //The address IBR branch to after images are loaded and verified correctly
    uint32_t        m_u32Count;      //Total image count. Maximum value is 4
    S_IMAGE_INFO_T  m_sImage[4];     //A structure array holds the attribute of the images

} S_BOOT_INFO_T;

typedef struct
{
    E_POR_BOOTSRC boot_from;
    const char *szDevName;
    uint32_t hdr_offset[2];
} S_HDR_INFO;


static const S_HDR_INFO s_sHdrInfo[evBootFrom_Cnt] =
{
    {evBootFrom_QSPI0_NOR,  STORAGE_DEVNAME_QSPI0_NOR,   {0,  1}},
    {evBootFrom_QSPI0_NAND, STORAGE_DEVNAME_QSPI0_NAND,  {0,  1}},
    {evBootFrom_SD_eMMC0,   STORAGE_DEVNAME_SD_EMMC0,    {2,  3}},
    {evBootFrom_SD_eMMC1,   STORAGE_DEVNAME_SD_EMMC1,    {2,  3}},
    {evBootFrom_RAW_NAND,   STORAGE_DEVNAME_RAW_NAND,    {0,  1}},
    {evBootFrom_USBD,       NULL,                        {0,  0}},
    {evBootFrom_USBH0,      "udisk0",                    {0,  0}},
    {evBootFrom_USBH1,      "udisk0",                    {0,  0}}
};

static const uint32_t crc32_tab[] =
{
    0x00000000, 0x77073096, 0xee0e612c, 0x990951ba, 0x076dc419, 0x706af48f,
    0xe963a535, 0x9e6495a3, 0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
    0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91, 0x1db71064, 0x6ab020f2,
    0xf3b97148, 0x84be41de, 0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
    0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec, 0x14015c4f, 0x63066cd9,
    0xfa0f3d63, 0x8d080df5, 0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172,
    0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b, 0x35b5a8fa, 0x42b2986c,
    0xdbbbc9d6, 0xacbcf940, 0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
    0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116, 0x21b4f4b5, 0x56b3c423,
    0xcfba9599, 0xb8bda50f, 0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
    0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d, 0x76dc4190, 0x01db7106,
    0x98d220bc, 0xefd5102a, 0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433,
    0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818, 0x7f6a0dbb, 0x086d3d2d,
    0x91646c97, 0xe6635c01, 0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e,
    0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457, 0x65b0d9c6, 0x12b7e950,
    0x8bbeb8ea, 0xfcb9887c, 0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
    0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2, 0x4adfa541, 0x3dd895d7,
    0xa4d1c46d, 0xd3d6f4fb, 0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0,
    0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9, 0x5005713c, 0x270241aa,
    0xbe0b1010, 0xc90c2086, 0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
    0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4, 0x59b33d17, 0x2eb40d81,
    0xb7bd5c3b, 0xc0ba6cad, 0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a,
    0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683, 0xe3630b12, 0x94643b84,
    0x0d6d6a3e, 0x7a6a5aa8, 0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1,
    0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe, 0xf762575d, 0x806567cb,
    0x196c3671, 0x6e6b06e7, 0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc,
    0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5, 0xd6d6a3e8, 0xa1d1937e,
    0x38d8c2c4, 0x4fdff252, 0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
    0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60, 0xdf60efc3, 0xa867df55,
    0x316e8eef, 0x4669be79, 0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
    0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f, 0xc5ba3bbe, 0xb2bd0b28,
    0x2bb45a92, 0x5cb36a04, 0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
    0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a, 0x9c0906a9, 0xeb0e363f,
    0x72076785, 0x05005713, 0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38,
    0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21, 0x86d3d2d4, 0xf1d4e242,
    0x68ddb3f8, 0x1fda836e, 0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
    0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c, 0x8f659eff, 0xf862ae69,
    0x616bffd3, 0x166ccf45, 0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2,
    0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db, 0xaed16a4a, 0xd9d65adc,
    0x40df0b66, 0x37d83bf0, 0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
    0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6, 0xbad03605, 0xcdd70693,
    0x54de5729, 0x23d967bf, 0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94,
    0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d
};

#define CRC_SEED    0xFFFFFFFF

static uint32_t crc32(uint32_t *ptr, uint32_t len)
{
    int i, j;

    uint32_t  crc = CRC_SEED;
    uint32_t data32;
    uint8_t data8;

    /* WDTAT_RVS, CHECKSUM_RVS, CHECKSUM_COM */
    for (j = 0; j < len; j += 4)
    {
        data32 = *ptr++;
        for (i = 0; i < 4; i++)
        {
            data8 = (data32 >> (i * 8)) & 0xff;
            crc = crc32_tab[(crc ^ data8) & 0xFF] ^ (crc >> 8);
        }
    }

    /* CHECKSUM_COM */
    return crc ^ ~0U;
}


static int nuwriter_spi_info_dump(S_SPI_INFO_T *psSPIInfo)
{
    LOG_D("\t\tSPI Info");

    LOG_D("\t\t\tPage size: %d", psSPIInfo->m_u16PageSize);
    LOG_D("\t\t\tSpare size: %d", psSPIInfo->m_u16SpareArea);
    LOG_D("\t\t\tPage per block: %d", psSPIInfo->m_u16PagePerBlock);

    LOG_D("\t\t\tQuad read command ID: 0x%02X", psSPIInfo->m_u8QuadReadCmd);
    LOG_D("\t\t\tRead status command ID: 0x%02X", psSPIInfo->m_u8ReadStatusCmd);
    LOG_D("\t\t\tWrite status command ID: 0x%02X", psSPIInfo->m_u8WriteStatusCmd);
    LOG_D("\t\t\tDummy byte num between command and address: %d", psSPIInfo->m_u8Dummybyte1);
    LOG_D("\t\t\tDummy byte num between address and data: %d", psSPIInfo->m_u8Dummybyte2);
    LOG_D("\t\t\tSuspend interval(0~15): %d", psSPIInfo->m_u8SuspendInterval);

    return 0;
}

static int nuwriter_check_image_info(S_IMAGE_INFO_T *psImageInfo)
{
    static char *ImgType [] =
    {
        "",
        "Stands for TSI",
        "System setting",
        "Data",
        "Loader"
    };

    LOG_D("\t\t\tOffset in storage: 0x%08X", psImageInfo->m_u32Offset);
    LOG_D("\t\t\tLoad-to address: 0x%08X", psImageInfo->m_u32LoadAddr);
    LOG_D("\t\t\tTotal length of header: %d", psImageInfo->m_u32Size);
    if (psImageInfo->m_u32Type > 4)
    {
        LOG_E("\t\t\tInvalid image type(%d)", psImageInfo->m_u32Type);
        goto exit_nuwriter_check_image_info;
    }
    else
    {
        LOG_D("\t\t\tType: %s", ImgType[psImageInfo->m_u32Type]);
    }

    //LOG_HEX("ECDSA-R", 16, (void *)&psImageInfo->m_au8SignatureR[0], sizeof(psImageInfo->m_au8SignatureR));
    //LOG_HEX("ECDSA-S", 16, (void *)&psImageInfo->m_au8SignatureS[0], sizeof(psImageInfo->m_au8SignatureS));

    return 0;

exit_nuwriter_check_image_info:

    return -1;
}

static int nuwriter_check_boot_info(S_BOOT_INFO_T *psBootInfo, uint32_t u32Length)
{
    int i;
    uint32_t u32CRC32ChkSum;

    if ((psBootInfo->m_u32BootMarker != NVT_MARKER))
    {
        LOG_E("Wrong marker 0x%08X", psBootInfo->m_u32BootMarker);
        goto exit_nuwriter_check_boot_info;
    }

    // Do CRC32 checksum
    u32CRC32ChkSum = crc32((uint32_t *)&psBootInfo->m_u32Length, u32Length);
    if (u32CRC32ChkSum != psBootInfo->m_u32CheckSum)
    {
        LOG_E("Invalid CRC32 checksum value(0x%08X != 0x%08X)\n", u32CRC32ChkSum, psBootInfo->m_u32CheckSum);
        goto exit_nuwriter_check_boot_info;
    }

    LOG_D("\tBoot Info");
    LOG_D("\t\tBoot Marker: 0x%08X", psBootInfo->m_u32BootMarker);
    LOG_D("\t\tCRC32 CheckSum: 0x%08X", psBootInfo->m_u32CheckSum);
    LOG_D("\t\tTotal length of header: %d", psBootInfo->m_u32Length);
    LOG_D("\t\tVersion number: 0x%08X", psBootInfo->m_u32Version);

    nuwriter_spi_info_dump(&psBootInfo->m_sSpiInfo);

    LOG_D("\t\tEntry point: 0x%08X", psBootInfo->m_u32EntryPoint);
    LOG_D("\t\tTotal image count: %d", psBootInfo->m_u32Count);

    if (psBootInfo->m_u32Count > 4) // Over range
    {
        LOG_E("Image count is over range.(%d > 4)\n", psBootInfo->m_u32Count);
        goto exit_nuwriter_check_boot_info;
    }

    for (i = 0; i < psBootInfo->m_u32Count; i++)
    {
        LOG_D("\t\tImage info[%d]", i);
        if (nuwriter_check_image_info(&psBootInfo->m_sImage[i]) < 0)
            goto exit_nuwriter_check_boot_info;
    }

    return 0;

exit_nuwriter_check_boot_info:

    return -1;
}

static int nuwriter_pack_verify(const uint8_t *pu8PackFileBuf, uint64_t u64FileLength)
{
    int i = 0;
    uint32_t u32CRC32ChkSum;

    S_NUWRITER_PACK_HDR *psPackHdr;
    S_NUWRITER_PACK_CHILD *psPackChild;

    LOG_D("[Verify pack file]");

    if ((pu8PackFileBuf == RT_NULL) || (u64FileLength == 0))
    {
        LOG_E("Wrong parameters");
        goto exit_nuwriter_pack_verify;
    }

    psPackHdr = (S_NUWRITER_PACK_HDR *)pu8PackFileBuf;
    psPackChild = (S_NUWRITER_PACK_CHILD *)(pu8PackFileBuf + sizeof(S_NUWRITER_PACK_HDR));

    if ((psPackHdr->m_ui32Marker != NVT_MARKER) || (psPackHdr->m_ui32Reserve != 0xffffffff))
    {
        LOG_E("Wrong marker");
        goto exit_nuwriter_pack_verify;
    }

    // Do CRC32 checksum
    u32CRC32ChkSum = crc32((uint32_t *)&psPackHdr->m_ui32TotalImageCount, u64FileLength - 8);
    if (u32CRC32ChkSum != psPackHdr->m_ui32CRC32)
    {
        LOG_E("Invalid CRC32 checksum value(0x%08X != 0x%08X)", u32CRC32ChkSum, psPackHdr->m_ui32CRC32);
        goto exit_nuwriter_pack_verify;
    }

    LOG_D("Pack header:");
    LOG_D("\tMarker: 0x%08X", psPackHdr->m_ui32Marker);
    LOG_D("\tCRC32: 0x%08X", psPackHdr->m_ui32CRC32);
    LOG_D("\tTotal image count: %d", psPackHdr->m_ui32TotalImageCount);
    LOG_D("\tReserve: 0x%08X", psPackHdr->m_ui32Reserve);

    for (i = 0; i < psPackHdr->m_ui32TotalImageCount; i++)
    {
        uint32_t next;

        LOG_D("Pack child[%d]", i);
        LOG_D("\tImage length:  %d Bytes", psPackChild->m_ui64ImageLength);
        LOG_D("\tFlash address: 0x%08X", (uint32_t)psPackChild->m_ui64FlashAddress);
        LOG_D("\tImage type: %d", psPackChild->m_ui32ImageType);
        LOG_D("\tReserve: 0x%08X", psPackChild->m_ui32Reserve);
        LOG_D("\tData Buffer Address: 0x%08X", psPackChild->m_au8Data);

        if (i == 0)
        {
            /* Limitation: header.bin must at first region. */
            nuwriter_check_boot_info((S_BOOT_INFO_T *)psPackChild->m_au8Data, psPackChild->m_ui64ImageLength - 8);
        }

        if ((i + 1) < psPackHdr->m_ui32TotalImageCount)
        {
            next = PACK_ALIGN((uint32_t)psPackChild +
                              sizeof(S_NUWRITER_PACK_CHILD) +
                              psPackChild->m_ui64ImageLength);
            psPackChild = (S_NUWRITER_PACK_CHILD *)next;

            LOG_D("\tNext Child Address: 0x%08X", next);
        }
    }

    LOG_D("\n");

    return 0;

exit_nuwriter_pack_verify:

    return -1;
}

static int nuwriter_pack_program_block(S_NUWRITER_PACK_HDR *psPackHdr, S_NUWRITER_PACK_CHILD **ppsChildList, rt_device_t device)
{
    struct rt_device_blk_geometry geo;
    void *block_buffer = RT_NULL;
    int i, ret = -1;

    rt_memset(&geo, 0, sizeof(geo));
    if (rt_device_control(device, RT_DEVICE_CTRL_BLK_GETGEOME, &geo) != RT_EOK)
    {
        LOG_E("%s CTRL_BLK_GETGEOME failed!\n", device->parent.name);
        goto exit_nuwriter_pack_program_block;
    }

    LOG_D("Block device information:");
    LOG_D("Sector size : %d bytes", geo.bytes_per_sector);
    LOG_D("Sector count : %d", geo.sector_count);
    LOG_D("Block size : %d Bytes", geo.block_size);

    if (geo.bytes_per_sector == 0)
    {
        LOG_E("Invalid block size!\n", device->parent.name);
        goto exit_nuwriter_pack_program_block;
    }

    block_buffer = rt_malloc_align(geo.bytes_per_sector, 64);

    for (i = psPackHdr->m_ui32TotalImageCount - 1; i >= 0; i--)
    {
        uint32_t total_block, u32Remain;
        uint32_t blk_off = 0;
        uint32_t flash_progress = 0;
        S_NUWRITER_PACK_CHILD *psPackChild = ppsChildList[i];

        u32Remain = psPackChild->m_ui64ImageLength;
        total_block = RT_ALIGN(psPackChild->m_ui64ImageLength, geo.bytes_per_sector) / geo.bytes_per_sector;

        LOG_D("Program child[%d], total block=%d...Start", i, total_block);

        while (blk_off < total_block)
        {
            rt_size_t size, transfer_bytes;
            transfer_bytes = (u32Remain >= geo.bytes_per_sector) ?  geo.bytes_per_sector : u32Remain;
            memcpy(block_buffer,
                   psPackChild->m_au8Data + (blk_off * geo.bytes_per_sector),
                   transfer_bytes);

            size = rt_device_write(device,
                                   ((psPackChild->m_ui64FlashAddress / geo.bytes_per_sector) + blk_off),
                                   block_buffer,
                                   1);
            if (size != 1)
            {
                LOG_E("Write device %s %d failed!\n", device->parent.name, size);
                goto exit_nuwriter_pack_program_block;
            }

            blk_off++;
            u32Remain -= transfer_bytes;

            if (flash_progress != (10 * blk_off / total_block))
            {
                flash_progress = (10 * blk_off / total_block);
                LOG_I("%d %...", flash_progress * 10);
            }
        }

        LOG_D("Program child[%d]...Done\n", i);
    }

    ret = 0;

exit_nuwriter_pack_program_block:

    if (block_buffer)
        rt_free_align(block_buffer);

    return ret;
}

#if defined(RT_USING_MTD_NAND)
static int nuwriter_pack_program_mtd(S_NUWRITER_PACK_HDR *psPackHdr, S_NUWRITER_PACK_CHILD **ppsChildList, struct rt_mtd_nand_device *device)
{
    int i, ret = -1;
    uint32_t u32EraseSize;
    void *page_buffer = RT_NULL;

    LOG_D("Name: %s", device->parent.parent.name);
    LOG_D("Start block: %d", device->block_start);
    LOG_D("End block: %d", device->block_end);
    LOG_D("Block number: %d", device->block_total);
    LOG_D("Plane number: %d", device->plane_num);
    LOG_D("Pages per Block: %d", device->pages_per_block);
    LOG_D("Page size: %d bytes", device->page_size);
    LOG_D("Spare size: %d bytes", device->oob_size);
    LOG_D("Total size: %d bytes (%d KB)",
          device->block_total * device->pages_per_block * device->page_size,
          device->block_total * device->pages_per_block * device->page_size / 1024);


    u32EraseSize = device->pages_per_block * device->page_size;

    page_buffer = rt_malloc_align(device->page_size, 64);

    for (i = psPackHdr->m_ui32TotalImageCount - 1; i >= 0; i--)
    {
        uint32_t total_block, block_off, block_idx, u32Remain;
        rt_err_t result;
        uint32_t flash_progress = 0;

        S_NUWRITER_PACK_CHILD *psPackChild = ppsChildList[i];

        u32Remain = psPackChild->m_ui64ImageLength;
        total_block = RT_ALIGN(u32Remain, u32EraseSize) / u32EraseSize;

        LOG_D("Program child[%d], total block=%d...Start", i, total_block);
        if (psPackChild->m_ui64FlashAddress != RT_ALIGN(psPackChild->m_ui64FlashAddress, u32EraseSize))
        {
            LOG_E("Flash address(%08x) is not aligned on erase size boundary", psPackChild->m_ui64FlashAddress);
            goto exit_nuwriter_pack_program_mtd;
        }

        block_off = psPackChild->m_ui64FlashAddress / u32EraseSize;
        block_idx = 0;

        while (block_idx < total_block)
        {
            uint32_t total_page, page_off, page_idx;

            result = rt_mtd_nand_check_block(device, block_off);
            if (result != RT_EOK)
            {
                LOG_W("Block-%d is bad. Skip.", block_off);
                block_off++;
                continue;
            }

            result = rt_mtd_nand_erase_block(device, block_off);
            if (result != RT_EOK)
            {
                LOG_E("Failed to erase block(%d)", block_off);
                goto exit_nuwriter_pack_program_mtd;
            }

            total_page = (u32Remain >= u32EraseSize) ?
                         device->pages_per_block :
                         RT_ALIGN(u32Remain, device->page_size) / device->page_size;

            page_off = block_off * device->pages_per_block;
            page_idx = 0;
            while (page_idx < total_page)
            {
                rt_size_t transfer_bytes = (u32Remain >= device->page_size) ? device->page_size : u32Remain;

                //rt_kprintf("-> %d total block:%d, bi: %d, pi: %d, page:(%d/%d)\n",
                //           u32Remain,
                //           total_block, block_off, page_off,
                //           page_idx, total_page);

                if (transfer_bytes != device->page_size)
                    memset(page_buffer, 0xff, device->page_size);

                memcpy(page_buffer,
                       psPackChild->m_au8Data + ((block_idx * device->pages_per_block + page_idx) * device->page_size),
                       transfer_bytes);

                result = rt_mtd_nand_write(device,
                                           page_off + page_idx,
                                           page_buffer,
                                           transfer_bytes,
                                           RT_NULL,
                                           RT_NULL);
                if (result != RT_EOK)
                {
                    LOG_E("Failed to write page(%d)", page_off + page_idx);
                    goto exit_nuwriter_pack_program_mtd;
                }
                page_idx++;
                u32Remain -= transfer_bytes;
            }

            if (flash_progress != (10 * block_idx / total_block))
            {
                flash_progress = (10 * block_idx / total_block);
                LOG_I("%d %...", flash_progress * 10);
            }

            block_off++;
            block_idx++;
        }

        LOG_D("Program child[%d]...Done\n", i);
    }

exit_nuwriter_pack_program_mtd:

    if (page_buffer)
        rt_free_align(page_buffer);

    return ret;
}

static int nuwriter_readback_mtd(int fd, struct rt_mtd_nand_device *device)
{
    void *page_buffer = RT_NULL;
    uint32_t total_block, block_off;
    rt_err_t result;

    LOG_D("Start block: %d", device->block_start);
    LOG_D("End block: %d", device->block_end);
    LOG_D("Block number: %d", device->block_total);
    LOG_D("Plane number: %d", device->plane_num);
    LOG_D("Pages per Block: %d", device->pages_per_block);
    LOG_D("Page size: %d bytes", device->page_size);
    LOG_D("Spare size: %d bytes", device->oob_size);
    LOG_D("Total size: %d bytes (%d KB)",
          device->block_total * device->pages_per_block * device->page_size,
          device->block_total * device->pages_per_block * device->page_size / 1024);

    page_buffer = rt_malloc_align(device->page_size, 64);
    total_block = device->block_total;
    block_off = device->block_start;

    while (total_block > 0)
    {
        uint32_t total_page, page_off, page_idx;

        result = rt_mtd_nand_check_block(device, block_off);
        if (result != RT_EOK)
        {
            LOG_W("Block-%d is bad. Skip.", block_off);
            block_off++;
            continue;
        }

        total_page = device->pages_per_block;
        page_off = block_off * device->pages_per_block;
        page_idx = 0;
        while (page_idx < total_page)
        {
            rt_size_t transfer_bytes = device->page_size;

            rt_kprintf("-> total block:%d, bi: %d, pi: %d, page:(%d/%d)\n",
                       total_block, block_off, page_off,
                       page_idx, total_page);

            result = rt_mtd_nand_read(device,
                                      page_off + page_idx,
                                      page_buffer,
                                      device->page_size,
                                      RT_NULL,
                                      RT_NULL);
            if (result != RT_EOK)
            {
                LOG_E("Failed to read page(%d)", page_off + page_idx);
                goto exit_nuwriter_readback_mtd;
            }

            if ((fd >= 0) && (device->page_size != write(fd, page_buffer, device->page_size)))
            {
                LOG_E("Failed to write file(%d)", page_off + page_idx);
                goto exit_nuwriter_readback_mtd;
            }

            page_idx++;
        }
        block_off++;
        total_block--;
    }

exit_nuwriter_readback_mtd:

    return -1;
}

#endif

static int nuwriter_pack_program(const uint8_t *pu8PackFileBuf, uint64_t u64FileLength, rt_device_t device)
{
    int i, ret = -1;
    uint32_t u32CRC32ChkSum;
    S_NUWRITER_PACK_CHILD **ppsChildList = RT_NULL;

    S_NUWRITER_PACK_HDR *psPackHdr;
    S_NUWRITER_PACK_CHILD *psPackChild;

    LOG_D("[Program pack file]");

    if ((pu8PackFileBuf == RT_NULL) || (device == RT_NULL) || (u64FileLength == 0))
    {
        LOG_E("Wrong parameters\n");
        return -1;
    }

    psPackHdr = (S_NUWRITER_PACK_HDR *)pu8PackFileBuf;
    psPackChild = (S_NUWRITER_PACK_CHILD *)(pu8PackFileBuf + sizeof(S_NUWRITER_PACK_HDR));

    if ((psPackHdr->m_ui32Marker != NVT_MARKER) || (psPackHdr->m_ui32Reserve != 0xffffffff))
    {
        LOG_E("Wrong marker\n");
        goto exit_nuwriter_pack_program;
    }

    // Do CRC32 checksum
    u32CRC32ChkSum = crc32((uint32_t *)&psPackHdr->m_ui32TotalImageCount, u64FileLength - 8);
    if (u32CRC32ChkSum != psPackHdr->m_ui32CRC32)
    {
        LOG_E("Invalid CRC32 checksum value(0x%08X != 0x%08X)\n", u32CRC32ChkSum, psPackHdr->m_ui32CRC32);
        goto exit_nuwriter_pack_program;
    }

    ppsChildList = rt_malloc(psPackHdr->m_ui32TotalImageCount * sizeof(S_NUWRITER_PACK_CHILD *));
    if (!ppsChildList)
    {
        LOG_E("Failed to allocate memory %d", psPackHdr->m_ui32TotalImageCount);
        goto exit_nuwriter_pack_program;
    }

    for (i = 0; i < psPackHdr->m_ui32TotalImageCount; i++)
    {
        uint32_t next;
        ppsChildList[i] = psPackChild;
        next = PACK_ALIGN((uint32_t)psPackChild +
                          sizeof(S_NUWRITER_PACK_CHILD) +
                          psPackChild->m_ui64ImageLength);
        psPackChild = (S_NUWRITER_PACK_CHILD *)next;
    }

    if (rt_device_open(device, RT_DEVICE_OFLAG_RDWR) != RT_EOK)
    {
        LOG_E("Open device %s failed!\n", device->parent.name);
        LOG_E("Check %s's reference count\n", device->parent.name);
        goto exit_nuwriter_pack_program;
    }

    switch (device->type)
    {
    case RT_Device_Class_Block: //SD, EMMC, SPI NOR
        ret = nuwriter_pack_program_block(psPackHdr, ppsChildList, device);
        break;

#if defined(RT_USING_MTD_NAND)
    case RT_Device_Class_MTD:  //SPI NAND, Raw NAND
        ret = nuwriter_pack_program_mtd(psPackHdr, ppsChildList, (struct rt_mtd_nand_device *)device);
        break;
#endif

    default:
        LOG_E("Not supported storage type %d", device->type);
        goto exit_nuwriter_pack_program;
    }

exit_nuwriter_pack_program:

    if (device)
        rt_device_close(device);

    if (ppsChildList)
        rt_free(ppsChildList);

    return ret;
}



static int nuwriter_readback(int fd, rt_device_t device)
{
    int ret = -1;

    if (rt_device_open(device, RT_DEVICE_OFLAG_RDWR) != RT_EOK)
    {
        LOG_E("Open device %s failed!\n", device->parent.name);
        LOG_E("Check %s's reference count\n", device->parent.name);

        return -1;
    }

    switch (device->type)
    {
#if defined(RT_USING_MTD_NAND)
    case RT_Device_Class_MTD:
        ret = nuwriter_readback_mtd(fd, (struct rt_mtd_nand_device *)device);
        break;
#endif
    default:
        LOG_E("Not supported storage type %d", device->type);
        goto exit_nuwriter_readback;
    }

exit_nuwriter_readback:

    if (device)
        rt_device_close(device);

    return ret;
}

static int nuwriter_get_bootinfo(S_BOOT_INFO_T *psUserBootInfo)
{
    int ret = -1;
    rt_device_t device;
    E_POR_BOOTSRC bootsrc = nu_get_bootfrom_source();
    void *pvUnitBuf = RT_NULL;
    uint32_t u32UnitSize, u32NewerVerNum = 0;

    //bootsrc = evBootFrom_QSPI0_NOR;
    switch (bootsrc)
    {
    case evBootFrom_USBD:
    case evBootFrom_USBH0:
    case evBootFrom_USBH1:
        LOG_E("Not supported bootsrc %d.", bootsrc);
        return -1;
    default:
        if (s_sHdrInfo[bootsrc].szDevName == RT_NULL)
        {
            LOG_E("Invalid bootsrc %d", bootsrc);
            return -2;
        }
        LOG_D("bootsrc = %d(%s)", bootsrc, s_sHdrInfo[bootsrc].szDevName);
        break;
    }

    device = rt_device_find(s_sHdrInfo[bootsrc].szDevName);
    if (device == RT_NULL)
    {
        LOG_E("Failed to find %s.\n", s_sHdrInfo[bootsrc].szDevName);
        return -3;
    }

    if (rt_device_open(device, RT_DEVICE_OFLAG_RDWR) != RT_EOK)
    {
        LOG_E("Open device %s failed!\n", s_sHdrInfo[bootsrc].szDevName);
        LOG_E("Check %s's reference count\n", s_sHdrInfo[bootsrc].szDevName);

        return -4;
    }

    switch (device->type)
    {
#if defined(RT_USING_MTD_NAND)
    case RT_Device_Class_MTD:
    {
        struct rt_mtd_nand_device *mtd_device = (struct rt_mtd_nand_device *)device;
        u32UnitSize = mtd_device->pages_per_block * mtd_device->page_size;

        pvUnitBuf = rt_malloc_align(mtd_device->page_size, 64);
        if (pvUnitBuf == RT_NULL)
        {
            LOG_E("Failed to allocate memory!\n");
            goto exit_nuwriter_get_version;
        }
    }
    break;
#endif

    case RT_Device_Class_Block:
    {
        struct rt_device_blk_geometry geo;
        rt_memset(&geo, 0, sizeof(geo));
        if (rt_device_control(device, RT_DEVICE_CTRL_BLK_GETGEOME, &geo) != RT_EOK)
        {
            LOG_E("%s CTRL_BLK_GETGEOME failed!\n", s_sHdrInfo[bootsrc].szDevName);
            goto exit_nuwriter_get_version;
        }
        else if (geo.bytes_per_sector == 0)
        {
            LOG_E("Invalid block size!\n", s_sHdrInfo[bootsrc].szDevName);
            goto exit_nuwriter_get_version;
        }

        u32UnitSize = geo.bytes_per_sector;
        pvUnitBuf = rt_malloc_align(u32UnitSize, 64);
        if (pvUnitBuf == RT_NULL)
        {
            LOG_E("Failed to allocate memory!\n");
            goto exit_nuwriter_get_version;
        }
    }
    break;

    default:
        LOG_E("Not supported storage type %d", device->type);
        goto exit_nuwriter_get_version;
    }

    for (int i = 0; i < 2; i++)
    {
        switch (device->type)
        {

#if defined(RT_USING_MTD_NAND)
        case RT_Device_Class_MTD:
        {
            struct rt_mtd_nand_device *mtd_device = (struct rt_mtd_nand_device *)device;

            rt_err_t result = rt_mtd_nand_read(mtd_device,
                                               s_sHdrInfo[bootsrc].hdr_offset[i] * u32UnitSize,
                                               pvUnitBuf,
                                               mtd_device->page_size,
                                               RT_NULL,
                                               RT_NULL);
            if (result != RT_EOK)
            {
                LOG_E("Failed to read 0x%08X", i * u32UnitSize);
                goto exit_nuwriter_get_version;
            }
        }
        break;
#endif

        case RT_Device_Class_Block:
        {
            rt_size_t size = rt_device_read(device,
                                            s_sHdrInfo[bootsrc].hdr_offset[i],
                                            pvUnitBuf,
                                            1);
            if (size != 1)
            {
                LOG_E("Failed to read 0x%08X", i * u32UnitSize);
                goto exit_nuwriter_get_version;
            }
        }
        break;

        default:
            LOG_E("Not supported storage type %d", device->type);
            goto exit_nuwriter_get_version;

        } // switch (device->type)

        if (pvUnitBuf)
        {
            S_BOOT_INFO_T *psBootInfo = (S_BOOT_INFO_T *)pvUnitBuf;
            if (psBootInfo->m_u32Length > sizeof(S_BOOT_INFO_T))
            {
                LOG_E("Invalid boot info header length (%d > %d)", psBootInfo->m_u32Length, sizeof(S_BOOT_INFO_T));
                continue;
            }

            if (nuwriter_check_boot_info(psBootInfo, psBootInfo->m_u32Length) == 0)
            {
                LOG_I("%s's version number in header%d is [0x%08x].",
                      s_sHdrInfo[bootsrc].szDevName,
                      i,
                      psBootInfo->m_u32Version);

                if (psUserBootInfo && (u32NewerVerNum < psBootInfo->m_u32Version))
                {
                    u32NewerVerNum = psBootInfo->m_u32Version;
                    rt_memcpy(psUserBootInfo, psBootInfo, sizeof(S_BOOT_INFO_T));
                }
            }
            else
            {
                LOG_D("%s's header%d is invalid.", s_sHdrInfo[bootsrc].szDevName, i);
            }

        } //if (pvUnitBuf)

    } // for (int i = 0; i < 2; i++)

    if (u32NewerVerNum != 0)
    {
        LOG_I("%s's newer verion number is [0x%08x].",
              s_sHdrInfo[bootsrc].szDevName,
              u32NewerVerNum);
    }
    ret = 0;

exit_nuwriter_get_version:

    if (pvUnitBuf)
        rt_free_align(pvUnitBuf);

    if (device)
        rt_device_close(device);

    return ret;
}

int nuwriter_get_version(uint32_t *pu32VersionNumber)
{
    S_BOOT_INFO_T sUserBootInfo = {0};
    int ret = nuwriter_get_bootinfo(&sUserBootInfo);

    if ((ret == 0) && pu32VersionNumber)
    {
        *pu32VersionNumber = sUserBootInfo.m_u32Version;
    }

    return ret;
}

int nuwriter_get_image0_offset(uint32_t *pu32Img0Off)
{
    S_BOOT_INFO_T sUserBootInfo = {0};
    int ret = nuwriter_get_bootinfo(&sUserBootInfo);

    if ((ret == 0) && pu32Img0Off)
    {
        *pu32Img0Off = sUserBootInfo.m_sImage[0].m_u32Offset;
    }

    return ret;
}

int nu_ibr_get_version(void)
{
    int ret;
    uint32_t u32NewerVerNum = 0;
    ret = nuwriter_get_version(&u32NewerVerNum);
    return (ret == 0) ? (int)u32NewerVerNum : -1;
}
MSH_CMD_EXPORT(nu_ibr_get_version, To get booted image version number);

static struct optparse_long opts[] =
{
    { "help", 'h', OPTPARSE_NONE},
    { "file", 'f', OPTPARSE_REQUIRED},
    { "device", 'd', OPTPARSE_REQUIRED},
    { "program", 'p', OPTPARSE_NONE},
    { "readback", 'r', OPTPARSE_NONE},
    { NULL,  0,  OPTPARSE_NONE}
};

static void nuwriter_usage(void)
{
    rt_kprintf("usage: nuwriter [option] [target] ...\n\n");
    rt_kprintf("usage options:\n");
    rt_kprintf("  -h,              --help          Print defined help message.\n");
    rt_kprintf("  -f URI,          --file=URI      Specify NuWriter Pack file.(local).\n");
    rt_kprintf("  -d Device name,  --device=device Specify device name.\n");
    rt_kprintf("  -p,              --program       Execute program.\n");
    rt_kprintf("  -r,              --readback      Read back from storage.\n");
    rt_kprintf("\n");
    rt_kprintf("For examples,\n");
    rt_kprintf("  Pack file verification:\n");
    rt_kprintf("    nuwriter -f /mnt/udisk/pack.bin\n");
    rt_kprintf("  Pack file programming to SD/QSPINAND/RAWNAND/QSPINOR storage:\n");
    rt_kprintf("    nuwriter -f /mnt/udisk/pack.bin -d %s --program\n", STORAGE_DEVNAME_SD_EMMC1);
    rt_kprintf("    nuwriter -f /mnt/udisk/pack.bin -d %s --program\n", STORAGE_DEVNAME_QSPI0_NAND);
    rt_kprintf("    nuwriter -f /mnt/udisk/pack.bin -d %s --program\n", STORAGE_DEVNAME_RAW_NAND);
    rt_kprintf("    nuwriter -f /mnt/udisk/pack.bin -d %s --program\n", STORAGE_DEVNAME_QSPI0_NOR);
    rt_kprintf("  Read back content of specified MTD device to specified file:\n");
    rt_kprintf("    nuwriter -f /nand0.bin -d nand0 --readback\n");
}

static rt_err_t nuwriter_args_parse(int argc, char *argv[], S_NUWRITER_ARGS *psNuwriterArgs)
{
    int ch, option_index;
    struct optparse options;

    if (argc == 1)
    {
        psNuwriterArgs->Cmd = NUWRITER_COMMAND_HELP;
        return -1;
    }

    /* Parse cmd */
    optparse_init(&options, argv);
    while ((ch = optparse_long(&options, opts, &option_index)) != -1)
    {
        switch (ch)
        {
        case 'h': //help
            psNuwriterArgs->Cmd = NUWRITER_COMMAND_HELP;
            break;

        case 'f': //pack bin file path
            psNuwriterArgs->Cmd = NUWRITER_COMMAND_VERIFY;
            psNuwriterArgs->FilePath = options.optarg;
            break;

        case 'd': //device name
            psNuwriterArgs->DeviceName = options.optarg;
            break;

        case 'p':
            psNuwriterArgs->Cmd = NUWRITER_COMMAND_PROGRAM;
            break;

        case 'r':
            psNuwriterArgs->Cmd = NUWRITER_COMMAND_READBACK;
            break;

        default:
            return -1;
        }
    }

    return 0;
}


int nuwriter_exec(S_NUWRITER_ARGS *psNuwriterArgs)
{
    int fd = -1, ret = -1;
    struct stat sb;
    rt_device_t dev = RT_NULL;
    uint8_t *pu8DataBuf = RT_NULL;

    if (!psNuwriterArgs)
        goto exit_nuwriter_exec;

    switch (psNuwriterArgs->Cmd)
    {
    case NUWRITER_COMMAND_HELP:
        nuwriter_usage();
        ret = 0;
        goto exit_nuwriter_exec;

    case NUWRITER_COMMAND_PROGRAM:
    case NUWRITER_COMMAND_READBACK:
        dev = rt_device_find(psNuwriterArgs->DeviceName);
        break;

    case NUWRITER_COMMAND_VERIFY:
        break;

    default:
        LOG_E("Unknown command %d", psNuwriterArgs->Cmd);
        goto exit_nuwriter_exec;
    }

    if ((psNuwriterArgs->Cmd == NUWRITER_COMMAND_PROGRAM) ||
            (psNuwriterArgs->Cmd == NUWRITER_COMMAND_VERIFY))
    {
        if (stat(psNuwriterArgs->FilePath, &sb) != 0)
        {
            LOG_E("Can't stat %s", psNuwriterArgs->FilePath);
            goto exit_nuwriter_exec;
        }

        pu8DataBuf = rt_malloc(sb.st_size);
        if (!pu8DataBuf)
        {
            LOG_E("Can't allocate memory(%dB)", sb.st_size);
            goto exit_nuwriter_exec;
        }
        if (((fd = open(psNuwriterArgs->FilePath, O_RDONLY, 0)) < 0) ||
                (read(fd, pu8DataBuf, sb.st_size) != sb.st_size))
        {
            LOG_E("Can't open file or read(%s)", psNuwriterArgs->FilePath);
            goto exit_nuwriter_exec;
        }
        if (nuwriter_pack_verify((const uint8_t *)pu8DataBuf, (uint64_t)sb.st_size) < 0)
        {
            LOG_E("Failed to verify file(%s)", psNuwriterArgs->FilePath);
            goto exit_nuwriter_exec;
        }
        if (dev &&
                (psNuwriterArgs->Cmd == NUWRITER_COMMAND_PROGRAM) &&
                (nuwriter_pack_program((const uint8_t *)pu8DataBuf, (uint64_t)sb.st_size, dev) < 0))
        {
            goto exit_nuwriter_exec;
        }
    }
    else if (psNuwriterArgs->Cmd == NUWRITER_COMMAND_READBACK)
    {
        if ((fd = open(psNuwriterArgs->FilePath, O_CREAT | O_WRONLY, 0)) < 0)
        {
            LOG_E("Can't open file(%s)", psNuwriterArgs->FilePath);
            goto exit_nuwriter_exec;
        }
        if (dev && (nuwriter_readback(fd, dev) < 0))
        {
            goto exit_nuwriter_exec;
        }
    }

    ret = 0;

exit_nuwriter_exec:

    if (fd >= 0)
        close(fd);

    if (pu8DataBuf)
        rt_free(pu8DataBuf);

    return ret;
}

int nuwriter(int argc, char *argv[])
{
    int result = -1;
    S_NUWRITER_ARGS NuWriterArgs = {0};

    result = nuwriter_args_parse(argc, argv, &NuWriterArgs);
    if ((result != RT_EOK) ||
            (NuWriterArgs.FilePath == RT_NULL))
    {
        nuwriter_usage();
        goto exit_nuwriter;
    }

    switch (NuWriterArgs.Cmd)
    {
    case NUWRITER_COMMAND_HELP:
        nuwriter_usage();
        break;
    case NUWRITER_COMMAND_VERIFY:
    case NUWRITER_COMMAND_PROGRAM:
    case NUWRITER_COMMAND_READBACK:
        result = nuwriter_exec(&NuWriterArgs);
        break;
    default:
        break;
    }

exit_nuwriter:

    return result;
}
MSH_CMD_EXPORT(nuwriter, A nuwriter pack file writer);

#endif
