
/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    iot_cli.c

  Summary:
    This file contains the source code for the command line interface for IOT project.

  Description:

 *******************************************************************************/
// DOM-IGNORE-BEGIN
/*
    (c) 2022 Microchip Technology Inc. and its subsidiaries. You may use this
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
#include "definitions.h"
#include "debug_print.h"
#include "m2m_wifi.h"
#include "cryptoauthlib.h"
#include "crypto_client.h"
#include "credentials_storage.h"
#include "cloud_status.h"

#define MAX_PUB_KEY_LEN         200
#define WIFI_PARAMS_OPEN    1
#define WIFI_PARAMS_PSK     2
#define WIFI_PARAMS_WEP     3

extern uint8_t mode;
extern enum cloud_iot_state g_cloud_wifi_state;
bool wifi_connectToAp(uint8_t passed_wifi_creds);
bool ssidReceived = 0;
extern uint8_t CRYPTO_CLIENT_printPublicKey(char *s);
const char * const cli_version_number             = "1.0";
const char * const firmware_version_number        = "1.0.0";
static char *ateccsn = NULL;
void WiFi_ProvisionCb(uint8_t sectype, uint8_t * SSID, uint8_t * password);
static void CommandReset(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char** argv);
static void reconnect_cmd(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char** argv);
static void set_wifi_auth(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char** argv);
static void get_public_key(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char** argv);
static void get_device_id(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char** argv);
static void get_cli_version(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char** argv);
static void get_firmware_version(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char** argv);
static void set_debug_level(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char** argv);

#define         LINE_TERM       "\r\n"
static const SYS_CMD_DESCRIPTOR    usercmd1[]=
{
    {"reset_mcu",       CommandReset,           ": Reset MCU"},
};
static const SYS_CMD_DESCRIPTOR    usercmd2[]=
{
   {"reconnect",   reconnect_cmd,          ": MQTT Reconnect "},
};
static const SYS_CMD_DESCRIPTOR    usercmd3[]=
{
    {"wifi",        set_wifi_auth,          ": Set Wifi credentials //Usage: wifi <ssid>[,<pass>,[authType]] "},
};
static const SYS_CMD_DESCRIPTOR    usercmd4[]=
{
     {"key",         get_public_key,         ": Get ECC Public Key "},
};

static const SYS_CMD_DESCRIPTOR    usercmd5[]=
{
     {"device",      get_device_id,          ": Get ECC Serial No. "},
};

static const SYS_CMD_DESCRIPTOR    usercmd6[]=
{
     {"cli_version", get_cli_version,        ": Get CLI version "},
};

static const SYS_CMD_DESCRIPTOR    usercmd7[]=
{
      {"version",     get_firmware_version,   ": Get Firmware version "},
};

static const SYS_CMD_DESCRIPTOR    usercmd8[]=
{
     {"debug",       set_debug_level,        ": Set Debug Level "},
};

void sys_cmd_init()
{
    SYS_CMD_ADDGRP(usercmd1, sizeof(usercmd1)/sizeof(*usercmd1),
                        (const char*)usercmd1->cmdStr, (const char*)usercmd1->cmdDescr);
    SYS_CMD_ADDGRP(usercmd2, sizeof(usercmd2)/sizeof(*usercmd2),
                        (const char*)usercmd2->cmdStr, (const char*)usercmd2->cmdDescr);
    SYS_CMD_ADDGRP(usercmd3, sizeof(usercmd3)/sizeof(*usercmd3),
                        (const char*)usercmd3->cmdStr, (const char*)usercmd3->cmdDescr);
    SYS_CMD_ADDGRP(usercmd4, sizeof(usercmd4)/sizeof(*usercmd4),
                        (const char*)usercmd4->cmdStr, (const char*)usercmd4->cmdDescr);
    SYS_CMD_ADDGRP(usercmd5, sizeof(usercmd5)/sizeof(*usercmd5),
                        (const char*)usercmd5->cmdStr, (const char*)usercmd5->cmdDescr);
    SYS_CMD_ADDGRP(usercmd6, sizeof(usercmd6)/sizeof(*usercmd6),
                        (const char*)usercmd6->cmdStr, (const char*)usercmd6->cmdDescr);
    SYS_CMD_ADDGRP(usercmd7, sizeof(usercmd7)/sizeof(*usercmd7),
                        (const char*)usercmd7->cmdStr, (const char*)usercmd7->cmdDescr);
    SYS_CMD_ADDGRP(usercmd8, sizeof(usercmd8)/sizeof(*usercmd8),
                        (const char*)usercmd8->cmdStr, (const char*)usercmd8->cmdDescr);
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

static void set_wifi_auth(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char** argv)
{
    char *credentials[3];
    uint8_t params = 0;
    uint8_t i,j;
    const void* cmdIoParam = pCmdIO->cmdIoParam;
    char dummy_ssid[100];
    uint8_t dummy_argc = 0;

     for(i=0;i<=2;i++)credentials[i]='\0';
    if(argc >4 )
    {
        for(j=1;j<=(argc-3);j++){
          sprintf(&dummy_ssid[dummy_argc],"%s ",argv[j]);
          dummy_argc += strlen(argv[j])+1;
        }
        credentials[0] = dummy_ssid;
        credentials[1] = argv[argc - 2];
        credentials[2] = argv[argc - 1];
        params = atoi(credentials[2]);

    }else{
        credentials[0] = argv[1];
        credentials[1] = argv[2];
        credentials[2] = argv[3];
        params = atoi(credentials[2]);
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
        mode = 2; //new credentials received
        (*pCmdIO->pCmdApi->msg)(cmdIoParam, LINE_TERM "OK\r\n\4" );

        if( g_cloud_wifi_state >= CLOUD_STATE_CLOUD_CONNECTED )
        {
           g_cloud_wifi_state = CLOUD_STATE_CLOUD_DISCONNECT;
        }else{

        g_cloud_wifi_state = CLOUD_STATE_WIFI_DISCONNECT;
        ssidReceived = 1;
        }

    }
    else
    {
        (*pCmdIO->pCmdApi->msg)(cmdIoParam, LINE_TERM "Error. Wi-Fi command format is wifi <ssid>[,<pass>,[authType]]\r\n\4" );
    }
}

static void reconnect_cmd(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char** argv)
{
    const void* cmdIoParam = pCmdIO->cmdIoParam;
    g_cloud_wifi_state = CLOUD_STATE_CLOUD_DISCONNECT;
    (*pCmdIO->pCmdApi->msg)(cmdIoParam, LINE_TERM "OK\r\n" );
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