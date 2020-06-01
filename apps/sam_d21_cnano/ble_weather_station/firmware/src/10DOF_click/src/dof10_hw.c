/****************************************************************************
* Title                 :   9DOF_Click
* Filename              :   dof9_hw.c
* Author                :   Nikola Golubovic
* Origin Date           :   17/11/2015
* Notes                 :   None
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date    Software Version    Initials    Description
*  17/11/15         1.0             NG
*
*****************************************************************************/
/** @file dof9_hw.c
 *  @brief 9DOF communication driver
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include "../include/dof9_hal.h"
#include "../include/dof9_hw.h"
#include <stdint.h>

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/
/**
 * Doxygen tag for documenting variables and constants
 */

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/
char rawdata[20];

sensor_t LSM9DS1;

// Stores the 16-bit signed accelerometer, gyro, and mag sensor output
static int tmpCount[3];

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/

// LSM9DS1M_ADDRESS
void LSM9DS1_i2c_init( uint8_t mag_address,  uint8_t gyro_address )
{
    dof9_i2c_init( mag_address,  gyro_address );
}

//------------------------------------------------------------------------------
//                         Public functions
//------------------------------------------------------------------------------
char LSM9DS1_GetGyroID()
{
    //must return 0x68
    char cfg[1] = {0};
    dof9_i2c_hal_read( GYRO, LSM9DS1XG_WHO_AM_I, 1, &cfg );
    return cfg[0];
}


char LSM9DS1_GetMagID()
{
    //must return 0x3D
    char cfg[1] = {0};
    dof9_i2c_hal_read( MAG, LSM9DS1M_WHO_AM_I, 1, &cfg );
    return cfg[0];
}

//------------------------------------------------------------------------------
// Set of useful function to access acceleration, gyroscope, magnetometer,
// and temperature data
//------------------------------------------------------------------------------
static void LSM9DS1_SetMagRes()
{
    switch ( LSM9DS1.magScale )
    {
        // Possible magnetometer scales (and their register bit settings) are:
        // 4 Gauss (00), 8 Gauss (01), 12 Gauss (10) and 16 Gauss (11)
        case MFS_4G:
            LSM9DS1.magRes = 4.0 / 32768.0;
            break;
        case MFS_8G:
            LSM9DS1.magRes = 8.0 / 32768.0;
            break;
        case MFS_12G:
            LSM9DS1.magRes = 12.0 / 32768.0;
            break;
        case MFS_16G:
            LSM9DS1.magRes = 16.0 / 32768.0;
            break;
    }
}

static void LSM9DS1_SetGyroRes()
{
    switch ( LSM9DS1.gyroScale )
    {
        // Possible gyro scales (and their register bit settings) are:
        // 245 DPS (00), 500 DPS (01), and 2000 DPS  (11).
        case GFS_245DPS:
            LSM9DS1.gyroRes = 245.0 / 32768.0;
            break;
        case GFS_500DPS:
            LSM9DS1.gyroRes = 500.0 / 32768.0;
            break;
        case GFS_2000DPS:
            LSM9DS1.gyroRes = 2000.0 / 32768.0;
            break;
    }
}

static void LSM9DS1_SetAccelRes()
{
    switch ( LSM9DS1.accelScale )
    {
        // Possible accelerometer scales (and their register bit settings) are:
        // 2 Gs (00), 16 Gs (01), 4 Gs (10), and 8 Gs  (11).
        case AFS_2G:
            LSM9DS1.accelRes = 2.0 / 32768.0;
            break;
        case AFS_16G:
            LSM9DS1.accelRes = 16.0 / 32768.0;
            break;
        case AFS_4G:
            LSM9DS1.accelRes = 4.0 / 32768.0;
            break;
        case AFS_8G:
            LSM9DS1.accelRes = 8.0 / 32768.0;
            break;
    }
}

