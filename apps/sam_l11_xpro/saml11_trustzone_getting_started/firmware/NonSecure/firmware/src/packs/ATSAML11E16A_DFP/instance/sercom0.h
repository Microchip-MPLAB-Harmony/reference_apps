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
#ifndef _SAML11_SERCOM0_INSTANCE_
#define _SAML11_SERCOM0_INSTANCE_


/* ========== Instance Parameter definitions for SERCOM0 peripheral ========== */
#define SERCOM0_DMAC_ID_RX                       (4)        /* Index of DMA RX trigger */
#define SERCOM0_DMAC_ID_TX                       (5)        /* Index of DMA TX trigger */
#define SERCOM0_FIFO_DEPTH_POWER                 (1)        /* Rx Fifo depth = 2^FIFO_DEPTH_POWER */
#define SERCOM0_GCLK_ID_CORE                     (11)       
#define SERCOM0_GCLK_ID_SLOW                     (10)       
#define SERCOM0_I2C_0_INT_SRC                    (22)       /* I2C 0 Interrupt */
#define SERCOM0_I2C_1_INT_SRC                    (23)       /* I2C 1 Interrupt */
#define SERCOM0_I2C_2_INT_SRC                    (24)       /* I2C 2 Interrupt */
#define SERCOM0_I2C_3_INT_SRC                    (25)       /* I2C 3 Interrupt */
#define SERCOM0_INSTANCE_ID                      (65)       
#define SERCOM0_INT_MSB                          (6)        
#define SERCOM0_PMSB                             (3)        
#define SERCOM0_SPI                              (1)        /* SPI mode implemented? */
#define SERCOM0_SPI_ERROR_INT_SRC                (25)       /* SPI ERROR Interrupt */
#define SERCOM0_SPI_RX_INT_SRC                   (24)       /* SPI RX Interrupt */
#define SERCOM0_SPI_TX_COMPLETE_INT_SRC          (23)       /* SPI TX COMPLETE Interrupt */
#define SERCOM0_SPI_TX_READY_INT_SRC             (22)       /* SPI TX READY Interrupt */
#define SERCOM0_TWIM                             (1)        /* TWI Master mode implemented? */
#define SERCOM0_TWIS                             (1)        /* TWI Slave mode implemented? */
#define SERCOM0_TWI_HSMODE                       (1)        /* TWI HighSpeed mode implemented? */
#define SERCOM0_USART                            (1)        /* USART mode implemented? */
#define SERCOM0_USART_AUTOBAUD                   (0)        /* USART AUTOBAUD mode implemented? */
#define SERCOM0_USART_ERROR_INT_SRC              (25)       /* USART ERROR Interrupt */
#define SERCOM0_USART_ISO7816                    (0)        /* USART ISO7816 mode implemented? */
#define SERCOM0_USART_LIN_MASTER                 (0)        /* USART LIN Master mode implemented? */
#define SERCOM0_USART_RS485                      (0)        /* USART RS485 mode implemented? */
#define SERCOM0_USART_RX_INT_SRC                 (24)       /* USART RX Interrupt */
#define SERCOM0_USART_TX_COMPLETE_INT_SRC        (23)       /* USART TX COMPLETE Interrupt */
#define SERCOM0_USART_TX_READY_INT_SRC           (22)       /* USART TX READY Interrupt */

#endif /* _SAML11_SERCOM0_INSTANCE_ */
