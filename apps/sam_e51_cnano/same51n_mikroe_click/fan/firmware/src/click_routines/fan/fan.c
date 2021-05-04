/*******************************************************************************
  Fan click source file

  Company:
    Microchip Technology Inc.

  File Name:
    fan.c

  Summary:
    Fan click routine Implementation File.

  Description:
    This file defines the interface to Fan click using I2C PLIB.
    This click routine provides to control DC fan.
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
#include "fan.h"
#include "click_routines/click_interface.h"

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define EMC2301_I2C_ADDR 0x2F

/**
 * EMC2301 Registers
 */
#define EMC2301_CONFIGURATION       0x20 /**< Configures the clocking and watchdog functions. default 0x40 R/W */
#define EMC2301_FAN_STATUS          0x24 /**< Stores the status bits for the RPM-based Fan Speed Control Algorithm. default 00 R-C */
#define EMC2301_FAN_STALL_STATUS    0x25 /**< Stores status bits associated with a stalled fan. default 0x00 R-C */
#define EMC2301_FAN_SPIN_STATUS     0x26 /**< Stores status bits associated with a spin-up failure. default 0x00 R-C */
#define EMC2301_DRIVE_FAIL_STATUS   0x27 /**< Stores status bits associated with drive failure. default 0x00 R-C */
#define EMC2301_FAN_INTERRUPT_ENABLE 0x29 /**< Controls the masking of interrupts on all channels. default 0x00 R/W */
#define EMC2301_PWM_POLARITY        0x2A /**< Configures polarity of the PWM driver. default 0x00 R/W */
#define EMC2301_PWM_OUTPUT_CONFIG   0x2B /**< Configures output type of the PWM driver. default 0x00 R/W */
#define EMC2301_PWM_BASE_FREQ       0x2D /**< Selects the base frequency for the PWM output. default 0x00 R/W */
#define EMC2301_FAN_SETTING         0x30 /**< Always displays the most recent fan input setting for the fan.  If the RPM based fan speed
                                            control algorithm is disabled, allows direct user control of the fan driver. default 0x00 R/W */
#define EMC2301_PWM_DIVIDE          0x31 /**< Sores the divide ratio to set the freq of the fan driver. default 0x01 R/W */
#define EMC2301_FAN_CONFIG1         0x32 /**< Sets configuration values for the RPM base fan speed control. default 0x2B R/W */
#define EMC2301_FAN_CONFIG2         0x33 /**< Sets additional configuration values for the fan driver.  default 0x28 R/W */
#define EMC2301_GAIN                0x35 /**< Holds the gain terms used by the RPM based Fan Speed Control Algorithm for the Fan driver. 0x2A R/W */
#define EMC2301_FAN_SPINUP          0x36 /**< Sets the configuration values for Spin Up Routine of the Fan driver. default 0x19 R/W */
#define EMC2301_FAN_MAX_STEP        0x37 /**< Sets the maximum change per update for the Fan drive. default 0x10 R/W */
#define EMC2301_FAN_MIN_DRIVE       0x38 /**< Sets the min drive value of the fan driver. default 0x66 40% R/W */
#define EMC2301_FAN_VALID_TACH      0x39 /**< Holds the tachometer reading that indicates Fan is spinning properly. default 0xF5 R/W */
#define EMC2301_FAN_FAIL_LOW        0x3A /**< Stores the number of tach counts used to determine how the actual fan speed must match the target fan speed at full scale. */
#define EMC2301_FAN_FAIL_HIGH       0x3B
#define EMC2301_TACH_TARGET_LOW     0x3C /**< Holds the target tachometer reading low byte for the Fan. default 0xF8 R/W */
#define EMC2301_TACH_TARGET_HIGH    0x3D /**< Holds the target tachometer reading high byte for the Fan. default 0xFF R/W */
#define EMC2301_TACH_READING_HIGH   0x3E /**< Holds the tachometer reading high byte for the Fan. default 0xFF R/W */
#define EMC2301_TACH_READING_LOW    0x3F /**< Holds the tachometer reading low byte for the Fan. default 0xF8 R/W */
#define EMC2301_SOFTWARE_LOCK       0xEF /**< Locks all SWL registers. default 0x00 R/W */
#define EMC2301_PRODUCT_ID          0xFD /**< Stores the unique product ID. default 0x37 R */
#define EMC2301_MANUFACTUERE_ID     0xFE /**< Stores the manufacturer ID. default 0x5D R */
#define EMC2301_REVISION            0xFF /**< Revision. default 0x80 R */

/******************************************************************************
* Configuration Constants
*******************************************************************************/
#define EMC2301_CLOCK_FREQ_HZ       32768
#define EMC2301_FAN_POLES           2


/******************************************************************************
* Macros
*******************************************************************************/
#define EMC2301_SET_VALUE(n, x)            ((x << n ## _SHIFT) & n ## _MASK)
#define EMC2301_GET_VALUE(n, x)            ((x & n ## _MASK) >> n ## _SHIFT)

