/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_Initialize" and "APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

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

#ifndef _APP_H
#define _APP_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "definitions.h"                // SYS function prototypes

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

    
// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************
    
#define KEY_VERIFY                   1
#define SIGN_BUF_SIZE               64
#define PUB_KEY_BUF_SIZE            64
#define AES_TAG_SIZE                144

#define SECURE_TOKEN_SIZE           (SIGN_BUF_SIZE + PUB_KEY_BUF_SIZE + AES_TAG_SIZE)
#define SECURE_TOKEN_ADDR           ((uint32_t)&secure_token)

#define APP_IMAGE_START_ADDR        0xC000UL 


/* Definitions */
#define APP_IMAGE_SIZE                              sizeof(image_pattern)
#define APP_IMAGE_END_ADDR                          (APP_IMAGE_START_ADDR + APP_IMAGE_SIZE)
#define APP_PROTOCOL_HEADER_MAX_SIZE                4
#define LED_ON()                                    LED_Clear()
#define LED_OFF()                                   LED_Set()
#define SWITCH_GET()                                SWITCH_Get()
#define SWITCH_PRESSED                              0

#define CAN_DATA_FRAME_SIZE                         (64UL)
#define CAN_FILTER_ID                               0x45A

/* Standard identifier id[28:18]*/
#define WRITE_ID(id) (id << 18)
#define READ_ID(id)  (id >> 18)    
    
    
/*****************************************************************************/
/* Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/
    
typedef enum
{
    APP_STATE_INIT,
    APP_STATE_WAIT_SW_PRESS,
    APP_STATE_ENCRYPT_IMAGE,
    APP_STATE_SEND_UNLOCK_COMMAND,
    APP_STATE_WAIT_UNLOCK_COMMAND_TRANSFER_COMPLETE,
    APP_STATE_SEND_DATA_COMMAND,
    APP_STATE_WAIT_DATA_COMMAND_TRANSFER_COMPLETE,
    APP_STATE_SEND_VERIFY_COMMAND,
    APP_STATE_WAIT_VERIFY_COMMAND_TRANSFER_COMPLETE,
    APP_STATE_SEND_RESET_COMMAND,
    APP_STATE_WAIT_RESET_COMMAND_TRANSFER_COMPLETE,
    APP_STATE_SUCCESSFUL,
    APP_STATE_ERROR,
    APP_STATE_IDLE

} APP_STATES;


/*****************************************************************************/
/* Bootloader response

  Summary:
    Bootloader response enumeration
 */
enum
{
    BL_RESP_OK          = 0x50,
    BL_RESP_ERROR       = 0x51,
    BL_RESP_INVALID     = 0x52,
    BL_RESP_CRC_OK      = 0x53,
    BL_RESP_CRC_FAIL    = 0x54,
    BL_RESP_SEQ_ERROR   = 0x55
};

/*****************************************************************************/
/* Bootloader command

  Summary:
    Bootloader command enumeration
 */
typedef enum
{
    APP_BL_COMMAND_UNLOCK = 0xA0,
    APP_BL_COMMAND_DATA = 0xA1,
    APP_BL_COMMAND_VERIFY = 0xA2,
    APP_BL_COMMAND_RESET = 0xA3
}APP_BL_COMMAND;

/*****************************************************************************/
/* Transfer Status

  Summary:
    CAN application transfer status enumeration
 */
typedef enum
{
    APP_TRANSFER_STATUS_IN_PROGRESS,
    APP_TRANSFER_STATUS_SUCCESS,
    APP_TRANSFER_STATUS_ERROR,
    APP_TRANSFER_STATUS_IDLE,

} APP_TRANSFER_STATUS;

/*****************************************************************************/
/* Application data

  Summary:
    Holds Application data
 */
typedef struct
{
    APP_STATES                      state;
    volatile APP_TRANSFER_STATUS    trasnferStatus;
    uint32_t                        appMemStartAddr;
    uint32_t                        nBytesWritten;
    uint32_t                        nBytesSent;
    uint32_t                        nPendingBytes;
    uint8_t                         wrBuffer[CAN_DATA_FRAME_SIZE];
} APP_DATA;
    

