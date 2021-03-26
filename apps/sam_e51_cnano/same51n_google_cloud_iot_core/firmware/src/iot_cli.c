/*******************************************************************************
 Iot cli source file

  Company:
    Microchip Technology Inc.

  File Name:
    iot_cli.c

  Summary:

  Description:
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************************
* © [2020] Microchip Technology Inc. and its subsidiaries
 
 * Subject to your compliance with these terms, you may use this Microchip software
 * and any derivatives exclusively with Microchip products. You are responsible for
 * complying with third party license terms applicable to your use of third party
 * software (including open source software) that may accompany this Microchip software.
 
 * SOFTWARE IS ?AS IS.? NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO
 * THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT,
 * SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF
 * THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW,
 * MICROCHIP?S TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT EXCEED AMOUNT
 * OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE. ADDITIONALLY, MICROCHIP
 * OFFERS NO SUPPORT FOR THE SOFTWARE. YOU MAY CONTACT YOUR LOCAL MICROCHIP FIELD SALES SUPPORT
 * REPRESENTATIVE TO INQUIRE ABOUT SUPPORT SERVICES AND APPLICABLE FEES, IF ANY. THESE TERMS
 * OVERRIDE ANY OTHER PRIOR OR SUBSEQUENT TERMS OR CONDITIONS THAT MIGHT APPLY TO THIS SOFTWARE
 * AND BY USING THE SOFTWARE, YOU AGREE TO THESE TERMS.
*******************************************************************************************/
// DOM-IGNORE-END
#include "definitions.h"      
#include "mqtt/mqtt_core/mqtt_core.h"
#include "services/iot/cloud/crypto_client/crypto_client.h"
#include "services/iot/cloud/cloud_service.h"
#include "services/iot/cloud/wifi_service.h"
#include "credentials_storage/credentials_storage.h"
#include "debug_print.h"
#include "m2m_wifi.h"


#define MAX_PUB_KEY_LEN         200
#define WIFI_PARAMS_OPEN    1
#define WIFI_PARAMS_PSK     2
#define WIFI_PARAMS_WEP     3

const char * const cli_version_number             = "1.0";
const char * const firmware_version_number        = "1.0.0";
static char *ateccsn = NULL;

static void CommandReset(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char** argv);
static void reconnect_cmd(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char** argv);
static void set_wifi_auth(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char** argv);
static void get_public_key(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char** argv);
static void get_device_id(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char** argv);
static void get_cli_version(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char** argv);
static void get_firmware_version(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char** argv);
static void set_debug_level(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char** argv);

#define         LINE_TERM       "\r\n"  

static SYS_CMD_DESCRIPTOR    appCmdTbl[]=
{
    {"reset",       CommandReset,           ": Reset host"},
    {"reconnect",   reconnect_cmd,          ": MQTT Reconnect "},
    {"wifi",        set_wifi_auth,          ": Set Wifi credentials //Usage: wifi <ssid>[,<pass>,[authType]] "},
    {"key",         get_public_key,         ": Get ECC Public Key "},
    {"device",      get_device_id,          ": Get ECC Serial No. "},
    {"cli_version", get_cli_version,        ": Get CLI version "},
    {"version",     get_firmware_version,   ": Get Firmware version "},
    {"debug",       set_debug_level,        ": Set Debug Level "},
};

void sys_cmd_init()
{
    int ix;
    SYS_CMD_DESCRIPTOR*  pDcpt;
        pDcpt = appCmdTbl;
    for(ix = 0 ; ix < sizeof(appCmdTbl)/sizeof(*appCmdTbl); ix++ )
    {
        SYS_CMD_ADDGRP(&appCmdTbl[ix], sizeof(appCmdTbl)/sizeof(*appCmdTbl),
                   pDcpt->cmdStr, pDcpt->cmdDescr);
        pDcpt++;
    }
}

static void get_device_id(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char** argv)
{
    const void* cmdIoParam = pCmdIO->cmdIoParam;
    (*pCmdIO->pCmdApi->msg)(cmdIoParam, LINE_TERM " Device ID\r\n" );
    if (ateccsn)
    {
        (*pCmdIO->pCmdApi->print)(cmdIoParam, ateccsn);
        (*pCmdIO->pCmdApi->msg)(cmdIoParam, LINE_TERM "OK\r\n\4" );
    }
    else
    {
        (*pCmdIO->pCmdApi->msg)(cmdIoParam, LINE_TERM " Unknown.\r\n" );
    }    
}

static void get_cli_version(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char** argv)
{
    const void* cmdIoParam = pCmdIO->cmdIoParam;
    (*pCmdIO->pCmdApi->msg)(cmdIoParam, LINE_TERM " CLI Version\r\n" );
    (*pCmdIO->pCmdApi->print)(cmdIoParam, cli_version_number);
}

