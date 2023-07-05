/**************************************************************************//**
 * @file     nu_disp.h
 * @brief    DISP driver header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __NU_DISP_H__
#define __NU_DISP_H__

#ifdef __cplusplus
extern "C"
{
#endif


/** @addtogroup Standard_Driver Standard Driver
  @{
*/

/** @addtogroup DISP_Driver DISP Driver
  @{
*/

/** @addtogroup DISP_EXPORTED_CONSTANTS DISP Exported Constants
  @{
*/

typedef enum
{
    ePolarity_Disable  = -1,
    ePolarity_Positive = 0,
    ePolarity_Negative = 1
} E_POLARITY;

typedef enum
{
    eDPIFmt_D16CFG1,
    eDPIFmt_D16CFG2,
    eDPIFmt_D16CFG3,
    eDPIFmt_D18CFG1,
    eDPIFmt_D18CFG2,
    eDPIFmt_D24
} E_DPI_DATA_FMT;

typedef enum
{
    eLayer_Video   = 0,
    eLayer_Overlay = 1,
    eLayer_Cursor  = 2,
    eLayer_Cnt
} E_DISP_LAYER;

typedef enum
{
    eYUV_709_BT709   = 1,
    eYUV_2020_BT2020 = 3,
} E_YUV_STANDARD;

typedef enum
{
    eFBFmt_X4R4G4B4      = 0,
    eFBFmt_A4R4G4B4      = 1,
    eFBFmt_X1R5G5B5      = 2,
    eFBFmt_A1R5G5B5      = 3,
    eFBFmt_R5G6B5        = 4,
    eFBFmt_X8R8G8B8      = 5,
    eFBFmt_A8R8G8B8      = 6,
    eFBFmt_YUY2          = 7,
    eFBFmt_UYVY          = 8,
    eFBFmt_INDEX8        = 9,
    eFBFmt_MONOCHROME    = 10,
    eFBFmt_YV12          = 15,
    eFBFmt_A8            = 16,
    eFBFmt_NV12          = 17,
    eFBFmt_NV16          = 18,
    eFBFmt_RG16          = 19,
    eFBFmt_R8            = 20,
    eFBFmt_NV12_10BIT    = 21,
    eFBFmt_A2R10G10B10   = 22,
    eFBFmt_NV16_10BIT    = 23,
    eFBFmt_INDEX1        = 24,
    eFBFmt_INDEX2        = 25,
    eFBFmt_INDEX4        = 26,
    eFBFmt_P010          = 27,
    eFBFmt_NV12_10BIT_L1 = 28,
    eFBFmt_NV16_10BIT_L1 = 29
} E_FB_FMT;

typedef enum
{
    eOPAQUE,
    eMASK,
    eKEY
} E_TRANSPARENCY_MODE;

typedef enum
{
    DC_BLEND_MODE_CLEAR,
    DC_BLEND_MODE_SRC,
    DC_BLEND_MODE_DST,
    DC_BLEND_MODE_SRC_OVER,
    DC_BLEND_MODE_DST_OVER,
    DC_BLEND_MODE_SRC_IN,
    DC_BLEND_MODE_DST_IN,
    DC_BLEND_MODE_SRC_OUT
} E_DC_BLEND_MODE;

typedef enum
{
    eGloAM_NORMAL,
    eGloAM_GLOBAL,
    eGloAM_SCALED
} E_GLOBAL_ALPHA_MODE;


typedef enum
{
    eBM_ZERO,
    eBM_ONE,
    eBM_NORMAL,
    eBM_INVERSED,
    eBM_COLOR,
    eBM_COLOR_INVERSED,
    eBM_SATURATED_ALPHA,
    eBM_SATURATED_DEST_ALPHA
} E_BLENDING_MODE;


typedef enum
{
    eCURSOR_FMT_DISABLE = 0,
    eCURSOR_FMT_MASKED,
    eCURSOR_FMT_ARGB8888
} E_CURSOR_FMT;

typedef struct
{
    uint32_t  u32X;
    uint32_t  u32Y;
} S_COORDINATE;

typedef struct
{
    /*
    htotal: u32HA + u32HBP + u32HFP + u32HSL
    vtotal: u32VA + u32VBP + u32VFP + u32VSL
    clock-frequency: htotal * vtotal * fps
    */
    uint32_t u32PCF;     // Pixel Clock Frequency

    uint32_t u32HA;      // Horizontal Active
    uint32_t u32HSL;     // Horizontal Sync Length
    uint32_t u32HFP;     // Horizontal Front Porch
    uint32_t u32HBP;     // Horizontal Back Porch
    uint32_t u32VA;      // Vertical Active
    uint32_t u32VSL;     // Vertical Sync Len
    uint32_t u32VFP;     // Vertical Front Porch
    uint32_t u32VBP;     // Vertical Back Porch

    E_POLARITY eHSPP;    // HSync Pulse Polarity
    E_POLARITY eVSPP;    // VSync Pulse Polarity

} DISP_LCD_TIMING;

typedef struct
{
    E_DPI_DATA_FMT eDpiFmt; // DPI Data Format
    E_POLARITY     eDEP;    // DE Polarity
    E_POLARITY     eDP;     // DATA Polarity
    E_POLARITY     eCP;     // CLOCK Polarity
} DISP_PANEL_CONF;

