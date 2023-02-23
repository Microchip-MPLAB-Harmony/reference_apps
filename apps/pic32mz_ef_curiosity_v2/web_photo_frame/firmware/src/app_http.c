/*******************************************************************************
 * Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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

/*******************************************************************************
  HTTP Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_http.c

  Summary:
    

  Description:
    
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************



// application included files
#include "app_http.h"
#include "app_http_private.h"
#include "http_net_print.h"

#ifdef APP_DEBUG_MEMORY
#include "tcpip_heap_alloc.h"
#endif

#if defined(TCPIP_STACK_USE_HTTP_NET_SERVER)

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

// application data
static APP_HTTP_DATA appHttpData;

// http connections data
static APP_HTTP_CONNECTION_DATA httpConnSentData[TCPIP_HTTP_NET_MAX_CONNECTIONS] = {0};

// file that will be displayed on the web interface if the media request is invalid
#define APP_HTTP_404_NOT_FOUND "404_not_found"
#define APP_HTTP_404_NOT_FOUND_FILE_NAME "404_not_found.jpeg"

// pointer to media data
static APP_FILE_HANDLER_DATA* tempAppHttpFileData;

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Callback Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

// callback used to be called when the File System mounts/unmounts media
void APP_HTTP_SYS_FS_EventHandler(SYS_FS_EVENT event, void * eventData, uintptr_t context)
{
    switch (event)
    {
        case SYS_FS_EVENT_MOUNT:
        {
            if (memcmp((void*)eventData, (const void*)APP_SYS_FS_NVM_MOUNT_POINT, strlen((char*)APP_SYS_FS_NVM_MOUNT_POINT)) == 0)
            {
                SYS_CONSOLE_PRINT("SYS_Initialize: The %s File System is mounted from %s to %s\r\n", APP_SYS_FS_NVM_TYPE_STRING, APP_SYS_FS_NVM_VOL, APP_SYS_FS_NVM_MOUNT_POINT);

                appHttpData.webFSMounted = true;
            }
            break;
        }

        case SYS_FS_EVENT_UNMOUNT:
        {
            if (memcmp((void*)eventData, (const void*)APP_SYS_FS_NVM_MOUNT_POINT, strlen((char*)APP_SYS_FS_NVM_MOUNT_POINT)) == 0)
            {
                SYS_CONSOLE_PRINT("SYS_Initialize: The %s File System is unmounted\r\n", APP_SYS_FS_NVM_TYPE_STRING);

                appHttpData.webFSMounted = false;
            }
            break;
        }

        default:
        {
            // do nothing
            break;
        }
    }
}

// initializer of the application
void APP_HTTP_Initialize()
{
    // start from the init state
    appHttpData.state = APP_HTTP_TCPIP_INIT;

    // set the current index to an invalid value
    appHttpData.currentAppHttpFileIdx = APP_FileHandler_GetMaxNumberOfFiles();

    // add callback for mount and unmount of the nvm MPFS
    SYS_FS_EventHandlerSet(APP_HTTP_SYS_FS_EventHandler, (uintptr_t)NULL);

    // set the flag with the fact the file system where the web server is hosted was mounted
    appHttpData.webFSMounted = false;

    return;
}

// application state machine
void APP_HTTP_Tasks()
{
    SYS_STATUS tcpipStat;
    TCPIP_NET_HANDLE netH = NULL;
    int nNets;
    static IPV4_ADDR dwLastIP[2] = { {-1}, {-1} };
    IPV4_ADDR ipAddr = {0};
    int i;

    switch (appHttpData.state)
    {
        case APP_HTTP_TCPIP_INIT:
        {
            tcpipStat = TCPIP_STACK_Status(sysObj.tcpip);
            if (tcpipStat < 0)
            { // some error occurred
                SYS_CONSOLE_MESSAGE("APP: TCP/IP stack initialization failed!\r\n");

                // change the state
                appHttpData.state = APP_HTTP_TCPIP_ERROR;
            }

            if (tcpipStat == SYS_STATUS_READY)
            { // change the state
                appHttpData.state = APP_HTTP_START_WEB_SERVER;
            }
            break;
        }

        case APP_HTTP_START_WEB_SERVER:
        {
            if (appHttpData.webFSMounted == true)
            { // register the application HTTP processing
                HTTP_APP_Initialize();

                // change the state
                appHttpData.state = APP_HTTP_GOING_ON;
            }
            break;
        }

        case APP_HTTP_GOING_ON:
        {
            // if the IP address of an interface has changed
            // display the new value on the system console
            nNets = TCPIP_STACK_NumberOfNetworksGet();

            for (i = 0; i < nNets; i++)
            {
                netH = TCPIP_STACK_IndexToNet(i);
                if (!TCPIP_STACK_NetIsReady(netH))
                {
                    return; // interface not ready yet!
                }
                ipAddr.Val = TCPIP_STACK_NetAddress(netH);
                if (dwLastIP[i].Val != ipAddr.Val)
                {
                    dwLastIP[i].Val = ipAddr.Val;

                    SYS_CONSOLE_MESSAGE(TCPIP_STACK_NetNameGet(netH));
                    SYS_CONSOLE_MESSAGE(" IP Address: ");
                    SYS_CONSOLE_PRINT("%d.%d.%d.%d \r\n", ipAddr.v[0], ipAddr.v[1], ipAddr.v[2], ipAddr.v[3]);
                }
            }
            break;
        }

        case APP_HTTP_TCPIP_ERROR:
        {
            break;
        }

            // no default needed
            // the compiler should complain if a new value is added into the enum
    }

    // a bit of debugging
#ifdef APP_DEBUG_MEMORY
    static uint32_t debugDelayTick = 0;
    TCPIP_STACK_HEAP_HANDLE heapH;
    if (SYS_TMR_TickCountGet() - debugDelayTick >= SYS_TMR_TickCounterFrequencyGet() * APP_DEBUG_MEMORY_DELAY_SEC)
    {
        heapH = TCPIP_STACK_HeapHandleGet(TCPIP_STACK_HEAP_TYPE_INTERNAL_HEAP, 0);

        // SYS_CONSOLE_PRINT("    HEAP DEBUG: TCPIP Heap type: internal. Initial created heap size: %d Bytes\r\n", TCPIP_HEAP_Size(heapH));
        // SYS_CONSOLE_PRINT("    HEAP DEBUG: TCPIP Allocable block heap size: %d Bytes\r\n", TCPIP_HEAP_MaxSize(heapH));
        SYS_CONSOLE_PRINT("    HEAP DEBUG: TCPIP available heap size: %d Bytes, high watermark: %d\r\n", TCPIP_HEAP_FreeSize(heapH), TCPIP_HEAP_HighWatermark(heapH));
        // SYS_CONSOLE_PRINT("    HEAP DEBUG: TCPIP Last heap error: 0x%x\r\n", TCPIP_HEAP_LastError(heapH));

        // update the tick to current value
        debugDelayTick = SYS_TMR_TickCountGet();
    }
#endif
    return;
}

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

// gets from the file handler the requested picture to show up or down in the file list
static void _APP_HTTP_GetPictureToShow(APP_FILE_HANDLER_GET_DIRECTION nextPrev)
{
    // ask the file handler for the next picture
    tempAppHttpFileData = APP_FileHandler_GetPictureToShow(appHttpData.currentAppHttpFileIdx, nextPrev);

    // save the current index
    appHttpData.currentAppHttpFileIdx = tempAppHttpFileData->mediaFileIdx;

    return;
}

/****************************************************************************
  Section:
    Dynamic Variable Callback Functions
 ****************************************************************************/

