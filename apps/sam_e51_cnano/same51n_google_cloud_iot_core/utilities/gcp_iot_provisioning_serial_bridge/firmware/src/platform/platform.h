/**
 *
 * Copyright (c) 2019 Microchip Technology Inc. and its subsidiaries.
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#ifndef _PLATFORM_H
#define _PLATFORM_H

#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif

void SerialBridge_PlatformInit(void);
void SerialBridge_PlatformUARTSetBaudRate(uint32_t baud);
size_t SerialBridge_PlatformUARTReadGetCount(void);
uint8_t SerialBridge_PlatformUARTReadGetByte(void);
size_t SerialBridge_PlatformUARTReadGetBuffer(void *pBuf, size_t numBytes);
size_t SerialBridge_PlatformUARTWriteGetCount(void);
bool SerialBridge_PlatformUARTWritePutByte(uint8_t b);
bool SerialBridge_PlatformUARTWritePutBuffer(const void *pBuf, size_t numBytes);
uint32_t ATCMD_PlatformGetSysTimeMs(void);

#ifdef __cplusplus
}
#endif

#endif /* _PLATFORM_H */
