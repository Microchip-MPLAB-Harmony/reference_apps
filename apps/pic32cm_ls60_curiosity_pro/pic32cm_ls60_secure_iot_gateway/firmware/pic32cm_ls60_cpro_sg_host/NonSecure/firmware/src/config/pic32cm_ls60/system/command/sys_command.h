/*******************************************************************************
  Command Processor System Service Interface Definition

  Company:
    Microchip Technology Inc.

  File Name:
    sys_command.h

  Summary:
    Command Processor System Service interface definition.

  Description:
    This file contains the interface definition for the Command Processor System
    Service.  It provides a way to interact with the Command Processor subsystem
    to manage the ASCII command requests from the user supported by the system.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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

#ifndef SYS_COMMAND_H
#define SYS_COMMAND_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include "configuration.h"
#include "system/system.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: SYS CMD Data Types and Definitions
// *****************************************************************************
// *****************************************************************************

//SYS_CMD_BUFFER_DMA_READY is defined in configuration.h by MHC, this is here in-case MHC is not used
#ifndef SYS_CMD_BUFFER_DMA_READY
    #define SYS_CMD_BUFFER_DMA_READY //Define this for MX
    /* #define SYS_CMD_BUFFER_DMA_READY        __attribute__((coherent)) __attribute__((aligned(4))) */ //Define this for MZ
#endif

#ifndef SYS_COMMAND_INCLUDE_APIS
    #ifndef SYS_CMD_ENABLE

        #ifndef SYS_CMD_MESSAGE
            #define SYS_CMD_MESSAGE(message)
        #endif

        #ifndef SYS_CMD_PRINT
            #define SYS_CMD_PRINT(fmt, ...)
        #endif

    #endif
#endif

#ifndef SYS_CMD_ENABLE
    #define SYS_CMD_READY_TO_READ()
#endif

#ifndef SYS_CMD_DEVICE_MAX_INSTANCES
    #define SYS_CMD_DEVICE_MAX_INSTANCES            1
#endif


// *****************************************************************************
/* SYS CMD Processor Buffer Maximum Length

  Summary:
    Command Processor System Service Command Buffer Maximum Length definition.

  Description:
    This macro defines the maximum length of the command buffer.

  Remarks:
    None.

*/
#define     SYS_CMD_MAX_LENGTH  					80


// *****************************************************************************
/* SYS CMD Processor Read Buffer Size

  Summary:
    Command Processor System Service Read Buffer Size definition.

  Description:
    This macro defines the maximum size of the command buffer.

  Remarks:
    None

*/
#define         SYS_CMD_READ_BUFFER_SIZE 128


// *****************************************************************************
/* SYS CMD Processor Maximum Number of Command Group

  Summary:
    Command Processor System Service Maximum Number of Command Group definitions.

  Description:
    This macro defines the maximum number of command groups.

  Remarks:
    None.

*/
#define         MAX_CMD_GROUP   8


// *****************************************************************************
/* SYS CMD Processor Maximum Number of Command Arguments

  Summary:
    Command Processor System Service Maximum Number of Argument definitions.

  Description:
    This macro defines the maximum number of arguments per command.

  Remarks:
    None.

*/
#define         MAX_CMD_ARGS    8


// *****************************************************************************
/* SYS CMD Processor Command History Depth

  Summary:
    Command Processor System Service Maximum Depth of Command History.

  Description:
    This macro defines the maximum depth of the command history.

  Remarks:
    None.

*/
#define         COMMAND_HISTORY_DEPTH   4


// *****************************************************************************
/*
  Summary:
    Identifies a message function API.

  Description:
    Message function API. This handle identifies the interface structure of the
    message function API within the Command I/O encapsulation.

  Remarks:
    None.
*/
typedef void (*SYS_CMD_MSG_FNC)(const void* cmdIoParam, const char* str);


// *****************************************************************************
/*
  Summary:
    Identifies a print function API.

  Description:
    Print function API. This handle identifies the interface structure of the
    print function API within the Command I/O encapsulation.

  Remarks:
    None.
*/
typedef void (*SYS_CMD_PRINT_FNC)(const void* cmdIoParam, const char* format, ...);


