/*******************************************************************************
  MPLAB Harmony UART Live Update Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_live_update.c

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

#include "app_live_update.h"
#include "definitions.h"
#include <device.h>

#define BTL_TRIGGER_PATTERN (0x5048434DUL)

#define FLASH_START                     (0x9d000000UL)
#define FLASH_LENGTH                    (0x200000UL)
#define PAGE_SIZE                       (2048UL)
#define ERASE_BLOCK_SIZE                (16384UL)
#define PAGES_IN_ERASE_BLOCK            (ERASE_BLOCK_SIZE / PAGE_SIZE)

#define APP_START_ADDRESS               (PA_TO_KVA0(0x1d000000UL))

#define GUARD_OFFSET                    0
#define CMD_OFFSET                      2
#define ADDR_OFFSET                     0
#define SIZE_OFFSET                     1
#define DATA_OFFSET                     1
#define CRC_OFFSET                      0

#define CMD_SIZE                        1
#define GUARD_SIZE                      4
#define SIZE_SIZE                       4
#define OFFSET_SIZE                     4
#define CRC_SIZE                        4
#define HEADER_SIZE                     (GUARD_SIZE + SIZE_SIZE + CMD_SIZE)
#define DATA_SIZE                       ERASE_BLOCK_SIZE

#define WORDS(x)                        ((int)((x) / sizeof(uint32_t)))

#define OFFSET_ALIGN_MASK               (~ERASE_BLOCK_SIZE + 1)
#define SIZE_ALIGN_MASK                 (~PAGE_SIZE + 1)

#define LIVE_UPDATE_GUARD               (0x5048434DUL)

#define LOWER_FLASH_START               (FLASH_START)
#define LOWER_FLASH_SERIAL_START        (LOWER_FLASH_START + (FLASH_LENGTH / 2) - PAGE_SIZE)
#define LOWER_FLASH_SERIAL_SECTOR       (LOWER_FLASH_START + (FLASH_LENGTH / 2) - ERASE_BLOCK_SIZE)

#define UPPER_FLASH_START               (FLASH_START + (FLASH_LENGTH / 2))
#define UPPER_FLASH_SERIAL_START        (UPPER_FLASH_START + (FLASH_LENGTH / 2) - PAGE_SIZE)
#define UPPER_FLASH_SERIAL_SECTOR       (UPPER_FLASH_START + (FLASH_LENGTH / 2) - ERASE_BLOCK_SIZE)

#define FLASH_SERIAL_CHECKSUM_START     0xDEADBEEF
#define FLASH_SERIAL_CHECKSUM_END       0xBEEFDEAD
#define FLASH_SERIAL_CHECKSUM_CLR       0xFFFFFFFF

#define LOWER_FLASH_SERIAL_READ         ((APP_LIVE_UPDATE_FLASH_SERIAL *)KVA0_TO_KVA1(LOWER_FLASH_SERIAL_START))
#define UPPER_FLASH_SERIAL_READ         ((APP_LIVE_UPDATE_FLASH_SERIAL *)KVA0_TO_KVA1(UPPER_FLASH_SERIAL_START))

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
    This structure should be initialized by the APP_LIVE_UPDATE_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/
APP_LIVE_UPDATE_DATA app_live_update;

static uint32_t CACHE_ALIGN input_buffer[WORDS(OFFSET_SIZE + DATA_SIZE)];

static uint32_t CACHE_ALIGN flash_data[WORDS(DATA_SIZE)];

static uint32_t flash_addr          = 0;

static uint32_t unlock_begin        = 0;
static uint32_t unlock_end          = 0;

static bool upper_flash_serial_erased   = false;

APP_LIVE_UPDATE_FLASH_SERIAL CACHE_ALIGN  update_flash_serial;

static uint32_t *ramStart = (uint32_t *)BTL_TRIGGER_RAM_START;

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

/* Function to read the Serial number from Flash bank mapped to lower region */
static uint32_t get_LowerFlashSerial( void )
{
    APP_LIVE_UPDATE_FLASH_SERIAL *lower_flash_serial = LOWER_FLASH_SERIAL_READ;

    return (lower_flash_serial->serial);
}

/* Function to update the serial number based on address */
static void update_FlashSerial( uint32_t serial, uint32_t addr )
{
    update_flash_serial.serial          = serial;
    update_flash_serial.checksum_start  = FLASH_SERIAL_CHECKSUM_START;
    update_flash_serial.checksum_end    = FLASH_SERIAL_CHECKSUM_END;

    NVM_QuadWordWrite((uint32_t *)&update_flash_serial, addr);

    while(NVM_IsBusy() == true);
}