static void get_firmware_version(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char** argv)
{
    const void* cmdIoParam = pCmdIO->cmdIoParam;
    (*pCmdIO->pCmdApi->msg)(cmdIoParam, LINE_TERM " Firmware Version\r\n" );
    (*pCmdIO->pCmdApi->print)(cmdIoParam, firmware_version_number);
}

static void set_debug_level(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char** argv)
{
    const void* cmdIoParam = pCmdIO->cmdIoParam;
     //debug_severity_t level = SEVERITY_NONE;
     uint8_t level = 0;
    (*pCmdIO->pCmdApi->msg)(cmdIoParam, LINE_TERM " Set Debug Level\r\n" );
    (*pCmdIO->pCmdApi->print)(cmdIoParam, argv[1]);
    level = (*argv[1] - '0');
    if (level >=0 && level <=4){
        debug_setSeverity((debug_severity_t)level);
        (*pCmdIO->pCmdApi->msg)(cmdIoParam, LINE_TERM "OK\r\n\4" );
    }
    else {
        (*pCmdIO->pCmdApi->msg)(cmdIoParam, LINE_TERM "Debug level must be between 0 (Least) and 4 (Most) \r\n" );
    }
}
// implementation
static void CommandReset(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char** argv)
{
    const void* cmdIoParam = pCmdIO->cmdIoParam;
    (*pCmdIO->pCmdApi->msg)(cmdIoParam, LINE_TERM " *** System Reboot ***\r\n" );
    NVIC_SystemReset();
}

static void reconnect_cmd(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char** argv)
{
    const void* cmdIoParam = pCmdIO->cmdIoParam;
    MQTT_Disconnect(MQTT_GetClientConnectionInfo());
    (*pCmdIO->pCmdApi->msg)(cmdIoParam, LINE_TERM "OK\r\n" );
}
static void set_wifi_auth(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char** argv)
{
//    const void* cmdIoParam = pCmdIO->cmdIoParam;
    char *credentials[3];
    char *pch;
    uint8_t params = 0;
	uint8_t i,j;
    const void* cmdIoParam = pCmdIO->cmdIoParam;
    char dummy_ssid[100];
    uint8_t dummy_argc = 0;
    
    for(j=1;j<argc;j++){
      
        sprintf(&dummy_ssid[dummy_argc],"%s ",argv[j]);
        dummy_argc += strlen(argv[j])+1;
    }      
    
    for(i=0;i<=2;i++)credentials[i]='\0';

    pch = strtok (&dummy_ssid[0], ",");
    credentials[0]=pch;
       
    while (pch != NULL && params <= 2)
    {
        credentials[params] = pch;
        params++;
        pch = strtok (NULL, ",");

    }
    
    if(credentials[0]!=NULL)
    {
        if(credentials[1]==NULL && credentials[2]==NULL) params=1;
        else if(credentials[1]!= NULL && credentials[2]== NULL)
        {
            params=atoi(credentials[1]);//Resuse the same variable to store the auth type
            if (params==2 || params==3)params=5;
            else if(params==1);
            else params=2;
        }
		else params = atoi(credentials[2]);		
    }

    switch (params)
    {
        case WIFI_PARAMS_OPEN:
                strncpy(ssid, credentials[0],MAX_WIFI_CREDENTIALS_LENGTH-1);
                strcpy(pass, "\0");
                strcpy(authType, "1");                
            break;

        case WIFI_PARAMS_PSK:
		case WIFI_PARAMS_WEP:
                strncpy(ssid, credentials[0],MAX_WIFI_CREDENTIALS_LENGTH-1);
                strncpy(pass, credentials[1],MAX_WIFI_CREDENTIALS_LENGTH-1);
                sprintf(authType, "%d", params);                
            break;
            
        default:
			params = 0;
            break;
    }
	if (params)
	{
		(*pCmdIO->pCmdApi->msg)(cmdIoParam, LINE_TERM "OK\r\n\4" );
        
        if(CLOUD_isConnected())
        {
            MQTT_Close(MQTT_GetClientConnectionInfo());
        }        
		//wifi_disconnectFromAp();
        m2m_wifi_disconnect();
	}
	else
	{
        (*pCmdIO->pCmdApi->msg)(cmdIoParam, LINE_TERM "Error. Wi-Fi command format is wifi <ssid>[,<pass>,[authType]]\r\n\4" );
	}
}

static void get_public_key(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char** argv)
{
    const void* cmdIoParam = pCmdIO->cmdIoParam;
    char key_pem_format[MAX_PUB_KEY_LEN];

    if (CRYPTO_CLIENT_printPublicKey(key_pem_format) == NO_ERROR)
    {
        (*pCmdIO->pCmdApi->print)(cmdIoParam, key_pem_format);
    }
    else
    {
        (*pCmdIO->pCmdApi->msg)(cmdIoParam, LINE_TERM " Error getting key.\r\n" );
    }
}

void set_deviceId(char *id)
{
   ateccsn = id;
}