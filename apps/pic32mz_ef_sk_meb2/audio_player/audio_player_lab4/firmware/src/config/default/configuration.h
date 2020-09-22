/*******************************************************************************
  System Configuration Header

  File Name:
    configuration.h

  Summary:
    Build-time configuration header for the system defined by this project.

  Description:
    An MPLAB Project may have multiple configurations.  This file defines the
    build-time options for a single configuration.

  Remarks:
    This configuration header must not define any prototypes or data
    definitions (or include any files that do).  It only provides macro
    definitions for build-time configuration options

*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/*  This section Includes other configuration headers necessary to completely
    define this configuration.
*/

#include "user.h"
#include "toolchain_specifics.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: System Configuration
// *****************************************************************************
// *****************************************************************************



// *****************************************************************************
// *****************************************************************************
// Section: System Service Configuration
// *****************************************************************************
// *****************************************************************************
/* TIME System Service Configuration Options */
#define SYS_TIME_INDEX_0                            (0)
#define SYS_TIME_MAX_TIMERS                         (5)
#define SYS_TIME_HW_COUNTER_WIDTH                   (32)
#define SYS_TIME_HW_COUNTER_PERIOD                  (4294967295U)
#define SYS_TIME_HW_COUNTER_HALF_PERIOD             (SYS_TIME_HW_COUNTER_PERIOD>>1)
#define SYS_TIME_CPU_CLOCK_FREQUENCY                (198000000)
#define SYS_TIME_COMPARE_UPDATE_EXECUTION_CYCLES    (620)


/* File System Service Configuration */

#define SYS_FS_MEDIA_NUMBER               1
#define SYS_FS_VOLUME_NUMBER              1

#define SYS_FS_AUTOMOUNT_ENABLE           false
#define SYS_FS_MAX_FILES                  2
#define SYS_FS_MAX_FILE_SYSTEM_TYPE       1
#define SYS_FS_MEDIA_MAX_BLOCK_SIZE       512
#define SYS_FS_MEDIA_MANAGER_BUFFER_SIZE  2048
#define SYS_FS_USE_LFN                    1
#define SYS_FS_FILE_NAME_LEN              255
#define SYS_FS_CWD_STRING_LEN             1024


#define SYS_FS_FAT_VERSION                "v0.14"
#define SYS_FS_FAT_READONLY               false
#define SYS_FS_FAT_CODE_PAGE              437
#define SYS_FS_FAT_MAX_SS                 SYS_FS_MEDIA_MAX_BLOCK_SIZE
#define SYS_FS_FAT_ALIGNED_BUFFER_LEN     512






// *****************************************************************************
// *****************************************************************************
// Section: Driver Configuration
// *****************************************************************************
// *****************************************************************************
/* SDSPI Driver Instance 0 Configuration Options */
#define DRV_SDSPI_INDEX_0                       0
#define DRV_SDSPI_CLIENTS_NUMBER_IDX0           2
#define DRV_SDSPI_QUEUE_SIZE_IDX0               10
#define DRV_SDSPI_CHIP_SELECT_PIN_IDX0          SYS_PORT_PIN_RB14
#define DRV_SDSPI_SPEED_HZ_IDX0                 20000000
#define DRV_SDSPI_POLLING_INTERVAL_MS_IDX0      1000




/* I2C Driver Instance 0 Configuration Options */
#define DRV_I2C_INDEX_0                       0
#define DRV_I2C_CLIENTS_NUMBER_IDX0           1
#define DRV_I2C_QUEUE_SIZE_IDX0               2
#define DRV_I2C_CLOCK_SPEED_IDX0              50000

/* I2S Driver Instance 0 Configuration Options */
#define DRV_I2S_INDEX_0                       0
#define DRV_I2S_CLIENTS_NUMBER_IDX0           1
#define DRV_I2S_QUEUE_DEPTH_COMBINED          8
#define DRV_I2S_QUEUE_SIZE_IDX0               8
#define DRV_I2S_DATA_LENGTH_IDX0              16
#define DRV_I2S_INT_SRC_IDX0                  _DMA0_VECTOR
#define DRV_I2S_XMIT_DMA_CH_IDX0              SYS_DMA_CHANNEL_0
#define DRV_I2S_RCV_DMA_CH_IDX0               SYS_DMA_CHANNEL_1


/* SDSPI Driver Common Configuration Options */
#define DRV_SDSPI_INSTANCES_NUMBER              1

/* I2C Driver Common Configuration Options */
#define DRV_I2C_INSTANCES_NUMBER              1


/*** Codec Driver Configuration ***/

#define DRV_AK4953_CLIENTS_NUMBER                           1
#define DRV_AK4953_INSTANCES_NUMBER                         1

#define DRV_AK4953_MASTER_MODE                              false
#define DRV_AK4953_AUDIO_SAMPLING_RATE                      48000
#define DRV_AK4953_VOLUME	                      	        200
#define DRV_AK4953_AUDIO_DATA_FORMAT_MACRO             	    DRV_AK4953_AUDIO_DATA_FORMAT_I2S_16BIT_24BIT
#define DRV_AK4953_WHICH_MIC_INPUT                          MIC1
#define DRV_AK4953_ENABLE_MIC_BIAS                          true
#define DRV_AK4953_MIC_GAIN	                      	        20
#define DRV_AK4953_MCLK_SAMPLE_FREQ_MULTPLIER               256
#define DRV_AK4953_BCLK_BIT_CLK_DIVISOR                     4
#define DRV_AK4953_DELAY_INITIALIZATION                     false

#define DRV_AK4953_I2S_DRIVER_MODULE_INDEX_IDX0             DRV_I2S_INDEX_0
#define DRV_AK4953_I2C_DRIVER_MODULE_INDEX_IDX0             DRV_I2C_INDEX_0
/* CODEC Driver Abstraction definition */

