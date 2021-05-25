/*******************************************************************************
  RFID click routine example source file

  Company:
    Microchip Technology Inc.

  File Name:
    rfid_example.c

  Summary
    RFID click routine example implementation File.

  Description
    This file defines the usage of the RFID click routine APIs.

  Remarks:
    None.
 
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*
    (c) 2021 Microchip Technology Inc. and its subsidiaries. You may use this
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

/**
  Section: Included Files
 */

#include <stdbool.h>
#include "definitions.h"                           // SYS function prototypes
#include "rfid.h"
#include "rfid_example.h"

#define    ID_BUF_SIZE            38

volatile bool switchPressEvent = false;
         char ID_Buf[ID_BUF_SIZE];


/**
  Section: Example Code
 */

void rfid_example(void)
{
    rfid_init();
    printf("\n\rRFID Click Initialization completed");
    printf("\n\n\n\rKeep any RFID tag near to RFID transceiver Antenna and Press Switch SW0 Button\n");
    while(true)
    {
        if(switchPressEvent == true)
        {
            if(false == GetTagID(ID_Buf))
            {
                printf("\n\rNo RFID Tag found");
            }
            else
            {
                printf("\n\rRFID Tag ID = %s", ID_Buf);
            }
            switchPressEvent = false;
        }
    }
}
