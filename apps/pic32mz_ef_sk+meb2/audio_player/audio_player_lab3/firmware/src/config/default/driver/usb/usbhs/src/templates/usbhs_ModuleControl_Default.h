/*******************************************************************************
  USBHS Peripheral Library Template Implementation

  File Name:
    usbhs_ModuleControl_Default.h

  Summary:
    USBHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ModuleControl
    and its Variant : Default
    For following APIs :
        PLIB_USBHS_ResumeEnable
        PLIB_USBHS_ResumeDisable
        PLIB_USBHS_SuspendEnable
        PLIB_USBHS_SuspendDisable
        PLIB_USBHS_ResetEnable
        PLIB_USBHS_ResetDisable
        PLIB_USBHS_VBUSLevelGet
        PLIB_USBHS_HostModeIsEnabled
        PLIB_USBHS_IsBDevice
        PLIB_USBHS_SessionEnable
        PLIB_USBHS_SessionDisable
        PLIB_USBHS_DeviceAddressSet
        PLIB_USBHS_DeviceAttach
        PLIB_USBHS_DeviceDetach
        PLIB_USBHS_ExistsModuleControl

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

#ifndef _USBHS_MODULECONTROL_DEFAULT_H
#define _USBHS_MODULECONTROL_DEFAULT_H

#include "usbhs_registers.h"

//******************************************************************************
/* Function :  USBHS_ResumeEnable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_ResumeEnable 

  Description:
    This template implements the Default variant of the 
    PLIB_USBHS_ResumeEnable function.
*/

PLIB_TEMPLATE void USBHS_ResumeEnable_Default( USBHS_MODULE_ID index )
{
    /* Function enables resume signaling */
    
    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    usbhs->POWERbits.RESUME = 1;
}

//******************************************************************************
/* Function :  USBHS_ResumeDisable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_ResumeDisable 

  Description:
    This template implements the Default variant of the 
    PLIB_USBHS_ResumeDisable function.
*/

PLIB_TEMPLATE void USBHS_ResumeDisable_Default( USBHS_MODULE_ID index )
{
    /* Function disables resume signaling */
    
    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    usbhs->POWERbits.RESUME = 0;
}

//******************************************************************************
/* Function :  USBHS_SuspendEnable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_SuspendEnable 

  Description:
    This template implements the Default variant of the 
    PLIB_USBHS_SuspendEnable function.
*/

PLIB_TEMPLATE void USBHS_SuspendEnable_Default( USBHS_MODULE_ID index )
{
    /* Function enables bus suspend  */
    
    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    usbhs->POWERbits.SUSPMODE = 1;
}

//******************************************************************************
/* Function :  USBHS_SuspendDisable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_SuspendDisable 

  Description:
    This template implements the Default variant of the 
    PLIB_USBHS_SuspendDisable function.
*/

PLIB_TEMPLATE void USBHS_SuspendDisable_Default( USBHS_MODULE_ID index )
{
    /* Function disables bus suspend  */
    
    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    usbhs->POWERbits.SUSPMODE = 0;
}

//******************************************************************************
/* Function :  USBHS_VBUSLevelGet_Default

  Summary:
    Implements Default variant of PLIB_USBHS_VBUSLevelGet 

  Description:
    This template implements the Default variant of the 
    PLIB_USBHS_VBUSLevelGet function.
*/

PLIB_TEMPLATE USBHS_VBUS_LEVEL USBHS_VBUSLevelGet_Default( USBHS_MODULE_ID index )
{
    /* Function returns the current VBUS level */
    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    return((USBHS_VBUS_LEVEL)((usbhs->DEVCTLbits.w) & 0x18));
}

//******************************************************************************
/* Function :  USBHS_HostModeIsEnabled_Default

  Summary:
    Implements Default variant of PLIB_USBHS_HostModeIsEnabled 

  Description:
    This template implements the Default variant of the 
    PLIB_USBHS_HostModeIsEnabled function.
*/

PLIB_TEMPLATE bool USBHS_HostModeIsEnabled_Default( USBHS_MODULE_ID index )
{
    /* Returns true if the Host Mode is enabled. */
    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    return((bool)(usbhs->DEVCTLbits.HOSTMODE));
}

//******************************************************************************
/* Function :  USBHS_SessionEnable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_SessionEnable 

  Description:
    This template implements the Default variant of the 
    PLIB_USBHS_SessionEnable function.
*/

