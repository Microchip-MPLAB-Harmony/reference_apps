/*
 * Instance header file for PIC32CK2051SG01144
 *
 * Copyright (c) 2023 Microchip Technology Inc. and its subsidiaries.
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

/* file generated from device description file (ATDF) version 2023-11-16T06:44:02Z */
#ifndef _PIC32CKSG01_SERCOM4_INSTANCE_
#define _PIC32CKSG01_SERCOM4_INSTANCE_


/* ========== Instance Parameter definitions for SERCOM4 peripheral ========== */
#define SERCOM4_CLK_REDUCTION                    (1)        /* Reduce clock options to pin 1 for SPI and USART */
#define SERCOM4_DMA                              (1)        /* DMA support implemented? */
#define SERCOM4_DMAC_ID_RX                       (41)       /* Index of DMA RX trigger */
#define SERCOM4_DMAC_ID_TX                       (42)       /* Index of DMA TX trigger */
#define SERCOM4_FIFO_IMPLEMENTED                 (1)        /* FIFO Rx/Tx implemented? */
#define SERCOM4_FIFO_SIZE                        (8)        /* Rx-Tx FIFO size in bytes */
#define SERCOM4_FSYNC_IMPLEMENTED                (1)        /* SPI Frame Synch mode implemented? */
#define SERCOM4_GCLK_ID_CORE                     (25)       
#define SERCOM4_GCLK_ID_SLOW                     (18)       
#define SERCOM4_I2C_0_INT_SRC                    (96)       /* USART/SPI/I2C Error */
#define SERCOM4_I2C_1_INT_SRC                    (99)       /* USART-SPI Receive Complete/ I2C Data Ready */
#define SERCOM4_I2C_2_INT_SRC                    (100)      /* USART Receive Start/ SPI Slave Select Low/ I2C TX FIFO Empty */
#define SERCOM4_I2C_3_INT_SRC                    (101)      /* USART Clear To Send Input Change/ I2C RX FIFO Full */
#define SERCOM4_INSTANCE_ID                      (64)       /* Instance index for SERCOM4 */
#define SERCOM4_MCLK_ID_APB                      (96)       /* Index for SERCOM4 APB clock */
#define SERCOM4_PAC_ID                           (64)       /* Index for SERCOM4 registers write protection */
#define SERCOM4_SPI                              (1)        /* SPI mode implemented? */
#define SERCOM4_SPI_RX_INT_SRC                   (99)       /* USART-SPI Receive Complete/ I2C Data Ready */
#define SERCOM4_SPI_TX_COMPLETE_INT_SRC          (98)       /* USART-SPI Transmit Complete/ I2C Address Match */
#define SERCOM4_SPI_TX_READY_INT_SRC             (97)       /* USART-SPI Data Register Empty/ I2C Stop Received */
#define SERCOM4_TWIM                             (1)        /* TWI Master mode implemented? */
#define SERCOM4_TWIS                             (1)        /* TWI Slave mode implemented? */
#define SERCOM4_TWI_HSMODE                       (1)        /* TWI HighSpeed mode implemented? */
#define SERCOM4_ULTRA_IMPLEMENTATION             (0)        /* ULTRA platform compatibility? */
#define SERCOM4_USART                            (1)        /* USART mode implemented? */
#define SERCOM4_USART_AUTOBAUD                   (1)        /* USART autobaud implemented? */
#define SERCOM4_USART_ERROR_INT_SRC              (96)       /* USART/SPI/I2C Error */
#define SERCOM4_USART_IRDA                       (1)        /* USART IrDA implemented? */
#define SERCOM4_USART_ISO7816                    (1)        /* USART ISO7816 mode implemented? */
#define SERCOM4_USART_LIN_MASTER                 (1)        /* USART LIN Master mode implemented? */
#define SERCOM4_USART_RS485                      (1)        /* USART RS485 mode implemented? */
#define SERCOM4_USART_RX_INT_SRC                 (99)       /* USART-SPI Receive Complete/ I2C Data Ready */
#define SERCOM4_USART_TX_COMPLETE_INT_SRC        (98)       /* USART-SPI Transmit Complete/ I2C Address Match */
#define SERCOM4_USART_TX_READY_INT_SRC           (97)       /* USART-SPI Data Register Empty/ I2C Stop Received */

#endif /* _PIC32CKSG01_SERCOM4_INSTANCE_ */