/*****************************************************************************/
/* Security Token

  Summary:
    Structure for Signature and keys
 */

 typedef struct
{
    uint8_t signature[SIGN_BUF_SIZE];
    uint8_t pub_key[PUB_KEY_BUF_SIZE];
    uint8_t Aes_tag[AES_TAG_SIZE];
}__attribute__((packed)) SECURE_TOKEN;

/*****************************************************************************/
/* HSM SPI Configuration

  Summary:
      SPI Configuration for internal Hardware Security Module
 */
typedef struct
{
    uint8_t  select_pin; 
    uint32_t baud;
    void *   cfg_data;
    
}spi_config;


typedef bool (* spi_plib_read)( void * , size_t );
typedef bool (* spi_plib_write)( void *, size_t );
typedef bool (* spi_plib_is_busy)( void );
typedef void (* spi_plib_select)(uint32_t pin, bool value);

typedef struct plib_spi_api
{
    spi_plib_read              read;
    spi_plib_write             write;
    spi_plib_is_busy           is_busy;
    spi_plib_select            select;
} plib_spi_api_t;

    
// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Summary:
     Application initialization routine.

  Description:
    This function initializes the application.  It places the
    application in its initial state and prepares it to run so that its
    APP_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Initialize();
    </code>
*/

void APP_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_Tasks ( void )

  Summary:
    MPLAB Harmony Demo application tasks function

  Description:
    This routine is the Harmony Demo application's tasks function.  It
    defines the application's state machine and core logic.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP_Task( void );

/*******************************************************************************
  Function:
    void sercom2_select_pin ( void )

  Summary:
    Select pin for the internal HSM SPI connection

 */

void APP_SPI_SelectPin(uint32_t pin, bool value);


/*******************************************************************************
  Function:
    void APP_CheckBTLResponse ( void )

  Summary:
    Receive response from bootloader device
 
  Description:
    This function reads the CAN receive buffer and stores in rxFiFo0

 */
void APP_CheckBTLResponse(void);

/*******************************************************************************
  Function:
    uint32_t APP_ResetCommandSend(void)

  Summary:
    Data to reset bootloader device
 
  Description:
    This function populates the data buffer with command to reset the bootloader
    device

 */

uint32_t APP_ResetCommandSend(void);

/*******************************************************************************
  Function:
    uint32_t APP_UnlockCommandSend(uint32_t appStartAddr, uint32_t appSize)

  Summary:
    Data to unlock bootloader device
 
  Description:
    This function populates the data buffer with command to unlock the bootloader
    device

 */
uint32_t APP_UnlockCommandSend(uint32_t appStartAddr, uint32_t appSize);
        
/*******************************************************************************
  Function:
    uint32_t APP_ImageDataWrite(uint32_t memAddr, uint32_t nBytes)

  Summary:
    Writes Encrypted Application image
 
  Description:
    This function populates the data buffer with encrypted application image that 
    is to be sent to the bootloader device

 */        
uint32_t APP_ImageDataWrite(uint32_t memAddr, uint32_t nBytes);


/*******************************************************************************
  Function:
    uint32_t APP_TokenDataWrite(uint32_t memAddr, uint32_t nBytes)

  Summary:
    Writes Security token data
 
  Description:
    This function populates the data buffer with secure token data (signature and keys)

 */
uint32_t APP_TokenDataWrite(uint32_t memAddr, uint32_t nBytes);

/*******************************************************************************
  Function:
    void rx_message ( uint8_t numberOfMessage, CAN_RX_BUFFER *rxBuf, uint8_t rxBufLen )

  Summary:
    Read data received from bootloader device 
 
  Description:
    This function reads the CAN rx buffer and interprest the response from bootloader device

 */
void APP_RX_Message(uint8_t numberOfMessage, CAN_RX_BUFFER *rxBuf, uint8_t rxBufLen);

/*******************************************************************************
  Function:
    uint8_t CANDlcToLengthGet(uint8_t dlc)

  Summary:
    Converts Data length code to Message Length of CAN  
 
 */

uint8_t APP_CANDlcToLengthGet(uint8_t dlc);


/*******************************************************************************
  Function:
    uint8_t CANLengthToDlcGet(uint8_t length)

  Summary:
    Converts  Message Length of CAN to Data length
 
 */
uint8_t APP_CANLengthToDlcGet(uint8_t length);



#endif /* _APP_H */

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */