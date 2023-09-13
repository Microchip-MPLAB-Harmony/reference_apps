/*******************************************************************************
  WINC Driver NVM Access Header File

  Company:
    Microchip Technology Inc.

  File Name:
    wdrv_winc_nvm.h

  Summary:
    WINC wireless driver NVM access header file.

  Description:
     This interface manages access to the SPI flash of the WINC device.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*
Copyright (C) 2019, Microchip Technology Inc., and its subsidiaries. All rights reserved.

The software and documentation is provided by microchip and its contributors
"as is" and any express, implied or statutory warranties, including, but not
limited to, the implied warranties of merchantability, fitness for a particular
purpose and non-infringement of third party intellectual property rights are
disclaimed to the fullest extent permitted by law. In no event shall microchip
or its contributors be liable for any direct, indirect, incidental, special,
exemplary, or consequential damages (including, but not limited to, procurement
of substitute goods or services; loss of use, data, or profits; or business
interruption) however caused and on any theory of liability, whether in contract,
strict liability, or tort (including negligence or otherwise) arising in any way
out of the use of the software and documentation, even if advised of the
possibility of such damage.

Except as expressly permitted hereunder and subject to the applicable license terms
for any third-party software incorporated in the software and any applicable open
source software license terms, no license or other rights, whether express or
implied, are granted under any patent or other intellectual property rights of
Microchip or any third party.
*/
// DOM-IGNORE-END

#ifndef _WDRV_WINC_NVM_H
#define _WDRV_WINC_NVM_H

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>

#include "wdrv_winc_common.h"

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver NVM Access Data Types
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/*  WINC NVM Regions

  Summary:
    Defines the available NVM regions.

  Description:
    This enumeration defines the possible NVM regions which can be manipulated
    using this interface. The WDRV_WINC_NVM_REGION_RAW can be used to access
    the entire flash.

  Remarks:
    None.
*/

typedef enum
{
    /* Access to the entire flash address space. */
    WDRV_WINC_NVM_REGION_RAW,

    /* Access to the firmware region (active image). */
    WDRV_WINC_NVM_REGION_FIRMWARE_ACTIVE,

    /* Access to the firmware region (inactive image). */
    WDRV_WINC_NVM_REGION_FIRMWARE_INACTIVE,

    /* Access to PLL table region. */
    WDRV_WINC_NVM_REGION_PLL_TABLE,

    /* Access to gain table region. */
    WDRV_WINC_NVM_REGION_GAIN_TABLE,

    /* Access to PLL and gain tables region. */
    WDRV_WINC_NVM_REGION_PLL_AND_GAIN_TABLES,

    /* Access to root certificate region. */
    WDRV_WINC_NVM_REGION_ROOT_CERTS,

    /* Access to TLS local certificate region. */
    WDRV_WINC_NVM_REGION_LOCAL_CERTS,

    /* Access to connection parameters region. */
    WDRV_WINC_NVM_REGION_CONN_PARAM,

    /* Access to HTTP files region. */
    WDRV_WINC_NVM_REGION_HTTP_FILES,
#ifdef WDRV_WINC_DEVICE_HOST_FILE_DOWNLOAD
    /* Access to host download region. */
    WDRV_WINC_NVM_REGION_HOST_FILE,
#endif
    /* Number of regions. */
    NUM_WDRV_WINC_NVM_REGIONS
} WDRV_WINC_NVM_REGION;

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver NVM Access Routines
// *****************************************************************************
// *****************************************************************************

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_NVMEraseSector
    (
        DRV_HANDLE handle,
        WDRV_WINC_NVM_REGION region,
        uint8_t startSector,
        uint8_t numSectors
    );

  Summary:
    Erase a sector within an NVM region.

  Description:
    Erases a number of sectors which exist within the requested region.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called with the intent
        DRV_IO_INTENT_EXCLUSIVE to obtain a valid handle.

  Parameters:
    handle      - Client handle obtained by a call to WDRV_WINC_Open.
    region      - Region of NVM to erase.
    startSector - Sector offset within region to erase.
    numSectors  - Number of sectors to erase.

  Returns:
    WDRV_WINC_STATUS_OK             - The erase completed successfully.
    WDRV_WINC_STATUS_INVALID_ARG    - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR  - The request encountered an error.

  Remarks:
    The WINC driver must have been opened for exclusive access to the flash to
    ensure the WINC firmware is not operating when manipulating the SPI flash.

*/
WDRV_WINC_STATUS WDRV_WINC_NVMEraseSector
(
    DRV_HANDLE handle,
    WDRV_WINC_NVM_REGION region,
    uint8_t startSector,
    uint8_t numSectors
);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_NVMWrite
    (
        DRV_HANDLE handle,
        WDRV_WINC_NVM_REGION region,
        void *pBuffer,
        uint32_t offset,
        uint32_t size
    );

  Summary:
    Writes data to an NVM region.

  Description:
    Writes the number of bytes specified to the NVM region.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called with the intent
        DRV_IO_INTENT_EXCLUSIVE to obtain a valid handle.

  Parameters:
    handle  - Client handle obtained by a call to WDRV_WINC_Open.
    region  - Region of NVM to write.
    pBuffer - Pointer to buffer containing the data to write.
    offset  - Offset within NVM region to write the data to.
    size    - Number of bytes to be written.

  Returns:
    WDRV_WINC_STATUS_OK             - The write completed successfully.
    WDRV_WINC_STATUS_INVALID_ARG    - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR  - The request encountered an error.

  Remarks:
    The WINC driver must have been opened for exclusive access to the flash to
    ensure the WINC firmware is not operating when manipulating the SPI flash.

    The write operation does not erase the flash device first, therefore the user
    must ensure the flash region has been erased first.

*/
WDRV_WINC_STATUS WDRV_WINC_NVMWrite
(
    DRV_HANDLE handle,
    WDRV_WINC_NVM_REGION region,
    void *pBuffer,
    uint32_t offset,
    uint32_t size
);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_NVMRead
    (
        DRV_HANDLE handle,
        WDRV_WINC_NVM_REGION region,
        void *pBuffer,
        uint32_t offset,
        uint32_t size
    );

  Summary:
    Reads data from an NVM region.

  Description:
    Reads the number of bytes specified from the NVM region.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called with the intent
        DRV_IO_INTENT_EXCLUSIVE to obtain a valid handle.

  Parameters:
    handle  - Client handle obtained by a call to WDRV_WINC_Open.
    region  - Region of NVM to read.
    pBuffer - Pointer to buffer to write the data read into.
    offset  - Offset within NVM region to read the data from.
    size    - Number of bytes to be read.

  Returns:
    WDRV_WINC_STATUS_OK             - The read completed successfully.
    WDRV_WINC_STATUS_INVALID_ARG    - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR  - The request encountered an error.

  Remarks:
    The WINC driver must have been opened for exclusive access to the flash to
    ensure the WINC firmware is not operating when manipulating the SPI flash.

*/
WDRV_WINC_STATUS WDRV_WINC_NVMRead
(
    DRV_HANDLE handle,
    WDRV_WINC_NVM_REGION region,
    void *pBuffer,
    uint32_t offset,
    uint32_t size
);

#endif /* _WDRV_WINC_NVM_H */