// handler of the ~media_status~ dynamic variable
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_media_status(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt)
{
    HTTP_APP_DYNVAR_BUFFER *pDynBuffer = HTTP_APP_GetDynamicBuffer();
    if (pDynBuffer == 0)
    { // failed to get a buffer; retry
        return TCPIP_HTTP_DYN_PRINT_RES_AGAIN;
    }

    // decide what to say back function to media file handler
    if (APP_FileHandler_IsMediaMounted() == false)
    {
        strcpy(pDynBuffer->data, APP_HTTP_RESPONSE_MEDIA_UNMOUNTED);
    }
    else if (APP_FileHandler_GetNumberOfMediaFiles() == 0)
    {
        strcpy(pDynBuffer->data, APP_HTTP_RESPONSE_MEDIA_NOT_FOUND);
    }
    else
    {
        strcpy(pDynBuffer->data, APP_HTTP_RESPONSE_MEDIA_LOADED);
    }

    // write it to the dynamic var
    TCPIP_HTTP_NET_DynamicWrite(vDcpt, pDynBuffer->data, strlen(pDynBuffer->data), true);

    // done
    return TCPIP_HTTP_DYN_PRINT_RES_DONE;
}

// sends the name of the file when next picture is requested. 
// Fills the ~next_picture_file_name~ dynamic variable
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_get_picture_file_name(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt)
{
    const uint8_t* ptrDirection;

    APP_FILE_HANDLER_GET_DIRECTION direction = APP_FILE_HANDLER_GET_NEXT;

    HTTP_APP_DYNVAR_BUFFER *pDynBuffer = HTTP_APP_GetDynamicBuffer();

    if (pDynBuffer == 0)
    { // failed to get a buffer; retry
        return TCPIP_HTTP_DYN_PRINT_RES_AGAIN;
    }

    ptrDirection = TCPIP_HTTP_NET_ArgGet(TCPIP_HTTP_NET_ConnectionDataBufferGet(connHandle), (const uint8_t *)"direction");
    if (ptrDirection != NULL)
    {
        if (strstr((const char*)ptrDirection, "previous") != NULL)
        {
            direction = APP_FILE_HANDLER_GET_PREVIOUS;
        }
    }

    if (APP_FileHandler_GetNumberOfMediaFiles() != 0)
    {
        // prepare the picture data to be sent to the browser
        _APP_HTTP_GetPictureToShow(direction);

        // copy the file name to the buffer data
        strcpy(pDynBuffer->data, tempAppHttpFileData->mediaWebPath);
    }
    else
    {
        // copy the file name to the buffer data
        strcpy(pDynBuffer->data, APP_HTTP_404_NOT_FOUND);
    }

    // write it to the dynamic var
    TCPIP_HTTP_NET_DynamicWrite(vDcpt, pDynBuffer->data, strlen(pDynBuffer->data), true);

    // done
    return TCPIP_HTTP_DYN_PRINT_RES_DONE;
}

