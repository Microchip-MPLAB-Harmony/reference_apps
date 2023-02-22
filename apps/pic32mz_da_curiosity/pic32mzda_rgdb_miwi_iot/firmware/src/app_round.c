/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_round.c

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
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app_round.h"
#include "definitions.h"
#include "legato_public.h"
#include <time.h>
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
    This structure should be initialized by the APP_ROUND_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_ROUND_DATA app_roundData;
APP_ROUND_DEVICE app_deviceData[APP_DEV_NUM] = {0};

leChar dynamicTempCharBuff[APP_STR_SIZE] = {0};
leFixedString  dynamicTemp;

leChar dynamicRSSICharBuff[APP_STR_SIZE] = {0};
leFixedString  dynamicRSSI;

int32_t current_idx = 0;
int32_t current_screen = 1;

char receiveBuffer[RX_BUFFER_SIZE] = {0};
char localBuffer[RX_BUFFER_SIZE] = {0};
char data = 0;
int32_t sendidx = 0;
bool appInitialized = false;

/* command list for R30 initialization */
char cmd_list[][16] = {
    "cfg pan 4321\r",
    "cfg channel 8\r",
    "cfg txpower c1\r",
    "cfg phymod 0c\r",
    "cfg reconn 2\r",
    "~cfg\r",
    "start\r"
};

/* command list for toggle LED on sensor board */
char cmd_toggle_led[][18] = {
    "send 0 0 LED1 1\r",
    "send 0 0 LED1 0\r",
    "send 1 0 LED1 1\r",
    "send 1 0 LED1 0\r",
    "send 2 0 LED1 1\r",
    "send 2 0 LED1 0\r"
};

/* command list for toggle GPIO1 on sensor board */
char cmd_toggle_gpio1[][19] = {
    "send 0 0 GPIO1 1\r",
    "send 0 0 GPIO1 0\r",
    "send 1 0 GPIO1 1\r",
    "send 1 0 GPIO1 0\r",
    "send 2 0 GPIO1 1\r",
    "send 2 0 GPIO1 0\r"
};

/* command list for toggle GPIO2 on sensor board */
char cmd_toggle_gpio2[][19] = {
    "send 0 0 GPIO2 1\r",
    "send 0 0 GPIO2 0\r",
    "send 1 0 GPIO2 1\r",
    "send 1 0 GPIO2 0\r",
    "send 2 0 GPIO2 1\r",
    "send 2 0 GPIO2 0\r"
};

char messageError[] = "** UART ERRNO: ";
bool errorStatus = false;
bool readStatus = false;
UART_ERROR uart_err;
bool R30InitOK = false;

// /*****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

void APP_ReadCallback(uintptr_t context)
{
    uart_err = UART1_ErrorGet();
    if (uart_err != UART_ERROR_NONE)
    {
        /* ErrorGet clears errors, set error flag to notify console */
        errorStatus = true;
    }
    else
    {
        readStatus = true;
    }
    if (!R30InitOK)
    {
        app_roundData.state = APP_ROUND_STATE_R30INITRSP_TASKS;
    }
}

static void show_screen0_updating(void)
{
    dynamicTemp.fn->setFromCStr(&dynamicTemp, app_deviceData[current_idx].temp);
    SET_STRING(Screen0_LbTemp, (leString*)&dynamicTemp);

    dynamicRSSI.fn->setFromCStr(&dynamicRSSI, app_deviceData[current_idx].rssi);
    SET_STRING(Screen0_LbRSSI, (leString*)&dynamicRSSI);

    switch (current_idx)
    {
        case 0:
            SET_STRING(Screen0_LbDev, (leString*)&string_device);
            break;
        case 1:
            SET_STRING(Screen0_LbDev, (leString*)&string_Device2);
            break;
        case 2:
            SET_STRING(Screen0_LbDev, (leString*)&string_Device3);
            break;
        default:
            break;
    }
}

