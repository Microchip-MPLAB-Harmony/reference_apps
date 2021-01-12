---
grand_parent: Reference Applications
parent: SAM E51 Curiosity Nano Evaluation Kit
title: BLE Fitness Tracker
nav_order: 4
---
<img src = "images/microchip_logo.png">
<img src = "images/microchip_mplab_harmony_logo_small.png">

# BLE Fitness Tracker Application on SAM E51 Curiosity Nano and Nano Base for Click boards
-----

## Description:
> The application demonstrates a solution based on Microchip products for health care industry
  and wearable products. The application displays heart rate readings (in beats per minute - bpm)
  on a very low power consuming display and posts this Heart Rate data to Microchip Bluetooth Data (MBD)
  android mobile application via BLE (Bluetooth Low Energy).  


> The Mikro Elektronika Heart Rate 3 click board is used to read the heart pulse.
  Mikroelektronika eINK click bundle is used for displaying heart rate.
  The eINK click bundle contains the eINK click adapter board and the eINK display. BM71
  Bluetooth module is used to send the heart rate data over BLE.

> The Heart Rate 3 click contains two integrated LEDs, a photosensitive element and advanced low
  noise analog front end to provide clean and accurate heart rate readings. It is enough to place
  an index finger on top of the sensor to get the heart rate via I2C interface.

> The eINK display is a very low power consumption display and it has the ability to retain the information,
  even after disconnecting from the power source. The host MCU SAM E51 is interfaced with the Heart Rate 3 click
  over the I2C interface and eINK click over SPI Interface.

## Modules/Technology Used:

- Peripheral Modules  
	- Timer
	- EIC
- Driver Modules
	- SPI Driver
	- I2C Driver
  - BM71 Driver
- STDIO Library

## Hardware Used:

- [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)
- [Curiosity Nano Base for Click Boards](https://www.microchip.com/Developmenttools/ProductDetails/AC164162)
- [Heart Rate 3 click](https://www.mikroe.com/heart-rate-3-click)
- [EINK CLICK BUNDLE](https://www.mikroe.com/eink-click)
- [BM71-XPRO](https://www.microchip.com/Developmenttools/ProductDetails/DM164146)

## Software/Tools Used:
<span style="color:blue"> *This project has been verified to work with the following versions of software tools:*</span>  

- [MPLAB Harmony v3 "csp" repo v3.8.3](https://github.com/Microchip-MPLAB-Harmony/csp/releases/tag/v3.8.3)  
- [MPLAB Harmony v3 "core" repo v3.8.1](https://github.com/Microchip-MPLAB-Harmony/core/releases/tag/v3.8.1)  
- [MPLAB Harmony v3 "dev_packs" repo v3.8.0](https://github.com/Microchip-MPLAB-Harmony/dev_packs/releases/tag/v3.8.0)  
- [MPLAB Harmony v3 "mhc" repo v3.6.5](https://github.com/Microchip-MPLAB-Harmony/mhc/releases/tag/v3.6.5)  
- [MPLAB Harmony v3 "bt" repo v3.4.0](https://github.com/Microchip-MPLAB-Harmony/bt/releases/tag/v3.4.0)  
- MPLAB Harmony 3 Launcher Plugin v3.6.2  
- [MPLAB X IDE v5.45](https://www.microchip.com/mplab/mplab-x-ide)  
- [MPLAB XC32 Compiler v2.41](https://www.microchip.com/mplab/compilers)  
- Microchip Bluetooth Data Android App - Install using "\ble_fitness_tracker\firmware\android_apk\mbd_3_1.apk"  

<span style="color:blue"> *Because Microchip regularly update tools, occasionally issue(s) could be discovered while using the newer versions of the tools. If the project doesn’t seem to work and version incompatibility is suspected, It is recommended to double-check and use the same versions that the project was tested with.* </span>

## Adding private characteristics to BM71:
#### Hardware Setup
- In BM71-XPRO, Change jumper J2 to select USB
- In BM71-XPRO, Configure DIP switch SW2 with below configurations
  - All DIP switch ON
- Power the BM71-XPRO from a Host PC through a Type-A male to Micro-B USB cable connected to Micro-B port (J1)
- Perform reset by pressing switch SW1 on BM71-XPRO and check blue LD1 is ON  
<img src = "images/ble_setup.jpg" width="400" height="300" align="middle">

#### Programming private characteristics
- Download the manual configuration tool from [BM70/71 Firmware & Software Tools v1.11](https://www.microchip.com/wwwproducts/en/BM71)
- Extract and locate configuration tool from below location
 	- Your_downloaded_folder ```\Firmware & Software Tools v1.11\ConfigurationTool\IS187x_102_BLEDK3v1.11_UI1.00```
- Double click on ```IS187x_102_BLEDK3v1.11_UI1.00.exe```
- Click on "Load" button and select "Load Text File"  
<img src = "images/ble_config_loading_mainscreen.png" width="300" height="300" align="middle"> <img src = "images/ble_config_loading_step1.png" width="300" height="300" align="middle">
- Select “**bm71_heart_rate_service_chars_config.txt**” from **bm71_configuration** folder present in **firmware** folder  
<img src = "images/ble_config_loading_step2.png" width="800" height="225" align="middle">  
- Click on "EDIT" option  
<img src = "images/ble_config_loading_step3.png" width="300" height="250" align="middle">

- Select “0x01: BM71” in BLEDK and click ok

  <img src = "images/ble_config_loading_step4.png" width="400" height="200" align="middle">

- Click on "Finish"  
<img src = "images/ble_config_loading_step5.png" width="600" height="500"  align="middle">

- Click on “Write”  
<img src = "images/ble_config_loading_step6.png" width="300" height="250" align="middle">

- Select respective COM Port and set baud rate to 115200 then click on Write  
<img src = "images/ble_config_loading_step7.png" width="300" height="200" align="middle">

- Click on Yes to successfully update the private characteristics on to BM71 module  
<img src = "images/ble_config_loading_step8.png" width="300" height="150" align="middle">

- After successful update, click OK and remove the power from BM71-XPRO and change jumper J2 to select EXT  
<img src = "images/ble_config_loading_step9.png" width="300" height="300" align="middle">

- Turn OFF DIP 1 switch

## Setup:
- Mount SAM E51 Curiosity Nano Evaluation Kit on "CNANO56_HOST_CONN"(U3) connector of Curiosity Nano Base board
- Mount Heart Rate 3 click board on mikro bus click 2 connector of Curiosity Nano Base board
- Mount the eINK click bundle (eINK click + eINK dispaly) on the mikro bus 1 connector of Curiosity Nano Base board
- Connect the BM71-XPRO on to EXT 1 connector of Curiosity Nano Base board  
- Power the SAM E51 Curiosity Nano Evaluation Kit from a Host PC through a Type-A male to Micro-B USB cable connected to Micro-B port (J105)  

  <img src = "images/ble_fitness_tracker_demo_setup.jpg" width="600" height="650">  


## Programming hex file:
The pre-built hex file can be programmed by following the below steps.  

### Steps to program the hex file
- Open MPLAB X IDE
- Close all existing projects in IDE, if any project is opened.
- Go to File -> Import -> Hex/ELF File
- In the "Import Image File" window, Step 1 - Create Prebuilt Project, Click the "Browse" button to select the prebuilt hex file.
- Select Device has "ATSAME51G17D"
- Ensure the proper tool is selected under "Hardware Tool"
- Click on Next button
- In the "Import Image File" window, Step 2 - Select Project Name and Folder, select appropriate project name and folder
- Click on Finish button
- In MPLAB X IDE, click on "Make and Program Device" Button. The device gets programmed in sometime
- Follow the steps in "Running the Demo" section below

## Programming/Debugging Application Project:
- Open the project (ble_fitness_tracker\firmware\sam_e51_cnano.X) in MPLAB X IDE
- Ensure "PKOB nano" is selected as hardware tool to program/debug the application
- Build the code and program the device by clicking on the "make and program" button in MPLAB X IDE tool bar
- Follow the steps in "Running the Demo" section below

## Running the Demo:
<span style="color:blue"> *Before proceeding, install the Microchip Bluetooth Data android app in an Android Smartphone.* </span>
- Enable Bluetooth and location from Smartphone settings
- Perform reset by unplugging and re-plugging the power cable of SAM E51 Curiosity Nano
- Parallelly, open the "**Microchip Bluetooth Data (MBD)**" android app from your smartphone
  and tap on "Bluetooth Smart" icon on the dashboard. If prompted, allow the application to turn on Bluetooth.  
<img src = "images/mbd_appscreen1.jpg" width="250" height="450" align="middle">

- After power up, the application displays the Microchip logo on the eINK display and initializes the heart rate sensor
- After successful initialization of heart rate sensor, two integrated LEDs on the heart rate 3 click lights up

-  Now, scan for Bluetooth devices by tapping START SCAN option on the MBD APP.
  The BM71 device should appear as **MCHP_SAM_E51_HR** in the list of Bluetooth devices.  
<img src = "images/mbd_appscreen2.jpg" width="250" height="450" align="middle">

- Stop the scan and connect the **MCHP BLE device** by clicking on **MCHP_SAM_E51_HR**.
  This will establish a connection between the MBD BLE application and the BM71 BLE device.  
<img src = "images/mbd_appscreen3.jpg" width="250" height="450" align="middle">
<img src = "images/mbd_appscreen4.jpg" width="250" height="450" align="middle">

- Once BLE device is connected, the application shows the different services screen. Scrolll down
  and tap on the **Heart Rate Service**, it will redirect to **Sensor Location** screen.  
<img src = "images/mbd_appscreen5.jpg" width="250" height="450" align="middle">
<img src = "images/mbd_appscreen6.jpg" width="250" height="450" align="middle">

- Place your index finger gently on the heart rate 3 click sensor as shown in the figure below.  
<img src = "images/ble_fitness_tracker_demo_run.jpg" width="600" height="600" align="middle">

- In the bottom right corner of the **Sensor Location** screen, disable and enable the **Notify Button**.  
<img src = "images/mbd_appscreen6.jpg" width="250" height="450" align="middle">
<img src = "images/mbd_appscreen7.jpg" width="250" height="450" align="middle">  

- Wait till the LED "LED0" on SAM E51 Curiosity Nano board goes off. Once the LED is off, lift your finger.  
  **Note**: Make sure smartphone screen is not turned off and also don't switch to any other App(s) on your smartphone.
- The heart rate value (in bpm - beats per minute) gets displayed on the **Sensor Loaction** screen as shown
  in the figure below. Also, the same heart rate value gets displayed on the eINK display.  
<img src = "images/mbd_appscreen8.jpg" width="250" height="450" align="middle">

### Running the Demo with out BLE:
#### Note: To test in this procedure, the hardware setup doesn't requires BM71 XPRO. So, user can wish to disconnect the BM71-XPRO from EXT 1 connector of Curiosity Nano Base board.
- Perform reset by unplugging and re-plugging the power cable of SAM E51 Curiosity Nano
- After power up, the application displays the Microchip logo on the eINK display and initializes the heart rate sensor
- After successful initialization of heart rate sensor, two integrated LEDs on the heart rate 3 click lights up
- Press the switch "SW0" on SAM E51 Curiosity Nano board, LED "LED0" on SAM E51 Curiosity Nano board glows on
- Place your index finger gently on the heart rate 3 click sensor as shown in the figure below  
<img src = "images/ble_fitness_tracker_demo_run.jpg" width="600" height="600" align="middle">
- Wait till the LED "LED0" on SAM E51 Curiosity Nano board goes off and then lift your finger
- The heart rate value (in bpm - beats per minute) gets displayed on the eINK display


## Comments:
- Place your index finger gently on the heart rate 3 click sensor, don’t push or put pressure on the sensor (the heart rate values may not be accurate)
- Make sure smartphone screen is not turned off when reading Heart Rate Sensor data using the MBD smartphone APP and also, don't switch to any other smartphone App(s)
- Reference Training Module: [Getting Started with Harmony v3 Peripheral Libraries on SAM D5x/E5x MCUs](https://microchipdeveloper.com/harmony3:same54-getting-started-training-module)
- This application demo builds and works out of box by following the instructions above in "Running the Demo" section. If you need to enhance/customize this application demo, you need to use the MPLAB Harmony v3 Software framework. Refer links below to setup and build your applications using MPLAB Harmony.
	- [How to Setup MPLAB Harmony v3 Software Development Framework](https://www.microchip.com/mymicrochip/filehandler.aspx?ddocname=en1000821)
	- [How to Build an Application by Adding a New PLIB, Driver, or Middleware to an Existing MPLAB Harmony v3 Project](http://ww1.microchip.com/downloads/en/DeviceDoc/How_to_Build_Application_Adding_PLIB_%20Driver_or_Middleware%20_to_MPLAB_Harmony_v3Project_DS90003253A.pdf)  
- Code related for Heart Rate services are added manually, harmony v3 framework doesn't generate code related to it.

## Revision:
- v1.2.0 - Regenerated and tested application.
- v1.1.0 - Regenerated and tested application.
- v1.0.0 - Released demo application
