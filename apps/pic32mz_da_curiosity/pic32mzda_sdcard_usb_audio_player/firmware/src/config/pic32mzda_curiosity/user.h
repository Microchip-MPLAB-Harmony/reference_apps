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
//#include "audio/decoder/audio_decoders_config.h"
//#include "audio/decoder/audio_decoders.h"
// *****************************************************************************
// *****************************************************************************
// Section: User Configuration macros
// *****************************************************************************
// *****************************************************************************
#define APP_SDCARD_AUDIO_CARD_MAX_DIRS   300
#define APP_SDCARD_AUDIO_CARD_MAX_FILES  500
    
#define APP_AUDIO_SRC_SWITCH                            BSP_SWITCH_1    

#define APP_OFF_RGB_LED()                           RGB_LED_R_Off(); \
    RGB_LED_G_Off(); \
    RGB_LED_B_Off();
       	  
#define APP_SDCARD_AUDIO_SRC_ON()                       RGB_LED_R_on()
#define APP_SDCARD_AUDIO_SRC_OFF()                      RGB_LED_R_Off()
#define APP_TRACK_CHANGE_INDICATE()                     RGB_LED_R_Toggle()
    
    
#define APP_SDCARD_AUDIO_CARD_MOUNT_NAME                SYS_FS_MEDIA_IDX0_MOUNT_NAME_VOLUME_IDX0
#define APP_SDCARD_AUDIO_CARD_DEVICE_NAME               SYS_FS_MEDIA_IDX0_DEVICE_NAME_VOLUME_IDX0    

    
#define SWAPCHANNELS
#define NUM_SAMPLES                     5152
#define BUFFER_SIZE                     4*NUM_SAMPLES      
    
#define VBUS_AH_PowerEnable()              (LATESET = (1<<0))
#define VBUS_AH_PowerDisable()             (LATECLR = (1<<0)) 
    

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // USER_H
/*******************************************************************************
 End of File
*/