typedef struct
{
    uint32_t u32ResolutionWidth;
    uint32_t u32ResolutionHeight;
    DISP_LCD_TIMING sLcdTiming;
    DISP_PANEL_CONF sPanelConf;
} DISP_LCD_INFO;

typedef struct
{
    E_CURSOR_FMT  eFmt;
    uint32_t      u32FrameBuffer;

    S_COORDINATE  sHotSpot;
    S_COORDINATE  sInitPosition;

    union
    {
        uint32_t u32BGColor;
        struct
        {
            uint8_t B;
            uint8_t G;
            uint8_t R;
        } S_BGCOLOR;
    };

    union
    {
        uint32_t u32FGColor;
        struct
        {
            uint8_t B;
            uint8_t G;
            uint8_t R;
        } S_FGCOLOR;
    };

} DISP_CURSOR_CONF;

#define DISP_ENABLE_INT()     (DISP->DisplayIntrEnable |=  DISP_DisplayIntrEnable_DISP0_Msk)
#define DISP_DISABLE_INT()    (DISP->DisplayIntrEnable &= ~DISP_DisplayIntrEnable_DISP0_Msk)
#define DISP_GET_INTSTS()     (DISP->DisplayIntr & DISP_DisplayIntr_DISP0_Msk)

#define DISP_CURSOR_SET_FORMAT(f)  (DISP->CursorConfig = (DISP->CursorConfig & ~DISP_CursorConfig_FORMAT_Msk) | f )

#define DISP_VIDEO_IS_UNDERFLOW()    ((DISP->FrameBufferConfig0 & DISP_FrameBufferConfig0_UNDERFLOW_Msk) ? 1 : 0 )
#define DISP_OVERLAY_IS_UNDERFLOW()  ((DISP->OverlayConfig0 & DISP_OverlayConfig0_UNDERFLOW_Msk) ? 1 : 0)

#define DISP_CURSOR_SET_POSITION(x,y) \
                    ( DISP->CursorLocation = \
                      ((x<<DISP_CursorLocation_X_Pos) & DISP_CursorLocation_X_Msk) | \
                      ((y<<DISP_CursorLocation_Y_Pos) & DISP_CursorLocation_Y_Msk) )

#define DISP_CURSOR_SET_BGCOLOR(r,g,b) \
                    ( DISP->CursorBackground = \
                      ((r<<DISP_CursorBackground_RED_Pos) & DISP_CursorBackground_RED_Msk) | \ ((g<<DISP_CursorBackground_GREEN_Pos) & DISP_CursorBackground_GREEN_Msk) | \ ((b<<DISP_CursorBackground_BLUE_Pos) & DISP_CursorBackground_BLUE_Msk) )

#define DISP_CURSOR_SET_FGCOLOR(r,g,b) \
                    ( DISP->CursorForeground = \
                      ((r<<DISP_CursorForeground_RED_Pos) & DISP_CursorForeground_RED_Msk) | \ ((g<<DISP_CursorForeground_GREEN_Pos) & DISP_CursorForeground_GREEN_Msk) | \ ((b<<DISP_CursorForeground_BLUE_Pos) & DISP_CursorForeground_BLUE_Msk) )

int32_t DISP_LCDInit(const DISP_LCD_INFO *psLCDInfo);
int32_t DISP_LCDDeinit(void);
int DISP_SetFBConfig(E_DISP_LAYER eLayer, E_FB_FMT eFbFmt, uint32_t u32ResWidth, uint32_t u32ResHeight, uint32_t u32DMAFBStartAddr);
void DISP_SetPanelConf(DISP_PANEL_CONF *psPanelConf);
void DISP_SetTiming(DISP_LCD_TIMING *psLCDTiming);
int DISP_Trigger(E_DISP_LAYER eLayer, uint32_t u32Action);
int DISP_SetTransparencyMode(E_DISP_LAYER eLayer, E_TRANSPARENCY_MODE eTM);
int DISP_SetBlendOpMode(E_DC_BLEND_MODE eDCBM, E_GLOBAL_ALPHA_MODE eGloAM_Src, E_GLOBAL_ALPHA_MODE eGloAM_Dst);
void DISP_SetBlendValue(uint32_t u32GloAV_Src, uint32_t u32GloAV_Dst);
void DISP_SetColorKeyValue(uint32_t u32ColorKeyLow, uint32_t u32ColorKeyHigh);
int DISP_SetFBAddr(E_DISP_LAYER eLayer, uint32_t u32DMAFBStartAddr);
int DISP_SetFBFmt(E_DISP_LAYER eLayer, E_FB_FMT eFbFmt, uint32_t u32Pitch);
uint32_t DISP_LCDTIMING_GetFPS(const DISP_LCD_TIMING *psDispLCDTiming);
uint32_t DISP_LCDTIMING_SetFPS(uint32_t u32FPS);
void DISP_SetCursorPosition(uint32_t u32X, uint32_t u32Y);
void DISP_InitCursor(DISP_CURSOR_CONF *psCursorConf);


/*@}*/ /* end of group DISP_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group DISP_Driver */

/*@}*/ /* end of group Standard_Driver */

#ifdef __cplusplus
}
#endif

#endif /* __NU_DISP_H__ */

