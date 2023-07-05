/**************************************************************************//**
 * @file     nu_disp.c
 * @brief    DISP driver source file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/

#include "NuMicro.h"

/** @addtogroup Standard_Driver Standard Driver
  @{
*/

/** @addtogroup DISP_Driver DISP Driver
  @{
*/

/** @addtogroup DISP_EXPORTED_FUNCTIONS DISP Exported Functions
  @{
*/

static const DISP_LCD_INFO *g_psDispLcdInfo_Curr = NULL;

static uint32_t DISP_GetBitPerPixel(E_FB_FMT eFbFmt)
{
    uint32_t u32bpp;

    switch (eFbFmt)
    {
    case eFBFmt_MONOCHROME:
    case eFBFmt_R8:
    case eFBFmt_INDEX8:
    case eFBFmt_NV12:
    case eFBFmt_NV16:
        u32bpp = 8U;
        break;

    case eFBFmt_X4R4G4B4:
    case eFBFmt_A4R4G4B4:
    case eFBFmt_X1R5G5B5:
    case eFBFmt_A1R5G5B5:
    case eFBFmt_R5G6B5:
    case eFBFmt_YUY2:
    case eFBFmt_UYVY:
    case eFBFmt_YV12:
    case eFBFmt_RG16:
        u32bpp = 16U;
        break;

    case eFBFmt_INDEX1:
        u32bpp = 1U;
        break;

    case eFBFmt_INDEX2:
        u32bpp = 2U;
        break;

    case eFBFmt_INDEX4:
        u32bpp = 4U;
        break;

    default:
        u32bpp = 32U;
        break;
    }
    return u32bpp;
}

uint64_t DISP_GeneratePixelClk(uint32_t u32PixClkInHz)
{
    uint64_t u64PixClkOut;

    /* Set new VPLL clock frequency. */
    u32PixClkInHz <<= 1U;
    u64PixClkOut = CLK_SetPLLFreq(VPLL, PLL_OPMODE_INTEGER, __HXT, (uint64_t)u32PixClkInHz);

    /* Waiting clock ready */
    CLK_WaitClockReady(CLK_STATUS_VPLLSTB_Msk);

    return u64PixClkOut;
}

void DISP_SuspendPixelClk(void)
{
    /* Stop VPLL forcely. */
    CLK_SetPLLPowerDown(VPLL);
}

void DISP_SetTiming(DISP_LCD_TIMING *psLCDTiming)
{
    uint32_t u32HEnd, u32HTotal, u32HSyncStart, u32HSyncEnd;
    uint32_t u32VEnd, u32VTotal, u32VSyncStart, u32VSyncEnd;
    uint32_t u32Value;

    /* Set H- timing */
    u32HEnd = psLCDTiming->u32HA;
    u32HTotal = u32HEnd + psLCDTiming->u32HFP + psLCDTiming->u32HBP + psLCDTiming->u32HSL;
    u32HSyncStart = u32HEnd + psLCDTiming->u32HFP;
    u32HSyncEnd = u32HSyncStart + psLCDTiming->u32HSL;

    u32Value = (u32HTotal << DISP_HDisplay0_TOTAL_Pos) | (u32HEnd << DISP_HDisplay0_DISPLAY_END_Pos);
    DISP->HDisplay0 = u32Value;

    u32Value = 0U;
    if (psLCDTiming->eHSPP != ePolarity_Disable)
    {
        u32Value = (psLCDTiming->eHSPP << DISP_HSync0_POLARITY_Pos) | DISP_HSync0_PULSE_Msk;
    }

    u32Value |= (u32HSyncEnd << DISP_HSync0_END_Pos) | (u32HSyncStart << DISP_HSync0_START_Pos);
    DISP->HSync0 = u32Value;

    /* Set V- timing */
    u32VEnd = psLCDTiming->u32VA;
    u32VTotal = u32VEnd + psLCDTiming->u32VFP + psLCDTiming->u32VBP + psLCDTiming->u32VSL;
    u32VSyncStart = u32VEnd + psLCDTiming->u32VFP;
    u32VSyncEnd = u32VSyncStart + psLCDTiming->u32VSL;

    u32Value = (u32VTotal << DISP_VDisplay0_TOTAL_Pos) | (u32VEnd << DISP_VDisplay0_DISPLAY_END_Pos);
    DISP->VDisplay0 = u32Value;

    u32Value = 0U;
    if (psLCDTiming->eVSPP != ePolarity_Disable)
    {
        u32Value = (psLCDTiming->eVSPP << DISP_VSync0_POLARITY_Pos) | DISP_VSync0_PULSE_Msk;
    }

    u32Value |= (u32VSyncEnd << DISP_VSync0_END_Pos) | (u32VSyncStart << DISP_VSync0_START_Pos);
    DISP->VSync0 = u32Value;
}

