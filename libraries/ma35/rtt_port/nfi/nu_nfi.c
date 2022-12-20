/**************************************************************************//**
 * @file     nfi.c
 * @brief    NFI driver source file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/

#include "NuMicro.h"
#include "nand.h"
#include "drv_sys.h"

/** @addtogroup Standard_Driver Standard Driver
  @{
*/

/** @addtogroup NAND_Driver NAND Driver
  @{
*/

/** @addtogroup NAND_EXPORTED_CONSTANTS NAND Exported Constants
  @{
*/
/// @cond HIDDEN_SYMBOLS

#define READYBUSY   NFI_NANDINTSTS_RB0Status_Msk
#define ENDADDR     (0x80000000)

/*-----------------------------------------------------------------------------
 * Define some constants for BCH
 *---------------------------------------------------------------------------*/
// define the total padding bytes for 512/1024 data segment
#define BCH_PADDING_LEN_512     32
#define BCH_PADDING_LEN_1024    64

// define the BCH parity code lenght for 512 bytes data pattern
#define BCH_PARITY_LEN_T8  15
#define BCH_PARITY_LEN_T12 23
// define the BCH parity code lenght for 1024 bytes data pattern
#define BCH_PARITY_LEN_T24 45

#define NAND_BCH_T8     0x00100000
#define NAND_BCH_T12    0x00200000
#define NAND_BCH_T24    0x00040000

#define NAND_PAGE_2KB_Msk  0x10000
#define NAND_PAGE_4KB_Msk  0x20000
#define NAND_PAGE_8KB_Msk  0x30000

#define NAND_PAGE_2KB   2048
#define NAND_PAGE_4KB   4096
#define NAND_PAGE_8KB   8192

struct nfi_nand_info
{
    struct nand_hw_control  controller;
    struct mtd_info         mtd;
    struct nand_chip        chip;
    int                     i32BCHAlgo;
    int                     m_i32SMRASize;
};
struct nfi_nand_info g_nfi_nand;
struct nfi_nand_info *nfi_nand;

static struct nand_ecclayout nfi_nand_oob;
static const int g_i32BCHAlgoIdx[3] = {NAND_BCH_T8, NAND_BCH_T12, NAND_BCH_T24 };
static const int g_i32ParityNum[3][3] =
{
    /* T8,   T12,    T24 */
    { 60,     92,     90  },  // For 2K
    { 120,    184,    180 },  // For 4K
    { 240,    368,    360 }  // For 8K
};

static const char *s_szBCHAlgo[3] = { "T8", "T12", "T24" };

static void nfi_layout_oob_table(struct nand_ecclayout *pNandOOBTbl, int oobsize, int eccbytes)
{
    pNandOOBTbl->eccbytes = eccbytes;

    pNandOOBTbl->oobavail = oobsize - 4 - eccbytes ;

    pNandOOBTbl->oobfree[0].offset = 4;  // Bad block marker size

    pNandOOBTbl->oobfree[0].length = oobsize - eccbytes - pNandOOBTbl->oobfree[0].offset ;
}


static void nfi_hwcontrol(struct mtd_info *mtd, int cmd, unsigned int ctrl)
{
    struct nand_chip *chip = mtd->priv;

    if (ctrl & NAND_CTRL_CHANGE)
    {
        void __iomem *IO_ADDR_W = (void __iomem *)&NFI->NANDDATA;

        if ((ctrl & NAND_CLE))
            IO_ADDR_W = (void __iomem *)&NFI->NANDCMD;
        if ((ctrl & NAND_ALE))
            IO_ADDR_W = (void __iomem *)&NFI->NANDADDR;

        chip->IO_ADDR_W = IO_ADDR_W;
    }

    if (cmd != NAND_CMD_NONE)
        outpb(chip->IO_ADDR_W, cmd);
}


/* select chip */
static void nfi_nand_select_chip(struct mtd_info *mtd, int chip)
{
    NFI->NANDCTL |= (NFI_NANDCTL_CS0_Msk | NFI_NANDCTL_CS1_Msk);
    switch (chip)
    {
    case -1:
        NFI->NANDCTL |= (NFI_NANDCTL_CS0_Msk | NFI_NANDCTL_CS1_Msk);
        break;
    case 0:
        NFI->NANDCTL = (NFI->NANDCTL & ~NFI_NANDCTL_CS0_Msk) | NFI_NANDCTL_CS1_Msk;
        break;
    case 1:
        NFI->NANDCTL = (NFI->NANDCTL & ~NFI_NANDCTL_CS1_Msk) | NFI_NANDCTL_CS0_Msk;
        break;
    }
}