// reads the image file from the media nad sends it through buffers to the application
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_picture_content(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt)
{
    const uint8_t* ptrFileName;
    const uint8_t* ptrSeed;
    APP_FILE_HANDLER_DATA* appFileData;
    SYS_FS_HANDLE fileHandle;
    // received seed value as long
    uint32_t seedValue;
    // needed for strtol
    char *ptr;

    static HTTP_APP_DYNVAR_BUFFER *pDynBuffer;
    bool fileNotFound = false;

    // get the connection index
    uint32_t connIdx = TCPIP_HTTP_NET_ConnectionIndexGet(connHandle);
    // SYS_CONSOLE_PRINT("TCPIP_HTTP_Print_picture_content->connection: %d\r\n", connIdx);

    do {
        // if no media is inserted, just exit
        if (APP_FileHandler_IsMediaMounted() == 0)
        {
            // no files to show
            fileNotFound = true;

            break;
        }

        // if no media is available, just exit
        if (APP_FileHandler_GetNumberOfMediaFiles() == 0)
        {
            // no files to show
            fileNotFound = true;

            break;
        }

        // gets the seed from the request
        ptrSeed = TCPIP_HTTP_NET_ArgGet(TCPIP_HTTP_NET_ConnectionDataBufferGet(connHandle), (const uint8_t *)"seed");
        if (ptrSeed == NULL)
        {
            // seed not sent
            fileNotFound = true;

            break;
        }

        // get the requested image web path, this one is sent with the file http request in get
        ptrFileName = TCPIP_HTTP_NET_ArgGet(TCPIP_HTTP_NET_ConnectionDataBufferGet(connHandle), (const uint8_t *)"image");
        if (ptrFileName == NULL)
        {
            // file name not found
            fileNotFound = true;

            break;
        }

        // gets the picture by received file name
        appFileData = APP_FileHandler_GetPictureByWebName((char*)ptrFileName);
        if (appFileData == NULL)
        {
            // the file is not available the media
            fileNotFound = true;

            break;
        }

        fileHandle = SYS_FS_FileOpen(appFileData->mediaFullPath, SYS_FS_FILE_OPEN_READ);
        if (fileHandle == SYS_FS_HANDLE_INVALID)
        {
            // failed to open the file
            fileNotFound = true;

            break;
        }
    } while (false);

    // if the file was not found or the request invalid, show the file not found picture from flash
    if (fileNotFound == true)
    {
        // directly include the available 404 file from the web server - available all the time
        TCPIP_HTTP_NET_DynamicFileInclude(connHandle, vDcpt, APP_HTTP_404_NOT_FOUND_FILE_NAME);

        return TCPIP_HTTP_DYN_PRINT_RES_DONE;
    }

    size_t nChars;
    bool needToComeBack = true;

    // the seed is sent as an integer - convert it to integer
    seedValue = strtol((const char*)ptrSeed, &ptr, 10);

    // get the user data from the HTTP connection
    APP_HTTP_CONNECTION_DATA* userData = (APP_HTTP_CONNECTION_DATA*)TCPIP_HTTP_NET_ConnectionUserDataGet(connHandle);
    // validate it - the seed must be the same
    if (userData == NULL || userData->seed != seedValue)
    { // reset the connection data

        SYS_CONSOLE_PRINT("APP_HTTP: Loading image %s\r\n", appFileData->mediaFullPath);

        // SYS_CONSOLE_PRINT("New file request: %s. File size %d.\r\n", appFileData->mediaFullPath, SYS_FS_FileSize(fileHandle));

        // set bytes is 0
        httpConnSentData[connIdx].sentBytes = 0;

        // set the received seed
        httpConnSentData[connIdx].seed = seedValue;

        // set the connection data back into the http connection
        TCPIP_HTTP_NET_ConnectionUserDataSet(connHandle, &httpConnSentData[connIdx]);
    }

    // set the cursor inside the file to the position of he number of bytes sent already
    SYS_FS_FileSeek(fileHandle, httpConnSentData[connIdx].sentBytes, SYS_FS_SEEK_SET);

    // use all available buffers - configured in the http_net_print.h
    while ((pDynBuffer = HTTP_APP_GetDynamicBuffer()))
    {
        // read the data into the buffer
        nChars = SYS_FS_FileRead(fileHandle, pDynBuffer->data, pDynBuffer->bufferSize);

        // if the number of bytes read from the file is larger than 0,
        if (nChars > 0)
        {
            // ask to write the buffer to the TCP sockets
            TCPIP_HTTP_NET_DynamicWrite(vDcpt, pDynBuffer->data, nChars, true);

            // increment the connection data with the sent data
            httpConnSentData[connIdx].sentBytes += nChars;
        }

        // check if the file ended
        if (SYS_FS_FileEOF(fileHandle))
        {
            // the file ended, no need to come back
            needToComeBack = false;

            // break the while loop
            break;
        }
    }
    // close the file
    SYS_FS_FileClose(fileHandle);

    // some data has been sent, but not finished
    if (needToComeBack == true)
    {
        // need to come back
        return TCPIP_HTTP_DYN_PRINT_RES_PROCESS_AGAIN;
    }

    // SYS_CONSOLE_PRINT("Connection Handler bytes sent %d\r\n", httpConnSentData[connIdx]);

    // reset the connection sent data
    httpConnSentData[connIdx].sentBytes = 0;
    httpConnSentData[connIdx].seed = 0;

    // say done
    return TCPIP_HTTP_DYN_PRINT_RES_DONE;
}