void DISP_SetCursorPosition(uint32_t u32X, uint32_t u32Y)
{
    DISP_CURSOR_SET_POSITION(u32X, u32Y);
}

void DISP_InitCursor(DISP_CURSOR_CONF *psCursorConf)
{
    DISP->CursorModuleClockGatingControl = 0;

    DISP->CursorAddress = psCursorConf->u32FrameBuffer;
    DISP->CursorBackground = psCursorConf->u32BGColor;
    DISP->CursorForeground = psCursorConf->u32FGColor;

    DISP->CursorLocation = ((psCursorConf->sInitPosition.u32X << DISP_CursorLocation_X_Pos) & DISP_CursorLocation_X_Msk) | \
                           ((psCursorConf->sInitPosition.u32Y << DISP_CursorLocation_Y_Pos) & DISP_CursorLocation_Y_Msk);

    DISP_CURSOR_SET_POSITION(psCursorConf->sInitPosition.u32X, psCursorConf->sInitPosition.u32Y);

    DISP->CursorConfig = \
                         ((psCursorConf->eFmt << DISP_CursorConfig_FORMAT_Pos) & DISP_CursorConfig_FORMAT_Msk) | \
                         ((psCursorConf->sHotSpot.u32X << DISP_CursorConfig_HOT_SPOT_X_Pos) & DISP_CursorConfig_HOT_SPOT_X_Msk) | \
                         ((psCursorConf->sHotSpot.u32Y << DISP_CursorConfig_HOT_SPOT_Y_Pos) & DISP_CursorConfig_HOT_SPOT_Y_Msk);

}

void DISP_SetPanelConf(DISP_PANEL_CONF *psPanelConf)
{
    uint32_t u32Value = 0U;

    if (psPanelConf->eDEP != ePolarity_Disable)
    {
        u32Value = (psPanelConf->eDEP << DISP_PanelConfig0_DE_POLARITY_Pos) | DISP_PanelConfig0_DE_Msk;
    }

    if (psPanelConf->eDP != ePolarity_Disable)
    {
        u32Value |= ((psPanelConf->eDP << DISP_PanelConfig0_DATA_POLARITY_Pos) | DISP_PanelConfig0_DATA_ENABLE_Msk);
    }

    if (psPanelConf->eCP != ePolarity_Disable)
    {
        u32Value |= ((psPanelConf->eCP << DISP_PanelConfig0_CLOCK_POLARITY_Pos) | DISP_PanelConfig0_CLOCK_Msk);
    }

    DISP->DbiConfig0 = 0x00000080U;
    DISP->DpiConfig0 = psPanelConf->eDpiFmt << DISP_DpiConfig0_DPI_DATA_FORMAT_Pos;
    DISP->PanelConfig0 = u32Value;
}

int DISP_SetTransparencyMode(E_DISP_LAYER eLayer, E_TRANSPARENCY_MODE eTM)
{
    switch (eLayer)
    {

    case eLayer_Video:
        DISP->FrameBufferConfig0 &= ~DISP_FrameBufferConfig0_TRANSPARENCY_Msk;
        DISP->FrameBufferConfig0 |= (eTM << DISP_FrameBufferConfig0_TRANSPARENCY_Pos);
        break;

    case eLayer_Overlay:
        DISP->OverlayConfig0 &= ~DISP_OverlayConfig0_TRANSPARENCY_Msk;
        DISP->OverlayConfig0 |= (eTM << DISP_OverlayConfig0_TRANSPARENCY_Pos);
        break;

    default:
        return -1;
    }

    return 0;
}

