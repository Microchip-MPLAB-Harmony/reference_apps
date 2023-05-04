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
    simpleMAP_HAL.c

  @Summary
    Bridges platform specific hardware peripherals to be used by the library.

  @Description
    Implements specific USART/I2C/Delay functions that the library can use.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include "config/default/definitions.h"
#include "simpleMAP_library.h"
#include "app_secure_ble_manager.h"
#include "simpleMAP_HAL.h"

sha256_ctx sha256_dynamic_ctx_tx;
sha256_ctx sha256_dynamic_ctx_rx;

/* ************************************************************************** */
/*  SERCOM0 UART USED AS DEBUG PORT
 *  - it's used as blocking: it exits only when all bytes have been 
 *    sent out
 */
void DebugUartWrite(uint8_t * buffer, uint16_t len){
    if(!simpleMAP_DEBUG_ENABLED()) return;
   /* if(simpleMAP_APPLICATION_CALLBACK==NULL){
        if(SERCOM0_USART_WriteIsBusy()) while(SERCOM0_USART_WriteIsBusy());
        SERCOM0_USART_Write(buffer,len);
        while(SERCOM0_USART_WriteIsBusy());
    }else{
        memcpy(simpleMAP_APPLICATION_CALLBACK_MESSAGE->data,buffer,len);
        simpleMAP_APPLICATION_CALLBACK_MESSAGE->messagesize = len;
        simpleMAP_APPLICATION_CALLBACK(simpleMAP_CB_TYPE_LOGFROMSECURE);
    }*/
    printf("%s\n\r",buffer);
}


/* ************************************************************************** */
/*  SERCOM1 I2C READ
 */
bool pic32cm_i2c_read(uint16_t address, uint8_t * readbuffer, uint32_t len){
    while(SERCOM1_I2C_IsBusy());
    SERCOM1_I2C_Read(address >> 1, readbuffer, len);
    while(SERCOM1_I2C_IsBusy());
    if(SERCOM1_I2C_ErrorGet() != SERCOM_I2C_ERROR_NONE)
        return false;
    return true;
}


/* ************************************************************************** */
/*  SERCOM1 I2C WRITE
 */
bool pic32cm_i2c_write(uint16_t address, uint8_t * buffer, uint32_t len){
    while(SERCOM1_I2C_IsBusy());
    SERCOM1_I2C_Write(address >> 1, buffer, len);
    while(SERCOM1_I2C_IsBusy());
    if(SERCOM1_I2C_ErrorGet() != SERCOM_I2C_ERROR_NONE)
        return false;
    return true;
}


/* ************************************************************************** */
/*  SERCOM1 I2C SET BAUD RATE
 */
bool pic32cm_i2c_set_baudrate(uint32_t baud){
    while(SERCOM1_I2C_IsBusy());
    SERCOM_I2C_TRANSFER_SETUP setup;
    setup.clkSpeed = baud;
    return SERCOM1_I2C_TransferSetup(&setup,0);
}


/* ************************************************************************** */
/*  SAML11 SOFTWARE RESET
 */
void pic32cm_soft_reset(void){
    NVIC_SystemReset();
}


/* ************************************************************************** */
/*  CORTEX M Cycles delay
 */
void _arm_delay_cycles(void *const hw, uint32_t cycles)
{
    (void)hw;
    (void)cycles;
    __asm(".syntax unified\n"
          "__delay:\n"
          "subs r1, r1, #1\n"
          "bhi __delay\n"
          ".syntax divided");
}


/* ************************************************************************** */
/*  SAML11 SLEEP GIVEN MICROSECONDS
 */
void pic32cm_sleep_us(uint32_t us)
{
    _arm_delay_cycles((void *)0, us * 106 / 10);
}

/* ************************************************************************** */
/** SAML11 SLEEP GIVEN MILLISECONDS
 */
void pic32cm_sleep_ms(uint32_t ms)
{
    _arm_delay_cycles((void *)0, ms * 2667);
}

/* ************************************************************************** */
/** SAML11 HW ACCELERATED sha256 INIT
 */
