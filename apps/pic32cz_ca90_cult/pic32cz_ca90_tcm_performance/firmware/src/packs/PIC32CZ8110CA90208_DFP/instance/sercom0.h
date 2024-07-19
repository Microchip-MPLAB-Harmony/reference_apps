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
#ifndef _PIC32CZCA90_SERCOM0_INSTANCE_
#define _PIC32CZCA90_SERCOM0_INSTANCE_


/* ========== Instance Parameter definitions for SERCOM0 peripheral ========== */
#define SERCOM0_CLK_REDUCTION                    (1)        /* Reduce clock options to pin 1 for SPI and USART */
#define SERCOM0_DMA                              (1)        /* DMA support implemented? */
#define SERCOM0_DMAC_ID_RX                       (5)        /* Index of DMA RX trigger */
#define SERCOM0_DMAC_ID_TX                       (6)        /* Index of DMA TX trigger */
#define SERCOM0_FIFO_IMPLEMENTED                 (1)        /* FIFO Rx/Tx implemented? */
#define SERCOM0_FIFO_SIZE                        (16)       /* Rx-Tx FIFO size in bytes */
#define SERCOM0_FSYNC_IMPLEMENTED                (1)        /* SPI Frame Synch mode implemented? */
#define SERCOM0_GCLK_ID_CORE                     (21)       
#define SERCOM0_GCLK_ID_SLOW                     (18)       
#define SERCOM0_I2C_0_INT_SRC                    (55)       /* USART/SPI/I2C Error */
#define SERCOM0_I2C_1_INT_SRC                    (59)       /* USART-SPI Receive Complete/ I2C Data Ready */
#define SERCOM0_I2C_2_INT_SRC                    (60)       /* USART Receive Start/ SPI Slave Select Low/ I2C TX FIFO Empty */
#define SERCOM0_I2C_3_INT_SRC                    (61)       /* USART Clear To Send Input Change/ I2C RX FIFO Full */
#define SERCOM0_INSTANCE_ID                      (23)       /* Instance index for SERCOM0 */
#define SERCOM0_MCLK_ID_APB                      (31)       /* Index for SERCOM0 APB clock */
#define SERCOM0_PAC_ID                           (23)       /* Index for SERCOM0 registers write protection */
#define SERCOM0_SPI                              (1)        /* SPI mode implemented? */
#define SERCOM0_SPI_RX_INT_SRC                   (59)       /* USART-SPI Receive Complete/ I2C Data Ready */
#define SERCOM0_SPI_TX_COMPLETE_INT_SRC          (58)       /* USART-SPI Transmit Complete/ I2C Address Match */
#define SERCOM0_SPI_TX_READY_INT_SRC             (57)       /* USART-SPI Data Register Empty/ I2C Stop Received */
#define SERCOM0_TWIM                             (1)        /* TWI Master mode implemented? */
#define SERCOM0_TWIS                             (1)        /* TWI Slave mode implemented? */
#define SERCOM0_TWI_HSMODE                       (1)        /* TWI HighSpeed mode implemented? */
#define SERCOM0_ULTRA_IMPLEMENTATION             (0)        /* ULTRA platform compatibility? */
#define SERCOM0_USART                            (1)        /* USART mode implemented? */
#define SERCOM0_USART_AUTOBAUD                   (1)        /* USART autobaud implemented? */
#define SERCOM0_USART_ERROR_INT_SRC              (55)       /* USART/SPI/I2C Error */
#define SERCOM0_USART_IRDA                       (1)        /* USART IrDA implemented? */
#define SERCOM0_USART_ISO7816                    (1)        /* USART ISO7816 mode implemented? */
#define SERCOM0_USART_LIN_MASTER                 (1)        /* USART LIN Master mode implemented? */
#define SERCOM0_USART_RS485                      (1)        /* USART RS485 mode implemented? */
#define SERCOM0_USART_RX_INT_SRC                 (59)       /* USART-SPI Receive Complete/ I2C Data Ready */
#define SERCOM0_USART_TX_COMPLETE_INT_SRC        (58)       /* USART-SPI Transmit Complete/ I2C Address Match */
#define SERCOM0_USART_TX_READY_INT_SRC           (57)       /* USART-SPI Data Register Empty/ I2C Stop Received */

#endif /* _PIC32CZCA90_SERCOM0_INSTANCE_ */
