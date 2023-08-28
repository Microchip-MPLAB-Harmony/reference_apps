/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_transfer.c

  Summary:
    This file contains the source code for the MPLAB Harmony application for transfer functions.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*
    (c) 2021 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app_transfer.h"
#include <stdio.h>
#include "app_sec.h"
#include "peripheral/systick/plib_systick.h"
#include <string.h>
#include "cryptoauthlib.h"
// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
extern ATCAIfaceCfg atecc608_0_init_data;
extern uint8_t num_in[20];
extern uint8_t rand_out[32];
volatile bool NonceComp=false;


extern uint8_t device_mac[32];
extern volatile bool mac_stat;
volatile bool RandRead=false;
volatile bool WriteUpdate=0;
volatile bool tx_complt=0;
volatile bool ECC_No_Ack = 0;
uint8_t count=0, wrt_contxt=0;;
uint8_t host_data[64];
volatile bool timerOverflow=0;
uint8_t ECC_NACK_DATA[64];
uint8_t Ack[1];
uint8_t auth_ack;
extern uint8_t ECC_Ack;

uint8_t* sensor_Data;
volatile uint8_t sensor_temp, light_lsb, light_msb;
uint8_t sensor_datas[3];


extern APP_SEC_DATA app_secData;
extern APP_TRANSFER_DATA app_transfer_Data;
extern uint8_t temperatureVal;
extern uint16_t adc_val;
uint8_t sensorData[3], adc_msb, secure_state;

/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_TRANSFER_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************
void App_Write_callback(uintptr_t context)
{
    WriteUpdate=1;   
}

void App_Read_callback(uintptr_t context)
{   
    RandRead=1;   
}

void secure_USART_callback_init(void)
{
    SERCOM2_USART_WriteCallbackRegister(App_Write_callback,0);
    SERCOM2_USART_ReadCallbackRegister(App_Read_callback,0);
}

void secure_transmit_data_no_ecc(void)
{
    for(int i=0; i<64; i++)
    {
        ECC_NACK_DATA[i] = 0xFF;
    }
    SERCOM2_USART_Write(ECC_NACK_DATA,sizeof(ECC_NACK_DATA));
    ECC_No_Ack = 1;
}

void secure_transmit_data(void)
{
   
    if((WriteUpdate==0)&& (mac_stat == 1)){ 
    memcpy((uint8_t *)host_data,(uint8_t *)rand_out,sizeof(rand_out));
    memcpy((uint8_t *)(host_data+sizeof(rand_out)),(uint8_t *)device_mac,sizeof(device_mac));
    SERCOM2_USART_Write(host_data,sizeof(host_data));
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
void secure_receive_data(void)
{
    if((RandRead==0)&&(NonceComp==0))
        SERCOM2_USART_Read(num_in,sizeof(num_in));             
}

bool secure_receive_state(void)
{
    return RandRead;
}

void secure_clr_receive_state(void)
{
    RandRead = false;
}

bool secure_mac_state(void)
{
    return mac_stat;
}

bool secure_ack_state(void)
{
    return auth_ack;
}

bool secure_transmit_state(void)
{
    return WriteUpdate;
}

void secure_pass_sensor_data(uint8_t* sensorval)
{
    
    sensor_datas[0] = sensorval[0];
    sensor_datas[1] = sensorval[1];
    sensor_datas[2] = sensorval[2];
          
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_TRANSFER_Initialize ( void )

  Remarks:
    See prototype in app_transfer.h.
 */

void APP_TRANSFER_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app_transfer_Data.state = APP_STATE_TRANSFER_INIT;

}


/******************************************************************************
  Function:
    void APP_TRANSFER_Tasks ( void )

  Remarks:
    See prototype in app_transfer.h.
 */

void APP_TRANSFER_Tasks ( void )
{

    /* Check the application's current state. */
   
    switch ( app_transfer_Data.state )
    {
        /* Application's initial state. */
        case APP_STATE_TRANSFER_INIT:
        {
            secure_USART_callback_init();
            app_transfer_Data.state= APP_STATE_RECEIVE_RNG;
            break;
        }
        
        case APP_STATE_NO_ECC:
        {
            if(ECC_No_Ack ==0)
            secure_transmit_data_no_ecc();
            
            if((ECC_No_Ack)&&(WriteUpdate==1))
            {
            SERCOM2_USART_Read(Ack,1);
            if(Ack[0] == 0x55)
            app_transfer_Data.state= APP_STATE_SERVICE_TRANSFER_TASKS;
            }            
            
                
            break;
            
        }
        
        /*Receive Random number(20 bytes) for MAC computation*/
        case APP_STATE_RECEIVE_RNG:
        {         
            secure_receive_data();
            app_transfer_Data.state= APP_STATE_GET_AUTH_DATA;     
            
           break;
        }
        
        
        /*Check if Random bytes are received and compute device MAC*/
        case APP_STATE_GET_AUTH_DATA:
        {
             if (secure_receive_state()==1){
                 if(!ECC_Ack)
                    {
                        app_transfer_Data.state= APP_STATE_NO_ECC;
                    }
                else
                    {
                        app_secData.state= APP_SEC_STATE_GENERATE_DEVICE_MAC;
                        app_transfer_Data.state= APP_STATE_SERVICE_TRANSFER_TASKS;
                        secure_clr_receive_state();
                 }
             }
             break;            
        }
             
        
        /*Transmit generated MAC and RNG(32 bytes) to host for authentication*/
        case  APP_STATE_TRANSMIT_AUTH_DATA:
        {              
            secure_transmit_data();
            app_transfer_Data.state= APP_STATE_GET_DATA_READY;        

            break;
        }    
        
        /*Check Authorization Ack from host and get ready to receive sensor data*/
        case APP_STATE_GET_DATA_READY:
        {
            if(secure_ack_state())
            {
                secure_state = 1;
                
                adc_msb = (uint8_t)(adc_val>>8);
                memcpy(&sensorData[0], &temperatureVal, sizeof(uint8_t));
                memcpy(&sensorData[1], &adc_val, sizeof(uint8_t));
                memcpy(&sensorData[2], &(adc_msb), sizeof(uint8_t));
                secure_pass_sensor_data(sensorData);                
            }            
            secure_transmit_data();            
        }
     

        case APP_STATE_SERVICE_TRANSFER_TASKS:
        {
            break;
        }     


        /* The default state should never be executed. */
        default:
        {

            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
