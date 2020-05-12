/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_tone_lookup_table.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2015-2016 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END

#include "app_tone_lookup_table.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Variable Definitions
// *****************************************************************************
// *****************************************************************************
const DRV_I2S_DATA16 App_Tone_Lookup_Table_tone[]=
{
    {0,         0}, 
    {1714,      1714},
    {3425,      3425},
    {5125,      5125},
    {6812,      6812},
    {8480,      8480},
    {10125,     10125},
    {11742,     11742},
    {13327,     13327},
    {14876,     14876},
    {16383,     16383},
    {17846,     17846},
    {19260,     19260},
    {20621,     20621},
    {21925,     21925},
    {23170,     23170},
    {24350,     24350},
    {25465,     25465},
    {26509,     26509},
    {27481,     27481},
    {28377,     28377},
    {29196,     29196},
    {29934,     29934},
    {30591,     30591},
    {31163,     31163},
    {31650,     31650},
    {32051,     32051},
    {32364,     32364},
    {32587,     32587},
    {32722,     32722},
    {32767,     32767},
    {32722,     32722},
    {32587,     32587},
    {32364,     32364},
    {32051,     32051},
    {31650,     31650},
    {31163,     31163},
    {30591,     30591},
    {29934,     29934},
    {29196,     29196},
    {28377,     28377},
    {27481,     27481},
    {26509,     26509},
    {25465,     25465},
    {24350,     24350},
    {23170,     23170},
    {21925,     21925},
    {20621,     20621},
    {19260,     19260},
    {17846,     17846},
    {16383,     16383},
    {14876,     14876},
    {13327,     13327},
    {11742,     11742},
    {10125,     10125},
    {8480,      8480},
    {6812,      6812},
    {5125,      5125},
    {3425,      3425},
    {1714,      1714},
    {0,         0},
    {-1715,     -1715},
    {-3426,     -3426},
    {-5126,     -5126},
    {-6813,     -6813},
    {-8481,     -8481},
    {-10126,    -10126},
    {-11743,    -11743},
    {-13328,    -13328},
    {-14877,    -14877},
    {-16384,    -16384},
    {-17847,    -17847},
    {-19261,    -19261},
    {-20622,    -20622},
    {-21926,    -21926},
    {-23171,    -23171},
    {-24351,    -24351},
    {-25466,    -25466},
    {-26510,    -26510},
    {-27482,    -27482},
    {-28378,    -28378},
    {-29197,    -29197},
    {-29935,    -29935},
    {-30592,    -30592},
    {-31164,    -31164},
    {-31651,    -31651},
    {-32052,    -32052},
    {-32365,    -32365},
    {-32588,    -32588},
    {-32723,    -32723},
    {-32768,    -32768},
    {-32723,    -32723},
    {-32588,    -32588},
    {-32365,    -32365},
    {-32052,    -32052},
    {-31651,    -31651},
    {-31164,    -31164},
    {-30592,    -30592},
    {-29935,    -29935},
    {-29197,    -29197},
    {-28378,    -28378},
    {-27482,    -27482},
    {-26510,    -26510},
    {-25466,    -25466},
    {-24351,    -24351},
    {-23171,    -23171},
    {-21926,    -21926},
    {-20622,    -20622},
    {-19261,    -19261},
    {-17847,    -17847},
    {-16384,    -16384},
    {-14877,    -14877},
    {-13328,    -13328},
    {-11743,    -11743},
    {-10126,    -10126},
    {-8481,     -8481}, 
    {-6813,     -6813}, 
    {-5126,     -5126}, 
    {-3426,     -3426}, 
    {-1715,     -1715}
};

APP_TONE_LOOKUP_TABLE_DATA appToneLookupTableData;
uint32_t appSdCardAudioContext;

/* This is initialization function */

void APP_TONE_LOOKUP_TABLE_Initialize(void)
{
    appToneLookupTableData.state = APP_TONE_LOOKUP_TABLE_STATE_CODEC_OPEN;    
    appToneLookupTableData.codec.context = (uintptr_t)&appSdCardAudioContext;
    appToneLookupTableData.codec.bufferHandler = (DRV_CODEC_BUFFER_EVENT_HANDLER) APP_TONE_LOOKUP_TABLE_BufferEventHandler;
    appToneLookupTableData.codec.txbufferObject = (uint8_t *) App_Tone_Lookup_Table_tone;
    appToneLookupTableData.codec.bufferSize = sizeof(App_Tone_Lookup_Table_tone);        
}

/* This is the task routine for this lab */

