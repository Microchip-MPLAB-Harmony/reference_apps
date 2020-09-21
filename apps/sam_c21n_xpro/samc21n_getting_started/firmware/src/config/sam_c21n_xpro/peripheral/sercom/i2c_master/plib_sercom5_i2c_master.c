/*******************************************************************************
  Serial Communication Interface Inter-Integrated Circuit (SERCOM I2C) Library
  Source File

  Company:
    Microchip Technology Inc.

  File Name:
    plib_sercom5_i2c.c

  Summary:
    SERCOM I2C PLIB Implementation file

  Description:
    This file defines the interface to the SERCOM I2C peripheral library.
    This library provides access to and control of the associated peripheral
    instance.

*******************************************************************************/
// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "plib_sercom5_i2c_master.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************


/* SERCOM5 I2C baud value */
#define SERCOM5_I2CM_BAUD_VALUE         (0xE8U)


static SERCOM_I2C_OBJ sercom5I2CObj;

// *****************************************************************************
// *****************************************************************************
// Section: SERCOM5 I2C Implementation
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************

void SERCOM5_I2C_Initialize(void)
{
    /* Reset the module */
    SERCOM5_REGS->I2CM.SERCOM_CTRLA = SERCOM_I2CM_CTRLA_SWRST_Msk ;

    /* Wait for synchronization */
    while(SERCOM5_REGS->I2CM.SERCOM_SYNCBUSY);

    /* Enable smart mode enable */
    SERCOM5_REGS->I2CM.SERCOM_CTRLB = SERCOM_I2CM_CTRLB_SMEN_Msk;

    /* Wait for synchronization */
    while(SERCOM5_REGS->I2CM.SERCOM_SYNCBUSY);

    /* Baud rate - Master Baud Rate*/
    SERCOM5_REGS->I2CM.SERCOM_BAUD = SERCOM5_I2CM_BAUD_VALUE;

    /* Set Operation Mode (Master), SDA Hold time, run in stand by and i2c master enable */
    SERCOM5_REGS->I2CM.SERCOM_CTRLA = SERCOM_I2CM_CTRLA_MODE_I2C_MASTER | SERCOM_I2CM_CTRLA_SDAHOLD_75NS | SERCOM_I2CM_CTRLA_SPEED_STANDARD_AND_FAST_MODE | SERCOM_I2CM_CTRLA_SCLSM(0) | SERCOM_I2CM_CTRLA_ENABLE_Msk ;

    /* Wait for synchronization */
    while(SERCOM5_REGS->I2CM.SERCOM_SYNCBUSY);

    /* Initial Bus State: IDLE */
    SERCOM5_REGS->I2CM.SERCOM_STATUS = SERCOM_I2CM_STATUS_BUSSTATE(0x01);

    /* Wait for synchronization */
    while(SERCOM5_REGS->I2CM.SERCOM_SYNCBUSY);

    /* Initialize the SERCOM5 PLib Object */
    sercom5I2CObj.error = SERCOM_I2C_ERROR_NONE;
    sercom5I2CObj.state = SERCOM_I2C_STATE_IDLE;

    /* Enable all Interrupts */
    SERCOM5_REGS->I2CM.SERCOM_INTENSET = SERCOM_I2CM_INTENSET_Msk;
}

static bool SERCOM5_I2C_CalculateBaudValue(uint32_t srcClkFreq, uint32_t i2cClkSpeed, uint32_t* baudVal)
{
    uint32_t baudValue;

    /* Reference clock frequency must be atleast two times the baud rate */
    if (srcClkFreq < (2*i2cClkSpeed))
    {
        return false;
    }

    if (i2cClkSpeed <= 1000000)
    {
        /* Standard, FM and FM+ baud calculation */
        baudValue = (uint32_t) (((((float)srcClkFreq)/i2cClkSpeed) - ((((float)srcClkFreq) * (100/1000000000.0)) + 10)));
    }
    else
    {
        return false;
    }
    if (i2cClkSpeed <= 400000)
    {
        /* For I2C clock speed upto 400 kHz, the value of BAUD<7:0> determines both SCL_L and SCL_H with SCL_L = SCL_H */
        if (baudValue > (0xFF * 2))
        {
            /* Set baud rate to the minimum possible value */
            baudValue = 0xFF;
        }
        else if (baudValue <= 1)
        {
            /* Baud value cannot be 0. Set baud rate to maximum possible value */
            baudValue = 1;
        }
        else
        {
            baudValue /= 2;
        }
    }
    else
    {
        /* To maintain the ratio of SCL_L:SCL_H to 2:1, the max value of BAUD_LOW<15:8>:BAUD<7:0> can be 0xFF:0x7F. Hence BAUD_LOW + BAUD can not exceed 255+127 = 382 */
        if (baudValue >= 382)
        {
            /* Set baud rate to the minimum possible value while maintaining SCL_L:SCL_H to 2:1 */
            baudValue = (0xFF << 8) | (0x7F);
        }
        else if (baudValue <= 3)
        {
            /* Baud value cannot be 0. Set baud rate to maximum possible value while maintaining SCL_L:SCL_H to 2:1 */
            baudValue = (2 << 8) | 1;
        }
        else
        {
            /* For Fm+ mode, I2C SCL_L:SCL_H to 2:1 */
            baudValue  = ((((baudValue * 2)/3) << 8) | (baudValue/3));
        }
    }
    *baudVal = baudValue;
    return true;
}

