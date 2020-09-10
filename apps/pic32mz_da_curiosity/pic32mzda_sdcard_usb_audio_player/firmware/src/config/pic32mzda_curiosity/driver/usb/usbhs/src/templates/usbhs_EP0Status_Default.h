/*******************************************************************************
  USBHS Peripheral Library Template Implementation

  File Name:
    usbhs_EP0Status_Default.h

  Summary:
    USBHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : EP0Status
    and its Variant : Default
    For following APIs :
        PLIB_USBHS_EP0StatusGet
        PLIB_USBHS_EP0StatusClear
        PLIB_USBHS_EP0INHandshakeSend
        PLIB_USBHS_EP0INTokenSend
        PLIB_USBHS_EP0OUTHandshakeSend
        PLIB_USBHS_EP0INHandshakeClear
        PLIB_USBHS_ExistsEP0Status

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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

//DOM-IGNORE-END

#ifndef _USBHS_EP0STATUS_DEFAULT_H
#define _USBHS_EP0STATUS_DEFAULT_H

#include "usbhs_registers.h"

//******************************************************************************
/* Function :  USBHS_EP0StatusGet_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0StatusGet 

  Description:
    This template implements the Default variant of the 
    PLIB_USBHS_EP0StatusGet function.
*/

PLIB_TEMPLATE uint8_t USBHS_EP0StatusGet_Default( USBHS_MODULE_ID index )
{
    /* Returns the entire CSR0L register contents */
    
    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    return(usbhs->EPCSR[0].CSR0L_HOSTbits.w);
}

//******************************************************************************
/* Function :  USBHS_EP0StatusClear_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0StatusClear 

  Description:
    This template implements the Default variant of the 
    PLIB_USBHS_EP0StatusClear function.
*/

PLIB_TEMPLATE void USBHS_EP0StatusClear_Default
( 
    USBHS_MODULE_ID index , 
    USBHS_EP0_ERROR error
)
{
    /* This function clears the specified error */
    
    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    usbhs->EPCSR[0].CSR0L_HOSTbits.w &= (~(error));
}

//******************************************************************************
/* Function :  USBHS_EP0SentStallClear_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0SentStallClear 

  Description:
    This template implements the Default variant of the 
    PLIB_USBHS_EP0SentStallClear function.
*/

PLIB_TEMPLATE void USBHS_EP0SentStallClear_Default( USBHS_MODULE_ID index)
{
    /* This function clears sent stall bit */

    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    usbhs->EPCSR[0].CSR0L_HOSTbits.RXSTALL = 0;
}

//******************************************************************************
/* Function :  USBHS_EP0SetupEndServiced_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0SetupEndServiced 

  Description:
    This template implements the Default variant of the 
    PLIB_USBHS_EP0SetupEndServiced function.
*/

PLIB_TEMPLATE void USBHS_EP0SetupEndServiced_Default( USBHS_MODULE_ID index)
{
    /* This function sets the "Serviced Setup End" bit
     * which then clears the setup end bit */

    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    usbhs->EPCSR[0].CSR0L_DEVICEbits.SVSSETEND = 1;
}

//******************************************************************************
/* Function :  USBHS_EP0RxPktRdyServiced_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0RxPktRdyServiced 

  Description:
    This template implements the Default variant of the 
    PLIB_USBHS_EP0RxPktRdyServiced function.
*/

PLIB_TEMPLATE void USBHS_EP0RxPktRdyServiced_Default( USBHS_MODULE_ID index)
{
    /* This function sets the Serviced RxPktRdy bit */

    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    usbhs->EPCSR[0].CSR0L_DEVICEbits.SVCRPR = 1;
}

//******************************************************************************
/* Function :  USBHS_EP0RxPktRdyServicedDataEnd_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0RxPktRdyServicedDataEnd 

  Description:
    This template implements the Default variant of the 
    PLIB_USBHS_EP0RxPktRdyServicedDataEnd function.
*/

PLIB_TEMPLATE void USBHS_EP0RxPktRdyServicedDataEnd_Default( USBHS_MODULE_ID index)
{
    /* This function sets the RxPktRdy serviced bit and the Data End bit. */
    
    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    usbhs->EPCSR[0].CSR0L_DEVICEbits.w = (USBHS_EP0_DEVICE_SERVICED_RXPKTRDY| USBHS_EP0_DEVICE_DATAEND);
}

//******************************************************************************
/* Function :  USBHS_EP0TxPktRdyDataEnd_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0TxPktRdyDataEnd 

  Description:
    This template implements the Default variant of the 
    PLIB_USBHS_EP0TxPktRdyDataEnd function.
*/

PLIB_TEMPLATE void USBHS_EP0TxPktRdyDataEnd_Default( USBHS_MODULE_ID index)
{
    /* This function sets the TxPktRdy bit and the Data End bit. */

    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    usbhs->EPCSR[0].CSR0L_DEVICEbits.w = (USBHS_EP0_DEVICE_TXPKTRDY| USBHS_EP0_DEVICE_DATAEND);
}

