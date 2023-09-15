/*******************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
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
#include "plib_clk.h"

#define PLL_ID_PLLA     0U
#define PLL_ID_UPLL     1U
#define PLL_ID_PLLADIV2 4U


/*********************************************************************************
Generate Software delay (in multiples of microsecond units)
*********************************************************************************/
static void swDelayUs(uint32_t delay)
{
    uint32_t i, count;

    /* delay * (CPU_FREQ/1000000) / 6 */
    count = delay *  (800000000U/1000000U)/6U;

    /* 6 CPU cycles per iteration */
    for (i = 0U; i < count; i++)
    {
        __NOP();
    }
}

/*********************************************************************************
Initialize UPLL
*********************************************************************************/
static void initUPLLCLK(void)
{
    /* STEP 1: PMC_PLL_UPDT to target UPLL, startup time of 150us and update disabled */
    PMC_REGS->PMC_PLL_UPDT = PMC_PLL_UPDT_STUPTIM(0x6) |
                             PMC_PLL_UPDT_UPDATE(0x0) |
                             PMC_PLL_UPDT_ID(PLL_ID_UPLL);

    /* STEP 2: Set the Analog controls to the values recommended by data sheet */
    PMC_REGS->PMC_PLL_ACR = PMC_PLL_ACR_LOOP_FILTER(0x1B) |
                            PMC_PLL_ACR_LOCK_THR(0x4) |
                            PMC_PLL_ACR_CONTROL(0x10);

    /* STEP 3: Set loop paramaters for the fractional PLL */
    PMC_REGS->PMC_PLL_CTRL1 = PMC_PLL_CTRL1_MUL(39) |
                              PMC_PLL_CTRL1_FRACR(0);

    /* STEP 4: Enable UTMI Bandgap */
    PMC_REGS->PMC_PLL_ACR |= PMC_PLL_ACR_UTMIBG_Msk;

    /* STEP 5: Wait 10 us */
    swDelayUs(10);

    /* STEP 6: Enable UTMI Internal Regulator */
    PMC_REGS->PMC_PLL_ACR |= PMC_PLL_ACR_UTMIVR_Msk;

    /* STEP 7: Wait 10 us */
    swDelayUs(10);

    /* STEP 8: Update the PLL controls */
    PMC_REGS->PMC_PLL_UPDT |= PMC_PLL_UPDT_UPDATE_Msk;

    /* STEP 9: Enable UPLL, lock and PMC clock from UPLL */
    PMC_REGS->PMC_PLL_CTRL0 = PMC_PLL_CTRL0_ENLOCK_Msk |
                              PMC_PLL_CTRL0_ENPLL_Msk |
                              PMC_PLL_CTRL0_ENPLLCK_Msk;

    /* STEP 10: Wait for the lock bit to rise by polling the PMC_PLL_ISR0 */
    while ((PMC_REGS->PMC_PLL_ISR0 & PMC_PLL_ISR0_LOCKU_Msk) != PMC_PLL_ISR0_LOCKU_Msk)
    {
        /* Wait */
    }
}



/*********************************************************************************
Initialize Programmable clocks
*********************************************************************************/
static void initProgrammableClk(void)
{
    PMC_REGS->PMC_SCDR |= PMC_SCDR_PCK0_Msk | PMC_SCDR_PCK1_Msk;
}

/*********************************************************************************
Initialize Peripheral clocks
*********************************************************************************/
static void initPeriphClk(void)
{
    struct {
        uint8_t id;
        uint8_t clken;
        uint8_t gclken;
        uint8_t css;
        uint8_t div_val;
    } periphList[] =
    {
        { ID_PIOA, 1, 0, 0, 0},
        { ID_PIOB, 1, 0, 0, 0},
        { ID_PIOC, 1, 0, 0, 0},
        { ID_TC0, 1, 0, 0, 0},
        { ID_UHPHS, 1, 0, 0, 0},
        { ID_PIOD, 1, 0, 0, 0},
        { ID_DBGU, 1, 0, 0, 0},
        { ID_PERIPH_MAX + 1, 0, 0, 0, 0}//end of list marker
    };

    uint32_t count = sizeof(periphList)/sizeof(periphList[0]);
    for (uint32_t i = 0; i < count; i++)
    {
        if (periphList[i].id == (uint8_t)((uint32_t)ID_PERIPH_MAX + 1U))
        {
            break;
        }

        PMC_REGS->PMC_PCR = PMC_PCR_CMD_Msk |
                            PMC_PCR_GCLKEN(periphList[i].gclken) |
                            PMC_PCR_EN(periphList[i].clken) |
                            PMC_PCR_GCLKDIV(periphList[i].div_val) |
                            PMC_PCR_GCLKCSS(periphList[i].css) |
                            PMC_PCR_PID(periphList[i].id);
    }

}

/*********************************************************************************
Initialize USB OHCI clocks
*********************************************************************************/
static void initUSBClk ( void )
{
    /* Configure USB OHCI clock source and divider */
    PMC_REGS->PMC_USB = PMC_USB_USBDIV(9) | PMC_USB_USBS_UPLL;

    /* Enable UHP48M and UHP12M OHCI clocks */
    PMC_REGS->PMC_SCER |= PMC_SCER_UHP_Msk;
}


/*********************************************************************************
Clock Initialize
*********************************************************************************/
void CLK_Initialize( void )
{

    /* Initialize UPLLA clock generator */
    initUPLLCLK();

    /* Initialize Programmable clock */
    initProgrammableClk();

    /* Initialize Peripheral clock */
    initPeriphClk();

    /* Initialize USB Clock */
    initUSBClk();

}