static void show_screen1_updating(void)
{
    if (app_deviceData[current_idx].online)
    {
        SET_SCHEME(Screen1_lbonline, &GreenScheme);
        SET_STRING(Screen1_lbonline, (leString*)&string_Online);
    }
    else
    {
        SET_SCHEME(Screen1_lbonline, &Alarm);
        SET_STRING(Screen1_lbonline, (leString*)&string_Offline);
    }
}

void event_Screen1_ListWheelWidget_0_OnSelectionChanged(leListWheelWidget* wgt, int32_t idx)
{
    current_idx = idx;
    show_screen1_updating();
}

void event_Screen0_BTNled_OnPressed(leButtonWidget* btn)
{
    int32_t list_idx = 0;
    switch (current_idx)
    {
        case 0:
            list_idx = app_deviceData[current_idx].led ? 1 : 0;
            break;
        case 1:
            list_idx = app_deviceData[current_idx].led ? 3 : 2;
            break;
        case 2:
            list_idx = app_deviceData[current_idx].led ? 5 : 4;
            break;
        default:
            break;
    }

    UART1_Write(cmd_toggle_led[list_idx], strlen(cmd_toggle_led[list_idx]));

    if (app_deviceData[current_idx].led)
    {
        SET_RELEASED_IMAGE(Screen0_BTNled, (leImage*)&offcircle);
        SET_PRESSED_IMAGE(Screen0_BTNled, (leImage*)&oncircle);
        app_deviceData[current_idx].led = false;
    }
    else
    {
        SET_RELEASED_IMAGE(Screen0_BTNled, (leImage*)&oncircle);
        SET_PRESSED_IMAGE(Screen0_BTNled, (leImage*)&offcircle);
        app_deviceData[current_idx].led = true;
    }
}

void event_Screen0_BTNgpio1_OnPressed(leButtonWidget* btn)
{
    int32_t list_idx = 0;
    switch (current_idx)
    {
        case 0:
            list_idx = app_deviceData[current_idx].gpio1 ? 1 : 0;
            break;
        case 1:
            list_idx = app_deviceData[current_idx].gpio1 ? 3 : 2;
            break;
        case 2:
            list_idx = app_deviceData[current_idx].gpio1 ? 5 : 4;
            break;
        default:
            break;
    }

    UART1_Write(cmd_toggle_gpio1[list_idx], strlen(cmd_toggle_gpio1[list_idx]));

    if (app_deviceData[current_idx].gpio1)
    {
        SET_RELEASED_IMAGE(Screen0_BTNgpio1, (leImage*)&offcircle);
        SET_PRESSED_IMAGE(Screen0_BTNgpio1, (leImage*)&oncircle);
        app_deviceData[current_idx].gpio1 = false;
    }
    else
    {
        SET_RELEASED_IMAGE(Screen0_BTNgpio1, (leImage*)&oncircle);
        SET_PRESSED_IMAGE(Screen0_BTNgpio1, (leImage*)&offcircle);
        app_deviceData[current_idx].gpio1 = true;
    }
}

void event_Screen0_BTNgpio2_OnPressed(leButtonWidget* btn)
{
    int32_t list_idx = 0;
    switch (current_idx)
    {
        case 0:
            list_idx = app_deviceData[current_idx].gpio2 ? 1 : 0;
            break;
        case 1:
            list_idx = app_deviceData[current_idx].gpio2 ? 3 : 2;
            break;
        case 2:
            list_idx = app_deviceData[current_idx].gpio2 ? 5 : 4;
            break;
        default:
            break;
    }

    UART1_Write(cmd_toggle_gpio2[list_idx], strlen(cmd_toggle_gpio2[list_idx]));

    if (app_deviceData[current_idx].gpio2)
    {
        SET_RELEASED_IMAGE(Screen0_BTNgpio2, (leImage*)&offcircle);
        SET_PRESSED_IMAGE(Screen0_BTNgpio2, (leImage*)&oncircle);
        app_deviceData[current_idx].gpio2 = false;
    }
    else
    {
        SET_RELEASED_IMAGE(Screen0_BTNgpio2, (leImage*)&oncircle);
        SET_PRESSED_IMAGE(Screen0_BTNgpio2, (leImage*)&offcircle);
        app_deviceData[current_idx].gpio2 = true;
    }
}

