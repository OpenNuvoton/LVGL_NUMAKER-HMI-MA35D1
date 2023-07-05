/**************************************************************************//**
*
* @copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
*
* SPDX-License-Identifier: Apache-2.0
*
* Change Logs:
* Date            Author           Notes
* 2023-04-17      Wayne            First version
*
******************************************************************************/

#ifndef __CCAP_DEMO_H__
#define __CCAP_DEMO_H__

#include <rtthread.h>
#include <ccap_sensor.h>

typedef enum
{
#if defined(BSP_USING_CCAP0)
    evCCAP0,
#endif
#if defined(BSP_USING_CCAP1)
    evCCAP1,
#endif
    evCCAP_Cnt
} E_CCAP_INDEX;

typedef enum
{
    evSP_BINARIZATION,
    evSP_PACKET,
    evSP_PLANAR,
    evSAVEFMT_Cnt
} E_SAVE_PIPE;

int ccap_set_y_threshold(E_CCAP_INDEX evCCAPIdx, int i32YThd);  // 0 <= i32YThd < 256
int ccap_enable_binarization(E_CCAP_INDEX evCCAPIdx, int bOnOff); // 0: Disable, 1: Enable
int ccap_sensor_read_register(E_CCAP_INDEX evCCAPIdx, sensor_reg_val_t psSenorRegVal);
int ccap_sensor_write_register(E_CCAP_INDEX evCCAPIdx, sensor_reg_val_t psSenorRegVal);
int ccap_lcd_toggle(uint32_t u32Toggle);  // 0: Line offset=0, others: Line offset=LCDHeight/2
int ccap_save_image(E_CCAP_INDEX evCCAPIdx, const char *szSavedFileFolderPath, E_SAVE_PIPE evSavePipe);

ccap_view_info_t ccap_get_binarization(E_CCAP_INDEX evCCAPIdx);

#endif // __CCAP_DEMO_H__
