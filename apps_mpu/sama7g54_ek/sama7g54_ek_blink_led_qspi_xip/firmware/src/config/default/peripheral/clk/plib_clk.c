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


#include <stdbool.h>
#include "device.h"
#include "plib_clk.h"

#define PLL_ID_CPUPLL           0U
#define PLL_ID_SYSPLL           1U
#define PLL_ID_DDRPLL           2U
#define PLL_ID_IMGPLL           3U
#define PLL_ID_BAUDPLL          4U
#define PLL_ID_AUDIOPLL         5U
#define PLL_ID_ETHPLL           6U
#define PLL_UPDT_STUPTIM_VAL    0x3FU
#define PLL_ACR_RECOMMENDED     0x1B040010U

#define APB_DEBUG_S_BASE 0xE8800000U
#define TIMESTAMP_OFFSET 0x43000U
#define PSELCTRL_REGS ((pselctrl_registers_t*)(APB_DEBUG_S_BASE + TIMESTAMP_OFFSET))

#define CNTCR_EN_Pos            0U
#define CNTCR_EN_Msk            (1U << CNTCR_EN_Pos)

#define SYSTEM_COUNTER_FREQUENCY 24000000U

typedef struct pmc_pll_cfg {
    uint32_t mul;
    uint32_t divpll;
    bool eniopllck;
    uint32_t divio;
    uint32_t count;
    uint32_t fracr;
    uint32_t acr;
    bool ss;
    uint32_t step;
    uint32_t nstep;
}pmc_pll_cfg_t;


typedef struct
{
    __IO   uint32_t CNTCR;
    __O    uint32_t CNTSR;
    __IO   uint32_t CNTCVL;
    __IO   uint32_t CNTCVU;
    __I    uint8_t  Reserved[0x14];
    __IO   uint32_t CNTFID0;
}pselctrl_registers_t;


/*********************************************************************************
Initialize Programmable clocks
*********************************************************************************/
static void initProgrammableClocks(void)
{
    PMC_REGS->PMC_SCDR = PMC_SCDR_PCK_Msk;
}

/*********************************************************************************
Initialize Peripheral clocks
*********************************************************************************/
static void initPeripheralClocks(void)
{
    const uint8_t EOL_MARKER = ((uint8_t)ID_PERIPH_MAX + 1U);
    struct {
        uint8_t id;
        uint8_t clken;
        uint8_t gclken;
        uint8_t css;
        uint8_t divs;
    } periphList[] =
    {
        {ID_PIOA, 1U, 0U, 0U, 0U},
        {EOL_MARKER, 0U, 0U, 0U, 0U}//end of list marker
    };

    uint32_t count = sizeof(periphList)/sizeof(periphList[0]);
    for (uint32_t i = 0U; i < count; i++)
    {
        if (periphList[i].id == EOL_MARKER)
        {
            break;
        }

        PMC_REGS->PMC_PCR = PMC_PCR_CMD_Msk |\
                            PMC_PCR_GCLKEN(periphList[i].gclken) |\
                            PMC_PCR_EN(periphList[i].clken) |\
                            PMC_PCR_GCLKDIV(periphList[i].divs) |\
                            PMC_PCR_GCLKCSS(periphList[i].css) |\
                            PMC_PCR_PID(periphList[i].id);
    }

}

/*********************************************************************************
Initialize system counter
*********************************************************************************/
static void initSystemCounter(void)
{
    /* Turn on GCLK 29 if it is not enabled already  */
    if ((PMC_REGS->PMC_GCSR0 & PMC_GCSR0_GPID29_Msk) == 0U)
    {
        PMC_REGS->PMC_PCR = PMC_PCR_CMD_Msk |\
                            PMC_PCR_GCLKEN(1U) |\
                            PMC_PCR_EN(0U) |\
                            PMC_PCR_GCLKDIV(0U) |\
                            PMC_PCR_GCLKCSS_MAINCK |\
                            PMC_PCR_PID(29U);
        while((PMC_REGS->PMC_GCSR0 & PMC_GCSR0_GPID29_Msk) == 0U)
        {
            /* Wait for GCLK 29 to enabled */
        }
    }

    /* Set timestamp count frequency */
    PSELCTRL_REGS->CNTFID0 = SYSTEM_COUNTER_FREQUENCY;

    /* Enable counter */
    PSELCTRL_REGS->CNTCR |= CNTCR_EN_Msk;

}

/*********************************************************************************
Clock Initialize
*********************************************************************************/
void CLK_Initialize( void )
{
    /* Set main crystal frequency for UTMI PLL */
    PMC_REGS->PMC_XTALF = PMC_XTALF_XTALF_F24M;

    /* Initialize Programmable clock */
    initProgrammableClocks();

    /* Initialize Peripheral clock */
    initPeripheralClocks();

    /* Initialize system counter (timestamp generator) */
    initSystemCounter();
}