void event_Screen0_BTNhome_OnPressed(leButtonWidget* btn)
{

}

void event_Screen0_BTNhome_OnReleased(leButtonWidget* btn)
{
    legato_showScreen(1);
}

void Screen0_OnShow(void)
{
    current_screen = 0;
    leFixedString_Constructor(&dynamicTemp, dynamicTempCharBuff, APP_STR_SIZE);
    dynamicTemp.fn->setFont(&dynamicTemp, (leFont*)&NotoSans_Regular);
    leFixedString_Constructor(&dynamicRSSI, dynamicRSSICharBuff, APP_STR_SIZE);
    dynamicRSSI.fn->setFont(&dynamicRSSI, (leFont*)&NotoSans_Regular);
    switch (current_idx)
    {
        case 0:
            SET_STRING(Screen0_LbDev, (leString*)&string_device);
            break;
        case 1:
            SET_STRING(Screen0_LbDev, (leString*)&string_Device2);
            break;
        case 2:
            SET_STRING(Screen0_LbDev, (leString*)&string_Device3);
            break;
        default:
            break;
    }
    show_screen0_updating();
}

void Screen0_OnHide(void)
{
    current_screen = -1;
    dynamicTemp.fn->destructor(&dynamicTemp);
    dynamicRSSI.fn->destructor(&dynamicRSSI);
}

void Screen1_OnShow(void)
{
    Screen1_ListWheelWidget_0->fn->setSelectedItem(Screen1_ListWheelWidget_0, current_idx);
    current_screen = 1;
    show_screen1_updating();
}

void Screen1_OnHide(void)
{
    current_screen = -1;
}

void event_Screen1_btnChoose_OnPressed(leButtonWidget* btn)
{

}

