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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app_live_update.h"
#include "definitions.h"
#include <device.h>

#define BTL_TRIGGER_PATTERN (0x5048434DUL)

#define FLASH_START             (0UL)
#define FLASH_LENGTH            (1048576UL)
#define PAGE_SIZE               (512UL)
#define ERASE_BLOCK_SIZE        (8192UL)
#define PAGES_IN_ERASE_BLOCK    (ERASE_BLOCK_SIZE / PAGE_SIZE)

#define APP_START_ADDRESS       (0x2000UL)

#define GUARD_OFFSET            0
#define CMD_OFFSET              2
#define ADDR_OFFSET             0
#define SIZE_OFFSET             1
#define DATA_OFFSET             1
#define CRC_OFFSET              0

#define CMD_SIZE                1
#define GUARD_SIZE              4
#define SIZE_SIZE               4
#define OFFSET_SIZE             4
#define CRC_SIZE                4
#define HEADER_SIZE             (GUARD_SIZE + SIZE_SIZE + CMD_SIZE)
#define DATA_SIZE               ERASE_BLOCK_SIZE

#define WORDS(x)                ((int)((x) / sizeof(uint32_t)))

#define OFFSET_ALIGN_MASK       (~ERASE_BLOCK_SIZE + 1)
#define SIZE_ALIGN_MASK         (~PAGE_SIZE + 1)

#define LIVE_UPDATE_GUARD       (0x5048434DUL)

// *****************************************************************************
// *****************************************************************************
// Section: Global objects
// *****************************************************************************
// *****************************************************************************
volatile bool changeSamplingRate    = false;
volatile bool isLiveUpdateFailure   = false;

APP_LIVE_UPDATE_DATA app_live_update;

static uint32_t lu_input_buffer[WORDS(OFFSET_SIZE + DATA_SIZE)];

static uint32_t lu_flash_data[WORDS(DATA_SIZE)];
static uint32_t lu_flash_addr          = 0;

static uint32_t lu_unlock_begin        = 0;
static uint32_t lu_unlock_end          = 0;

static uint32_t *ramStart = (uint32_t *)BTL_TRIGGER_RAM_START;

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
// *****************************************************************************
// Section: Live Update Task Local Functions
// *****************************************************************************
// *****************************************************************************

/* Function to Send the response command to the Host */
static void send_Response( T_APP_LIVE_UPDATE_RESP sendResp )
{
    SERCOM1_USART_Write((uint8_t*)&sendResp, sizeof(sendResp));
    /* Wait for all bytes to be transmitted out */
    while (SERCOM1_USART_WriteCountGet() != 0);
}

/* Function to Generate CRC using the device service unit peripheral on programmed data */
static uint32_t crc_generate(void)
{
    uint32_t addr = lu_unlock_begin;
    uint32_t size = lu_unlock_end - lu_unlock_begin;
    uint32_t crc  = 0;

    PAC_PeripheralProtectSetup (PAC_PERIPHERAL_DSU, PAC_PROTECTION_CLEAR);

    DSU_CRCCalculate (addr, size, 0xffffffff, &crc);

    PAC_PeripheralProtectSetup (PAC_PERIPHERAL_DSU, PAC_PROTECTION_SET);

    return crc;
}

