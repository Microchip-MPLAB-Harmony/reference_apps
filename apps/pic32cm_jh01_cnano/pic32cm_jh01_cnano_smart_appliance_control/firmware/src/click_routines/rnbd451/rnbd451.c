/*******************************************************************************
  RNBD451 Source File

  Company:
    Microchip Technology Inc.

  File Name:
    rnbd451.c

  Summary:
    This file contains the "rnbd451" functions

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


#include "definitions.h"
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include "../click_interface.h"
#include "click_routines/rnbd451/rnbd451.h"


/**
 * \def PERIODIC_TRANSMIT_COUNT
 * This macro provide a definition for a periodic data transmission demostration
 */
#define PERIODIC_TRANSMIT_COUNT           (uint8_t)(100)
static bool read_data = false;                      /**< Flag which indicates whether Non-Status Message Data is ready */

bool rnbd451_init(void)
{
    return CLICK_RNBD451_Init();
}

bool rnbd451_isotabegin(void)
{
    return CLICK_RNBD451_IsOTABegin();
}

bool rnbd451_isstreamopen(void)
{
    return CLICK_RNBD451_IsStreamopen();
}

bool rnbd451_dataready(void)
{
    return CLICK_RNBD451_DataReady();
}

uint8_t rnbd451_read(void)
{
    return CLICK_RNBD451_Read();
}

bool rnbd451_isconnected(void)
{
    return CLICK_RNBD451_IsConnected();
}

bool rnbd451_entercmdmode(void)
{
    return CLICK_RNBD451_EnterCmdMode();
}

bool rnbd451_rebootcmd(void)
{
    return CLICK_RNBD451_RebootCmd();
}

bool rnbd451_basicdataexchange(void)
{
   static uint16_t periodic_counter = 0;
   bool isstreamopen, isotabegin;
   read_data = 0;
   isstreamopen = rnbd451_isstreamopen();
   isotabegin = rnbd451_isotabegin();
   LED_On();

   if (true == isstreamopen && false == isotabegin)
   {
       while (rnbd451_dataready())
       {
           read_data = rnbd451_read();
           // Use the readData as desired
       }
       if (periodic_counter == PERIODIC_TRANSMIT_COUNT)
       {
           RNBD.Write('1');
           periodic_counter = 0;
           LED_Off();
           RNBD.DelayMs(150);

       }
       else
       {
           periodic_counter++;
              RNBD.DelayMs(1);
       }
   }
   else
    {
        while(rnbd451_dataready())
        {
            // Clear data; Allow ASYNC processor decode
            //read_data = rnbd451_read();
        }
    }

    return isstreamopen;
}

bool rnbd451_setasyncmessagehandler(char* pbuffer, uint8_t len)
{
    return CLICK_RNBD451_SetAsyncMessageHandler(pbuffer, len);
}