uint32_t DISP_LCDTIMING_GetFPS(const DISP_LCD_TIMING *psDispLCDTiming)
{
    static uint32_t u32FPS = 0;

    if (psDispLCDTiming != NULL)
    {
        uint32_t u32HTotal, u32VTotal;

        u32HTotal = psDispLCDTiming->u32HA + psDispLCDTiming->u32HBP + psDispLCDTiming->u32HFP + psDispLCDTiming->u32HSL;
        u32VTotal = psDispLCDTiming->u32VA + psDispLCDTiming->u32VBP + psDispLCDTiming->u32VFP + psDispLCDTiming->u32VSL;

        u32FPS =  psDispLCDTiming->u32PCF / u32HTotal / u32VTotal;
    }

    return u32FPS;
}

uint32_t DISP_LCDTIMING_SetFPS(uint32_t u32FPS)
{
    if (g_psDispLcdInfo_Curr != NULL)
    {
        uint32_t u32HTotal, u32VTotal;
        const DISP_LCD_TIMING *psDispLCDTiming = &g_psDispLcdInfo_Curr->sLcdTiming;

        u32HTotal = psDispLCDTiming->u32HA + psDispLCDTiming->u32HBP + psDispLCDTiming->u32HFP + psDispLCDTiming->u32HSL;
        u32VTotal = psDispLCDTiming->u32VA + psDispLCDTiming->u32VBP + psDispLCDTiming->u32VFP + psDispLCDTiming->u32VSL;

        DISP_SuspendPixelClk();

        DISP_GeneratePixelClk(u32HTotal * u32VTotal * u32FPS);

        return u32FPS;
    }

    return 0;
}


int DISP_Trigger(E_DISP_LAYER eLayer, uint32_t u32Action)
{
    switch (eLayer)
    {
    case eLayer_Video:
        if (g_psDispLcdInfo_Curr && u32Action)
        {
            /* Start engine clock. */
            CLK_EnableModuleClock(DCU_MODULE);

            /* Generate Pixel clock */
            DISP_GeneratePixelClk(g_psDispLcdInfo_Curr->sLcdTiming.u32PCF);

            DISP->FrameBufferConfig0 |= DISP_FrameBufferConfig0_OUTPUT_Msk;
        }
        else
        {
            DISP->FrameBufferConfig0 &= ~DISP_FrameBufferConfig0_OUTPUT_Msk;

            /* Stop pixel clock. */
            DISP_SuspendPixelClk();

            /* Stop engine clock. */
            CLK_DisableModuleClock(DCU_MODULE);
        }
        break;

    case eLayer_Overlay:
        if (u32Action)
        {
            DISP->OverlayConfig0 = (DISP->OverlayConfig0 & ~DISP_OverlayConfig0_ENABLE_Msk) | DISP_OverlayConfig0_ENABLE_Msk;
        }
        else
        {
            DISP->OverlayConfig0 &= ~DISP_OverlayConfig0_ENABLE_Msk;
        }
        break;

    case eLayer_Cursor:
        if (u32Action)
        {
            DISP_CURSOR_SET_FORMAT(eCURSOR_FMT_ARGB8888);
        }
        else
        {
            DISP_CURSOR_SET_FORMAT(eCURSOR_FMT_DISABLE);
        }
        break;

    default:
        return -1;
    }

    return 0;
}

