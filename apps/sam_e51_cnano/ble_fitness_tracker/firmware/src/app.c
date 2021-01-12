/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

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
// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <string.h>
#include "app.h"
#include "click_heartrate3/include/heartrate_3_hw.h"
#include "click_heartrate3/include/heartrate_3.h"
#include "click_eink/include/eink.h"
#include "click_eink/include/image.h"
#include "click_eink/include/eink_font.h"
#include "../src/ble/non_gui/ble.h"

extern BLE_DATA bleData;

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

#define APP_HR3_SLAVE_ADDR                         0x58
// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_HR3_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_HR3_DATA    app_hr3Data;
APP_DATA        appData;
dynamic_modes_t dynamic_modes;

volatile    bool    cmd_sent, cmd_successfull;
volatile    bool    hr_measurment_request;
volatile    uint8_t eic_count = 0;
volatile    bool    button_pressed = false;
            uint8_t hr_measurment_handle;
            bool    rdy_signal = false;
            char    lcl_buffer[10];
            uint32_t count = 0;
            uint8_t heartRateMeasuredData  = 0;


// *****************************************************************************
// *****************************************************************************
static void APP_I2C_HR3_EventHandler(
    DRV_I2C_TRANSFER_EVENT event,
    DRV_I2C_TRANSFER_HANDLE transferHandle,
    uintptr_t context
)
{
    switch(event)
    {
        case DRV_I2C_TRANSFER_EVENT_COMPLETE:
            app_hr3Data.isTransferDone = true;
            break;
        case DRV_I2C_TRANSFER_EVENT_ERROR:
            app_hr3Data.state = APP_HR3_STATE_ERROR;
            break;
        default:
            break;
    }
}

static void EIC_INT14_Handler(uintptr_t context)
{
    //RDY signal hit once every 10msec
    rdy_signal = true;
    eic_count++;
    if (eic_count >= 25){
        eic_count = 0;
    }
}

