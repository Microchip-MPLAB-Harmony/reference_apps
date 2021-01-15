/**
 * @page specifications Specifications
 * @par
 * <a href="http://ww1.microchip.com/downloads/en/DeviceDoc/2301.pdf">Datasheet</a>
 *
 * @section FEATURES
 *
 * @par
 * Programmable Fan Control circuit
 * <ul>
 * <li>4-wire fan compatible</li>
 * <li>High speed PWM (26 kHz)</li>
 * <li>Low speed PWM (9.5Hz - 2240 Hz)</li>
 * <li>Optional detection of aging fans</li>
 * <li>Fan Spin Up Control and Ramp Rate Control</li>
 * <li>Alert on Fan Stall</li>
 * </ul>
 *
 * <ul>
 * <li>Watchdog Timer</li>
 * </ul>
 *
 * <ul>
 * <li>RPM-based fan control algorithm</li>
 * <li>0.5% accuracy from 500 RPM to 16k RPM (external crystal oscillator)</li>
 * <li>1% accuracy from 500 RPM to 16k RPM (internal clock)</li>
 * </ul>
 *
 * <ul>
 * <li>SMBus 2.0 Compliant</li>
 * SMBus Alert compatible</li>
 * </ul>
 *
 * <ul>
 * <li>CLK Pin can provide a clock source output</li>
 * <li>Available in an 8-pin MSOP RoHS Compliant package</li>
 * </ul>
 *
 * @par
 * Applications
 * <ul>
 * <li>Servers</li>
 * <li>Projectors</li>
 * <li>Industrial and Networking Equipment</li>
 * <li>Notebook Computers</li>
 * </ul>
 */
// DOM-IGNORE-BEGIN
/*******************************************************************************************
* � [2020] Microchip Technology Inc. and its subsidiaries
 
 * Subject to your compliance with these terms, you may use this Microchip software
 * and any derivatives exclusively with Microchip products. You are responsible for 
 * complying with third party license terms applicable to your use of third party 
 * software (including open source software) that may accompany this Microchip software.
 
 * SOFTWARE IS ?AS IS.? NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO 
 * THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, 
 * SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF 
 * THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, 
 * MICROCHIP?S TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT EXCEED AMOUNT 
 * OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE. ADDITIONALLY, MICROCHIP 
 * OFFERS NO SUPPORT FOR THE SOFTWARE. YOU MAY CONTACT YOUR LOCAL MICROCHIP FIELD SALES SUPPORT 
 * REPRESENTATIVE TO INQUIRE ABOUT SUPPORT SERVICES AND APPLICABLE FEES, IF ANY. THESE TERMS 
 * OVERRIDE ANY OTHER PRIOR OR SUBSEQUENT TERMS OR CONDITIONS THAT MIGHT APPLY TO THIS SOFTWARE 
 * AND BY USING THE SOFTWARE, YOU AGREE TO THESE TERMS. 
*******************************************************************************************/
// DOM-IGNORE-END
#ifndef FAN_CLICK_H_
#define FAN_CLICK_H_

/******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>
#include <stdbool.h>

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

/******************************************************************************
* Typedefs
*******************************************************************************/
/**
 * @enum Configuration Bits
 */
enum
{
    USE_EXT_CLK = 0,    /**< Enables the EMC2301 to use a clock present on the CLK */
    DR_EXT_CLK  = 2,    /**< Enables the internal tach clock */
    WD_EN       = 32,   /**< Enables the watchdog timer. default 0 */
    DIS_TO      = 64,   /**< Disables the SMBus timeout function, 1 default */
    MASK        = 128   /**< Blocks the ALERT pin from being asserted, 0 default */
};

/**
 * @enum Status register results
 */
typedef enum
{
    FAN_STALL = 1,      /**< Indicates that the fan driver has stalled */
    FAN_SPIN  = 2,      /**< Indicates that the fan driver cannot spin up */
    FAN_DRIVE_FAIL = 4, /**< Indicates that the driver cannot meet the programmed fan speed */
    FAN_WATCH = 128     /**< Indicates that the watchdog timer has expired */
} fan_status_t;