PLIB_TEMPLATE void USBHS_SessionEnable_Default( USBHS_MODULE_ID index )
{
    /* Function enables a session  */
    
    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    usbhs->DEVCTLbits.SESSION = 1;
}


//******************************************************************************
/* Function :  USBHS_IsBDevice_Default

  Summary:
    Implements Default variant of PLIB_USBHS_IsBDevice 

  Description:
    This template implements the Default variant of the 
    PLIB_USBHS_IsBDevice function.
*/

PLIB_TEMPLATE bool USBHS_IsBDevice_Default( USBHS_MODULE_ID index )
{
    /* Returns true if the Host Mode is enabled. */
    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    return((bool)(usbhs->DEVCTLbits.BDEV));
}

//******************************************************************************
/* Function :  USBHS_SessionDisable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_SessionDisable 

  Description:
    This template implements the Default variant of the 
    PLIB_USBHS_SessionDisable function.
*/

PLIB_TEMPLATE void USBHS_SessionDisable_Default( USBHS_MODULE_ID index )
{
    /* Clears the session bit */
    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    usbhs->DEVCTLbits.SESSION = 0;
}

//******************************************************************************
/* Function :  USBHS_ResetEnable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_ResetEnable 

  Description:
    This template implements the Default variant of the PLIB_USBHS_ResetEnable function.
*/

PLIB_TEMPLATE void USBHS_ResetEnable_Default( USBHS_MODULE_ID index )
{
    /* Sets the reset bit */
    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    usbhs->POWERbits.RESET = 1;
}

//******************************************************************************
/* Function :  USBHS_ResetDisable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_ResetDisable 

  Description:
    This template implements the Default variant of the 
    PLIB_USBHS_ResetDisable function.
*/

PLIB_TEMPLATE void USBHS_ResetDisable_Default( USBHS_MODULE_ID index )
{
   /* Sets the reset bit */
    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    usbhs->POWERbits.RESET = 0;
}

//******************************************************************************
/* Function :  USBHS_DeviceAddressSet_Default

  Summary:
    Implements Default variant of PLIB_USBHS_DeviceAddressSet 

  Description:
    This template implements the Default variant of the PLIB_USBHS_DeviceAddressSet function.
*/

PLIB_TEMPLATE void USBHS_DeviceAddressSet_Default
( 
    USBHS_MODULE_ID index, 
    uint8_t address 
)
{
    /* Clears the reset bit */
    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    usbhs->FADDRbits.FUNC = address ;
}

//******************************************************************************
/* Function :  USBHS_DeviceAttach_Default

  Summary:
    Implements Default variant of PLIB_USBHS_DeviceAttach 

  Description:
    This template implements the Default variant of the 
    PLIB_USBHS_DeviceAttach function.
*/

PLIB_TEMPLATE void USBHS_DeviceAttach_Default( USBHS_MODULE_ID index, uint32_t speed )
{
    /* Attach the device at the specified speed */
    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);

    /* Full speed value is 0x2 and high speed value is 0x1.
     * So if high speed is specified, then HSEN will be 1
     * and if full speed is specified, the HSEN will be 0 */
    
    usbhs->POWERbits.HSEN = (speed & 0x1);
    usbhs->POWERbits.SOFTCONN = 1;
}

//******************************************************************************
/* Function :  USBHS_DeviceDetach_Default

  Summary:
    Implements Default variant of PLIB_USBHS_DeviceDetach 

  Description:
    This template implements the Default variant of the PLIB_USBHS_DeviceDetach function.
*/

PLIB_TEMPLATE void USBHS_DeviceDetach_Default( USBHS_MODULE_ID index)
{
   /* Detach the device. */
    
    volatile usbhs_registers_t * usbhs = (usbhs_registers_t *)(index);
    usbhs->POWERbits.SOFTCONN = 0;
}

//******************************************************************************
/* Function :  USBHS_ExistsModuleControl_Default

  Summary:
    Implements Default variant of PLIB_USBHS_ExistsModuleControl

  Description:
    This template implements the Default variant of the PLIB_USBHS_ExistsModuleControl function.
*/

#define PLIB_USBHS_ExistsModuleControl PLIB_USBHS_ExistsModuleControl
PLIB_TEMPLATE bool USBHS_ExistsModuleControl_Default( USBHS_MODULE_ID index )
{
    return true;
}


#endif /*_USBHS_MODULECONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