bool SERCOM5_I2C_TransferSetup(SERCOM_I2C_TRANSFER_SETUP* setup, uint32_t srcClkFreq )
{
    uint32_t baudValue;
    uint32_t i2cClkSpeed;
    uint32_t i2cSpeedMode = 0;

    if (setup == NULL)
    {
        return false;
    }

    i2cClkSpeed = setup->clkSpeed;

    if( srcClkFreq == 0)
    {
        srcClkFreq = 48000000UL;
    }

    if (SERCOM5_I2C_CalculateBaudValue(srcClkFreq, i2cClkSpeed, &baudValue) == false)
    {
        return false;
    }

    if (i2cClkSpeed > 400000)
    {
        i2cSpeedMode = 1;
    }

    /* Disable the I2C before changing the I2C clock speed */
    SERCOM5_REGS->I2CM.SERCOM_CTRLA &= ~SERCOM_I2CM_CTRLA_ENABLE_Msk;

    /* Wait for synchronization */
    while(SERCOM5_REGS->I2CM.SERCOM_SYNCBUSY);

    /* Baud rate - Master Baud Rate*/
    SERCOM5_REGS->I2CM.SERCOM_BAUD = baudValue;

    SERCOM5_REGS->I2CM.SERCOM_CTRLA  = ((SERCOM5_REGS->I2CM.SERCOM_CTRLA & ~SERCOM_I2CM_CTRLA_SPEED_Msk) | (SERCOM_I2CM_CTRLA_SPEED(i2cSpeedMode)));

    /* Re-enable the I2C module */
    SERCOM5_REGS->I2CM.SERCOM_CTRLA |= SERCOM_I2CM_CTRLA_ENABLE_Msk;

    /* Wait for synchronization */
    while(SERCOM5_REGS->I2CM.SERCOM_SYNCBUSY);

    /* Since the I2C module was disabled, re-initialize the bus state to IDLE */
    SERCOM5_REGS->I2CM.SERCOM_STATUS = SERCOM_I2CM_STATUS_BUSSTATE(0x01);

    /* Wait for synchronization */
    while(SERCOM5_REGS->I2CM.SERCOM_SYNCBUSY);

    return true;
}

void SERCOM5_I2C_CallbackRegister(SERCOM_I2C_CALLBACK callback, uintptr_t contextHandle)
{
    sercom5I2CObj.callback = callback;

    sercom5I2CObj.context  = contextHandle;
}


static void SERCOM5_I2C_SendAddress(uint16_t address, bool dir)
{
    if(dir == I2C_TRANSFER_READ)
    {
        /* <xxxx-xxxR> <read-data> <P> */

        /* Next state will be to read data */
        sercom5I2CObj.state = SERCOM_I2C_STATE_TRANSFER_READ;
    }
    else
    {
        /* <xxxx-xxxW> <write-data> <P> */

        /* Next state will be to write data */
        sercom5I2CObj.state = SERCOM_I2C_STATE_TRANSFER_WRITE;
    }


    SERCOM5_REGS->I2CM.SERCOM_ADDR = (address << 1) | dir;

    /* Wait for synchronization */
    while(SERCOM5_REGS->I2CM.SERCOM_SYNCBUSY);
}

