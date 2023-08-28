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
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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
// DOM-IGNORE-END

#include <stdint.h>
#include "definitions.h"
#include "security.h"
#include "cryptoauthlib.h"
#include <stdio.h>
#include <stdlib.h>

extern ATCAIfaceCfg atecc608_0_init_data;
extern uint8_t num_in[20];
extern uint8_t rand_out[32];
volatile bool NonceComp=false;


extern uint8_t device_mac[32];
extern volatile bool mac_stat;
volatile bool RandRead=false;
volatile bool WriteUpdate=0;
volatile bool tx_complt=0;
uint8_t count=0, wrt_contxt=0;;
uint8_t host_data[64];
volatile bool timerOverflow=0;
uint8_t Ack[1];
uint8_t auth_ack;

uint8_t* sensor_Data;
volatile uint8_t sensor_temp, light_lsb, light_msb;
uint8_t sensor_datas[3];

void App_Write_callback(uintptr_t context)
{
    WriteUpdate=1;   
}

void App_Read_callback(uintptr_t context)
{   
    RandRead=1;   
}

void  App_timerCallback(TC_TIMER_STATUS status, uintptr_t context)
{
    timerOverflow = 1;
}


void RNG(uint8_t *dest, size_t size)
{
    ATCA_STATUS status = ATCA_GEN_FAIL;
    uint8_t random[RANDOM_NUM_SIZE];

    if (ATCA_SUCCESS == (status = atcab_random(random)))
    {
        memcpy(dest, random, size);
    }
}


/* Non-secure callable (entry) function */
bool __attribute__((cmse_nonsecure_entry))secure_check_device_type_in_cfg(void)
{
    ATCAIfaceCfg *cfg;
    ATCA_STATUS status;
    cfg = &atecc608_0_init_data;
    if (ATCA_SUCCESS != (status = check_device_type_in_cfg(cfg, false)))
    {
       //ATCAB init fail
        return 0;
    }
        
    else
    {
      //ATCAB init success
        return true;
    }
        
}

bool __attribute__((cmse_nonsecure_entry))secure_atcab_init(void)
{
    uint8_t io_protect=6;
    uint8_t slot_num=5;
    ATCA_STATUS status;
    ATCAIfaceCfg *cfg = &atecc608_0_init_data;
 
    if (ATCA_SUCCESS != (status = atcab_init(cfg)))
    {
      return 0;
    }
    else
    {   
        if(ATCA_SUCCESS != (status= slot_write(io_protect))){
          //Slot not written
            return 0;
        }
        else{
        if (ATCA_SUCCESS !=(status = atcab_nonce_rand(num_in, rand_out)))
        {
            return 0;
        }
        else{
        if(ATCA_SUCCESS != (status = slot_write(slot_num))){
           //Slot not written
            return 0;
        }
        else
        return true;
        }
        }
    }
       
}

uint8_t __attribute__((cmse_nonsecure_entry))secure_generate_device_mac(void)
{
    uint8_t status;
    status = generate_device_mac();
    return status;
}

void __attribute__((cmse_nonsecure_entry))secure_USART_callback_init(void)
{
    SERCOM2_USART_WriteCallbackRegister(App_Write_callback,0);
    SERCOM2_USART_ReadCallbackRegister(App_Read_callback,0);
    TC1_TimerCallbackRegister(App_timerCallback, 0);
}

void __attribute__((cmse_nonsecure_entry))secure_transmit_data(void)
{
   
    if((WriteUpdate==0)&& (mac_stat == 1)){ 
    memcpy((uint8_t *)host_data,(uint8_t *)rand_out,sizeof(rand_out));
    memcpy((uint8_t *)(host_data+sizeof(rand_out)),(uint8_t *)device_mac,sizeof(device_mac));
   
    SERCOM2_USART_Write(host_data,sizeof(host_data));
    TC1_TimerStart();
    mac_stat=0;   
    }
    else if((WriteUpdate==1)&&(mac_stat ==0))
    {
        
        SERCOM2_USART_Read(Ack,1);
        WriteUpdate=0;
    }
              
    else if((Ack[0]==0x11)&&(auth_ack==0)) /*Device authentic*/ 
            auth_ack = 1;
           
            
    else if((Ack[0]==0x11)&&(auth_ack==1)){   
        
     if(timerOverflow==1){               
        SERCOM2_USART_Write(sensor_datas,3);
        timerOverflow=0;
        }
    }
}
    
    



void __attribute__((cmse_nonsecure_entry))secure_receive_data(void)
{
    if((RandRead==0)&&(NonceComp==0))
        SERCOM2_USART_Read(num_in,sizeof(num_in));             
}

bool __attribute__((cmse_nonsecure_entry))secure_receive_state(void)
{
    return RandRead;
}

void __attribute__((cmse_nonsecure_entry))secure_clr_receive_state(void)
{
    RandRead = false;
}

bool __attribute__((cmse_nonsecure_entry))secure_mac_state(void)
{
    return mac_stat;
}

bool __attribute__((cmse_nonsecure_entry))secure_ack_state(void)
{
    return auth_ack;
}

bool __attribute__((cmse_nonsecure_entry))secure_transmit_state(void)
{
    return WriteUpdate;
}

void __attribute__((cmse_nonsecure_entry)) secure_pass_sensor_data(uint8_t* sensorval)
{
   
    sensor_datas[0] = sensorval[0];
    sensor_datas[1] = sensorval[1];
    sensor_datas[2] = sensorval[2];
          
}