void LSM9DS1_ReadAccelData()
{
    // Read the six raw data registers into data array
    dof9_i2c_hal_read( GYRO, LSM9DS1XG_OUT_X_L_XL, 6, &rawdata );
    // Turn the MSB and LSB into a signed 16-bit value
    tmpCount[0] = ( ( int )rawData[1] << 8 ) | rawData[0];
    tmpCount[1] = ( ( int )rawData[3] << 8 ) | rawData[2];
    tmpCount[2] = ( ( int )rawData[5] << 8 ) | rawData[4];
    // Now we'll calculate the accleration value into actual g's
    // get actual g value, this depends on scale being set
    LSM9DS1.accelX = ( float )tmpCount[0] * LSM9DS1.accelRes -
                     LSM9DS1.accelBias[0];
    LSM9DS1.accelY = ( float )tmpCount[1] * LSM9DS1.accelRes -
                     LSM9DS1.accelBias[1];
    LSM9DS1.accelZ = ( float )tmpCount[2] * LSM9DS1.accelRes -
                     LSM9DS1.accelBias[2];
}


void LSM9DS1_ReadGyroData()
{
    // Read the six raw data registers sequentially into data array
    dof9_i2c_hal_read( GYRO, LSM9DS1XG_OUT_X_L_G, 6, &rawdata );
    // Turn the MSB and LSB into a signed 16-bit value
    tmpCount[0] = ( ( int )rawData[1] << 8 ) | rawData[0] ;
    tmpCount[1] = ( ( int )rawData[3] << 8 ) | rawData[2] ;
    tmpCount[2] = ( ( int )rawData[5] << 8 ) | rawData[4] ;
    // Calculate the gyro value into actual degrees per second
    // get actual gyro value, this depends on scale being set
    LSM9DS1.gyroX = ( float )tmpCount[0] * LSM9DS1.gyroRes - LSM9DS1.gyroBias[0];
    LSM9DS1.gyroY = ( float )tmpCount[1] * LSM9DS1.gyroRes - LSM9DS1.gyroBias[1];
    LSM9DS1.gyroZ = ( float )tmpCount[2] * LSM9DS1.gyroRes - LSM9DS1.gyroBias[2];
}


void LSM9DS1_ReadMagData()
{
    // Read the six raw data registers sequentially into data array
    dof9_i2c_hal_read( MAG, LSM9DS1M_OUT_X_L_M, 6, &rawdata );
    // Turn the MSB and LSB into a signed 16-bit value
    // Data stored as little Endian
    tmpCount[0] = ( ( int )rawData[1] << 8 ) | rawData[0] ;
    tmpCount[1] = ( ( int )rawData[3] << 8 ) | rawData[2] ;
    tmpCount[2] = ( ( int )rawData[5] << 8 ) | rawData[4] ;
    // Calculate the magnetometer values in milliGauss
    // Include factory calibration per data sheet and user environmental corrections
    // get actual magnetometer value, this depends on scale being set
    LSM9DS1.magX = ( float )tmpCount[0] * LSM9DS1.magRes; // - magBias[0];
    LSM9DS1.magY = ( float )tmpCount[1] * LSM9DS1.magRes; // - magBias[1];
    LSM9DS1.magZ = ( float )tmpCount[2] * LSM9DS1.magRes; // - magBias[2];
}

//Internal temperature for compensation
void LSM9DS1_ReadTemperatureData()
{
    int temp;
    // Read the two raw data registers sequentially into data array
    dof9_i2c_hal_read( GYRO, LSM9DS1XG_OUT_TEMP_L, 2, &rawdata );
    // Turn the MSB and LSB into a 16-bit signed value
    temp = ( ( ( int )rawData[1] << 8 ) | rawData[0] );
    // Gyro chip temperature in degrees Celsius
    LSM9DS1.temperature = ( ( float ) temp / 256. + 25.0 );
}