/**
 * @enum FAN PWM Base frequencies
 */
typedef enum
{
    FAN_FREQ_26KHZ = 0, /**< Base of 26kHz */
    FAN_FREQ_19_531KHZ, /**< Base of 19.5431kHz */
    FAN_FREQ_4_882HZ,   /**< Base of 4.882Hz */
    FAN_FREQ_2_441HZ    /**< Base of 2.441Hz */
} fan_base_freq_t;


/**
 * @enum Range of tach readings
 *
 * Adjusts the range of reported and programmed tachometer reading values.
 * The RANGE bits determine the weighting of all TACH values
 */
typedef enum
{
    RPM_MIN_500,
    RPM_MIN_1000,
    RPM_MIN_2000,
    RPM_MIN_4000
} fan_range_t;

/**
 * @enum Number of Fan Edges
 *
 * Determines the minimum number of edges that must be detected on the
 * TACHx signal to determine a single rotation. A typical fan measured 5 edges
 * ( for a 2-pole fan ). For more accurate tachometer measurement, the minimum
 * number of edges measured may be increased.
 */
typedef enum
{
    EDGE_1_POLE,
    EDGE_2_POLE,
    EDGE_3_POLE,
    EDGE_4_POLE
} fan_edges_t;

/**
 * @enum Update Time Configuration
 */
typedef enum
{
    UPDATE_100MS,
    UPDATE_200MS,
    UPDATE_300MS,
    UPDATE_400MS,
    UPDATE_500MS,
    UPDATE_800MS,
    UPDATE_1200MS,
    UPDATE_1600MS
} fan_update_t;

/**
 * @enum Derivative options
 *
 * Control some of the advanced options that affect the derivative portion of
 * the RPM-based Fan Speed Control Algorithm
 */
typedef enum
{
    DERIVATIVE_NONE,
    DERIVATIVE_BASIC,
    DERIVATIVE_STEP,
    DERIVATIVE_BOTH
} fan_derivative_t;


/**
 * @enum Error range options
 *
 * Control some of the advanced options that affect the error window. When the
 * measured fan speed is within the programmed error window around the target
 * speed, then the fan drive setting is not updated. The algorithm will
 * continue to monitor the fan speed and calculate necessary drive setting
 * changes based on the error.
 */
typedef enum
{
    RPM_0,
    RPM_50,
    RPM_100,
    RPM_200
} fan_error_t;


/**
 * @enum Gain for PID settings
 *
 */
typedef enum
{
    FAN_GAIN1X,
    FAN_GAIN2X,
    FAN_GAIN4X,
    FAN_GAIN8X
} fan_gain_t;


/**
 * @enum How mnay update cycles are used for detection of error
 *
 * Determines how many update cycles are used for the Drive Fail detection
 * function
*/
typedef enum
{
    DRIVE_CNT_DISABLED,
    DRIVE_CNT_16,
    DRIVE_CNT_32,
    DRIVE_CNT_64,
} fan_drive_fail_count_t;


/**
 * @enum Spin up percent
 *
 * Determines the final drive level that is used by the Spin Up Routine
 */
typedef enum
{
    SPINUP_30PERCENT, /**< 30% of duty */
    SPINUP_35PERCENT, /**< 35% of duty */
    SPINUP_40PERCENT, /**< 40% of duty */
    SPINUP_45PERCENT, /**< 45% of duty */
    SPINUP_50PERCENT, /**< 50% of duty */
    SPINUP_55PERCENT, /**< 55% of duty */
    SPINUP_60PERCENT, /**< 60% of duty */
    SPINUP_65PERCENT  /**< 65% of duty */
} fan_spinup_t;


/**
 * @enum Spin time options
 *
 */
