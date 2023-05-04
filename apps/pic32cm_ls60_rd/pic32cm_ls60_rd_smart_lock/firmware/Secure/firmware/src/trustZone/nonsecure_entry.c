/*******************************************************************************
 Non-secure entry source file for secure project

  Company:
    Microchip Technology Inc.

  File Name:
    nonsecure_entry.c

  Summary:
    Implements hooks for Non-secure application

  Description:
    This file is used to call specific API's in the secure world from the Non-Secure world.

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

/* Non-secure callable (entry) function */
/*int __attribute__((cmse_nonsecure_entry)) secure_add(int x, int y)
{
    return (x + y);
}*/

#include <stdint.h>
#include "config/default/definitions.h"
#include "../src/simpleMAP/simpleMAP_library.h"
#include "unsecure_interface.h"
#include "app_secure_security.h"
#include "cryptoauthlib.h"
#include "../src/simpleMAP/simpleMAP_HAL.h"
#include "app_secure_ble_manager.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern bool PREVIOUS_TIMER_HANDLER_PROCESSING;

extern uint8_t nonce[];

uint8_t sha_digest_compute[32]={0};
char sha_digest_compute_string[96];

static int index1=0;
extern uint8_t *passkey;

extern uint8_t sha_digest[32];

ATCAIface iface_1;
extern ATCADevice _gDevice;
ATCAIfaceCfg *cfg2;

bool errorStat=false;
volatile bool writeStat=false;
volatile bool readStat =false;
char  data_received_1[200] = {};
const char digest_string_1[6]= "digest";
char *digest_ptr_1;
char digest_data_1[200];
uint8_t i=0;

extern ATCAIfaceCfg atecc608_0_init_data_smap;

uint8_t battery_status[32];
uint8_t lock_status[2] ={0x77, 0x00};
uint8_t dig_bytecount=0;

void APP_WriteCallback(uintptr_t context)
{
    if(SERCOM5_USART_ErrorGet() != USART_ERROR_NONE)
    {
        /* ErrorGet clears errors, set error flag to notify console */
        errorStat = true;
    }
    else
    {
        writeStat = true;
        
    }
}

void APP_ReadCallback(uintptr_t context)
{
    if(SERCOM5_USART_ErrorGet() != USART_ERROR_NONE)
    {
        /* ErrorGet clears errors, set error flag to notify console */
        errorStat = true;
    }
    else
    {
        readStat = true;
        
    }
}
/* simple MAP NSC */
typedef void (*funcptr_ns) (uint8_t callbacktype) __attribute__((cmse_nonsecure_call));
#define cmse_nsfptr_create(p) ((intptr_t) (p) & ~1)

extern uint8_t key_check[32];
extern const uint8_t io_protection_key[32];
extern const uint8_t nvm_data_flash_user_start_address[(DATAFLASH_PAGE_SIZE * 4)] __attribute__((address(DATAFLASH_ADDR)));


// *****************************************************************************
// *****************************************************************************
// Section: Security Application Functions called from Non-secure region
// *****************************************************************************
// *****************************************************************************

bool __attribute__((cmse_nonsecure_entry))APP_NONSECURE_ENTRY_CheckDeviceType(void)
{
    cfg = &atecc608_0_init_data;
    if (ATCA_SUCCESS != (status = APP_SECURITY_CheckDeviceType(cfg, false)))
    {
        printf("ATCAB init fail");
        return 0;
    }
        
    else
    {
        printf("ATCAB init success");
        return true;
    }
        
}
bool __attribute__((cmse_nonsecure_entry))APP_NONSECURE_ENTRY_atcabInit(void)
{
    if (ATCA_SUCCESS != (status = atcab_init(cfg)))
    {
        return 0;
    }
    return true;   
}

SE_PASSKEY_STATUS __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_ValidatePasskey(void)
{
    return APP_SECURITY_ValidatePasskey();
}
bool __attribute__((cmse_nonsecure_entry))APP_NONSECURE_ENTRY_SetNewPasskey(void)
{
    return APP_SECURITY_SetNewPasskey();
}

void __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_SetPasskeyData(uint8_t* passkey_data)
{
   APP_SECURITY_SetPasskeyData(passkey_data);
}

void __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_SetDefaultKeyStore(bool store_default_key)
{
    APP_SECURITY_SetDefaultKeyStore (store_default_key);
}

