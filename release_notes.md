---
title: Release notes
nav_order: 99
---

# Microchip MPLAB® Harmony 3 Release Notes

---

## Reference Applications Release v1.4.1 (March 2022)

### New Applications
- N/A  

### Updated Applications
- Fixed images and hyperlink in [pic32cmmc_smart_tag_google_cloud_iot_core](./apps/pic32cm_mc00_cnano/pic32cmmc_smart_tag_google_cloud_iot_core/readme.md) and [same51n_google_cloud_iot_core](./apps/sam_e51_cnano/same51n_google_cloud_iot_core/readme.md) demo documentation.

### Known Issues
- Same as v1.4.0  

### Development Tools
- Same as v1.4.0

---

## Reference Applications Release v1.4.0 (December 2021)

- Added MCC support for all demo applications

### New Applications

| Application | Description | MCU | Development Board/Kit |  
| --- | --- | --- | --- |  
| [pic32mzef_thermal_camera_heat_map](./apps/pic32mz_ef_curiosity_v2/pic32mzef_thermal_camera_heat_map/readme.md) |  Thermal Camera based Heat Map Application | [PIC32MZ](https://www.microchip.com/wwwproducts/en/PIC32MZ2048EFM144) | [Curiosity PIC32MZ EF 2.0 Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320209)|
| [pic32cmmc_smart_tag_google_cloud_iot_core](./apps/pic32cm_mc00_cnano/pic32cmmc_smart_tag_google_cloud_iot_core/readme.md) | Smart Tag Google Cloud IoT Core Application | [PIC32CM MC00](https://www.microchip.com/wwwproducts/en/PIC32CM1216MC00032) | [PIC32CM MC00 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV10N93A)|
| [samd21_low_power](./apps/sam_d21_xpro/samd21_low_power/readme.md) |  Low Power | [SAM D21](https://www.microchip.com/wwwproducts/en/ATSAMD21J18A) | [SAM D21 Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/atsamd21-xpro)|
| [samd21_sdcard_usb_datalogger](./apps/sam_d21_xpro/samd21_sdcard_usb_datalogger/readme.md) |  SD Card, USB Data Logger | [SAM D21](https://www.microchip.com/wwwproducts/en/ATSAMD21J18A) | [SAM D21 Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/atsamd21-xpro)|
| [wifi_7](./apps/sam_e51_cnano/same51n_mikroe_click/wifi_7/readme.md) | MikroElektronika WIFI 7 Click Board example | [SAM E51](https://www.microchip.com/wwwproducts/en/ATSAME51N20A) | [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)|
| [oled_c](./apps/sam_e51_cnano/same51n_mikroe_click/oled_c/readme.md) | MikroElektronika OLED C Click Board example | [SAM E51](https://www.microchip.com/wwwproducts/en/ATSAME51N20A) | [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)|
| [usb_i2c](./apps/sam_e51_cnano/same51n_mikroe_click/usb_i2c/readme.md) | MikroElektronika USB I2C Click Board example | [SAM E51](https://www.microchip.com/wwwproducts/en/ATSAME51N20A) | [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)|
| [rfid](./apps/sam_e51_cnano/same51n_mikroe_click/rfid/readme.md) | MikroElektronika RFID Click Board example | [SAM E51](https://www.microchip.com/wwwproducts/en/ATSAME51N20A) | [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)|

### Updated Applications  

| Application | Description | MCU | Development Board/Kit | Comment |  
| --- | --- | --- | --- | --- |  
| [pic32cmmc_smart_appliance_control](./apps/pic32cm_mc00_cnano/pic32cmmc_smart_appliance_control/readme.md) | Smart Appliance Control Application | [PIC32CM MC00](https://www.microchip.com/wwwproducts/en/PIC32CM1216MC00032) | [PIC32CM MC00 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV10N93A)| Added display capability |  
| [same54_getting_started_freertos](./apps/sam_e54_xpro/same54_getting_started_freertos/readme.md) | Getting Started with Harmony Drivers using FreeRTOS | [SAM E54](https://www.microchip.com/wwwproducts/en/ATSAME54P20A) | [SAM E54 Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/productdetails/atsame54-xpro)| Updated hardware setup image |
| [usb_uart](./apps/sam_e51_cnano/same51n_mikroe_click/usb_uart/readme.md) | MikroElektronika USB UART Click Board example | [SAM E51](https://www.microchip.com/wwwproducts/en/ATSAME51N20A) | [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)| Updated click interface APIs |
| [pic32cmmc_getting_started](./apps/pic32cm_mc00_cnano/pic32cmmc_getting_started/readme.md) |  Getting Started using Harmony v3 Peripheral Libraries | [PIC32CM MC00](https://www.microchip.com/wwwproducts/en/PIC32CM1216MC00032) | [PIC32CM MC00 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV10N93A)| Updated hardware setup image |
| [getting_started_ext](./apps/pic32mz_ef_curiosity_v2/getting_started_ext/readme.md) | Getting Started Extended using Harmony v3 Peripheral Libraries | [PIC32MZ EF](https://www.microchip.com/wwwproducts/en/PIC32MZ2048EFM144) | [Curiosity PIC32MZ EF 2.0 Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320209)| Extended functionality to toggle LED3 on SW3 press |
| [google_cloud_iot_core](./apps/sam_d21_iot/google_cloud_iot_core/readme.md) |  Google Cloud IoT Core | [SAM D21](https://www.microchip.com/wwwproducts/en/ATSAMD21G18) | [SAM-IoT WG Development Board](https://www.microchip.com/DevelopmentTools/ProductDetails/EV75S95A)| AP mode support added and fixed clound connectivity issue |
| [ble_weather_station](./apps/sam_d21_cnano/ble_weather_station/readme.md) | BLE based Weather Station and Motion Sensor Application on SAM D21 Curiosity Nano and Nano Base for Click boards | [SAMD 21](https://www.microchip.com/wwwproducts/en/ATSAMD21G17) | [SAM D21 Curiosity Nano Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320119)| Updated to use click rotunes |
| [location_sos](./apps/sam_d21_cnano/location_sos/readme.md) | Location Tagged SOS using Curiosity Nano Base for click boards and GSM-GPS click |[SAMD 21](https://www.microchip.com/wwwproducts/en/ATSAMD21G17) | [SAM D21 Curiosity Nano Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320119)| Updated to use click routines |

### Deleted Applications  

| Application | Description | Comment |  
| --- | --- |  --- |  
| pic32cmmc_temp_based_fan_control_oled_c | Temperature based Fan Speed Control with OLED C click display | Removed as the same functionality is provided by [Smart Appliance Control](./apps/pic32cm_mc00_cnano/pic32cmmc_smart_appliance_control/readme.md) demo |
| msd_multiple_luns | USB MSD with Multiple Drives Application | Removed as the same functionality is provided in [MPLAB Harmony v3 USB apps repository](https://github.com/Microchip-MPLAB-Harmony/usb_apps_device/tree/master/apps/msd_multiple_luns) |




### Known Issues
- None

### Development Tools
- [MPLAB® X IDE v5.50](https://www.microchip.com/mplab/mplab-x-ide)
- [MPLAB® XC32 C/C++ Compiler v3.01](https://www.microchip.com/mplab/compilers)
- [IAR EWARM v8.50](https://www.iar.com/iar-embedded-workbench/#!?architecture=Arm)
- MPLAB® X IDE plug-ins:
  - MPLAB Harmony 3 Launcher v3.6.4
  - MPLAB Harmony Configurator (MCC) v5.0.3    


---


## Reference Applications Release v1.3.0 (June 2021)
### New Applications

| Application | Description | MCU | Development Board/Kit |  
| --- | --- | --- | --- |  
| [same51n_google_cloud_iot_core](./apps/sam_e51_cnano/same51n_google_cloud_iot_core/readme.md) |  Google Cloud IoT Core Application | [SAM E51](https://www.microchip.com/wwwproducts/en/ATSAME51N20A) | [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)|
| [same54c_motion_surveillance](./apps/sam_e54_cult/same54c_motion_surveillance/readme.md) | Motion Surveillance Application | [SAM E54](https://www.microchip.com/wwwproducts/en/ATSAME54P20A) | [SAM E54 Curiosity Ultra Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320210)|
| [pic32cmmc_smart_appliance_control](./apps/pic32cm_mc00_cnano/pic32cmmc_smart_appliance_control/readme.md) | Smart Appliance Control Application | [PIC32CM MC00](https://www.microchip.com/wwwproducts/en/PIC32CM1216MC00032) | [PIC32CM MC00 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV10N93A)|
| [10dof](./apps/sam_e51_cnano/same51n_mikroe_click/10dof/readme.md) | MikroElektronika 10DOF Click Board example | [SAM E51](https://www.microchip.com/wwwproducts/en/ATSAME51N20A) | [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)|
| [eeprom4](./apps/sam_e51_cnano/same51n_mikroe_click/eeprom4/readme.md) | MikroElektronika EEPROM 4 Click Board example | [SAM E51](https://www.microchip.com/wwwproducts/en/ATSAME51N20A) | [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)|
| [leddriver3](./apps/sam_e51_cnano/same51n_mikroe_click/leddriver3/readme.md) | MikroElektronika LED DRIVER 3 Click Board example | [SAM E51](https://www.microchip.com/wwwproducts/en/ATSAME51N20A) | [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)|
| [gsm_gps](./apps/sam_e51_cnano/same51n_mikroe_click/gsm_gps/readme.md) | MikroElektronika GSM-GPS Click Board example | [SAM E51](https://www.microchip.com/wwwproducts/en/ATSAME51N20A) | [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)|
| [pir](./apps/sam_e51_cnano/same51n_mikroe_click/pir/readme.md) | MikroElektronika PIR Click Board example | [SAM E51](https://www.microchip.com/wwwproducts/en/ATSAME51N20A) | [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)|
| [thumbstick](./apps/sam_e51_cnano/same51n_mikroe_click/thumbstick/readme.md) | MikroElektronika Thumbstick Click Board example | [SAM E51](https://www.microchip.com/wwwproducts/en/ATSAME51N20A) | [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)|
| [usb_uart](./apps/sam_e51_cnano/same51n_mikroe_click/usb_uart/readme.md) | MikroElektronika USB UART Click Board example | [SAM E51](https://www.microchip.com/wwwproducts/en/ATSAME51N20A) | [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)|
| [xpro_adapter](./apps/sam_e51_cnano/same51n_mikroe_click/xpro_adapter/readme.md) | MikroElektronika XPRO Adapter Click Board example | [SAM E51](https://www.microchip.com/wwwproducts/en/ATSAME51N20A) | [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)|
| [eink_bundle](./apps/sam_e51_cnano/same51n_mikroe_click/eink_bundle/readme.md) | MikroElektronika EINK Bundle Click Board example | [SAM E51](https://www.microchip.com/wwwproducts/en/ATSAME51N20A) | [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)|
| [fan](./apps/sam_e51_cnano/same51n_mikroe_click/fan/readme.md) | MikroElektronika Fan Click Board example | [SAM E51](https://www.microchip.com/wwwproducts/en/ATSAME51N20A) | [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)|
| [heartrate9](./apps/sam_e51_cnano/same51n_mikroe_click/heartrate9/readme.md) | MikroElektronika Heart Rate 9 Click Board example | [SAM E51](https://www.microchip.com/wwwproducts/en/ATSAME51N20A) | [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)|
| [ir_thermo2](./apps/sam_e51_cnano/same51n_mikroe_click/ir_thermo2/readme.md) | MikroElektronika IrThermo 2 Click Board example | [SAM E51](https://www.microchip.com/wwwproducts/en/ATSAME51N20A) | [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)|
| [weather](./apps/sam_e51_cnano/same51n_mikroe_click/weather/readme.md) | MikroElektronika Weather Click Board example | [SAM E51](https://www.microchip.com/wwwproducts/en/ATSAME51N20A) | [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)|
| [same54_getting_started_freertos](./apps/sam_e54_xpro/same54_getting_started_freertos/readme.md) | Getting Started with Harmony Drivers using FreeRTOS | [SAM E54](https://www.microchip.com/wwwproducts/en/ATSAME54P20A) | [SAM E54 Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/productdetails/atsame54-xpro)|
| [samc21_getting_started_freertos](./apps/sam_c21_xpro/samc21_getting_started_freertos/readme.md) | Getting Started with Harmony Drivers using FreeRTOS | [SAM C21](https://www.microchip.com/wwwproducts/en/ATSAMC21N18A) | [SAM C21 Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/ATSAMC21-XPRO)|

### Updated Applications  

| Application | Description | MCU | Development Board/Kit | Comment |  
| --- | --- | --- | --- | --- |  
| [snake_game](./apps/pic32mz_ef_curiosity_v2/snake_game/readme.md) |  Snake Game | [PIC32MZ EF](https://www.microchip.com/wwwproducts/en/PIC32MZ2048EFM144) | [Curiosity PIC32MZ EF 2.0 Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320209)| Removed video reference in readme |  
| [ack_bootloader](./apps/sam_d21_cnano/samd21_amazon_ack/bootloader/readme.md) |  Amazon Alexa Connect Kit (ACK) OTA Bootloader | [SAM D21](https://www.microchip.com/wwwproducts/en/ATSAMD21G17) | [SAM D21 Curiosity Nano Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320119)| Updated to support ACK SDK v4.0 |  
| [ack_helloworld](./apps/sam_d21_cnano/samd21_amazon_ack/applications/HelloWorld/readme.md) |  Amazon Alexa Connect Kit (ACK) Hello World | [SAM D21](https://www.microchip.com/wwwproducts/en/ATSAMD21G17) | [SAM D21 Curiosity Nano Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320119)| Updated to support ACK SDK v4.0 |  
| [ack_microwave](./apps/sam_d21_cnano/samd21_amazon_ack/applications/Microwave/readme.md) |  Amazon Alexa Connect Kit (ACK) Microwave | [SAM D21](https://www.microchip.com/wwwproducts/en/ATSAMD21G17) | [SAM D21 Curiosity Nano Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320119)| Updated to support ACK SDK v4.0 |
| [ack_smartlight](./apps/sam_d21_cnano/samd21_amazon_ack/applications/SmartLight/readme.md) |  Amazon Alexa Connect Kit (ACK) SmartLight | [SAM D21](https://www.microchip.com/wwwproducts/en/ATSAMD21G17) | [SAM D21 Curiosity Nano Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320119)| Updated to support ACK SDK v4.0 |
| [ack_dashreplenishment](./apps/sam_d21_cnano/samd21_amazon_ack/applications/DashReplenishment/readme.md) |  Amazon Alexa Connect Kit (ACK) DashReplenishment | [SAM D21](https://www.microchip.com/wwwproducts/en/ATSAMD21G17) | [SAM D21 Curiosity Nano Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320119)| Updated to support ACK SDK v4.0 |
| [google_cloud_iot_core](./apps/sam_d21_iot/google_cloud_iot_core/readme.md) |  Google Cloud IoT Core | [SAM D21](https://www.microchip.com/wwwproducts/en/ATSAMD21G18) | [SAM-IoT WG Development Board](https://www.microchip.com/DevelopmentTools/ProductDetails/EV75S95A)| Updated to integrate CryptAuthLib, Harmony System service and WINC driver |
| [fitness_tracker](./apps/sam_d21_cnano/fitness_tracker/readme.md) |  Fitness Tracker | [SAM D21](https://www.microchip.com/wwwproducts/en/ATSAMD21G17) | [SAM D21 Curiosity Nano Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320119)| Updated to replace Heart rate 3 click board with Heart rate 9 click board |
| [ble_fitness_tracker](./apps/sam_e51_cnano/ble_fitness_tracker/readme.md) |  BLE Fitness Tracker |  [SAM E51](https://www.microchip.com/wwwproducts/en/ATSAME51N20A) | [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)| Updated to replace Heart rate 3 click board with Heart rate 9 click board |
| [pic32mzda_sdcard_usb_audio_player](./apps/pic32mz_da_curiosity/pic32mzda_sdcard_usb_audio_player/readme.md) |  SD Card USB Audio Player |  [PIC32MZ DA](https://www.microchip.com/wwwproducts/en/ATSAME51N20A) | [PIC32MZ DA Curiosity Development Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV87D54A)| Updated to support multiple bit rates, fixed display refresh rate. Removed unused Audio decoders (Adpcm and mp3) files |


### Deleted Applications  

| Application | Description | Comment |  
| --- | --- |  --- |  
| audio_player_lab1 |  Audio-Tone using a Lookup Table | Removed MEB-II based audio demo as hardware is matured |  
| audio_player_lab2 |  Audio-Tone Application by reading the tone from a text file stored in an SD card | Removed MEB-II based audio demo as hardware is matured |  
| audio_player_lab3 |  SD Card Reader and Audio-Tone Application by reading the tone from a text file stored in an SD card | Removed MEB-II based audio demo as hardware is matured |  
| audio_player_lab4 |  SD Card Reader ".wav" Audio player | Removed MEB-II based audio demo as hardware is matured |  
| audio_player_lab5 |  SD Card Audio Player/Reader with Aria Graphics | Removed MEB-II based audio demo as hardware is matured |  


### Known Issues
- None

### Development Tools

* Refer demo specific documentation in folder "docs" to know the tools and Harmony 3 packages used.

---

## Reference Applications Release v1.2.0 (January 2021)
### New Applications

| Application | Description | MCU | Development Board/Kit |  
| --- | --- | --- | --- |  
| [pic32cm_mc_curiosity_getting_started](./apps/pic32cm_mc00_curiosity_pro/pic32cm_mc_curiosity_getting_started/readme.md) |  Getting Started using Harmony v3 Peripheral Libraries | [PIC32CM MC00](https://www.microchip.com/wwwproducts/en/PIC32CM1216MC00048) | [PIC32CM MC Curiosity Pro Development Board](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV15N46A)|
| [pic32cmmc_getting_started](./apps/pic32cm_mc00_cnano/pic32cmmc_getting_started/readme.md) |  Getting Started using Harmony v3 Peripheral Libraries | [PIC32CM MC00](https://www.microchip.com/wwwproducts/en/PIC32CM1216MC00032) | [PIC32CM MC00 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV10N93A)|
| [pic32cmmc_temp_based_fan_control_oled_c](./apps/pic32cm_mc00_cnano/pic32cmmc_temp_based_fan_control_oled_c/readme.md) | Temperature based Fan Speed Control with OLED C click display | [PIC32CM MC00](https://www.microchip.com/wwwproducts/en/PIC32CM1216MC00032) | [PIC32CM MC00 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV10N93A)|
| [getting_started_drivers_middleware](./apps/sam_e70_xpld/getting_started_drivers_middleware/readme.md) | Getting Started with Drivers and Middleware | [SAM E70](https://www.microchip.com/wwwproducts/en/ATSAME70Q21B) | [SAM E70 Xplained Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/ATSAME70-XPLD)|
| [same54c_getting_started](./apps/sam_e54_cult/same54c_getting_started/readme.md) | Getting Started using Harmony v3 Peripheral Libraries | [SAM E54](https://www.microchip.com/wwwproducts/en/ATSAME54P20A) | [SAM E54 Curiosity Ultra Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320210)|
| [samd21_getting_started_freertos](./apps/sam_d21_xpro/samd21_getting_started_freertos/readme.md) | Getting Started with Harmony v3 Drivers using FreeRTOS | [SAM D21](https://www.microchip.com/wwwproducts/en/ATSAMD21J18A) | [SAM D21 Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/atsamd21-xpro)|
| [same51n_low_power_with_oled_c_click](./apps/sam_e51_cnano/same51n_low_power_with_oled_c_click/readme.md) | Low Power Application with OLED C Click | [SAME 51](https://www.microchip.com/wwwproducts/en/ATSAME51G18A) | [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)|

### Updated Applications  

| Application | Description | MCU | Development Board/Kit | Comment |  
| --- | --- | --- | --- | --- |  
| [snake_game](./apps/pic32mz_ef_curiosity_v2/snake_game/readme.md) |  Snake Game | [PIC32MZ EF](https://www.microchip.com/wwwproducts/en/PIC32MZ2048EFM144) | [Curiosity PIC32MZ EF 2.0 Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320209)| Fixed image view issue in documentation |  
| [ack_bootloader](./apps/sam_d21_cnano/samd21_amazon_ack/bootloader/readme.md) |  Amazon Alexa Connect Kit (ACK) OTA Bootloader | [SAM D21](https://www.microchip.com/wwwproducts/en/ATSAMD21G17) | [SAM D21 Curiosity Nano Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320119)| Updated to support ACK SDK v3.2 |  
| [ack_helloworld](./apps/sam_d21_cnano/samd21_amazon_ack/applications/HelloWorld/readme.md) |  Amazon Alexa Connect Kit (ACK) Hello World | [SAM D21](https://www.microchip.com/wwwproducts/en/ATSAMD21G17) | [SAM D21 Curiosity Nano Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320119)| Updated to support ACK SDK v3.2 |  
| [ack_microwave](./apps/sam_d21_cnano/samd21_amazon_ack/applications/Microwave/readme.md) |  Amazon Alexa Connect Kit (ACK) Microwave | [SAM D21](https://www.microchip.com/wwwproducts/en/ATSAMD21G17) | [SAM D21 Curiosity Nano Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320119)| Updated to support ACK SDK v3.2 |
| [ack_smartlight](./apps/sam_d21_cnano/samd21_amazon_ack/applications/SmartLight/readme.md) |  Amazon Alexa Connect Kit (ACK) SmartLight | [SAM D21](https://www.microchip.com/wwwproducts/en/ATSAMD21G17) | [SAM D21 Curiosity Nano Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320119)| Updated to support ACK SDK v3.2 |
| [ack_dashreplenishment](./apps/sam_d21_cnano/samd21_amazon_ack/applications/DashReplenishment/readme.md) |  Amazon Alexa Connect Kit (ACK) DashReplenishment | [SAM D21](https://www.microchip.com/wwwproducts/en/ATSAMD21G17) | [SAM D21 Curiosity Nano Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320119)| Updated to support ACK SDK v3.2 |
| [google_cloud_iot_core](./apps/sam_d21_iot/google_cloud_iot_core/readme.md) |  Google Cloud IoT Core | [SAM D21](https://www.microchip.com/wwwproducts/en/ATSAMD21G18) | [SAM-IoT WG Development Board](https://www.microchip.com/DevelopmentTools/ProductDetails/EV75S95A)| Update demo to support 32 character length password and SSID to support single space character |
| [snake_game](./apps/pic32mz_ef_curiosity_v2/snake_game/readme.md) |  Snake Game | [PIC32MZ EF](https://www.microchip.com/wwwproducts/en/PIC32MZ2048EFM144) | [Curiosity PIC32MZ EF 2.0 Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320209)| Fixed image view issue in documentation |
| [sdadc_conversion_interrupt](./apps/sam_c21n_xpro/sdadc_conversion_interrupt/readme.md) | SDADC Conversion Interrupt Mode | [SAM C21N](https://www.microchip.com/wwwproducts/en/ATSAMC21N18A) | [SAM C21N Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/atsamc21n-xpro)| Updated documentation with reference application note link |
| [sdadc_conversion_polling](./apps/sam_c21n_xpro/sdadc_conversion_polling/readme.md) | SDADC Conversion Polling Mode | [SAM C21N](https://www.microchip.com/wwwproducts/en/ATSAMC21N18A) | [SAM C21N Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/atsamc21n-xpro)| Updated documentation with reference application note link |





### Known Issues
1. The application “sam_d21_iot/google_cloud_iot_core" is developed by applying a patch (available in folder "google_cloud_iot_core/firmware/app_patch”) to MPLAB Harmony v3. If you need to reconfigure or regenerate this demo using MHC, please refer the “Notes.txt” file under “google_cloud_iot_core/firmware/app_patch” folder.  
The patch is applied due to a known issue in the application. This issue is expected to be fixed in a future release of "reference_apps" repository.
2. The application “pic32mz_ef_curiosity_v2/wifi_rgb_easy_configuration" is developed by applying a patch (available in folder "wifi_rgb_easy_configuration/firmware/wifi_repo_patch”) to MPLAB Harmony v3. If you need to reconfigure or regenerate this demo using MHC, please refer the “Notes.txt” file under “wifi_rgb_easy_configuration/firmware/wifi_repo_patch” folder.
The patch is applied due to a known issue in "wireless" repo. This issue is expected to be fixed in a future release of "wireless" repo.
3. The application demo "pic32mz_ef_sk_meb2/audio_player/audio_player_lab5" is developed using Aria Graphics library. From gfx v3.9.0 onwards Aria Graphics support is deprecated and archived in a separate gfx_aria v3.7.1 repo. If you wish to regenerate this demo, follow the notes mentioned in "Software/Tools Used" section in [readme](./apps/pic32mz_ef_sk_meb2/audio_player/audio_player_lab5/readme.md) for audio_player_lab5.


### Development Tools

* Refer demo specific documentation in folder "docs" to know the tools and Harmony 3 packages used.

---

## Reference Applications Release v1.1.0 (September 2020)
### New Applications

| Application | Description | MCU | Development Board/Kit |  
| --- | --- | --- | --- |  
| [google_cloud_iot_core](./apps/sam_d21_iot/google_cloud_iot_core/readme.md) |  Google Cloud IoT Core | [SAM D21](https://www.microchip.com/wwwproducts/en/ATSAMD21G18) | [SAM-IoT WG Development Board](https://www.microchip.com/DevelopmentTools/ProductDetails/EV75S95A)|
| [same51n_getting_started](./apps/sam_e51_cnano/same51n_getting_started/readme.md) |  Getting Started using Harmony v3 Peripheral Libraries | [SAME 51](https://www.microchip.com/wwwproducts/en/ATSAME51G18A) | [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)|
| [ble_fitness_tracker](./apps/sam_e51_cnano/ble_fitness_tracker/readme.md) |  BLE Fitness Tracker | [SAME 51](https://www.microchip.com/wwwproducts/en/ATSAME51G18A) | [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)|
| [pic32mzda_getting_started](./apps/pic32mz_da_curiosity/pic32mzda_getting_started/readme.md) |  Getting Started using Harmony v3 Peripheral Libraries | [PIC32MZ DA](https://www.microchip.com/wwwproducts/en/PIC32MZ2064DAR176) | [Curiosity PIC32MZ DA Development Board]()|
| [pic32mzda_sdcard_usb_audio_player](./apps/pic32mz_da_curiosity/pic32mzda_sdcard_usb_audio_player/readme.md) |  SD Card USB Audio Player | [PIC32MZ DA](https://www.microchip.com/wwwproducts/en/PIC32MZ2064DAR176) | [Curiosity PIC32MZ DA Development Board]()|
| [ack_bootloader](./apps/sam_d21_cnano/samd21_amazon_ack/bootloader/readme.md) |  Amazon Alexa Connect Kit (ACK) OTA Bootloader | [SAM D21](https://www.microchip.com/wwwproducts/en/ATSAMD21G17) | [SAM D21 Curiosity Nano Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320119)|
| [ack_helloworld](./apps/sam_d21_cnano/samd21_amazon_ack/applications/HelloWorld/readme.md) |  Amazon Alexa Connect Kit (ACK) Hello World | [SAM D21](https://www.microchip.com/wwwproducts/en/ATSAMD21G17) | [SAM D21 Curiosity Nano Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320119)|
| [ack_microwave](./apps/sam_d21_cnano/samd21_amazon_ack/applications/Microwave/readme.md) |  Amazon Alexa Connect Kit (ACK) Microwave | [SAM D21](https://www.microchip.com/wwwproducts/en/ATSAMD21G17) | [SAM D21 Curiosity Nano Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320119)|
| [ack_smartlight](./apps/sam_d21_cnano/samd21_amazon_ack/applications/SmartLight/readme.md) |  Amazon Alexa Connect Kit (ACK) SmartLight | [SAM D21](https://www.microchip.com/wwwproducts/en/ATSAMD21G17) | [SAM D21 Curiosity Nano Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320119)|
| [ack_dashreplenishment](./apps/sam_d21_cnano/samd21_amazon_ack/applications/DashReplenishment/readme.md) |  Amazon Alexa Connect Kit (ACK) DashReplenishment | [SAM D21](https://www.microchip.com/wwwproducts/en/ATSAMD21G17) | [SAM D21 Curiosity Nano Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320119)|
| [pic18f_to_samd21_migration](./apps/sam_d21_cnano/pic18f_to_samd21_migration/readme.md) |  Application migration from 8-bit PIC18F to 32-bit SAM D21 | [SAMD 21](https://www.microchip.com/wwwproducts/en/ATSAMD21G17) | [SAM D21 Curiosity Nano Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320119)|
| [atmega4809_to_samd21_migration](./apps/sam_d21_cnano/atmega4809_to_samd21_migration/readme.md) |  Application migration from 8-bit PIC18F to 32-bit SAM D21 | [SAMD 21](https://www.microchip.com/wwwproducts/en/ATSAMD21G17) | [SAM D21 Curiosity Nano Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320119)|
| [wifi_rgb_easy_configuration](./apps/pic32mz_ef_curiosity_v2/wifi_rgb_easy_configuration/readme.md) |  WiFi based RGB LED Control | [PIC32MZ EF](https://www.microchip.com/wwwproducts/en/PIC32MZ2048EFM144) | [Curiosity PIC32MZ EF 2.0 Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320209)|
| [snake_game](./apps/pic32mz_ef_curiosity_v2/snake_game/readme.md) |  Snake Game | [PIC32MZ EF](https://www.microchip.com/wwwproducts/en/PIC32MZ2048EFM144) | [Curiosity PIC32MZ EF 2.0 Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320209)|
| [same54_vending_machine](./apps/sam_e54_xpro/same54_vending_machine/readme.md) |  Vending Machine | [SAM E54](https://www.microchip.com/wwwproducts/en/ATSAME54P20A) | [SAM E54 Xplained Pro Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/ATSAME54-XPRO)|
| [same54_low_power](./apps/sam_e54_xpro/same54_low_power/readme.md) |  Low Power | [SAM E54](https://www.microchip.com/wwwproducts/en/ATSAME54P20A) | [SAM E54 Xplained Pro Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/ATSAME54-XPRO)|
| [samd21_ac_sleepwalk_singleshot_gcc](./apps/sam_d21_xpro/samd21_ac_sleepwalk_singleshot_gcc/readme.md) | AC Sleepwalking Application built with GCC Toolchain  | [SAM D21](https://www.microchip.com/wwwproducts/en/ATSAMD21J18A) | [SAM D21 Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/atsamd21-xpro)|
| [sdadc_conversion_interrupt](./apps/sam_c21n_xpro/sdadc_conversion_interrupt/readme.md) | SDADC Conversion Interrupt Mode | [SAM C21N](https://www.microchip.com/wwwproducts/en/ATSAMC21N18A) | [SAM C21N Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/atsamc21n-xpro)|
| [sdadc_conversion_polling](./apps/sam_c21n_xpro/sdadc_conversion_polling/readme.md) | SDADC Conversion Polling Mode | [SAM C21N](https://www.microchip.com/wwwproducts/en/ATSAMC21N18A) | [SAM C21N Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/atsamc21n-xpro)|
| [same54_sdcard_usb_audio_player](./apps/sam_e54_cult/same54_sdcard_usb_audio_player/readme.md) | SD Card USB Audio Player | [SAM E54](https://www.microchip.com/wwwproducts/en/ATSAME54P20A) | [SAM E54 Curiosity Ultra Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320210)|
| [same54_uart_live_update](./apps/sam_e54_cult/same54_uart_live_update/readme.md) | Live Update | [SAM E54](https://www.microchip.com/wwwproducts/en/ATSAME54P20A) | [SAM E54 Curiosity Ultra Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320210)|
| [saml11_trustzone_getting_started](./apps/sam_l11_xpro/saml11_trustzone_getting_started/readme.md) | TrustZone Getting Started | [SAM L11](https://www.microchip.com/wwwproducts/en/ATSAML11E16A) | [SAML11 Xplained Pro Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/dm320205)|

### Updated Applications
	- NA -

### Known Issues
1. The application “sam_d21_iot/google_cloud_iot_core" is developed by applying a patch (available in folder "google_cloud_iot_core/firmware/app_patch”) to MPLAB Harmony v3. If you need to reconfigure or regenerate this demo using MHC, please refer the “Notes.txt” file under “google_cloud_iot_core/firmware/app_patch” folder.  
The patch is applied due to a known issue in the application. This issue is expected to be fixed in a future release of "reference_apps" repository.
2. The application “sam_d21_cnano/ble_weather_station" is developed by applying a patch (available in folder "ble_weather_station/firmware/app_patch”) to MPLAB Harmony v3. If you need to reconfigure or regenerate this demo using MHC, please refer the “Notes.txt” file under “ble_weather_station/firmware/app_patch” folder.  
The patch is applied due to a known issue in "bt" repo and in the application. This issue is expected to be fixed in a future release of "reference_apps" repository and "bt" repository.
3. The application “sam_e51_cnano/ble_weather_station" is developed by applying a patch (available in folder "ble_fitness_tracker/firmware/app_patch”) to MPLAB Harmony v3. If you need to reconfigure or regenerate this demo using MHC, please refer the “Notes.txt” file under “ble_fitness_tracker/firmware/app_patch” folder.  
The patch is applied due to a known issue in "bt" repo and in the application. This issue is expected to be fixed in a future release of "reference_apps" repository and "bt" repository.
4. The application “pic32mz_ef_curiosity_v2/snake_game" is developed by applying a patch (available in folder "snake_game/firmware/gfx_ssd_driver_patch”) to MPLAB Harmony v3 “gfx” repository. If you need to reconfigure or regenerate this demo using MHC, please refer the “Notes.txt” file under “snake_game/firmware/gfx_ssd_driver_patch” folder.
The patch is applied due to a known issue in "gfx" repo v3.7.0. This issue is expected to be fixed in a future release of "gfx” repository.
5. The application demos “pic32mz_ef_curiosity_v2/snake_game", "pic32mz_da_curiosity/pic32mzda_sdcard_usb_audio_player", "sam_e54_cult/same54_sdcard_usb_audio_player" and "pic32mz_ef_sk_meb2/audio_player/audio_player_lab5" having Graphics features are developed using Graphics library "gfx" v3.7.0. These demos could version incompatibility when regenerated with a higher version of "gfx" repo. This limitation is expected to be fixed in a future release of "reference_apps” repository.

### Development Tools

* Refer demo specific documentation in folder "docs" to know the tools and Harmony 3 packages used.

---

## Reference Applications Release v1.0.0 (June 2020)
### New Applications

The following table provides the list of new applications:

| Application | Description | MCU | Development Board/Kit |
| --- | --- | --- | --- |
| [samd21n_getting_started](./apps/sam_d21_cnano/samd21n_getting_started/readme.md) |  Getting Started using Harmony v3 Peripheral Libraries | [SAMD 21](https://www.microchip.com/wwwproducts/en/ATSAMD21G17) | [SAM D21 Curiosity Nano Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320119)|
| [fitness_tracker](./apps/sam_d21_cnano/fitness_tracker/readme.md) | Fitness Tracker using Curiosity Nano Base for click boards, Heart Rate 3 click and EINK CLICK BUNDLE | [SAMD 21](https://www.microchip.com/wwwproducts/en/ATSAMD21G17) | [SAM D21 Curiosity Nano Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320119)|
| [location_sos](./apps/sam_d21_cnano/location_sos/readme.md) | Location Tagged SOS using Curiosity Nano Base for click boards and GSM-GPS click |[SAMD 21](https://www.microchip.com/wwwproducts/en/ATSAMD21G17) | [SAM D21 Curiosity Nano Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320119)|
| [ble_weather_station](./apps/sam_d21_cnano/ble_weather_station/readme.md) | BLE based Weather Station and Motion Sensor Application on SAM D21 Curiosity Nano and Nano Base for Click boards | [SAMD 21](https://www.microchip.com/wwwproducts/en/ATSAMD21G17) | [SAM D21 Curiosity Nano Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320119)|
| [pic32mzef_getting_started](./apps/pic32mz_ef_curiosity_v2/pic32mzef_getting_started/readme.md) | Getting Started using Harmony v3 Peripheral Libraries | [PIC32MZ EF](https://www.microchip.com/wwwproducts/en/PIC32MZ2048EFM144) | [Curiosity PIC32MZ EF 2.0 Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320209)|
| [getting_started_ext](./apps/pic32mz_ef_curiosity_v2/getting_started_ext/readme.md) | Getting Started Extended using Harmony v3 Peripheral Libraries | [PIC32MZ EF](https://www.microchip.com/wwwproducts/en/PIC32MZ2048EFM144) | [Curiosity PIC32MZ EF 2.0 Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320209)|
| [getting_started_middleware](./apps/pic32mz_ef_curiosity_v2/getting_started_middleware/readme.md) | Getting Started Application using Harmony v3 Drivers, System Services, Middleware and FreeRTOS | [PIC32MZ EF](https://www.microchip.com/wwwproducts/en/PIC32MZ2048EFM144) | [Curiosity PIC32MZ EF 2.0 Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320209)|
| [msd_multiple_luns](./apps/pic32mz_ef_curiosity_v2/msd_multiple_luns/readme.md) | USB MSD with Multiple Drives | [PIC32MZ EF](https://www.microchip.com/wwwproducts/en/PIC32MZ2048EFM144) | [Curiosity PIC32MZ EF 2.0 Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320209)|
| [sdcard_player](./apps/pic32mz_ef_curiosity_v2/sdcard_player/readme.md) | SD Card Audio Player | [PIC32MZ EF](https://www.microchip.com/wwwproducts/en/PIC32MZ2048EFM144) | [Curiosity PIC32MZ EF 2.0 Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320209)|
| [saml10_getting_started](./apps/sam_l10_xpro/saml10_getting_started/readme.md) | Getting Started using Harmony v3 Peripheral Libraries | [SAM L10](https://www.microchip.com/wwwproducts/en/ATSAML10E16A) | [SAM L10 Xplained Pro Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320204)|
| [saml10_low_power](./apps/sam_l10_xpro/saml10_low_power/readme.md) 		       | Low Power 					| [SAM L10](https://www.microchip.com/wwwproducts/en/ATSAML10E16A) 	   | [SAM L10 Xplained Pro Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/dm320204)|
| [saml21_low_power](./apps/sam_l21_xpro/saml21_low_power/readme.md) | Low Power | [SAM L21](https://www.microchip.com/wwwproducts/en/ATSAML21J18B) | [SAM L21 Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/atsaml21-xpro-b)|
| [samc21_low_power](./apps/sam_c21_xpro/samc21_low_power/readme.md) | Low Power | [SAM C21](https://www.microchip.com/wwwproducts/en/ATSAMC21J18A) | [SAM C21 Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/atsamc21-xpro)|
| [same70_getting_started](./apps/sam_e70_xult/same70_getting_started/readme.md) | Getting Started using Harmony v3 Peripheral Libraries | [SAM E70](https://www.microchip.com/wwwproducts/en/ATSAME70Q21B) | [SAM E70 Xplained Ultra Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320113)|
| [getting_started_drv](./apps/sam_e70_xult/getting_started_drv/readme.md) | Getting Started using Harmony v3 Drivers | [SAM E70](https://www.microchip.com/wwwproducts/en/ATSAME70Q21B) | [SAM E70 Xplained Ultra Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320113)|
| [getting_started_freertos](./apps/sam_e70_xult/getting_started_freertos/readme.md) | Getting Started using Harmony v3 Drivers and FreeRTOS | [SAM E70](https://www.microchip.com/wwwproducts/en/ATSAME70Q21B) | [SAM E70 Xplained Ultra Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320113)|
| [qspi_xdmac_read_write](./apps/sam_e70_xult/qspi_xdmac_read_write/readme.md) | XDMAC with QSPI | [SAM E70](https://www.microchip.com/wwwproducts/en/ATSAME70Q21B) | [SAM E70 Xplained Ultra Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320113)|
| [ftp_bootloader](./apps/sam_e70_xult/ftp_bootloader/readme.md) | Ethernet bootloader - File Transfer Protocol | [SAM E70](https://www.microchip.com/wwwproducts/en/ATSAME70Q21B) | [SAM E70 Xplained Ultra Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320113)|
| [same54_getting_started](./apps/sam_e54_xpro/same54_getting_started/readme.md) | Getting Started using Harmony v3 Peripheral Libraries | [SAM E54](https://www.microchip.com/wwwproducts/en/ATSAME54P20A) | [SAM E54 Xplained Pro Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/ATSAME54-XPRO)|
| [sleepwalking](./apps/sam_e54_xpro/sleepwalking/readme.md) | SleepWalking  | [SAM E54](https://www.microchip.com/wwwproducts/en/ATSAME54P20A) | [SAM E54 Xplained Pro Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/ATSAME54-XPRO)|
| [samd21_getting_started](./apps/sam_d21_xpro/samd21_getting_started/readme.md) | Getting Started using Harmony v3 Peripheral Libraries | [SAM D21](https://www.microchip.com/wwwproducts/en/ATSAMD21J18A) | [SAM D21 Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/atsamd21-xpro)|
| [samc21n_getting_started](./apps/sam_c21n_xpro/samc21n_getting_started/readme.md) | Getting Started using Harmony v3 Peripheral Libraries | [SAM C21N](https://www.microchip.com/wwwproducts/en/ATSAMC21N18A) | [SAM C21N Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/atsamc21n-xpro)|
| [pic32mk_getting_started](./apps/pic32mk_gp_db/pic32mk_getting_started/readme.md) | Getting Started using Harmony v3 Peripheral Libraries | [PIC32MK](https://www.microchip.com/wwwproducts/en/PIC32MK1024GPE100) | [PIC32MK General Purpose (GP) Development Board](http://www.microchip.com/DevelopmentTools/ProductDetails.aspx?PartNO=DM320106)|
| [pic32mx470_getting_started](./apps/pic32mx470_curiosity/pic32mx470_getting_started/readme.md) | Getting Started using Harmony v3 Peripheral Libraries | [PIC32MX](https://www.microchip.com/wwwproducts/en/PIC32MX470F512H) | [Curiosity PIC32MX470 Development Board](http://www.microchip.com/DevelopmentTools/ProductDetails.aspx?PartNO=DM320103)|
| [audio_player_lab1](./apps/pic32mz_ef_sk_meb2/audio_player/audio_player_lab1/readme.md) | Audio-Tone using a Lookup Table | [PIC32MZ EF](https://www.microchip.com/wwwproducts/en/PIC32MZ2048EFM144) | [PIC32MZ Embedded Connectivity with FPU Starter Kit](http://www.microchip.com/Developmenttools/ProductDetails.aspx?PartNO=DM320007) + [Multimedia Expansion Board II](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320005-5)|
| [audio_player_lab2](./apps/pic32mz_ef_sk_meb2/audio_player/audio_player_lab2/readme.md) | Audio-Tone Application by reading the tone from a text file stored in an SD card | [PIC32MZ EF](https://www.microchip.com/wwwproducts/en/PIC32MZ2048EFM144) | [PIC32MZ Embedded Connectivity with FPU Starter Kit](http://www.microchip.com/Developmenttools/ProductDetails.aspx?PartNO=DM320007) + [Multimedia Expansion Board II](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320005-5)|
| [audio_player_lab3](./apps/pic32mz_ef_sk_meb2/audio_player/audio_player_lab3/readme.md) | SD Card Reader and Audio-Tone Application by reading the tone from a text file stored in an SD card | [PIC32MZ EF](https://www.microchip.com/wwwproducts/en/PIC32MZ2048EFM144) | [PIC32MZ Embedded Connectivity with FPU Starter Kit](http://www.microchip.com/Developmenttools/ProductDetails.aspx?PartNO=DM320007) + [Multimedia Expansion Board II](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320005-5)|
| [audio_player_lab4](./apps/pic32mz_ef_sk_meb2/audio_player/audio_player_lab4/readme.md) | SD Card Reader ".wav" Audio player | [PIC32MZ EF](https://www.microchip.com/wwwproducts/en/PIC32MZ2048EFM144) | [PIC32MZ Embedded Connectivity with FPU Starter Kit](http://www.microchip.com/Developmenttools/ProductDetails.aspx?PartNO=DM320007) + [Multimedia Expansion Board II](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320005-5)|
| [audio_player_lab5](./apps/pic32mz_ef_sk_meb2/audio_player/audio_player_lab5/readme.md) | SD Card Audio Player/Reader with Aria Graphics | [PIC32MZ EF](https://www.microchip.com/wwwproducts/en/PIC32MZ2048EFM144) | [PIC32MZ Embedded Connectivity with FPU Starter Kit](http://www.microchip.com/Developmenttools/ProductDetails.aspx?PartNO=DM320007) + [Multimedia Expansion Board II](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320005-5)|
| [pic32mz_uart_live_update](./apps/pic32mz_ef_sk/pic32mz_uart_live_update/readme.md)     | Live update on PIC32MZ  			| [PIC32MZ EF](https://www.microchip.com/wwwproducts/en/PIC32MZ2048EFM144) | [PIC32MZ Embedded Connectivity with FPU Starter Kit](http://www.microchip.com/Developmenttools/ProductDetails.aspx?PartNO=DM320007)|

### Updated Applications
	- NA -

### Known Issues
1. The demo “pic32mz_ef_sk_meb2/audio_player/audio_player_lab5” is developed by applying a patch (available in folder “audio_player_lab5/firmware/gfx_repo_patch”) to the MPLAB Harmony v3 “gfx” repository. If you need to reconfigure or regenerate this demo using the MHC, please refer the “Notes.txt” file under audio_player_lab5/firmware/gfx_repo_patch” folder.  
The patch is applied due to a known issue with MHC v3.5.0 for Aria GAC Code Generation. This issue is expected to be fixed in gfx release v3.7.0.  
2. The application “pic32mz_ef_curiosity_v2/msd_multiple_luns” is developed by by applying a patch (available in folder “msd_multiple_luns/firmware/usb_repo_patch”) to MPLAB Harmony v3 “usb” repository. If you need to reconfigure or regenerate this demo using MHC, please refer the “Notes.txt” file under “msd_multiple_luns/firmware/usb_repo_patch” folder.  
The patch is applied due to a known issue with MHC v3.5.0 for USB Code Generation for this demo application.
This issue is expected to be fixed in a future release of "usb” repository.


### Development Tools

* Refer demo specific documentation in folder "docs" to know the tools and Harmony 3 packages used.
