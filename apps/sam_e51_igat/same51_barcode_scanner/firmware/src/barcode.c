/*******************************************************************************
    barcode Source File

  Company:
    Microchip Technology Inc.

  File Name:
    barcode.c

  Summary:
    Barcode Decoding file

  Description:
    This file has the function definitions like scan and measure function which
    give functionality to barcode decoding.

 *******************************************************************************/
// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
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
// DOM-IGNORE-END

/*!
 * \file
 *
 */
#include "barcode.h"

/********************************************************************/
/*                      Local variables                             */
/********************************************************************/
const uint8_t mod_table[30] = {
/* Left, odd parity (0 - 9)
 0b0001101, 0b0011001, 0b0010011, 0b0111101, 0b0100011,
 0b0110001, 0b0101111, 0b0111011, 0b0110111, 0b0001011,
*/
 0x0d, 0x19, 0x13, 0x3d, 0x23, 0x31, 0x2f, 0x3b, 0x37, 0x0b,
/* Left, even parity (10 - 19)
 0b0100111, 0b0110011, 0b0011011, 0b0100001, 0b0011101,
 0b0111001, 0b0000101, 0b0010001, 0b0001001, 0b0010111,
*/
 0x27, 0x33, 0x1b, 0x21, 0x1d, 0x39, 0x05, 0x11, 0x09, 0x17,
/* Right, check (20-29)
 0b1110010, 0b1100110, 0b1101100, 0b1000010, 0b1011100,
 0b1001110, 0b1010000, 0b1000100, 0b1001000, 0b1110100,
*/
 0x72, 0x66, 0x6c, 0x42, 0x5c, 0x4e, 0x50, 0x44, 0x48, 0x74,
};

/*
 * parity_table[] is used to find first prefix character.
 *
 * 0b000000, 0b001011, 0b001101, 0b001110, 0b010011,	0..4
 * 0b011001, 0b011100, 0b010101, 0b010110, 0b011010,	5..9
 */
static const uint8_t parity_tab[10] =   {
                                            0x00, 0x0b, 0x0d, 0x0e, 0x13,
                                            0x19, 0x1d, 0x15, 0x16, 0x1a,
                                        };

char bar_digits[13+1];
short bar_width[JAN_BARS];

static const uint8_t otab[5] = { 0, 1, 3, 7, 15 };


int find_char_val(int zflag, int *plen)
{
    int i, val, nb;

    val = i = 0;

    if (zflag)                          /* Left side. starts with white bar */
    {	
        while (i < 4) 
        {
            nb = plen[i];
            
            if (i&1)                    /* odd number bar is black */
            {	
                val = val << nb;
                val |= otab[nb];        /* shift and set bits */
            } 
            
            else                        /* even number bar is white */
            {		
                val = val << nb;        /* shift only */
            }
        
            i++;
        }
    } 
    
    else                                /* Right side. starts with black bar */
    {	
        while (i < 4) 
        {
            nb = plen[i];
            
            if (i&1)                    /* odd number bar is white */
            {	
                val = val << nb;
            } 
            
            else                        /* event number bar is black */
            {		
                val = val << nb;
                val |= otab[nb];        /* shift and set bits */
            }
        
            i++;
        }
    }
    
    /* Try to find the value in our module table */
    for (i = 0; i < sizeof(mod_table); i++) 
    {
        if (val == mod_table[i])
            return(i);
    }
    
    return -1;	/* Not found. Failed to decode */
}

/*
 * Decode data character consists from seven modules
 */