void APP_TONE_LOOKUP_TABLE_Tasks(void)
{
    switch(appToneLookupTableData.state)
    {
        case APP_TONE_LOOKUP_TABLE_STATE_CODEC_OPEN:
        {
            /* A client opens the driver object to get an Handle */
            appToneLookupTableData.codec.handle = DRV_CODEC_Open(DRV_CODEC_INDEX_0, 
                    DRV_IO_INTENT_WRITE | DRV_IO_INTENT_EXCLUSIVE);
            if(appToneLookupTableData.codec.handle != DRV_HANDLE_INVALID)
            {
                appToneLookupTableData.state = APP_TONE_LOOKUP_TABLE_STATE_CODEC_SET_BUFFER_HANDLER;
            }
            else
            {
                /* Got an Invalid Handle.  Wait for AK4384 to Initialize */
                ;
            }
        }
        break;

        /* Set a handler for the audio buffer completion event */
        case APP_TONE_LOOKUP_TABLE_STATE_CODEC_SET_BUFFER_HANDLER:
        {
            DRV_CODEC_BufferEventHandlerSet(appToneLookupTableData.codec.handle,
                    appToneLookupTableData.codec.bufferHandler,
                    appToneLookupTableData.codec.context);
            appToneLookupTableData.state = APP_TONE_LOOKUP_TABLE_STATE_CODEC_ADD_BUFFER;
        }
        break;

        /* Add an audio buffer to the codec driver queue to be transmitted */
        case APP_TONE_LOOKUP_TABLE_STATE_CODEC_ADD_BUFFER:
        {
            uint8_t index;
            bool isInvalidHandle;

            isInvalidHandle = false;
            /* Queuing buffers (Queue Size - 1) items */
            /* Note: Here we are queuing the same buffer (Queue Size - 1) times. */
            for(index=0; index < (APP_TONE_LOOKUP_TABLE_CODEC_WRITE_QUEUE_SIZE - 1); index++)
            {
                DRV_CODEC_BufferAddWrite(appToneLookupTableData.codec.handle, &appToneLookupTableData.codec.writeBufHandle,
                appToneLookupTableData.codec.txbufferObject, appToneLookupTableData.codec.bufferSize);
                if(appToneLookupTableData.codec.writeBufHandle != DRV_CODEC_BUFFER_HANDLE_INVALID)
                {
                    ;
                }
                else
                {
                    isInvalidHandle = true;
                }
            }

            if(false == isInvalidHandle)
            {
                /* Queuing Done. Transmission has begun. */
                    appToneLookupTableData.state = APP_TONE_LOOKUP_TABLE_STATE_CODEC_WAIT_FOR_BUFFER_COMPLETE;
            }
        }
        break;

        /* Audio data Transmission under process */
        case APP_TONE_LOOKUP_TABLE_STATE_CODEC_WAIT_FOR_BUFFER_COMPLETE:
        {
        }
        break;

        /* Audio data Transmission complete */
        case APP_TONE_LOOKUP_TABLE_STATE_CODEC_BUFFER_COMPLETE:
        {
            DRV_CODEC_BufferAddWrite(appToneLookupTableData.codec.handle, &appToneLookupTableData.codec.writeBufHandle,
            appToneLookupTableData.codec.txbufferObject, appToneLookupTableData.codec.bufferSize);
            if(appToneLookupTableData.codec.writeBufHandle != DRV_CODEC_BUFFER_HANDLE_INVALID)
            {
                appToneLookupTableData.state = APP_TONE_LOOKUP_TABLE_STATE_CODEC_WAIT_FOR_BUFFER_COMPLETE;
            }
            else
            {
                // Something is wrong
            }
        }
        break;

        default:
        {
        }
        break;
    }
}




/**********************************************************
 * Application CODEC buffer Event handler.
 ***********************************************************/
static void APP_TONE_LOOKUP_TABLE_BufferEventHandler(DRV_CODEC_BUFFER_EVENT event,
        DRV_CODEC_BUFFER_HANDLE handle, uintptr_t context )
{              
    switch(event)
    {
        case DRV_CODEC_BUFFER_EVENT_COMPLETE:
        {
            appToneLookupTableData.state = APP_TONE_LOOKUP_TABLE_STATE_CODEC_BUFFER_COMPLETE;
        }
        break;
        case DRV_CODEC_BUFFER_EVENT_ERROR:
        {
        } break;

        case DRV_CODEC_BUFFER_EVENT_ABORT:
        {
        } break;
    }
}