/*******************************************************************************
  GRID EYE click routine source file

  Company
    Microchip Technology Inc.

  File Name
    grid_eye.c

  Summary
    GRID EYE click routine implementation file.

  Description
    This file defines the interface to the GRID EYE click using I2C PLIB.
    This click routine provides to read and write on GRID EYE click.

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

/**
  Section: Included Files
 */

#include <string.h>
#include "definitions.h"                // SYS function prototypes
#include "../click_interface.h"
#include "grid_eye.h"

static GRID_EYE_CMD_WRITE grid_eye_cmd_state = GRID_EYE_CMD_INIT;
static uint8_t txBuffer[10] = {0};
static volatile bool gridEyeTransferStatus = false;
volatile bool grid_eye_init = false;

static void GRID_EYE_I2C_TransferEventHandler(uintptr_t context)
{
    if(CLICK_GRID_EYE_I2C_ErrorGet() == SERCOM_I2C_ERROR_NONE)
    {
        gridEyeTransferStatus = true;
    }
    else
    {
        gridEyeTransferStatus = false;
    }
}

void GRID_EYE_SensorInit(void)
{
    while(grid_eye_init == false)
    {
        switch(grid_eye_cmd_state)
        {
            case GRID_EYE_CMD_INIT:
            {
                CLICK_GRID_EYE_I2C_CallbackRegister(GRID_EYE_I2C_TransferEventHandler, (uintptr_t) NULL);
                CLICK_GRID_EYE_SYSTICK_TimerStart();
                grid_eye_cmd_state = GRID_EYE_CMD_WRITE_POWER_MODE_REG;
                break;
            }

            case GRID_EYE_CMD_WRITE_POWER_MODE_REG:
            {
                txBuffer[0] = GRID_EYE_POWER_MODE_REG;
                txBuffer[1] = GRID_EYE_POWER_MODE_NORMAL_MODE_COMMAND;

                if (CLICK_GRID_EYE_I2C_Write(GRID_EYE_SLAVE_ADDRESS, &txBuffer[0], GRID_EYE_TRANSFER_SIZE) == false)
                {
                    grid_eye_cmd_state = GRID_EYE_CMD_WRITE_ERROR;
                }
                else
                {
                    CLICK_GRID_EYE_SYSTICK_DelayMs(50);
                    grid_eye_cmd_state = GRID_EYE_CMD_WRITE_RESET_REG;
                }
                break;
            }

            case GRID_EYE_CMD_WRITE_RESET_REG:
            {
                txBuffer[0] = GRID_EYE_RESET_REG;
                txBuffer[1] = GRID_EYE_RESET_FLAG_RESET_COMMAND;
                if (CLICK_GRID_EYE_I2C_Write(GRID_EYE_SLAVE_ADDRESS, &txBuffer[0], GRID_EYE_TRANSFER_SIZE) == false)
                {
                    grid_eye_cmd_state = GRID_EYE_CMD_WRITE_ERROR;
                }
                else
                {
                    CLICK_GRID_EYE_SYSTICK_DelayMs(50);
                    grid_eye_cmd_state = GRID_EYE_CMD_WRITE_FRAME_RATE_REG;
                }
                break;
            }

            case GRID_EYE_CMD_WRITE_FRAME_RATE_REG:
            {
                txBuffer[0] = GRID_EYE_FRAME_RATE_REG;
                txBuffer[1] = GRID_EYE_FRAME_RATE_10FPS;
                if (CLICK_GRID_EYE_I2C_Write(GRID_EYE_SLAVE_ADDRESS, &txBuffer[0], GRID_EYE_TRANSFER_SIZE) == false)
                {
                    grid_eye_cmd_state = GRID_EYE_CMD_WRITE_ERROR;
                }
                else
                {
                    CLICK_GRID_EYE_SYSTICK_DelayMs(100);
                    grid_eye_cmd_state = GRID_EYE_CMD_WRITE_INTC_REG;
                }
                break;
            }

            case GRID_EYE_CMD_WRITE_INTC_REG:
            {
                txBuffer[0] = GRID_EYE_INTC_REG;
                txBuffer[1] = GRID_EYE_INTC_INTMODE_SET;
                if (CLICK_GRID_EYE_I2C_Write(GRID_EYE_SLAVE_ADDRESS, &txBuffer[0], GRID_EYE_TRANSFER_SIZE) == false)
                {
                    grid_eye_cmd_state = GRID_EYE_CMD_WRITE_ERROR;
                }
                else
                {
                    CLICK_GRID_EYE_SYSTICK_DelayMs(50);
                    grid_eye_cmd_state = GRID_EYE_CMD_WRITE_INTHL_REG;
                }
                break;
            }

            case GRID_EYE_CMD_WRITE_INTHL_REG:
            {
                txBuffer[0] = GRID_EYE_INTHL_REG;
                txBuffer[1] = GRID_EYE_INTHL_VALUE;
                if (CLICK_GRID_EYE_I2C_Write(GRID_EYE_SLAVE_ADDRESS, &txBuffer[0], GRID_EYE_TRANSFER_SIZE) == false)
                {
                    grid_eye_cmd_state = GRID_EYE_CMD_WRITE_ERROR;
                }
                else
                {
                    CLICK_GRID_EYE_SYSTICK_DelayMs(50);
                    grid_eye_cmd_state = GRID_EYE_CMD_WRITE_INTHH_REG;
                }
                break;
            }

            case GRID_EYE_CMD_WRITE_INTHH_REG:
            {
                txBuffer[0] = GRID_EYE_INTHH_REG;
                txBuffer[1] = GRID_EYE_INTHH_VALUE;
                if (CLICK_GRID_EYE_I2C_Write(GRID_EYE_SLAVE_ADDRESS, &txBuffer[0], GRID_EYE_TRANSFER_SIZE) == false)
                {
                    grid_eye_cmd_state = GRID_EYE_CMD_WRITE_ERROR;
                }
                else
                {
                    CLICK_GRID_EYE_SYSTICK_DelayMs(50);
                    grid_eye_cmd_state = GRID_EYE_CMD_WRITE_INTLL_REG;
                }
                break;
            }

            case GRID_EYE_CMD_WRITE_INTLL_REG:
            {
                txBuffer[0] = GRID_EYE_INTLL_REG;
                txBuffer[1] = GRID_EYE_INTLL_VALUE;
                if (CLICK_GRID_EYE_I2C_Write(GRID_EYE_SLAVE_ADDRESS, &txBuffer[0], GRID_EYE_TRANSFER_SIZE) == false)
                {
                    grid_eye_cmd_state = GRID_EYE_CMD_WRITE_ERROR;
                }
                else
                {
                    CLICK_GRID_EYE_SYSTICK_DelayMs(50);
                    grid_eye_cmd_state = GRID_EYE_CMD_WRITE_INTLH_REG;
                }
                break;
            }

            case GRID_EYE_CMD_WRITE_INTLH_REG:
            {
                txBuffer[0] = GRID_EYE_INTLH_REG;
                txBuffer[1] = GRID_EYE_INTLH_VALUE;
                if (CLICK_GRID_EYE_I2C_Write(GRID_EYE_SLAVE_ADDRESS, &txBuffer[0], GRID_EYE_TRANSFER_SIZE) == false)
                {
                    grid_eye_cmd_state = GRID_EYE_CMD_WRITE_ERROR;
                }
                else
                {
                    CLICK_GRID_EYE_SYSTICK_DelayMs(50);
                    grid_eye_cmd_state = GRID_EYE_CMD_WRITE_INTSL_REG;
                }
                break;
            }

            case GRID_EYE_CMD_WRITE_INTSL_REG:
            {
                txBuffer[0] = GRID_EYE_INTSL_REG;
                txBuffer[1] = GRID_EYE_INTSL_VALUE;
                if (CLICK_GRID_EYE_I2C_Write(GRID_EYE_SLAVE_ADDRESS, &txBuffer[0], GRID_EYE_TRANSFER_SIZE) == false)
                {
                    grid_eye_cmd_state = GRID_EYE_CMD_WRITE_ERROR;
                }
                else
                {
                    CLICK_GRID_EYE_SYSTICK_DelayMs(100);
                    grid_eye_cmd_state = GRID_EYE_CMD_WRITE_INTSH_REG;
                }
                break;
            }

            case GRID_EYE_CMD_WRITE_INTSH_REG:
            {
                txBuffer[0] = GRID_EYE_INTSH_REG;
                txBuffer[1] = GRID_EYE_INTSH_VALUE;
                if (CLICK_GRID_EYE_I2C_Write(GRID_EYE_SLAVE_ADDRESS, &txBuffer[0], GRID_EYE_TRANSFER_SIZE) == false)
                {
                    grid_eye_cmd_state = GRID_EYE_CMD_WRITE_ERROR;
                }
                else
                {
                    CLICK_GRID_EYE_SYSTICK_DelayMs(50);
                    grid_eye_init = true;
                }
                break;
            }

            case GRID_EYE_CMD_WRITE_ERROR:
            {

                printf("Error in initializing GRID EYE Click!");
                grid_eye_cmd_state = GRID_EYE_CMD_WRITE_IDLE;
                break;
            }

            case GRID_EYE_CMD_WRITE_IDLE:
                break;

            default:
                break;
        }
    }
}

bool GRID_EYE_WriteRead(uint16_t address, uint8_t* wrData, uint32_t wrSize, uint8_t* rdData, uint32_t rdSize)
{
    return CLICK_GRID_EYE_I2C_WriteRead(address, wrData, wrSize, rdData, rdSize);
}

bool GRID_EYE_GetWriteReadStatus(void)
{
    return gridEyeTransferStatus;
}

void GRID_EYE_SetWriteReadStatus(bool status)
{
    gridEyeTransferStatus = status;
}