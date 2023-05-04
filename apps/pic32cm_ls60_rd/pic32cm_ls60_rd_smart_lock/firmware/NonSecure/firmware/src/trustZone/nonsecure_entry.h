/*******************************************************************************
 Non-secure entry header File for non-secure project

  Company:
    Microchip Technology Inc.

  File Name:
    nonsecure_entry.h

  Summary:
    Function prototype declarations for Non-secure callable functions

  Description:
    This file is used to declare non-secure callable functions in non-secure project.

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

#ifndef NONSECURE_ENTRY_H_
#define NONSECURE_ENTRY_H_

/* Non-secure callable functions */
//extern int secure_add(int x, int y);


/*Simple MAP NSC functions*/
#define simpleMAP_CB_TYPE_CONNECTED		0x00
#define simpleMAP_CB_TYPE_DISCONNECTED	0xFF
#define simpleMAP_CB_TYPE_MESSAGE		0x01
#define simpleMAP_CB_TYPE_TX_BUF_READY	0x02
#define simpleMAP_CB_TYPE_TX_ACK_RCV	0x03
#define simpleMAP_CB_TYPE_LOGFROMSECURE	0x04
#define simpleMAP_CB_TYPE_ERROR	        0x05
#define simpleMAP_CB_TYPE_MESSAGE_HMAC  0x06

#define simpleMAP_SETTINGS_DEFAULT		0x00
#define simpleMAP_SETTINGS_DEBUG		0x80

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

typedef void (*SERCOM_USART_CALLBACK)( uintptr_t context );

typedef uint16_t USART_ERROR;

typedef void (*funcptr_ns) (uint8_t callbacktype) __attribute__((cmse_nonsecure_call));


// *****************************************************************************
// *****************************************************************************
// Section: Structures
// *****************************************************************************
// *****************************************************************************

struct simpleMAP_message{
	uint16_t messagesize;
	uint8_t	 data[1056];
};

// *****************************************************************************
// *****************************************************************************
// Section: External Functions
// *****************************************************************************
// *****************************************************************************

extern void APP_NONSECURE_ENTRY_simpleMAP_Initialize(uint8_t settings, struct simpleMAP_message * receive_message_buffer, funcptr_ns cb);
extern bool APP_NONSECURE_ENTRY_simpleMAP_MessageSend(struct simpleMAP_message * send_message_buffer);
extern void APP_NONSECURE_ENTRY_simpleMAP_KeyRotation( void );
extern bool APP_NONSECURE_ENTRY_simpleMAP_CheckTrust( void );
    


/*ECC Non-Secure Entry functions*/

extern bool APP_NONSECURE_ENTRY_CheckDeviceType(void);
extern bool APP_NONSECURE_ENTRY_atcabInit(void);
extern APP_NONSECURE_PASSKEY_STATUS APP_NONSECURE_ENTRY_ValidatePasskey(void);
extern bool APP_NONSECURE_ENTRY_SetNewPasskey(void);
extern bool APP_NONSECURE_ENTRY_SaveTempPasskey(void);
extern void APP_NONSECURE_ENTRY_SecurityWait(void);
extern void APP_NONSECURE_ENTRY_DigestCompute(void);
extern bool APP_NONSECURE_ENTRY_DigestValidation();

/*Touch Non-Secure Entry functions*/

