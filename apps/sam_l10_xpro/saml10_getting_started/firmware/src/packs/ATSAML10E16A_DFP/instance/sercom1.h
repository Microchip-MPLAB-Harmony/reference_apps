/*
 * Instance header file for ATSAML10E16A
 *
 * Copyright (c) 2021 Microchip Technology Inc. and its subsidiaries.
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

/* file generated from device description version 2021-06-28T12:20:34Z */
#ifndef _SAML10_SERCOM1_INSTANCE_
#define _SAML10_SERCOM1_INSTANCE_


/* ========== Instance Parameter definitions for SERCOM1 peripheral ========== */
#define SERCOM1_DMAC_ID_RX                       _UL_(6)    /* Index of DMA RX trigger */
#define SERCOM1_DMAC_ID_TX                       _UL_(7)    /* Index of DMA TX trigger */
#define SERCOM1_FIFO_DEPTH_POWER                 _UL_(2)    /* Rx Fifo depth = 2^FIFO_DEPTH_POWER */
#define SERCOM1_GCLK_ID_CORE                     _UL_(12)   
#define SERCOM1_GCLK_ID_SLOW                     _UL_(10)   
#define SERCOM1_INT_MSB                          _UL_(6)    
#define SERCOM1_PMSB                             _UL_(3)    
#define SERCOM1_SPI                              _UL_(1)    /* SPI mode implemented? */
#define SERCOM1_SPI_TX_READY_INT_SRC             _UL_(26)   /* SPI TX READY Interrupt */
#define SERCOM1_SPI_TX_COMPLETE_INT_SRC          _UL_(27)   /* SPI TX COMPLETE Interrupt */
#define SERCOM1_SPI_RX_INT_SRC                   _UL_(28)   /* SPI RX Interrupt */
#define SERCOM1_SPI_ERROR_INT_SRC                _UL_(29)   /* SPI ERROR Interrupt */
#define SERCOM1_TWIM                             _UL_(1)    /* TWI Master mode implemented? */
#define SERCOM1_TWIS                             _UL_(1)    /* TWI Slave mode implemented? */
#define SERCOM1_TWI_HSMODE                       _UL_(0)    /* TWI HighSpeed mode implemented? */
#define SERCOM1_I2C_0_INT_SRC                    _UL_(26)   /* I2C 0 Interrupt */
#define SERCOM1_I2C_1_INT_SRC                    _UL_(27)   /* I2C 1 Interrupt */
#define SERCOM1_I2C_2_INT_SRC                    _UL_(28)   /* I2C 2 Interrupt */
#define SERCOM1_I2C_3_INT_SRC                    _UL_(29)   /* I2C 3 Interrupt */
#define SERCOM1_USART                            _UL_(1)    /* USART mode implemented? */
#define SERCOM1_USART_AUTOBAUD                   _UL_(0)    /* USART AUTOBAUD mode implemented? */
#define SERCOM1_USART_ISO7816                    _UL_(0)    /* USART ISO7816 mode implemented? */
#define SERCOM1_USART_LIN_MASTER                 _UL_(0)    /* USART LIN Master mode implemented? */
#define SERCOM1_USART_RS485                      _UL_(0)    /* USART RS485 mode implemented? */
#define SERCOM1_USART_TX_READY_INT_SRC           _UL_(26)   /* USART TX READY Interrupt */
#define SERCOM1_USART_TX_COMPLETE_INT_SRC        _UL_(27)   /* USART TX COMPLETE Interrupt */
#define SERCOM1_USART_RX_INT_SRC                 _UL_(28)   /* USART RX Interrupt */
#define SERCOM1_USART_ERROR_INT_SRC              _UL_(29)   /* USART ERROR Interrupt */
#define SERCOM1_INSTANCE_ID                      _UL_(66)   

#endif /* _SAML10_SERCOM1_INSTANCE_ */
