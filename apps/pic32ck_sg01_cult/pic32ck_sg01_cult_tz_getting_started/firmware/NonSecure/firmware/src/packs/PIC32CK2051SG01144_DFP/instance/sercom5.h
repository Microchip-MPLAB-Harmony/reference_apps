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
#ifndef _PIC32CKSG01_SERCOM5_INSTANCE_
#define _PIC32CKSG01_SERCOM5_INSTANCE_


/* ========== Instance Parameter definitions for SERCOM5 peripheral ========== */
#define SERCOM5_CLK_REDUCTION                    (1)        /* Reduce clock options to pin 1 for SPI and USART */
#define SERCOM5_DMA                              (1)        /* DMA support implemented? */
#define SERCOM5_DMAC_ID_RX                       (43)       /* Index of DMA RX trigger */
#define SERCOM5_DMAC_ID_TX                       (44)       /* Index of DMA TX trigger */
#define SERCOM5_FIFO_IMPLEMENTED                 (1)        /* FIFO Rx/Tx implemented? */
#define SERCOM5_FIFO_SIZE                        (8)        /* Rx-Tx FIFO size in bytes */
#define SERCOM5_FSYNC_IMPLEMENTED                (1)        /* SPI Frame Synch mode implemented? */
#define SERCOM5_GCLK_ID_CORE                     (26)       
#define SERCOM5_GCLK_ID_SLOW                     (18)       
#define SERCOM5_I2C_0_INT_SRC                    (102)      /* USART/SPI/I2C Error */
#define SERCOM5_I2C_1_INT_SRC                    (105)      /* USART-SPI Receive Complete/ I2C Data Ready */
#define SERCOM5_I2C_2_INT_SRC                    (106)      /* USART Receive Start/ SPI Slave Select Low/ I2C TX FIFO Empty */
#define SERCOM5_I2C_3_INT_SRC                    (107)      /* USART Clear To Send Input Change/ I2C RX FIFO Full */
#define SERCOM5_INSTANCE_ID                      (65)       /* Instance index for SERCOM5 */
#define SERCOM5_MCLK_ID_APB                      (97)       /* Index for SERCOM5 APB clock */
#define SERCOM5_PAC_ID                           (65)       /* Index for SERCOM5 registers write protection */
#define SERCOM5_SPI                              (1)        /* SPI mode implemented? */
#define SERCOM5_SPI_RX_INT_SRC                   (105)      /* USART-SPI Receive Complete/ I2C Data Ready */
#define SERCOM5_SPI_TX_COMPLETE_INT_SRC          (104)      /* USART-SPI Transmit Complete/ I2C Address Match */
#define SERCOM5_SPI_TX_READY_INT_SRC             (103)      /* USART-SPI Data Register Empty/ I2C Stop Received */
#define SERCOM5_TWIM                             (1)        /* TWI Master mode implemented? */
#define SERCOM5_TWIS                             (1)        /* TWI Slave mode implemented? */
#define SERCOM5_TWI_HSMODE                       (1)        /* TWI HighSpeed mode implemented? */
#define SERCOM5_ULTRA_IMPLEMENTATION             (0)        /* ULTRA platform compatibility? */
#define SERCOM5_USART                            (1)        /* USART mode implemented? */
#define SERCOM5_USART_AUTOBAUD                   (1)        /* USART autobaud implemented? */
#define SERCOM5_USART_ERROR_INT_SRC              (102)      /* USART/SPI/I2C Error */
#define SERCOM5_USART_IRDA                       (1)        /* USART IrDA implemented? */
#define SERCOM5_USART_ISO7816                    (1)        /* USART ISO7816 mode implemented? */
#define SERCOM5_USART_LIN_MASTER                 (1)        /* USART LIN Master mode implemented? */
#define SERCOM5_USART_RS485                      (1)        /* USART RS485 mode implemented? */
#define SERCOM5_USART_RX_INT_SRC                 (105)      /* USART-SPI Receive Complete/ I2C Data Ready */
#define SERCOM5_USART_TX_COMPLETE_INT_SRC        (104)      /* USART-SPI Transmit Complete/ I2C Address Match */
#define SERCOM5_USART_TX_READY_INT_SRC           (103)      /* USART-SPI Data Register Empty/ I2C Stop Received */

#endif /* _PIC32CKSG01_SERCOM5_INSTANCE_ */