int decode7(int index, short *wtab)
{
    int i, mod_len[4];
    int wval[4];
    int av, remain;
    int maxid;

    /* We are going to find module counts of each bars.
     * It is obvious that each bar has at least one bar width.
     */
    for (i = 0; i < 4; i++)             /* Total four bars */
    {  
      mod_len[i] = 1;                   /* Each bar has at least one module */
      wval[i] = wtab[i] << 2;
    }
    
    /* Because data character always have 7 modules,
     * we have three modules remain.
     */
    remain = 3;
    
    /* Compute average module width */
    av = 0;
    for (i = 0; i < 4; i++) av += wval[i];
    av = av / 7;
    for (i = 0; i < 4; i++) wval[i] -= av;

    /* Allocate module length from bigger bars */
    while (remain > 0) 
    {
      /* Find biggest */
      maxid = 0;
      if (wval[1] > wval[0]) maxid = 1;
      if (wval[2] > wval[maxid]) maxid = 2;
      if (wval[3] > wval[maxid]) maxid = 3;
      mod_len[maxid]++;
      wval[maxid] -= av;
      remain--;
    }

    if (index < 6)                      /* Left side digit character */
    {	
      i = find_char_val(1, mod_len);
    } 
    else                                /* Right side character */
    {		
      i = find_char_val(0, mod_len);
    }

    return i;
}

static uint16_t Calculate_Threshold(uint16_t* imageData, int imageSize) 
{
    uint64_t totalIntensity = 0;
    uint64_t totalPixels = 0;
    
    uint64_t sumAbove = 0;
    uint64_t countAbove = 0;
    uint64_t sumBelow = 0;
    uint64_t countBelow = 0;
    
    uint16_t threshold;
    uint16_t meanAbove;
    uint16_t meanBelow;

    for (int i = 0; i < imageSize; i++) 
    {
        totalIntensity += imageData[i];
        totalPixels++;
    }

    threshold = (uint16_t)(totalIntensity / totalPixels);

    int prevThreshold = -1;

    while (threshold != prevThreshold) 
    {
        prevThreshold = threshold;

        sumAbove = 0;
        countAbove = 0;
        sumBelow = 0;
        countBelow = 0;

        for (int i = 0; i < imageSize; i++) 
        {
            if (imageData[i] >= threshold) 
            {
                sumAbove += imageData[i];
                countAbove++;
            } 
            
            else 
            {
                sumBelow += imageData[i];
                countBelow++;
            }
        }

        if (countAbove > 0 && countBelow > 0) 
        {
            meanAbove = (uint16_t)(sumAbove / countAbove);
            meanBelow = (uint16_t)(sumBelow / countBelow);
            threshold = (meanAbove + meanBelow) / 2;
        }
    }
    
    #ifdef  TEST

        printf("\n\r Image Threshold: %d", threshold);

    #endif
    

    return threshold;
}

uint8_t Measure_Barcode_Width(uint16_t* Buf, uint16_t pixelThreshold, bool direction)
{
    bool mark = false;
    
    uint8_t idx = 0;      
    
    int whiteWidth = 0;
    int blackWidth = 0;

    if(direction == true)
    {
        // Iterate through the image data to measure the bar widths and counts
        for (int i = 0; i < IMAGE_WIDTH; i++) 
        {
            if (Buf[i] <= pixelThreshold) 
            {
                if ((mark == false) && (whiteWidth > 0))
                {
                    bar_width[idx] = whiteWidth;
                    idx++;

                    whiteWidth = 0;
                }

                // Current pixel is black (below or equal to the threshold)
                blackWidth++;

                mark = true;
            } 

            else 
            {
                if ((mark == true) && (blackWidth > 0))
                {                
                    bar_width[idx] = blackWidth;
                    idx++;

                    blackWidth = 0; 
                }

                // Current pixel is white (above the threshold)
                whiteWidth++;

                mark = false;
            }
            
            if(idx > JAN_BARS)
            {
                return 0;
            }
        }

        if(blackWidth > 0)
        {
            bar_width[idx] = blackWidth;
            idx++;
        }

        else
        {
            bar_width[idx] = whiteWidth;
            idx++;
        }
    }

    else
    {
        // Iterate through the image data to measure the bar widths and counts
        for (int i = IMAGE_WIDTH -1 ; i > 0; i--) 
        {
            if (Buf[i] <= pixelThreshold) 
            {
                if ((mark == false) && (whiteWidth > 0))
                {
                    bar_width[idx] = whiteWidth;
                    idx++;

                    whiteWidth = 0;
                }

                // Current pixel is black (below or equal to the threshold)
                blackWidth++;

                mark = true;
            } 

            else 
            {
                if ((mark == true) && (blackWidth > 0))
                {                
                    bar_width[idx] = blackWidth;
                    idx++;

                    blackWidth = 0; 
                }

                // Current pixel is white (above the threshold)
                whiteWidth++;

                mark = false;
            }
            
            if(idx > JAN_BARS)
            {
                return 0;
            }
        }

        if(blackWidth > 0)
        {
            bar_width[idx] = blackWidth;
            idx++;
        }

        else
        {
            bar_width[idx] = whiteWidth;
            idx++;
        }
    }    

    return idx;
}