//******************************************************************************
/* Function :  USBHS_EP0TxPktRdy_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0TxPktRdy 

  Description:
    This template implements the Default variant of the 
    PLIB_USBHS_EP0TxPktRdy function.
*/

PLIB_TEMPLATE void USBHS_EP0TxPktRdy_Default( USBHS_MODULE_ID index)
{
    /* This function sets the TxPktRdy bit. */

    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    usbhs->EPCSR[0].CSR0L_DEVICEbits.TXPKTRDY = 1;
}

//******************************************************************************
/* Function :  USBHS_EP0DataEndSet_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0DataEndSet 

  Description:
    This template implements the Default variant of the 
    PLIB_USBHS_EP0DataEndSet function.
*/

PLIB_TEMPLATE void USBHS_EP0DataEndSet_Default( USBHS_MODULE_ID index)
{
    /* This function sets the data end bit */

    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    usbhs->EPCSR[0].CSR0L_DEVICEbits.DATAEND = 1;
}

//******************************************************************************
/* Function :  USBHS_EP0INHandshakeSend_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0INHandshakeSend 

  Description:
    This template implements the Default variant of the 
    PLIB_USBHS_EP0INHandshakeSend function.
*/

PLIB_TEMPLATE void USBHS_EP0INHandshakeSend_Default( USBHS_MODULE_ID index )
{
    /* Starts the IN Handshake stage of a control transfer on EP0 in 
     * Host mode. */
    
    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    usbhs->EPCSR[0].CSR0L_HOSTbits.w = (USBHS_EP0_HOST_STATUS_STAGE_START | USBHS_EP0_HOST_REQPKT);
}


//******************************************************************************
/* Function :  USBHS_EP0INTokenSend_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0INTokenSend 

  Description:
    This template implements the Default variant of the 
    PLIB_USBHS_EP0INTokenSend function.
*/

PLIB_TEMPLATE void USBHS_EP0INTokenSend_Default( USBHS_MODULE_ID index )
{
    /* Sends an IN token on EP0 in Host mode */
    
    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    usbhs->EPCSR[0].CSR0L_HOSTbits.REQPKT = 1;
}

//******************************************************************************
/* Function :  USBHS_EP0StallEnable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0StallEnable 

  Description:
    This template implements the Default variant of the 
    PLIB_USBHS_EP0StallEnable function.
*/

PLIB_TEMPLATE void USBHS_EP0StallEnable_Default( USBHS_MODULE_ID index )
{
    /* Causes a stall to be sent on EP0 in device mode */
    
    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    usbhs->EPCSR[0].CSR0L_DEVICEbits.SENDSTALL = 1;
}

//******************************************************************************
/* Function :  USBHS_EP0StallDisable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0StallDisable 

  Description:
    This template implements the Default variant of the 
    PLIB_USBHS_EP0StallDisable function.
*/

PLIB_TEMPLATE void USBHS_EP0StallDisable_Default( USBHS_MODULE_ID index )
{
    /* Clear the SENDSTALL bit */
    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    usbhs->EPCSR[0].CSR0L_DEVICEbits.SENDSTALL = 0;
}

//******************************************************************************
/* Function :  USBHS_EP0OUTHandshakeSend_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0OUTHandshakeSend 

  Description:
    This template implements the Default variant of the 
    PLIB_USBHS_EP0OUTHandshakeSend function.
*/

PLIB_TEMPLATE void USBHS_EP0OUTHandshakeSend_Default( USBHS_MODULE_ID index )
{
    /* Starts an OUT Handshake stage on EP0 in host mode. */
    
    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    usbhs->EPCSR[0].CSR0L_HOSTbits.w = (USBHS_EP0_HOST_STATUS_STAGE_START | USBHS_EP0_HOST_TXPKTRDY);
}

//******************************************************************************
/* Function :  USBHS_EP0INHandshakeClear_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0INHandshakeClear 

  Description:
    This template implements the Default variant of the 
    PLIB_USBHS_EP0INHandshakeClear function.
*/

PLIB_TEMPLATE void USBHS_EP0INHandshakeClear_Default( USBHS_MODULE_ID index )
{
    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    usbhs->EPCSR[0].CSR0L_HOSTbits.w &= (~(USBHS_EP0_HOST_STATUS_STAGE_START | USBHS_EP0_HOST_RXPKTRDY));
}

//******************************************************************************
/* Function :  USBHS_ExistsEP0Status_Default

  Summary:
    Implements Default variant of PLIB_USBHS_ExistsEP0Status

  Description:
    This template implements the Default variant of the PLIB_USBHS_ExistsEP0Status function.
*/

#define PLIB_USBHS_ExistsEP0Status PLIB_USBHS_ExistsEP0Status
PLIB_TEMPLATE bool USBHS_ExistsEP0Status_Default( USBHS_MODULE_ID index )
{
    return true;
}


#endif /*_USBHS_EP0STATUS_DEFAULT_H*/

/******************************************************************************
 End of File
*/

