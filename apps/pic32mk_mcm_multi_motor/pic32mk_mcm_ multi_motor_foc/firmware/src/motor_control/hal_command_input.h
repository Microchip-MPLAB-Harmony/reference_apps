/*******************************************************************************
 Motor Control Hardware Abstraction interface file

  Company:
    Microchip Technology Inc.

  File Name:
    hal_command_input.h

  Summary:
    Header file for command input hardware abstraction

  Description:
    This file contains the function mapping and channel mapping to provide
    hardware abstraction layer for motor control algorithm
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


#ifndef _HAL_COMMAND_INPUT_H
#define _HAL_COMMAND_INPUT_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <stdint.h>
#include <stdbool.h>
#include "hal_configure_common.h" 


#ifdef __cplusplus  // Provide C++ Compatibility
    extern "C" {
#endif

// *****************************************************************************
// *****************************************************************************
// Section: Macro Defines
// *****************************************************************************
// *****************************************************************************
#define POTENTIOMETER_1   ADCHS_CH20
#define POTENTIOMETER_2   ADCHS_CH12
#define POTENTIOMETER_3   ADCHS_CH13

#define BUTTON_ENABLE_1   GPIO_BUTTON1_PIN
#define BUTTON_ENABLE_2   GPIO_BUTTON2_PIN
#define BUTTON_ENABLE_3   GPIO_BUTTON3_PIN


#define SW_DEBOUNCE_DLY_MS                     (float)500  // Switch debounce delay in mS



// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************
typedef struct
{
    uint8_t  potentiometer_channel;
    uint8_t  button_input;
}HAL_COMMAND_CONFIG_T;



typedef enum
{
    button_pressed,
    button_released

}HAL_BUTTON_INPUT_E;


// *****************************************************************************
// *****************************************************************************
// Section: Function Declarations
// *****************************************************************************
// *****************************************************************************
bool HAL_ButtonRead(HAL_CHANNEL_ID_E id);
float HAL_PotRefRead(HAL_CHANNEL_ID_E id);


#ifdef __cplusplus  // Provide C++ Compatibility
    }
#endif


#endif // _HAL_COMMAND_INPUT_H

/*******************************************************************************
 End of File
*/    