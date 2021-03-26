/*******************************************************************************
  source file

  Company:
    Microchip Technology Inc.

  File Name:
    leddriver3.c

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
#include "leddriver3.h"
#include "click_interface.h"
#define LED_DRV_SLAVE_ADDRESS 0x38

//#define CLICK_I2C_Write 			SERCOM2_I2C_Write
//#define CLICK_I2C_IsBusy 			SERCOM2_I2C_IsBusy
//#define CLICK_I2C_WriteRead			SERCOM2_I2C_WriteRead

void led_driver3_write ( uint8_t wrData )
{
    CLICK_I2C_Write( LED_DRV_SLAVE_ADDRESS, &wrData, 1 );
    while(CLICK_I2C_IsBusy() == true);
}

void led_driver3_write_read (uint8_t wrData, uint8_t *rdData, uint8_t len )
{
    CLICK_I2C_WriteRead( LED_DRV_SLAVE_ADDRESS, &wrData, 1, rdData, len );
    while(CLICK_I2C_IsBusy() == true);
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

    CLICK_I2C_Write( LED_DRV_SLAVE_ADDRESS, &write_reg[0], 1 );
    while(CLICK_I2C_IsBusy() == true);

    CLICK_I2C_Write( LED_DRV_SLAVE_ADDRESS, &write_reg[1], 1 );
    while(CLICK_I2C_IsBusy() == true);

    CLICK_I2C_Write( LED_DRV_SLAVE_ADDRESS, &write_reg[2], 1 );
    while(CLICK_I2C_IsBusy() == true);

}

void led_driver3_shut_down ()
{
    uint8_t write_reg[ 1 ];

    write_reg[ 0 ] = 0x00;

    led_driver3_write(write_reg[0] );
}

void led_driver3_set_timer (uint8_t time )
{
     led_driver3_write(time );
}

// ------------------------------------------------------------------------- END

