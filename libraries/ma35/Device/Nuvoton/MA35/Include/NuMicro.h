/**************************************************************************//**
 * @file     NuMicro.h
 * @brief    NuMicro peripheral access layer header file.
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __NUMICRO_H__
#define __NUMICRO_H__

#include "rtconfig.h"

#if defined(SOC_SERIES_MA35D1)

    #include "ma35d1.h"

#elif defined(SOC_SERIES_MA35D0)

    #include "ma35d0.h"

#elif defined(SOC_SERIES_MA35H0)

    #include "ma35h0.h"

#else

    #error "Unknown NuMicro series"

#endif

#endif  /* __NUMICRO_H__ */
