/*******************************************************************************
  SDHC1 PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_sdhc1.c

  Summary:
    SDHC1 PLIB Implementation File

  Description:
    None

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

#include "device.h"
#include "plib_sdhc1.h"
#include "interrupts.h"

// *****************************************************************************
// *****************************************************************************
// Section: Include Files
// *****************************************************************************
// *****************************************************************************

#include "plib_sdhc_common.h"

#define SDHC1_DMA_NUM_DESCR_LINES        (1U)
#define SDHC1_BASE_CLOCK_FREQUENCY       (120000000U)
#define SDHC1_MAX_BLOCK_SIZE             (0x200U)
#define SDHC1_DMA_DESC_TABLE_SIZE	     (8U * 1)
#define SDHC1_DMA_DESC_TABLE_SIZE_CACHE_ALIGN	 (SDHC1_DMA_DESC_TABLE_SIZE + ((SDHC1_DMA_DESC_TABLE_SIZE % CACHE_LINE_SIZE)? (CACHE_LINE_SIZE - (SDHC1_DMA_DESC_TABLE_SIZE % CACHE_LINE_SIZE)) : 0U))

static CACHE_ALIGN SDHC_ADMA_DESCR sdhc1DmaDescrTable[(SDHC1_DMA_DESC_TABLE_SIZE_CACHE_ALIGN/8U)];

volatile static SDHC_OBJECT sdhc1Obj;

static void SDHC1_VariablesInit ( void )
{
    sdhc1Obj.errorStatus = 0U;
    sdhc1Obj.isCmdInProgress = false;
    sdhc1Obj.isDataInProgress = false;
    sdhc1Obj.callback = NULL;
}

static void SDHC1_TransferModeSet ( uint32_t opcode )
{
    uint16_t transferMode = 0U;

    switch(opcode)
    {
        case SDHC_CMD_READ_SCR:
        case SDHC_CMD_SET_BUS_WIDTH:
        case SDHC_CMD_READ_SINGLE_BLOCK:
            /* Read single block of data from the device. */
            transferMode = (SDHC_TMR_DMAEN_ENABLE | SDHC_TMR_DTDSEL_Msk);
            break;

        case SDHC_CMD_READ_MULTI_BLOCK:
            /* Read multiple blocks of data from the device. */
            transferMode = (SDHC_TMR_DMAEN_ENABLE | SDHC_TMR_DTDSEL_Msk | SDHC_TMR_MSBSEL_Msk | SDHC_TMR_BCEN_Msk);
            break;

        case SDHC_CMD_WRITE_SINGLE_BLOCK:
            /* Write single block of data to the device. */
            transferMode = SDHC_TMR_DMAEN_ENABLE;
            break;

        case SDHC_CMD_WRITE_MULTI_BLOCK:
            /* Write multiple blocks of data to the device. */
            transferMode = (SDHC_TMR_DMAEN_ENABLE | SDHC_TMR_MSBSEL_Msk | SDHC_TMR_BCEN_Msk);
            break;

        default:
		   /* Do Nothing here */
            break;
    }

    SDHC1_REGS->SDHC_TMR = transferMode;
}