bool __attribute__((cmse_nonsecure_entry))APP_NONSECURE_ENTRY_SaveTempPasskey(void)
{
    return APP_SECURITY_SaveTempPasskey();
}

void __attribute__((cmse_nonsecure_entry))APP_NONSECURE_ENTRY_SecurityWait(void)
{
     APP_SECURITY_Wait();
}

bool __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_GetTempkeyStatus(void)
{
   return APP_SECURITY_GetTempkeyStatus();
}

void __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_SetTempkeyStatus(bool status)
{
    APP_SECURITY_SetTempkeyStatus(status);
}

void __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_SetPasskeySlot(uint8_t slot)
{
    APP_SECURITY_SetPasskeySlot(slot);
}

void __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_SetNewPasskeyStatus(bool status)
{
    APP_SECURITY_SetNewPasskeyStatus(status);
}

bool __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_GetNewPasskeyStatus(void)
{
    return APP_SECURITY_GetNewPasskeyStatus();
}


void __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_SetPasskeyValidationStatus(bool status)
{
    APP_SECURITY_SetPasskeyValidationStatus(status);
}

bool __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_GetLowPowerMeasurementStatus(void)
{
    return APP_SECURE_GetLowPowerMeasurementStatus();
}

bool __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_GetPasskeyValidationStatus(void)
{
    return APP_SECURITY_GetPasskeyValidationStatus();
}

bool __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_DefaultPasskeyStore(void)
{
    /*Store default passkey to respective user slots*/
    APP_SECURITY_DefaultPasskeyStore();
    /* Passkey Store Done */
    return 1;
 }

// *****************************************************************************
// *****************************************************************************
// Section: SimpleMAP Application Functions called from Non-secure region
// *****************************************************************************
// *****************************************************************************

void __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_simpleMAP_Initialize(uint8_t settings, struct simpleMAP_message * receive_message_buffer, funcptr_ns cb)
{
	funcptr_ns callback_NS;
	callback_NS =  (funcptr_ns) cmse_nsfptr_create(cb);
	simpleMAP_Register_Callback(settings, receive_message_buffer, callback_NS);
}


void __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_simpleMAP_KeyRotation( void ){
    simpleMAP_KeyRotation();
}

bool __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_simpleMAP_CheckTrust( void ){
    return simpleMAP_TrustChainCheck(NULL);
}

bool __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_simpleMAP_MessageSend(struct simpleMAP_message * send_message_buffer)
{
    bool addhmac = false;
    bool requestack = false;
    uint16_t len;
    
    if((send_message_buffer->messagesize & 0x8000)>0) addhmac = true;
    if((send_message_buffer->messagesize & 0x2000)>0) requestack = true;
    len = send_message_buffer->messagesize & 0xFFF;
	return simpleMAP_SendMessage(send_message_buffer->data,len,addhmac,requestack);
}



// *****************************************************************************
// *****************************************************************************
// Section: Delay Functions called from Non-secure region
// *****************************************************************************
// *****************************************************************************

void __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_DelayMS(uint32_t ms)
{
    APP_SECURE_DelayCycles((void*)0,ms * 106000 / 10);
}


// *****************************************************************************
// *****************************************************************************
// Section: Touch Application Functions called from Non-secure region
// *****************************************************************************
// *****************************************************************************

void __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_TouchInit(void) {
       touch_init();
}
void __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_TouchProcess(void){
        touch_process();
}

uint8_t __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_GetSensorState(uint16_t sensor_node)
{
    return get_sensor_state(sensor_node);
}

uint8_t __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_GetMeasurementDoneTouch(void){    
    return APP_SECURE_GetMeasurementDoneTouch();
}


void __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_SetMeasurementDoneTouch(uint8_t setVal){
    APP_SECURE_SetMeasurementDoneTouch(setVal);
  
}


// *****************************************************************************
// *****************************************************************************
// Section: RTC Functions called from Non-secure region
// *****************************************************************************
// *****************************************************************************
void __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_RTC_TimerStop(){
    RTC_Timer32Stop();
}


void __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_RTC_TimerStart(){
    RTC_Timer32Start();
}


// *****************************************************************************
// *****************************************************************************
// Section: NVM Functions called from Non-secure region
// *****************************************************************************
// *****************************************************************************

void __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_NVM_Erase (uint32_t nvm_data_flash_user_start_address)
{
   NVMCTRL_RowErase(nvm_data_flash_user_start_address);
}