//------------------------------------------------------------------------------
// Function which accumulates gyro and accelerometer data after device
// initialization. It calculates the average of the at-rest readings and then
// loads the resulting offsets into accelerometer and gyro bias registers.
//------------------------------------------------------------------------------
void LSM9DS1_CalibrateXG()
{
    long gyro_bias[3] = {0, 0, 0};
    long accel_bias[3] = {0, 0, 0};
    unsigned int samples, cnt;
    uint8_t tmp;
    //uint8_t tmp[1];
    int gyro_temp[3] = {0, 0, 0};
    int accel_temp[3] = {0, 0, 0};

    // enable the 3-axes of the gyroscope
    tmp = 0x38;
    dof9_i2c_hal_write( GYRO, LSM9DS1XG_CTRL_REG4, 1, &tmp );
    // configure the gyroscope
    tmp = LSM9DS1.gyroOdr << 5 | LSM9DS1.gyroScale << 3 | LSM9DS1.gyroAbw;
    dof9_i2c_hal_write( GYRO, LSM9DS1XG_CTRL_REG1_G, 1, &tmp );
    delay_ms( 200 );
    // enable the three axes of the accelerometer
    tmp = 0x38;
    dof9_i2c_hal_write( GYRO, LSM9DS1XG_CTRL_REG5_XL, 1, &tmp );
    // configure the accelerometer-specify bandwidth selection with Abw
    tmp = LSM9DS1.accelOdr << 5 | LSM9DS1.accelScale << 3 | 0x04 |
          LSM9DS1.accelAbw;
    dof9_i2c_hal_write( GYRO, LSM9DS1XG_CTRL_REG6_XL, 1, &tmp );
    delay_ms( 200 );
    // enable block data update, allow auto-increment during multiple byte read
    tmp = 0x44;
    dof9_i2c_hal_write( GYRO, LSM9DS1XG_CTRL_REG8, 1, &tmp );

    // First get gyro bias
    dof9_i2c_hal_read( GYRO, LSM9DS1XG_CTRL_REG9, 1, &tmp );
    // Enable gyro FIFO
    tmp |= 0x02;
    dof9_i2c_hal_write( GYRO, LSM9DS1XG_CTRL_REG9, 1, &tmp );
    delay_ms( 50 );
    // Wait for change to take effect
    tmp = 0x20 | 0x1F;
    dof9_i2c_hal_write( GYRO, LSM9DS1XG_FIFO_CTRL, 1,
                        &tmp ); // Enable gyro FIFO stream mode and set watermark at 32 samples
    delay_ms( 1000 ); // delay 1000 milliseconds to collect FIFO samples
    dof9_i2c_hal_read( GYRO, LSM9DS1XG_FIFO_SRC, 1, &tmp );
    samples = tmp & 0x2F; // Read number of stored samples

    for( cnt = 0; cnt < samples ; cnt++ )
    {
        // Read the gyro data stored in the FIFO
        dof9_i2c_hal_read( GYRO, LSM9DS1XG_OUT_X_L_G, 6, &rawdata );
        gyro_temp[0] = ( int ) ( ( ( int )rawdata[1] << 8 ) |
                                 rawdata[0] ); // Form signed 16-bit integer for each sample in FIFO
        gyro_temp[1] = ( int ) ( ( ( int )rawdata[3] << 8 ) | rawdata[2] );
        gyro_temp[2] = ( int ) ( ( ( int )rawdata[5] << 8 ) | rawdata[4] );

        gyro_bias[0] += ( long )
                        gyro_temp[0]; // Sum individual signed 16-bit biases to get accumulated signed 32-bit biases
        gyro_bias[1] += ( long ) gyro_temp[1];
        gyro_bias[2] += ( long ) gyro_temp[2];
    }

    gyro_bias[0] /= samples; // average the data
    gyro_bias[1] /= samples;
    gyro_bias[2] /= samples;

    LSM9DS1.gyroBias[0] = ( float )gyro_bias[0] *
                          LSM9DS1.gyroRes; // Properly scale the data to get deg/s
    LSM9DS1.gyroBias[1] = ( float )gyro_bias[1] * LSM9DS1.gyroRes;
    LSM9DS1.gyroBias[2] = ( float )gyro_bias[2] * LSM9DS1.gyroRes;

    dof9_i2c_hal_read( GYRO, LSM9DS1XG_CTRL_REG9, 1, &tmp );
    tmp &= ~0x02;
    dof9_i2c_hal_write( GYRO, LSM9DS1XG_CTRL_REG9, 1, &tmp );  //Disable gyro FIFO
    delay_us( 50 );
    tmp = 0x00;
    dof9_i2c_hal_write( GYRO, LSM9DS1XG_FIFO_CTRL, 1,
                        &tmp ); // Enable gyro bypass mode

    // now get the accelerometer bias
    dof9_i2c_hal_read( GYRO, LSM9DS1XG_CTRL_REG9, 1, &tmp );
    tmp |= 0x02;
    dof9_i2c_hal_write( GYRO, LSM9DS1XG_CTRL_REG9, 1,
                        &tmp );    // Enable accel FIFO
    delay_us( 50 );                                                     // Wait for change to take effect
    tmp = 0x20 | 0x1F;
    dof9_i2c_hal_write( GYRO, LSM9DS1XG_FIFO_CTRL, 1,
                        &tmp ); // Enable accel FIFO stream mode and set watermark at 32 samples
    delay_ms( 1000 ); // delay 1000 milliseconds to collect FIFO samples
    dof9_i2c_hal_read( GYRO, LSM9DS1XG_FIFO_SRC, 1, &tmp );
    samples = tmp & 0x2F; // Read number of stored samples

    for( cnt = 0; cnt < samples ; cnt++ )
    {
        // Read the accel data stored in the FIFO
        dof9_i2c_hal_read( GYRO, LSM9DS1XG_OUT_X_L_XL, 6, &rawdata );
        accel_temp[0] = ( int ) ( ( ( int )rawdata[1] << 8 ) |
                                  rawdata[0] ); // Form signed 16-bit integer for each sample in FIFO
        accel_temp[1] = ( int ) ( ( ( int )rawdata[3] << 8 ) | rawdata[2] );
        accel_temp[2] = ( int ) ( ( ( int )rawdata[5] << 8 ) | rawdata[4] );

        accel_bias[0] += ( long )
                         accel_temp[0]; // Sum individual signed 16-bit biases to get accumulated signed 32-bit biases
        accel_bias[1] += ( long ) accel_temp[1];
        accel_bias[2] += ( long ) accel_temp[2];
    }

    accel_bias[0] /= samples; // average the data
    accel_bias[1] /= samples;
    accel_bias[2] /= samples;

    if( accel_bias[2] > 0L )
    {
        accel_bias[2] -= ( long ) ( 1.0 /
                                    LSM9DS1.accelRes );                                       // Remove gravity from the z-axis accelerometer bias calculation
    }
    else
        accel_bias[2] += ( long ) ( 1.0 / LSM9DS1.accelRes );

    LSM9DS1.accelBias[0] = ( float )accel_bias[0] *
                           LSM9DS1.accelRes; // Properly scale the data to get g
    LSM9DS1.accelBias[1] = ( float )accel_bias[1] * LSM9DS1.accelRes;
    LSM9DS1.accelBias[2] = ( float )accel_bias[2] * LSM9DS1.accelRes;

    dof9_i2c_hal_read( GYRO, LSM9DS1XG_CTRL_REG9, 1, &tmp );
    tmp &= ~0x02;
    dof9_i2c_hal_write( GYRO, LSM9DS1XG_CTRL_REG9, 1,
                        &tmp );  //Disable accel FIFO
    delay_ms( 50 );
    tmp = 0x00;
    dof9_i2c_hal_write( GYRO, LSM9DS1XG_FIFO_CTRL, 1,
                        &tmp ); // Enable accel bypass mode
}


