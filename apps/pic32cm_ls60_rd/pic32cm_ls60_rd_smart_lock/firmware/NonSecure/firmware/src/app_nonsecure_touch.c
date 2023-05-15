
/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_nonsecure_touch.c

  Summary:
    Source code for touch.

  Description:
    This file contains the source code for handling the touch inputs from user.  It
    implements the logic to receive passkey inputs for access authentication as well 
    as updating old passkey.
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

#include "app_nonsecure_touch.h"
#include "app_nonsecure_deadbolt_control.h"
#include "trustZone/nonsecure_entry.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
#define LUMP_SENSOR 12

#define KEYPAD_TIMEOUT 5000 // in milliseconds

#define LONG_PRESS_TIME 100

#define DEF_NUM_SENSORS 13

// *****************************************************************************
// *****************************************************************************
// Section: External variables
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

extern APP_NONSECURE_SECURITY_DATA app_securityData;

extern APP_NONSECURE_DEADBOLT_CONTROL_DATA app_db_motorData;

extern bool g_passkeyentry_stat;

extern volatile bool Wakeup;

// *****************************************************************************
// *****************************************************************************
// Section: Global Variables
// *****************************************************************************
// *****************************************************************************

volatile uint8_t passkey_slot;

uint8_t temp_passkey_slot = 1;

volatile bool dynamic_passkey=0;

volatile uint8_t entry_count=0;

/*Digit of the PIN number*/
uint8_t digit = 0;

/*Number of the key pressed*/
uint8_t pressed_key = 13;

/*Long Press Counter*/
uint32_t long_press_cnt = 0;

/*Flag to check de-bouncing*/
volatile bool key_pressed = false;

volatile bool key_suspended = false;

volatile bool set_new_passkey = false;

volatile bool user_selected = false;

/*Array to store the entered PIN*/
char passkey[32] = {'\0'};
char newkey_doublecheck[32] = {'\0'};
char temp_passkey[32] = {'\0'};

volatile bool digest_verify_status=false;


/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_NONSECURE_TOUCH_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_NONSECURE_TOUCH_DATA app_touchData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_NONSECURE_TOUCH_BuzzerOffCallback(uintptr_t context)
  Remarks:
    See prototype in app_nonsecure_touch.h
 */
void APP_NONSECURE_TOUCH_BuzzerOffCallback(uintptr_t context)
{
    TC2_CompareStop();
}

/*******************************************************************************
  Function:
    void APP_NONSECURE_BLEWakeCallback(void)
  Remarks:
    See prototype in app_nonsecure_touch.h
 */

void APP_NONSECURE_BLEWakeCallback (void)
{
/* Clear RX indication pin in case of BM71 ->  BM71_RX_IND_Clear();*/
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/*******************************************************************************
  Function:
    void APP_NONSECURE_TOUCH_BuzzerOn(uint16_t time_ms)
  Remarks:
    See prototype in app_nonsecure_touch.h
 */
void APP_NONSECURE_TOUCH_BuzzerOn(uint16_t time_ms)
{
    TC2_CompareStart();
    SYS_TIME_CallbackRegisterMS(APP_NONSECURE_TOUCH_BuzzerOffCallback, 0, time_ms, SYS_TIME_SINGLE);
}

/*******************************************************************************
  Function:
    void APP_NONSECURE_TOUCH_Backlight (bool backlight_on)
  Remarks:
    Function to control QT3 Backlight
 */
void APP_NONSECURE_TOUCH_Backlight (bool backlight_on)
{
    if (backlight_on)
    {
            QT_LED_COL0_Clear();
            QT_LED_COL1_Clear();
            QT_LED_COL2_Clear();
            QT_LED_COL3_Clear();


            QT_LED_ROW0_Clear();
            QT_LED_ROW1_Clear();
            QT_LED_ROW2_Clear();
            QT_LED_ROW3_Clear();
        
    }
    
    else
    {
            QT_LED_COL0_Set();
            QT_LED_COL1_Set();
            QT_LED_COL2_Set();
            QT_LED_COL3_Set();

            QT_LED_ROW0_Set();
            QT_LED_ROW1_Set();
            QT_LED_ROW2_Set();
            QT_LED_ROW3_Set();
    }
}

/*******************************************************************************
  Function:
    void APP_NONSECURE_TOUCH_Backlight_FalseBlink (void)
  Remarks:
    Blink backlight to indicate failed access
 */

void APP_NONSECURE_TOUCH_Backlight_FalseBlink (void)
{
   uint8_t i=0;
   APP_NONSECURE_TOUCH_BuzzerOn(500);
    while (i<=4)
    {
        i++;
        QT_LED_COL0_Clear();
        QT_LED_COL2_Clear();
        QT_LED_ROW0_Clear();
        QT_LED_ROW2_Clear();
        
        APP_NONSECURE_ENTRY_DelayMS(50);
        
        QT_LED_COL0_Set();
        QT_LED_COL2_Set();
        QT_LED_ROW0_Set();
        QT_LED_ROW2_Set();
    }
}




// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_NONSECURE_TOUCH_Initialize ( void )

  Remarks:
    See prototype in app_nonsecure_touch.h.
 */

void APP_NONSECURE_TOUCH_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app_touchData.state = APP_NONSECURE_TOUCH_STATE_INIT;


    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}