static int nfi_dev_ready(struct mtd_info *mtd)
{
    return (NFI->NANDINTSTS & READYBUSY) ? 1 : 0;
}

static int nfi_waitfunc(struct nand_chip *chip)
{
    volatile int i;

    if (chip->chip_delay)
        for (i = 0; i < chip->chip_delay; i++);

    /* check r/b# flag */
    while (!(NFI->NANDINTSTS & READYBUSY)) ;

    return 0;
}

void nfi_nand_set_page_addr(struct nand_chip *chip, int page_addr)
{
    if (chip->chipsize > (128 << 20))
    {
        //if ( chip->options & NAND_ROW_ADDR_3) {
        NFI->NANDADDR = (page_addr >> 8) & 0xff;
        NFI->NANDADDR = ((page_addr >> 16) & 0xff) | ENDADDR;
    }
    else
    {
        NFI->NANDADDR = ((page_addr >> 8) & 0xff) | ENDADDR;
    }
}

static void nfi_nand_command(struct mtd_info *mtd, unsigned int command, int column, int page_addr)
{
    struct nand_chip *chip = mtd->priv;

    if (command == NAND_CMD_READOOB)
    {
        column += mtd->writesize;
        command = NAND_CMD_READ0;
    }

    NFI->NANDCMD = command & 0xff;

    if (command == NAND_CMD_READID)
    {
        NFI->NANDADDR = column | ENDADDR;
    }
    else if (column != -1 || page_addr != -1)
    {
        if (column != -1)
        {
            NFI->NANDADDR = column & 0xff;
            if (page_addr != -1)
                NFI->NANDADDR = column >> 8;
            else
                NFI->NANDADDR = (column >> 8) | ENDADDR;
        }

        if (page_addr != -1)
        {
            NFI->NANDADDR = page_addr & 0xFF;

            if (chip->chipsize > (128 << 20))
            {
                NFI->NANDADDR = (page_addr >> 8) & 0xFF;
                NFI->NANDADDR = ((page_addr >> 16) & 0xFF) | ENDADDR;
            }
            else
            {
                NFI->NANDADDR = ((page_addr >> 8) & 0xFF) | ENDADDR;
            }
        }
    }

    switch (command)
    {
    case NAND_CMD_CACHEDPROG:
    case NAND_CMD_PAGEPROG:
    case NAND_CMD_ERASE1:
    case NAND_CMD_ERASE2:
    case NAND_CMD_SEQIN:
    case NAND_CMD_RNDIN:
    case NAND_CMD_STATUS:
        return;

    case NAND_CMD_RESET:
        if (chip->dev_ready)
            break;

        nfi_waitfunc(chip);

        NFI->NANDCMD = NAND_CMD_STATUS;
        NFI->NANDCMD = command;

        break;

    case NAND_CMD_RNDOUT:
        NFI->NANDCMD = NAND_CMD_RNDOUTSTART;
        nfi_waitfunc(chip);
        return;

    case NAND_CMD_READ0:
        NFI->NANDCMD = NAND_CMD_READSTART;
        break;

    default:
        break;
    }

    nfi_waitfunc(chip);
}

/*
 * nfi_nand_read_byte - read a byte from NAND controller into buffer
 * @mtd: MTD device structure
 */
static uint8_t nfi_nand_read_byte(struct mtd_info *mtd)
{
    return ((uint8_t)NFI->NANDDATA);
}

/*
 * nfi_nand_write_buf - write data from buffer into NAND controller
 * @mtd: MTD device structure
 * @buf: virtual address in RAM of source
 * @len: number of data bytes to be transferred
 */

static void nfi_nand_write_buf(struct mtd_info *mtd, const uint8_t *buf, int len)
{
    int i;

    for (i = 0; i < len; i++)
        NFI->NANDDATA = buf[i];
}