int DISP_SetBlendOpMode(E_DC_BLEND_MODE eDCBM, E_GLOBAL_ALPHA_MODE eGloAM_Src, E_GLOBAL_ALPHA_MODE eGloAM_Dst)
{
    uint32_t u32Value;

    u32Value = (eGloAM_Dst << DISP_OverlayAlphaBlendConfig0_DST_GLOBAL_ALPHA_MODE_Pos) |
               (eGloAM_Src << DISP_OverlayAlphaBlendConfig0_SRC_GLOBAL_ALPHA_MODE_Pos);

    switch (eDCBM)
    {
    case DC_BLEND_MODE_CLEAR:
        u32Value |= (eBM_ZERO << DISP_OverlayAlphaBlendConfig0_SRC_BLENDING_MODE_Pos) |
                    (eBM_ZERO << DISP_OverlayAlphaBlendConfig0_DST_BLENDING_MODE_Pos);
        break;
    case DC_BLEND_MODE_SRC:
        u32Value |= (eBM_ONE << DISP_OverlayAlphaBlendConfig0_SRC_BLENDING_MODE_Pos) |
                    (eBM_ZERO << DISP_OverlayAlphaBlendConfig0_DST_BLENDING_MODE_Pos);
        break;
    case DC_BLEND_MODE_DST:
        u32Value |= (eBM_ZERO << DISP_OverlayAlphaBlendConfig0_SRC_BLENDING_MODE_Pos) |
                    (eBM_ONE << DISP_OverlayAlphaBlendConfig0_DST_BLENDING_MODE_Pos);
        break;
    case DC_BLEND_MODE_SRC_OVER:
        u32Value |= (eBM_ONE << DISP_OverlayAlphaBlendConfig0_SRC_BLENDING_MODE_Pos) |
                    (eBM_INVERSED << DISP_OverlayAlphaBlendConfig0_DST_BLENDING_MODE_Pos);
        break;
    case DC_BLEND_MODE_DST_OVER:
        u32Value |= (eBM_INVERSED << DISP_OverlayAlphaBlendConfig0_SRC_BLENDING_MODE_Pos) |
                    (eBM_ONE << DISP_OverlayAlphaBlendConfig0_DST_BLENDING_MODE_Pos);
        break;
    case DC_BLEND_MODE_SRC_IN:
        u32Value |= (eBM_NORMAL << DISP_OverlayAlphaBlendConfig0_SRC_BLENDING_MODE_Pos) |
                    (eBM_ZERO << DISP_OverlayAlphaBlendConfig0_DST_BLENDING_MODE_Pos);
        break;
    case DC_BLEND_MODE_DST_IN:
        u32Value |= (eBM_ZERO << DISP_OverlayAlphaBlendConfig0_SRC_BLENDING_MODE_Pos) |
                    (eBM_NORMAL << DISP_OverlayAlphaBlendConfig0_DST_BLENDING_MODE_Pos);
        break;
    case DC_BLEND_MODE_SRC_OUT:
        u32Value |= (eBM_INVERSED << DISP_OverlayAlphaBlendConfig0_SRC_BLENDING_MODE_Pos) |
                    (eBM_ZERO << DISP_OverlayAlphaBlendConfig0_DST_BLENDING_MODE_Pos);
        break;
    default:
        return -1;
    }

    DISP->OverlayAlphaBlendConfig0 = u32Value;

    return 0;
}

void DISP_SetBlendValue(uint32_t u32GloAV_Src, uint32_t u32GloAV_Dst)
{
    DISP->OverlaySrcGlobalColor0 = u32GloAV_Src;
    DISP->OverlayDstGlobalColor0 = u32GloAV_Dst;
}

void DISP_SetColorKeyValue(uint32_t u32ColorKeyLow, uint32_t u32ColorKeyHigh)
{
    DISP->OverlayColorKey0 = u32ColorKeyLow;
    DISP->OverlayColorKeyHigh0 = u32ColorKeyHigh;
}

