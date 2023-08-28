/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_transfer.c

  Summary:
    This file contains the source code for the MPLAB Harmony application for data transfer.

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
//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2023 Microchip Technology Inc. and its subsidiaries.
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app_transfer.h"
#include "app_sec.h"
#include "peripheral/sercom/usart/plib_sercom2_usart.h"
#include "bsp/bsp.h"
#include "definitions.h"
#include "click_routines/oled_c/oled_c_example.h"
#include "click_routines/oled_c/oled_c.h"
#include "gfx/legato/generated/le_gen_harmony.h"


// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_TRANSFER_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

extern APP_TRANSFER_DATA app_transferData;
extern APP_SEC_DATA app_secData;

extern uint8_t rand_out[];
extern uint8_t num_in[20];
extern uint8_t device_mac[];
uint8_t Client_Data[64];
uint8_t Client_Nack_Data[64];
 
volatile bool mac=0; 
volatile bool ReadUpdate=0;

uint8_t sensor_data[3];
volatile bool SensorDataRec=0;
extern volatile bool RandomGen; 
volatile bool screenInit=0;

uint8_t temperatureVal;
uint16_t adc_val;


volatile bool RandWrite=0;

extern volatile int authenticDevice;

volatile bool updateFlag=0;

volatile uint8_t Client_ECC_Nack = 0;

extern  LegatoState legatoState;

uint8_t Ack[1]={0x11};
uint8_t NAck[1]={0x55};


void App_Write_callback(uintptr_t context)
{
    RandWrite=1; 
   
}

void App_Read_callback(uintptr_t context)
{    
    ReadUpdate=1; 
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
    app_transferData.state = APP_TRANSFER_STATE_INIT;


}


/******************************************************************************
  Function:
    void APP_TRANSFER_Tasks ( void )

  Remarks:
    See prototype in app_transfer.h.
 */

void APP_TRANSFER_Tasks ( void )
{
    uint8_t i=0;
    /* Check the application's current state. */
    switch ( app_transferData.state )
    {
        /* Application's initial state. */
        case APP_TRANSFER_STATE_INIT:
        {
            bool appInitialized = true;
            if (appInitialized)
            {
                SERCOM2_USART_WriteCallbackRegister(App_Write_callback,0);
                SERCOM2_USART_ReadCallbackRegister(App_Read_callback,0);                               
                app_transferData.state = APP_TRANSFER_STATE_SERVICE_TASKS;
            }
            break;
        }
        case APP_STATE_TRANSMIT_RN:
        {
            if((legatoState==LEGATO_STATE_RUNNING)&&(screenInit==0))
            {
                oled_c_example_initialize();
                oled_c_dispaly_refresh();
                oled_c_example();
                screenInit=1;
            }
            if(SW0_Get()==0){
                while(SW0_Get()==0);
                if(RandomGen==1){
                    SERCOM2_USART_Write(num_in,sizeof(num_in));
                    app_transferData.state= APP_STATE_RECEIVE_AUTH_DATA;           
                }
            }
            
            break;
        }
        case APP_STATE_RECEIVE_AUTH_DATA:
        { 
            for(i=0;i<64;i++)
            Client_Nack_Data[i]=0xFF;
            
            if((RandWrite==1)&&(ReadUpdate==0)){    
                    SERCOM2_USART_Read(Client_Data,sizeof(Client_Data)); 
                    RandWrite=0;
            }
            else if(ReadUpdate){
                    if(memcmp(Client_Data, Client_Nack_Data, 64) == 0){
                        Client_ECC_Nack = 1;
                        oled_c_Image_nonsecure_visible();
                        SERCOM2_USART_Write(NAck,sizeof(NAck));}                
            
                    for(i=0;i<32;i++)
                    rand_out[i]=Client_Data[i];
                    for(i=32;i<64;i++)
                    device_mac[i-32]=Client_Data[i];
                    ReadUpdate=0;
                   
                   app_transferData.state=APP_TRANSFER_STATE_SERVICE_TASKS;
                   app_secData.state= APP_SEC_STATE_CALCULATE_HOST_MAC;
                }
            
   
           break;
        }
        case APP_STATE_TRANSMIT_ACK:
        {
            if(authenticDevice==1)
            {
                SERCOM2_USART_Write(Ack,sizeof(Ack));
                app_transferData.state = APP_STATE_RECEIVE_SENSOR_DATA;
                SensorDataRec=1;
                
            }
            else if(authenticDevice==-1)
            {
                SERCOM2_USART_Write(NAck,sizeof(NAck));
                app_transferData.state = APP_TRANSFER_STATE_SERVICE_TASKS;
            }
            break;
            
        }
        case APP_STATE_RECEIVE_SENSOR_DATA:
        {
            if(SensorDataRec==1) 
            {
                if((ReadUpdate==0)&&(RandWrite==1)){
                   SERCOM2_USART_Read(sensor_data,3);
                   RandWrite=0;
                }
                else if(ReadUpdate==1){               
                temperatureVal = sensor_data[0];
                adc_val = (sensor_data[2]<<8)|(sensor_data[1]);
                oled_c_example();
                ReadUpdate=0;
                SERCOM2_USART_Read(sensor_data,3);
                }
            }
            break;
        }   
        
        case APP_TRANSFER_STATE_SERVICE_TASKS:
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
