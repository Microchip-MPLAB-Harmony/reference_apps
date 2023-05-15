/*******************************************************************************
  System Initialization File

  File Name:
    initialization.c

  Summary:
    This file contains source code necessary to initialize the system.

  Description:
    This file contains source code necessary to initialize the system.  It
    implements the "SYS_Initialize" function, defines the configuration bits,
    and allocates any necessary global system resources,
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************************
* Copyright (C) 2023 Microchip Technology Inc. and its subsidiaries.

 * Subject to your compliance with these terms, you may use this Microchip software
 * and any derivatives exclusively with Microchip products. You are responsible for
 * complying with third party license terms applicable to your use of third party
 * software (including open source software) that may accompany this Microchip software.

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
 *******************************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "definitions.h"
#include "device.h"
#include "unsecure_interface.h"

// ****************************************************************************
// ****************************************************************************
// Section: Configuration Bits
// ****************************************************************************
// ****************************************************************************
#pragma config NVMCTRL_SULCK = 0x7
#pragma config NVMCTRL_NSULCK = 0x6
#pragma config BOD33USERLEVEL = 0x6
#pragma config BOD33_DIS = SET
#pragma config BOD33_ACTION = 0x1
#pragma config WDT_RUNSTDBY = CLEAR
#pragma config WDT_ENABLE = CLEAR
#pragma config WDT_ALWAYSON = CLEAR
#pragma config WDT_PER = 0xb
#pragma config WDT_WINDOW = 0xb
#pragma config WDT_EWOFFSET = 0xb
#pragma config WDT_WEN = CLEAR
#pragma config BOD33_HYST = CLEAR
#pragma config IDAU_RXN = CLEAR
#pragma config NVMCTRL_DXN = SET
#pragma config IDAU_AS = 0x400
#pragma config IDAU_ANSC = 0x86
#pragma config IDAU_DS = 0x38
#pragma config IDAU_RS = 0x100
#pragma config NVMCTRL_URWEN = SET
#pragma config NONSECA_PAC = CLEAR
#pragma config NONSECA_PM = CLEAR
#pragma config NONSECA_MCLK = CLEAR
#pragma config NONSECA_RSTC = CLEAR
#pragma config NONSECA_OSCCTRL = CLEAR
#pragma config NONSECA_OSC32KCTRL = CLEAR
#pragma config NONSECA_SUPC = CLEAR
#pragma config NONSECA_GCLK = CLEAR
#pragma config NONSECA_WDT = CLEAR
#pragma config NONSECA_RTC = CLEAR
#pragma config NONSECA_EIC = CLEAR
#pragma config NONSECA_FREQM = CLEAR
#pragma config NONSECA_PORT = CLEAR
#pragma config NONSECA_AC = CLEAR
#pragma config NONSECB_IDAU = CLEAR
#pragma config NONSECB_DSU = SET
#pragma config NONSECB_NVMCTRL = CLEAR
#pragma config NONSECB_DMAC = CLEAR
#pragma config NONSECB_USB = CLEAR
#pragma config NONSECC_EVSYS = CLEAR
#pragma config NONSECC_SERCOM0 = CLEAR
#pragma config NONSECC_SERCOM1 = CLEAR
#pragma config NONSECC_SERCOM2 = CLEAR
#pragma config NONSECC_SERCOM3 = CLEAR
#pragma config NONSECC_SERCOM4 = CLEAR
#pragma config NONSECC_SERCOM5 = CLEAR
#pragma config NONSECC_TC0 = CLEAR
#pragma config NONSECC_TC1 = SET
#pragma config NONSECC_TC2 = SET
#pragma config NONSECC_TCC0 = SET
#pragma config NONSECC_TCC1 = CLEAR
#pragma config NONSECC_TCC2 = CLEAR
#pragma config NONSECC_TCC3 = CLEAR
#pragma config NONSECC_ADC = SET
#pragma config NONSECC_DAC = CLEAR
#pragma config NONSECC_PTC = CLEAR
#pragma config NONSECC_TRNG = CLEAR
#pragma config NONSECC_CCL = CLEAR
#pragma config NONSECC_I2S = CLEAR
#pragma config NONSECC_OPAMP = CLEAR
#pragma config NONSECC_TRAM = CLEAR
#pragma config BOOTROM_CDIROFFSET = 0x0
#pragma config BOOTROM_USERCRC = 0xe87673b6
#pragma config IDAU_BNSC = 0x0
#pragma config BOOTROM_BOOTOPT = 0x0
#pragma config IDAU_BOOTPROT = 0x0
#pragma config BOOTROM_SECCFGLOCK = SET
#pragma config BOOTROM_DICEEN = CLEAR
#pragma config NVMCTRL_BCWEN = SET
#pragma config NVMCTRL_BCREN = SET
#pragma config BOOTROM_BOCORCRC = 0xc0349acc
#pragma config BOOTROM_CEKEY0_0 = 0xffffffff
#pragma config BOOTROM_CEKEY0_1 = 0xffffffff
#pragma config BOOTROM_CEKEY0_2 = 0xffffffff
#pragma config BOOTROM_CEKEY0_3 = 0xffffffff
#pragma config BOOTROM_CEKEY1_0 = 0xffffffff
#pragma config BOOTROM_CEKEY1_1 = 0xffffffff
#pragma config BOOTROM_CEKEY1_2 = 0xffffffff
#pragma config BOOTROM_CEKEY1_3 = 0xffffffff
#pragma config BOOTROM_CEKEY2_0 = 0xffffffff
#pragma config BOOTROM_CEKEY2_1 = 0xffffffff
#pragma config BOOTROM_CEKEY2_2 = 0xffffffff
#pragma config BOOTROM_CEKEY2_3 = 0xffffffff
#pragma config BOOTROM_CRCKEY_0 = 0xffffffff
#pragma config BOOTROM_CRCKEY_1 = 0xffffffff
#pragma config BOOTROM_CRCKEY_2 = 0xffffffff
#pragma config BOOTROM_CRCKEY_3 = 0xffffffff
#pragma config BOOTROM_BOOTKEY_0 = 0xffffffff
#pragma config BOOTROM_BOOTKEY_1 = 0xffffffff
#pragma config BOOTROM_BOOTKEY_2 = 0xffffffff
#pragma config BOOTROM_BOOTKEY_3 = 0xffffffff
#pragma config BOOTROM_BOOTKEY_4 = 0xffffffff
#pragma config BOOTROM_BOOTKEY_5 = 0xffffffff
#pragma config BOOTROM_BOOTKEY_6 = 0xffffffff
#pragma config BOOTROM_BOOTKEY_7 = 0xffffffff
#pragma config BOOTROM_UDS_0 = 0xffffffff
#pragma config BOOTROM_UDS_1 = 0xffffffff
#pragma config BOOTROM_UDS_2 = 0xffffffff
#pragma config BOOTROM_UDS_3 = 0xffffffff
#pragma config BOOTROM_UDS_4 = 0xffffffff
#pragma config BOOTROM_UDS_5 = 0xffffffff
#pragma config BOOTROM_UDS_6 = 0xffffffff
#pragma config BOOTROM_UDS_7 = 0xffffffff
#pragma config BOOTROM_IOPROTKEY_0 = 0xffffffff
#pragma config BOOTROM_IOPROTKEY_1 = 0xffffffff
#pragma config BOOTROM_IOPROTKEY_2 = 0xffffffff
#pragma config BOOTROM_IOPROTKEY_3 = 0xffffffff
#pragma config BOOTROM_IOPROTKEY_4 = 0xffffffff
#pragma config BOOTROM_IOPROTKEY_5 = 0xffffffff
#pragma config BOOTROM_IOPROTKEY_6 = 0xffffffff
#pragma config BOOTROM_IOPROTKEY_7 = 0xffffffff
#pragma config BOOTROM_BOCORHASH_0 = 0xffffffff
#pragma config BOOTROM_BOCORHASH_1 = 0xffffffff
#pragma config BOOTROM_BOCORHASH_2 = 0xffffffff
#pragma config BOOTROM_BOCORHASH_3 = 0xffffffff
#pragma config BOOTROM_BOCORHASH_4 = 0xffffffff
#pragma config BOOTROM_BOCORHASH_5 = 0xffffffff
#pragma config BOOTROM_BOCORHASH_6 = 0xffffffff
#pragma config BOOTROM_BOCORHASH_7 = 0xffffffff



// *****************************************************************************
// *****************************************************************************
// Section: Local initialization functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void STDIO_BufferModeSet ( void )

  Summary:
    Sets the buffering mode for stdin and stdout

  Remarks:
 ********************************************************************************/
static void STDIO_BufferModeSet(void)
{

    /* Make stdin unbuffered */
    setbuf(stdin, NULL);

    /* Make stdout unbuffered */
    setbuf(stdout, NULL);
}




/*******************************************************************************
  Function:
    void SYS_Initialize ( void *data )

  Summary:
    Initializes the board, services, drivers, application and other modules.

  Remarks:
 */

void SYS_Initialize ( void* data )
{
    PM_Initialize();


    NVMCTRL_SEC_REGS->NVMCTRL_CTRLB = NVMCTRL_CTRLB_RWS(2);

    STDIO_BufferModeSet();

    PORT_Initialize();

    CLOCK_Initialize();



    NVMCTRL_Initialize();

    SUPC_Initialize();
    
  
    
    RTC_Initialize();
	touch_init();

    TC0_TimerInitialize();

	TRNG_Initialize();

   SERCOM2_USART_Initialize();

    SERCOM1_I2C_Initialize();

    SERCOM0_USART_Initialize();

    EVSYS_Initialize();

    DMAC_Initialize();
    
    SERCOM5_USART_Initialize();

    EIC_Initialize();
    

    NVIC_Initialize();

}


/*******************************************************************************
 End of File
*/
