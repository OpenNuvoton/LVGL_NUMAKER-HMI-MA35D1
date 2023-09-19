/**************************************************************************//**
*
* @copyright (C) 2019 Nuvoton Technology Corp. All rights reserved.
*
* SPDX-License-Identifier: Apache-2.0
*
* Change Logs:
* Date            Author       Notes
* 2023-9-18       Wayne        First version
*
******************************************************************************/

#ifndef __NUWRITER_H__
#define __NUWRITER_H__

#include <rtthread.h>

typedef enum
{
    NUWRITER_COMMAND_HELP,
    NUWRITER_COMMAND_VERIFY,    // S_NUWRITER_ARGS.FilePath is a must.
    NUWRITER_COMMAND_PROGRAM,   // Both arguments of S_NUWRITER_ARGS.FilePath and S_NUWRITER_ARGS.DeviceName are a must.
    NUWRITER_COMMAND_READBACK,  // Both arguments of S_NUWRITER_ARGS.FilePath and S_NUWRITER_ARGS.DeviceName are a must.
    NUWRITER_COMMAND_CNT
} NUWRITER_COMMAND;

typedef struct
{
    NUWRITER_COMMAND Cmd;
    char *FilePath;     // File path of pack.bin created by PC-NuWriter utility
    char *DeviceName;   // RT-Thread device name
} S_NUWRITER_ARGS;

#define STORAGE_DEVNAME_QSPI0_NOR     "sf_whole"
#define STORAGE_DEVNAME_QSPI0_NAND    "nand2"
#define STORAGE_DEVNAME_SD_EMMC0      "sd0"
#define STORAGE_DEVNAME_SD_EMMC1      "sd1"
#define STORAGE_DEVNAME_RAW_NAND      "rawnd2"

int nuwriter_get_image0_offset(uint32_t *pu32Img0Off);
int nuwriter_get_version(uint32_t *pu32VersionNumber);
int nuwriter_exec(S_NUWRITER_ARGS* psNuWriterArgs);


#endif /* __NUWRITER_H__ */