/*
 * nfi_nand_read_buf - read data from NAND controller into buffer
 * @mtd: MTD device structure
 * @buf: virtual address in RAM of source
 * @len: number of data bytes to be transferred
 */
static void nfi_nand_read_buf(struct mtd_info *mtd, unsigned char *buf, int len)
{
    int i;

    for (i = 0; i < len; i++)
        buf[i] = NFI->NANDDATA;
}


/*
 * Enable HW ECC : unused on most chips
 */
void nfi_nand_enable_hwecc(struct mtd_info *mtd, int mode)
{
}

/*
 * Calculate HW ECC
 * function called after a write
 * mtd:        MTD block structure
 * dat:        raw data (unused)
 * ecc_code:   buffer for ECC
 */
static int nfi_nand_calculate_ecc(struct mtd_info *mtd, const u_char *dat, u_char *ecc_code)
{
    return 0;
}

/*
 * HW ECC Correction
 * function called after a read
 * mtd:        MTD block structure
 * dat:        raw data read from the chip
 * read_ecc:   ECC from the chip (unused)
 * isnull:     unused
 */
static int nfi_nand_correct_data(struct mtd_info *mtd, u_char *dat,
                                 u_char *read_ecc, u_char *calc_ecc)
{
    return 0;
}


/*-----------------------------------------------------------------------------
 * Correct data by BCH alrogithm.
 *      Support 8K page size NAND and BCH T4/8/12/15/24.
 *---------------------------------------------------------------------------*/
void fmiSM_CorrectData_BCH(uint8_t ucFieidIndex, uint8_t ucErrorCnt, uint8_t *pDAddr)
{
    unsigned int uaData[24], uaAddr[24];
    unsigned int uaErrorData[6];
    uint8_t  ii, jj;
    unsigned int uPageSize;
    unsigned int field_len, padding_len, parity_len;
    unsigned int total_field_num;
    uint8_t  *smra_index;
    volatile uint8_t *vpu8RA = (volatile uint8_t *)&NFI->NANDRA[0];

    //--- assign some parameters for different BCH and page size
    switch (NFI->NANDCTL & NFI_NANDCTL_BCHTSEL_Msk)
    {
    case NAND_BCH_T24:
        field_len   = 1024;
        padding_len = BCH_PADDING_LEN_1024;
        parity_len  = BCH_PARITY_LEN_T24;
        break;
    case NAND_BCH_T12:
        field_len   = 512;
        padding_len = BCH_PADDING_LEN_512;
        parity_len  = BCH_PARITY_LEN_T12;
        break;
    case NAND_BCH_T8:
        field_len   = 512;
        padding_len = BCH_PADDING_LEN_512;
        parity_len  = BCH_PARITY_LEN_T8;
        break;
    default:
        return;
    }

    uPageSize = NFI->NANDCTL & NFI_NANDCTL_PSIZE_Msk;
    switch (uPageSize)
    {
    case NAND_PAGE_8KB_Msk:
        total_field_num = 8192 / field_len;
        break;
    case NAND_PAGE_4KB_Msk:
        total_field_num = 4096 / field_len;
        break;
    case NAND_PAGE_2KB_Msk:
        total_field_num = 2048 / field_len;
        break;
    default:
        return;
    }

    //--- got valid BCH_ECC_DATAx and parse them to uaData[]
    // got the valid register number of BCH_ECC_DATAx since one register include 4 error bytes
    jj = ucErrorCnt / 4;
    jj ++;
    if (jj > 6)
        jj = 6;     // there are 6 BCH_ECC_DATAx registers to support BCH T24

    for (ii = 0; ii < jj; ii++)
    {
        uaErrorData[ii] = inpw(((unsigned int)&NFI->NANDECCED[0]) + ii * 4);
    }

    for (ii = 0; ii < jj; ii++)
    {
        uaData[ii * 4 + 0] = uaErrorData[ii] & 0xff;
        uaData[ii * 4 + 1] = (uaErrorData[ii] >> 8) & 0xff;
        uaData[ii * 4 + 2] = (uaErrorData[ii] >> 16) & 0xff;
        uaData[ii * 4 + 3] = (uaErrorData[ii] >> 24) & 0xff;
    }

    //--- got valid REG_BCH_ECC_ADDRx and parse them to uaAddr[]
    // got the valid register number of REG_BCH_ECC_ADDRx since one register include 2 error addresses
    jj = ucErrorCnt / 2;
    jj ++;
    if (jj > 12)
        jj = 12;    // there are 12 REG_BCH_ECC_ADDRx registers to support BCH T24

    for (ii = 0; ii < jj; ii++)
    {
        uaAddr[ii * 2 + 0] = inpw((unsigned int)&NFI->NANDECCEA[0] + ii * 4) & 0x07ff;  // 11 bits for error address
        uaAddr[ii * 2 + 1] = (inpw((unsigned int)&NFI->NANDECCEA[0] + ii * 4) >> 16) & 0x07ff;
    }

    //--- pointer to begin address of field that with data error
    pDAddr += (ucFieidIndex - 1) * field_len;

    //--- correct each error bytes
    for (ii = 0; ii < ucErrorCnt; ii++)
    {
        // for wrong data in field
        if (uaAddr[ii] < field_len)
        {
            *(pDAddr + uaAddr[ii]) ^= uaData[ii];
        }
        // for wrong first-3-bytes in redundancy area
        else if (uaAddr[ii] < (field_len + 3))
        {
            uaAddr[ii] -= field_len;
            uaAddr[ii] += (parity_len * (ucFieidIndex - 1)); // field offset
            vpu8RA[uaAddr[ii]] ^= uaData[ii];
        }
        // for wrong parity code in redundancy area
        else
        {
            // BCH_ERR_ADDRx = [data in field] + [3 bytes] + [xx] + [parity code]
            //                                   |<--     padding bytes      -->|
            // The BCH_ERR_ADDRx for last parity code always = field size + padding size.
            // So, the first parity code = field size + padding size - parity code length.
            // For example, for BCH T12, the first parity code = 512 + 32 - 23 = 521.
            // That is, error byte address offset within field is
            uaAddr[ii] = uaAddr[ii] - (field_len + padding_len - parity_len);

            // smra_index point to the first parity code of first field in register SMRA0~n
            smra_index = (uint8_t *)
                         ((vpu8RA[NFI->NANDRACTL & 0x1ff]) - // bottom of all parity code -
                          (parity_len * total_field_num)    // byte count of all parity code
                         );

            // final address = first parity code of first field +
            //                 offset of fields +
            //                 offset within field
            *((uint8_t *)smra_index + (parity_len * (ucFieidIndex - 1)) + uaAddr[ii]) ^= uaData[ii];
        }
    }   // end of for (ii<ucErrorCnt)
}