/******************************************************************************
  Function:
    void APP_NONSECURE_TOUCH_Tasks ( void )

  Remarks:
    See prototype in app_nonsecure_touch.h.
 */

void APP_NONSECURE_TOUCH_Tasks ( void )
{        
    if(TOUCH_ENABLE_Get() == false)
    {
        app_touchData.state = APP_NONSECURE_TOUCH_STATE_DISABLE;
    }

    /* Check the application's current state. */
    switch ( app_touchData.state )
    {
        /* Application's initial state. */
        case APP_NONSECURE_TOUCH_STATE_INIT:
        {
            bool appInitialized = true;


            if (appInitialized)
            {

              app_touchData.state = APP_NONSECURE_TOUCH_STATE_LUMP_MEASURE;
            
            }
            break;
        }
        
        case APP_NONSECURE_TOUCH_STATE_LUMP_MEASURE:
        {
            if (APP_NONSECURE_ENTRY_GetLowPowerMeasurementStatus() ==  true)
            {
                APP_NONSECURE_TOUCH_Backlight(false);
                APP_NONSECURE_ENTRY_TouchProcess();
                if ((APP_NONSECURE_ENTRY_GetMeasurementDoneTouch() == 1u)) 
                {
                    APP_NONSECURE_ENTRY_SetMeasurementDoneTouch(0);
                }
            }
            else
            {
                APP_NONSECURE_ENTRY_TouchProcess();
                if ((APP_NONSECURE_ENTRY_GetMeasurementDoneTouch() == 1u)) 
                {
                    APP_NONSECURE_ENTRY_SetMeasurementDoneTouch(0);
                    if ((APP_NONSECURE_ENTRY_GetSensorState(LUMP_SENSOR) & 0x80) && key_pressed == false) 
                    {// Tap Detect
                        key_pressed = true;
                    }
                    else if ((key_pressed == true) && ((APP_NONSECURE_ENTRY_GetSensorState(LUMP_SENSOR) & 0x80) != 0x80)) 
                    {
                        key_pressed = false;
                        app_touchData.state = APP_NONSECURE_TOUCH_STATE_MEASURE;
                    }
                }
            }
             break;
        }
        
        case APP_NONSECURE_TOUCH_STATE_MEASURE:
        { 
            
            //Scan keys till timeout
            if (APP_NONSECURE_ENTRY_GetLowPowerMeasurementStatus() == false)
            {
                APP_NONSECURE_ENTRY_TouchProcess();
                if ((APP_NONSECURE_ENTRY_GetMeasurementDoneTouch() == 1u)) {
                    APP_NONSECURE_ENTRY_SetMeasurementDoneTouch(0);
                    app_touchData.state = APP_NONSECURE_TOUCH_STATE_READ;
                }
            }
            
            else
            {
                app_touchData.state = APP_NONSECURE_TOUCH_STATE_LUMP_MEASURE;
            }
            
            break;
        }
        
        case APP_NONSECURE_TOUCH_STATE_READ:
        {
            app_touchData.state = APP_NONSECURE_TOUCH_STATE_UPDATE_LED;
            for (uint8_t cnt = 0; cnt < DEF_NUM_SENSORS-1; cnt++) 
                {
                    //At least one key pressed
                    if ((APP_NONSECURE_ENTRY_GetSensorState(cnt) & 0x80) && key_pressed == false) 
                    {
                        pressed_key = cnt;
                        key_pressed = true;
                    }

                }

                //Process pressed key after touch is removed from the key. Else single touch will be processed multiple times
                if ( (pressed_key < DEF_NUM_SENSORS) && ((APP_NONSECURE_ENTRY_GetSensorState(pressed_key) & 0x80) != 0x80))
                {
                    switch (pressed_key)
                        {   
                            case 0:
                                passkey[digit] = '1';
                                digit++;
                                break;

                            case 1:
                                passkey[digit] = '2';
                                digit++;
                                break;

                            case 2:
                                passkey[digit] = '3';
                                digit++;
                                break;

                            case 3:
                                passkey[digit] = '4';
                                digit++;
                                break;

                            case 4:
                                passkey[digit] = '5';
                                digit++;
                                break;

                            case 5:
                                passkey[digit] = '6';
                                digit++;
                                break;

                            case 6:
                                passkey[digit] = '7';
                                digit++;
                                break;

                            case 7:
                                passkey[digit] = '8';
                                digit++;
                                break;

                            case 8:
                                passkey[digit] = '9';
                                digit++;
                                break;

                            case 9:
                                if (long_press_cnt > LONG_PRESS_TIME)
                                {//Long press for entering Digest passkey
                                #ifdef WIFI_ENABLE
                                   if(g_passkeyentry_stat==true){
                                    long_press_cnt = 0; 
                                    user_selected = true;    
                                    dynamic_passkey = true;                                    
                                    }
                                    else{
                                       APP_NONSECURE_TOUCH_Backlight_FalseBlink();
                                       user_selected = false;                                      
                                    }
                                #else
                                    APP_NONSECURE_TOUCH_Backlight_FalseBlink();
                                       user_selected = false; 
                                #endif
                                }
                                else{
                                memset (passkey, 0, sizeof passkey);
                                dynamic_passkey=false;
                                user_selected=false;
                                entry_count=0;                                
                                digit = 0;
                                }
                                break;

                            case 10:
                                passkey[digit] = '0';
                                digit++;
                                break;    

                            case 11:
                            {
                                //Long Press Detected. Configure for New passkey storage
                                if (long_press_cnt > LONG_PRESS_TIME) 
                                 {
                                    #if DEBUG_PRINT
                                  printf ("\r\n Select User and Enter your current Passkey");
                                  #endif
                                  long_press_cnt = 0;
                                  APP_NONSECURE_ENTRY_SetNewPasskeyStatus(true);
                                  APP_NONSECURE_ENTRY_SetPasskeyValidationStatus(false);
                                  user_selected = false;
                                  break;
                                 }
                                   
                                if((user_selected==true)&&(dynamic_passkey==true))
                                {
                                #ifdef WIFI_ENABLE
                                    if (digit < 5)
                                    {
                                        APP_NONSECURE_TOUCH_Backlight_FalseBlink();
                                        user_selected = false;
                                        break;
                                    }
                                    //Take only the last 5 digits entered
                                    strcpy (temp_passkey, &passkey[digit-5]);
                                    memset (passkey, 0, sizeof passkey);
                                    strcpy (passkey,temp_passkey);                                    
                                    APP_NONSECURE_ENTRY_SetPasskeyData((uint8_t*)passkey);                                    
                                    APP_NONSECURE_ENTRY_DigestCompute();
                                    if((digest_verify_status=APP_NONSECURE_ENTRY_DigestValidation())==1)
                                    {
                                      g_passkeyentry_stat=false;
                                      dynamic_passkey=false;
                                      user_selected=false;
                                      app_securityData.state = APP_NONSECURE_SECURITY_STATE_WAIT;
                                      app_db_motorData.state = APP_NONSECURE_DEADBOLT_CONTROL_STATE_OPEN; 
                                    }
                                    else
                                    {
                                        entry_count++;
                                        if(entry_count>3){                                            
                                            g_passkeyentry_stat=false;
                                            dynamic_passkey=false;
                                            user_selected=false;
                                            entry_count=0;
                                        }
                                    }                                 
                                #endif    
                                }       
                                //Passkey for specific user has been entered
                                else if ((user_selected == true)&&(dynamic_passkey==false))
                                {
                                    //If entered key less than 5 digits, abort
                                    if (digit < 5)
                                    {
                                        APP_NONSECURE_TOUCH_Backlight_FalseBlink();
                                        user_selected = false;
                                        break;
                                    }
                                        
                                    //Take only the last 5 digits entered
                                    strcpy (temp_passkey, &passkey[digit-5]);
                                    memset (passkey, 0, sizeof passkey);
                                    strcpy (passkey,temp_passkey);
                                    #if DEBUG_PRINT
                                    printf ("\r\n Five Digitkey = %s",passkey);
                                    #endif
                                
                                    //User authenticated for entering new passkey
                                    if ((APP_NONSECURE_ENTRY_GetNewPasskeyStatus()) && (APP_NONSECURE_ENTRY_GetPasskeyValidationStatus()))
                                    {
                                        //Request new key to be entered twice
                                        if (newkey_doublecheck[0] == '\0')
                                        {
                                            strcpy(newkey_doublecheck, passkey);
                                            #if DEBUG_PRINT
                                            printf("\r\nRe-enter new key");
                                            #endif
                                        }
                                        
                                        else
                                        {
                                            if ( strcmp(passkey,newkey_doublecheck) == 0) // Keys match
                                            {
                                                #if DEBUG_PRINT
                                                printf("\r\nKeys match");
                                                #endif
                                                memset (newkey_doublecheck, 0, sizeof newkey_doublecheck);
                                                APP_NONSECURE_ENTRY_SetNewPasskeyStatus(false);
                                                APP_NONSECURE_ENTRY_SetPasskeyValidationStatus(false);
                                                user_selected = false;

                                                app_securityData.state = APP_NONSECURE_SECURITY_STATE_NEW_PASSKEY;
                                            }
                                            
                                            else
                                            {
                                                APP_NONSECURE_TOUCH_Backlight_FalseBlink();
                                                #if DEBUG_PRINT
                                                printf("\r\nKeys do not match. Re-enter two times");
                                                #endif
                                                memset (newkey_doublecheck, 0, sizeof newkey_doublecheck);
                                            }
                                        }
 
                                    }
                                    
                                    //Validate entered key
                                    else
                                    {
                                        if (!APP_NONSECURE_ENTRY_GetNewPasskeyStatus())
                                            user_selected = false;
                                        APP_NONSECURE_ENTRY_SetPasskeyData((uint8_t*)passkey);
                                        app_securityData.state = APP_NONSECURE_SECURITY_STATE_VALIDATE_PASSKEY;
                                    }
                                }
                                
                                //Select User
                                else
                                {
                                    passkey_slot = (atoi(passkey)%10);
                                    memset (passkey, 0, sizeof passkey);
                                    
                                    if (passkey_slot == 1)  // Temporary key slot (9)
                                    {
                                        if (APP_NONSECURE_ENTRY_GetTempkeyStatus() == true)
                                        {
                                            passkey_slot = temp_passkey_slot;
                                            APP_NONSECURE_ENTRY_SetTempkeyStatus(false);
                                        }
                                        else
                                        {
                                            #if DEBUG_PRINT
                                            printf ("\r\n Temporary key expired");
                                            #endif
                                            digit = 0;
                                            APP_NONSECURE_TOUCH_Backlight_FalseBlink();
                                            break;
                                        }
                                    }
                                        
                                    
                                    //Invalid Slot
                                    else if (passkey_slot==0 || passkey_slot>5)
                                    {
                                        #if DEBUG_PRINT
                                        printf ("\r\n Enter valid slot (from 1 to 5)");
                                        #endif
                                        digit = 0;
                                        APP_NONSECURE_TOUCH_Backlight_FalseBlink();
                                        break;
                                    }
                                    
                                    user_selected = true;
                                    APP_NONSECURE_ENTRY_SetPasskeySlot(passkey_slot);
                                    #if DEBUG_PRINT
                                    printf ("\r\nUser Selected = %d",passkey_slot);
                                    #endif
                                }
                                
                                digit = 0;
                                break;
                            } 
                        case 12:{
                            // Lump Sensor Touched. Handle Door Close
                            if(app_db_motorData.door_state != APP_NONSECURE_DEADBOLT_CONTROL_DOOR_CLOSED)
                                app_db_motorData.state = APP_NONSECURE_DEADBOLT_CONTROL_STATE_CLOSE;
                            else                        
                                APP_NONSECURE_TOUCH_Backlight(true);

                            break;}
                            
                        default:
                            break;
                        }
                    
                    key_pressed = false;
                    pressed_key = DEF_NUM_SENSORS;
                    long_press_cnt = 0;
                }
            
                //Touch key press and on-hold
                else if ( (pressed_key < DEF_NUM_SENSORS) && ((APP_NONSECURE_ENTRY_GetSensorState(pressed_key) & 0x80) == 0x80))
                {
                    long_press_cnt++;
                    
                    if (long_press_cnt > LONG_PRESS_TIME) //Long Press Detected
                    {   
                        /*Clear Long pressed key*/
                        memset (passkey, 0, sizeof passkey);
                        digit = 0;
                        
                        /*Blink Backlight */
                        APP_NONSECURE_TOUCH_Backlight(false);
                        APP_NONSECURE_ENTRY_DelayMS(50);
                        
                        APP_NONSECURE_TOUCH_Backlight(true);
                        APP_NONSECURE_ENTRY_DelayMS(50);
                       
                        APP_NONSECURE_TOUCH_Backlight(false);
                        APP_NONSECURE_ENTRY_DelayMS(50);
                       
                        APP_NONSECURE_TOUCH_Backlight(true);
                        APP_NONSECURE_ENTRY_DelayMS(50);
                       
                        APP_NONSECURE_TOUCH_Backlight(false);
                        /*Blink Backlight */
                    }
                }
            break;
        }
        
        case APP_NONSECURE_TOUCH_STATE_UPDATE_LED:
        {
            uint8_t column_mask = 0;
            uint8_t row_mask    = 0;

            QT_LED_COL0_Clear();
            QT_LED_COL1_Clear();
            QT_LED_COL2_Clear();
            QT_LED_COL3_Clear();

            QT_LED_ROW0_Clear();
            QT_LED_ROW1_Clear();
            QT_LED_ROW2_Clear();
            QT_LED_ROW3_Clear();
            
            /* get the touch button status as column and row */
            for (uint8_t cnt = 0; cnt < DEF_NUM_SENSORS-1; cnt++) {
                if (APP_NONSECURE_ENTRY_GetSensorState(cnt) & 0x80) {
                    column_mask |= (1 << (cnt % 3));
                    row_mask |= (1 << (cnt / 3)); 
                }
            }

            /* turn on corresponding column line based on touch status */
            if (column_mask & (1 << 0))
            {
                QT_LED_COL0_Clear();
                QT_LED_COL1_Set();
                QT_LED_COL2_Set();
                QT_LED_COL3_Set();
            }


            if (column_mask & (1 << 1))
            {
                QT_LED_COL1_Clear();
                QT_LED_COL0_Set();
                QT_LED_COL2_Set();
                QT_LED_COL3_Set();
            }

            if (column_mask & (1 << 2))
            {
                QT_LED_COL2_Clear();
                QT_LED_COL0_Set();
                QT_LED_COL1_Set();
                QT_LED_COL3_Set();
            }

            if (column_mask & (1 << 3))
            {
                QT_LED_COL3_Clear();
                QT_LED_COL0_Set();
                QT_LED_COL1_Set();
                QT_LED_COL2_Set();
            }

            /* turn on corresponding row line based on touch status */
            if (row_mask & (1 << 0))
            {
                QT_LED_ROW0_Clear();
                QT_LED_ROW1_Set();
                QT_LED_ROW2_Set();
                QT_LED_ROW3_Set();
            }

            if (row_mask & (1 << 1))
            {
                QT_LED_ROW1_Clear();
                QT_LED_ROW0_Set();
                QT_LED_ROW2_Set();
                QT_LED_ROW3_Set();
            }

            if (row_mask & (1 << 2))
            {
                QT_LED_ROW2_Clear();
                QT_LED_ROW0_Set();
                QT_LED_ROW1_Set();
                QT_LED_ROW3_Set();
            }

            if (row_mask & (1 << 3))
            {
                QT_LED_ROW3_Clear();
                QT_LED_ROW0_Set();
                QT_LED_ROW1_Set();
                QT_LED_ROW2_Set();
            }
            app_touchData.state = APP_NONSECURE_TOUCH_STATE_MEASURE;
            break;
        }
        case APP_NONSECURE_TOUCH_STATE_DISABLE:
        {
            QT_LED_COL0_Set();
            QT_LED_COL1_Set();
            QT_LED_COL2_Set();
            QT_LED_COL3_Set();

            QT_LED_ROW0_Set();
            QT_LED_ROW1_Set();
            QT_LED_ROW2_Set();
            QT_LED_ROW3_Set();
            
            APP_NONSECURE_ENTRY_RTC_TimerStop();
            app_touchData.state = APP_NONSECURE_TOUCH_STATE_ENABLE_WAIT;
                  
            break;
        }
        case APP_NONSECURE_TOUCH_STATE_ENABLE_WAIT:
        {
             /*If touch enabled again*/
            if(TOUCH_ENABLE_Get() == true)
            {
                APP_NONSECURE_ENTRY_RTC_TimerStart();
                app_touchData.state = APP_NONSECURE_TOUCH_STATE_MEASURE;
                break;
            }
        }
        
     


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