#define EMC2301_FAN_CONFIG1_EN_ALGO_SHIFT       0x07
#define EMC2301_FAN_CONFIG1_EN_ALGO_MASK        0x80
#define EMC2301_FAN_CONFIG1_EN_ALGO_VALUE(x)    EMC2301_GET_VALUE(EMC2301_FAN_CONFIG1_EN_ALGO, x)
#define EMC2301_FAN_CONFIG1_EN_ALGO(x)          EMC2301_SET_VALUE(EMC2301_FAN_CONFIG1_EN_ALGO, x)
#define EMC2301_FAN_CONFIG1_RANGE_SHIFT         0x05
#define EMC2301_FAN_CONFIG1_RANGE_MASK          0x60
#define EMC2301_FAN_CONFIG1_RANGE_VALUE(x)      EMC2301_GET_VALUE(EMC2301_FAN_CONFIG1_RANGE, x)
#define EMC2301_FAN_CONFIG1_RANGE(x)            EMC2301_SET_VALUE(EMC2301_FAN_CONFIG1_RANGE, x)
#define EMC2301_FAN_CONFIG1_EDGES_SHIFT         0x03
#define EMC2301_FAN_CONFIG1_EDGES_MASK          0x18
#define EMC2301_FAN_CONFIG1_EDGES_VALUE(x)      EMC2301_GET_VALUE(EMC2301_FAN_CONFIG1_EDGES, x)
#define EMC2301_FAN_CONFIG1_EDGES(x)            EMC2301_SET_VALUE(EMC2301_FAN_CONFIG1_EDGES, x)


static uint8_t fan_config_reg;

static uint8_t fan_read(uint8_t reg)
{
    uint8_t rxdata;
    
    CLICK_FAN_I2C_WriteRead(EMC2301_I2C_ADDR,&reg,1,&rxdata,sizeof(rxdata));
    
    while(CLICK_FAN_I2C_IsBusy() == true);
    
    return rxdata;
}

static void fan_write(uint8_t reg, uint8_t txdata)
{   
    uint8_t testTxData[20] ;
    
    testTxData[0] = reg;

    memcpy(&testTxData[1],&txdata,sizeof(txdata));

    CLICK_FAN_I2C_Write(EMC2301_I2C_ADDR,testTxData,sizeof(txdata)+1);
    
    while(CLICK_FAN_I2C_IsBusy() == true);
     
}

static uint16_t fan_rpm_to_count(uint32_t rpm)
{
    /* To convert from count to rpm where:
        p = # of poles of the motor
        n = # of edges observed per rotation
        m = multiplier defined by the range bits
        f = measurement frequency
        
        RPM = (n - 1) * m * f * 60 / (p * c)
    */
    /* Load the constants */
    uint32_t count = EMC2301_CLOCK_FREQ_HZ * 60 / EMC2301_FAN_POLES;

    /* Edges */
    count *= 2 * (1 + EMC2301_FAN_CONFIG1_EDGES_VALUE(fan_config_reg));
    
    /* Multiplier */
    count *= 1 << EMC2301_FAN_CONFIG1_RANGE_VALUE(fan_config_reg);

    /* Convert */
    count /= rpm;

    return (uint16_t)count;
}


static void fan_set_target_tach( uint16_t tach )
{
    if(0 == tach)
    {
        fan_write(EMC2301_TACH_TARGET_LOW, 0xFF);
        fan_write(EMC2301_TACH_TARGET_HIGH, 0xFF);
    }
    else
    {
        tach = fan_rpm_to_count(tach);

        fan_write(EMC2301_TACH_TARGET_LOW, tach << 3);
        fan_write(EMC2301_TACH_TARGET_HIGH, tach >> 5);
    }
}

int fan_init( void )
{
    uint8_t pid = fan_read(EMC2301_PRODUCT_ID);
    uint8_t mid = fan_read(EMC2301_MANUFACTUERE_ID);

    if(0x37 != pid || 0x5D != mid)
    {
        return -1;
    }
    
    fan_write(EMC2301_FAN_CONFIG1, 0xAE);

    fan_write(EMC2301_FAN_MIN_DRIVE, 0x35);

    fan_write(EMC2301_FAN_VALID_TACH, 0xF6);

    fan_write(EMC2301_FAN_SPINUP, 0xFF);

    fan_write(EMC2301_PWM_POLARITY, 0x00);

    fan_config_reg = fan_read(EMC2301_FAN_CONFIG1);

    return 0;
}

void fan_switch_off()
{
    fan_set_target_tach(0x00);
}

void fan_switch_on()
{
    fan_set_target_tach(0x3F);
}

void fan_set_speed(fan_speed_t fspeed)
{
    if(fspeed == SPEED_MEDIUM)
    {
        fan_set_target_tach(0x3F);        
    }
    else if(fspeed == SPEED_LOW)
    {
        fan_set_target_tach(0x7F);  
    }
    else if(fspeed == SPEED_HIGH)
    {
        fan_set_target_tach(0x01);  
    }
    else
    {
        ;
    }    
}