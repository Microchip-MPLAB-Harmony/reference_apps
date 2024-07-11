/*******************************************************************************
  DRAM click header file

  Company
    Microchip Technology Inc.

  File Name
    dram.h

  Summary
    This file contains prototypes for functions in dram.c file

  Description
    This file contains the prototype for dram.c which has function calls
    for collecting various parameters like temperature and pressure.
  Remarks:
    None.

 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*
    (c) 2024 Microchip Technology Inc. and its subsidiaries. You may use this
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

#ifndef DRAM_H
#define DRAM_H

#ifdef __cplusplus
extern "C"{
#endif

#include "definitions.h"


#define DRAM_CMD_READ                   0x03
#define DRAM_CMD_FAST_READ              0x0B
#define DRAM_CMD_WRITE                  0x02
#define DRAM_CMD_RESET_ENABLE           0x66
#define DRAM_CMD_RESET                  0x99
#define DRAM_CMD_WRAP_BOUNDARY_TOGGLE   0xC0
#define DRAM_CMD_READ_ID                0x9F

#define DRAM_MIN_ADDRESS                0x000000
#define DRAM_MAX_ADDRESS                0x7FFFFFul

#define DRAM_MANUFACTURER_ID            0x0D

typedef enum
{
    DRAM_ERROR = 0,
    DRAM_OK = 1

} dram_return_value_t;

/**
 * @brief DRAM init function.
 * @details This function initializes all necessary pins and peripherals used
 * for this click board.
 */
void dram_init (void);

/**
 * @brief DRAM read id function.
 * @details This function reads the device ID (8 bytes).
 */
bool dram_read_id ( uint8_t *device_id );
/**
 * @brief DRAM check communication function.
 * @details This function checks the communication by reading the device ID bytes and
 * verifying the manufacturer ID.
 */
bool dram_check_communication ( );

/**
 * @brief DRAM memory write function.
 * @details This function writes a desired number of data bytes starting from the
 * selected memory address.
 */
void dram_mem_write ( uint8_t *pTxData, uint8_t txSize );

/**
 * @brief DRAM memory read function.
 * @details This function reads a desired number of data bytes starting from the
 * selected memory address.
 */
void dram_mem_write_read ( uint8_t *pTxData, uint8_t txSize, uint8_t *pRxData, uint8_t rxSize );

/**
 * @brief DRAM reset function.
 * @details This function resets the device by putting the device in SPI standby mode which is
 * also the default mode after power-up.
 */
bool dram_reset_cmd ( );

#ifdef __cplusplus
}
#endif
#endif // DRAM_H

/*! @} */ // dram

// ------------------------------------------------------------------------ END