int fmiSMCorrectData(struct mtd_info *mtd, unsigned long uDAddr)
{
    int uStatus, ii, jj, i32FieldNum = 0;
    volatile int uErrorCnt = 0;

    if (NFI->NANDINTSTS & NFI_NANDINTSTS_ECCFLDIF_Msk)
    {
        if ((NFI->NANDCTL & NFI_NANDCTL_BCHTSEL_Msk) == NAND_BCH_T24)
            i32FieldNum = mtd->writesize / 1024;    // Block=1024 for BCH
        else
            i32FieldNum = mtd->writesize / 512;

        if (i32FieldNum < 4)
            i32FieldNum  = 1;
        else
            i32FieldNum /= 4;

        for (jj = 0; jj < i32FieldNum; jj++)
        {
            uStatus = inpw((uint32_t)&NFI->NANDECCES[0] + jj * 4);
            if (!uStatus)
                continue;

            for (ii = 1; ii < 5; ii++)
            {
                if (!(uStatus & 0x03))     // No error
                {

                    uStatus >>= 8;
                    continue;

                }
                else if ((uStatus & 0x03) == 0x01)     // Correctable error
                {

                    uErrorCnt = (uStatus >> 2) & 0x1F;
                    fmiSM_CorrectData_BCH(jj * 4 + ii, uErrorCnt, (uint8_t *)uDAddr);

                    uStatus >>= 8;
                    continue;
                }
                else   // uncorrectable error or ECC error
                {
                    return -1;
                }
            }
        } //jj
    }
    return uErrorCnt;
}