/****************************************************************************
  Section:
    Customized HTTP NET Functions
 ****************************************************************************/

// processing the HTTP buffer acknowledgment
void TCPIP_HTTP_NET_DynAcknowledge(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const void *buffer, const struct _tag_TCPIP_HTTP_NET_USER_CALLBACK *pCBack)
{
    HTTP_APP_DYNVAR_BUFFER *pDynBuffer = (HTTP_APP_DYNVAR_BUFFER*)((const uint8_t *)buffer - offsetof(struct HTTP_APP_DYNVAR_BUFFER, data));

    pDynBuffer->busy = 0;
}

// processing the HTTP reported events
void TCPIP_HTTP_NET_EventReport(TCPIP_HTTP_NET_CONN_HANDLE connHandle, TCPIP_HTTP_NET_EVENT_TYPE evType, const void *evInfo, const struct _tag_TCPIP_HTTP_NET_USER_CALLBACK *pCBack)
{
    const char *evMsg = (const char *)evInfo;

    if (evType < 0)
    { // display errors only
        if (evMsg == 0)
        {
            evMsg = "none";
        }
        // SYS_CONSOLE_PRINT("HTTP event: %d, info: %s\r\n", evType, evMsg);
    }
    // SYS_CONSOLE_PRINT("HTTP event: %d, info: %s\r\n", evType, evMsg);
}

