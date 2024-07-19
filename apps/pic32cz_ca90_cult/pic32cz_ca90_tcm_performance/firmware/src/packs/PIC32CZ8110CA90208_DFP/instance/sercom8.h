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
#ifndef _PIC32CZCA90_SERCOM8_INSTANCE_
#define _PIC32CZCA90_SERCOM8_INSTANCE_


/* ========== Instance Parameter definitions for SERCOM8 peripheral ========== */
#define SERCOM8_CLK_REDUCTION                    (1)        /* Reduce clock options to pin 1 for SPI and USART */
#define SERCOM8_DMA                              (1)        /* DMA support implemented? */
#define SERCOM8_DMAC_ID_RX                       (21)       /* Index of DMA RX trigger */
#define SERCOM8_DMAC_ID_TX                       (22)       /* Index of DMA TX trigger */
#define SERCOM8_FIFO_IMPLEMENTED                 (1)        /* FIFO Rx/Tx implemented? */
#define SERCOM8_FIFO_SIZE                        (16)       /* Rx-Tx FIFO size in bytes */
#define SERCOM8_FSYNC_IMPLEMENTED                (1)        /* SPI Frame Synch mode implemented? */
#define SERCOM8_GCLK_ID_CORE                     (29)       
#define SERCOM8_GCLK_ID_SLOW                     (20)       
#define SERCOM8_I2C_0_INT_SRC                    (111)      /* USART/SPI/I2C Error */
#define SERCOM8_I2C_1_INT_SRC                    (115)      /* USART-SPI Receive Complete/ I2C Data Ready */
#define SERCOM8_I2C_2_INT_SRC                    (116)      /* USART Receive Start/ SPI Slave Select Low/ I2C TX FIFO Empty */
#define SERCOM8_I2C_3_INT_SRC                    (117)      /* USART Clear To Send Input Change/ I2C RX FIFO Full */
#define SERCOM8_INSTANCE_ID                      (31)       /* Instance index for SERCOM8 */
#define SERCOM8_MCLK_ID_APB                      (39)       /* Index for SERCOM8 APB clock */
#define SERCOM8_PAC_ID                           (31)       /* Index for SERCOM8 registers write protection */
#define SERCOM8_SPI                              (1)        /* SPI mode implemented? */
#define SERCOM8_SPI_RX_INT_SRC                   (115)      /* USART-SPI Receive Complete/ I2C Data Ready */
#define SERCOM8_SPI_TX_COMPLETE_INT_SRC          (114)      /* USART-SPI Transmit Complete/ I2C Address Match */
#define SERCOM8_SPI_TX_READY_INT_SRC             (113)      /* USART-SPI Data Register Empty/ I2C Stop Received */
#define SERCOM8_TWIM                             (1)        /* TWI Master mode implemented? */
#define SERCOM8_TWIS                             (1)        /* TWI Slave mode implemented? */
#define SERCOM8_TWI_HSMODE                       (1)        /* TWI HighSpeed mode implemented? */
#define SERCOM8_ULTRA_IMPLEMENTATION             (0)        /* ULTRA platform compatibility? */
#define SERCOM8_USART                            (1)        /* USART mode implemented? */
#define SERCOM8_USART_AUTOBAUD                   (1)        /* USART autobaud implemented? */
#define SERCOM8_USART_ERROR_INT_SRC              (111)      /* USART/SPI/I2C Error */
#define SERCOM8_USART_IRDA                       (1)        /* USART IrDA implemented? */
#define SERCOM8_USART_ISO7816                    (1)        /* USART ISO7816 mode implemented? */
#define SERCOM8_USART_LIN_MASTER                 (1)        /* USART LIN Master mode implemented? */
#define SERCOM8_USART_RS485                      (1)        /* USART RS485 mode implemented? */
#define SERCOM8_USART_RX_INT_SRC                 (115)      /* USART-SPI Receive Complete/ I2C Data Ready */
#define SERCOM8_USART_TX_COMPLETE_INT_SRC        (114)      /* USART-SPI Transmit Complete/ I2C Address Match */
#define SERCOM8_USART_TX_READY_INT_SRC           (113)      /* USART-SPI Data Register Empty/ I2C Stop Received */

#endif /* _PIC32CZCA90_SERCOM8_INSTANCE_ */
