/*******************************************************************************
  User Configuration Header

  File Name:
    user.h

  Summary:
    Build-time configuration header for the user defined by this project.

  Description:
    An MPLAB Project may have multiple configurations.  This file defines the
    build-time options for a single configuration.

  Remarks:
    It only provides macro definitions for build-time configuration options

*******************************************************************************/

#ifndef USER_H
#define USER_H

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: User Configuration macros
// *****************************************************************************
//#define APP_SDCARD_AUDIO_CODEC_WRITE_QUEUE_SIZE         QUEUE_SIZE_TX_IDX0
#define APP_SDCARD_AUDIO_CARD_MAX_DIRS   20
#define APP_SDCARD_AUDIO_CARD_MAX_FILES  500
    
#define APP_AUDIO_SRC_SWITCH                            BSP_SWITCH_1    

#define APP_OFF_RGB_LED()                           RGB_LED_R_Off(); \
    RGB_LED_G_Off(); \
    RGB_LED_B_Off();
       	  
#define APP_SDCARD_AUDIO_SRC_ON()                       LED1_On()
#define APP_SDCARD_AUDIO_SRC_OFF()                      LED1_Off()
#define APP_TRACK_CHANGE_INDICATE()                     LED3_Toggle()
    
    
#define APP_SDCARD_AUDIO_CARD_MOUNT_NAME                SYS_FS_MEDIA_IDX0_MOUNT_NAME_VOLUME_IDX0
#define APP_SDCARD_AUDIO_CARD_DEVICE_NAME               SYS_FS_MEDIA_IDX0_DEVICE_NAME_VOLUME_IDX0    



//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // USER_H
/*******************************************************************************
 End of File
*/