int DISP_SetFBAddr(E_DISP_LAYER eLayer, uint32_t u32DMAFBStartAddr)
{
    /* Check Start address is 128B alignment. */
    if ((u32DMAFBStartAddr % 128) != 0)
        return -1;

    switch (eLayer)
    {
    case eLayer_Video:
    {
        uint32_t u32ResWidth, u32ResHeight;

        /* Set frame buffer address registers */
        // Y, RGB
        DISP->FrameBufferAddress0 = u32DMAFBStartAddr;
        u32ResWidth = (DISP->FrameBufferSize0 & DISP_FrameBufferSize0_WIDTH_Msk) >> DISP_FrameBufferSize0_WIDTH_Pos;
        u32ResHeight = (DISP->FrameBufferSize0 & DISP_FrameBufferSize0_HEIGHT_Msk) >> DISP_FrameBufferSize0_HEIGHT_Pos;

        // U
        DISP->FrameBufferUPlanarAddress0 = u32DMAFBStartAddr + u32ResWidth * u32ResHeight;
        DISP->FrameBufferUStride0 = u32ResWidth;

        // V
        DISP->FrameBufferVPlanarAddress0 = DISP->FrameBufferUPlanarAddress0 + u32ResWidth * u32ResHeight / 2;
        DISP->FrameBufferVStride0 = u32ResWidth / 2;
    }
    break;

    case eLayer_Overlay:
    {
        uint32_t u32ResWidth, u32ResHeight;

        /* Set frame buffer address registers */
        DISP->OverlayAddress0 = u32DMAFBStartAddr;
        u32ResWidth = (DISP->OverlaySize0 & DISP_OverlaySize0_WIDTH_Msk) >> DISP_OverlaySize0_WIDTH_Pos;
        u32ResHeight = (DISP->OverlaySize0 & DISP_OverlaySize0_HEIGHT_Msk) >> DISP_OverlaySize0_HEIGHT_Pos;

        // U
        DISP->OverlayUPlanarAddress0 = u32DMAFBStartAddr + u32ResWidth * u32ResHeight;
        DISP->OverlayUStride0 = u32ResWidth;

        // V
        DISP->OverlayVPlanarAddress0 = DISP->OverlayUPlanarAddress0 + u32ResWidth * u32ResHeight / 2;
        DISP->OverlayVStride0 = u32ResWidth / 2;
    }
    break;

    case eLayer_Cursor:
        /* Set frame buffer address registers */
        DISP->CursorAddress = u32DMAFBStartAddr;
        break;

    default:
        return -1;
    }
    return 0;
}

int DISP_SetFBFmt(E_DISP_LAYER eLayer, E_FB_FMT eFbFmt, uint32_t u32Pitch)
{
    switch (eLayer)
    {
    case eLayer_Video:
    {
        uint32_t u32FBConf = DISP->FrameBufferConfig0;
        DISP->FrameBufferConfig0 = 0;
        DISP->FrameBufferStride0 = u32Pitch;
        u32FBConf = (u32FBConf & ~DISP_FrameBufferConfig0_FORMAT_Msk) |
                    (eFbFmt << DISP_FrameBufferConfig0_FORMAT_Pos) |
                    DISP_FrameBufferConfig0_RESET_Msk;

        DISP->FrameBufferConfig0 = u32FBConf;

        break;
    }
    default:
        return -2;
    }

    return 0;
}