typedef enum
{
    SPINUP_250MS, /**< 250ms delay */
    SPINUP_500,   /**< 500ms delay */
    SPINUP_1S,    /**< 1s delay */
    SPINUP_2S     /**< 2s delay */
} fan_spintime_t;

/******************************************************************************
* Variables
*******************************************************************************/


/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initializes the emc2301
 *
 * @param address - slave address of the controller
 * @return int - 0 success / -1 error
 *
 * @code
 * if( !fan_click_init( EMC2301_I2C_ADDRESS ) )
 *     return ERROR_INIT;
 * @endcode
 */
int fan_click_init(void);

/**
 * @brief Specifies external clock speed if different from standard
 *
 * @note Only used if external clock differs from standard(rare). Changes tach
 * calculations - use caution.
 *
 * @param freq - frequency of clock
 */
void fan_click_ext_clock( double freq );

/**
 * @brief Fan configuration
 *
 * The Configuration Register controls the basic functionality of the EMC2301.
 *
 * @param config 
 *
 * @code
 * fan_click_config( USE_EXT_CLK | MASK );
 * @endcode
 */
void fan_click_config( uint8_t config );

/**
 * @brief Fan status
 *
 * The Fan Status register indicates that the fan driver has stalled or failed
 * or that the Watchdog Timer has expired.
 *
 * @return
 * @retval FAN_STALL = 1
 * @retval FAN_SPIN = 2
 * @retval FAN_DRIVE_FAIL = 4
 * @retval FAN_WATCH = 128
 */
fan_status_t fan_click_get_status( void );

/**
 * @brief Fan stall status
 *
 * The Fan Stall Status register indicates that the fan driver has detected a
 * stalled condition
 *
 * @return
 * @retval FAN_STALL = 1
 */
fan_status_t fan_click_get_stall_status( void );

/**
 * @brief Fan spin status
 *
 * The Fan Spin Status register indicates that the fan driver has failed to
 * spin-up.
 *
 * @return
 * @retval 1 FAN_SPIN has failed
 * @retval 0 FAN OK
 */
uint8_t fan_click_get_spin_status( void );

/**
 * @brief Fan click drive fail status
 *
 * The Fan Drive Fail Status register indicates that the fan driver cannot
 * drive to the programmed speed even at 100% duty cycle.
 *
 * @return
 * @retval 1 DRIVE_FAIL
 * @retval 0 DRIVE OK
 */
uint8_t fan_click_get_drive_fail( void );

/**
 * @brief Enable or disable external interrupts
 *
 * The Fan Interrupt Enable controls the masking for the Fan channel. When a
 * channel is enabled, it will cause the ALERT# pin to be asserted when an
 * error condition is detected.
 *
 */
void fan_click_interrupts( bool enable );

/**
 * @brief Reverse polarity of fan.
 *
 * Determines the polarity of the PWM.
 *
 * @param inverted - false default, true inverted
 */
void fan_click_polarity( bool inverted );

/**
 * @brief Configure PWM type 
 *
 * Determines the output type of the PWM driver.
 *
 * @param push_pull - false open drain / true push-pull
 * @note
 * Default mode is open drain
 */
void fan_click_pwm_config( bool push_pull );

/**
 * @brief Base frequency
 *
 * The PWM Base Frequency register determines the base frequency that is used
 * with the PWM Divide register to determine the final PWM frequency.
 *
 * @param freq
 */
void fan_click_pwm_base( fan_base_freq_t freq );

/**
 * @brief Fan setting
 *
 * The Fan Setting register always displays the current setting of the fan
 * driver. Reading from the register will report the current fan speed setting
 * of the fan driver regardless of the operating mode. Therefore it is
 * possible that reading from this register will not report data that was
 * previously written into this register.
 *
 * @param percentage - percentage of duty
 *
 * @note While the RPM-based Fan Speed Control Algorithm is active, the
 * register is read only. Writing to the register will have no effect and the
 * data will not be stored.
 *
 */
void fan_click_settings( double percentage );

