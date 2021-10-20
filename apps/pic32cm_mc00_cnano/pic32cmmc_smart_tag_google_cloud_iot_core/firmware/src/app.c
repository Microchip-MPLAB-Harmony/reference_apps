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
#include <time.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "app.h"
#include "wdrv_winc_client_api.h"
#include "iot_config/IoT_Sensor_Node_config.h"
#include "services/iot/cloud/crypto_client/cryptoauthlib_main.h"
#include "services/iot/cloud/crypto_client/crypto_client.h"
#include "services/iot/cloud/cloud_service.h"
#include "services/iot/cloud/wifi_service.h"
#include "services/iot/cloud/bsd_adapter/bsdWINC.h"
#include "credentials_storage/credentials_storage.h"
#include "debug_print.h"
#include "led.h"
#include "mqtt/mqtt_core/mqtt_core.h"
#ifdef CFG_ENABLE_CLI
#include "system/command/sys_command.h"
#endif

#include "click_routines/leddriver3/leddriver3.h"
#include "click_routines/rfid/rfid.h"
#include "click_routines/ir_thermo2/ir_thermo2.h"
// *****************************************************************************
// *****************************************************************************
// Section: Local Function Prototypes
// *****************************************************************************
// *****************************************************************************
static void APP_SendToCloud(void);
static void APP_DataTask(void);
static void APP_WiFiConnectionStateChanged(uint8_t status);
static void APP_ProvisionRespCb(DRV_HANDLE handle, WDRV_WINC_SSID * targetSSID, WDRV_WINC_AUTH_CONTEXT * authCtx, bool status);
static void APP_DHCPAddressEventCb(DRV_HANDLE handle, uint32_t ipAddress);
static void APP_GetTimeNotifyCb(DRV_HANDLE handle, uint32_t timeUTC);
static void APP_ConnectNotifyCb(DRV_HANDLE handle,WDRV_WINC_ASSOC_HANDLE assochandle, WDRV_WINC_CONN_STATE currentState, WDRV_WINC_CONN_ERROR errorCode);

volatile bool led_on_green =0;
volatile bool led_on_blue =0;
volatile bool led_on_red =0;
// *****************************************************************************
// *****************************************************************************
// Section: Application Macros
// *****************************************************************************
// *****************************************************************************


#define APP_WIFI_SOFT_AP  0
#define APP_WIFI_DEFAULT  1
#define APP_DATATASK_INTERVAL 100L //100msec
#define APP_SW_DEBOUNCE_INTERVAL   1460000L

/* WIFI SSID, AUTH and PWD for AP */
#define APP_CFG_MAIN_WLAN_SSID  "MCHP.IOT"
#define APP_CFG_MAIN_WLAN_AUTH  M2M_WIFI_SEC_WPA_PSK
#define APP_CFG_MAIN_WLAN_PSK   "microchip"

#define CFG_APP_WINC_DEBUG       0 //define this to print WINC debug messages

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

/* Place holder for ECC608A unique serial id */
char attDeviceID[20] = "BAAAAADD1DBAAADD1D";
ATCA_STATUS appCryptoClientSerialNumber;

shared_networking_params_t shared_networking_params;

/* Various NTP Host servers that application relies upon for time sync */
#define WORLDWIDE_NTP_POOL_HOSTNAME     "*.pool.ntp.org"
#define ASIA_NTP_POOL_HOSTNAME          "asia.pool.ntp.org"
#define EUROPE_NTP_POOL_HOSTNAME        "europe.pool.ntp.org"
#define NAMERICA_NTP_POOL_HOSTNAME      "north-america.pool.ntp.org"
#define OCEANIA_NTP_POOL_HOSTNAME       "oceania.pool.ntp.org"
#define SAMERICA_NTP_POOL_HOSTNAME      "south-america.pool.ntp.org"
#define GOOGLE_NTP_HOSTNAME             "time.google.com"

#define ID_BUF_SIZE                     38