extern void secure_touch_status_display1(void);
extern uint8_t APP_NONSECURE_ENTRY_GetMeasurementDoneTouch(void);
extern void APP_NONSECURE_ENTRY_SetMeasurementDoneTouch(uint8_t val);
extern bool APP_NONSECURE_ENTRY_GetLowPowerMeasurementStatus(void);
extern bool APP_NONSECURE_ENTRY_GetPasskeyValidationStatus(void);
extern void APP_NONSECURE_ENTRY_SetPasskeyValidationStatus(bool status);
extern bool APP_NONSECURE_ENTRY_GetNewPasskeyStatus(void);
extern void APP_NONSECURE_ENTRY_SetNewPasskeyStatus(bool status);
extern void APP_NONSECURE_ENTRY_SetTempkeyStatus(bool status);
extern void APP_NONSECURE_ENTRY_SetPasskeySlot(uint8_t slot);
extern bool APP_NONSECURE_ENTRY_GetTempkeyStatus(void);
extern void APP_NONSECURE_ENTRY_TouchProcess(void);
extern void APP_NONSECURE_ENTRY_TouchInit(void);
extern uint8_t APP_NONSECURE_ENTRY_GetSensorState(uint16_t sensor_node);
extern void APP_NONSECURE_ENTRY_RTC_TimerStop(void);
extern void APP_NONSECURE_ENTRY_RTC_TimerStart(void);        
extern void APP_NONSECURE_ENTRY_NVM_Erase(uint32_t nvm_data_flash_user_start_address);
extern void APP_NONSECURE_ENTRY_NVM_Write (uint32_t *data_flash, const uint32_t data_flash_address);
extern void APP_NONSECURE_ENTRY_NVM_Read (uint32_t *data_flash_read, uint32_t length, const uint32_t read_address);
extern bool APP_NONSECURE_ENTRY_NVM_Busy(void);
extern void APP_NONSECURE_ENTRY_SetDefaultKeyStore(bool state);


/* NVM Data-flash Non-Secure Entry functions*/
extern bool APP_NONSECURE_ENTRY_NVM_ReadDefaultKey(void);
extern bool APP_NONSECURE_ENTRY_DefaultPasskeyStore(void);
extern void APP_NONSECURE_ENTRY_SetPasskeyData(uint8_t* passkey_data);
extern void APP_NONSECURE_ENTRY_DelayMS(uint32_t milliseconds);

//extern bool secure_SERCOM5_USART_Read(void *buffer, const size_t size);

/* USART Non-Secure Entry functions*/

extern bool APP_NONSECURE_ENTRY_USART_Read(void);
extern bool APP_NONSECURE_ENTRY_USART_Write(void *buffer, const size_t size);
extern void APP_NONSECURE_ENTRY_USART_WriteCallbackRegister( SERCOM_USART_CALLBACK callback, uintptr_t context );
extern USART_ERROR APP_NONSECURE_ENTRY_USART_ErrorStatus( void );
extern void APP_NONSECURE_ENTRY_ReadCallbackRegister( SERCOM_USART_CALLBACK callback, uintptr_t context );
extern void APP_NONSECURE_ENTRY_USART_CallbacksRegister();
extern bool secure_get_error_Stat();
extern bool APP_NONSECURE_ENTRY_USART_GetWriteStatus();
extern bool APP_NONSECURE_ENTRY_USART_GetReadStatus();
extern void APP_NONSECURE_ENTRY_USART_SetReadStatus(bool);
extern void APP_NONSECURE_ENTRY_USART_SetWriteStatus(bool);

extern bool APP_NONSECURE_ENTRY_USART_WriteBusy();

/* Other Non-Secure Entry functions*/

extern void APP_NONSECURE_ENTRY_BLE_ModuleDisconnect(void);
extern uint8_t APP_NONSECURE_ENTRY_CommancCheck(void);

extern void APP_NONSECURE_ENTRY_UpdateDoorStatus(bool);
extern bool APP_NONSECURE_ENTRY_BLE_IsModuleConnected(void);
extern void APP_NONSECURE_ENTRY_StandbyEnter(void);
extern void APP_NONSECURE_ENTRY_SleepPrepare(void);

extern void APP_NONSECURE_ENTRY_EIC_Disable (void);

extern bool APP_NONSECURE_ENTRY_BLE_IsModuleConnected(void);

extern void APP_NONSECURE_ENTRY_simpleMAP_DebugOut(uint8_t *, uint16_t );

extern void secure_printf(float);

extern void APP_NONSECURE_ENTRY_UpdateBatteryStatus(float battery_voltage);
extern void secure_update_lock_status(bool locked);

#endif /* NONSECURE_ENTRY_H_ */
