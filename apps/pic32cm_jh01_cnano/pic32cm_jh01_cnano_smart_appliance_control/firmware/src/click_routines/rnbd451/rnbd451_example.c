 /*******************************************************************************
  RNBD451 Example Source file

  Company:
    Microchip Technology Inc.

  File Name:
    rnbd451_example.c

  Summary:
  This file contains the "rnbd451" example 
 
  Description:
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
// ----------------------------------------------------------------------------


#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "click_routines/rnbd451/rnbd451_example.h"
#include "click_routines/rnbd451/rnbd451.h"
#include "click_routines/click_interface.h"


/** MACRO used to configure the application used buffer sizes.
 *  This is used by the application for communication buffers.
 */
#define MAX_BUFFER_SIZE                 (80U)

/**< Status Buffer instance passed to RN487X drive used for Asynchronous Message Handling (see *asyncBuffer in rn487x.c) */
static char statusBuf[MAX_BUFFER_SIZE];

/**
 * \def DEMO_PERIODIC_TRANSMIT_COUNT
 * This macro provide a definition for a periodic data transmission demostration
 */
#define DEMO_PERIODIC_TRANSMIT_COUNT           (uint8_t)(100)


bool rnbd451_setasyncmessagehandler(char* pbuffer, uint8_t len)
{
    return CLICK_RNBD451_SetAsyncMessageHandler(pbuffer, len);
}

bool rnbd451_example_tasks(void)
{
    rnbd451_init();

    bool res = false;

    res = rnbd451_setasyncmessagehandler(statusBuf, sizeof(statusBuf));

    if (res == true)
    {
        while(true)
        {
            if (true == rnbd451_basicdataexchange())
            {
                // Connected
            }
            else
            {
                // Not Connected
            }
        }
    }
    return (false);     // ^ Held if Successful; Return failure if reaching this.
}
