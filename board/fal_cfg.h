/**************************************************************************//**
*
* @copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
*
* SPDX-License-Identifier: Apache-2.0
*
* Change Logs:
* Date            Author       Notes
* 2023-9-15       Wayne        First version
*
******************************************************************************/

#ifndef _FAL_CFG_H_
#define _FAL_CFG_H_

#include <rtconfig.h>
#include <board.h>

#define PARTITION_NAME_SF     "sf"
#define PARTITION_NAME_WHOLE  "sf_whole"

/* ===================== Flash device Configuration ========================= */
#if defined(RT_USING_SFUD)
extern struct fal_flash_dev nor_flash0;

/* -flash device table------------------------------------------------------- */
#define FAL_FLASH_DEV_TABLE                                                    \
{                                                                              \
    &nor_flash0,                                                               \
}
#else
#define FAL_FLASH_DEV_TABLE                                                    \
{                                                                              \
    0                                                                          \
}
#endif

/* ====================== Partition Configuration ============================ */
#ifdef FAL_PART_HAS_TABLE_CFG

/* partition table------------------------------------------------------------ */
#define FAL_PART_TABLE                                                         \
{                                                                              \
    {FAL_PART_MAGIC_WORD, PARTITION_NAME_SF,    FAL_USING_NOR_FLASH_DEV_NAME, 0x840000,     0x17C0000, 0}, \
    {FAL_PART_MAGIC_WORD, PARTITION_NAME_WHOLE, FAL_USING_NOR_FLASH_DEV_NAME,        0,  32*1024*1024, 0}, \
}
#endif /* FAL_PART_HAS_TABLE_CFG */

#endif /* _FAL_CFG_H_ */
