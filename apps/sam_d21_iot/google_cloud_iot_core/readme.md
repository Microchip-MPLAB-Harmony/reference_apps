---
grand_parent: Reference Applications
parent: SAM D21 IoT Development Board
title: Google Cloud IoT Core Application
nav_order: 1
---
<img src = "images/microchip_logo.png">
<img src = "images/microchip_mplab_harmony_logo_small.png">

# Google Cloud IoT Core Application on SAM D21 IoT WG Development Board
<h2 align="center"> <a href="https://github.com/MicrochipTech/MPLAB-Harmony-Reference-Apps/releases/latest/download/google_cloud_iot_core.zip" > Download </a> </h2>

-----

## <span style="color:red"> <b>Important:</b>
> There could be updates and bug fixes to the Google IoT sensor node application. Therefore, it is recommended to program SAM D21 IoT WG Development Board with the latest version of hex file from the [hex folder](./hex).  

## Description:

> The SAM-IoT WG Development board based on SAM D21 microcontroller is a small and easily expandable demonstration and development platform for Wi-Fi based IoT Node applications. This specific development board comes pre-provisioned for Google IoT core and hence the name "WG". The application that comes pre-programmed with factory shipped boards demonstrates MQTT data transfer of on-board light and temperature sensor data to Google IoT core.

## Key Highlights of [SAM-IoT WG Development Board](https://www.microchip.com/DevelopmentTools/ProductDetails/EV75S95A):