static __inline int _nfi_nand_dma_transfer(struct mtd_info *mtd, const u_char *addr, unsigned int len, int is_write)
{
    struct nfi_nand_info *nand = nfi_nand;

    // For save, wait DMAC to ready
    while (NFI->DMACTL & NFI_DMACTL_DMABUSY_Msk);

    // Reinitial dmac
    // DMAC enable
    NFI->DMACTL |= (NFI_DMACTL_DMACEN_Msk | NFI_DMACTL_DMARST_Msk);
    while (NFI->DMACTL & NFI_DMACTL_DMARST_Msk);

    // Clear DMA finished flag
    NFI->NANDINTSTS |= NFI_NANDINTSTS_DMAIF_Msk;

    // Disable Interrupt
    NFI->NANDINTEN &= ~NFI_NANDINTEN_DMAIE_Msk;

    // Flush to memory
    rt_hw_cpu_dcache_clean_inv((void *)addr, len);

    // Fill dma_addr
    NFI->DMASA = (uint32_t)addr;

    // Enable target abort interrupt generation during DMA transfer.
    NFI->DMAINTEN = NFI_NANDINTEN_DMAIE_Msk;

    // Clear Ready/Busy 0 Rising edge detect flag
    NFI->NANDINTSTS = NFI_NANDINTSTS_RB0IF_Msk;

    // Set which BCH algorithm
    if (nand->i32BCHAlgo >= 0)
    {
        // Protect redundant 3 bytes
        // because we need to implement write_oob function to partial data to oob available area.
        // Please note we skip 4 bytes
        NFI->NANDCTL |= NFI_NANDCTL_PROT3BEN_Msk;

        // To read/write the ECC parity codes automatically from/to NAND Flash after data area field written.
        NFI->NANDCTL |= NFI_NANDCTL_REDUNAUTOWEN_Msk;

        // Set BCH algorithm
        NFI->NANDCTL = (NFI->NANDCTL & ~NFI_NANDCTL_BCHTSEL_Msk) | g_i32BCHAlgoIdx[nand->i32BCHAlgo];

        // Enable H/W ECC, ECC parity check enable bit during read page
        NFI->NANDCTL |= (NFI_NANDCTL_ECCEN_Msk | NFI_NANDCTL_ECCCHK_Msk);
    }
    else
    {
        // Disable H/W ECC / ECC parity check enable bit during read page
        // Disable Protect redundant 3 bytes
        // To read/write the ECC parity codes automatically
        NFI->NANDCTL &= ~(NFI_NANDCTL_ECCEN_Msk | NFI_NANDCTL_ECCCHK_Msk | NFI_NANDCTL_REDUNAUTOWEN_Msk | NFI_NANDCTL_PROT3BEN_Msk);
    }

    NFI->NANDRACTL = nand->m_i32SMRASize;

    NFI->NANDINTEN &= ~NFI_NANDINTEN_ECCFLDIE_Msk;

    NFI->NANDINTSTS = NFI_NANDINTSTS_ECCFLDIF_Msk;

    /* setup and start DMA using dma_addr */
    if (is_write)
    {
        volatile uint8_t *ptr = (volatile uint8_t *)&NFI->NANDRA[0];

        // To mark this page as dirty.
        if (ptr[3] == 0xFF)
            ptr[3] = 0;
        if (ptr[2] == 0xFF)
            ptr[2] = 0;

        NFI->NANDCTL |= NFI_NANDCTL_DWREN_Msk;
        while (!(NFI->NANDINTSTS & NFI_NANDINTSTS_DMAIF_Msk));
    }
    else
    {
        // Blocking for reading
        // Enable DMA Read

        NFI->NANDCTL |= NFI_NANDCTL_DRDEN_Msk;

        if (NFI->NANDCTL & NFI_NANDCTL_ECCCHK_Msk)
        {
            do
            {
                int stat = 0;
                if ((stat = fmiSMCorrectData(mtd, (unsigned int)addr)) < 0)
                {
                    mtd->ecc_stats.failed++;
                    NFI->NANDINTSTS = NFI_NANDINTSTS_ECCFLDIF_Msk;
                    NFI->DMACTL = (NFI_DMACTL_DMACEN_Msk | NFI_DMACTL_DMARST_Msk);        // Reset DMAC
                    NFI->NANDCTL |= NFI_NANDCTL_SWRST_Msk;
                    break;
                }
                else if (stat > 0)
                {
                    //mtd->ecc_stats.corrected += stat; //Occure: MLC UBIFS mount error
                    NFI->NANDINTSTS = NFI_NANDINTSTS_ECCFLDIF_Msk;
                }

            }
            while (!(NFI->NANDINTSTS & NFI_NANDINTSTS_DMAIF_Msk) || (NFI->NANDINTSTS & NFI_NANDINTSTS_ECCFLDIF_Msk));
        }
        else
            while (!(NFI->NANDINTSTS & NFI_NANDINTSTS_DMAIF_Msk));
    }

    // Clear DMA finished flag
    NFI->NANDINTSTS |= NFI_NANDINTSTS_DMAIF_Msk;

    return 0;
}


