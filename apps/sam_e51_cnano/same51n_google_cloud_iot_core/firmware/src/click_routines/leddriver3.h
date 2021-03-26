/*******************************************************************************
  Header file

  Company:
    Microchip Technology Inc.

  File Name:
    leddriver3.h

  Summary:

  Description:
 *******************************************************************************/
// DOM-IGNORE-BEGIN
/*
    (c) 2021 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/
// DOM-IGNORE-END
// ----------------------------------------------------------------------------

#ifndef LEDDRIVER3_H
#define LEDDRIVER3_H

#include "definitions.h"

#define LED_DRIVER_3_COLOR_RED      0x5F6080
#define LED_DRIVER_3_COLOR_ORANGE   0x5F6280
#define LED_DRIVER_3_COLOR_YELLOW   0x5F7480
#define LED_DRIVER_3_COLOR_GREEN    0x407F80
#define LED_DRIVER_3_COLOR_BLUE     0x40609F
#define LED_DRIVER_3_COLOR_WHITE    0x5F7F9F
#define LED_DRIVER_3_COLOR_PURPLE   0x58609C
#define LED_DRIVER_3_COLOR_OFF      0x000000
                 
#define LED_DRIVER_3_TIMER_8ms      0xE1
#define LED_DRIVER_3_TIMER_16ms     0xE2
#define LED_DRIVER_3_TIMER_32ms     0xE4
#define LED_DRIVER_3_TIMER_64ms     0xE8
#define LED_DRIVER_3_TIMER_128ms    0xE0
                  
#define LED_DRIVER_3_BRIGHTNESS_1    0x01
#define LED_DRIVER_3_BRIGHTNESS_2    0x02
#define LED_DRIVER_3_BRIGHTNESS_4    0x04
#define LED_DRIVER_3_BRIGHTNESS_8    0x08
#define LED_DRIVER_3_BRIGHTNESS_16   0x10
                  
#define LED_DRIVER_3_INCREMENT      0xA0
#define LED_DRIVER_3_DECREMENT      0xC0
#define LED_DRIVER_3_CONSTANT       0x20

void led_driver3_write ( uint8_t wrData );
void led_driver3_write_read (uint8_t wrData, uint8_t *rdData, uint8_t len );
void led_driver3_set_brightness (uint8_t brightness );
void led_driver3_set_color (uint32_t color );
void led_driver3_off ();
void led_driver3_set_timer (uint8_t time );

#endif  