/* Driver handle for WINC1510 */
static DRV_HANDLE wdrvHandle;
uint8_t mode = WIFI_DEFAULT;

static char ID_Buf[ID_BUF_SIZE];

SYS_TIME_HANDLE App_DataTaskHandle = SYS_TIME_HANDLE_INVALID;
volatile bool App_DataTaskTmrExpired = false;
SYS_TIME_HANDLE App_CloudTaskHandle = SYS_TIME_HANDLE_INVALID;  
volatile bool App_CloudTaskTmrExpired = false;
extern void sys_cmd_init();
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

APP_DATA appData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************
void APP_CloudTaskcb(uintptr_t context)
{
    App_CloudTaskTmrExpired = true;
}
void APP_DataTaskcb(uintptr_t context)
{
    App_DataTaskTmrExpired = true;
}
// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

// React to the WIFI state change here. Status of 1 means connected, Status of 0 means disconnected
static void  APP_WiFiConnectionStateChanged(uint8_t status)
{
   // If we have no AP access we want to retry
   if (status != 1)
   {
      // Restart the WIFI module if we get disconnected from the WiFi Access Point (AP)
      CLOUD_reset();
   } 
}


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************


/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */
void APP_Initialize(void)
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_CRYPTO_INIT;
    
    SYSTICK_TimerStart();
    
    sys_cmd_init(); // CLI init
    
    CLICK_WIFI7_CS_Clear();
#if (CFG_APP_WINC_DEBUG == 1)    
    WDRV_WINC_DebugRegisterCallback(debug_printf);
#endif
}

static void APP_ConnectNotifyCb(DRV_HANDLE handle,WDRV_WINC_ASSOC_HANDLE assochandle, WDRV_WINC_CONN_STATE currentState, WDRV_WINC_CONN_ERROR errorCode)
{
    if (WDRV_WINC_CONN_STATE_CONNECTED == currentState)
    {
        WiFi_ConStateCb(M2M_WIFI_CONNECTED);
    }
    else if(WDRV_WINC_CONN_STATE_DISCONNECTED == currentState)
    {
        WiFi_ConStateCb(M2M_WIFI_DISCONNECTED);
    }
}

static void APP_GetTimeNotifyCb(DRV_HANDLE handle, uint32_t timeUTC)
{
    //checking > 0 is not recommended, even if getsystime returns null, utctime value will be > 0
    if (timeUTC != 0x86615400U)
    {
        tstrSystemTime pSysTime;
        struct tm theTime;

        WDRV_WINC_UTCToLocalTime(timeUTC, &pSysTime);
        theTime.tm_hour = pSysTime.u8Hour;
        theTime.tm_min = pSysTime.u8Minute;
        theTime.tm_sec = pSysTime.u8Second;
        theTime.tm_year = pSysTime.u16Year-1900;
        theTime.tm_mon = pSysTime.u8Month-1;
        theTime.tm_mday = pSysTime.u8Day;
        theTime.tm_isdst = 0;      
        RTC_RTCCTimeSet(&theTime);
    }
}

static void APP_DHCPAddressEventCb(DRV_HANDLE handle, uint32_t ipAddress)
{
    WiFi_HostLookupCb();    
}
             
static void APP_ProvisionRespCb(DRV_HANDLE handle, WDRV_WINC_SSID * targetSSID, 
                                WDRV_WINC_AUTH_CONTEXT * authCtx, bool status)
{
    uint8_t sectype;
	uint8_t* ssid;
	uint8_t* password; 
    
    if (status == M2M_SUCCESS)
    {
        sectype = authCtx->authType;
        ssid = targetSSID->name;
        password = authCtx->authInfo.WPAPerPSK.key;
        WiFi_ProvisionCb(sectype, ssid, password);
    }    
}

