 /*******************************************************************************
  13DOF click routine header file

  Company
    Microchip Technology Inc.

  File Name
    13dof.h

  Summary
    This is the header file which has Macros and prototypes for functions in 13dof.c

  Description
    This file contains prototype for the three integrated sensors on 13dof click board

  Remarks:
    None.

 *******************************************************************************/
 // DOM-IGNORE-BEGIN
/*
    (c) 2023 Microchip Technology Inc. and its subsidiaries. You may use this
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

/*!
 * \file
 *
 * \brief This file contains API for 13DOF Click driver.
 *
 * \addtogroup c13dof 13DOF Click Driver
 * @{
 */
// ----------------------------------------------------------------------------

#ifndef C13DOF_H
#define C13DOF_H
#include <stdint.h>
#include "bmi088.h"
#include "bmm150.h"
#include "bme680.h"
// -------------------------------------------------------------- PUBLIC MACROS
/**
 * \defgroup error_code Error Code
 * \{
 */
#define C13DOF_RETVAL       uint8_t

#define C13DOF_OK           0x00
#define C13DOF_INIT_ERROR   0xFF
/** \} */

#define C13DOF_POLL_PERIOD_MS                                      10

#define T_C13DOF_P                             const uint8_t*


// ----------------------------------------------- PUBLIC FUNCTION DECLARATIONS

/**
 * \defgroup public_function Public function
 * \{
 */

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief Initialization function.
 *
 * @param bme Click object.
 * @param bme680_t Click configuration structure.
 *
 * @description This function initializes all necessary pins and peripherals used for this click.
 */
void thirteenDof_bme680_init( bme680_t *bme );
/**
 * @brief Initialization function.
 *
 * @param bmm150 Click object.
 * @param bmm150_t Click configuration structure.
 *
 * @description This function initializes all necessary pins and peripherals used for this click.
 */
void thirteenDof_bmm150_init( bmm150_t *bmm );
/**
 * @brief Initialization function.
 *
 * @param bmi Click object.
 * @param bmi088_t Click configuration structure.
 *
 * @description This function initializes all necessary pins and peripherals used for this click.
 */
void thirteenDof_bmi088_init( bmi088_t *bmi );
/**
 * @brief Initialization function.
 *
 * @param bme Click object.
 * @param bme680_t Click Click configuration structure.
 *
 * @description This function calls temperature function of bme_680 sensor.
 */
float thirteenDof_get_temperature( bme680_t *bme );
/**
 * @brief Initialization function.
 *
 * @param bme Click object.
 * @param bme680_t Click Click configuration structure.
 *
 * @description This function calls humidity function of bme_680 sensor.
 */
float thirteenDof_get_humidity( bme680_t *bme );
/**
 * @brief Initialization function.
 *
 * @param bme Click object.
 * @param bme680_t Click Click configuration structure.
 *
 * @description This function calls pressure function of bme_680 sensor.
 */
float thirteenDof_get_pressure( bme680_t *bme );
/**
 * @brief Initialization function.
 *
 * @param bme Click object.
 * @param bme680_t Click Click configuration structure.
 *
 * @description This function calls gas resistance function of bme_680 sensor.
 */
uint32_t thirteenDof_get_gas_resistance( bme680_t *bme );
/**
 * @brief Initialization function.
 *
 * @param bmi Click object.
 * @param bmi088_t Click configuration structure.
 *
 * @description This function calls read_accel funtion of bmi088 sensor 
 */
void thirteenDof_read_accel( int16_t *accel_x, int16_t *accel_y, int16_t *accel_z );
/**
 * @brief Initialization function.
 *
 * @param bmi Click object.
 * @param bmi088_t Click configuration structure.
 *
 * @description This function calls read_gyro funtion of bmi088 sensor 
 */
void thirteenDof_read_gyro( int16_t *gyro_x, int16_t *gyro_y, int16_t *gyro_z );
/**
 * @brief Initialization function.
 *
 * @param bmm150 Click object.
 * @param bmm150_t Click configuration structure.
 *
 * @description This function calls geomagnetic data function of bmm150 sensor
 */
void thirteenDof_read_geo_mag_data( int16_t *mag_x, int16_t *mag_y, int16_t *mag_z, uint16_t *res_hall );

#ifdef __cplusplus
}
#endif
#endif  // _C13DOF_H_

/** \} */ // End public_function group
/// \}    // End click Driver group
/*! @} */
// ------------------------------------------------------------------------- END