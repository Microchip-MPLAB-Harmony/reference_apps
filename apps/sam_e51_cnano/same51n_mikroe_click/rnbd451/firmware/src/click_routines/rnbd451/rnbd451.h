/*******************************************************************************
  RNBD Header file

  Company:
    Microchip Technology Inc.

  File Name:
    rnbd451.h

  Summary:
  This file contains the "rnbd451" function definitions
 
  Description:
 *******************************************************************************/
/*
    (c) 2024 Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip software and any
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party
    license terms applicable to your use of third party software (including open source software) that
    may accompany Microchip software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS
    FOR A PARTICULAR PURPOSE.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS
    SOFTWARE.
*/


#ifndef MCHP_RNBD_H
#define MCHP_RNBD_H

#include <stdbool.h>
#include <stdint.h>

 /**
  * \ingroup RNBD
  * \brief Initializes RNBD Device
  *
  * This API initializes RNBD Device.
  *
  * \return Initialization Status.
  * \retval true - Success
  * \retval false - Failure.
  */
bool rnbd451_init(void);

 /**
  * \ingroup CLICK_RNBD
  * \brief Puts the CLICK_RNBD in user defined mode (Command Mode/Data Mode/ Set commands etc..).
  *
  * This API puts the CLICK_RNBD in user defined mode (Command Mode/Data Mode/ Set commands etc..).
  *
  * \return User Defined Mode Status
  * \retval true - Success
  * \retval false - Failure

  * Paramater 1 - Command to be sent
  * Parameter 2 - Length of Command to be sent
  * Parameter 3 - Expected Response message
  * Parameter 4 - Expected Response length
  */
bool rnbd451_sendcommand_receiveresponse(const char *cmdMsg, uint8_t cmdLen, const char *responsemsg, uint8_t responseLen);

 /**
  * \ingroup CLICK_RNBD
  * \brief Sets up the Buffer and Buffer Size for Aysnc Message Handler
  *
  * This API sets up the Buffer and the Buffer size to be used by the Async
  * Message Handler.
  * \param pBuffer Passed buffer
  * \param len Size of passed buffer
  * \return Set Status
  * \retval true - Success
  * \retval false - Failure
  */

 /**
  * \ingroup CLICK_RNBD
  * \brief Checks to see if there is Data Ready using Async Message Handling
  *
  * This API checks to see if there is Data ready on the line using Async Message Handling.
  * This API follows the standard UART form.
  * \return Data Ready Status
  * \retval true - Data is ready
  * \retval false - Data is not ready
  */
bool rnbd451_dataready(void);

 /**
  * \ingroup CLICK_RNBD
  * \brief Read incoming Data using Async Message Handling
  *
  * This API reads incoming data using Async Message Handling.
  * This API follows the standard UART form.
  * \return Data Read
  */
uint8_t rnbd451_read(void);



bool rnbd451_basicdataexchange (void);

#endif  /* MCHP_RNBD_H */