void __attribute__((used)) SDHC1_InterruptHandler(void)
{
    uint16_t nistr = 0U;
    uint16_t eistr = 0U;
    SDHC_XFER_STATUS xferStatus = (SDHC_XFER_STATUS) 0;

    nistr = SDHC1_REGS->SDHC_NISTR;
    eistr = SDHC1_REGS->SDHC_EISTR;
    /* Save the error in a global variable for later use */
    sdhc1Obj.errorStatus |= eistr;

    if ((nistr & SDHC_NISTR_CINS_Msk) != 0U)
    {
        xferStatus |= SDHC_XFER_STATUS_CARD_INSERTED;
    }
    if ((nistr & SDHC_NISTR_CREM_Msk) != 0U)
    {
        xferStatus |= SDHC_XFER_STATUS_CARD_REMOVED;
    }

    if (sdhc1Obj.isCmdInProgress == true)
    {
        if ((nistr & (SDHC_NISTR_CMDC_Msk | SDHC_NISTR_TRFC_Msk | SDHC_NISTR_ERRINT_Msk)) != 0U)
        {
            if ((nistr & SDHC_NISTR_ERRINT_Msk) != 0U)
            {
                if (((eistr & (SDHC_EISTR_CMDTEO_Msk | \
                                      SDHC_EISTR_CMDCRC_Msk | \
                                      SDHC_EISTR_CMDEND_Msk | \
                                      SDHC_EISTR_CMDIDX_Msk))) != 0U)
                {
                    SDHC1_ErrorReset (SDHC_RESET_CMD);
                }
            }
            sdhc1Obj.isCmdInProgress = false;
            xferStatus |= SDHC_XFER_STATUS_CMD_COMPLETED;
        }
    }

    if (sdhc1Obj.isDataInProgress == true)
    {
        if ((nistr & (SDHC_NISTR_TRFC_Msk | SDHC_NISTR_DMAINT_Msk | SDHC_NISTR_ERRINT_Msk)) != 0U)
        {
            if ((nistr & SDHC_NISTR_ERRINT_Msk) != 0U)
            {
                if ((eistr & (SDHC_EISTR_DATTEO_Msk | \
                            SDHC_EISTR_DATCRC_Msk | \
                            SDHC_EISTR_DATEND_Msk)) != 0U)
                {
                    SDHC1_ErrorReset (SDHC_RESET_DAT);
                }
            }
            if ((nistr & SDHC_NISTR_TRFC_Msk) != 0U)
            {
                /* Clear the data timeout error as transfer complete has higher priority */
                sdhc1Obj.errorStatus &= (uint16_t)(~SDHC_EISTR_DATTEO_Msk);
            }
            sdhc1Obj.isDataInProgress = false;
            xferStatus |= SDHC_XFER_STATUS_DATA_COMPLETED;
        }
    }

    /* Clear normal interrupt and error status bits that have been processed */
    SDHC1_REGS->SDHC_NISTR = nistr;
    SDHC1_REGS->SDHC_EISTR = eistr;

    if ((sdhc1Obj.callback != NULL) && ((uint32_t)xferStatus > 0U))
    {
        uintptr_t context = sdhc1Obj.context;
        sdhc1Obj.callback(xferStatus, context);
    }
}

void SDHC1_ErrorReset ( SDHC_RESET_TYPE resetType )
{
    SDHC1_REGS->SDHC_SRR = (uint8_t)resetType;

    /* Wait until host resets the error status */
    while ((SDHC1_REGS->SDHC_SRR & (uint8_t)resetType) != 0U)
	{

	}
}

uint16_t SDHC1_GetError(void)
{
    return sdhc1Obj.errorStatus;
}

uint16_t SDHC1_CommandErrorGet(void)
{
    return (sdhc1Obj.errorStatus & (SDHC_EISTR_CMDTEO_Msk | SDHC_EISTR_CMDCRC_Msk | \
                SDHC_EISTR_CMDEND_Msk | SDHC_EISTR_CMDIDX_Msk));
}

uint16_t SDHC1_DataErrorGet(void)
{
    return (sdhc1Obj.errorStatus & (SDHC_EISTR_ADMA_Msk | SDHC_EISTR_DATTEO_Msk | \
            SDHC_EISTR_DATCRC_Msk | SDHC_EISTR_DATEND_Msk));
}

void SDHC1_BusWidthSet ( SDHC_BUS_WIDTH busWidth )
{
    if (busWidth == SDHC_BUS_WIDTH_4_BIT)
    {
       SDHC1_REGS->SDHC_HC1R |= SDHC_HC1R_DW_4BIT;
    }
    else
    {
        SDHC1_REGS->SDHC_HC1R &= (uint8_t)(~SDHC_HC1R_DW_4BIT);
    }
}

void SDHC1_SpeedModeSet ( SDHC_SPEED_MODE speedMode )
{
    if (speedMode == SDHC_SPEED_MODE_HIGH)
    {
       SDHC1_REGS->SDHC_HC1R |= SDHC_HC1R_HSEN_Msk;
    }
    else
    {
       SDHC1_REGS->SDHC_HC1R &= (uint8_t)(~SDHC_HC1R_HSEN_Msk);
    }
}

bool SDHC1_IsCmdLineBusy ( void )
{
    return(((SDHC1_REGS->SDHC_PSR & SDHC_PSR_CMDINHC_Msk) == SDHC_PSR_CMDINHC_Msk)? true : false);
}

bool SDHC1_IsDatLineBusy ( void )
{
    return (((SDHC1_REGS->SDHC_PSR & SDHC_PSR_CMDINHD_Msk) == SDHC_PSR_CMDINHD_Msk)? true : false);
}

bool SDHC1_IsCardAttached ( void )
{
    return ((SDHC1_REGS->SDHC_PSR & SDHC_PSR_CARDINS_Msk) == SDHC_PSR_CARDINS_Msk)? true : false;
}

