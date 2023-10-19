/*******************************************************************************
    arducam Header File

  Company:
    Microchip Technology Inc.

  File Name:
    arducam.h

  Summary:

  Description:

 *******************************************************************************/
// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
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
// DOM-IGNORE-END

/*!
 * \file
 *
 */

#ifndef ARDUCAM_H
#define ARDUCAM_H


#ifdef  __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#define ARDUCHIP_FRAMES                             0x01
#define ARDUCHIP_TEST1                              0x00  //TEST register
#define ARDUCHIP_FIFO                               0x04  //FIFO and I2C control
#define ARDUCHIP_FIFO_2                             0x07  // FIFO and I2C control

#define FIFO_START_MASK                             0x02
#define FIFO_RDPTR_RST_MASK                         0x10
#define FIFO_WRPTR_RST_MASK                         0x20
#define FIFO_CLEAR_MASK                             0x01


#define ARDUCHIP_TRIG                               0x44  //Trigger source
#define VSYNC_MASK                                  0x01
#define SHUTTER_MASK                                0x02
#define CAP_DONE_MASK                               0x04


#define FIFO_SIZE1                                  0x45  //Camera write FIFO size[7:0] for burst to read
#define FIFO_SIZE2                                  0x46  //Camera write FIFO size[15:8]
#define FIFO_SIZE3                                  0x47  //Camera write FIFO size[18:16]


#define BURST_FIFO_READ                             0x3C  //Burst FIFO read operation
#define SINGLE_FIFO_READ                            0x3D  //Single FIFO read operation


#define CAPTURE_MAX_NUM                             0xFF

#define CAM_REG_POWER_CONTROL                       0x02
#define CAM_REG_SENSOR_RESET                        0x07
#define CAM_REG_FORMAT                              0x20
#define CAM_REG_CAPTURE_RESOLUTION                  0x21
#define CAM_REG_BRIGHTNESS_CONTROL                  0x22
#define CAM_REG_CONTRAST_CONTROL                    0x23
#define CAM_REG_SATURATION_CONTROL                  0x24
#define CAM_REG_EV_CONTROL                          0x25
#define CAM_REG_WHILEBALANCE_MODE_CONTROL           0x26
#define CAM_REG_COLOR_EFFECT_CONTROL                0x27
#define CAM_REG_SHARPNESS_CONTROL                   0x28
#define CAM_REG_AUTO_FOCUS_CONTROL                  0x29
#define CAM_REG_IMAGE_QUALITY                       0x2A
#define CAM_REG_EXPOSURE_GAIN_WHILEBALANCE_CONTROL  0x30
#define CAM_REG_MANUAL_GAIN_BIT_9_8                 0x31
#define CAM_REG_MANUAL_GAIN_BIT_7_0                 0x32
#define CAM_REG_MANUAL_EXPOSURE_BIT_19_16           0x33
#define CAM_REG_MANUAL_EXPOSURE_BIT_15_8            0x34
#define CAM_REG_MANUAL_EXPOSURE_BIT_7_0             0x35
#define CAM_REG_BURST_FIFO_READ_OPERATION           0x3C
#define CAM_REG_SINGLE_FIFO_READ_OPERATION          0x3D
#define CAM_REG_SENSOR_ID                           0x40
#define CAM_REG_YEAR_ID                             0x41
#define CAM_REG_MONTH_ID                            0x42
#define CAM_REG_DAY_ID                              0x43
#define CAM_REG_SENSOR_STATE                        0x44
#define CAM_REG_FPGA_VERSION_NUMBER                 0x49
#define CAM_REG_DEBUG_DEVICE_ADDRESS                0x0A
#define CAM_REG_DEBUG_REGISTER_HIGH                 0x0B
#define CAM_REG_DEBUG_REGISTER_LOW                  0x0C
#define CAM_REG_DEBUG_REGISTER_VALUE                0x0D