void APP_Tasks(void)
{
    switch(appData.state)
    {
        case APP_STATE_CRYPTO_INIT:
        {
        #ifdef CFG_ENABLE_CLI     
            set_deviceId(attDeviceID);
        #endif   
            debug_init(attDeviceID);
    		CLICK_WIFI7_CS_Set();
            rfid_init();
    		CLICK_WIFI7_CS_Clear();

            cryptoauthlib_init(); 
            if (cryptoDeviceInitialized == false)
            {
               debug_printError("APP: CryptoAuthInit failed");
            }
            appCryptoClientSerialNumber = CRYPTO_CLIENT_printSerialNumber(attDeviceID);
            if(appCryptoClientSerialNumber != ATCA_SUCCESS )
            {
               switch(appCryptoClientSerialNumber)
               {
                  case ATCA_GEN_FAIL:
                        debug_printError("APP: DeviceID generation failed, unspecified error");
                  break;
                  case ATCA_BAD_PARAM:
                        debug_printError("APP: DeviceID generation failed, bad argument");
                  default:
                        debug_printError("APP: DeviceID generation failed");
                  break;
               }
            }
        #ifdef CFG_ENABLE_CLI   
            set_deviceId(attDeviceID);
        #endif  
            debug_setPrefix(attDeviceID);
            CLOUD_setdeviceId(attDeviceID);
            appData.state = APP_STATE_WDRV_INIT;
            break;
        }
        case APP_STATE_WDRV_INIT:
        {
			led_driver3_set_brightness(  LED_DRIVER_3_CONSTANT | LED_DRIVER_3_BRIGHTNESS_16 );
            if (SYS_STATUS_READY == WDRV_WINC_Status(sysObj.drvWifiWinc)) {
                appData.state = APP_STATE_WDRV_INIT_READY;
            }
            break;
        }
        case APP_STATE_WDRV_INIT_READY:
        {   
            wdrvHandle = WDRV_WINC_Open(0, 0);

            if (DRV_HANDLE_INVALID != wdrvHandle) {
                appData.state = APP_STATE_WDRV_OPEN;
            }
            
            break;
        }

        case APP_STATE_WDRV_OPEN:
        {
            m2m_wifi_configure_sntp((uint8_t *)GOOGLE_NTP_HOSTNAME, strlen(GOOGLE_NTP_HOSTNAME), SNTP_ENABLE_DHCP);
            m2m_wifi_enable_sntp(1); 
            WDRV_WINC_DCPT *pDcpt = (WDRV_WINC_DCPT *)wdrvHandle;
            pDcpt->pCtrl->pfProvConnectInfoCB = APP_ProvisionRespCb;
            wifi_init(APP_WiFiConnectionStateChanged, mode);

            if (mode == WIFI_DEFAULT) {
                
                /* Enable use of DHCP for network configuration, DHCP is the default
                but this also registers the callback for notifications. */
                WDRV_WINC_IPUseDHCPSet(wdrvHandle, &APP_DHCPAddressEventCb);
            
                App_CloudTaskHandle = SYS_TIME_CallbackRegisterMS(APP_CloudTaskcb, 0, 500, SYS_TIME_PERIODIC);
                App_DataTaskHandle = SYS_TIME_CallbackRegisterMS(APP_DataTaskcb, 0, APP_DATATASK_INTERVAL, SYS_TIME_PERIODIC);
                WDRV_WINC_BSSReconnect(wdrvHandle, &APP_ConnectNotifyCb); 
                WDRV_WINC_SystemTimeGetCurrent(wdrvHandle, &APP_GetTimeNotifyCb);
            }
            
            appData.state = APP_STATE_WDRV_ACTIV;
            break;
        }

        case APP_STATE_WDRV_ACTIV:
        {
            if(App_CloudTaskTmrExpired == true) {
                App_CloudTaskTmrExpired = false;
                CLOUD_task();
            }
            if(App_DataTaskTmrExpired == true) {
                App_DataTaskTmrExpired = false;
                APP_DataTask();
            }
            CLOUD_sched();
            wifi_sched();
            MQTT_sched();
            LED_sched();
            break;
        }    
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}

// This gets called by the scheduler approximately every 100ms
static void APP_DataTask(void)
{
   static time_t previousTransmissionTime = 0;
   
   // Get the current time. This uses the C standard library time functions
   time_t timeNow;// = time(NULL);

   struct tm sys_time;
   RTC_RTCCTimeGet(&sys_time);
   timeNow = mktime(&sys_time);

   // Example of how to send data when MQTT is connected every 1 second based on the system clock
    if (CLOUD_isConnected()) {
        // How many seconds since the last time this loop ran?
        int32_t delta = difftime(timeNow,previousTransmissionTime);

        if (delta >= CFG_SEND_INTERVAL) {
           previousTransmissionTime = timeNow;

           // Call the data task in main.c
           APP_SendToCloud();
        }
    } 
    if (!shared_networking_params.haveAPConnection) {
       led_on_blue = 0;
        
    } else {
        if(led_on_blue == 0){
        led_driver3_set_color(  LED_DRIVER_3_COLOR_BLUE );
        SYSTICK_DelayMs(200);
        led_on_blue = 1;
        }
    }
    if (!shared_networking_params.haveERROR) {
        led_on_red = 0;
    } else {
      if(led_on_red == 0){
        led_driver3_set_color(  LED_DRIVER_3_COLOR_RED );
        SYSTICK_DelayMs(200);
        led_on_red = 1;
       }
    }
    if (LED_isBlinkingGreen() == false) {
        if (!CLOUD_isConnected()) {
           led_on_green= 0;
        } else {
            if(led_on_green == 0){
                led_driver3_set_color(  LED_DRIVER_3_COLOR_GREEN );
                SYSTICK_DelayMs(200);
                led_on_green = 1;
            }
        }
    }
}

// This will get called every 1 second only while we have a valid Cloud connection
void APP_SendToCloud(void)
{
    static char json[120];
    int len = 0;

    // This part runs every CFG_SEND_INTERVAL seconds
    float rawTemperature = ir_thermo2_Get_Object_Temperature();
    CLICK_WIFI7_CS_Set();
    if(false == GetTagID(ID_Buf))
    {
        len = sprintf(json, "{\"RFID Tag ID\":\"No RFID Tag\",\"Temp(C}\":\"%d\"}", 
                            (int)rawTemperature);
        debug_printError("\n\rNo RFID Tag found\n\rTemp(C):%d",(int)rawTemperature);
    }
    else
    {
        len = sprintf(json, "{\"RFID Tag ID\":\"%s\",\"Temp(C}\":\"%d\"}", 
                            ID_Buf,(int)rawTemperature);
        debug_printError("\n\rRFID Tag ID = %s\n\rTemp(C):%d", ID_Buf,(int)rawTemperature);
    }
    CLICK_WIFI7_CS_Clear();

   if (len >0) {
      CLOUD_publishData((uint8_t*)json, len);
     
      led_driver3_set_color(  LED_DRIVER_3_COLOR_YELLOW );
      SYSTICK_DelayMs(200);
      led_driver3_set_color(  LED_DRIVER_3_COLOR_OFF );
      SYSTICK_DelayMs(200);
      
   }
}

void APP_ReceivedFromCloud(uint8_t *topic, uint8_t *payload)
{
    char *toggleToken = "\"toggle\":";
    char *subString;
    
    if ((subString = strstr((char*)payload, toggleToken)))
    {
        LED_holdYellowOn(subString[strlen(toggleToken)] == '1' );
    }
  
    debug_print("topic: %s", topic);
    debug_print("payload: %s", payload);
}

void APP_application_post_provisioning(void)
{
    App_CloudTaskHandle = SYS_TIME_CallbackRegisterMS(APP_CloudTaskcb, 0, 500,
                                                        SYS_TIME_PERIODIC);
    App_DataTaskHandle = SYS_TIME_CallbackRegisterMS(APP_DataTaskcb, 0, 
                                APP_DATATASK_INTERVAL, SYS_TIME_PERIODIC);  
}

/*******************************************************************************
 End of File
 */
