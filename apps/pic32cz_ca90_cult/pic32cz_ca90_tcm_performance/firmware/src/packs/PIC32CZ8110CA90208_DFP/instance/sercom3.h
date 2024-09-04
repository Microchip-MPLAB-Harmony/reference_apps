/*
 * Instance header file for PIC32CZ8110CA90208
 *
 * Copyright (c) 2023 Microchip Technology Inc. and its subsidiaries.
 *
 * Subject to your compliance with these terms, you may use Microchip software and any derivatives
 * exclusively with Microchip products. It is your responsibility to comply with third party license
 * terms applicable to your use of third party software (including open source software) that may
 * accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY,
 * APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF
 * MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT
 * EXCEED THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/* file generated from device description version 2023-05-18T19:14:33Z */
#ifndef _PIC32CZCA90_SERCOM3_INSTANCE_
#define _PIC32CZCA90_SERCOM3_INSTANCE_


/* ========== Instance Parameter definitions for SERCOM3 peripheral ========== */
#define SERCOM3_CLK_REDUCTION                    (1)        /* Reduce clock options to pin 1 for SPI and USART */
#define SERCOM3_DMA                              (1)        /* DMA support implemented? */
#define SERCOM3_DMAC_ID_RX                       (11)       /* Index of DMA RX trigger */
#define SERCOM3_DMAC_ID_TX                       (12)       /* Index of DMA TX trigger */
#define SERCOM3_FIFO_IMPLEMENTED                 (1)        /* FIFO Rx/Tx implemented? */
#define SERCOM3_FIFO_SIZE                        (16)       /* Rx-Tx FIFO size in bytes */
#define SERCOM3_FSYNC_IMPLEMENTED                (1)        /* SPI Frame Synch mode implemented? */
#define SERCOM3_GCLK_ID_CORE                     (24)       
#define SERCOM3_GCLK_ID_SLOW                     (19)       
#define SERCOM3_I2C_0_INT_SRC                    (76)       /* USART/SPI/I2C Error */
#define SERCOM3_I2C_1_INT_SRC                    (80)       /* USART-SPI Receive Complete/ I2C Data Ready */
#define SERCOM3_I2C_2_INT_SRC                    (81)       /* USART Receive Start/ SPI Slave Select Low/ I2C TX FIFO Empty */
#define SERCOM3_I2C_3_INT_SRC                    (82)       /* USART Clear To Send Input Change/ I2C RX FIFO Full */
#define SERCOM3_INSTANCE_ID                      (26)       /* Instance index for SERCOM3 */
#define SERCOM3_MCLK_ID_APB                      (34)       /* Index for SERCOM3 APB clock */
#define SERCOM3_PAC_ID                           (26)       /* Index for SERCOM3 registers write protection */
#define SERCOM3_SPI                              (1)        /* SPI mode implemented? */
#define SERCOM3_SPI_RX_INT_SRC                   (80)       /* USART-SPI Receive Complete/ I2C Data Ready */
#define SERCOM3_SPI_TX_COMPLETE_INT_SRC          (79)       /* USART-SPI Transmit Complete/ I2C Address Match */
#define SERCOM3_SPI_TX_READY_INT_SRC             (78)       /* USART-SPI Data Register Empty/ I2C Stop Received */
#define SERCOM3_TWIM                             (1)        /* TWI Master mode implemented? */
#define SERCOM3_TWIS                             (1)        /* TWI Slave mode implemented? */
#define SERCOM3_TWI_HSMODE                       (1)        /* TWI HighSpeed mode implemented? */
#define SERCOM3_ULTRA_IMPLEMENTATION             (0)        /* ULTRA platform compatibility? */
#define SERCOM3_USART                            (1)        /* USART mode implemented? */
#define SERCOM3_USART_AUTOBAUD                   (1)        /* USART autobaud implemented? */
#define SERCOM3_USART_ERROR_INT_SRC              (76)       /* USART/SPI/I2C Error */
#define SERCOM3_USART_IRDA                       (1)        /* USART IrDA implemented? */
#define SERCOM3_USART_ISO7816                    (1)        /* USART ISO7816 mode implemented? */
#define SERCOM3_USART_LIN_MASTER                 (1)        /* USART LIN Master mode implemented? */
#define SERCOM3_USART_RS485                      (1)        /* USART RS485 mode implemented? */
#define SERCOM3_USART_RX_INT_SRC                 (80)       /* USART-SPI Receive Complete/ I2C Data Ready */
#define SERCOM3_USART_TX_COMPLETE_INT_SRC        (79)       /* USART-SPI Transmit Complete/ I2C Address Match */
#define SERCOM3_USART_TX_READY_INT_SRC           (78)       /* USART-SPI Data Register Empty/ I2C Stop Received */

#endif /* _PIC32CZCA90_SERCOM3_INSTANCE_ */