#define CAM_REG_SENSOR_STATE_IDLE                   (1 << 1)
#define CAM_SENSOR_RESET_ENABLE                     (1 << 6)
#define CAM_FORMAT_BASICS                           (0 << 0)
#define CAM_SET_CAPTURE_MODE                        (0 << 7)
#define CAM_SET_VIDEO_MODE                          (1 << 7)

#define SET_WHILEBALANCE                            0x02
#define SET_EXPOSURE                                0x01
#define SET_GAIN                                    0x00

#define FORMAT_JPEG                                 0x01
#define FORMAT_RGB                                  0x02
#define FORMAT_YUV                                  0x03




#define RESOLUTION_160x120                          (1 << 0)
#define RESOLUTION_320x240                          (1 << 1)
#define RESOLUTION_640x480                          (1 << 2)
#define RESOLUTION_800x600                          (1 << 3)
#define RESOLUTION_1280x720                         (1 << 4)
#define RESOLUTION_1280x960                         (1 << 5)
#define RESOLUTION_1600x1200                        (1 << 6)
#define RESOLUTION_1920x1080                        (1 << 7)
#define RESOLUTION_2048X1536                        (1 << 8)
#define RESOLUTION_2592X1944                        (1 << 9)

#define SPECIAL_NORMAL                              (0 << 0)
#define SPECIAL_BLUEISH                             (1 << 0)
#define SPECIAL_REDISH                              (1 << 1)
#define SPECIAL_BW                                  (1 << 2)
#define SPECIAL_SEPIA                               (1 << 3)
#define SPECIAL_NEGATIVE                            (1 << 4)
#define SPECIAL_GREENISH                            (1 << 5)
#define SPECIAL_OVEREXPOSURE                        (1 << 6)
#define SPECIAL_SOLARIZE                            (1 << 7)
#define SPECIAL_YELLOWISH                           (1 << 8)


#define RESET_CAMERA                                0xFF

#define SET_PICTURE_RESOLUTION                      0x01
#define SET_PICTURE_FORMAT                          0x02
#define SET_BRIGHTNESS                              0x03
#define SET_CONTRAST                                0x04
#define SET_SATURATION                              0x05
#define SET_EV                                      0x06
#define SET_WHITEBALANCE                            0x07
#define SET_SPECIAL_EFFECTS                         0x08
#define SET_FOCUS_CONTROL                           0x09
#define SET_EXPOSUREANDGAIN_CONTROL                 0x0A
#define SET_SHARPNESS                               0x0B
#define SET_WHILEBALANCE_CONTROL                    0x0C
#define SET_MANUAL_GAIN                             0x0D
#define SET_MANUAL_EXPOSURE                         0x0E
#define GET_CAMERA_INFO                             0x0F
#define TAKE_PICTURE                                0x10
#define DEBUG_WRITE_REGISTER                        0x12
#define STOP_STREAM                                 0x21
#define GET_FRM_VER_INFO                            0x30
#define GET_SDK_VER_INFO                            0x40
#define SET_IMAGE_QUALITY                           0x50

#define CAMERA_DEVICE_ADDRESS                       0x78
#define MEGA_5MP_ID                                 0x81
#define MEGA_3MP_ID                                 0x82



/**
  * @enum CAM_IMAGE_MODE
  * @brief Configure camera resolution
  */
