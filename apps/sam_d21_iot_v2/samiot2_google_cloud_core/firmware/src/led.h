// DOM-IGNORE-BEGIN
/*
    (c) 2022 Microchip Technology Inc. and its subsidiaries. You may use this
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


#ifndef LED_H_
#define LED_H_
#include <stdint.h>
#include <stdbool.h>
#include "definitions.h"

#define LED_ON				false
#define LED_OFF				true

#define LED_YELLOW_SetHigh()    LED_DAT_GPIO_PA11_Set()
#define LED_GREEN_SetHigh()     LED_CON_GPIO_PA20_Set()    
#define LED_BLUE_SetHigh()      LED_WIFI_GPIO_PA21_Set()
#define LED_RED_SetHigh()       LED_ERR_GPIO_PA10_Set()

#define LED_YELLOW_SetLow()     LED_DAT_GPIO_PA11_Clear()
#define LED_GREEN_SetLow()      LED_CON_GPIO_PA20_Clear()
#define LED_BLUE_SetLow()       LED_WIFI_GPIO_PA21_Clear()
#define LED_RED_SetLow()        LED_ERR_GPIO_PA10_Clear()

#define LED_BLUE_Toggle()       LED_WIFI_GPIO_PA21_Toggle()
#define LED_GREEN_Toggle()      LED_CON_GPIO_PA20_Toggle()

void LED_test(void);
void LED_flashYellow(void);
void LED_holdYellowOn(bool holdHigh);
void LED_flashRed(void);
void LED_blinkingBlue(bool amBlinking);
void LED_startBlinkingGreen(void);
void LED_stopBlinkingGreen(void);
bool LED_isBlinkingGreen (void);
void LED_sched(void);

#endif /* LED_H_ */
