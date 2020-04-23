/*******************************************************************************
  ADPCM Decoder Header File

  Company:
    Microchip Technology Inc.

  File Name:
    adpcm_dec.h

  Summary:
    Contains the ADPCM decoder specific defintions and function prototypes.

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
 
#ifndef _ADPCM_DEC_H	 /* Guard against multiple inclusion */
#define	_ADPCM_DEC_H
 
#include <stdint.h>
#include <stdbool.h>


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
extern "C" {
#endif
//DOM-IGNORE-END


/*	ADPCM WAV File Header Size
	
	Summary:
		WAV Header Size
	Description:
		WAV Header Size
*/
#define ADPCM_HEADER_SIZE 44
    

/*	ADPCM Audio File Header Structure
	
	Summary:
		ADPCM WAV File Header
	Description:
		This structure is header structure of wav container.
*/
typedef struct {
    int format;
    int filesize;
    int filetype;
    int frmtchunk_marker;
    int dataLen;
    short type_frmt;
    short numOfChan;
    int samplesPerSec;
    int bytesPerSec;
    short blockAlign;
    short bitsPerSample;
    int *extra;
    unsigned int extralen;        
} ADPCMHEADER; 

// *****************************************************************************
/* Function:
	void ADPCM_Initialize(uint8_t *input);

	Summary:
		Initializes ADPCM decoder.

	Description:
		Initalizes ADPCM decoder state.

	Parameters:
		input - Pointer to the data of ADPCM WAV format header, 
				this pointer could be null if ADPCM WAV format header 
				is not available .
		
	Returns:
		None.
*/
void ADPCM_Initialize(uint8_t *input);

// *****************************************************************************
/* Function:
	bool ADPCM_Decoder
	(uint8_t *input, 
	uint16_t inSize, 
	uint16_t *read, 
	int16_t *output, 
	uint16_t *written);

	Summary:
		Decode the ADPCM stream of inSize from input pointer into output pointer.

	Description:
		Decode the ADPCM stream of inSize from input pointer into output pointer.

	
	Parameters:
		input	- Pointer to the data of ADPCM byte stream.
		inSize	- Size of ADPCM input stream in bytes.
		read	- Size of ADPCM decoder has decoded after this function complete
		output	- Pointer to the decoded data.
		written	- Size of decoded data.


	Returns:
		If successful, return true, otherwise, return false.
*/
bool ADPCM_Decoder(uint8_t *input, uint16_t inSize, uint16_t *read, int16_t *output, uint16_t *written);

// *****************************************************************************
/* Function (deprecate):
	int ADPCM_HdrGetFormat (void);

	Summary:
		Get ADPCM WAV conainter format code.

	Description:
		Get ADPCM WAV conainter format code.

	Precondition:
		Input pointer to ADPCM_Initialize function must not be null.

	Parameters:
		None.
	Returns:
		WAV header format code.
*/
int ADPCM_HdrGetFormat (void);

// *****************************************************************************
/* Function (deprecate):
	int ADPCM_HdrGetNumOfChan (void);

	Summary:
		Get number of channel states in ADPCM WAV header.

	Description:
		Get number of channel states in ADPCM WAV header.

	Precondition:
		Input pointer to ADPCM_Initialize function must not be null.

	Parameters:
		None.
	Returns:
		Number of channels states in ADPCM WAV header structure.
*/
int ADPCM_HdrGetNumOfChan(void);

// *****************************************************************************
/* Function (deprecate):
	int ADPCM_HdrGetSamplesPerSec (void);

	Summary:
		Get sample rate in ADPCM WAV header.

	Description:
		Get sample rate in ADPCM WAV header.

	Precondition:
		Input pointer to ADPCM_Initialize function must not be null.

	Parameters:
		None.
	Returns:
		Sample rate states in ADPCM WAV header structure.
*/
int ADPCM_HdrGetSamplesPerSec(void);

// *****************************************************************************
/* Function (deprecate):
	int ADPCM_HdrGetBlockAlign (void);

	Summary:
		Get blockAlign (NumChannels * BitsPerSample/8)
        in ADPCM WAV header.

	Description:
		Get blockAlign (NumChannels * BitsPerSample/8)
        in ADPCM WAV header.

	Precondition:
		Input pointer to ADPCM_Initialize function must not be null.

	Parameters:
		None.
	Returns:
		blockAlign states in ADPCM WAV header structure.
*/
int ADPCM_HdrGetBlockAlign(void);

// *****************************************************************************
/* Function (deprecate):
	int ADPCM_HdrGetBitsPerSample (void);

	Summary:
		Get bits per sample in ADPCM WAV header.

	Description:
		Get bits per sample in ADPCM WAV header,  
		8 bits = 8, 16 bits = 16, etc.

	Precondition:
		Input pointer to ADPCM_Initialize function must not be null.

	Parameters:
		None.
	Returns:
		Bits per sample states in ADPCM WAV header structure.
*/
int ADPCM_HdrGetBitsPerSample(void);

// *****************************************************************************
/* Function (deprecate):
	int ADPCM_HdrGetBytesPerSec (void);

	Summary:
		Get bytes per second in ADPCM WAV header.

	Description:
		Get bytes per second in ADPCM WAV header.
	
	Precondition:
		Input pointer to ADPCM_Initialize function must not be null.

	Parameters:
		None.
	Returns:
		Bits per sample states in ADPCM WAV header structure.
*/
int ADPCM_HdrGetBytesPerSec(void);

// *****************************************************************************
/* Function (deprecate):
	int ADPCM_HdrGetDataLen (void);

	Summary:
		Get ADPCM data size states in ADPCM WAV header.

	Description:
		Get ADPCM data size states in ADPCM WAV header.

	Precondition:
		Input pointer to ADPCM_Initialize function must not be null.

	Parameters:
		None.
	Returns:
		Data size states in ADPCM WAV header structure.
*/
int ADPCM_HdrGetDataLen(void);

// *****************************************************************************
/* Function (deprecate):
	unsigned int ADPCM_HdrGetFileSize (void);

	Summary:
		Get ADPCM WAV file size.

	Description:
		Get ADPCM WAV file size.

	Precondition:
		Input pointer to ADPCM_Initialize function must not be null.

	Parameters:
		None.
	Returns:
		ADPCM WAV file size.
*/
unsigned int ADPCM_HdrGetFileSize(void);

// *****************************************************************************
/* Function:
	int ADPCM_GetChannels (void);

	Summary:
		Get number of channel states in ADPCM WAV header.

	Description:
		Get number of channel states in ADPCM WAV header.

	Precondition:
		Input pointer to ADPCM_Initialize function must not be null.

	Parameters:
		None.
	Returns:
		Number of channels states in ADPCM WAV header structure.
*/
uint8_t ADPCM_GetChannels();

// *****************************************************************************
/* Function:
	void ADPCM_Decoder_ConfigByteOrder (bool isLE);

	Summary:
		Configure input ADPCM stream byte order.

	Description:
		Configure input ADPCM stream byte order.

	Parameters:
		isLE - True if ADPCM stream is in little endian format, 
			   otherwise, false.
	Returns:
		None.
*/
void ADPCM_Decoder_ConfigByteOrder(bool isLE);


#ifdef __cplusplus
}
#endif

#endif	/* _ADPCM_DEC_H */