typedef enum
{
    CAM_IMAGE_MODE_QQVGA    = 0x00,     /**<160x120 */
    CAM_IMAGE_MODE_QVGA     = 0x01,     /**<320x240*/
    CAM_IMAGE_MODE_VGA      = 0x02,     /**<640x480*/
    CAM_IMAGE_MODE_SVGA     = 0x03,     /**<800x600*/
    CAM_IMAGE_MODE_HD       = 0x04,     /**<1280x720*/
    CAM_IMAGE_MODE_SXGAM    = 0x05,     /**<1280x960*/
    CAM_IMAGE_MODE_UXGA     = 0x06,     /**<1600x1200*/
    CAM_IMAGE_MODE_FHD      = 0x07,     /**<1920x1080*/
    CAM_IMAGE_MODE_QXGA     = 0x08,     /**<2048x1536*/
    CAM_IMAGE_MODE_WQXGA2   = 0x09,     /**<2592x1944*/
    /// @cond
    CAM_IMAGE_MODE_12       = 0x0d,     /**<Reserve*/
    CAM_IMAGE_MODE_13       = 0x0e,     /**<Reserve*/
    CAM_IMAGE_MODE_14       = 0x0f,     /**<Reserve*/
    CAM_IMAGE_MODE_15       = 0x10,     /**<Reserve*/
    CAM_IMAGE_MODE_NONE,

}CAM_IMAGE_MODE;


/**
  * @enum CAM_CONTRAST_LEVEL
  * @brief Configure camera contrast level
  */
typedef enum
{
    CAM_CONTRAST_LEVEL_MINUS_3  = 6, /**<Level -3 */
    CAM_CONTRAST_LEVEL_MINUS_2  = 4, /**<Level -2 */
    CAM_CONTRAST_LEVEL_MINUS_1  = 2, /**<Level -1 */
    CAM_CONTRAST_LEVEL_DEFAULT  = 0, /**<Level Default*/
    CAM_CONTRAST_LEVEL_1        = 1, /**<Level +1 */
    CAM_CONTRAST_LEVEL_2        = 3, /**<Level +2 */
    CAM_CONTRAST_LEVEL_3        = 5, /**<Level +3 */

}CAM_CONTRAST_LEVEL;

/**
  * @enum CAM_EV_LEVEL
  * @brief Configure camera EV level
  */
typedef enum
{
    CAM_EV_LEVEL_MINUS_3        = 6, /**<Level -3 */
    CAM_EV_LEVEL_MINUS_2        = 4, /**<Level -2 */
    CAM_EV_LEVEL_MINUS_1        = 2, /**<Level -1 */
    CAM_EV_LEVEL_DEFAULT        = 0, /**<Level Default*/
    CAM_EV_LEVEL_1              = 1, /**<Level +1 */
    CAM_EV_LEVEL_2              = 3, /**<Level +2 */
    CAM_EV_LEVEL_3              = 5, /**<Level +3 */

}CAM_EV_LEVEL;


/**
  * @enum CAM_SATURATION_LEVEL
  * @brief Configure camera saturation  level
  */
typedef enum
{
    CAM_SATURATION_LEVEL_MINUS_3= 6, /**<Level -3 */
    CAM_SATURATION_LEVEL_MINUS_2= 4, /**<Level -2 */
    CAM_SATURATION_LEVEL_MINUS_1= 2, /**<Level -1 */
    CAM_SATURATION_LEVEL_DEFAULT= 0, /**<Level Default*/
    CAM_SATURATION_LEVEL_1      = 1, /**<Level +1 */
    CAM_SATURATION_LEVEL_2      = 3, /**<Level +2 */
    CAM_SATURATION_LEVEL_3      = 5, /**<Level +3 */

}CAM_SATURATION_LEVEL;

/**
  * @enum CAM_BRIGHTNESS_LEVEL
  * @brief Configure camera brightness level
  */
typedef enum
{
    CAM_BRIGHTNESS_LEVEL_MINUS_4= 8, /**<Level -4 */
    CAM_BRIGHTNESS_LEVEL_MINUS_3= 6, /**<Level -3 */
    CAM_BRIGHTNESS_LEVEL_MINUS_2= 4, /**<Level -2 */
    CAM_BRIGHTNESS_LEVEL_MINUS_1= 2, /**<Level -1 */
    CAM_BRIGHTNESS_LEVEL_DEFAULT= 0, /**<Level Default*/
    CAM_BRIGHTNESS_LEVEL_1      = 1, /**<Level +1 */
    CAM_BRIGHTNESS_LEVEL_2      = 3, /**<Level +2 */
    CAM_BRIGHTNESS_LEVEL_3      = 5, /**<Level +3 */
    CAM_BRIGHTNESS_LEVEL_4      = 7, /**<Level +4 */

}CAM_BRIGHTNESS_LEVEL;