/* Function to update the serial number in upper flash panel (Inactive Panel) */
static void update_UpperFlashSerial( void )
{
    uint32_t upper_flash_serial;

    /* Increment Upper Mapped Flash panel serial by 1 to be ahead of the
     * current running Lower Mapped Flash panel serial
     */
    upper_flash_serial = get_LowerFlashSerial() + 1;

    /* Check if the Serial sector was erased during programming */
    if (upper_flash_serial_erased == false)
    {
        /* Erase the Sector in which Flash Serial Resides */
        NVM_PageErase(UPPER_FLASH_SERIAL_SECTOR);

        /* Wait for erase to complete */
        while(NVM_IsBusy() == true);
    }
    else
    {
        upper_flash_serial_erased = false;
    }

    update_FlashSerial(upper_flash_serial, UPPER_FLASH_SERIAL_START);
}

/* Function to Send the response command to the Host */
static void send_Response( T_APP_LIVE_UPDATE_RESP sendResp )
{
    UART2_Write((uint8_t*)&sendResp, sizeof(sendResp));
    /* Wait for all bytes to be transmitted out */
    while (UART2_WriteCountGet() != 0);
}

/* Function to Generate CRC by reading the firmware programmed into internal flash */
static uint32_t crc_Generate(void)
{
    uint32_t   i, j, value;
    uint32_t   crc_tab[256];
    uint32_t   size    = unlock_end - unlock_begin;
    uint32_t   crc     = 0xffffffff;
    uint8_t    data;

    for (i = 0; i < 256; i++)
    {
        value = i;

        for (j = 0; j < 8; j++)
        {
            if (value & 1)
            {
                value = (value >> 1) ^ 0xEDB88320;
            }
            else
            {
                value >>= 1;
            }
        }
        crc_tab[i] = value;
    }

    for (i = 0; i < size; i++)
    {
        data = *(uint8_t *)KVA0_TO_KVA1((unlock_begin + i));

        crc = crc_tab[(crc ^ data) & 0xff] ^ (crc >> 8);
    }
    return crc;
}

/* Function to process the received command */
static T_APP_LIVE_UPDATE_STATUS command_Task( uint8_t command )
{
    uint32_t i;
    T_APP_LIVE_UPDATE_STATUS command_status = APP_LIVE_UPDATE_STATUS_ERROR;

    if (APP_LIVE_UPDATE_CMD_UNLOCK == command)
    {
        uint32_t begin  = (input_buffer[ADDR_OFFSET] & OFFSET_ALIGN_MASK);

        uint32_t end    = begin + (input_buffer[SIZE_OFFSET] & SIZE_ALIGN_MASK);

        if (end > begin && end <= (FLASH_START + FLASH_LENGTH))
        {
            unlock_begin = begin;
            unlock_end = end;

            send_Response(APP_LIVE_UPDATE_RESP_OK);
            command_status = APP_LIVE_UPDATE_STATUS_UNLOCK;
        }
        else
        {
            unlock_begin = 0;
            unlock_end = 0;

            send_Response(APP_LIVE_UPDATE_RESP_ERROR);
            command_status = APP_LIVE_UPDATE_STATUS_ERROR;
        }
    }
    else if (APP_LIVE_UPDATE_CMD_DATA == command)
    {
        flash_addr = (input_buffer[ADDR_OFFSET] & OFFSET_ALIGN_MASK);

        if (unlock_begin <= flash_addr && flash_addr < unlock_end)
        {
            for (i = 0; i < WORDS(DATA_SIZE); i++)
                flash_data[i] = input_buffer[i + DATA_OFFSET];

            command_status = APP_LIVE_UPDATE_STATUS_READY_FOR_FLASH;
        }
        else
        {
            command_status = APP_LIVE_UPDATE_STATUS_ERROR;
            send_Response(APP_LIVE_UPDATE_RESP_ERROR);
        }
    }
    else if (APP_LIVE_UPDATE_CMD_VERIFY == command)
    {
        uint32_t crc        = input_buffer[CRC_OFFSET];
        uint32_t crc_gen    = 0;

        crc_gen = crc_Generate();

        if (crc == crc_gen)
        {
            send_Response(APP_LIVE_UPDATE_RESP_CRC_OK);
            command_status = APP_LIVE_UPDATE_STATUS_VERIFY;
        }
        else
        {
            send_Response(APP_LIVE_UPDATE_RESP_CRC_FAIL);
            command_status = APP_LIVE_UPDATE_STATUS_ERROR;
        }
    }
    else if (APP_LIVE_UPDATE_CMD_BKSWAP == command)
    {
        update_UpperFlashSerial();

        send_Response(APP_LIVE_UPDATE_RESP_OK);

        command_status = APP_LIVE_UPDATE_STATUS_SWAP_BANK;
    }
    else
    {
        send_Response(APP_LIVE_UPDATE_RESP_INVALID);
        command_status = APP_LIVE_UPDATE_STATUS_ERROR;
    }

    app_live_update.packet_received = false;
    return command_status;
}