void event_Screen1_btnChoose_OnReleased(leButtonWidget* btn)
{
    if (app_deviceData[current_idx].online)
    {
        legato_showScreen(0);
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary local functions.
*/
static bool find_empty_dev(int32_t* id)
{
    int32_t i;
    for (i=0; i<APP_DEV_NUM; i++)
    {
        //printf("empty devSN[%d]: %s\n", i, app_deviceData[i].sn);
        if (app_deviceData[i].sn[0] == 0)
        {
            *id = i;
            return true;
        }
    }
    return false;
}

static bool find_dev_bySN(char* SN, int32_t* id)
{
    int32_t i;
    //printf("find SN:%s\n", SN);
    for (i=0; i<APP_DEV_NUM; i++)
    {
        //printf("devSN[%d]: %s\n", i, app_deviceData[i].sn);
        if (!strncmp(app_deviceData[i].sn, SN, LEN_RPT_DATA-1))
        {
            *id = i;
            return true;
        }
    }
    return false;
}

static void add_device(char* sn, int32_t idx)
{
    memcpy(app_deviceData[idx].sn, sn, LEN_RPT_DATA-1);
    app_deviceData[idx].sn[LEN_RPT_DATA-1] = '\0';
}

static void rm_device(int32_t idx)
{
    memset(app_deviceData[idx].sn, 0, LEN_RPT_DATA);
}

/* Connect message format:
** Data from R30: conn 0 1 ed0937feff19276a
** conn: connect; 0: sensor id; 1: online(0:offline); ed093*: serial number
*/
static void conn_device(char* buf)
{
    int32_t idx = 0;
    bool is_disconnected = false;
    char sn[LEN_RPT_DATA] = {0};
    memcpy(sn, &buf[9], LEN_RPT_DATA-1);
    sn[LEN_RPT_DATA-1] = '\0';

    /* find if this device in the list */
    if (find_dev_bySN(sn, &idx))
    {
        if (buf[7] == '1')
        {
            app_deviceData[idx].online = true;
        }
        else
        {
            app_deviceData[idx].online = false;
            rm_device(idx);
            is_disconnected = true;
        }
    }
    else /* this device is not in list, add to new */
    {
        if (buf[7] == '1')
        {
            if (find_empty_dev(&idx))
            {
                add_device(sn, idx);
                app_deviceData[idx].online = true;
            }
            else
            {
                add_device(sn, APP_DEV_NUM-1);
                app_deviceData[APP_DEV_NUM-1].online = true;
            }
        }
        else
        {
            printf("ERROR, should not run to here:%s[%d]\n", __func__, __LINE__);
        }
    }

    /* if current device is disconnected, screen should be back to home page */
    if (is_disconnected)
    {
        if ((idx == current_idx) && (0 == current_screen))
        {
            legato_showScreen(1);
        }
    }

    /* if report is current device and in screen1, then udpate screen1 */
    if ((idx == current_idx) && (1 == current_screen))
    {
        show_screen1_updating();
    }
}

static void convert_2_db(char* str, char* outdb)
{
    if (NULL == outdb)
    {
        printf("convert_2_db outdb is NULL\n");
        return;
    }
    int32_t rssi = strtol(str,NULL,16);
    int32_t dec = 0xff & rssi;
    dec = (~dec & 0xff) + 1;
    sprintf(outdb, "-%i", dec);
}

/* Update message format:
** Data from R30: recv 00 b6 2be637feff19276a TEMP 25.8
** recv: receive; 00: reserved; b6: RSSI; 2be63*: serial number; TEMP 25.8: 25.8℃
*/
static void update_device(char* buf)
{
    int32_t idx = 0;
    char rssi[3] = {0};
    char rssistr[LEN_RPT_DATA] = {0};
    char sn[LEN_RPT_DATA] = {0};
    char temp[LEN_RPT_DATA] = {0};

    /* parse SN value from msg */
    memcpy(sn, &buf[11], LEN_RPT_DATA-1);
    sn[LEN_RPT_DATA-1] = '\0';

    /* find the device by SN in list */
    if (!find_dev_bySN(sn, &idx))
    {
        printf("recv SN not found in list!!!ERROR\n");
        return;
    }

    /* set online flag */
    app_deviceData[idx].online = true;

    /* parse RSSI value from msg */
    memcpy(rssi, &buf[8], 2);
    rssi[2] = '\0';
    convert_2_db(rssi, rssistr);
    strncpy(app_deviceData[idx].rssi, rssistr, LEN_RPT_DATA);

    /* parse temperature value from msg */
    memcpy(temp, &buf[33], LEN_RPT_DATA-1);
    temp[LEN_RPT_DATA-1] = '\0';
    strncpy(app_deviceData[idx].temp, temp, LEN_RPT_DATA);

    if ((idx == current_idx) && (0 == current_screen))
    {
        show_screen0_updating();
    }
}

bool Handle_R30_MSG(char* buf)
{
    printf(">>>read: %s\n", buf);
    if (!strncmp(buf, "AOK", 3))
    {
        //success
        return true;
    }
    else if (!strncmp(buf, "ERR", 3))
    {
        printf("!!!R30 report error: %s\n", buf);
    }
    else if (!strncmp(buf, "conn", 4))
    {
        if (LEN_CONN_MSG <= strlen(buf))
        {
            conn_device(buf);
        }
    }
    else if (!strncmp(buf, "recv", 4))
    {
        if (LEN_RECV_MSG <= strlen(buf))
        {
            update_device(buf);
        }
    }
    else if (!strncmp(buf, "Reboot", 6))
    {
        app_roundData.state = APP_ROUND_STATE_INIT;
    }
    else
    {
        //unkown message
        printf("Unkown message: %s\n", buf);
    }
    return false;
}

void Read_UART1_Data_Task(void)
{
    if(errorStatus == true)
    {
        errorStatus = false;
        printf("%s%d\n", messageError, uart_err);
        memset(receiveBuffer, 0, RX_BUFFER_SIZE);
        UART1_Read(receiveBuffer, RX_BUFFER_SIZE);
    }
    else if(readStatus == true)
    {
        readStatus = false;
        memcpy(localBuffer, receiveBuffer, RX_BUFFER_SIZE);
        Handle_R30_MSG(localBuffer);
        memset(receiveBuffer, 0, RX_BUFFER_SIZE);
        UART1_Read(receiveBuffer, RX_BUFFER_SIZE);
    }
    else
    {
        ;
    }
}

void UART1_Init(void)
{
    /* Pull the Reset of R30 module */
    GPIO_RH3_Set();

    /* Register callback functions */
    UART1_ReadCallbackRegister(APP_ReadCallback, 0);

    /* UART1_Read will reset uart2Obj.rxProcessedSize=0, then the callback will work */
    memset(receiveBuffer, 0, RX_BUFFER_SIZE);
    UART1_Read(receiveBuffer, RX_BUFFER_SIZE);
}

void APP_Screen_Constructor(void)
{
    int32_t i;
    for (i=0; i<APP_DEV_NUM; i++)
    {
        strncpy(app_deviceData[i].temp, "N/A", LEN_RPT_DATA);
        strncpy(app_deviceData[i].rssi, "N/A", LEN_RPT_DATA);
        app_deviceData[i].led = true;
        app_deviceData[i].gpio1 = true;
        app_deviceData[i].gpio2 = true;
    }
}
// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_ROUND_Initialize ( void )

  Remarks:
    See prototype in app_round.h.
 */

void APP_ROUND_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app_roundData.state = APP_ROUND_STATE_INIT;

    APP_Screen_Constructor();

    /* Initialize R30 module, first of all, set GPIO RH3 to reset chip. Secondly,
     * set parameters of power sequence of R30 by UART1*/
    UART1_Init();

    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}


/******************************************************************************
  Function:
    void APP_ROUND_Tasks ( void )

  Remarks:
    See prototype in app_round.h.
 */

void APP_ROUND_Tasks ( void )
{
    static int32_t sentidx = -1;
    /* Check the application's current state. */
    switch ( app_roundData.state )
    {
        /* Application's initial state. */
        case APP_ROUND_STATE_INIT:
        {
            sendidx = 0;
            sentidx = -1;
            app_roundData.state = APP_ROUND_STATE_R30INITREQ_TASKS;
            break;
        }

        case APP_ROUND_STATE_SERVICE_TASKS:
        {

            break;
        }

        case APP_ROUND_STATE_R30INITREQ_TASKS:
        {
            if (sentidx != sendidx)
            {
                UART1_Write(cmd_list[sendidx], strlen(cmd_list[sendidx]));
                sentidx = sendidx;
            }

            break;
        }

        case APP_ROUND_STATE_R30INITRSP_TASKS:
        {
            readStatus = false;
            memcpy(localBuffer, receiveBuffer, RX_BUFFER_SIZE);
            memset(receiveBuffer, 0, RX_BUFFER_SIZE);
            UART1_Read(receiveBuffer, RX_BUFFER_SIZE);
            if (Handle_R30_MSG(localBuffer))
            {
                sendidx++;
                if (sendidx >= sizeof(cmd_list)/sizeof(cmd_list[0]))
                {
                    R30InitOK = true;
                    app_roundData.state = APP_ROUND_STATE_UART1_TASKS;
                }
                else
                {
                    app_roundData.state = APP_ROUND_STATE_R30INITREQ_TASKS;
                }
            }
            else
            {
                if (app_roundData.state != APP_ROUND_STATE_INIT)
                {
                    printf("R30 INIT failed\n");
                    app_roundData.state = APP_ROUND_STATE_SERVICE_TASKS;
                }
            }

            break;
        }

        case APP_ROUND_STATE_UART1_TASKS:
        {
            Read_UART1_Data_Task();
            break;
        }
        /* TODO: implement your application state machine.*/


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