/**
  * @enum CAM_SHARPNESS_LEVEL
  * @brief Configure camera Sharpness level
  */
typedef enum
{
    CAM_SHARPNESS_LEVEL_AUTO    = 0,/**<Sharpness Auto */
    CAM_SHARPNESS_LEVEL_1,          /**<Sharpness Level 1 */
    CAM_SHARPNESS_LEVEL_2,          /**<Sharpness Level 2 */
    CAM_SHARPNESS_LEVEL_3,          /**<Sharpness Level 3 */
    CAM_SHARPNESS_LEVEL_4,          /**<Sharpness Level 4 */
    CAM_SHARPNESS_LEVEL_5,          /**<Sharpness Level 5 */
    CAM_SHARPNESS_LEVEL_6,          /**<Sharpness Level 6 */
    CAM_SHARPNESS_LEVEL_7,          /**<Sharpness Level 7 */
    CAM_SHARPNESS_LEVEL_8,          /**<Sharpness Level 8 */

}CAM_SHARPNESS_LEVEL;


/**
  * @enum CAM_VIDEO_MODE
  * @brief Configure resolution in video streaming mode
  */
typedef enum
{
    CAM_VIDEO_MODE_0            = 1, /**< 320x240 */
    CAM_VIDEO_MODE_1            = 2, /**< 640x480 */

}CAM_VIDEO_MODE;


/**
  * @enum CAM_IMAGE_PIX_FMT
  * @brief Configure image pixel format
  */
typedef enum
{
    CAM_IMAGE_PIX_FMT_RGB565    = 0x02, /**< RGB565 format */
    CAM_IMAGE_PIX_FMT_JPG       = 0x01, /**< JPEG format */
    CAM_IMAGE_PIX_FMT_YUV       = 0x03, /**< YUV format */
    CAM_IMAGE_PIX_FMT_NONE,             /**< No defined format */

}CAM_IMAGE_PIX_FMT;


/**
  * @enum CAM_WHITE_BALANCE
  * @brief Configure white balance mode
  */
typedef enum
{
    CAM_WHITE_BALANCE_MODE_DEFAULT  = 0,/**< Auto */
    CAM_WHITE_BALANCE_MODE_SUNNY,       /**< Sunny */
    CAM_WHITE_BALANCE_MODE_OFFICE,      /**< Office */
    CAM_WHITE_BALANCE_MODE_CLOUDY,      /**< Cloudy*/
    CAM_WHITE_BALANCE_MODE_HOME,        /**< Home */

}CAM_WHITE_BALANCE;


/**
  * @enum CAM_COLOR_FX
  * @brief Configure special effects
  */
typedef enum  {
    CAM_COLOR_FX_NONE               = 0,/**< no effect   */
    CAM_COLOR_FX_BLUEISH,               /**< cool light   */
    CAM_COLOR_FX_REDISH,                /**< warm   */
    CAM_COLOR_FX_BW,                    /**< Black/white   */
    CAM_COLOR_FX_SEPIA,                 /**<Sepia   */
    CAM_COLOR_FX_NEGATIVE,              /**<positive/negative inversion  */
    CAM_COLOR_FX_GRASS_GREEN,           /**<Grass green */
    CAM_COLOR_FX_OVER_EXPOSURE,         /**<Over exposure*/
    CAM_COLOR_FX_SOLARIZE,              /**< Solarize   */

}CAM_COLOR_FX;


#ifdef  __cplusplus
}
#endif

#endif  /* ARDUCAM_H */

