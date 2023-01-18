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
#include "click_routines/heartrate9/heartrate9.h"
#include "click_routines/eink_epaper_2_9_296_128/eink_epaper_2_9_296_128.h"
#include "click_routines/eink_epaper_2_9_296_128/eink_epaper_2_9_296_128_image.h"
#include "click_routines/eink_epaper_2_9_296_128/eink_epaper_2_9_296_128_font.h"
#include "../src/ble/non_gui/ble.h"

extern BLE_DATA bleData;

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
    This structure should be initialized by the APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_DATA        appData;

volatile    bool    cmd_sent, cmd_successfull;
volatile    bool    hr_measurment_request;
volatile    uint8_t eic_count = 0;
volatile    bool    button_pressed = false;
            uint8_t hr_measurment_handle;
            bool    rdy_signal = false;
            char    lcl_buffer[10];
            uint32_t count = 0;
static            int8_t heartRateMeasuredData  = -1;


// *****************************************************************************
// *****************************************************************************
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
    CUSTOM_BT_SendDataOverBLE(bleData.bt.handle, (uint8_t*)tempBuffer, 2);
}

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    appData.app_state           = APP_INIT_STATE;
}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in apph.
 */
void APP_Tasks ( void )
{
    CUSTOM_BM71_Tasks();
    bleTasks(); 

    /* Check the application's current state. */
    switch ( appData.app_state )
    {
        /* Application's initial state. */
        case APP_INIT_STATE:
            eink_epaper_2_9_296_128_init();
            eink_epaper_2_9_296_128_fill_screen( EINK_EPAPER_2_9_296_128_COLOR_BLACK );
            eink_epaper_2_9_296_128_image_bmp(mchp_logo);
            eink_epaper_2_9_296_128_set_font( guiFont_Tahoma_10_Regular, EINK_EPAPER_2_9_296_128_COLOR_WHITE, FO_HORIZONTAL );

            EIC_CallbackRegister(EIC_PIN_15, EIC_Button_Handler, 0);
            CUSTOM_BM71_Initialize();
            appData.app_state           = APP_IDLE_STATE;
            break;
        case CHKNG_HEART_RATE_DATA_RDY_STATE:
            if(true == is_heartrate9_byte_ready())  // Checking the Heartrate sensor data ready Status
            {
                heartRateMeasuredData   = -1;
                appData.app_state       = HEART_RATE_SENSOR_DATA_PROSS_STATE;
            }
            break;
        case HEART_RATE_SENSOR_DATA_PROSS_STATE:
            heartRateMeasuredData       = heartrate9_read_byte();
            if(heartRateMeasuredData != -1)             // Checking the Heartrate sensor data process completed
            {
                appData.app_state       = EINK_EPAPER_2_9_296_128_UPDATE_STATE;
            }
            break;
        case EINK_EPAPER_2_9_296_128_UPDATE_STATE:
            printf("Heartrate = %d bpm \t\r\n", (uint8_t)heartRateMeasuredData); 
            sprintf(lcl_buffer, "%dbpm", (uint8_t)heartRateMeasuredData);
            CNANO_LED_Set();
            eink_epaper_2_9_296_128_fill_screen( EINK_EPAPER_2_9_296_128_COLOR_BLACK );
            eink_epaper_2_9_296_128_image_bmp(heartrate_image);
            eink_epaper_2_9_296_128_set_font( guiFont_Tahoma_10_Regular, EINK_EPAPER_2_9_296_128_COLOR_WHITE, FO_HORIZONTAL );
            lcl_buffer[9]='\0';
            eink_epaper_2_9_296_128_text(lcl_buffer, 14, 148 );
            button_pressed              = false;
            if(hr_measurment_request == 1)
            {
                hr_measurment_request   = 0;
                send_hr_data_over_ble();
            }
            appData.app_state           = APP_IDLE_STATE;
            break;
        case APP_IDLE_STATE:
            if (appData.queryDelay == 0)
            {
                CUSTOM_BT_BLE_QueryStatus(bleData.bt.handle);
                appData.queryDelay = QUERY_DELAY;
            }
            if(button_pressed == true)
            {
                appData.app_state       = CHKNG_HEART_RATE_DATA_RDY_STATE;
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

/*******************************************************************************
 End of File
 */