// *****************************************************************************
/*
  Summary:
    Identifies a single character print function API.

  Description:
    Single Character Print function API. This handle identifies the interface
    structure of single character print function API within the Command I/O
    encapsulation.

  Remarks:
    None.
*/
typedef void (*SYS_CMD_PUTC_FNC)(const void* cmdIoParam, char c);


// *****************************************************************************
/*
  Summary:
    Identifies a data available function API.

  Description:
    Ready Status Check function API. This handle identifies the interface structure
    of the data available function API within the Command IO encapsulation.

    Returns the number of available characters that could be read

  Remarks:
    None.
*/
typedef int (*SYS_CMD_DATA_RDY_FNC)(const void* cmdIoParam);


// *****************************************************************************
/*
  Summary:
    Identifies a get single character function API.

  Description:
    Get Single Character function API. This handle identifies the interface structure
    of the get single character function API within the Command I/O encapsulation.

  Remarks:
    None.
*/
typedef char (*SYS_CMD_GETC_FNC)(const void* cmdIoParam);


// *****************************************************************************
/*
  Summary:
    Identifies a read single character function API.

  Description:
    Read Single Character function API

    This handle identifies the interface structure of read single character
    function API within the Command I/O encapsulation.

  Remarks:
    None.
*/
typedef size_t (*SYS_CMD_READC_FNC)(const void* cmdIoParam);


// *****************************************************************************
/* SYS CMD API structure

  Summary:
    Identifies the Command API structure.

  Description:
    This structure identifies the Command API structure.

  Remarks:
    None.
*/
typedef struct
{
    // Message function API
    SYS_CMD_MSG_FNC msg;

    // Print function API
    SYS_CMD_PRINT_FNC print;

    // Put single char function API
    SYS_CMD_PUTC_FNC  putc_t;

    // Data available API
    SYS_CMD_DATA_RDY_FNC isRdy;

    // Get single data API
    SYS_CMD_GETC_FNC getc_t;

} SYS_CMD_API;


// *****************************************************************************
/* SYS CMD EVENT structure

  Summary:
    Identifies the Command Event Types

  Description:
    This structure identifies the Command Event Types.

  Remarks:
    None
*/
typedef enum
{
    SYS_CMD_EVENT_WRITE_COMPLETE,

    SYS_CMD_EVENT_READ_COMPLETE,

} SYS_CMD_EVENT;


// *****************************************************************************
/* SYS CMD Console I/O Parameter

   Summary
    Defines whether the command module is single character or full command read

   Description
    This enumeration defines whether the command module is single character or
    full command read.

   Remarks:
    None
*/
typedef enum
{
    SYS_CMD_SINGLE_CHARACTER_READ_CONSOLE_IO_PARAM = 0,

} SYS_CMD_CONSOLE_IO_PARAM;


// *****************************************************************************
/* SYS CMD INIT structure

  Summary:
    Identifies the system command initialize structure.

  Description:
    This structure identifies the system command initialize structure.

  Remarks:
    None.
*/

typedef struct
{
    /* System module initialization */
    SYS_MODULE_INIT     moduleInit;

    uint8_t             consoleCmdIOParam;

    /* Console index to receive debug messages */
    SYS_MODULE_INDEX    consoleIndex;

} SYS_CMD_INIT;


// *****************************************************************************
/* SYS CMD Command Instance Node Structure

   Summary
    Defines the data structure to store each command instance.

   Description
    This data structure stores all the data relevant to a uniquely entered
    command instance.  It is a node for a linked list structure to support the
    Command Processor System Service's command history feature

   Remarks:
    None.
*/
typedef struct
{
    const SYS_CMD_API*  pCmdApi;    // Cmd IO APIs
    const void*         cmdIoParam; // channel specific parameter
} SYS_CMD_DEVICE_NODE;


// *****************************************************************************
// *****************************************************************************
// Section: SYS CMD External Interface Definitions
// *****************************************************************************
// *****************************************************************************

//************************************************************************
/*
  SYS CMD Command Function

  Summary:
    Identifies the command process function API.

  Description:
    Command Process Function API. This handle identifies the interface structure
    of the command process function API.

  Remarks:
    None
*/
typedef void (*SYS_CMD_FNC)(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char **argv);