/**
 * @brief Read basic setting
 *
 * The Fan Setting register always displays the current setting of the fan
 * driver. Reading from the register will report the current fan speed setting
 * of the fan driver regardless of the operating mode. Therefore it is
 * possible that reading from this register will not report data that was
 * previously written into this register.
 *
 * @param settings
 *
 * @return double - percentage of current drive settings.
 *
 * @note While the RPM-based Fan Speed Control Algorithm is active, the
 * register is read only. Writing to the register will have no effect and the
 * data will not be stored.
 */
double fan_click_get_settings( void );

/**
 * @brief Divide PWM signal
 *
 * The PWM Divide registers determine the final frequency of the PWM Fan
 * Driver. The driver base frequency is divided by the value of the PWM Divide
 * Register to determine the final frequency. The duty cycle settings are not
 * affected by these settings, only the final frequency of the PWM driver. A
 * value of 00h will be decoded as 01h.
 *
 * @param divide
 */
void fan_click_set_PWM_divide( uint8_t divide );

/**
 * @brief Enable Fan Control Algorithm
 *
 * Changes the mode from manual to automatic fan speed control.
 *
 * false - (default) the control circuitry is disabled and the fan driver
 * output is determined by the Fan Driver Setting Register.
 * true - the control circuitry is enabled and the Fan Driver output will be
 * automatically updated to maintain the programmed fan speed as indicated by
 * the TACH Target Register.
 *
 * @param fsc - true enables fan control, false manual mode
 */
void fan_click_config_enableFSC( bool fsc );

/**
 * @brief Number of edges that needs to be detected
 *
 * Adjusts the range of reported and programmed tachometer reading values.
 * The RANGE bits determine the weighting of all TACH values
 *
 * @param range
 */
void fan_click_config_range( fan_range_t range );

/**
 * @brief Number of edges on fan
 *
 * Determines the minimum number of edges that must be detected on the TACHx
 * signal to determine a single rotation. A typical fan measured 5 edges
 * (for a 2-pole fan). For more accurate tachometer measurement, the minimum
 * number of edges measured may be increased.
 *
 * @param edges
 */
void fan_click_config_edges( fan_edges_t edges );

/**
 * @brief Update time
 *
 * determines the base time between fan driver updates. The Update Time, along
 * with the Fan Step Register, is used to control the ramp rate of the drive
 * response to provide a cleaner transition of the actual fan operation as
 * the desired fan speed changes.
 *
 * @param update
 */
void fan_click_config_update( fan_update_t update );

/**
 * @brief Ramp up mode
 *
 * Enables ramp rate control when the fan driver is operated in the Direct
 * Setting Mode
 *
 * false (default) - Ramp rate control is disabled. When the fan driver is
 * operating in Direct Setting mode, the fan setting will instantly transition
 * to the next programmed setting.
 *
 * true - Ramp rate control is enabled. When the fan driver is operating in
 * Direct Setting mode, the fan drive setting will follow the ramp rate
 * controls as determined by the Fan Step and Update Time settings. The
 * maximum fan drive setting step is capped at the Fan Step setting and is
 * updated based on the Update Time.
 *
 * @param rampControl
 */
void fan_click_config_enableRamp( bool rampControl );

/**
 * @brief Glitch enable
 *
 * Disables the low pass glitch filter that removes high frequency noise
 * injected on the TACHx pin.
 *
 * @param glitch
 */
void fan_click_config_enableGlitch( bool glitch );

/**
 * @brief Derivative
 *
 * Control some of the advanced options that affect the derivative portion of
 * the RPM-based Fan Speed Control Algorithm
 *
 * @param derivative - Basic derivative / Step Derivative / Both
 *
 * @note BASIC is default
 */
void fan_click_config_derivative( fan_derivative_t derivative );

/**
 * @brief Error Range
 *
 * Control some of the advanced options that affect the error window. When the
 * measured fan speed is within the programmed error window around the target
 * speed, then the fan drive setting is not updated.
 *
 * @param error
 */
