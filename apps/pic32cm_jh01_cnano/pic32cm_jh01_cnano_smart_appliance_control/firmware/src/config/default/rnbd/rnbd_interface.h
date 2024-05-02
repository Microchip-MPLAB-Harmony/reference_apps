/**
 * \file rnbd_interface.h
 * \brief This file provides and interface between the RNBD and the hardware.
 */
/*
    (c) 2023 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/
#ifndef RNBD_INTERFACE_H
#define	RNBD_INTERFACE_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/* RNBD Packet Size = RN_PAYLOAD_SIZE + 19U (Header Size) */
#define RN_PAYLOAD_SIZE (237U)

/**
 * \ingroup RNBD_INTERFACE
 * Enum of the RNBD System Configuration Modes
 */
typedef enum
{
    TEST_MODE           = 0x00,
    APPLICATION_MODE    = 0x01 
}RNBD_SYSTEM_MODES_t;

/**
 * \ingroup RNBD_INTERFACE
 * Struct of RNBD Interface Function Pointer Prototypes
 */
typedef struct
{
    // RNBD UART interface control
    void (*Write)(uint8_t txData);
    uint8_t (*Read)(void);
    bool (*TransmitDone)(void);
    bool (*DataReady)(void);
    // RNBD RX_IND pin control
    void (*IndicateRx)(bool value);
    // RNBD Reset pin control
    void (*ResetModule)(bool value);
    // RNBD Mode pin set
    void (*SetSystemMode)(RNBD_SYSTEM_MODES_t mode);
    // Delay API
    void (*DelayMs)(uint32_t delayCount);
    // Status Message Handler
    void (*AsyncHandler)(char* message);
}iRNBD_FunctionPtrs_t;

extern const iRNBD_FunctionPtrs_t RNBD;

struct OTA_REQ_PARAMETER{
    unsigned long total_image_size;
    unsigned long image_ID;
    unsigned long image_version;
    unsigned int connection_handle;
    unsigned int fwimage_checksum;
    unsigned int fwimage_crc16;
};


/**
 * \ingroup RNBD_INTERFACE
 * \brief Checks Connected State of RNBD
 * \return Connected Status
 * \retval true - Connected.
 * \retval false - Not Connected
 */
bool RNBD_IsConnected(void);
uint8_t UART_CDC_Read(void);
void UART_CDC_write(uint8_t buffer);
size_t UART_CDC_DataReady(void);
uint8_t UART_BLE_Read(void);
void UART_BLE_write(uint8_t buffer);
size_t UART_BLE_DataReady(void);
bool UART_BLE_TransmitDone(void);
bool RNBD_IsOTABegin(void);
bool RNBD_IsStreamopen(void);

#endif	/* RNBD_INTERFACE_H */