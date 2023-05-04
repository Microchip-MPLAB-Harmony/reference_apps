/*******************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

/* ************************************************************************** */
/** SIMPLEMAP HARDWARE ABSTRACTION LAYER

  @Company
    MICROCHIP TECHNOLOGY INC

  @File Name
    simpleMAP_HAL.h

  @Summary
    Bridges platform specific hardware peripherals to be used by the library.

  @Description
    Implements specific USART/I2C/Delay functions that the library can use.
 */
/* ************************************************************************** */

#ifndef _SIMPLEMAP_HAL_H    /* Guard against multiple inclusion */
#define _SIMPLEMAP_HAL_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#ifdef __cplusplus
extern "C" {
#endif
    
    //--- DEFINITIONS FOR SAML11 HW ACCELERATED SHA256 AND HMACSHA256
    #define LIBCRYA_BASE_ADDRESS 0x02006800  //Base address is changed for PIC32CM . For L11 it is 0X02001900
    #define CRYA_SHA_ADDRESS (LIBCRYA_BASE_ADDRESS + 0x0)
    #define CRYA_AES_ENC_ADDRESS (LIBCRYA_BASE_ADDRESS + 0x4)
    #define CRYA_AES_DEC_ADDRESS (LIBCRYA_BASE_ADDRESS + 0x8)

    typedef void (*crya_sha_process_t)(uint32_t hash_in_out[8], const uint8_t data[64], uint32_t ram_buf[64]);
    #define crya_sha_process ((crya_sha_process_t)(CRYA_SHA_ADDRESS | 0x1))

    typedef void (*crya_aes_encrypt_t)(const uint8_t *keys, uint32_t key_len, const uint8_t *src, uint8_t *dst);
    #define crya_aes_encrypt ((crya_aes_encrypt_t)(CRYA_AES_ENC_ADDRESS | 0x1))
    
    typedef void (*crya_aes_decrypt_t)(const uint8_t *keys, uint32_t key_len, const uint8_t *src, uint8_t *dst);
    #define crya_aes_decrypt ((crya_aes_decrypt_t)(CRYA_AES_DEC_ADDRESS | 0x1))
    

    #define SHA256_DIGEST_SIZE 32
    #define B 64
    #define L (SHA256_DIGEST_SIZE)
    #define K (SHA256_DIGEST_SIZE * 2)

    #define I_PAD 0x36
    #define O_PAD 0x5C

    typedef struct {
        uint32_t total_msg_size;               
        uint32_t block_size;                   
        uint8_t  block[64 * 2];				   
        uint32_t hash[8];                      
    } sha256_ctx;
    
    
    typedef struct {
        sha256_ctx ctx;
        uint8_t kx[64];
        uint8_t prev_hmac[32];
    }hmac_ctx;
    
    
    //--- BLE UART RX DMA TRANSFER BUFFER AND SIZE
    #define DMA_RX_SIZE     16
    uint8_t BLE_DMA_RX[DMA_RX_SIZE];

    //--- BLE UART DMA TRANSFER BUFFER AND SIZE
    #define DMA_TX_SIZE     16
    uint8_t BLE_DMA_TX[DMA_TX_SIZE];
    
    /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: FUNCTIONS                                                    */
    /* ************************************************************************** */
    /* ************************************************************************** */
    
    void simpleMAP_HAL_init();
    void pic32cm_sleep_us(uint32_t us);
    void pic32cm_sleep_ms(uint32_t ms);
    
    bool pic32cm_i2c_read(uint16_t address, uint8_t * readbuffer, uint32_t len);
    bool pic32cm_i2c_write(uint16_t address, uint8_t * buffer, uint32_t len);
    
#ifdef __cplusplus
}
#endif

#endif /* _SIMPLEMAP_HAL_H */

/* *****************************************************************************
 End of File
 */