int Bar_Decode(uint8_t index)
{
    uint8_t i;
    int prefix, error = 0;
    char *cp;
    short *wp;

    /* We should find total 61 bars. If not, report as error */
    if (index != JAN_BARS) 
    {
        #ifdef TEST
            
            printf("\n\r APP_CAM_Task: Incomplete Scan");
        
        #endif
        
        return 1;
    }

    prefix = 0;
    
    /* Decode left 6 digits */
    wp = bar_width + 4;
    cp = &bar_digits[1];
    
    for (i = 0; i < 6; i++)             /* Left side index starts from zero */
    {	
        index = decode7(i, wp);
        prefix <<= 1;
        
        if (index < 0 || index > 19)    /* Error */
        { 
            *cp = '?';
            error++;
        } 
        
        else 
        {
            if (index >= 10)            /* Even parity */
            {	
                prefix++;
            }
            
            *cp = (index % 10) + '0';
        }
        
        wp += 4;
        cp++;
    }
    
    /* Find first prefix character */
    for (i = 0; i < 10; i++) 
    {
        if (parity_tab[i] == prefix) 
        {
            bar_digits[0] = i + '0';
            break;
        }
    }
  
    if (i == 10) 
    {
        bar_digits[0] = '?';
        error++;
    }

    /* Decode right 6 digits */
    wp = bar_width + 33;
    cp = &bar_digits[7];
    
    for (i = 6; i < 12; i++)            /* right side index starts from six */
    {	
        index = decode7(i, wp);
    
        if (index < 20)                 /* Error */
        {
            *cp = '?';
            error++;
        } 
        
        else 
        {
            *cp = index - 20 + '0';
        }
        
        wp += 4;
        cp++;
    }
      
    *cp = 0;
    
    if (error == 0)                     /* validate check digit */
    {	
        short even_sum, odd_sum;
        int dval;

        even_sum = odd_sum = 0;
        
        for (i = 0; i < 12; i++) 
        {
            dval = bar_digits[i] - '0';
            
            if (i & 1)
                odd_sum += dval;
      
            else
                even_sum += dval;
        }
    
        even_sum += odd_sum * 3;
        i = 10 - (even_sum % 10);
    
        if (i == 10) i = 0;

        if (error == 0) 
        {
            if (('0' + i) != bar_digits[12]) 
            {
                error++;
            }
        }
    }
    
    if(error == 0)
    {               
        // Decode success
        printf("\n\r APP_CAM_Task: Result:   ");
        printf("%s",bar_digits);
    }
    
    return error;
}

/*
 * Decoded 13 digits number is stored in bar_digits[] array.
 */
bool Barcode_Scan(uint16_t* Buf)
{
    uint8_t barCounts, result;

    uint16_t thres = Calculate_Threshold(Buf, IMAGE_WIDTH * IMAGE_HEIGHT);
       
    barCounts = Measure_Barcode_Width(Buf, thres, true);

    result = Bar_Decode(barCounts);

    if(result != 0)
    {
        /*
         * Decode failed.
         * Try to decode data scanned from right to left direction.         
         */
        
        barCounts = Measure_Barcode_Width(Buf + IMAGE_WIDTH, thres, false);

        result = Bar_Decode(barCounts);
        
        if(result != 0)
        {
            return false;
        }
    }
    
    return true;    
}

void Get_Barcode(char* output)
{
    memcpy(output, bar_digits, sizeof(bar_digits));    
}

