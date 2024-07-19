/*
 * Instance header file for PIC32CZ8110CA90208
 *
 * Copyright (c) 2024 Microchip Technology Inc. and its subsidiaries.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/* file generated from device description file (ATDF) version 2024-06-28T20:38:26Z */
#ifndef _PIC32CZCA90_SERCOM1_INSTANCE_
#define _PIC32CZCA90_SERCOM1_INSTANCE_


/* ========== Instance Parameter definitions for SERCOM1 peripheral ========== */
#define SERCOM1_CLK_REDUCTION                    (1)        /* Reduce clock options to pin 1 for SPI and USART */
#define SERCOM1_DMA                              (1)        /* DMA support implemented? */
#define SERCOM1_DMAC_ID_RX                       (7)        /* Index of DMA RX trigger */
#define SERCOM1_DMAC_ID_TX                       (8)        /* Index of DMA TX trigger */
#define SERCOM1_FIFO_IMPLEMENTED                 (1)        /* FIFO Rx/Tx implemented? */
#define SERCOM1_FIFO_SIZE                        (16)       /* Rx-Tx FIFO size in bytes */
#define SERCOM1_FSYNC_IMPLEMENTED                (1)        /* SPI Frame Synch mode implemented? */
#define SERCOM1_GCLK_ID_CORE                     (22)       
#define SERCOM1_GCLK_ID_SLOW                     (18)       
#define SERCOM1_I2C_0_INT_SRC                    (62)       /* USART/SPI/I2C Error */
#define SERCOM1_I2C_1_INT_SRC                    (66)       /* USART-SPI Receive Complete/ I2C Data Ready */
#define SERCOM1_I2C_2_INT_SRC                    (67)       /* USART Receive Start/ SPI Slave Select Low/ I2C TX FIFO Empty */
#define SERCOM1_I2C_3_INT_SRC                    (68)       /* USART Clear To Send Input Change/ I2C RX FIFO Full */
#define SERCOM1_INSTANCE_ID                      (24)       /* Instance index for SERCOM1 */
#define SERCOM1_MCLK_ID_APB                      (32)       /* Index for SERCOM1 APB clock */
#define SERCOM1_PAC_ID                           (24)       /* Index for SERCOM1 registers write protection */
#define SERCOM1_SPI                              (1)        /* SPI mode implemented? */
#define SERCOM1_SPI_RX_INT_SRC                   (66)       /* USART-SPI Receive Complete/ I2C Data Ready */
#define SERCOM1_SPI_TX_COMPLETE_INT_SRC          (65)       /* USART-SPI Transmit Complete/ I2C Address Match */
#define SERCOM1_SPI_TX_READY_INT_SRC             (64)       /* USART-SPI Data Register Empty/ I2C Stop Received */
#define SERCOM1_TWIM                             (1)        /* TWI Master mode implemented? */
#define SERCOM1_TWIS                             (1)        /* TWI Slave mode implemented? */
#define SERCOM1_TWI_HSMODE                       (1)        /* TWI HighSpeed mode implemented? */
#define SERCOM1_ULTRA_IMPLEMENTATION             (0)        /* ULTRA platform compatibility? */
#define SERCOM1_USART                            (1)        /* USART mode implemented? */
#define SERCOM1_USART_AUTOBAUD                   (1)        /* USART autobaud implemented? */
#define SERCOM1_USART_ERROR_INT_SRC              (62)       /* USART/SPI/I2C Error */
#define SERCOM1_USART_IRDA                       (1)        /* USART IrDA implemented? */
#define SERCOM1_USART_ISO7816                    (1)        /* USART ISO7816 mode implemented? */
#define SERCOM1_USART_LIN_MASTER                 (1)        /* USART LIN Master mode implemented? */
#define SERCOM1_USART_RS485                      (1)        /* USART RS485 mode implemented? */
#define SERCOM1_USART_RX_INT_SRC                 (66)       /* USART-SPI Receive Complete/ I2C Data Ready */
#define SERCOM1_USART_TX_COMPLETE_INT_SRC        (65)       /* USART-SPI Transmit Complete/ I2C Address Match */
#define SERCOM1_USART_TX_READY_INT_SRC           (64)       /* USART-SPI Data Register Empty/ I2C Stop Received */

#endif /* _PIC32CZCA90_SERCOM1_INSTANCE_ */
