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
/** simpleMAP  Library Header File

  @Company
    Microchip Technology Inc

  @File Name
    simpleMAP_library.h

  @Summary
    Header file for simpleMAP Library.

  @Description
    Contains HAL typedef and configuration, plus all API calls.
 */
/* ************************************************************************** */

#ifndef _SIMPLEMAP_LIBRARY_H    /* Guard against multiple inclusion */
#define _SIMPLEMAP_LIBRARY_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */


#ifdef __cplusplus
extern "C" {
#endif
    //--- **************************************
    //--- TYPE DEFINITION FOR HAL IMPLEMENTATION
    //--- **************************************
    //--- Those functions are the reference to hook hardware specific function to the used platform
    //--- Each function must be implemented as indicated here
    
    //--- TYPE DEFINITION: FUNCTION TO SEND OUT ON A UART A DEBUG MESSAGE
    //--- Sends out a byte buffer on a UART
    typedef void (* debugMessageOnUart)(uint8_t *, uint16_t );
    debugMessageOnUart  simpleMAP_debug_out;
    //--- TYPE DEFINITION: FUNCTION TO READ BYTES FROM I2C
    //--- Read from an I2C (address, readbuffer, length-to-read) This function needs to take care of eventual
    //--- waits, delays, and go through its own error checking. An error code can be put on the i2c_packet 
    //--- structure. Returns true on success
    typedef bool (* i2c_read)( uint16_t, uint8_t *, uint32_t );
    i2c_read  ECC608_I2C_READ;
    //--- TYPE DEFINITION: FUNCTION TO WRITE BYTES TO I2C
    //--- Write to an I2C (address, bytes, length) This function needs to take care of eventual
    //--- waits, delays, and go through its own error checking. An error code can be put on the i2c_packet 
    //--- structure. Returns true on success
    typedef bool (* i2c_write)( uint16_t, uint8_t *, uint32_t );
    i2c_write  ECC608_I2C_WRITE;
    //--- TYPE DEFINITION: FUNCTION TO CHANGE I2C SPEED
    //--- Change I2C baud rate with one value between  I2C_BAUD_100, I2C_BAUD_400, I2C_BAUD_1000
    //--- This function needs to take care of eventual waits, delays, and go through its own error 
    //--- checking. Returns true on success
    typedef bool (* i2c_change_baud)( uint32_t );
    i2c_change_baud ECC608_I2C_SET_SPEED;
    //--- TYPE DEFINITION: FUNCTION TO SLEEP EXECUTION for N microseconds
    //--- Delays for given microseconds. Implementation is up to the user to eventual insert
    //--- low power modes platform specific
    typedef void (* delay_us)( uint32_t );
    delay_us  MCU_SLEEP_US;
    //--- TYPE DEFINITION: FUNCTION TO SLEEP EXECUTION for N milliseconds
    //--- Delays for given milliseconds. Implementation is up to the user to eventual insert
    //--- low power modes platform specific
    typedef void (* delay_ms)( uint32_t );
    delay_ms  MCU_SLEEP_MS;
    //--- TYPE DEFINITION: FUNCTION TO CALCULATE SHA256
    //--- It takes a vararg of byte buffers followed by their lenght and calculate the
    //--- result putting it into hash 
    typedef struct sha256_element_t{
        uint8_t * element;
        uint16_t element_size;
    }sha256_element;
    sha256_element format_sha256_element(uint8_t * element, uint16_t element_size);
    typedef void (* sha256_custom)(uint8_t *, sha256_element  [], uint8_t);
    sha256_custom MCU_SHA256;
    #define sha256(hash, args...) ({                                               \
        sha256_element  arguments[] = {args};                                      \
        MCU_SHA256(hash,arguments,sizeof(arguments)/sizeof(sha256_element));       \
    })
    //--- TYPE DEFINITION: FUNCTION TO CALCULATE SHA256 DYNAMICALLY
    //--- Context is maintained by the HAL
    //--- and one function to calculate it statically.
    //--- Parameters are: message (whole len or blocks of 16 bytes), key, previous hmac
    typedef void (* sha256_custom_dynamic_init)( void );
    sha256_custom_dynamic_init MCU_SHA256_DYNAMIC_INIT_TX;
    sha256_custom_dynamic_init MCU_SHA256_DYNAMIC_INIT_RX;
    typedef void (* sha256_custom_dynamic_update)(uint8_t *, uint16_t);
    sha256_custom_dynamic_update MCU_SHA256_DYNAMIC_UPDATE_TX;
    sha256_custom_dynamic_update MCU_SHA256_DYNAMIC_UPDATE_RX;
    typedef void (* sha256_custom_dynamic_final)(uint8_t *);
    sha256_custom_dynamic_final MCU_SHA256_DYNAMIC_FINAL_TX;
    sha256_custom_dynamic_final MCU_SHA256_DYNAMIC_FINAL_RX;
    typedef void (* hmac_sha256_custom)(uint8_t *, uint16_t,  uint8_t *,  uint8_t *);
    hmac_sha256_custom MCU_HMAC_SHA256;
    
    //--- TYPE DEFINITION: FUNCTIONS TO ENCRYPT/DECRYPT 16bytes with AES128 ECB
    //--- Can be defined platform specific: takes as input pointers to key, buffer
    //--- and result buffer. All operations on a 16byte size (128 bit)
    typedef void (* aes128_encrypt)(const uint8_t *, const uint8_t *, uint8_t *);
    aes128_encrypt MCU_AES128_16BYTES_ENCRYPT;
    typedef void (* aes128_decrypt)(const uint8_t *, const uint8_t *, uint8_t *);
    aes128_decrypt MCU_AES128_16BYTES_DECRYPT;
    
    //--- TYPE DEFINITION: FUNCTIONS TO ERASE, WRITE MCU FLASH PAGES OF 256Bytes
    typedef bool (* flash_erase_256)( uint32_t );
    flash_erase_256 MCU_FLASH_ERASE_256;
    typedef bool (* flash_write_256)( uint8_t *, uint32_t );
    flash_write_256 MCU_FLASH_WRITE_256;
    
    //--- TYPE DEFINITION: FUNCTION TO ENABLE DMA OR ANY CUSTOM MECHANISM TO TRANSMIT/RECEIVE DATA
    //--- It is platform and implementation dependent. Functions are defined to start receive and transmit
    //--- and pointer are defined to Transmit And Receive buffers
    typedef void (* control_tx_rx_flow)(void);
    control_tx_rx_flow MCU_START_RECEIVE_ON_CHANNEL;
    control_tx_rx_flow MCU_START_TRANSMIT_ON_CHANNEL;
    uint8_t * simpleMAP_TRANSMIT_BUFFER;
    uint8_t * simpleMAP_RECEIVE_BUFFER;
    //--- TYPE DEFINITION: FUNCTION TO VALIDATE/INVALIDATE A SIMPLEMAP CHANNEL
    //--- If invalidated, the application should disconnect or invalidate the connectivity used
    //--- (disconnect ble, drop socket, etc)
    typedef void (* channel_validation)(bool);
    channel_validation simpleMAP_CHANNEL_SET_VALID;
    //--- TYPE DEFINITION: FUNCTION TO RETRIEVE SIMPLEMAP CHANNEL STATUS (ACTIVE/INACTIVE)
    //--- TRUE means that underline medium is connected
    //--- FALSE means that underline connection is disconnected 
    typedef bool (* channel_active)( void );
    channel_active simpleMAP_IS_CHANNEL_CONNECTED;
    //--- TYPE DEFINITION: FUNCTION TO RESET THE MCU
    //--- Ususally NVIC_Reset for ARM, but can be customize for any platform
    typedef void (* ucontroller_reset)( void );
    ucontroller_reset MCU_SOFTWARE_RESET;
    
    //--- TYPE DEFINITION: FUNCTION AND BUFFER TO RETURN STATUS AND DATA TO APPLICATION CODE
    //--- Must be implemented by Application code to be notified by the library about status
    //--- and data availability
    typedef void (* app_callback)(uint8_t);
    app_callback simpleMAP_APPLICATION_CALLBACK;
    typedef struct simpleMAP_message{
        uint16_t messagesize;
        uint8_t	 data[1056];
    }simpleMAP_message;
    simpleMAP_message * simpleMAP_APPLICATION_CALLBACK_MESSAGE;
    #define simpleMAP_CB_TYPE_CONNECTED		0x00
    #define simpleMAP_CB_TYPE_DISCONNECTED	0xFF
    #define simpleMAP_CB_TYPE_MESSAGE		0x01
    #define simpleMAP_CB_TYPE_TX_BUF_READY	0x02
    #define simpleMAP_CB_TYPE_TX_ACK_RCV	0x03
    #define simpleMAP_CB_TYPE_LOGFROMSECURE	0x04
    #define simpleMAP_CB_TYPE_ERROR	        0x05
    #define simpleMAP_CB_TYPE_MESSAGE_HMAC  0x06
    
    
    //--- APPLICATION SETTINGS
    //--- IT is passed by APPLICATION INIT TO ENABLE/DISABLE DEBUG MESSAGES
    uint8_t simpleMAP_APPLICATION_SETTINGS;
    #define simpleMAP_SETTINGS_DEFAULT		0x00
    #define simpleMAP_SETTINGS_DEBUG		0x80
    
    //--- ECC608 DEFINITIONS
    //--- Defines Baud rates and address for I2C
    //--- and defines the slots for keys 
    //--- ECC608 I2C BAUD RATE DEFINITIONS 
    //--- One of this value must be passed to the library init function to
    //--- specify what speed is set on ECC I2C bus
    #define I2C_BAUDRATE_100K       0x00
    #define I2C_BAUDRATE_400K       0x01
    #define I2C_BAUDRATE_1M         0x02
    //--- ECC I2C ADDRESS
    //--- Example value: Must be passed to the library init function 
    #define ECC_I2C_7BIT_ADDRESS    0xC0
    //--- ECC608 SLOT DEFINITIONS
    #define SLOT_DEVICE_PRIVATE         0
    #define SLOT_BOOTSTRAP_PRIVATE      2 //ONLY FOR TESTING, WILL BE 2
    #define SLOT_IO_PROTECTION          6
    #define SLOT_TRUST_CHAIN            8
    #define SLOT_CA_PUBLIC             13

    
    //--- simpleMAP CHANNEL TX and RX Queue size
    //--- This is the static memory dedicated to TX and RX queue on 
    //--- simpleMAP channel: RAM occupied is QUEUE_CAPACITY * 16byte(element size) * 2(TX + RX) 
    #define QUEUE_CAPACITY		100
    
    //--- INTERNAL ASSERT AND VALIDATE FUNCTIONS
    #define simpleMAP_ASSERT_BOOL(var,string9)   if(var==false){simpleMAP_debug_out((uint8_t *)"FATAL: ",7);simpleMAP_debug_out((uint8_t *)string9,9);while(1);};
    #define simpleMAP_VALIDATE_BOOL(var,string9) if(var==false){simpleMAP_debug_out((uint8_t *)"ERROR: ",7);simpleMAP_debug_out((uint8_t *)string9,9);return true;};
    #define simpleMAP_VALIDATE(var,string9) if(var==false){simpleMAP_debug_out((uint8_t *)"ERROR: ",7);simpleMAP_debug_out((uint8_t *)string9,9);return false;};
    
    //--- USER FW VERSION
    extern uint8_t			PRESENT_FW_VER[2];
    
    //--- FLASH ADDRESSES
    //--- 7C00 - 8000 = RESERVED FOR TRUST-ZONE MANAGER = 1024
    //--- Defines the addresses for storing commontable and secure storage
    //--- structures. Defines also the start of the usercode
    //#define FLASH_ADD_COMMON_TABLE    0x00007A00
    //#define FLASH_ADD_SECURE_STORAGE  0x00007B00
    //#define FLASH_ADD_USERCODE_START  TZ_START_NS

    
    //--- Defines the handshake types
    #define ACTIVE_HANDSHAKE_STANDARD     0
    #define ACTIVE_HANDSHAKE_EXTENDED     1
    

    //--- USER DEFINED 
    //--- IO PROTECTION KEY DEFAULT VALUE
    static const uint8_t default_IOPROTECTIONKEY[32] = {
        0x7D, 0xF0, 0x8B, 0x62, 0xBA, 0xAB, 0x3F, 0xF2,
        0x7F, 0x53, 0xA4, 0xBB, 0x98, 0xB6, 0x5A, 0x0C,
        0x4F, 0x88, 0x17, 0xC6, 0x7C, 0x58, 0x30, 0xEE,
        0x32, 0x7E, 0x25, 0xCD, 0x6F, 0x30, 0x78, 0x99
    };
    //--- ROOT CA PUBLIC KEY
    /*static const uint8_t ROOTCA_PUBLIC[64] = {
        0xF0, 0x00, 0x9B, 0x35, 0xA7, 0xB6, 0xE5, 0x1B,   0xBD, 0xBD, 0xBA, 0xFF, 0x3C, 0x2A, 0xF9, 0x5D, 
        0xD1, 0xEB, 0x71, 0xA5, 0x0E, 0x43, 0xB1, 0x6A,   0x19, 0x08, 0x5E, 0xE4, 0xE0, 0x1E, 0x96, 0x16, 
        0x22, 0x0B, 0x82, 0xCC, 0xFD, 0x23, 0xBB, 0x4E,   0x3F, 0xEF, 0x50, 0xB7, 0x46, 0x1E, 0xB1, 0xEE, 
        0x91, 0xB4, 0x9F, 0x1C, 0xBD, 0x6D, 0xCD, 0x12,   0x3C, 0xFA, 0x8D, 0xD6, 0x0C, 0x74, 0x2D, 0x99
    };*/
   /* static const uint8_t ROOTCA_PUBLIC[64] = {
            0x0B, 0xB5, 0x32, 0x1F, 0x3D, 0x52, 0x85, 0xDD,   0x4E, 0x70, 0xD0, 0xAC, 0x59, 0x20, 0x4F, 0xDB, 
            0x39, 0x0B, 0x68, 0x08, 0x97, 0x0F, 0xE0, 0x73,   0x6A, 0x8B, 0x85, 0x90, 0x94, 0x5A, 0x45, 0x71, 
            0x3F, 0x04, 0xEE, 0x8F, 0x36, 0xF9, 0x6D, 0xD9,   0xC6, 0x7A, 0x20, 0xFD, 0x00, 0x5C, 0xB7, 0xD6, 
            0x3A, 0x8D, 0xFD, 0x4B, 0x0C, 0x38, 0xDC, 0xE2,   0x45, 0xB7, 0xAD, 0xB2, 0x4D, 0x46, 0x10, 0x11
      };*/
    
    static const uint8_t ROOTCA_PUBLIC[64] = {
        0x95, 0x46, 0x54, 0x54, 0x7C, 0x94, 0x0E, 0xC6,   0x35, 0x06, 0x7E, 0xB8, 0xE5, 0xD5, 0x0F, 0x71, 
        0xC9, 0x2C, 0xC8, 0x08, 0x17, 0x6C, 0xAD, 0x3E,   0xE2, 0x5D, 0x2C, 0x34, 0xF8, 0x4F, 0x07, 0x57, 
        0x2E, 0x07, 0x42, 0xC7, 0x5B, 0x50, 0x8F, 0xF3,   0x01, 0xF5, 0x47, 0xD5, 0x3D, 0x0E, 0x77, 0x39, 
        0x82, 0xF0, 0xED, 0xAE, 0xF4, 0xBF, 0x1F, 0x25,   0x49, 0x74, 0x91, 0x72, 0xCF, 0x67, 0x10, 0x54
    };
    
    //--- **************************************
    //--- SIMPLEMAP LIBRARY APIs
    //--- **************************************
    //--- Those functions are the APIs used by the user code and by the eventual TZ to initialize and 
    //--- manage the communications
    //--- ** INIT LIBRARY ** ---//
    //--- PARAMETERS: 
    //--- - ecc i2c address and baudrate
    //--- - 3 flash addresses: 256B sector add for Common Table, 256B sector add for Secure Storage, 
    //---   and flash address of usercode start
    //--- - default IOProtection Value (if not null and slot is unlocked will be inserted)
    //--- - Root CA Public key, if ecc slot is not locked, will ensure it contains the one provided
    bool simpleMAP_Library_init(uint8_t ecc_i2c_add, uint8_t ecc_i2c_baudrate, uint32_t flash_addresses[3], uint8_t * defaultIOP, uint8_t * myRootCAPublic);
    //--- ** SIMPLEMAP TASK: CORE OF THE LIBRARY FUNCTION: MUST BE CALLED EVERY 1 ms  ** ---//
    void simpleMAP_Task( void );
    //--- ** DATA RECEIVED: INSERT simpleMAP_RECEIVE_BUFFER in RX Queue ** ---//
    //--- usually called by the DMA interrupt
     bool simpleMAP_INSERT_IN_RX_QUEUE( void );
    //--- ** DATA TO TRANSMIT: INSERT INTO simpleMAP_TRANSMIT_BUFFER bytes from TX Queue ** ---//
    //--- usually called by the DMA interrupt
    void simpleMAP_TRANSFER_NEXT_IN_TX_QUEUE( void );
    //--- ** DATA TO TRANSMIT: INSERT GENERIC BUFFER IN TX QUEUE ** ---//
    bool simpleMAP_TRANSMIT_ON_CHANNEL(uint8_t * data, uint16_t len);
    //--- ** DATA TO TRANSMIT: APPLICATION API TO SEND A GENERIC BUFFER INTO SIMPLEMAP CHANNEL ** ---//
    bool simpleMAP_APPLICATION_SEND_MESSAGE(uint8_t * buffer, uint16_t bufferlength, bool addhmac, bool requestack);
    //--- ** CHANNEL CONTROL: RESET/INITIALIZE A CHANNEL  ** ---//
    void simpleMAP_channel_reset( void );
    //--- ** CHANNEL CONTROL:  START A NEW ONE WITH ACTIVE HANDSHAKE ** ---//
    void simpleMAP_StartNewChannel( uint8_t type);
    //--- ** CHANNEL CONTROL:  PERFORM A KEY ROTATION ** ---//
    void simpleMAP_start_key_rotation ( void );
    //--- ** TRUSTED BOOT: perform validity checks on user code  ** ---//
    bool simpleMAP_Trusted_Boot( void );
    //--- ** INVALIDATE USER CODE: clears user code signature to prevent user code boot  ** ---//
    bool simpleMAP_Invalidate_USer_Code( void );
    //--- ** TRUST CHAIN CHECK: check entire chain up to ROOT CA For VALIDATION ** ---//
    bool simpleMAP_TrustChainCheck( uint8_t * public );
     //--- ** CHECK IF APPLICATION CODE REQUESTED DEBUG ENABLED ** ---//
    bool simpleMAP_DEBUG_ENABLED( void );
    //--- **************************************
    //--- SIMPLEMAP LIBRARY APIs END
    //--- **************************************
    
#ifdef __cplusplus
}
#endif

#endif /* _SIMPLEMAP_LIBRARY_H */

/* *****************************************************************************
 End of File
 */
