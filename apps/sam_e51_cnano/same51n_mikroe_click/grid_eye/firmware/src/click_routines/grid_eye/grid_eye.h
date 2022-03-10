/*******************************************************************************
  GRID EYE click routine header file

  Company
    Microchip Technology Inc.

  File Name
    grid_eye.h

  Summary
    GRID EYE click routine header file.

  Description
    This file defines the interface to the GRID EYE click using I2C PLIB.
    This click routine provides to read and write interfaces on GRID EYE click.

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

#ifndef _GRID_EYE_H
#define _GRID_EYE_H

/**
  Section: Included Files
 */

#include <xc.h>
#include <stdint.h>

#define GRID_EYE_SLAVE_ADDRESS                  0x68

#define GRID_EYE_POWER_MODE_REG                 0x00
#define GRID_EYE_POWER_MODE_NORMAL_MODE_COMMAND 0x00

#define GRID_EYE_RESET_REG                      0x01
#define GRID_EYE_RESET_FLAG_RESET_COMMAND       0x30
#define GRID_EYE_RESET_INITIAL_RESET_COMMAND    0x3F

#define GRID_EYE_FRAME_RATE_REG                 0x02
#define GRID_EYE_FRAME_RATE_1FPS                0x01
#define GRID_EYE_FRAME_RATE_10FPS               0x00

#define GRID_EYE_INTC_REG                       0x03
#define GRID_EYE_INTC_INTMODE_SET               0x01
#define GRID_EYE_INTC_INTMODE_CLEAR             0x00
#define GRID_EYE_INTC_INTEN_SET                 0x01
#define GRID_EYE_INTC_INTEN_CLEAR               0x00

#define GRID_EYE_INTHL_REG                      0x08
#define GRID_EYE_INTHL_VALUE                    0x30

#define GRID_EYE_INTHH_REG                      0x09
#define GRID_EYE_INTHH_VALUE                    0x00

#define GRID_EYE_INTLL_REG                      0x0A
#define GRID_EYE_INTLL_VALUE                    0x15

#define GRID_EYE_INTLH_REG                      0x0B
#define GRID_EYE_INTLH_VALUE                    0x00

#define GRID_EYE_INTSL_REG                      0x0C
#define GRID_EYE_INTSL_VALUE                    0x20

#define GRID_EYE_INTSH_REG                      0x0D
#define GRID_EYE_INTSH_VALUE                    0x00

#define GRID_EYE_TEMP_REG                       0x80

#define GRID_EYE_TRANSFER_SIZE                     1

#define GRID_EYE_FRAMEBUFFER_SIZE                128

#define GRID_EYE_SAMPLES_NUMBER (GRID_EYE_FRAMEBUFFER_SIZE/2)
#define GRID_EYE_SAMPLES_PER_ROW                   8
#define GRID_EYE_SAMPLES_PER_COLUMN GRID_EYE_SAMPLES_PER_ROW


#define GRID_EYE_RED_COLOR_UPPER_LIMIT            30
#define GRID_EYE_ORANGE_COLOR_UPPER_LIMIT         28
#define GRID_EYE_YELLOW_COLOR_UPPER_LIMIT         26
#define GRID_EYE_BLUE_COLOR_UPPER_LIMIT           24
#define GRID_EYE_GREEN_COLOR_UPPER_LIMIT          22

typedef enum
{
    GRID_EYE_CMD_INIT=0,
    GRID_EYE_CMD_WRITE_POWER_MODE_REG,
    GRID_EYE_CMD_WRITE_RESET_REG,
    GRID_EYE_CMD_WRITE_FRAME_RATE_REG,
    GRID_EYE_CMD_WRITE_INTC_REG,
    GRID_EYE_CMD_WRITE_INTHL_REG,
    GRID_EYE_CMD_WRITE_INTHH_REG,
    GRID_EYE_CMD_WRITE_INTLL_REG,
    GRID_EYE_CMD_WRITE_INTLH_REG,
    GRID_EYE_CMD_WRITE_INTSL_REG,
    GRID_EYE_CMD_WRITE_INTSH_REG,
    GRID_EYE_CMD_WRITE_ERROR,
    GRID_EYE_CMD_WRITE_IDLE,
} GRID_EYE_CMD_WRITE;

void GRID_EYE_SensorInit(void);
bool GRID_EYE_WriteRead(uint16_t address, uint8_t* wrData, uint32_t wrSize, uint8_t* rdData, uint32_t rdSize);
bool GRID_EYE_GetWriteReadStatus(void);
void GRID_EYE_SetWriteReadStatus(bool);

#endif // _GRID_EYE_H
