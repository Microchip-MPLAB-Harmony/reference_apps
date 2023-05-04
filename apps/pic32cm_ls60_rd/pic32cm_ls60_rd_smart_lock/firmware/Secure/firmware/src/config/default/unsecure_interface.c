/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
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

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include <arm_cmse.h>
#include "config/default/definitions.h"
#include "unsecure_interface.h"
#include "../src/simpleMAP/simpleMAP_library.h"
#include "cryptoauthlib.h"

secure_callback SIMPLEMAP_USERAPPLICATION_CALLBACK;

/** 
  @Function
    void simpleMAP_Transfer_Application_Callback(uint8_t callbacktype) 

  @Remarks
    Refer to the unsecure_interface.h header for function usage details.
 */
void simpleMAP_Transfer_Application_Callback(uint8_t callbacktype){
    SIMPLEMAP_USERAPPLICATION_CALLBACK(callbacktype);
}


/** 
  @Function
    void simpleMAP_Register_Callback(uint8_t , struct simpleMAP_message * , secure_callback ) 

  @Remarks
    Refer to the unsecure_interface.h header for function usage details.
 */
void simpleMAP_Register_Callback(uint8_t settings, struct simpleMAP_message * receive_message_buffer, secure_callback cb)
{
	uint32_t add = (uint32_t)receive_message_buffer;
    if(add <0x00040000 || (add>0x20000000 && add<0x20002000)) return ;
    cb = cmse_check_address_range(cb,4,CMSE_NONSECURE);
    if(cb==NULL) return;
    SIMPLEMAP_USERAPPLICATION_CALLBACK = cb;
    simpleMAP_APPLICATION_CALLBACK = simpleMAP_Transfer_Application_Callback;
	simpleMAP_APPLICATION_CALLBACK_MESSAGE = receive_message_buffer;
    simpleMAP_APPLICATION_SETTINGS = settings;
}

/** 
  @Function
    bool simpleMAP_SendMessage(uint8_t * send_message_buffer, uint16_t bufferlength, bool addhmac, bool requestack) 

  @Remarks
    Refer to the unsecure_interface.h header for function usage details.
 */
bool simpleMAP_SendMessage(uint8_t * send_message_buffer, uint16_t bufferlength, bool addhmac, bool requestack)
{
    return simpleMAP_APPLICATION_SEND_MESSAGE(send_message_buffer, bufferlength, addhmac, requestack);
}

/** 
  @Function
    void simpleMAP_KeyRotation( void ) 

  @Remarks
    Refer to the unsecure_interface.h header for function usage details.
 */
void simpleMAP_KeyRotation( void ){
    simpleMAP_start_key_rotation();
}

/** 
  @Function
    void APP_SECURE_StandbyModeExit(void)

  @Remarks
    Refer to the unsecure_interface.h header for function usage details.
 */
void APP_SECURE_StandbyModeExit(void)
{ 
    /*BM70 Status Ind pin -> From EIC to Input pin*/
    PORT_SEC_REGS->GROUP[1].PORT_PINCFG[22] = 0x6;
    /*Disable External Interrupt*/
    EIC_SEC_REGS->EIC_INTENCLR = 0x40;
    
    
    /* Enable the BM70 interfacing UART */
    SERCOM0_REGS->USART_INT.SERCOM_CTRLA |= SERCOM_USART_INT_CTRLA_ENABLE_Msk;

    /* Wait for sync */
    while((SERCOM0_REGS->USART_INT.SERCOM_SYNCBUSY) != 0U)
    {
        /* Do nothing */
    }
    
   /* Enable the debug UART */
    SERCOM2_REGS->USART_INT.SERCOM_CTRLA |= SERCOM_USART_INT_CTRLA_ENABLE_Msk;

    /* Wait for sync */
    while((SERCOM2_REGS->USART_INT.SERCOM_SYNCBUSY) != 0U)
    {
        /* Do nothing */
    }
    
    atcab_wakeup();
        
    RTC_Timer32Start();
    TC0_TimerStart();
}


/** 
  @Function
    void APP_SECURE_DelayCycles(void *const hw, uint32_t cycles)

  @Remarks
    Refer to the unsecure_interface.h header for function usage details.
 */

void APP_SECURE_DelayCycles(void *const hw, uint32_t cycles)
{

    (void)hw;
    (void)cycles;

    __asm(".syntax unified\n"
          "__delay:\n"
          "subs r1, r1, #1\n"
          "bhi __delay\n"
          ".syntax divided");
}
/* *****************************************************************************
 End of File
 */
