/*******************************************************************************
  GRID EYE click routine example header file

  Company
    Microchip Technology Inc.

  File Name
    grid_eye_example.h

  Summary
    GRID EYE click routine example header file.

  Description
    This file defines the usage of the GRID EYE click routine APIs.

  Remarks:
    None.

 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*
    (c) 2022 Microchip Technology Inc. and its subsidiaries. You may use this
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

#ifndef _GRID_EYE_EXAMPLE_H
#define _GRID_EYE_EXAMPLE_H

#define BLUE                       0
#define RED                        1
#define ORANGE                     2
#define YELLOW                     3
#define GREEN                      4
#define LIGHT_YELLOW               5

#define GRID_EYE_TABLE_64_FIRST_SAMPLE_INDEX (GRID_EYE_SAMPLES_NUMBER - GRID_EYE_SAMPLES_PER_ROW)
#define GRIDEYE_TEMP_COEF 0.25

void GRID_EYE_Example(void);

#endif // _GRID_EYE_EXAMPLE_H