static void EIC_Button_Handler(uintptr_t context)
{
    CNANO_LED_Clear();
    button_pressed = true;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void send_hr_data_over_ble(void)
{
    uint8_t tempBuffer[21] = {0};

    tempBuffer[0] = 0x00;//Status of HR data is single byte
    tempBuffer[1] = heartRateMeasuredData;
    tempBuffer[2] = '\r';
    tempBuffer[3] = '\n';  
    DRV_BT_SendDataOverBLE(bleData.bt.handle, (uint8_t*)tempBuffer, 2);
}

/*******************************************************************************
  Function:
    void APP_HR3_Initialize ( void )

  Remarks:
    See prototype in app_hr3.h.
 */

void APP_Initialize ( void )
{
    DRV_BM71_Initialize();
    /* Place the App state machine in its initial state. */
    app_hr3Data.state = APP_HR3_STATE_INIT;
    app_hr3Data.i2cHandle      = DRV_HANDLE_INVALID;
    app_hr3Data.transferHandle = DRV_I2C_TRANSFER_HANDLE_INVALID;
    app_hr3Data.isTransferDone = true;
    
    //Set up dynamic modes for Heart Rate 3 Initialization
    dynamic_modes.transmit = trans_en;                      //Transmitter en/disabled
    dynamic_modes.curr_range = led_norm;                   //LED range 0 - 100
    dynamic_modes.adc_power = adc_on;                        //ADC on
    dynamic_modes.clk_mode = osc_mode;                       //Use internal Oscillator
    dynamic_modes.tia_power = tia_off;                       //TIA off
    dynamic_modes.rest_of_adc = rest_of_adc_off;             //Rest of ADC off
    dynamic_modes.afe_rx_mode = afe_rx_normal;               //Normal Receiving on AFE
    dynamic_modes.afe_mode = afe_normal;                     //Normal AFE functionality
   
    EIC_CallbackRegister(EIC_PIN_14, EIC_INT14_Handler, 0);
    EIC_CallbackRegister(EIC_PIN_15, EIC_Button_Handler, 0);
    initStatHRM();
}

/******************************************************************************
  Function:
    void APP_HR3_Tasks ( void )

  Remarks:
    See prototype in app_hr3.h.
 */
void APP_Tasks ( void )
{
    DRV_BM71_Tasks();
    bleTasks(); 

    /* Check the application's current state. */
    switch ( app_hr3Data.state )
    {
        /* Application's initial state. */
       case APP_HR3_STATE_INIT:
           
            appData.drvSPIHandle = DRV_SPI_Open( DRV_SPI_INDEX_0, DRV_IO_INTENT_READWRITE );
            if(appData.drvSPIHandle != DRV_HANDLE_INVALID)
            {
                eink_init();
                eink_image_bmp(mchp_logo);
                eink_set_font( guiFont_Tahoma_14_Regular, EINK_COLOR_BLACK, FO_HORIZONTAL);
            }
            else
            {
                app_hr3Data.state = APP_HR3_STATE_ERROR;
                break;
            }
            
            /* Open I2C driver client */
            app_hr3Data.i2cHandle = DRV_I2C_Open( DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE );
            if (app_hr3Data.i2cHandle != DRV_HANDLE_INVALID)
            {
                /* Register the I2C Driver client event callback */
                DRV_I2C_TransferEventHandlerSet(app_hr3Data.i2cHandle, APP_I2C_HR3_EventHandler, 0);

                hr3_init(APP_HR3_SLAVE_ADDR, &dynamic_modes);

                app_hr3Data.state = APP_HR3_STATE_PERIODIC_SERVICE;                               
            }
            else
            {
                app_hr3Data.state = APP_HR3_STATE_ERROR;
            }
            
          
            
            break;

        case APP_HR3_STATE_PERIODIC_SERVICE:
            if(button_pressed == true){
                if (rdy_signal != false){
                    rdy_signal = false;
     
                    uint32_t temp = hr3_get_led1_val();
                    statHRMAlgo(temp);
                    SYSTICK_DelayMs( 2 );
                    printf("%d \r\n",hr3_get_heartrate());
                    count++;
                    if(count > 2200){ 
                        count = 0;
                        button_pressed = false;
                        heartRateMeasuredData    = hr3_get_heartrate();
                        sprintf(lcl_buffer, "%dbpm", heartRateMeasuredData);
                        CNANO_LED_Set();
                        eink_image_bmp(heartrate_image);
                        eink_text(lcl_buffer,0,118 ); 
                        initStatHRM();
                        if(hr_measurment_request == 1)
                        {
                            hr_measurment_request = 0;
                            send_hr_data_over_ble();
                        }
                    }
                }
              }    
            break;

        case APP_HR3_STATE_ERROR:
           printf("Error \r\n");
            app_hr3Data.state = APP_HR3_STATE_IDLE;
            break;

        case APP_HR3_STATE_IDLE:
            if (appData.queryDelay == 0)
            {
                DRV_BT_BLE_QueryStatus(bleData.bt.handle);
                appData.queryDelay = QUERY_DELAY;
            }
            break;

        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}

void APP_HR3_I2C_Write_Ptr ( unsigned char slave_address, unsigned char *buffer, 
                            unsigned long count, unsigned long end_mode )
{
    end_mode = end_mode;   
                
    if (app_hr3Data.i2cHandle != DRV_HANDLE_INVALID)
    {      
        while (app_hr3Data.isTransferDone == false);
        app_hr3Data.isTransferDone = false;
        DRV_I2C_WriteTransferAdd(app_hr3Data.i2cHandle, slave_address, buffer,count, &app_hr3Data.transferHandle);
    }
}

void APP_HR3_I2C_Read_Ptr ( unsigned char slave_address,unsigned char *buffer, 
                              unsigned long count, unsigned long end_mode )
{
    end_mode = end_mode;

    if (app_hr3Data.i2cHandle != DRV_HANDLE_INVALID)
    {         
        while (app_hr3Data.isTransferDone == false);
        app_hr3Data.isTransferDone = false;
        DRV_I2C_ReadTransferAdd(app_hr3Data.i2cHandle, slave_address, buffer,count, &app_hr3Data.transferHandle); 
    }
}

void APP_HR3_I2C_Write_Read_Ptr ( unsigned char slave_address,unsigned char *txbuffer, 
                                 unsigned long txcount, unsigned char *rxbuffer, 
                                 unsigned long rxcount, unsigned long end_mode )
{
    end_mode = end_mode;

    if (app_hr3Data.i2cHandle != DRV_HANDLE_INVALID)
    {    
        while (app_hr3Data.isTransferDone == false);
        app_hr3Data.isTransferDone = false;            
        DRV_I2C_WriteReadTransferAdd(app_hr3Data.i2cHandle, slave_address, txbuffer, txcount, rxbuffer, rxcount, &app_hr3Data.transferHandle );
    }    
}

/*******************************************************************************
 End of File
 */