void SDHC1_BlockSizeSet ( uint16_t blockSize )
{
    if(blockSize == 0U)
    {
        blockSize = 1U;
    }
    else if(blockSize > SDHC1_MAX_BLOCK_SIZE)
    {
        blockSize = SDHC1_MAX_BLOCK_SIZE;
    }
    else
    {
      /* Do not modify the block size */
    }
    SDHC1_REGS->SDHC_BSR = (SDHC_BSR_BOUNDARY_4K | SDHC_BSR_BLOCKSIZE(blockSize));
}

void SDHC1_BlockCountSet ( uint16_t numBlocks )
{
    SDHC1_REGS->SDHC_BCR = numBlocks;
}

void SDHC1_ClockEnable ( void )
{
    /* Start the internal clock  */
    SDHC1_REGS->SDHC_CCR |= SDHC_CCR_INTCLKEN_Msk;

    while ((SDHC1_REGS->SDHC_CCR & SDHC_CCR_INTCLKS_Msk) == 0U)
	{
        /* Wait for the internal clock to stabilize */
	}

    /* Enable the SD Clock */
    SDHC1_REGS->SDHC_CCR |= SDHC_CCR_SDCLKEN_Msk;
}

void SDHC1_ClockDisable ( void )
{
    SDHC1_REGS->SDHC_CCR &= (uint16_t)(~(SDHC_CCR_INTCLKEN_Msk | SDHC_CCR_SDCLKEN_Msk));
}

void SDHC1_DmaSetup (
    uint8_t* buffer,
    uint32_t numBytes,
    SDHC_DATA_TRANSFER_DIR direction
)
{
    (void)direction;

    /* Each ADMA2 descriptor can transfer 65536 bytes (or 128 blocks) of data.
     * Block count register being a 16 bit register, maximum number of blocks is
     * limited to 65536 blocks. Hence, combined length of data that can be
     * transferred by all the descriptors is 512 bytes x 65536 blocks, assuming
     * a block size of 512 bytes.
     */

    if (numBytes <= 65536U)
    {
        sdhc1DmaDescrTable[0].address = (uint32_t)(buffer);
        sdhc1DmaDescrTable[0].length = (uint16_t)numBytes;
        sdhc1DmaDescrTable[0].attribute = \
            (SDHC_DESC_TABLE_ATTR_XFER_DATA | SDHC_DESC_TABLE_ATTR_VALID | SDHC_DESC_TABLE_ATTR_INTR);


         /* The last descriptor line must indicate the end of the descriptor list */
        sdhc1DmaDescrTable[0].attribute |= (uint16_t)(SDHC_DESC_TABLE_ATTR_END);

        /* Clean the cache associated with the modified descriptors */
        DCACHE_CLEAN_BY_ADDR((uint32_t*)(sdhc1DmaDescrTable), (sizeof(SDHC_ADMA_DESCR)));

        /* Set the starting address of the descriptor table */
        SDHC1_REGS->SDHC_ASAR[0] = (uint32_t)(&sdhc1DmaDescrTable[0]);
    }
}