void __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_NVM_Write (uint32_t *data_flash, const uint32_t data_flash_address)
{
  NVMCTRL_PageWrite(data_flash, data_flash_address);
}

void __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_NVM_Read (uint32_t *data_flash_read, uint32_t length, const uint32_t read_address)
{
   NVMCTRL_Read (data_flash_read, length, read_address);
}

bool __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_NVM_Busy(void)
{
      return (NVMCTRL_IsBusy());
}

bool __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_NVM_ReadDefaultKey(void)
{
     NVMCTRL_Read ((uint32_t *)key_check, sizeof(key_check),(uint32_t)(nvm_data_flash_user_start_address));
     while(NVMCTRL_IsBusy());
     if (memcmp(key_check,io_protection_key,32) == 0) // Check if passkey and io_protection already stored to DataFlash
     {
         return 1;
     }
     else
         return 0;
}



void __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_EIC_Disable(void)
{
    /*Disable External Interrupt until next sleep*/
     EIC_SEC_REGS->EIC_INTENCLR = 0x40;
}


// *****************************************************************************
// *****************************************************************************
// Section: BLE Application Functions called from Non-secure region
// *****************************************************************************
// *****************************************************************************

bool __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_BLE_IsModuleConnected(void)
{
    return APP_SECURE_BLE_MANAGER_ModuleConnected();
}

void __attribute__((cmse_nonsecure_entry)) APP_NONSECURE_ENTRY_BLE_ModuleDisconnect(void)
{
    APP_SECURE_BLE_MANAGER_BleModuleDisconnect();
}


void __attribute__((cmse_nonsecure_entry))APP_NONSECURE_ENTRY_simpleMAP_DebugOut(uint8_t * buffer, uint16_t len )
{
    simpleMAP_debug_out(buffer,len);
}

void __attribute__((cmse_nonsecure_entry, aligned (32))) APP_NONSECURE_ENTRY_StandbyEnter(void)
{
    /*Enable External Interrupt on BM70 Status Ind pin*/
    EIC_SEC_REGS->EIC_INTENSET = 0x40;
     
    PM_StandbyModeEnter();   
    
    APP_SECURE_StandbyModeExit();
}

void __attribute__((cmse_nonsecure_entry, aligned (32))) APP_NONSECURE_ENTRY_UpdateBatteryStatus(float battery_voltage)
{
    battery_status[0] = 0xBD;
            if (battery_voltage >= 1.03 )
            {
              //Battery is full
                battery_status[1] = BATTERY_FULL;
            }
            else if (battery_voltage >= 0.85 )
            {
                //Battery is 50%
                battery_status[1] = BATTERY_50;
            }
            else if (battery_voltage >= 0.75)
            {
                //Battery low
                battery_status[1] = BATTERY_LOW;
            }
            else
            {
                //Battery status unknown
                battery_status[1] = BATTERY_UNKNOWN;
            }
         simpleMAP_APPLICATION_SEND_MESSAGE(&battery_status[0],2,false,false);
}

void __attribute__((cmse_nonsecure_entry, aligned (32))) APP_NONSECURE_ENTRY_UpdateDoorStatus(bool locked)
{
    if(locked)
    {
        lock_status[0] = 0x77;
        lock_status[1] = 0xFF; // Door is closed
        simpleMAP_APPLICATION_SEND_MESSAGE(&lock_status[0],2,false,false);
    }
    else
    {
        lock_status[0] = 0x77;
        lock_status[1] = 0xAA; // Door is open
        simpleMAP_APPLICATION_SEND_MESSAGE(&lock_status[0],2,false,false);
    }
}

void __attribute__((cmse_nonsecure_entry, aligned (32))) APP_NONSECURE_ENTRY_SleepPrepare (void)
{
    /*Graceful BLE disconnect*/
    APP_SECURE_BLE_MANAGER_BleDisconnect();
    
    /*Stop Timers*/   
    while(PREVIOUS_TIMER_HANDLER_PROCESSING == true){};
    TC0_TimerStop();
    RTC_Timer32Stop();
    
    /*Put ECC608 to Sleep*/
    atcab_wakeup();   
    atcab_sleep();

    /*Disable all USARTs */
    /*Disable SERCOM2*/
    SERCOM2_REGS->USART_INT.SERCOM_CTRLA &= ~(SERCOM_USART_INT_CTRLA_ENABLE_Msk);  
    /*Disable SERCOM0*/
    SERCOM0_REGS->USART_INT.SERCOM_CTRLA &= ~(SERCOM_USART_INT_CTRLA_ENABLE_Msk);
    
    /*Enable EIC on BM70 Status Ind pin*/
    PORT_SEC_REGS->GROUP[1].PORT_PINCFG[22] = 0x7;
    EIC_SEC_REGS->EIC_INTENSET = 0x40;    
}


