/* ************************************************************************** */
/** BLE CHANNEL MANAGER FOR BM70 MODULE

  @Company
    MICROCHIP TECHNOLOGY INC

  @File Name
    ble_manager.c

  @Summary
    Manages BM70 Connections.

  @Description
    Implements specific BM70 managing functions.
 */
/* ************************************************************************** */

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

#ifndef _BLE_MANAGER_H    /* Guard against multiple inclusion */
#define _BLE_MANAGER_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */


#ifdef __cplusplus
extern "C" {
#endif
    
// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
   void APP_SECURE_BLE_MANAGER_Task( void )

  Summary:  
 Manages the BLE state machine
  Returns:
    None.
 */
void APP_SECURE_BLE_MANAGER_Task( void );


/*******************************************************************************
  Function:
   void APP_SECURE_BLE_MANAGER_ModuleReset( void )

  Summary:  
`` Reset BLE module
  Returns:
    None.
 */
void APP_SECURE_BLE_MANAGER_ModuleReset( void );

/*******************************************************************************
  Function:
   void APP_SECURE_BLE_MANAGER_IsPeerValid( void )

  Summary:  
    Used to check validity of connected peer
  Returns:
    None.
 */
void APP_SECURE_BLE_MANAGER_IsPeerValid( bool valid );

/*******************************************************************************
  Function:
   void APP_SECURE_BLE_MANAGER_ModuleConnected( void )

  Summary:  
    Checks the status of BLE connection
  Returns:
     BLE connection status
 */
bool APP_SECURE_BLE_MANAGER_ModuleConnected( void );

/*******************************************************************************
  Function:
   void APP_SECURE_BLE_MANAGER_BleDisconnect( void )

  Summary:  
     Clears BLE connection and prepares state machine for disconnect
  Returns:
    None.
 */
void APP_SECURE_BLE_MANAGER_BleDisconnect(void);

/*******************************************************************************
  Function:
   void APP_SECURE_BLE_MANAGER_BleModuleDisconnect( void )

  Summary:  
     Forcefully disconnect the connected BLE device
  Returns:
    None.
 */
void APP_SECURE_BLE_MANAGER_BleModuleDisconnect( void );
    
#ifdef __cplusplus
}
#endif

#endif /* _BLE_MANAGER_H */

/* *****************************************************************************
 End of File
 */