// *****************************************************************************
/* SYS CMD Command Descriptor Structure

   Summary
    Defines the descriptor structure for a single command process.

   Description
    This data structure stores the information for a single unique command
    process.

   Remarks:
    None.
*/
typedef struct
{
    const char*     cmdStr;        // string identifying the command
    SYS_CMD_FNC     cmdFnc;        // function to execute for this command
    const char*     cmdDescr;      // simple command description

} SYS_CMD_DESCRIPTOR;              // a simple command descriptor


// *****************************************************************************
/*
  Summary:
    Defines a Command processing handle.

  Description:
    Definition of a command processing handle used for
    external processing registration by the Command clients.

  Remarks:
    None.
*/
typedef const void* SYS_CMD_HANDLE;


// *****************************************************************************
/*
  Summary:
    Command Callback Function

  Description:
    This is a Command Callback Function.
    It will be called before the command is processed.
    The caller can examine/modify the command buffer as needed.

  Parameters:
    pCmdTbl     - pointer to a command group that has been added with SYS_CMD_ADDGRP
    pCmdIO      - pointer to a SYS_CMD_DEVICE_NODE identifying the command channel
                  that has been added with SYS_CMDIO_ADD
    cmdBuff     - the buffer containing the current command to be processed
                  This buffer can be examined or modified as needed.
    buffSize    - the size of the cmdBuff, including the termination '\0' character.
    hParam      - a user parameter that's passed to the SYS_CMD_CallbackRegister() to be
                  used in the callback
                  Not used by the SYS_CMD.
         

  Returns:
    - true  - if the command has been completely processed by the external handler.
              The internal SYS_CM handler will then ignore the command.
    - false - the string in the cmdBuff neds to be parsed ad processed as usualy.


  Remarks:
    The command callback function belongs to a command group.
    Different groups can have different/same command callback function

    If updating the cmdBuff the caller should not exceed the buffSize!
    Please note that on return from the callback, the buffer is truncated:
    cmdBuff[buffSize - 1] = 0;

  Currently only one callback is supported for a SYS_CMD command group.
    The call will fail if a handler is already registered.
    Use SYS_CMD_CallbackDeregister first
    
*/
typedef bool (*SYS_CMD_Callback) (const SYS_CMD_DESCRIPTOR* pCmdTbl, SYS_CMD_DEVICE_NODE* pCmdIO, char* cmdBuff, size_t bufSize, void* hParam);

// *****************************************************************************
// *****************************************************************************
// Section: SYS CMD Operation Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    bool SYS_CMD_Initialize( const SYS_MODULE_INIT * const init  )

  Summary:
    Initializes data for the instance of the Command Processor module.

  Description:
    This function initializes the Command Processor module.
    It also initializes any internal data structures.

  Precondition:
    None.

  Parameters:
    init            - Pointer to a data structure containing any data necessary
                      to initialize the sys command. This pointer may be null if no
                      data is required because static overrides have been
                      provided.

  Returns:
    - true  - Indicates success
    - false - Indicates an error occurred

  Remarks:
    This routine should only be called once during system initialization.
*/
bool SYS_CMD_Initialize(const SYS_MODULE_INIT * const init );


// *****************************************************************************
/* Function:
    bool SYS_CMD_ADDGRP(const SYS_CMD_DESCRIPTOR* pCmdTbl, int nCmds,
                            const char* groupName,
                            const char* menuStr)

  Summary:
    Allows clients to add command process to the Command Processor System
    Service.

  Description:
    Client modules may call this function to add command process to the Command
    Processor System Service.

  Precondition:
    SYS_CMD_Initialize was successfully run once.

  Parameters:
    None.

  Example:

    static const SYS_CMD_DESCRIPTOR    cmdTbl[]=
    {
        {"command_as_typed_at_the_prompt",
        _Function_Name_That_Supports_The_Command,
        ": Helpful description of the command for the user"},
    };

    bool APP_AddCommandFunction()
    {
        if (!SYS_CMD_ADDGRP(cmdTbl, sizeof(cmdTbl)/sizeof(*cmdTbl),
                        "Command Group Name", ": Command Group Description"))
        {
            return false;
        }
        return true;
    }

  Returns:
    - true  - Indicates success
    - false - Indicates an error occurred

  Remarks:
    None.
*/
bool    SYS_CMD_ADDGRP(const SYS_CMD_DESCRIPTOR* pCmdTbl, int nCmds, const char* groupName, const char* menuStr);

