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
#ifndef _PIC32CKSG01_SERCOM6_INSTANCE_
#define _PIC32CKSG01_SERCOM6_INSTANCE_


/* ========== Instance Parameter definitions for SERCOM6 peripheral ========== */
#define SERCOM6_CLK_REDUCTION                    (1)        /* Reduce clock options to pin 1 for SPI and USART */
#define SERCOM6_DMA                              (1)        /* DMA support implemented? */
#define SERCOM6_DMAC_ID_RX                       (45)       /* Index of DMA RX trigger */
#define SERCOM6_DMAC_ID_TX                       (46)       /* Index of DMA TX trigger */
#define SERCOM6_FIFO_IMPLEMENTED                 (1)        /* FIFO Rx/Tx implemented? */
#define SERCOM6_FIFO_SIZE                        (8)        /* Rx-Tx FIFO size in bytes */
#define SERCOM6_FSYNC_IMPLEMENTED                (1)        /* SPI Frame Synch mode implemented? */
#define SERCOM6_GCLK_ID_CORE                     (27)       
#define SERCOM6_GCLK_ID_SLOW                     (18)       
#define SERCOM6_I2C_0_INT_SRC                    (108)      /* USART/SPI/I2C Error */
#define SERCOM6_I2C_1_INT_SRC                    (111)      /* USART-SPI Receive Complete/ I2C Data Ready */
#define SERCOM6_I2C_2_INT_SRC                    (112)      /* USART Receive Start/ SPI Slave Select Low/ I2C TX FIFO Empty */
#define SERCOM6_I2C_3_INT_SRC                    (113)      /* USART Clear To Send Input Change/ I2C RX FIFO Full */
#define SERCOM6_INSTANCE_ID                      (66)       /* Instance index for SERCOM6 */
#define SERCOM6_MCLK_ID_APB                      (98)       /* Index for SERCOM6 APB clock */
#define SERCOM6_PAC_ID                           (66)       /* Index for SERCOM6 registers write protection */
#define SERCOM6_SPI                              (1)        /* SPI mode implemented? */
#define SERCOM6_SPI_RX_INT_SRC                   (111)      /* USART-SPI Receive Complete/ I2C Data Ready */
#define SERCOM6_SPI_TX_COMPLETE_INT_SRC          (110)      /* USART-SPI Transmit Complete/ I2C Address Match */
#define SERCOM6_SPI_TX_READY_INT_SRC             (109)      /* USART-SPI Data Register Empty/ I2C Stop Received */
#define SERCOM6_TWIM                             (1)        /* TWI Master mode implemented? */
#define SERCOM6_TWIS                             (1)        /* TWI Slave mode implemented? */
#define SERCOM6_TWI_HSMODE                       (1)        /* TWI HighSpeed mode implemented? */
#define SERCOM6_ULTRA_IMPLEMENTATION             (0)        /* ULTRA platform compatibility? */
#define SERCOM6_USART                            (1)        /* USART mode implemented? */
#define SERCOM6_USART_AUTOBAUD                   (1)        /* USART autobaud implemented? */
#define SERCOM6_USART_ERROR_INT_SRC              (108)      /* USART/SPI/I2C Error */
#define SERCOM6_USART_IRDA                       (1)        /* USART IrDA implemented? */
#define SERCOM6_USART_ISO7816                    (1)        /* USART ISO7816 mode implemented? */
#define SERCOM6_USART_LIN_MASTER                 (1)        /* USART LIN Master mode implemented? */
#define SERCOM6_USART_RS485                      (1)        /* USART RS485 mode implemented? */
#define SERCOM6_USART_RX_INT_SRC                 (111)      /* USART-SPI Receive Complete/ I2C Data Ready */
#define SERCOM6_USART_TX_COMPLETE_INT_SRC        (110)      /* USART-SPI Transmit Complete/ I2C Address Match */
#define SERCOM6_USART_TX_READY_INT_SRC           (109)      /* USART-SPI Data Register Empty/ I2C Stop Received */

#endif /* _PIC32CKSG01_SERCOM6_INSTANCE_ */
