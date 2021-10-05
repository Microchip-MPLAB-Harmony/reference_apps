/*******************************************************************************
  led driver 3 source file

  Company:
    Microchip Technology Inc.

  File Name:
    leddriver3.c

  Summary:
  This file contains the "led driver" function 

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
#include "leddriver3.h"
#include "click_routines/click_interface.h"
#define LED_DRV_SLAVE_ADDRESS 0x38

static void led_driver3_write ( uint8_t wrData )
{
    CLICK_LEDDRIVER3_I2C_Write( LED_DRV_SLAVE_ADDRESS, &wrData, 1 );
    while(CLICK_LEDDRIVER3_I2C_IsBusy() == true);
}

void led_driver3_set_brightness (uint8_t brightness )
{
     led_driver3_write(brightness );
}

void led_driver3_set_color ( uint32_t color )
{
    uint8_t write_reg[ 3 ];

    write_reg[ 0 ] = color;
    write_reg[ 1 ] = color >> 8;
    write_reg[ 2 ] = color >> 16;

    CLICK_LEDDRIVER3_I2C_Write( LED_DRV_SLAVE_ADDRESS, &write_reg[0], 1 );
    while(CLICK_LEDDRIVER3_I2C_IsBusy() == true);

    CLICK_LEDDRIVER3_I2C_Write( LED_DRV_SLAVE_ADDRESS, &write_reg[1], 1 );
    while(CLICK_LEDDRIVER3_I2C_IsBusy() == true);

    CLICK_LEDDRIVER3_I2C_Write( LED_DRV_SLAVE_ADDRESS, &write_reg[2], 1 );
    while(CLICK_LEDDRIVER3_I2C_IsBusy() == true);

}

// ------------------------------------------------------------------------- END