/**
 * nand_write_page_hwecc - [REPLACABLE] hardware ecc based page write function
 * @mtd:        mtd info structure
 * @chip:       nand chip info structure
 * @buf:        data buffer
 */
static int nfi_nand_write_page_hwecc(struct mtd_info *mtd, struct nand_chip *chip, const uint8_t *buf, int oob_required, int page)
{
    uint8_t *ecc_calc = chip->buffers->ecccalc;
    unsigned int hweccbytes = chip->ecc.layout->eccbytes;
    volatile uint8_t *ptr = (volatile uint8_t *)&NFI->NANDRA[0];

    //debug("nfi_nand_write_page_hwecc\n");
    memset((void *)ptr, 0xFF, mtd->oobsize);
    memcpy((void *)ptr, (void *)chip->oob_poi,  mtd->oobsize - chip->ecc.total);

    _nfi_nand_dma_transfer(mtd, buf, mtd->writesize, 0x1);

    // Copy parity code in SMRA to calc
    memcpy((void *)ecc_calc, (void *)(ptr + (mtd->oobsize - chip->ecc.total)), chip->ecc.total);

    // Copy parity code in calc to oob_poi
    memcpy((void *)(chip->oob_poi + hweccbytes), (void *)ecc_calc, chip->ecc.total);

    return 0;
}

/**
 * nfi_nand_read_page_hwecc_oob_first - hardware ecc based page write function
 * @mtd:        mtd info structure
 * @chip:       nand chip info structure
 * @buf:        buffer to store read data
 * @page:       page number to read
 */
static int nfi_nand_read_page_hwecc_oob_first(struct mtd_info *mtd, struct nand_chip *chip, uint8_t *buf, int oob_required, int page)
{
    int eccsize = chip->ecc.size;
    uint8_t *p = buf;
    volatile uint8_t *ptr = (volatile uint8_t *)&NFI->NANDRA[0];

    //rt_kprintf("%s\n", __func__);
    /* At first, read the OOB area  */
    nfi_nand_command(mtd, NAND_CMD_READOOB, 0, page);
    nfi_nand_read_buf(mtd, chip->oob_poi, mtd->oobsize);

    // Second, copy OOB data to SMRA for page read
    memcpy((void *)ptr, (void *)chip->oob_poi, mtd->oobsize);

    // Third, read data from nand
    nfi_nand_command(mtd, NAND_CMD_READ0, 0, page);
    _nfi_nand_dma_transfer(mtd, p, eccsize, 0x0);

    // Fouth, restore OOB data from SMRA
    memcpy((void *)chip->oob_poi, (void *)ptr, mtd->oobsize);

    return 0;
}

/**
 * nfi_nand_read_oob_hwecc - [REPLACABLE] the most common OOB data read function
 * @mtd:        mtd info structure
 * @chip:       nand chip info structure
 * @page:       page number to read
 * @sndcmd:     flag whether to issue read command or not
 */
static int nfi_nand_read_oob_hwecc(struct mtd_info *mtd, struct nand_chip *chip, int page)
{
    /* At first, read the OOB area  */
    nfi_nand_command(mtd, NAND_CMD_READOOB, 0, page);

    nfi_nand_read_buf(mtd, chip->oob_poi, mtd->oobsize);

    /* To check 2nd and 3rd byte is dirty or not. If not dirty, report all 0xff to caller. */
    if ((chip->oob_poi[2] != 0) && (chip->oob_poi[3] != 0))
    {
        memset((void *)chip->oob_poi, 0xff, mtd->oobsize);
    }

    return 0;
}

