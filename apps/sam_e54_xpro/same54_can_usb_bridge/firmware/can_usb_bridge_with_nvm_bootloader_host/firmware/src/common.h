/* ************************************************************************** */
/** Descriptive File Name

  Company
    Microchip Technology Inc.

  File Name
    common.h

  Summary
    This header file provides a common interface between applications for
    exchange of data.

  Description
    This file declares functions that can be used to fetch data between
    applications.
 */
/* ************************************************************************** */

// DOM-IGNORE-BEGIN
/*******************************************************************************************
* Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.

 * Subject to your compliance with these terms, you may use this Microchip software
 * and any derivatives exclusively with Microchip products. You are responsible for
 * complying with third party license terms applicable to your use of third party
 * software (including open source software) that may accompany this Microchip software.

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
 *******************************************************************************************/
// DOM-IGNORE-END

#ifndef _COMMON_H    /* Guard against multiple inclusion */
#define _COMMON_H



/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
//#include <plib_can1.h>

// *****************************************************************************
// *****************************************************************************
// Section: Interface Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function
    int8_t COMMON_APP_CAN_Rx_DataIsReady ( void )

  Summary
    Check if data from CAN task is ready

  Returns
    1 - if data is available

  Example
    <code>
    int8_t temp = COMMON_APP_CAN_Rx_DataIsReady();
    </code>
 */
int8_t COMMON_APP_CAN_Rx_DataIsReady(void);
/*******************************************************************************
  Function
    int8_t COMMON_APP_CAN_message_count ( void )

  Summary
    Sends the number of received messages

  Returns
    unsigned int

  Example
    <code>
    int8_t temp = COMMON_APP_CAN_message_count();
    </code>
 */
uint8_t COMMON_APP_CAN_message_count(void);

/*******************************************************************************
  Function
    uint8_t COMMON_APP_CAN_GetData ( void )

  Summary
    Gets CAN data

  Returns
    unsigned int

  Example
    <code>
    uint32_t temp = COMMON_APP_CAN_GetData();
    </code>
 */
uint8_t * COMMON_APP_CAN_GetData(void);
/*******************************************************************************
  Function
    void COMMON_APP_CAN_Rx_DataStatus(bool);

  Summary
    set the status of CAN Data

  Example
    <code>
    COMMON_APP_CAN_Rx_DataStatus(true);
    COMMON_APP_CAN_Rx_DataStatus(false);
    </code>
 */

void COMMON_APP_CAN_Rx_DataStatus(bool);

/*******************************************************************************
  Function
    Summary
    Sends CAN data

  Returns
    unsigned int

  Example
    <code>
    uint32_t temp = COMMON_APP_CAN_GetData();
    </code>
 */

bool COMMON_APP_CAN_SendData(uint8_t,uint8_t *);

#endif /* _COMMON_H */

/* *****************************************************************************
 End of File
 */