/* Function to process the received command */
static T_APP_LIVE_UPDATE_STATUS command_Task( uint8_t command )
{
    uint32_t i;
    T_APP_LIVE_UPDATE_STATUS command_status = APP_LIVE_UPDATE_STATUS_ERROR;

    if (APP_LIVE_UPDATE_CMD_UNLOCK == command)
    {
        uint32_t begin  = (lu_input_buffer[ADDR_OFFSET] & OFFSET_ALIGN_MASK);

        uint32_t end    = begin + (lu_input_buffer[SIZE_OFFSET] & SIZE_ALIGN_MASK);

        if (end > begin && end <= (FLASH_START + FLASH_LENGTH))
        {
            lu_unlock_begin = begin;
            lu_unlock_end = end;

            send_Response(APP_LIVE_UPDATE_RESP_OK);
            command_status = APP_LIVE_UPDATE_STATUS_UNLOCK;
        }
        else
        {
            lu_unlock_begin = 0;
            lu_unlock_end = 0;

            send_Response(APP_LIVE_UPDATE_RESP_ERROR);
            command_status = APP_LIVE_UPDATE_STATUS_ERROR;
        }
    }
    else if (APP_LIVE_UPDATE_CMD_DATA == command)
    {
        lu_flash_addr = (lu_input_buffer[ADDR_OFFSET] & OFFSET_ALIGN_MASK);

        if (lu_unlock_begin <= lu_flash_addr && lu_flash_addr < lu_unlock_end)
        {
            for (i = 0; i < WORDS(DATA_SIZE); i++)
                lu_flash_data[i] = lu_input_buffer[i + DATA_OFFSET];

            //send_Response(APP_LIVE_UPDATE_RESP_OK);
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
        uint32_t crc        = lu_input_buffer[CRC_OFFSET];
        uint32_t crc_gen    = 0;

        crc_gen = crc_generate();

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
    uint32_t addr                           = lu_flash_addr;
    uint32_t page                           = 0;
    uint32_t write_idx                      = 0;
    T_APP_LIVE_UPDATE_STATUS flash_status   = APP_LIVE_UPDATE_STATUS_ERROR;

    // Lock region size is always bigger than the row size
    NVMCTRL_RegionUnlock(addr);

    while(NVMCTRL_IsBusy() == true);

    /* Erase the Current sector */
    NVMCTRL_BlockErase(addr);

    /* Receive Next Bytes while waiting for erase to complete */
    while(NVMCTRL_IsBusy() == true);

    for (page = 0; page < PAGES_IN_ERASE_BLOCK; page++)
    {
        NVMCTRL_PageWrite(&lu_flash_data[write_idx], addr);

        while(NVMCTRL_IsBusy() == true);

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
void usart_ReadEventHandler( SERCOM_USART_EVENT event, uintptr_t context )
{
    static uint32_t bytes_read      = 0;
    static uint32_t ptr             = 0;
    static uint32_t size            = 0;
    static bool header_received     = false;

    uint8_t input_data              = 0;
    uint8_t guard_byte              = 0;
    uint8_t *byte_buf               = (uint8_t *)&lu_input_buffer[0];

    if(event == SERCOM_USART_EVENT_READ_ERROR)
    {
        if(SERCOM1_USART_ErrorGet() != USART_ERROR_NONE)
        {
            /* ErrorGet clears errors, set error flag to notify to the application */
            app_live_update.error_status = true;
        }
    }
    else
    {
        /* Receive data from HOST-PC. */
        bytes_read += SERCOM1_USART_Read((uint8_t*)&input_data, sizeof(input_data));

        /* Check if 100 ms have elapsed */
        if (SYSTICK_TimerPeriodHasExpired())
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
                guard_byte = (uint8_t)lu_input_buffer[GUARD_OFFSET];

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
                if (lu_input_buffer[GUARD_OFFSET] != LIVE_UPDATE_GUARD)
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
                size                           = lu_input_buffer[SIZE_OFFSET];
                app_live_update.guard_match    = true;
                app_live_update.input_command  = (uint8_t)lu_input_buffer[CMD_OFFSET];

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

        SYSTICK_TimerRestart();
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

    SYSTICK_TimerStart();
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
            /* Register a callback for read events */
            SERCOM1_USART_ReadCallbackRegister(usart_ReadEventHandler, (uintptr_t) NULL);

            /* Receive a callback for each character */
            SERCOM1_USART_ReadThresholdSet(1);

            /* Enable RX event notifications */
            SERCOM1_USART_ReadNotificationEnable(true, true);

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
                            else if (resp == APP_LIVE_UPDATE_STATUS_VERIFY)
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
                else if (resp == APP_LIVE_UPDATE_STATUS_VERIFY)
                {
                    app_live_update.state = APP_LIVE_UPDATE_STATE_SUCCESS;
                }
            }

            break;
        }

        /* Get ready for next Live Update request. */
        case APP_LIVE_UPDATE_STATE_SUCCESS:
        {
            changeSamplingRate      = true;
            isLiveUpdateFailure     = false;

            /* Reset the device for the programmed application firmware to run. */
            if (SWITCH2_Get() == SWITCH2_STATE_PRESSED)
            {
                NVMCTRL_BankSwap();
                app_live_update.state   = APP_LIVE_UPDATE_STATE_TRIGGER_SYS_RESET;
            }
            /* Get ready for next firmware upgrade. */
            else if (app_live_update.guard_byte_check == true)
            {
                app_live_update.state   = APP_LIVE_UPDATE_STATE_SERVICE_TASKS;
            }
            else // Wait for either switch press or for firmware upgrade.
            {
                app_live_update.state   = APP_LIVE_UPDATE_STATE_SUCCESS;
            }
            break;
        }

        /* Live Update Failed. */
        case APP_LIVE_UPDATE_STATE_ERROR:
        {
            app_live_update.guard_byte_check    = false;
            app_live_update.guard_received      = false;
            app_live_update.packet_received     = false;

            /* Press Switch 2 to enter to reset the device. */
            if (SWITCH2_Get() == SWITCH2_STATE_PRESSED)
            {
                app_live_update.state = APP_LIVE_UPDATE_STATE_TRIGGER_SYS_RESET;
            }

            changeSamplingRate  = false;
            isLiveUpdateFailure = true;
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