void fan_click_config_errorRange( fan_error_t error );

/**
 * @brief Gain D
 *
 * Control some of the advanced options that affect the derivative portion of
 * the RPM-based Fan Speed Control Algorithm. The Gain register stores the
 * gain terms used by the proportional and integral portions of the RPM-based
 * Fan Speed Control Algorithm. These gain terms are used as the KD, KI, and
 * KP gain terms in a classic PID control solution.
 *
 * @param gain
 */
void fan_click_config_gaind( fan_gain_t gain );

/**
 * @brief Gain I
 *
 * Control some of the advanced options that affect the derivative portion of
 * the RPM-based Fan Speed Control Algorithm. The Gain register stores the
 * gain terms used by the proportional and integral portions of the RPM-based
 * Fan Speed Control Algorithm. These gain terms are used as the KD, KI, and
 * KP gain terms in a classic PID control solution.
 *
 * @param gain
 */
void fan_click_config_gaini( fan_gain_t gain );

/**
 * @brief Gain P
 *
 * Control some of the advanced options that affect the derivative portion of
 * the RPM-based Fan Speed Control Algorithm. The Gain register stores the
 * gain terms used by the proportional and integral portions of the RPM-based
 * Fan Speed Control Algorithm. These gain terms are used as the KD, KI, and
 * KP gain terms in a classic PID control solution.
 *
 * @param gain
 */
void fan_click_config_gainp( fan_gain_t gain );

/**
 * @brief Drive Fail Count
 *
 * Determines how many update cycles are used for the Drive Fail
 * detection function.
 *
 * @param count - Disabled / 16 / 32 / 64
 */
void fan_click_config_drivefail( fan_drive_fail_count_t count );

/**
 * @brief fan_click_config_enableNoKick
 *
 * Determines if the Spin Up Routine will drive the fan to 100% duty cycle for
 * 1/4 of the programmed spin up time before driving it at the programmed
 * level.
 *
 * @param noKick
 * false = The spin up routine will drive the fan to 100% for
 * 1/4 of the programmed spin up time before reverting to the programmed spin
 * level.
 * true = The spin up routine will not drive the fan driver to 100%.  It will
 * set the drive at the programmed spin level for the entire duration of the
 * programmed spin up time.
 */
void fan_click_config_enableNoKick( bool noKick );

/**
 * @brief fan_click_config_spinLevel
 *
 * Determines if the Spin Up Routine will drive the fan to 100% duty cycle for
 * 1/4 of the programmed spin up time before driving it at the programmed
 * level.
 *
 * @param spin
 *
 * @code
 * fan_click_config_spinLevel( SPINUP_60PERCENT );
 */
void fan_click_config_spinLevel( fan_spinup_t spin );

/**
 * @brief fan_click_config_spinTime
 *
 * The Fan Spin Up Configuration register controls the settings of Spin Up
 * Routine.
 *
 * @param time
 *
 * @note The Fan Spin Up Configuration register is software locked.
 */
void fan_click_config_spinTime( fan_spintime_t time );

/**
 * @brief fan_click_set_max_step
 *
 * The Fan Max Step register, along with the Update Time, controls the ramp
 * rate of the fan driver response calculated by the RPM-based Fan Speed
 * Control Algorithm. The value of the register represents the maximum step
 * size the fan driver will take between update times
 *
 * @param step
 *
 * @note When the FSC algorithm is enabled, Ramp Rate control is automatically
 * used.
 */
void fan_click_set_max_step( uint8_t step );

/**
 * @brief fan_click_set_min_drive
 *
 * The Fan Minimum Drive register stores the minimum drive setting for the
 * RPM-based Fan Speed Control Algorithm. The RPM-based Fan Speed Control
 * Algorithm will not drive the fan at a level lower than the minimum drive
 * unless the target Fan Speed is set at FFh
 *
 * @param drive
 */
void fan_click_set_min_drive( double min_drive );


/***************************************
 ********** Tach Functions *************
 **************************************/