// *****************************************************************************
/* Function:
    bool SYS_CMD_READY_TO_READ( void )

  Summary:
    Allows upper layer application to confirm that the command
    module is ready to accept command input

  Description:
    This function allows upper layer application to confirm that the command
    module is ready to accept command input

  Precondition:
    SYS_CMD_Initialize was successfully run once.

  Parameters:
    None.

  Returns:
    - true  - Indicates command module is ready
    - false - Indicates command module is not ready

  Remarks:
    None
*/
#ifdef SYS_CMD_ENABLE
bool    SYS_CMD_READY_TO_READ( void );
#endif

// *****************************************************************************
/* MISRA C-2012 Rule 8.6 deviated:1 Deviation record ID -  H3_MISRAC_2012_R_8_6_DR_1 */
/* Function:
    bool SYS_CMD_READY_TO_WRITE( void )

  Summary:
    Allows upper layer application to confirm that the command
    module is ready to write output to the Console System Service.

  Description:
    This function allows upper layer application to confirm that the command
    module is ready to write output to the Console System Service.

  Precondition:
    SYS_CMD_Initialize was successfully run once.

  Parameters:
    None.

  Returns:
    - true  - Indicates command module is ready
    - false - Indicates command module is not ready

  Remarks:
    None
*/
#ifdef SYS_CMD_ENABLE
bool    SYS_CMD_READY_TO_WRITE( void );
#endif

/* MISRAC 2012 deviation block end */
// *****************************************************************************
/* Function:
    bool SYS_CMD_Tasks( void )

  Summary:
    Maintains the Command Processor System Service's internal state machine.

  Description:
    This function is used to maintain the Command Processor System Service
    internal state machine.

  Precondition:
    SYS_CMD_Initialize was successfully run once.

  Parameters:
    None.

  Returns:
    - true  - Indicates success
    - false - Indicates an error occurred

  Remarks:
    None.
*/
#ifdef SYS_CMD_ENABLE
bool     SYS_CMD_Tasks(void);
#endif

// *****************************************************************************
/* Function:
    void SYS_CMD_MESSAGE (const char* message)

  Summary:
    Outputs a message to the Command Processor System Service console.

  Description:
    This function outputs a message to the Command Processor System Service
    console.

  Precondition:
    SYS_CMD_Initialize was successfully run once.

  Parameters:
    None.

  Returns:
    None.

  Remarks:
    None.
*/
#ifdef SYS_CMD_ENABLE
void    SYS_CMD_MESSAGE(const char* message);
#endif

// *****************************************************************************
/* Function:
    void SYS_CMD_PRINT(const char *format, ...)

  Summary:
    Outputs a printout to the Command Processor System Service console.

  Description:
    This function outputs a printout to the Command Processor System Service
    console.

  Precondition:
    SYS_CMD_Initialize was successfully run once.

  Parameters:
    None.

  Returns:
    None.

  Remarks:
    None.
*/
#ifdef SYS_CMD_ENABLE
void    SYS_CMD_PRINT(const char *format, ...);
#endif

// *****************************************************************************
/* Function:
    SYS_CMD_DEVICE_NODE* SYS_CMDIO_GET_HANDLE(short num)

  Summary:
    Gets the CMDIO Handle base via index.

  Description:
    This function returns the handle for the CMDIO when supplied with an index.

  Precondition:
    SYS_CMD_Initialize was successfully run once.

  Parameters:
    short num

  Returns:
    - SYS_CMD_DEVICE_NODE Handle for the CMDIO - Indicates success
    - NULL - Indicates not successful

  Remarks:
    None.
*/
#ifdef SYS_CMD_ENABLE
SYS_CMD_DEVICE_NODE* SYS_CMDIO_GET_HANDLE(short num);
#endif

