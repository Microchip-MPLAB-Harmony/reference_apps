/*
 * Instance header file for ATSAML11E16A
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

/* file generated from device description version 2023-04-12T14:18:55Z */
#ifndef _SAML11_SERCOM2_INSTANCE_
#define _SAML11_SERCOM2_INSTANCE_


/* ========== Instance Parameter definitions for SERCOM2 peripheral ========== */
#define SERCOM2_DMAC_ID_RX                       (8)        /* Index of DMA RX trigger */
#define SERCOM2_DMAC_ID_TX                       (9)        /* Index of DMA TX trigger */
#define SERCOM2_FIFO_DEPTH_POWER                 (1)        /* Rx Fifo depth = 2^FIFO_DEPTH_POWER */
#define SERCOM2_GCLK_ID_CORE                     (13)       
#define SERCOM2_GCLK_ID_SLOW                     (10)       
#define SERCOM2_I2C_0_INT_SRC                    (30)       /* I2C 0 Interrupt */
#define SERCOM2_I2C_1_INT_SRC                    (31)       /* I2C 1 Interrupt */
#define SERCOM2_I2C_2_INT_SRC                    (32)       /* I2C 2 Interrupt */
#define SERCOM2_I2C_3_INT_SRC                    (33)       /* I2C 3 Interrupt */
#define SERCOM2_INSTANCE_ID                      (67)       
#define SERCOM2_INT_MSB                          (6)        
#define SERCOM2_PMSB                             (3)        
#define SERCOM2_SPI                              (1)        /* SPI mode implemented? */
#define SERCOM2_SPI_ERROR_INT_SRC                (33)       /* SPI ERROR Interrupt */
#define SERCOM2_SPI_RX_INT_SRC                   (32)       /* SPI RX Interrupt */
#define SERCOM2_SPI_TX_COMPLETE_INT_SRC          (31)       /* SPI TX COMPLETE Interrupt */
#define SERCOM2_SPI_TX_READY_INT_SRC             (30)       /* SPI TX READY Interrupt */
#define SERCOM2_TWIM                             (0)        /* TWI Master mode implemented? */
#define SERCOM2_TWIS                             (0)        /* TWI Slave mode implemented? */
#define SERCOM2_TWI_HSMODE                       (0)        /* TWI HighSpeed mode implemented? */
#define SERCOM2_USART                            (1)        /* USART mode implemented? */
#define SERCOM2_USART_AUTOBAUD                   (1)        /* USART AUTOBAUD mode implemented? */
#define SERCOM2_USART_ERROR_INT_SRC              (33)       /* USART ERROR Interrupt */
#define SERCOM2_USART_ISO7816                    (1)        /* USART ISO7816 mode implemented? */
#define SERCOM2_USART_LIN_MASTER                 (0)        /* USART LIN Master mode implemented? */
#define SERCOM2_USART_RS485                      (1)        /* USART RS485 mode implemented? */
#define SERCOM2_USART_RX_INT_SRC                 (32)       /* USART RX Interrupt */
#define SERCOM2_USART_TX_COMPLETE_INT_SRC        (31)       /* USART TX COMPLETE Interrupt */
#define SERCOM2_USART_TX_READY_INT_SRC           (30)       /* USART TX READY Interrupt */

#endif /* _SAML11_SERCOM2_INSTANCE_ */