void pic32cm_sha256_init(sha256_ctx *ctx)
{
	static const uint32_t hash_init[]
	    = {0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19};
	int i;
	memset(ctx, 0, sizeof(*ctx));
	for (i = 0; i < 8; i++) {
		ctx->hash[i] = hash_init[i];
	}
}

/* ************************************************************************** */
/** SAML11 HW ACCELERATED sha256 UPDATE
 */
void pic32cm_sha256_update(sha256_ctx *ctx, const uint8_t *msg, uint32_t msg_size)
{
	uint32_t ram_buf[64];
	uint32_t block_count;
	uint8_t *rest_of_msg;
	uint32_t block = 0;
	uint32_t rem_size  = 64 - ctx->block_size;
	uint32_t copy_size = msg_size > rem_size ? rem_size : msg_size;

	memcpy(&ctx->block[ctx->block_size], msg, copy_size);
    if (ctx->block_size + msg_size < 64) {
		ctx->block_size += msg_size;
		return;
	}
	crya_sha_process(ctx->hash, ctx->block, ram_buf);
	msg_size -= copy_size; 
	block_count = msg_size / 64;
	rest_of_msg = (uint8_t *)&msg[copy_size];
	for (block = 0; block < block_count; block++) {
		memcpy(ctx->block,(uint8_t *)&rest_of_msg[block * 64],64);
		crya_sha_process(ctx->hash, ctx->block, ram_buf);
	}
	ctx->total_msg_size += (block_count + 1) * 64;
	ctx->block_size = msg_size % 64;
	memcpy(ctx->block, &msg[copy_size + block_count * 64], ctx->block_size);
}

/* ************************************************************************** */
/** SAML11 HW ACCELERATED sha256 FINAL
 */
void pic32cm_sha256_final(sha256_ctx *ctx, uint8_t digest[32])
{
	int      i, j;
	uint32_t msg_size_bits;
	uint32_t pad_zero_count;
	uint32_t ram_buf[64];

	ctx->total_msg_size += ctx->block_size;
	msg_size_bits = ctx->total_msg_size * 8;
    pad_zero_count = (64 - ((ctx->block_size + 9) % 64)) % 64;
    ctx->block[ctx->block_size++] = 0x80;
    memset(&ctx->block[ctx->block_size], 0, pad_zero_count + 4);
	ctx->block_size += pad_zero_count + 4;
    ctx->block[ctx->block_size++] = (uint8_t)(msg_size_bits >> 24);
	ctx->block[ctx->block_size++] = (uint8_t)(msg_size_bits >> 16);
	ctx->block[ctx->block_size++] = (uint8_t)(msg_size_bits >> 8);
	ctx->block[ctx->block_size++] = (uint8_t)(msg_size_bits >> 0);
	crya_sha_process(ctx->hash, ctx->block, ram_buf);
    for (i = 0; i < 8; i++) {
		for (j = sizeof(int32_t) - 1; j >= 0; j--, ctx->hash[i] >>= 8) {
			digest[i * sizeof(int32_t) + j] = ctx->hash[i] & 0xFF;
		}
	}
}

/* ************************************************************************** */
/** SAML11 HW ACCELERATED sha256
 */
void pic32cm_sha256(uint8_t * hash, sha256_element  parts[], uint8_t nparts)
{
    int local = 0;
    sha256_ctx ctx;

	pic32cm_sha256_init(&ctx);
    for(local=0;local<nparts;local++){
        pic32cm_sha256_update(&ctx,parts[local].element,parts[local].element_size);
    }
    pic32cm_sha256_final(&ctx, hash);
    
}

/* ************************************************************************** */
/** SAML11 HW ACCELERATED SHA256 DYNAMIC INIT TX
 */
void pic32cm_dynamic_sha256_init_tx(){
    pic32cm_sha256_init(&sha256_dynamic_ctx_tx);
}

/* ************************************************************************** */
/** SAML11 HW ACCELERATED SHA256 DYNAMIC UPDATE TX
 */