void LSM9DS1_CalibrateMag()
{

    char cnt1, cnt2, samples;
    long mag_bias[3] = {0, 0, 0};
    int mag_max[3] = {0, 0, 0};
    int mag_min[3] = {0, 0, 0};
    int mag_temp[3] = {0, 0, 0};
    uint8_t tmp;

    // configure the magnetometer-enable temperature compensation of mag data
    tmp = 0x80 | LSM9DS1.magMode << 5 | LSM9DS1.magOdr << 2;
    dof9_i2c_hal_write( MAG, LSM9DS1M_CTRL_REG1_M, 1,
                        &tmp ); // select x,y-axis mode
    tmp = LSM9DS1.magScale << 5;
    dof9_i2c_hal_write( MAG, LSM9DS1M_CTRL_REG2_M, 1,
                        &tmp ); // select mag full scale
    tmp = 0x00;
    dof9_i2c_hal_write( MAG, LSM9DS1M_CTRL_REG3_M, 1,
                        &tmp ); // continuous conversion mode
    tmp = LSM9DS1.magMode << 2;
    dof9_i2c_hal_write( MAG, LSM9DS1M_CTRL_REG4_M, 1,
                        &tmp ); // select z-axis mode
    tmp = 0x40;
    dof9_i2c_hal_write( MAG, LSM9DS1M_CTRL_REG5_M, 1,
                        &tmp ); // select block update mode

    samples = SAMPLES_CALIBRATION; // User defined

    for( cnt1 = 0; cnt1 < samples; cnt1++ )
    {
        dof9_i2c_hal_read( MAG, LSM9DS1M_OUT_X_L_M, 6,
                           &rawdata ); // Read the six raw data registers into data array
        mag_temp[0] = ( int ) ( ( ( int )rawdata[1] << 8 ) | rawdata[0] )
                      ; // Form signed 16-bit integer for each sample in FIFO
        mag_temp[1] = ( int ) ( ( ( int )rawdata[3] << 8 ) | rawdata[2] ) ;
        mag_temp[2] = ( int ) ( ( ( int )rawdata[5] << 8 ) | rawdata[4] ) ;
        for ( cnt2 = 0; cnt2 < 3; cnt2++ )
        {
            if( mag_temp[cnt2] > mag_max[cnt2] )
                mag_max[cnt2] = mag_temp[cnt2];
            if( mag_temp[cnt2] < mag_min[cnt2] )
                mag_min[cnt2] = mag_temp[cnt2];
        }
        delay_ms( 110 ); // at 10 Hz ODR, new mag data is available every 100 ms
    }


    mag_bias[0]  = ( mag_max[0] + mag_min[0] ) /
                   2; // get average x mag bias in counts
    mag_bias[1]  = ( mag_max[1] + mag_min[1] ) /
                   2; // get average y mag bias in counts
    mag_bias[2]  = ( mag_max[2] + mag_min[2] ) /
                   2; // get average z mag bias in counts

    LSM9DS1.magBias[0] = ( float ) mag_bias[0] *
                         LSM9DS1.magRes; // save mag biases in G for main program
    LSM9DS1.magBias[1] = ( float ) mag_bias[1] * LSM9DS1.magRes;
    LSM9DS1.magBias[2] = ( float ) mag_bias[2] * LSM9DS1.magRes;

    //write biases to accelerometermagnetometer offset registers as counts);
    tmp = mag_bias[0] & 0xFF;
    dof9_i2c_hal_write( MAG, LSM9DS1M_OFFSET_X_REG_L_M, 1, &tmp );
    tmp = ( mag_bias[0] >> 8 ) & 0xFF;
    dof9_i2c_hal_write( MAG, LSM9DS1M_OFFSET_X_REG_H_M, 1, &tmp );
    tmp = mag_bias[1] & 0xFF;
    dof9_i2c_hal_write( MAG, LSM9DS1M_OFFSET_Y_REG_L_M, 1, &tmp );
    tmp = ( mag_bias[1] >> 8 ) & 0xFF;
    dof9_i2c_hal_write( MAG, LSM9DS1M_OFFSET_Y_REG_H_M, 1, &tmp );
    tmp = mag_bias[2] & 0xFF;
    dof9_i2c_hal_write( MAG, LSM9DS1M_OFFSET_Z_REG_L_M, 1, &tmp );
    tmp = ( mag_bias[2] >> 8 ) & 0xFF;
    dof9_i2c_hal_write( MAG, LSM9DS1M_OFFSET_Z_REG_H_M, 1, &tmp );

}