int board_nand_init(struct nand_chip *nand)
{
    struct mtd_info *mtd;
    uint32_t u32ParityNum;

    nfi_nand = &g_nfi_nand;
    memset((void *)nfi_nand, 0, sizeof(struct nfi_nand_info));

    mtd = &nfi_nand->mtd;
    nfi_nand->chip.controller = &nfi_nand->controller;

    /* initialize nand_chip data structure */
    nand->IO_ADDR_R = (void __iomem *)&NFI->NANDDATA;
    nand->IO_ADDR_W = (void __iomem *)&NFI->NANDDATA;

    /* read_buf and write_buf are default */
    /* read_byte and write_byte are default */
    /* hwcontrol always must be implemented */
    nand->cmd_ctrl = nfi_hwcontrol;
    nand->cmdfunc = nfi_nand_command;
    nand->dev_ready = nfi_dev_ready;
    nand->select_chip = nfi_nand_select_chip;

    nand->read_byte = nfi_nand_read_byte;
    nand->write_buf = nfi_nand_write_buf;
    nand->read_buf = nfi_nand_read_buf;
    nand->chip_delay = 200;

    nand->controller = &nfi_nand->controller;

    nand->ecc.mode      = NAND_ECC_HW_OOB_FIRST;
    nand->ecc.hwctl     = nfi_nand_enable_hwecc;
    nand->ecc.calculate = nfi_nand_calculate_ecc;
    nand->ecc.correct   = nfi_nand_correct_data;
    nand->ecc.write_page = nfi_nand_write_page_hwecc;
    nand->ecc.read_page = nfi_nand_read_page_hwecc_oob_first;
    nand->ecc.read_oob  = nfi_nand_read_oob_hwecc;

    nand->ecc.layout    = &nfi_nand_oob;
    nand->ecc.strength  = 8;
    mtd = nand_to_mtd(nand);

    mtd->priv = nand;

    /* initial NAND controller */
    CLK_EnableModuleClock(NAND_MODULE);
    SYS_ResetModule(NAND_RST);

    // Enable SM_EN
    NFI->GCTL = NFI_GCTL_NANDEN_Msk;
    //NFI->NANDTMCTL |= 0x0305;

    // Un-lock write protect
    NFI->NANDECTL = NFI_NANDECTL_WP_Msk;

    // NAND Reset
    NFI->NANDCTL |= NFI_NANDCTL_SWRST_Pos;    // software reset
    while (NFI->NANDCTL & NFI_NANDCTL_SWRST_Pos);

    /* Detect NAND chips */
    /* first scan to find the device and get the page size */
    if (nand_scan_ident(mtd, 1, NULL) != 0)
    {
        sysprintf("NAND Flash not found !\n");
        return -1;
    }

    //Set PSize bits of SMCSR register to select NAND card page size
    switch (mtd->writesize)
    {
    case NAND_PAGE_2KB:
        NFI->NANDCTL = (NFI->NANDCTL & ~NFI_NANDCTL_PSIZE_Msk) | NAND_PAGE_2KB_Msk;
        nfi_nand->i32BCHAlgo = 0; /* T8 */
        break;

    case NAND_PAGE_4KB:
        NFI->NANDCTL = (NFI->NANDCTL & ~NFI_NANDCTL_PSIZE_Msk) | NAND_PAGE_4KB_Msk;
        nfi_nand->i32BCHAlgo = 1; /* T12 */
        break;

    case NAND_PAGE_8KB:
        NFI->NANDCTL = (NFI->NANDCTL & ~NFI_NANDCTL_PSIZE_Msk) | NAND_PAGE_8KB_Msk;
        nfi_nand->i32BCHAlgo = 2; /* T24 */
        break;

    default:
        sysprintf("NOT SUPPORT THE PAGE SIZE. (%d, %d)\n", mtd->writesize, mtd->oobsize);
        return -1;
    }

    if (0)
    {
        uint32_t volatile uPowerOn, u32PageSize;

        /* check power-on-setting */
        uPowerOn = SYS->PWRONOTP;
        if ((uPowerOn & 0x1) == 0)
            uPowerOn = (uPowerOn & ~0xfd00) | (SYS->PWRONPIN << 8);

        if ((uPowerOn & 0x00003000) != 0)    /* page: 2K, 4K and 8K cases */
        {
            uint32_t u32PredefinedPPB = 64;
            u32PageSize = 1024 << ((uPowerOn >> 12) & 0x3);

            switch (u32PageSize)
            {
            case NAND_PAGE_2KB:
                NFI->NANDCTL = (NFI->NANDCTL & ~NFI_NANDCTL_PSIZE_Msk) | NAND_PAGE_2KB_Msk;
                u32PredefinedPPB = 64;
                nfi_nand->i32BCHAlgo = 0; /* T8 */
                break;

            case NAND_PAGE_4KB:
                NFI->NANDCTL = (NFI->NANDCTL & ~NFI_NANDCTL_PSIZE_Msk) | NAND_PAGE_4KB_Msk;
                u32PredefinedPPB = 128;
                nfi_nand->i32BCHAlgo = 0; /* T8 */
                break;

            case NAND_PAGE_8KB:
                NFI->NANDCTL = (NFI->NANDCTL & ~NFI_NANDCTL_PSIZE_Msk) | NAND_PAGE_8KB_Msk;
                u32PredefinedPPB = 128;
                nfi_nand->i32BCHAlgo = 1; /* T12 */
                break;

            default:
                break;
            }

            mtd->writesize = u32PageSize;
            mtd->erasesize = mtd->writesize * u32PredefinedPPB;
        }

        if ((uPowerOn & 0x0000C000) != 0)  /* BCH: NOECC, T12 and T24 cases */
        {
            uint32_t u32OOBSize = 0;

            switch ((uPowerOn & 0x0000C000))
            {
            case 0xc000:
                sysprintf("NoECC\n");
                u32OOBSize = 8;
                nfi_nand->i32BCHAlgo = -1; /* NoECC */
                break;
            case 0x4000:
                sysprintf("T12\n");
                nfi_nand->i32BCHAlgo = 1;  //T12
                u32OOBSize = 8 + g_i32ParityNum[mtd->writesize >> 12][nfi_nand->i32BCHAlgo];
                break;
            case 0x8000:
                sysprintf("T24\n");
                nfi_nand->i32BCHAlgo = 2;  //T24
                u32OOBSize = 8 + g_i32ParityNum[mtd->writesize >> 12][nfi_nand->i32BCHAlgo];
                break;
            default:
                break;
            }

            mtd->oobsize = u32OOBSize;
        }
    }

    nand->options = NAND_NO_SUBPAGE_WRITE;
    //nand->bbt_options = (NAND_BBT_USE_FLASH | NAND_BBT_NO_OOB);

    if (nfi_nand->i32BCHAlgo >= 0)
    {
        u32ParityNum = g_i32ParityNum[mtd->writesize >> 12][nfi_nand->i32BCHAlgo];
    }
    else
    {
        u32ParityNum = 0;
    }

    nfi_layout_oob_table(&nfi_nand_oob, mtd->oobsize, u32ParityNum);

    nfi_nand->m_i32SMRASize  = mtd->oobsize;
    nand->ecc.bytes = nfi_nand_oob.eccbytes;
    nand->ecc.size  = mtd->writesize;

    sysprintf("writesize: %d\n", mtd->writesize);
    sysprintf("oobsize: %d\n", mtd->oobsize);
    sysprintf("BCHAlgo: %s\n", (nfi_nand->i32BCHAlgo >= 0) ? s_szBCHAlgo[nfi_nand->i32BCHAlgo] : "NOECC");
    sysprintf("ParityNum: %d\n", g_i32ParityNum[mtd->writesize >> 12][nfi_nand->i32BCHAlgo]);
    sysprintf("SMRA Size: %d\n", nfi_nand->m_i32SMRASize);
    sysprintf("ecc size: %d\n", nand->ecc.size);
    sysprintf("ecc bytes: %d\n", nand->ecc.bytes);

    return 0;
}

/// @endcond HIDDEN_SYMBOLS


/*@}*/ /* end of group NAND_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group NAND_Driver */

/*@}*/ /* end of group Standard_Driver */

/*** (C) COPYRIGHT 2018 Nuvoton Technology Corp. ***/