void pic32cm_dynamic_sha256_update_tx(uint8_t * msg, uint16_t len){
    if(len==0) return;
    pic32cm_sha256_update(&sha256_dynamic_ctx_tx,msg,len);//(len>16)? 16 : len
}

/* ************************************************************************** */
/** SAML11 HW ACCELERATED SHA256 DYNAMIC INIT TX
 */
void pic32cm_dynamic_sha256_final_tx(uint8_t sha_digest[32]){
    pic32cm_sha256_final(&sha256_dynamic_ctx_tx, sha_digest);
}

/* ************************************************************************** */
/** SAML11 HW ACCELERATED SHA256 DYNAMIC INIT RX
 */
void pic32cm_dynamic_sha256_init_rx(){
    pic32cm_sha256_init(&sha256_dynamic_ctx_rx);
}

/* ************************************************************************** */
/** SAML11 HW ACCELERATED SHA256 DYNAMIC UPDATE RX
 */
void pic32cm_dynamic_sha256_update_rx(uint8_t * msg, uint16_t len){
    if(len==0) return;
    pic32cm_sha256_update(&sha256_dynamic_ctx_rx,msg,len);//(len>16)? 16 : len
}

/* ************************************************************************** */
/** SAML11 HW ACCELERATED SHA256 DYNAMIC INIT RX
 */
void pic32cm_dynamic_sha256_final_rx(uint8_t sha_digest[32]){
    pic32cm_sha256_final(&sha256_dynamic_ctx_rx, sha_digest);
}

/* ************************************************************************** */
/** SAML11 HW ACCELERATED HMAC 
 */
void pic32cm_hmac(uint8_t *message, uint16_t len, uint8_t hmackey[32], uint8_t digest[32])
{
    sha256_ctx ctx;
	
	uint8_t kx[B];
	for (size_t i = 0; i < 32; i++) kx[i] = I_PAD ^ hmackey[i];
	for (size_t i = 32; i < B; i++) kx[i] = I_PAD ^ 0;
	
	pic32cm_sha256_init(&ctx);
	pic32cm_sha256_update(&ctx, kx, B);
	pic32cm_sha256_update(&ctx, message, len);
    pic32cm_sha256_final(&ctx, digest);
	
	for (size_t i = 0; i < 32; i++) kx[i] = O_PAD ^ hmackey[i];
	for (size_t i = 32; i < B; i++) kx[i] = O_PAD ^ 0;
	
	pic32cm_sha256_init(&ctx);
	pic32cm_sha256_update(&ctx, kx, B);
	pic32cm_sha256_update(&ctx, digest, SHA256_DIGEST_SIZE);
	pic32cm_sha256_final(&ctx, digest);
}

/* ************************************************************************** */
/** SAML11 HW ACCELERATED AES128 ENCRYPT
 */
void pic32cm_aes128_hw_encrypt(const uint8_t *keys, const uint8_t *src, uint8_t *dst){
    crya_aes_encrypt(keys,4,src,dst);
}

/* ************************************************************************** */
/** SAML11 HW ACCELERATED AES128 DECRYPT
 */
void pic32cm_aes128_hw_decrypt(const uint8_t *keys, const uint8_t *src, uint8_t *dst){
    crya_aes_decrypt(keys,4,src,dst);
}

/* ************************************************************************** */
/** RE-ARM RX DMA TRANSFER
 */
void pic32cm_rearm_rx_dma_transfer(void){
    DMAC_ChannelTransfer(DMAC_CHANNEL_0, (const void *)&SERCOM0_REGS->USART_INT.SERCOM_DATA, &BLE_DMA_RX, DMA_RX_SIZE); 
}

/* ************************************************************************** */
/** RE-ARM TX DMA TRANSFER
 */
void pic32cm_rearm_tx_dma_transfer(void){
    DMAC_ChannelTransfer(DMAC_CHANNEL_1, &BLE_DMA_TX, (const void *)&SERCOM0_REGS->USART_INT.SERCOM_DATA, DMA_TX_SIZE); 
}

