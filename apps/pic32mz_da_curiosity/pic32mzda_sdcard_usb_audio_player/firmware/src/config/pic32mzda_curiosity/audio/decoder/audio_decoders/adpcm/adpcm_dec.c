/*******************************************************************************
  ADPCM Decoder Source File

  Company:
    Microchip Technology Inc.

  File Name:
    adpcm_dec.c

  Summary:
    Contains the functional implementation of ADPCM decoder.

  Description:
    This file contains the ADPCM decoder specific defintions and function
    prototypes.
 *******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2011-2012 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
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
 //DOM-IGNORE-END 

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "adpcm_dec.h"
#include <string.h>

/* ADPCM Decoder State Structure
	 Summary:
		APDCM decoder state structure.
	 Description:
		This structure holds current adpcm decoder state and byte order.
*/
typedef struct 
{
	int			prevsample;		/* Predicted adpcm sample */
	int			previndex;		/* Index into step size table */
	bool		isLE;			/* ADPCM stream in little endian format*/
} AdpcmState;

/*
* Local ADPCM state instance
*/
static AdpcmState adpcmState;
/*
* Local ADPCM file header(if have)
*/
static ADPCMHEADER adpcmHeader;

/* Table of index changes */
static const int indexTable[16] = 
{
    -1, -1, -1, -1, 2, 4, 6, 8,
    -1, -1, -1, -1, 2, 4, 6, 8,
};

/* Quantizer step size lookup table */
static const int stepSizeTable[89] = 
{
   7, 8, 9, 10, 11, 12, 13, 14, 16, 17,
   19, 21, 23, 25, 28, 31, 34, 37, 41, 45,
   50, 55, 60, 66, 73, 80, 88, 97, 107, 118,
   130, 143, 157, 173, 190, 209, 230, 253, 279, 307,
   337, 371, 408, 449, 494, 544, 598, 658, 724, 796,
   876, 963, 1060, 1166, 1282, 1411, 1552, 1707, 1878, 2066,
   2272, 2499, 2749, 3024, 3327, 3660, 4026, 4428, 4871, 5358,
   5894, 6484, 7132, 7845, 8630, 9493, 10442, 11487, 12635, 13899,
   15289, 16818, 18500, 20350, 22385, 24623, 27086, 29794, 32767
};

/*
 Local ADPCM decoder function declarition
*/
static short ADPCMDecodeSample(unsigned char code, AdpcmState *state);

void ADPCM_Initialize(uint8_t *input)
{
	if (input != NULL)
	{
		// initialize ADPCM decoder to decode a ADPCM WAV format file
		memcpy(&adpcmHeader, input, ADPCM_HEADER_SIZE);
	}
    
    adpcmState.previndex = 0;
    adpcmState.prevsample = 0;
	adpcmState.isLE = false;
}

bool ADPCM_Decoder(uint8_t *input, uint16_t inSize, uint16_t *read, int16_t *output, uint16_t *written)
{   
	unsigned char* srcBuff=(unsigned char*)input;
	int nBytes=inSize;
	unsigned char pChar;	// packed ADPCM character

	if (adpcmState.isLE)
	{
		while(nBytes--)
		{
			pChar = *srcBuff++;
			*output++=ADPCMDecodeSample(pChar&0x0f, &adpcmState);
            if (ADPCM_GetChannels() == 1 )
            {
                *output = *(output-1);
                output++;
            }
			*output++=ADPCMDecodeSample((pChar>>4)&0x0f, &adpcmState);
            if (ADPCM_GetChannels() == 1)
            {
                *output = *(output-1);
                output++;
            }
		}
	}
	else
	{
		while(nBytes--)
		{
			pChar = *srcBuff++;
			*output++ = ADPCMDecodeSample((pChar >> 4) & 0x0f, &adpcmState);
            if (ADPCM_GetChannels() == 1)
            {
                *output = *(output-1);
                output++;
            }
			*output++ = ADPCMDecodeSample(pChar & 0x0f, &adpcmState);
            if (ADPCM_GetChannels() == 1)
            {
                *output = *(output-1);
                output++;
            }
		}
	}
    // adpcm compression ratio 1:4
    *written = 4*inSize;
    if (ADPCM_GetChannels() == 1)
    {
        *written *= 2;
    }
    *read = inSize;
    return true;
}

uint8_t ADPCM_GetChannels()
{
	return adpcmHeader.numOfChan;
}

int ADPCM_GetSampleRate()
{
	return adpcmHeader.samplesPerSec;
}

int ADPCM__GetBitsPerSample(void)
{
    return adpcmHeader.bitsPerSample;
}

int ADPCM_GetDataLen(void)
{
    return (int)adpcmHeader.dataLen;
}

void ADPCM_Decoder_ConfigByteOrder(bool isLE)
{
	adpcmState.isLE = isLE;
}

static short ADPCMDecodeSample(unsigned char code, AdpcmState *state)
{
   int step;        /* Quantizer step size */
   int predsample;  /* Output of ADPCM predictor */
   int diffq;       /* Dequantized predicted difference */
   int index;       /* Index into step size table */

   /* Restore previous values of predicted sample and quantizer step size index */
   predsample = state->prevsample;
   index = state->previndex;

   /* Find quantizer step size from lookup table using index */
   step = stepSizeTable[index];

   /* Inverse quantize the ADPCM code into a difference using the quantizer step size */
   diffq = step >> 3;
   if (code & 4)
   {
      diffq += step;
   }
   if (code & 2)
   {
      diffq += step >> 1;
   }
   if (code & 1)
   {
      diffq += step >> 2;
   }

   /* Add the difference to the predicted sample */
   if (code & 8)
   {
      predsample -= diffq;
   }
   else
   {
      predsample += diffq;
   }

	if (predsample>32767)
	{
		predsample=32767;
	}
	else if (predsample<-32768)
	{
		predsample=-32768;
	}
	
    /* Find new quantizer step size by adding the old index and a
       table lookup using the ADPCM code */
    index += indexTable[code];

    /* Check for overflow of the new quantizer step size index */
    if (index < 0)
    {
       index = 0;
    }
    if (index > 88)
    {
       index = 88;
    }

    /* Save predicted sample and quantizer step size index for next iteration */
    state->prevsample = predsample;
    state->previndex = index;

    /* Return the new speech sample */
    return (short)predsample;
}