/* Function to program received application firmware data into internal flash */
static T_APP_LIVE_UPDATE_STATUS flash_Task( void )
{
    uint32_t addr                           = flash_addr;
    uint32_t page                           = 0;
    uint32_t write_idx                      = 0;
    T_APP_LIVE_UPDATE_STATUS flash_status    = APP_LIVE_UPDATE_STATUS_ERROR;

    if (addr == LOWER_FLASH_SERIAL_SECTOR)
    {
        /* Send error response if active Flash Panels (Lower Flash)
         * Serial Sector is being erased.
         */
        send_Response(APP_LIVE_UPDATE_RESP_ERROR);

        flash_status = APP_LIVE_UPDATE_STATUS_ERROR;
    }
    else if (addr == UPPER_FLASH_SERIAL_SECTOR)
    {
        upper_flash_serial_erased   = true;
    }

    /* Erase the Current sector */
    NVM_PageErase(addr);

    /* Wait for erase to complete */
    while(NVM_IsBusy() == true);

    for (page = 0; page < PAGES_IN_ERASE_BLOCK; page++)
    {
        NVM_RowWrite(&flash_data[write_idx], addr);

        while(NVM_IsBusy() == true);

        addr += PAGE_SIZE;
        write_idx += WORDS(PAGE_SIZE);
    }

    send_Response(APP_LIVE_UPDATE_RESP_OK);

    flash_status = APP_LIVE_UPDATE_STATUS_FLASH_SUCCESS;

    return flash_status;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************
void usart_ReadEventHandler( UART_EVENT event, uintptr_t context )
{
    static uint32_t bytes_read      = 0;
    static uint32_t ptr             = 0;
    static uint32_t size            = 0;
    static bool header_received     = false;

    uint8_t input_data              = 0;
    uint8_t guard_byte              = 0;
    uint8_t *byte_buf               = (uint8_t *)&input_buffer[0];

    if(event == UART_EVENT_READ_ERROR)
    {
        if(UART2_ErrorGet() != UART_ERROR_NONE)
        {
            /* ErrorGet clears errors, set error flag to notify to the application */
            app_live_update.error_status = true;
        }
    }
    else
    {
        /* Receive data from HOST-PC. */
        bytes_read += UART2_Read((uint8_t*)&input_data, sizeof(input_data));

        /* Check if 100 ms have elapsed */
        if (CORETIMER_CompareHasExpired())
        {
            header_received = false;
        }

        /* Check whether the header is received. If yes check for valid guard
         * before processing the data.
         */
        if (header_received == false)
        {
            byte_buf[ptr++] = input_data;

            /* If the first byte does not match with guard ignore the request
             * and process when a valid byte is received.
             */
            if (app_live_update.guard_byte_check == false)
            {
                guard_byte = (uint8_t)input_buffer[GUARD_OFFSET];

                if (guard_byte != (uint8_t)LIVE_UPDATE_GUARD)
                {
                    app_live_update.guard_received      = false;
                    app_live_update.guard_byte_check    = false;
                    ptr                                 = 0;    // reset pointer to beginning to read valid data
                }
                else
                {
                    app_live_update.guard_byte_check    = true;
                }
            }
            else if (ptr == GUARD_SIZE)
            {
                if (input_buffer[GUARD_OFFSET] != LIVE_UPDATE_GUARD)
                {
                    app_live_update.guard_match = false;
                    ptr                         = 0;
                }
                else
                {
                    app_live_update.guard_match = true;
                }

				app_live_update.guard_received  = true;
            }
            else if (ptr == HEADER_SIZE)
            {
                header_received                = true;
                size                           = input_buffer[SIZE_OFFSET];
                app_live_update.guard_match    = true;
                app_live_update.input_command  = (uint8_t)input_buffer[CMD_OFFSET];

                ptr                            = 0;
                
            }
        }
        else if (header_received == true)
        {
            if (ptr < size)
            {
                byte_buf[ptr++] = input_data;
            }

            if (ptr == size)
            {
                ptr                              = 0;
                header_received                  = false;
                size                             = 0;
                app_live_update.packet_received  = true;
            }
        }

        CORETIMER_Start();
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************
/*******************************************************************************
  Function:
    void APP_LIVE_UPDATE_Initialize ( void )

  Remarks:
    See prototype in app_live_update.h.
 */

void APP_LIVE_UPDATE_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app_live_update.state               = APP_LIVE_UPDATE_STATE_INIT;
    app_live_update.error_status        = false;
    app_live_update.guard_byte_check    = false;
    app_live_update.guard_match         = false;
    app_live_update.packet_received     = false;
    app_live_update.guard_received      = false;
}

/* Function to process the commands and program received application firmware data into internal flash */
T_APP_LIVE_UPDATE_STATUS APP_LIVE_UPDATE_ServiceTasks( void )
{
    T_APP_LIVE_UPDATE_STATUS status = APP_LIVE_UPDATE_STATUS_ERROR;

    status = command_Task(app_live_update.input_command);

    if (status == APP_LIVE_UPDATE_STATUS_READY_FOR_FLASH)
    {
        status = flash_Task();
    }

    return status;
}

/******************************************************************************
  Function:
    void APP_LIVE_UPDATE_Tasks ( void )

  Remarks:
    See prototype in app_live_update.h.
 */

void APP_LIVE_UPDATE_Tasks ( void )
{
    static T_APP_LIVE_UPDATE_STATUS resp = APP_LIVE_UPDATE_STATUS_ERROR;

    /* Check the application's current state. */
    switch ( app_live_update.state )
    {
        /* Application's initial state. */
        case APP_LIVE_UPDATE_STATE_INIT:
        {
            CORETIMER_CompareSet(TIMER_COMPARE_VALUE);

            /* Register a callback for read events */
            UART2_ReadCallbackRegister(usart_ReadEventHandler, (uintptr_t) NULL);

            /* Receive a callback for each character */
            UART2_ReadThresholdSet(1);

            /* Enable RX event notifications */
            UART2_ReadNotificationEnable(true, true);

            app_live_update.state = APP_LIVE_UPDATE_STATE_SERVICE_TASKS;

            break;
        }

        /* Live Update Service Routine. */
        case APP_LIVE_UPDATE_STATE_SERVICE_TASKS:
        {
            if (app_live_update.error_status == true)
            {
                app_live_update.error_status = false;
                app_live_update.state        = APP_LIVE_UPDATE_STATE_ERROR;
            }
            else
            {
                if (app_live_update.guard_byte_check == true &&
                    app_live_update.guard_received   == true)
                {
                    if (app_live_update.guard_match == true)
                    {
                        if (app_live_update.packet_received == true)
                        {
                            resp = APP_LIVE_UPDATE_ServiceTasks();

                            app_live_update.guard_byte_check = false;

                            if (resp == APP_LIVE_UPDATE_STATUS_ERROR)
                            {
                                app_live_update.state = APP_LIVE_UPDATE_STATE_ERROR;
                            }
                            else if (resp == APP_LIVE_UPDATE_STATUS_SWAP_BANK)
                            {
                                app_live_update.state = APP_LIVE_UPDATE_STATE_SUCCESS;
                            }
                            else // Live Update is in progress.
                            {
                                app_live_update.state = APP_LIVE_UPDATE_STATE_SERVICE_TASKS;
                            }
                        }
                        else
                        {
                            /* Wait for receiving the complete packet. */
                            app_live_update.state = APP_LIVE_UPDATE_STATE_SERVICE_TASKS;
                        }
                    }
                    else
                    {
                        /* Send error response to HOST-PC. */
                        send_Response(APP_LIVE_UPDATE_RESP_ERROR);

                        /* Wrong guard received, send response and wait for a valid guard data. */
                        app_live_update.state = APP_LIVE_UPDATE_STATE_ERROR;
                    }
                }
                else if (resp == APP_LIVE_UPDATE_STATUS_SWAP_BANK)
                {
                    app_live_update.state = APP_LIVE_UPDATE_STATE_SUCCESS;
                }
            }

            break;
        }

        /* Get ready for next Live Update request. */
        case APP_LIVE_UPDATE_STATE_SUCCESS:
        {
            LED3_On();

            app_live_update.state = APP_LIVE_UPDATE_STATE_SERVICE_TASKS;
            break;
        }

        /* Live Update Failed. */
        case APP_LIVE_UPDATE_STATE_ERROR:
        {
            LED3_Toggle();

            app_live_update.guard_byte_check    = false;
            app_live_update.guard_received      = false;
            app_live_update.packet_received     = false;

            /* Press Switch 1 to enter to to trigger Bootloader. */
            if (SWITCH_GET() == SWITCH_PRESSED)
            {
                app_live_update.state = APP_LIVE_UPDATE_STATE_TRIGGER_SYS_RESET;
            }

            APP_TIMER_DelayMs(1000);

            break;
        }

        /* Trigger System Reset. */
        case APP_LIVE_UPDATE_STATE_TRIGGER_SYS_RESET:
        {
            ramStart[0] = BTL_TRIGGER_PATTERN;
            ramStart[1] = BTL_TRIGGER_PATTERN;
            ramStart[2] = BTL_TRIGGER_PATTERN;
            ramStart[3] = BTL_TRIGGER_PATTERN;

            APP_SystemReset();
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