static void SERCOM5_I2C_InitiateTransfer(uint16_t address, bool dir)
{
    sercom5I2CObj.writeCount = 0;
    sercom5I2CObj.readCount = 0;

    /* Clear all flags */
    SERCOM5_REGS->I2CM.SERCOM_INTFLAG = SERCOM_I2CM_INTFLAG_Msk;

    /* Smart mode enabled with SCLSM = 0, - ACK is set to send while receiving the data */
    SERCOM5_REGS->I2CM.SERCOM_CTRLB &= ~SERCOM_I2CM_CTRLB_ACKACT_Msk;

    /* Wait for synchronization */
    while(SERCOM5_REGS->I2CM.SERCOM_SYNCBUSY);

    SERCOM5_I2C_SendAddress(address, dir);
}

static bool SERCOM5_I2C_XferSetup(
    uint16_t address,
    uint8_t* wrData,
    uint32_t wrLength,
    uint8_t* rdData,
    uint32_t rdLength,
    bool dir,
    bool isHighSpeed
)
{
    /* Check for ongoing transfer */
    if(sercom5I2CObj.state != SERCOM_I2C_STATE_IDLE)
    {
        return false;
    }

    sercom5I2CObj.address        = address;
    sercom5I2CObj.readBuffer     = rdData;
    sercom5I2CObj.readSize       = rdLength;
    sercom5I2CObj.writeBuffer    = wrData;
    sercom5I2CObj.writeSize      = wrLength;
    sercom5I2CObj.transferDir    = dir;
    sercom5I2CObj.isHighSpeed    = isHighSpeed;
    sercom5I2CObj.error          = SERCOM_I2C_ERROR_NONE;


    SERCOM5_I2C_InitiateTransfer(address, dir);

    return true;
}

bool SERCOM5_I2C_Read(uint16_t address, uint8_t* rdData, uint32_t rdLength)
{
    return SERCOM5_I2C_XferSetup(address, NULL, 0, rdData, rdLength, I2C_TRANSFER_READ, false);
}

bool SERCOM5_I2C_Write(uint16_t address, uint8_t* wrData, uint32_t wrLength)
{
    return SERCOM5_I2C_XferSetup(address, wrData, wrLength, NULL, 0, I2C_TRANSFER_WRITE, false);
}

bool SERCOM5_I2C_WriteRead(uint16_t address, uint8_t* wrData, uint32_t wrLength, uint8_t* rdData, uint32_t rdLength)
{
    return SERCOM5_I2C_XferSetup(address, wrData, wrLength, rdData, rdLength, I2C_TRANSFER_WRITE, false);
}


bool SERCOM5_I2C_IsBusy(void)
{
    if((sercom5I2CObj.state == SERCOM_I2C_STATE_IDLE) && ((SERCOM5_REGS->I2CM.SERCOM_STATUS & SERCOM_I2CM_STATUS_BUSSTATE_Msk) == SERCOM_I2CM_STATUS_BUSSTATE(0x01)))
    {
        return false;
    }
    else
    {
        return true;
    }
}

SERCOM_I2C_ERROR SERCOM5_I2C_ErrorGet(void)
{
    return sercom5I2CObj.error;
}