bool SDHC1_ClockSet ( uint32_t speed)
{
    uint32_t baseclk_frq = 0U;
    uint16_t divider = 0U;
    uint32_t clkmul = 0U;
    bool retval = false;

    /* Disable clock before changing it */
    if ((SDHC1_REGS->SDHC_CCR & SDHC_CCR_SDCLKEN_Msk) != 0U)
    {
        while ((SDHC1_REGS->SDHC_PSR & (SDHC_PSR_CMDINHC_Msk | SDHC_PSR_CMDINHD_Msk)) != 0U)
		{
            /* Wait for clock status to clear */
		}
        SDHC1_REGS->SDHC_CCR &= (uint16_t)(~SDHC_CCR_SDCLKEN_Msk);
    }

    /* Get the base clock frequency */
    baseclk_frq = (SDHC1_REGS->SDHC_CA0R & (SDHC_CA0R_BASECLKF_Msk)) >> SDHC_CA0R_BASECLKF_Pos;
    if (baseclk_frq == 0U)
    {
        baseclk_frq = (uint32_t)(SDHC1_BASE_CLOCK_FREQUENCY/2U);
    }
    else
    {
        baseclk_frq *= 1000000U;
    }

    clkmul = (SDHC1_REGS->SDHC_CA1R & (SDHC_CA1R_CLKMULT_Msk)) >> SDHC_CA1R_CLKMULT_Pos;
    if (clkmul > 0U)
    {
        /* F_SDCLK = F_MULTCLK/(DIV+1), where F_MULTCLK = F_BASECLK x (CLKMULT+1)
            F_SDCLK = (F_BASECLK x (CLKMULT + 1))/(DIV + 1)
            For a given F_SDCLK, DIV = [(F_BASECLK x (CLKMULT + 1))/F_SDCLK] - 1
        */
        divider = (uint16_t)((baseclk_frq * (clkmul + 1U)) / speed);
        if (divider > 0U)
        {
            divider = divider - 1U;
        }
        SDHC1_REGS->SDHC_CCR |= SDHC_CCR_CLKGSEL_Msk;

        if (speed > SDHC_CLOCK_FREQ_DS_25_MHZ)
        {
            /* Enable the high speed mode */
            SDHC1_REGS->SDHC_HC1R |= SDHC_HC1R_HSEN_Msk;
        }
        else
        {
            /* Clear the high speed mode */
            SDHC1_REGS->SDHC_HC1R &= (uint8_t)(~SDHC_HC1R_HSEN_Msk);
        }

        if (((SDHC1_REGS->SDHC_HC1R & SDHC_HC1R_HSEN_Msk) != 0U) && (divider == 0U))
        {
            /* IP limitation, if high speed mode is active divider must be non zero */
            divider = 1;
        }

        /* Set the divider */
        SDHC1_REGS->SDHC_CCR &= (uint16_t)(~(SDHC_CCR_SDCLKFSEL_Msk | SDHC_CCR_USDCLKFSEL_Msk));
        SDHC1_REGS->SDHC_CCR |= SDHC_CCR_SDCLKFSEL((divider & 0xffU)) | SDHC_CCR_USDCLKFSEL((divider >> 8U));

        /* Enable internal clock */
        SDHC1_REGS->SDHC_CCR |= SDHC_CCR_INTCLKEN_Msk;

        while((SDHC1_REGS->SDHC_CCR & SDHC_CCR_INTCLKS_Msk) == 0U)
        {
            /* Wait for the internal clock to stabilize */
        }

        /* Enable the SDCLK */
        SDHC1_REGS->SDHC_CCR |= SDHC_CCR_SDCLKEN_Msk;

        retval = true;
    }
    return retval;
}

void SDHC1_ResponseRead (
    SDHC_READ_RESPONSE_REG respReg,
    uint32_t* response
)
{
    switch (respReg)
    {
        case SDHC_READ_RESP_REG_1:
            *response = SDHC1_REGS->SDHC_RR[1];
            break;

        case SDHC_READ_RESP_REG_2:
            *response = SDHC1_REGS->SDHC_RR[2];
            break;

        case SDHC_READ_RESP_REG_3:
            *response = SDHC1_REGS->SDHC_RR[3];
            break;

        case SDHC_READ_RESP_REG_ALL:
            response[0] = SDHC1_REGS->SDHC_RR[0];
            response[1] = SDHC1_REGS->SDHC_RR[1];
            response[2] = SDHC1_REGS->SDHC_RR[2];
            response[3] = SDHC1_REGS->SDHC_RR[3];
            break;

		case SDHC_READ_RESP_REG_0:
        default:
            *response = SDHC1_REGS->SDHC_RR[0];
            break;
    }
}

