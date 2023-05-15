/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app_secure_security.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the secure interface of the application.
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

#ifndef _APP_SECURE_SECURITY_H    /* Guard against multiple inclusion */
#define _APP_SECURE_SECURITY_H

#include "atca_iface.h"
#include "atca_status.h"


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */


/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


    /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: Constants                                                         */
    /* ************************************************************************** */
    /* ************************************************************************** */

    /*  A brief description of a section can be given directly below the section
        banner.
     */


    /* ************************************************************************** */
    /** Descriptive Constant Name

      @Summary
        Brief one-line summary of the constant.
    
      @Description
        Full description, explaining the purpose and usage of the constant.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
      @Remarks
        Any additional remarks
     */
#define EXAMPLE_CONSTANT 0

typedef enum
{
    SE_VALIDATE_FAILED=0,
    SE_ONLY_VALIDATE,
    SE_SET_NEW_PASSKEY
}SE_PASSKEY_STATUS;

#if defined(__XC32__)
extern ATCAIfaceCfg atecc608_0_init_data;
#endif

ATCAIfaceCfg *cfg ;
ATCA_STATUS status;

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/*******************************************************************************
  Function:
   ATCADeviceType APP_SECURITY_GetDeviceType(uint8_t revision_byte)

  Summary:  
     Used to get Cryptoauthlib library device type
  Returns:
    Cryptoauthlib library device type
 */
   ATCADeviceType APP_SECURITY_GetDeviceType(uint8_t revision_byte);
   
   /*******************************************************************************
  Function:
   ATCA_STATUS APP_SECURITY_CheckDeviceType(ATCAIfaceCfg* cfg, bool overwrite)

  Summary:  
    Used to check Cryptoauthlib library device type
  Returns:
    ATCA lib status
 */
   ATCA_STATUS APP_SECURITY_CheckDeviceType(ATCAIfaceCfg* cfg, bool overwrite);
   
 /*******************************************************************************
  Function:
   SE_PASSKEY_STATUS APP_SECURITY_ValidatePasskey(void)

  Summary:  
  Validate passkey entered by user
  Returns:
    Validation status
 */
   SE_PASSKEY_STATUS APP_SECURITY_ValidatePasskey(void);
   
   /*******************************************************************************
  Function:
   bool APP_SECURITY_SetNewPasskey (void)

  Summary:  
    Updates the default passkey
  Returns:
    Status of passkey updation
 */
   bool APP_SECURITY_SetNewPasskey(void);
   
   /*******************************************************************************
  Function:
   bool APP_SECURITY_SaveTempPasskey(void)

  Summary:  
    Save temporary passkey generated from Mobile phone
  Returns:
    Status of passkey store.
 */
   bool APP_SECURITY_SaveTempPasskey(void);
   
   /*******************************************************************************
  Function:
   void APP_SECURITY_Wait(void)

  Summary:  
    Waits for next command
  Returns:
    None.
 */
   void APP_SECURITY_Wait(void);
   
   /*******************************************************************************
  Function:
   bool APP_SECURITY_GetTempkeyStatus(void)

  Summary:  
    Retrieve temporary passkey status
  Returns:
    True if tempkey is active
 */
   bool APP_SECURITY_GetTempkeyStatus(void);
   
   /*******************************************************************************
  Function:
   void APP_SECURITY_SetTempkeyStatus(bool status)

  Summary:  
    Set the temp key status. Set to true when temp passkey is active. Set to false after usage or inactivity timeout
  Returns:
    None.
 */
   void APP_SECURITY_SetTempkeyStatus(bool status);
   
   /*******************************************************************************
  Function:
   void APP_SECURITY_SetPasskeySlot(uint8_t slot)

  Summary:  
    Set the passkey slot
  Returns:
    None.
 */
   void APP_SECURITY_SetPasskeySlot(uint8_t slot);
   
   /*******************************************************************************
  Function:
   bool APP_SECURITY_GetPasskeyValidationStatus(void)

  Summary:  
    Validation status of entered passkey
  Returns:
   True if passkey is valid
 */
   bool APP_SECURITY_GetPasskeyValidationStatus(void);
   
   /*******************************************************************************
  Function:
   void APP_SECURITY_SetPasskeyValidationStatus(bool status)

  Summary:  
    Set the passkey validation status
  Returns:
    None.
 */
   void APP_SECURITY_SetPasskeyValidationStatus(bool status);
   
   /*******************************************************************************
  Function:
   void APP_SECURITY_SetNewPasskeyStatus(bool status)

  Summary:  
    Set new passkey status. True if new passkey is stored
  Returns:
    None.
 */
   void APP_SECURITY_SetNewPasskeyStatus(bool status);
   
   /*******************************************************************************
  Function:
   bool APP_SECURITY_GetNewPasskeyStatus(void)
    
  Summary:  
       Get new passkey status. 
  Returns:
    True if new passkey is stored
 */
   bool APP_SECURITY_GetNewPasskeyStatus(void);
   
   /*******************************************************************************
  Function:
   void APP_SECURITY_SetPasskeyData(uint8_t*)

  Summary:  
    Set new passkey value
  Returns:
    None.
 */
   void APP_SECURITY_SetPasskeyData(uint8_t*);
   
   /*******************************************************************************
  Function:
    void APP_SECURITY_DefaultPasskeyStore(void)

  Summary:  
    Store default passkey provided from mobile
  Returns:
    None.
 */
   void APP_SECURITY_DefaultPasskeyStore(void);
   
   /*******************************************************************************
  Function:
   void APP_SECURITY_SetDefaultKeyStore(bool state)

  Summary:  
    Set the status of default key storage. True if default key is stored
  Returns:
    None.
 */
   void APP_SECURITY_SetDefaultKeyStore(bool state);

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _APP_SECURE_SECURITY_H */

/* *****************************************************************************
 End of File
 */
