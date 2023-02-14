/*******************************************************************************
  Bootloader Common Header File

  File Name:
    bootloader_common.h

  Summary:
    This file contains common definitions and functions.

  Description:
    This file contains common definitions and functions.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Include Files
// *****************************************************************************
// *****************************************************************************

#ifndef BOOTLOADER_COMMON_H
#define BOOTLOADER_COMMON_H

#include "definitions.h"
#include <device.h>

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

#define FLASH_START                             (0x00000000UL)
#define FLASH_LENGTH                            (0x80000UL)
#define PAGE_SIZE                               (64UL)
#define ERASE_BLOCK_SIZE                        (256UL)
#define PAGES_IN_ERASE_BLOCK                    (ERASE_BLOCK_SIZE / PAGE_SIZE)

#define NVM_USER_ROW_START                      (0x00804000UL)
#define NVM_USER_ROW_SIZE                       (0x100UL)
#define NVM_USER_PAGE_SIZE                      (64UL)

#define NVM_BOCOR_ROW_START                      (0x0080C000UL)
#define NVM_BOCOR_ROW_SIZE                       (0x100UL)
#define NVM_BOCOR_PAGE_SIZE                      (64UL)

#define BOOTLOADER_SIZE                         4096

#define FLASH_END_ADDRESS                       (FLASH_START + FLASH_LENGTH)


#define APP_START_ADDRESS                       (0x1000UL)


#define BTL_TRIGGER_RAM_START                   (0x20000000 + 0x1000)

#define BTL_TRIGGER_LEN                         16

// *****************************************************************************
/* Function:
    uint16_t bootloader_GetVersion( void );

Summary:
    Returns the current bootloader version.

Description:
    This function can be used to read the current version of bootloader.

    The bootloader version is of 2 Bytes. MAJOR version is sent first
    followed by MINOR version

    This function is defined as __WEAK in bootloader core and defines the bootloader
    version to current release version of bootloader repo.

    It can be overridden with custom implementation by user based on his requirement.

    User can make use of bootloader read version command to read the current version
    from the respective host.

Precondition:
    None

Parameters:
    None.

Returns:
    bootloader version - 2 Bytes (MAJOR version is sent first followed by MINOR version)

Example:
    <code>

    // Bootloader Major and Minor version sent for a Read Version command (MAJOR.MINOR)
    #define BTL_MAJOR_VERSION       3
    #define BTL_MINOR_VERSION       6

    uint16_t bootloader_GetVersion( void )
    {
        uint16_t btlVersion = (((BTL_MAJOR_VERSION & 0xFF) << 8) | (BTL_MINOR_VERSION & 0xFF));

        return btlVersion;
    }

    </code>
*/
uint16_t bootloader_GetVersion( void );

// *****************************************************************************
/* Function:
    bool bootloader_Trigger( void );

Summary:
    Checks if Bootloader has to be executed at startup.

Description:
    This function can be used to check for a External HW trigger or Internal firmware
    trigger to execute bootloader at startup.

    This check should happen before any system resources are initialized apart for PORT
    as the same system resource can be Re-initialized by the application if bootloader jumps
    to it and may cause issues.

    - <b>External Trigger: </b>
        Is achieved by triggering the selected GPIO_PIN in bootloader configuration
        in MHC.
    - <b>Firmware Trigger: </b>
        Application firmware which wants to execute bootloader at startup needs to
        fill first 16 bytes of ram location with bootloader request pattern.

        <code>
            uint32_t *sram = (uint32_t *)RAM_START_ADDRESS;

            sram[0] = 0x5048434D;
            sram[1] = 0x5048434D;
            sram[2] = 0x5048434D;
            sram[3] = 0x5048434D;
        </code>

Precondition:
    PORT/PIO Initialize must have been called.

Parameters:
    None.

Returns:
    - True  : If any of trigger is detected.
    - False : If no trigger is detected..

Example:
    <code>

        NVMCTRL_Initialize();

        PORT_Initialize();

        if (bootloader_Trigger() == false)
        {
            run_Application(APP_START_ADDRESS);
        }

        CLOCK_Initialize();

    </code>
*/
bool bootloader_Trigger( void );

// *****************************************************************************
/* Function:
    void run_Application( uint32_t address );

Summary:
    Runs the programmed application at startup.

Description:
    This function can be used to run programmed application though bootloader at startup.

    If the first 4Bytes of Application Memory is not 0xFFFFFFFF then it jumps to
    the application start address to run the application programmed through bootloader and
    never returns.

    If the first 4Bytes of Application Memory is 0xFFFFFFFF then it returns from function
    and executes bootloader for accepting a new application firmware.

Precondition:
    bootloader_Trigger() must be called to check for bootloader triggers at startup.

Parameters:
    address - Application Start/Jump address.

Returns:
    None

Example:
    <code>

        NVMCTRL_Initialize();

        PORT_Initialize();

        if (bootloader_Trigger() == false)
        {
            run_Application(APP_START_ADDRESS);
        }

        CLOCK_Initialize();

    </code>
*/
void run_Application( uint32_t address );

// *****************************************************************************
/* Function:
    uint32_t bootloader_CRCGenerate(uint32_t start_addr, uint32_t size)

Summary:
    Generates CRC on the contents of Flash memory from the given start address and size

Description:
    This function can be used to verify the programmed image in flash when a Verify
    command is received from the host

Precondition:
    The application binary is already programmed in flash memory

Parameters:
    start_addr - Start address of flash memory to calculate the CRC from
    size - Size of the memory area to calculate CRC for

Returns:
    Returns the calculated CRC

Example:
    <code>
        uint32_t appImageStartAddr;
        uint32_t appImageSize;
        uint32_t receivedCRC;

        appImageStartAddr = 0x00002000;
        appImageSize = 0x8000;

        // receivedCRC is populated based on the Verify command received from the host

        if (bootloader_CRCGenerate(appImageStartAddr, appImageSize) != receivedCRC)
        {
            // CRC mismatch
        }
        else
        {
            // CRC matches
        }

    </code>
*/

uint32_t bootloader_CRCGenerate(uint32_t start_addr, uint32_t size);

// *****************************************************************************
/* Function:
    void bootloader_TriggerReset(void)

Summary:
    Triggers a reset

Description:
    This function can be used to reset the device in response to the RESET command
    received from the host

Precondition:
    None.

Parameters:
    None

Returns:
    None

Example:
    <code>
        // Make sure all transfers are complete before resetting the device

        bootloader_TriggerReset();

    </code>
*/
void bootloader_TriggerReset(void);


/* Function to refresh watchdog timer */
void kickdog(void);

#endif      //BOOTLOADER_COMMON_H