// example of processing an SSI notification
// return false for standard processing of this SSI command by the HTTP module
// return true if the processing is done by you and HTTP need take no further action
bool TCPIP_HTTP_NET_SSINotification(TCPIP_HTTP_NET_CONN_HANDLE connHandle, TCPIP_HTTP_SSI_NOTIFY_DCPT *pSSINotifyDcpt, const struct _tag_TCPIP_HTTP_NET_USER_CALLBACK *pCBack)
{
    static int newVarCount = 0;

    char *cmdStr, *varName;
    char newVarVal[] = "Page Visits: ";
    char scratchBuff[100];

    cmdStr = pSSINotifyDcpt->ssiCommand;

    if (strcmp(cmdStr, "include") == 0)
    { // here a standard SSI include directive is processed
        return false;
    }

    if (strcmp(cmdStr, "set") == 0)
    { // a SSI variable is set; let the standard processing take place
        return false;
    }

    if (strcmp(cmdStr, "echo") == 0)
    { // SSI echo command
        // inspect the variable name
        varName = pSSINotifyDcpt->pAttrDcpt->value;
        if (strcmp(varName, "myStrVar") == 0)
        { // change the value of this variable
            sprintf(scratchBuff, "%s%d", newVarVal, ++newVarCount);

            if (!TCPIP_HTTP_NET_SSIVariableSet(varName, TCPIP_HTTP_DYN_ARG_TYPE_STRING, scratchBuff, 0))
            {
                SYS_CONSOLE_MESSAGE("SSI set myStrVar failed!!!\r\n");
            }
            // else success
            return false;
        }
    }

    return false;
}


/****************************************************************************
  Section:
    GET Form Handlers
 ****************************************************************************/
/*****************************************************************************
  Function:
    TCPIP_HTTP_NET_IO_RESULT TCPIP_HTTP_NET_ConnectionGetExecute(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_NET_USER_CALLBACK *pCBack)

  Internal:
    See documentation in the TCP/IP Stack APIs or http_net.h for details.
 ****************************************************************************/
TCPIP_HTTP_NET_IO_RESULT TCPIP_HTTP_NET_ConnectionGetExecute(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_NET_USER_CALLBACK *pCBack)
{
    return TCPIP_HTTP_NET_IO_RES_DONE;
}


/****************************************************************************
  Section:
    POST Form Handlers
 ****************************************************************************/
#if defined(TCPIP_HTTP_NET_USE_POST)
/*****************************************************************************
  Function:
    TCPIP_HTTP_NET_IO_RESULT TCPIP_HTTP_NET_ConnectionPostExecute(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_NET_USER_CALLBACK *pCBack)

  Internal:
    See documentation in the TCP/IP Stack APIs or http_net.h for details.
 ****************************************************************************/
TCPIP_HTTP_NET_IO_RESULT TCPIP_HTTP_NET_ConnectionPostExecute(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_NET_USER_CALLBACK *pCBack)
{
    return TCPIP_HTTP_NET_IO_RES_DONE;
}

#endif

/****************************************************************************
  Section:
    Authorization Handlers
 ****************************************************************************/

/*****************************************************************************
  Function:
    uint8_t TCPIP_HTTP_NET_ConnectionFileAuthenticate(TCPIP_HTTP_NET_CONN_HANDLE connHandle, uint8_t *cFile, const TCPIP_HTTP_NET_USER_CALLBACK *pCBack)

  Internal:
    See documentation in the TCP/IP Stack APIs or http_net.h for details.
 ****************************************************************************/
#if defined(TCPIP_HTTP_NET_USE_AUTHENTICATION)
uint8_t TCPIP_HTTP_NET_ConnectionFileAuthenticate(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const char *cFile, const TCPIP_HTTP_NET_USER_CALLBACK *pCBack)
{
    return 0x80; // No authentication required
}
#endif

/*****************************************************************************
  Function:
    uint8_t TCPIP_HTTP_NET_ConnectionUserAuthenticate(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const char *cUser, const char *cPass, const TCPIP_HTTP_NET_USER_CALLBACK *pCBack)

  Internal:
    See documentation in the TCP/IP Stack APIs or http_net.h for details.
 ****************************************************************************/
#if defined(TCPIP_HTTP_NET_USE_AUTHENTICATION)
uint8_t TCPIP_HTTP_NET_ConnectionUserAuthenticate(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const char *cUser, const char *cPass, const TCPIP_HTTP_NET_USER_CALLBACK *pCBack)
{
    return 0x80; // We accept this combination
}
#endif

#endif
/* EOF */