/* ************************************************************************** */
/** ERASE 256 BYTES OF FLASH AT SPECIFIED ADDRESS
 */
bool pic32cm_flash_erase_256(uint32_t flash_address)
{
	return NVMCTRL_RowErase(flash_address);
}

/* ************************************************************************** */
/** WRITE 256 BYTES ON FLASH AT SPECIFIED ADDRESS
 */
bool pic32cm_flash_write_256(uint8_t * data256, uint32_t flash_address)
{
    uint32_t *dst = (uint32_t *)flash_address;
	uint32_t *src = (uint32_t *)data256;
    
    if(!pic32cm_flash_erase_256(flash_address)){
        return false;
    }
    while(NVMCTRL_IsBusy());
    for (int page = 0; page < 4; page++)
	{
		for (int i = 0; i < 16; i++)
		dst[i] = src[i];
		NVMCTRL_SEC_REGS->NVMCTRL_CTRLA = NVMCTRL_CTRLA_CMDEX_KEY | NVMCTRL_CTRLA_CMD_WP;
		while (0 == (NVMCTRL_SEC_REGS->NVMCTRL_STATUS & NVMCTRL_STATUS_READY_Msk));
        if(memcmp((uint8_t *)src, (uint8_t *)dst, 64)!=0) return false;
		dst += 16;
		src += 16;
	}
    return true;
}

/**
 *  HARDWARE ABSTRACTION FUNCTION ASSIGNEMENT
 */
void simpleMAP_HAL_init(){
    simpleMAP_debug_out                 = DebugUartWrite;
    ECC608_I2C_WRITE                    = pic32cm_i2c_write;
    ECC608_I2C_READ                     = pic32cm_i2c_read;
    ECC608_I2C_SET_SPEED                = pic32cm_i2c_set_baudrate;
    MCU_SOFTWARE_RESET                  = pic32cm_soft_reset;
    MCU_SLEEP_US                        = pic32cm_sleep_us;
    MCU_SLEEP_MS                        = pic32cm_sleep_ms;
    MCU_SHA256                          = pic32cm_sha256;
    MCU_START_RECEIVE_ON_CHANNEL        = pic32cm_rearm_rx_dma_transfer;
    MCU_START_TRANSMIT_ON_CHANNEL       = pic32cm_rearm_tx_dma_transfer;
    simpleMAP_TRANSMIT_BUFFER           = (uint8_t *)&BLE_DMA_TX;
    simpleMAP_RECEIVE_BUFFER            = (uint8_t *)&BLE_DMA_RX;
    simpleMAP_CHANNEL_SET_VALID         = APP_SECURE_BLE_MANAGER_IsPeerValid;
    simpleMAP_IS_CHANNEL_CONNECTED      = APP_SECURE_BLE_MANAGER_ModuleConnected;
    MCU_SHA256_DYNAMIC_INIT_TX          = pic32cm_dynamic_sha256_init_tx;
    MCU_SHA256_DYNAMIC_UPDATE_TX        = pic32cm_dynamic_sha256_update_tx;
    MCU_SHA256_DYNAMIC_FINAL_TX         = pic32cm_dynamic_sha256_final_tx;
    MCU_SHA256_DYNAMIC_INIT_RX          = pic32cm_dynamic_sha256_init_rx;
    MCU_SHA256_DYNAMIC_UPDATE_RX        = pic32cm_dynamic_sha256_update_rx;
    MCU_SHA256_DYNAMIC_FINAL_RX         = pic32cm_dynamic_sha256_final_rx;
    MCU_HMAC_SHA256                     = pic32cm_hmac;
    MCU_AES128_16BYTES_ENCRYPT          = pic32cm_aes128_hw_encrypt;
    MCU_AES128_16BYTES_DECRYPT          = pic32cm_aes128_hw_decrypt;
    MCU_FLASH_ERASE_256                 = pic32cm_flash_erase_256;
    MCU_FLASH_WRITE_256                 = pic32cm_flash_write_256;
}

/* *****************************************************************************
 End of File
 */