bool __attribute__((cmse_nonsecure_entry))APP_NONSECURE_ENTRY_USART_Read(void)
{
    return SERCOM5_USART_Read(data_received_1,sizeof(data_received_1));
}


bool __attribute__((cmse_nonsecure_entry))APP_NONSECURE_ENTRY_USART_Write(void *buffer, const size_t size)
{
    if ((buffer != NULL)) {
        return SERCOM5_USART_Write(buffer,size);
    }
    
    else{
        return SERCOM5_USART_Write(sha_digest,sizeof(sha_digest));
    }
}


void __attribute__((cmse_nonsecure_entry))APP_NONSECURE_ENTRY_USART_WriteCallbackRegister( SERCOM_USART_CALLBACK callback, uintptr_t context )
{
    SERCOM5_USART_WriteCallbackRegister(callback,context);
}

USART_ERROR __attribute__((cmse_nonsecure_entry))APP_NONSECURE_ENTRY_USART_ErrorStatus( void )
{
    return SERCOM5_USART_ErrorGet();
}

void __attribute__((cmse_nonsecure_entry))APP_NONSECURE_ENTRY_ReadCallbackRegister( SERCOM_USART_CALLBACK callback, uintptr_t context )
{
    SERCOM5_USART_ReadCallbackRegister(callback,context);
}

void __attribute__((cmse_nonsecure_entry))APP_NONSECURE_ENTRY_USART_CallbacksRegister()
{
    SERCOM5_USART_WriteCallbackRegister(APP_WriteCallback, 0);
    SERCOM5_USART_ReadCallbackRegister(APP_ReadCallback, 0);
}

bool __attribute__((cmse_nonsecure_entry))APP_NONSECURE_ENTRY_USART_GetReadStatus()
{
    return readStat;
}

bool __attribute__((cmse_nonsecure_entry))APP_NONSECURE_ENTRY_USART_GetWriteStatus()
{
    return writeStat;
}


void __attribute__((cmse_nonsecure_entry))APP_NONSECURE_ENTRY_USART_SetReadStatus(bool status)
{
     readStat= status;
}


void __attribute__((cmse_nonsecure_entry))APP_NONSECURE_ENTRY_USART_SetWriteStatus(bool status)
{
     writeStat= status;
}

bool __attribute__((cmse_nonsecure_entry))APP_NONSECURE_ENTRY_USART_WriteBusy()
{
    return SERCOM5_USART_WriteIsBusy();
}

uint8_t __attribute__((cmse_nonsecure_entry))APP_NONSECURE_ENTRY_CommancCheck()
{
    dig_bytecount=0;
    if((strncmp(&data_received_1[0],"Open",4))==0)
            {
                digest_ptr_1= strstr(data_received_1,digest_string_1);
                memcpy(digest_data_1,digest_ptr_1+11,200);
                for(i=0;i<200;i++)
                {
                    if(digest_data_1[i]!='*'){
                    dig_bytecount++;
                    }
                    else
                        break;
                }
                memset(&data_received_1[0],0x00,200);                
               return 1; 
            }
    else if((strncmp(&data_received_1[0],"Clos",4))==0)
            {
                return 2;                
            }
            else 
            {
                memset(&data_received_1[0],0x00,200);
                return 0;
            }
}

void __attribute__((cmse_nonsecure_entry))APP_NONSECURE_ENTRY_DigestCompute(void)
{
    atcac_sw_sha2_256(passkey, 32, sha_digest_compute);
    
    index1 = 0;
    
    for (i =0;i<32; i++)
    index1 +=sprintf(&sha_digest_compute_string[index1],"%d",sha_digest_compute[i]);
    
    
}

bool __attribute__((cmse_nonsecure_entry))APP_NONSECURE_ENTRY_DigestValidation()
{
    if(strncmp(&sha_digest_compute_string[0],&digest_data_1[0],dig_bytecount-1)==0){
        printf("\r\n Digest Match\r\n");
        dig_bytecount=0;
     return 1;}
    else
    {
         printf("\r\n Digest No Match\r\n");
        return 0;
    }
         
}