* On-board Light and Temperature Sensors.
* Additional sensors can be interfaced using "click boards" through on-board [mikroBUS connector](https://www.mikroe.com/click).
* On-board nEDBG debugger. Hence, no external debugger needed.
* Virtual COM and USB Mass Storage for Drag & Drop programming.
* Dual power supply options. USB or Battery.
* On-board Li-Po battery charging circuitry.
* ATECC608A based secure cloud connectivity

## Features of SAM-IoT WG Development Board:

* Drag & Drop of application hex files. Hence, no need for IDE to program SAM D21 microcontroller.
* Drag & Drop of Wi-Fi credentials to connect to the internet.
* Microcontroller peripheral libraries and Middleware are based on MPLAB Harmony 3 Software framework.
* MPLABX IDE based project.
* Command Line Interface (CLI) support for Wi-Fi credentials configuration.
* 4 LED indicators to indicate the operating status.

## Components Used:
- [ATSAMD21G18A microcontroller](https://www.microchip.com/wwwproducts/en/ATsamd21g18)
- [ATWINC1510 Wi-FI module](https://www.microchip.com/wwwproducts/en/ATwinc1500)
- [ATECC608A secure element](https://www.microchip.com/wwwproducts/en/ATECC608A)
- [MCP9808 digital temperature sensor](https://www.microchip.com/wwwproducts/en/en556182)
- [MCP73871 Battery Charger](https://www.microchip.com/wwwproducts/en/en536670)
- [MIC33050 Voltage Regulator](https://www.microchip.com/wwwproducts/en/MIC33050)
- TEMT6000 ambient light sensor


## Software/Tools Used:
<span style="color:blue"> *This project has been verified to work with the following versions of software tools:*</span>  

 - [MPLAB Harmony v3 "csp" repo v3.8.3](https://github.com/Microchip-MPLAB-Harmony/csp/releases/tag/v3.8.3)  
 - [MPLAB Harmony v3 "core" repo v3.8.1](https://github.com/Microchip-MPLAB-Harmony/core/releases/tag/v3.8.1)            
 - [MPLAB Harmony v3 "dev_packs" repo v3.8.0](https://github.com/Microchip-MPLAB-Harmony/dev_packs/releases/tag/v3.8.0)  
 - [MPLAB Harmony v3 "mhc" repo v3.6.5](https://github.com/Microchip-MPLAB-Harmony/mhc/releases/tag/v3.6.5)  
 - MPLAB Harmony 3 Launcher Plugin v3.6.2  
 - [MPLAB X IDE v5.50](https://www.microchip.com/mplab/mplab-x-ide)  
 - [MPLAB XC32 Compiler v2.41](https://www.microchip.com/mplab/compilers)   

<span style="color:blue"> *Because Microchip regularly update tools, occasionally issue(s) could be discovered while using the newer versions of the tools. If the project doesn’t seem to work and version incompatibility is suspected, It is recommended to double-check and use the same versions that the project was tested with.* </span>  

## <a id="WINC_Firmware_upgrade_and_Google_Cloud_IoT_Provisioning_Guide"> </a>
## ATWINC1510 Firmware upgrade and Google Cloud IoT Provisioning (Root certificate upgrade) Guide
<span style="color:blue"> [Refer the documentation in utilities  folder](./utilities/readme.md) </span>  
<span style="color:red"> **If this is the first time you are building/running this version of the demo, you must complete this step before proceeding further. Otherwise, you may skip this step.** </span>

## Application Demonstration:

The below sections describes the steps to run the application.

### 1. How to setup the SAM-IoT WG Development Board
- The SAM-IoT WG Development board comes with pre-loaded application for out-of-box experience for the end user. Connect the board to the host PC's USB port to power-up the board.  
- Alternatively, the board can be powered using a Li-Po battery. In order to perform Firmware upgrade or WiFi configuration, the board must be connected through USB port.  
- Once connected to PC, a mass storage drive icon by the name **CURIOSITY** will appear.  
<img src = "images/hardware_setup.png" width="530" height="290" align="middle">  

### 2. Running the Demo
- Open the drive and click open the CLICK-ME.HTM file to launch the Google IoT cloud landing page.
- In the landing page, enter Wi-Fi credentials (SSID, Password, security type) and download WIFI.CFG file.
- Drag & Drop the downloaded WIFI.CFG onto the CURIOSITY drive to set the Wi-Fi credentials.
- If the Wi-Fi network is active, then the SAM-IoT WG Development board establishes connectivity with the Wi-Fi network and securely connects to the Google IoT cloud.
- After successful connection, the SAM-IoT WG Development board pushes the real time light and temperature sensors data to the landing page.

### 3. Firmware upgrade and WiFi configuration process
  - #### Firmware upgrade through Drag & Drop
- Download the latest version of hex file from the [hex folder](./hex). Drag & Drop the downloaded .hex file onto the CURIOSITY drive.
- This will automatically program the microcontroller with the supplied .hex file. There is no need to open the MPLABX IDE to program the .hex file through Drag & Drop method.
  - #### Firmware upgrade through MPLABX IDE
- This method is usually followed by most of the developers to program the .hex file from MPLABX IDE environment.
  - #### WiFi configuration through Drag & Drop
- This is nothing but the WIFI.CFG Drag & Drop method discussed in the previous section.	 
  - #### WiFi configuration through CLI
- Open a terminal application on the host PC for the virtual COM port of connected SAM-IoT WG Development board, with 9600-8-None-1 settings
- Just enter the below command to set the Wi-Fi credentials.<br>
		**`wifi <SSID>,<PASSWORD>,<SECURITY TYPE>`**

## Reference:
- For more details on the application usage, functionality and other details, refer to the [SAM-IoT WG Development Board User Guide](https://github.com/MicrochipTech/MPLAB-Harmony-Reference-Apps/releases/latest/download/SAM_IoT_WG_Development_Board_User_Guide.pdf)

## Comments:
- This application demo builds and works out of box by following the instructions above in "Running the Demo" section. If you need to enhance/customize this application demo, you need to use the MPLAB Harmony v3 Software framework. Refer links below to setup and build your applications using MPLAB Harmony.
	- [How to Setup MPLAB Harmony v3 Software Development Framework](https://www.microchip.com/mymicrochip/filehandler.aspx?ddocname=en1000821)
	- [How to Build an Application by Adding a New PLIB, Driver, or Middleware to an Existing MPLAB Harmony v3 Project](http://ww1.microchip.com/downloads/en/DeviceDoc/How_to_Build_Application_Adding_PLIB_%20Driver_or_Middleware%20_to_MPLAB_Harmony_v3Project_DS90003253A.pdf)  

### Revision:
- v1.3.0 - Supported with harmony based crypto and bug fixes
- v1.2.0 - Regenerated and tested application.
- v1.1.0 released demo application
