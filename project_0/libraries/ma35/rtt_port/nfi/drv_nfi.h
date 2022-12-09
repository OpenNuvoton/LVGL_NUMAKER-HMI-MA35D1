/**************************************************************************//**
*
* @copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
*
* SPDX-License-Identifier: Apache-2.0
*
* Change Logs:
* Date            Author           Notes
* 2022-5-22       Wayne            First version
*
******************************************************************************/

#ifndef __DRV_NFI_H__
#define __DRV_NFI_H__

#include <rtthread.h>

rt_err_t rt_hw_mtd_nfi_register(const char *device_name);

#endif //__DRV_NFI_H__