int DISP_SetFBConfig(E_DISP_LAYER eLayer, E_FB_FMT eFbFmt, uint32_t u32ResWidth, uint32_t u32ResHeight, uint32_t u32DMAFBStartAddr)
{
    uint32_t u32bpp;

    /* Check Start address is 128B alignment. */
    if ((u32DMAFBStartAddr % 128) != 0)
        return -1;

    u32bpp = DISP_GetBitPerPixel(eFbFmt);

    switch (eLayer)
    {
    case eLayer_Video:

        DISP->FrameBufferUPlanarAddress0 = u32DMAFBStartAddr + u32ResWidth * u32ResHeight;
        DISP->FrameBufferVPlanarAddress0 = DISP->FrameBufferUPlanarAddress0 + u32ResWidth * u32ResHeight / 2;
        DISP->FrameBufferUStride0 = u32ResWidth;
        DISP->FrameBufferVStride0 = u32ResWidth / 2;
        DISP->IndexColorTableIndex0 = 0U;

        DISP->FrameBufferSize0 = (u32ResHeight << DISP_FrameBufferSize0_HEIGHT_Pos) |
                                 (u32ResWidth << DISP_FrameBufferSize0_WIDTH_Pos);

        DISP->FrameBufferStride0 = u32ResWidth * (u32bpp >> 3U);

        /* Set frame buffer address registers */
        DISP->FrameBufferAddress0 = u32DMAFBStartAddr;

        DISP->FrameBufferConfig0 = (eFbFmt << DISP_FrameBufferConfig0_FORMAT_Pos) |
                                   (eYUV_709_BT709 << DISP_FrameBufferConfig0_YUV_Pos) |
                                   (DISP_FrameBufferConfig0_RESET_Msk);

        break;

    case eLayer_Overlay:

        DISP->OverlayStride0 = u32ResWidth * (u32bpp >> 3U);

        /*
         * eFbFmt is fixed in eFBFmt_A8R8G8B8.
         */
        DISP->OverlayConfig0 = (eFBFmt_A8R8G8B8 << DISP_OverlayConfig0_FORMAT_Pos) |
                               (0 << DISP_OverlayConfig0_SWIZZLE_Pos) |
                               (0 << DISP_OverlayConfig0_TRANSPARENCY_Pos) |
                               (eYUV_709_BT709 << DISP_OverlayConfig0_YUV_Pos) |
                               (0 << DISP_OverlayConfig0_CLEAR_Pos);

        /* Set frame buffer address registers */
        DISP->OverlayAddress0 = u32DMAFBStartAddr;

        DISP->OverlaySize0 = (u32ResHeight << DISP_OverlaySize0_HEIGHT_Pos) |
                             (u32ResWidth << DISP_OverlaySize0_WIDTH_Pos);

        DISP->OverlayUPlanarAddress0 = u32DMAFBStartAddr + u32ResWidth * u32ResHeight;
        DISP->OverlayVPlanarAddress0 = DISP->OverlayUPlanarAddress0 + u32ResWidth * u32ResHeight / 2;
        DISP->OverlayUStride0 = u32ResWidth;
        DISP->OverlayVStride0 = u32ResWidth / 2;

        DISP->OverlayTL0 = (0U << DISP_OverlayTL0_Y_Pos) | (0 << DISP_OverlayTL0_X_Pos);
        DISP->OverlayBR0 = (u32ResHeight << DISP_OverlayBR0_Y_Pos) | (u32ResWidth << DISP_OverlayBR0_X_Pos);

        /* Default setting */
        DISP_SetBlendOpMode(DC_BLEND_MODE_SRC_OVER, eGloAM_NORMAL, eGloAM_NORMAL);
        DISP->OverlayClearValue0 = 0U;
        DISP_SetColorKeyValue(0U, 0U);

        break;

    default:
        return -2;
    }

    return 0;
}

int32_t DISP_LCDInit(const DISP_LCD_INFO *psLCDInfo)
{
    vu32 vu32UsDelay = CLK_GetPLLClockFreq(CAPLL) / 1000000;
    vu32 vu32Timeout;
    DISP_LCD_TIMING *psLCDTiming = (DISP_LCD_TIMING *)&psLCDInfo->sLcdTiming;
    DISP_PANEL_CONF *psPanelConf = (DISP_PANEL_CONF *)&psLCDInfo->sPanelConf;

    /* Store to current. */
    g_psDispLcdInfo_Curr = psLCDInfo;

    /* Start engine clock. */
    DISP_SuspendPixelClk();

    /* Reset */
    SYS->IPRST0 |= SYS_IPRST0_DISPCRST_Msk;
    vu32Timeout = 100 * vu32UsDelay;
    while (vu32Timeout--);
    SYS->IPRST0 &= ~SYS_IPRST0_DISPCRST_Msk;
    vu32Timeout = 100 * vu32UsDelay;
    while (vu32Timeout--);

    DISP->FrameBufferConfig0 = 0U;
    DISP->AQHiClockControl = 0x00071900U;
    DISP->AQHiClockControl = 0x00070900U;

    /* Delay 5ms */
    vu32Timeout = 5000 * vu32UsDelay;
    while (vu32Timeout--);

    /* Set timing */
    DISP_SetTiming(psLCDTiming);

    /* Set Panel config */
    DISP_SetPanelConf(psPanelConf);

    return 0;
}

int32_t DISP_LCDDeinit(void)
{
    /* Stop engine clock */
    DISP_SuspendPixelClk();

    /* Stop engine clock. */
    CLK_DisableModuleClock(DCU_MODULE);

    g_psDispLcdInfo_Curr = NULL;

    return 0;
}

/*@}*/ /* end of group DISP_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group DISP_Driver */

/*@}*/ /* end of group Standard_Driver */