//------------------------------------------------------------------------------
void LSM9DS1_Init()
{
    uint8_t tmp;

    LSM9DS1.accelX = 0;
    LSM9DS1.accelY = 0;
    LSM9DS1.accelZ = 0;
    LSM9DS1.magX = 0;
    LSM9DS1.magY = 0;
    LSM9DS1.magZ = 0;
    LSM9DS1.gyroX = 0;
    LSM9DS1.gyroY = 0;
    LSM9DS1.gyroZ = 0;
    LSM9DS1.temperature = 0;
    LSM9DS1.OSR = ADC_4096;      // set pressure amd temperature oversample rate
    LSM9DS1.gyroScale = GFS_245DPS; // gyro full scale
    LSM9DS1.gyroOdr =  GODR_238Hz;   // gyro data sample rate
    LSM9DS1.gyroAbw = GBW_med;       // gyro data bandwidth
    LSM9DS1.accelScale = AFS_2G;     // accel full scale
    LSM9DS1.accelOdr = AODR_238Hz;   // accel data sample rate
    LSM9DS1.accelAbw = ABW_50Hz;      // accel data bandwidth
    LSM9DS1.magScale = MFS_4G;     // mag full scale
    LSM9DS1.magOdr = MODR_10Hz;    // mag data sample rate
    LSM9DS1.magMode = MMode_HighPerformance;  // magnetometer operation mode
    LSM9DS1_SetMagRes();
    LSM9DS1_SetGyroRes();
    LSM9DS1_SetAccelRes();
    // enable the 3-axes of the gyroscope
    tmp = 0x38;
    dof9_i2c_hal_write( GYRO, LSM9DS1XG_CTRL_REG4, 1, &tmp );
    // configure the gyroscope
    tmp = LSM9DS1.gyroOdr << 5 | LSM9DS1.gyroScale << 3 | LSM9DS1.gyroAbw;
    dof9_i2c_hal_write( GYRO, LSM9DS1XG_CTRL_REG1_G, 1, &tmp );
    delay_ms( 200 );
    // enable the three axes of the accelerometer
    tmp = 0x38;
    dof9_i2c_hal_write( GYRO, LSM9DS1XG_CTRL_REG5_XL, 1, &tmp );
    // configure the accelerometer-specify bandwidth selection with Abw
    tmp = LSM9DS1.accelOdr << 5 | LSM9DS1.accelScale << 3 | 0x04 |
          LSM9DS1.accelAbw;
    dof9_i2c_hal_write( GYRO, LSM9DS1XG_CTRL_REG6_XL, 1, &tmp );
    delay_ms( 200 );
    // enable block data update, allow auto-increment during multiple byte read
    tmp = 0x44;
    dof9_i2c_hal_write( GYRO, LSM9DS1XG_CTRL_REG8, 1, &tmp );
    // configure the magnetometer-enable temperature compensation of mag data
    // select x,y-axis mode
    tmp = 0x80 | LSM9DS1.magMode << 5 | LSM9DS1.magOdr << 2;
    dof9_i2c_hal_write( MAG, LSM9DS1M_CTRL_REG1_M, 1, &tmp );
    // select mag full scale
    tmp = LSM9DS1.magScale << 5;
    dof9_i2c_hal_write( MAG, LSM9DS1M_CTRL_REG2_M, 1, &tmp );
    // continuous conversion mode;
    tmp = 0x00;
    dof9_i2c_hal_write( MAG, LSM9DS1M_CTRL_REG3_M, 1, &tmp );
    // select z-axis mode
    tmp = LSM9DS1.magMode << 2;
    dof9_i2c_hal_write( MAG, LSM9DS1M_CTRL_REG4_M, 1, &tmp );
    // select block update mode
    tmp = 0x40;
    dof9_i2c_hal_write( MAG, LSM9DS1M_CTRL_REG5_M, 1, &tmp );
}

char LSM9DS1_AccelDataReady()
{
    char cfg;
    dof9_i2c_hal_read( GYRO, LSM9DS1XG_STATUS_REG, 1, &cfg );
    return ( cfg & 0x01 );
}

char LSM9DS1_GyroDataReady()
{
    char cfg;
    dof9_i2c_hal_read( GYRO, LSM9DS1XG_STATUS_REG, 1, &cfg );
    return ( cfg & 0x02 );
}

char LSM9DS1_MagDataReady()
{
    char cfg;
    dof9_i2c_hal_read( MAG, LSM9DS1M_STATUS_REG_M, 1, &cfg );
    return ( cfg & 0x08 );
}

/*************** END OF FUNCTIONS ***************************************************************************/