void SERCOM5_I2C_InterruptHandler(void)
{
    if(SERCOM5_REGS->I2CM.SERCOM_INTENSET != 0)
    {
        /* Checks if the arbitration lost in multi-master scenario */
        if((SERCOM5_REGS->I2CM.SERCOM_STATUS & SERCOM_I2CM_STATUS_ARBLOST_Msk) == SERCOM_I2CM_STATUS_ARBLOST_Msk)
        {
            /* Set Error status */
            sercom5I2CObj.state = SERCOM_I2C_STATE_ERROR;
            sercom5I2CObj.error = SERCOM_I2C_ERROR_BUS;

        }
        /* Check for Bus Error during transmission */
        else if((SERCOM5_REGS->I2CM.SERCOM_STATUS & SERCOM_I2CM_STATUS_BUSERR_Msk) == SERCOM_I2CM_STATUS_BUSERR_Msk)
        {
            /* Set Error status */
            sercom5I2CObj.state = SERCOM_I2C_STATE_ERROR;
            sercom5I2CObj.error = SERCOM_I2C_ERROR_BUS;
        }
        /* Checks slave acknowledge for address or data */
        else if((SERCOM5_REGS->I2CM.SERCOM_STATUS & SERCOM_I2CM_STATUS_RXNACK_Msk) == SERCOM_I2CM_STATUS_RXNACK_Msk)
        {
            sercom5I2CObj.state = SERCOM_I2C_STATE_ERROR;
            sercom5I2CObj.error = SERCOM_I2C_ERROR_NAK;
        }
        else
        {
            switch(sercom5I2CObj.state)
            {
                case SERCOM_I2C_REINITIATE_TRANSFER:

                    if (sercom5I2CObj.writeSize != 0)
                    {
                        /* Initiate Write transfer */
                        SERCOM5_I2C_InitiateTransfer(sercom5I2CObj.address, false);
                    }
                    else
                    {
                        /* Initiate Read transfer */
                        SERCOM5_I2C_InitiateTransfer(sercom5I2CObj.address, true);
                    }

                    break;


                case SERCOM_I2C_STATE_IDLE:

                    break;



                case SERCOM_I2C_STATE_TRANSFER_WRITE:

                    if (sercom5I2CObj.writeCount == (sercom5I2CObj.writeSize))
                    {
                        if(sercom5I2CObj.readSize != 0)
                        {

                            /* Write 7bit address with direction (ADDR.ADDR[0]) equal to 1*/
                            SERCOM5_REGS->I2CM.SERCOM_ADDR =  (sercom5I2CObj.address << 1) | I2C_TRANSFER_READ;

                            /* Wait for synchronization */
                            while(SERCOM5_REGS->I2CM.SERCOM_SYNCBUSY);

                            sercom5I2CObj.state = SERCOM_I2C_STATE_TRANSFER_READ;

                        }
                        else
                        {
                            SERCOM5_REGS->I2CM.SERCOM_CTRLB |= SERCOM_I2CM_CTRLB_CMD(3);

                            /* Wait for synchronization */
                            while(SERCOM5_REGS->I2CM.SERCOM_SYNCBUSY);

                            sercom5I2CObj.state = SERCOM_I2C_STATE_TRANSFER_DONE;
                        }
                    }
                    /* Write next byte */
                    else
                    {
                        SERCOM5_REGS->I2CM.SERCOM_DATA = sercom5I2CObj.writeBuffer[sercom5I2CObj.writeCount++];
                    }

                    break;

                case SERCOM_I2C_STATE_TRANSFER_READ:

                    if(sercom5I2CObj.readCount == (sercom5I2CObj.readSize - 1))
                    {
                        /* Set NACK and send stop condition to the slave from master */
                        SERCOM5_REGS->I2CM.SERCOM_CTRLB |= SERCOM_I2CM_CTRLB_ACKACT_Msk | SERCOM_I2CM_CTRLB_CMD(3);

                        /* Wait for synchronization */
                        while(SERCOM5_REGS->I2CM.SERCOM_SYNCBUSY);

                        sercom5I2CObj.state = SERCOM_I2C_STATE_TRANSFER_DONE;
                    }

                    /* Read the received data */
                    sercom5I2CObj.readBuffer[sercom5I2CObj.readCount++] = SERCOM5_REGS->I2CM.SERCOM_DATA;


                    break;

                default:

                    break;
            }
        }

        /* Error Status */
        if(sercom5I2CObj.state == SERCOM_I2C_STATE_ERROR)
        {
            /* Reset the PLib objects and Interrupts */
            sercom5I2CObj.state = SERCOM_I2C_STATE_IDLE;

            /* Generate STOP condition */
            SERCOM5_REGS->I2CM.SERCOM_CTRLB |= SERCOM_I2CM_CTRLB_CMD(3);

            /* Wait for synchronization */
            while(SERCOM5_REGS->I2CM.SERCOM_SYNCBUSY);

            SERCOM5_REGS->I2CM.SERCOM_INTFLAG = SERCOM_I2CM_INTFLAG_Msk;

            if (sercom5I2CObj.callback != NULL)
            {
                sercom5I2CObj.callback(sercom5I2CObj.context);
            }
        }
        /* Transfer Complete */
        else if(sercom5I2CObj.state == SERCOM_I2C_STATE_TRANSFER_DONE)
        {
            /* Reset the PLib objects and interrupts */
            sercom5I2CObj.state = SERCOM_I2C_STATE_IDLE;
            sercom5I2CObj.error = SERCOM_I2C_ERROR_NONE;

            SERCOM5_REGS->I2CM.SERCOM_INTFLAG = SERCOM_I2CM_INTFLAG_Msk;

            /* Wait for the NAK and STOP bit to be transmitted out and I2C state machine to rest in IDLE state */
            while((SERCOM5_REGS->I2CM.SERCOM_STATUS & SERCOM_I2CM_STATUS_BUSSTATE_Msk) != SERCOM_I2CM_STATUS_BUSSTATE(0x01));

            if(sercom5I2CObj.callback != NULL)
            {
                sercom5I2CObj.callback(sercom5I2CObj.context);
            }

        }
    }

    return;
}