/**
 * @brief fan_click_set_valid_tach
 *
 * The Valid TACH Count register stores the maximum TACH Reading Register
 * value to indicate that the fan is spinning properly. The value is
 * referenced at the end of the Spin Up Routine to determine if the fan has
 * started operating and decide if the device needs to retry.
 *
 * @param tach
 *
 * @note The Valid TACH Count register is software locked.
 */
void fan_click_set_valid_tach( uint16_t tach );

/**
 * @brief fan_click_set_valid_tach
 *
 * The Valid TACH Count register stores the maximum TACH Reading Register
 * value to indicate that the fan is spinning properly. The value is
 * referenced at the end of the Spin Up Routine to determine if the fan has
 * started operating and decide if the device needs to retry.
 *
 * @return uint16_t
 *
 * @note The Valid TACH Count register is software locked.
 */
uint16_t fan_click_get_valid_tach( void );

/**
 * @brief fan_click_get_driveband_fail
 *
 * The Fan Drive Fail Band Registers store the number of tach counts used by
 * the Fan Drive Fail detection circuitry. This circuitry is activated when
 * the fan drive setting high byte is at FFh. When it is enabled, the actual
 * measured fan speed is compared against the target fan speed. These
 * registers are only used when the FSC is active.
 *
 * @return
 */
uint16_t fan_click_get_driveband_fail( void );

/**
 * @brief fan_click_set_target_tach
 *
 * The TACH Target Registers hold the target tachometer value that is
 * maintained by the RPM-based Fan Speed Control Algorithm.
 *
 * The value in the TACH Target Registers will always reflect the current
 * TACH Target value.
 *
 * If the algorithm is enabled, setting the TACH Target
 * Register to FFh will disable the fan driver (set the fan drive setting to
 * 0%). Setting the TACH Target to any other value (from a setting of FFh)
 * will cause the algorithm to invoke the Spin Up Routine after which it will
 * function normally.
 *
 * The Tach Target is not applied until the high byte is written. Once the
 * high byte is written, the current value of both high and low bytes will be
 * used as the next Tach target.
 *
 *
 * @param tach - RPM 12000
 */
void fan_click_set_target_tach( uint16_t tach );


/**
 * @brief fan_click_get_tach
 *
 * The Valid TACH Count register stores the maximum TACH Reading Register
 * value to indicate that the fan is spinning properly. The value is
 * referenced at the end of the Spin Up Routine to determine if the fan has
 * started operating and decide if the device needs to retry.
 *
 * @note The Valid TACH Count register is software locked. If the TACH Reading
 * Register value exceeds the Valid TACH Count Register (indicating that the
 * Fan RPM is below the threshold set by this count), then a stalled fan is
 * detected. In this condition, the algorithm will automatically begin its
 * Spin Up Routine.
 *
 * @return uint16_t
 *
 */
uint16_t fan_click_get_tach( void );


/****************************************
 ******* Informational Functions ********
 ***************************************/
/**
 * @brief fan_click_lock_registers
 *
 * The Lock Column describes the locking mechanism, if any, used for
 * individual registers. All SWL registers are Software Locked and therefore
 * made read-only when the LOCK bit is set.
 *
 */
void fan_click_lock_registers( bool lock );

/**
 * @brief fan_click_productID
 *
 * The Product ID Register contains a unique 8-bit word that identifies the
 * product.
 *
 * @return Product ID
 */
uint8_t fan_click_productID( void );

/**
 * @brief fan_click_manufactuerID
 *
 * The Manufacturer ID Register contains an 8-bit word that identifies SMSC.
 *
 * @return Manufacturer ID
 */
uint8_t fan_click_manufactuerID( void );


/**
 * @brief fan_click_revision
 *
 * The Revision Register contains an 8-bit word that identifies the die
 * revision.
 *
 * @return Revision number
 */
uint8_t fan_click_revision( void );

#ifdef __cplusplus
} // extern "C"
#endif

#endif /*FILE_CLICK_H_*/