#define DRV_CODEC_INDEX_0                                   DRV_AK4953_INDEX_0
#define sysObjdrvCodec0                                     sysObj.drvak4953Codec0
#define DRV_CODEC_BUFFER_HANDLE                             DRV_AK4953_BUFFER_HANDLE
#define DRV_CODEC_BUFFER_HANDLE_INVALID                     DRV_AK4953_BUFFER_HANDLE_INVALID
#define DRV_CODEC_BUFFER_EVENT_HANDLER                      DRV_AK4953_BUFFER_EVENT_HANDLER
#define DRV_CODEC_BUFFER_EVENT                              DRV_AK4953_BUFFER_EVENT
#define DRV_CODEC_BUFFER_EVENT_COMPLETE                     DRV_AK4953_BUFFER_EVENT_COMPLETE
#define DRV_CODEC_BUFFER_EVENT_ERROR                        DRV_AK4953_BUFFER_EVENT_ERROR
#define DRV_CODEC_BUFFER_EVENT_ABORT                        DRV_AK4953_BUFFER_EVENT_ABORT
#define DRV_CODEC_COMMAND_EVENT_HANDLER                     DRV_AK4953_COMMAND_EVENT_HANDLER

#define DRV_CODEC_CHANNEL_LEFT                              DRV_AK4953_CHANNEL_LEFT
#define DRV_CODEC_CHANNEL_RIGHT                             DRV_AK4953_CHANNEL_RIGHT
#define DRV_CODEC_CHANNEL_LEFT_RIGHT                        DRV_AK4953_CHANNEL_LEFT_RIGHT

#define DRV_CODEC_Initialize                                DRV_AK4953_Initialize
#define DRV_CODEC_Deinitialize                              DRV_AK4953_Deinitialize
#define DRV_CODEC_Status                                    DRV_AK4953_Status
#define DRV_CODEC_Tasks                                     DRV_AK4953_Tasks
#define DRV_CODEC_Open                                      DRV_AK4953_Open
#define DRV_CODEC_Close                                     DRV_AK4953_Close
#define DRV_CODEC_BufferEventHandlerSet                     DRV_AK4953_BufferEventHandlerSet
#define DRV_CODEC_CommandEventHandlerSet                    DRV_AK4953_CommandEventHandlerSet
#define DRV_CODEC_BufferAddWrite                            DRV_AK4953_BufferAddWrite
#define DRV_CODEC_BufferAddRead                             DRV_AK4953_BufferAddRead
#define DRV_CODEC_BufferAddWriteRead                        DRV_AK4953_BufferAddWriteRead
#define DRV_CODEC_WriteQueuePurge                           DRV_AK4953_WriteQueuePurge
#define DRV_CODEC_ReadQueuePurge                            DRV_AK4953_ReadQueuePurge
#define DRV_CODEC_SamplingRateSet                           DRV_AK4953_SamplingRateSet
#define DRV_CODEC_SamplingRateGet                           DRV_AK4953_SamplingRateGet
#define DRV_CODEC_VolumeSet                                 DRV_AK4953_VolumeSet
#define DRV_CODEC_VolumeGet                                 DRV_AK4953_VolumeGet
#define DRV_CODEC_MuteOn                                    DRV_AK4953_MuteOn
#define DRV_CODEC_MuteOff                                   DRV_AK4953_MuteOff
#define DRV_CODEC_MicGainSet                                DRV_AK4953_MicGainSet
#define DRV_CODEC_MicGainGet                                DRV_AK4953_MicGainGet
#define DRV_CODEC_MicMuteOn                                 DRV_AK4953_MicMuteOn
#define DRV_CODEC_MicMuteOff                                DRV_AK4953_MicMuteOff
#define DRV_CODEC_GetI2SDriver                              DRV_AK4953_GetI2SDriver
#define DRV_CODEC_LRCLK_Sync                                DRV_AK4953_LRCLK_Sync 

/* I2S Driver Common Configuration Options */
#define DRV_I2S_INSTANCES_NUMBER              1



// *****************************************************************************
// *****************************************************************************
// Section: Middleware & Other Library Configuration
// *****************************************************************************
// *****************************************************************************
/* Number of Endpoints used */
#define DRV_USBHS_ENDPOINTS_NUMBER                        3

/* The USB Device Layer will not initialize the USB Driver */
#define USB_DEVICE_DRIVER_INITIALIZE_EXPLICIT

/* Maximum device layer instances */
#define USB_DEVICE_INSTANCES_NUMBER                         1

/* EP0 size in bytes */
#define USB_DEVICE_EP0_BUFFER_SIZE                          64






/*** USB Driver Configuration ***/

/* Maximum USB driver instances */
#define DRV_USBHS_INSTANCES_NUMBER                        1

/* Interrupt mode enabled */
#define DRV_USBHS_INTERRUPT_MODE                          true


/* Enables Device Support */
#define DRV_USBHS_DEVICE_SUPPORT                          true
	
/* Disable Host Support */
#define DRV_USBHS_HOST_SUPPORT                            false




/* Alignment for buffers that are submitted to USB Driver*/ 
#define USB_ALIGN  CACHE_ALIGN

/* Maximum instances of MSD function driver */
#define USB_DEVICE_MSD_INSTANCES_NUMBER     1 

#define USB_DEVICE_MSD_NUM_SECTOR_BUFFERS 1


/* Number of Logical Units */
#define USB_DEVICE_MSD_LUNS_NUMBER      1





// *****************************************************************************
// *****************************************************************************
// Section: Application Configuration
// *****************************************************************************
// *****************************************************************************


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // CONFIGURATION_H
/*******************************************************************************
 End of File
*/