void SDHC1_CommandSend (
    uint8_t opCode,
    uint32_t argument,
    uint8_t respType,
    SDHC_DataTransferFlags transferFlags
)
{
    uint16_t cmd = 0U;
    uint16_t normalIntSigEnable = 0U;
    uint16_t flags = 0U;

    /* Clear the flags */
    sdhc1Obj.isCmdInProgress = false;
    sdhc1Obj.isDataInProgress = false;
    sdhc1Obj.errorStatus = 0U;

    /* Keep the card insertion and removal interrupts enabled */
    normalIntSigEnable = (SDHC_NISIER_CINS_Msk | SDHC_NISIER_CREM_Msk);

    switch (respType)
    {
        case SDHC_CMD_RESP_R1:
        case SDHC_CMD_RESP_R5:
        case SDHC_CMD_RESP_R6:
        case SDHC_CMD_RESP_R7:
            flags = (SDHC_CR_RESPTYP_48_BIT_Val | SDHC_CR_CMDCCEN_Msk | SDHC_CR_CMDICEN_Msk);
            break;

        case SDHC_CMD_RESP_R3:
        case SDHC_CMD_RESP_R4:
            flags = SDHC_CR_RESPTYP_48_BIT_Val;
            break;

        case SDHC_CMD_RESP_R1B:
            flags = (SDHC_CR_RESPTYP_48_BIT_BUSY_Val | SDHC_CR_CMDCCEN_Msk | SDHC_CR_CMDICEN_Msk);

            /* Commands with busy response will wait for transfer complete bit */
            normalIntSigEnable |= SDHC_NISIER_TRFC_Msk;
            break;

        case SDHC_CMD_RESP_R2:
            flags = (SDHC_CR_RESPTYP_136_BIT_Val | SDHC_CR_CMDCCEN_Msk);
            break;

        default:
            flags = SDHC_CR_RESPTYP_NONE_Val;
            break;
    }

    /* Enable command complete interrupt, for commands that do not have busy response type */
    if (respType != (uint8_t)SDHC_CMD_RESP_R1B)
    {
        normalIntSigEnable |= SDHC_NISIER_CMDC_Msk;
    }

    if (transferFlags.isDataPresent == true)
    {
        sdhc1Obj.isDataInProgress = true;
        SDHC1_TransferModeSet(opCode);
        /* Enable data transfer complete and DMA interrupt */
        normalIntSigEnable |= (SDHC_NISIER_TRFC_Msk | SDHC_NISIER_DMAINT_Msk);
    }
    else
    {
        SDHC1_REGS->SDHC_TMR = 0U;
    }

    /* Enable the needed normal interrupt signals */
    SDHC1_REGS->SDHC_NISIER = normalIntSigEnable;

    /* Enable all the error interrupt signals */
    SDHC1_REGS->SDHC_EISIER = SDHC_EISIER_Msk;

    SDHC1_REGS->SDHC_ARG1R = argument;

    sdhc1Obj.isCmdInProgress = true;

    cmd = (SDHC_CR_CMDIDX((uint16_t)opCode) | (transferFlags.isDataPresent ? (1U << SDHC_CR_DPSEL_Pos) : 0U) | (uint16_t)flags);
    SDHC1_REGS->SDHC_CR = cmd;
}

void SDHC1_ModuleInit( void )
{
    /* Reset module*/
    SDHC1_REGS->SDHC_SRR |= SDHC_SRR_SWRSTALL_Msk;
    while((SDHC1_REGS->SDHC_SRR & SDHC_SRR_SWRSTALL_Msk) == SDHC_SRR_SWRSTALL_Msk)
	{
        /* Wait for reset to complete */
	}

    /* Clear the normal and error interrupt status flags */
    SDHC1_REGS->SDHC_EISTR = SDHC_EISTR_Msk;
    SDHC1_REGS->SDHC_NISTR = SDHC_NISTR_Msk;

    /* Enable all the normal interrupt status and error status generation */
    SDHC1_REGS->SDHC_NISTER = SDHC_NISTER_Msk;
    SDHC1_REGS->SDHC_EISTER = SDHC_EISTER_Msk;

    /* Set timeout control register */
    SDHC1_REGS->SDHC_TCR = SDHC_TCR_DTCVAL(0xEU);

    /* Enable ADMA2 (Check CA0R capability register first) */
    SDHC1_REGS->SDHC_HC1R |= SDHC_HC1R_DMASEL(2U);

    /* SD Bus Voltage Select = 3.3V, SD Bus Power = On */
    SDHC1_REGS->SDHC_PCR = (SDHC_PCR_SDBVSEL_3V3 | SDHC_PCR_SDBPWR_ON);

    /* Set initial clock to 400 KHz*/
    (void)SDHC1_ClockSet (SDHC_CLOCK_FREQ_400_KHZ);

    /* Clear the high speed bit and set the data width to 1-bit mode */
    SDHC1_REGS->SDHC_HC1R &= (uint8_t)(~(SDHC_HC1R_HSEN_Msk | SDHC_HC1R_DW_Msk));

    /* Enable card inserted and card removed interrupt signals */
    SDHC1_REGS->SDHC_NISIER = (SDHC_NISIER_CINS_Msk | SDHC_NISIER_CREM_Msk);
}

void SDHC1_Initialize( void )
{
    SDHC1_VariablesInit();
    SDHC1_ModuleInit();
}

void SDHC1_CallbackRegister(SDHC_CALLBACK callback, uintptr_t contextHandle)
{
    if (callback != NULL)
    {
        sdhc1Obj.callback = callback;
        sdhc1Obj.context = contextHandle;
    }
}