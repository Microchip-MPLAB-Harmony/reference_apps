---
grand_parent: Reference Applications
parent: Curiosity PIC32MZ EF 2.0 Development Board
title: SD Card Audio Player
nav_order: 5
---
<img src = "images/microchip_logo.png">
<img src = "images/microchip_mplab_harmony_logo_small.png">

# SD Card GFX Audio Player Application on Curiosity PIC32MZ EF 2.0 Development Board
<h2 align="center"> <a href="https://github.com/Microchip-MPLAB-Harmony/reference_apps/releases/latest/download/sdcard_player.zip" > Download </a> </h2>

-----
## Description:

>    The demonstration application creates an audio player that reads audio files
     (.WAV format only) from an SD card mounted on the click interface. The audio
     is played through the CODEC placed on the X32 header interface. It also provides
     feature to switch to the next track on the media.    

>    The sdcard_player application plays .wav files from the SD Card. The SD Card
     driver uses the SPI driver to interact with the SD Card. The application uses
     the File System Service to read/write data on the SD Card. The audio data read
     from the SD card is decoded by passing it to the WAV decoder. The decoded output
     is saved in the output buffers 1 and 2 which are used in ping pong manner. The
     output buffers 1 and 2 are submitted to the Codec driver for playing.
     The Codec is configured for 16-bit data and 48 kHz sampling frequency.
     The Codec driver sends the audio data to the AK4954 Codec using the I2S driver,
     which in turn uses DMA to transfer the audio data. The Codec driver uses the
     I2C driver to send commands to the AK4954 Codec.

>    The application displays audio track from the SD card. It also provides 
     volume increase/decrease scroll bar, Play/Pause button, Next Track button, 
	 Previous Track button.

## Modules/Technology Used:

- Peripheral Modules      
	- Core Timer
	- DMA
- Driver Modules
    - I2S driver
    - SDSPI driver
    - AK4954 Codec driver
- System Service Libraries
	- File System
- WAV Audio decoder

## Hardware Used:

- [Curiosity PIC32MZ EF 2.0 Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320209)   
- [MICROSD CLICK from MikroElektronika](http://www.mikroe.com/click/microsd)
- [PIC32 Audio Codec Daughter Card - AK4954](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/AC324954)
- [HIGH-PERFORMANCE 4.3" WQVGA DISPLAY MODULE WITH MAXTOUCH® TECHNOLOGY](https://www.microchip.com/en-us/development-tool/AC320005-4)
- [565 LCD ADAPTER GRAPHICS CARD](https://www.microchip.com/en-us/development-tool/AC320212)
- Micro SD Card


## Software/Tools Used:
<span style="color:blue"> This project has been verified to work with the following versions of software tools:</span>  

Refer [Project Manifest](./firmware/src/config/pic32mzef_c2_ak4954/harmony-manifest-success.yml) present in harmony-manifest-success.yml under the project folder *firmware/src/config/pic32mzef_c2_ak4954*  
- Refer the [Release Notes](../../../release_notes.md#development-tools) to know the **MPLAB X IDE** and **MCC** Plugin version. Alternatively, [Click Here](https://github.com/Microchip-MPLAB-Harmony/reference_apps/blob/master/release_notes.md#development-tools)

<span style="color:blue"> Because Microchip regularly update tools, occasionally issue(s) could be discovered while using the newer versions of the tools. If the project doesn’t seem to work and version incompatibility is suspected, It is recommended to double-check and use the same versions that the project was tested with. </span> To download original version of MPLAB Harmony v3 packages, refer to document [How to Use the MPLAB Harmony v3 Project Manifest Feature](https://ww1.microchip.com/downloads/en/DeviceDoc/How-to-Use-the-MPLAB-Harmony-v3-Project-Manifest-Feature-DS90003305.pdf)

## Setup:
- Mount the microSD click board on the mikro bus 1 interface (J301, J302) on Curiosity PIC32MZ EF 2.0 Development Board
- Insert a micro SD card into the microSD click board card slot. Ensure that the SD card contains WAV audio files
- Mount the PIC32 Audio Codec Daughter Card - AK4954 on X32 HEADER 2 on Curiosity PIC32MZ EF 2.0 Development Board
- Connect speaker or headphone to the headphone out (HP OUT) connector (Yellow colour)  on top of the PIC32 Audio Codec Daughter Card - AK4954
- Attach the 565 LCD Adapter Graphics Card to the GFX Connector on the Curiosity PIC32MZ EF 2.0 Development Board
- Connect the ribbon cable from the High-Performance 4.3" WQVGA Display module to the ribbon connector on the 565 LCD Adapter Graphics Card.
- Power the Curiosity PIC32MZ EF 2.0 Development Board from a Host PC through a Type-A male to micro-B USB cable connected to Micro-B port (J700)  
<img src = "images/hardware.png" align="middle">

## Programming hex file:
The pre-built hex file can be programmed by following the below steps.  

### Steps to program the hex file
- Open MPLAB X IDE
- Close all existing projects in IDE, if any project is opened.
- Go to File -> Import -> Hex/ELF File
- In the "Import Image File" window, Step 1 - Create Prebuilt Project, Click the "Browse" button to select the prebuilt hex file.
- Select Device has "PIC32MZ2048EFM144"
- Ensure the proper tool is selected under "Hardware Tool"
- Click on Next button
- In the "Import Image File" window, Step 2 - Select Project Name and Folder, select appropriate project name and folder
- Click on Finish button
- In MPLAB X IDE, click on "Make and Program Device" Button. The device gets programmed in sometime
- Follow the steps in "Running the Demo" section below

## Programming/Debugging Application Project:
- Open the project (sdcard_player\firmware\pic32mz_ef_curiosity_v2.X) in MPLAB X IDE
- Ensure "Curiosity/Starter Kits (PKOB4)" is selected as hardware tool to program/debug the application
- Build the code and program the device by clicking on the "make and program" button in MPLAB X IDE tool bar
- Follow the steps in "Running the Demo" section below

## Running the Demo:
- Reset or power cycle the device.
- You should see a display as shown below  
<img src = "images/gfx_1.png" align="middle">
- Insert the SD card, display renders the audio player options as shown below and starts playing the audio.Put on the headphone. You should be able to hear the audio track being played from the SD card.
<img src = "images/gfx_2.png" align="middle">
- Description of the options available are shown in below image  
<img src = "images/gfx_3.png" align="middle">

  - **Track List** : Displays the Tracks
  - **Previous Track** : Plays the previous track in the list
  - **Play/Pause** : Play and Pause the track
  - **Next Track** : Plays next track in the list
  - **Volume Control** : Increases/Decreases the volume level
## Comments:
- This application demo builds and works out of box by following the instructions above in "Running the Demo" section. If you need to enhance/customize this application demo, you need to use the MPLAB Harmony v3 Software framework. Refer links below to setup and build your applications using MPLAB Harmony.
	- [How to Setup MPLAB Harmony v3 Software Development Framework](https://ww1.microchip.com/downloads/en/DeviceDoc/How_to_Setup_MPLAB_%20Harmony_v3_Software_Development_Framework_DS90003232C.pdf)
	- [How to Build an Application by Adding a New PLIB, Driver, or Middleware to an Existing MPLAB Harmony v3 Project](http://ww1.microchip.com/downloads/en/DeviceDoc/How_to_Build_Application_Adding_PLIB_%20Driver_or_Middleware%20_to_MPLAB_Harmony_v3Project_DS90003253A.pdf)                
	- <span style="color:blue"> **MPLAB Harmony v3 is also configurable through MPLAB Code Configurator (MCC). Refer to the below links for specific instructions to use MPLAB Harmony v3 with MCC.**</span>
		- [Create a new MPLAB Harmony v3 project using MCC](https://microchipdeveloper.com/harmony3:getting-started-training-module-using-mcc)
		- [Update and Configure an Existing MHC-based MPLAB Harmony v3 Project to MCC-based Project](https://microchipdeveloper.com/harmony3:update-and-configure-existing-mhc-proj-to-mcc-proj)
		- [Getting Started with MPLAB Harmony v3 Using MPLAB Code Configurator](https://www.youtube.com/watch?v=KdhltTWaDp0)
		- [MPLAB Code Configurator Content Manager for MPLAB Harmony v3 Projects](https://www.youtube.com/watch?v=PRewTzrI3iE)

## Revision:
- v1.6.0 - Graphics supported added
- v1.5.0 - Removed MHC support, Regenerated and tested application.
- v1.4.0 - Added MCC support, Regenerated and tested application.
- v1.3.0 - Regenerated and tested application.
- v1.2.0 - Regenerated and tested application
- v1.1.0 - Regenerated and tested the demo application
- v1.0.0 - Released demo application