// *****************************************************************************
/* Function:
    SYS_CMD_DEVICE_NODE* SYS_CMDIO_ADD(const SYS_CMD_API* opApi, const void* cmdIoParam,
                                       int unused)

  Summary:
    Adds CMDIO parameters to the Command Processor System Service console.

  Description:
    This function adds CMDIO Parameters to the Command Processor System Service
    console.

  Precondition:
    SYS_CMD_Initialize was successfully run once.

  Parameters:
    None.

  Returns:
    None.

  Remarks:
    None.
*/
#ifdef SYS_CMD_ENABLE
    SYS_CMD_DEVICE_NODE* SYS_CMDIO_ADD(const SYS_CMD_API* opApi, const void* cmdIoParam,
                                       int unused);
#endif

// *****************************************************************************
/* Function:
    bool SYS_CMD_DELETE(SYS_CMD_DEVICE_NODE* pDevNode);

  Summary:
    Removes CMDIO parameters from the Command Processor System Service console.

  Description:
    This function removes CMDIO parameters from the Command Processor System Service
    console.

  Precondition:
    SYS_CMD_Initialize was successfully run once.

  Parameters:
    None.

  Returns:
    True if rhe corresponding dommand device has been deleted
    False otherwise (no such node).

  Remarks:
    None.
*/
#ifdef SYS_CMD_ENABLE
bool SYS_CMD_DELETE(SYS_CMD_DEVICE_NODE* pDeviceNode);
#endif


// *****************************************************************************
/* Function:
    SYS_CMD_HANDLE  SYS_CMD_CallbackRegister(const SYS_CMD_DESCRIPTOR* pCmdTbl, SYS_CMD_Callback func, void* hParam);

  Summary:
    Sets a new SYS_CMD processing handler.

  Description:
    This function registers a new SYS_CMD callback processing handler.
    The caller can use the handler to be notified of incoming commands
    and given a chance to examine/modify/process them.

  Precondition:
    SYS_CMD properly initialized

  Parameters:
    pCmdTbl     - pointer to a command group to get a new process handler
                  The command group should have been added with SYS_CMD_ADDGRP
    func        - the SYS_CMD handler which will be called for an incoming command
    hParam      - a user parameter that's passed to the registered SYS_CMD_Callback function.
                  Not used by the SYS_CMD.

  Returns:
    - a valid SYS_CMD_HANDLE - if the operation succeeded
    - NULL - if the operation failed

  Example:
    <code>

    bool myCmdHandler(const SYS_CMD_DESCRIPTOR* pCmdTbl, SYS_CMD_DEVICE_NODE* pCmdIO, char* cmdBuff, size_t bufSize, void* hParam)
    {        
        return false;
    }

    SYS_CMD_HANDLE cmdHandle = SYS_CMD_CallbackRegister( myCmdGroup, myCmdHandler, 0);
    </code>

  Remarks:
    Currently only one callback function is supported for a SYS_CMD command group.
    The call will fail if a callback is already registered for the specified group.
    Use SYS_CMD_CallbackDeregister first

*/

SYS_CMD_HANDLE  SYS_CMD_CallbackRegister(const SYS_CMD_DESCRIPTOR* pCmdTbl, SYS_CMD_Callback func, void* hParam);

//*******************************************************************************
/*
  Function:
    bool    SYS_CMD_CallbackDeregister(SYS_CMD_HANDLE handle);

  Summary:
    Deregisters a previously registered callback handler.

  Description:
    This function removes a SYS_CMD processing handler.

  Precondition:
    SYS_CMD properly initialized

  Parameters:
    handle   - SYS_CMD_HANDLE obtained by a call to SYS_CMD_CallbackRegister


  Returns:
    - true  - if the operation succeeded
    - false - if the operation failed

  Example:
    <code>
    SYS_CMD_HANDLE myHandle = SYS_CMD_CallbackRegister(myCmdGroup, myCmdCallback, myParam );   
    SYS_CMD_CallbackDeregister(myHandle);
    </code>

  Remarks:
    None

*/

bool    SYS_CMD_CallbackDeregister(SYS_CMD_HANDLE handle);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus

    }

#endif
//DOM-IGNORE-END

#endif  /* SYS_COMMAND_H */
