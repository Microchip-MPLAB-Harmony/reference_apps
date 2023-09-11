---
grand_parent: 32-bit MCU Reference Applications
parent: SAM L11 Xplained Pro Evaluation Kit
title: TrustZone Getting Started on SAM L11
nav_order: 1
---
<img src = "images/microchip_logo.png">
<img src = "images/microchip_mplab_harmony_logo_small.png">

# TrustZone Getting Started Application on SAM L11 Xplained Pro Evaluation Kit
<h2 align="center"> <a href="https://github.com/Microchip-MPLAB-Harmony/reference_apps/releases/latest/download/saml11_trustzone_getting_started.zip" > Download </a> </h2>


-----
## Description


> This Application demonstrates the TrustZone feature on SAM L11 microcontroller (MCU). The application has two projects pertaining to Secure and Non-Secure modes of SAM L11, that work together on the same MCU and offers security isolation between the trusted and the non-trusted resources in the device.

- The Secure mode application reads the current room temperature from the temperature sensor on the I/O1 Xplained Pro
  Extension Kit every 500 milliseconds. Further, the application writes the temperature readings to EEPROM and reads
  when a request received from the Non-secure mode application. Also, an LED (LED0) is toggled every time the temperature
  is displayed on the serial console. The periodicity of the temperature values reading can be changed to 1 second, 2 seconds,
  4 seconds, and back to 500 milliseconds every time when the user presses the switch SW0 on the SAM L11 Xplained Pro Evaluation Kit.
  The temperature readings are transferred to Non-secure mode application when it requests to Secure application through
  Non Secure Callable (NSC).

- The Non-secure mode application requests the Secure mode application temperature values and prints them on a serial
  console once it receives from the Secure mode application. Further,  when it receives a request from the user (in the
  form of a key press on the serial console), it will request Secure mode application to retrieve the last five stored
  temperature values in the EEPROM. The Non-secure application prints the last five stored temperature values on the console.

## Modules/Technology Used:

- Peripheral Modules
	- Secure PORT Pins (All pins by default are secure)
	- Secure I2C
	- Secure RTC
	- Secure EIC
	- Non-secure USART
	- Non-secure DMAC
	- Non-secure PORT Pins (USART Pins only)

## Hardware Used:

- [SAM L11 Xplained Pro Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/dm320205)
- [I/O1 Xplained Pro Extension Kit](https://www.microchip.com/Developmenttools/ProductDetails/ATIO1-XPRO)

## Software/Tools Used:
<span style="color:blue"> This project has been verified to work with the following versions of software tools:</span>  

Refer Manifest for [Secure](./firmware/Secure/firmware/src/config/sam_l11_xpro/harmony-manifest-success.yml) and [NonSecure](./firmware/NonSecure/firmware/src/config/sam_l11_xpro/harmony-manifest-success.yml) projects present in harmony-manifest-success.yml under the project folder *firmware/{Secure or NonSecure}/firmware/src/config/sam_l11_xpro*
- Refer the [Release Notes](../../../release_notes.md#development-tools) to know the **MPLAB X IDE** and **MCC** Plugin version. Alternatively, [Click Here](https://github.com/Microchip-MPLAB-Harmony/reference_apps/blob/master/release_notes.md#development-tools).  
- Any Serial Terminal application like Tera Term terminal application.

<span style="color:blue"> Because Microchip regularly update tools, occasionally issue(s) could be discovered while using the newer versions of the tools. If the project doesn’t seem to work and version incompatibility is suspected, It is recommended to double-check and use the same versions that the project was tested with. </span> To download original version of MPLAB Harmony v3 packages, refer to document [How to Use the MPLAB Harmony v3 Project Manifest Feature](https://ww1.microchip.com/downloads/en/DeviceDoc/How-to-Use-the-MPLAB-Harmony-v3-Project-Manifest-Feature-DS90003305.pdf)

## Setup:
- Connect the I/O1 Xplained Pro Extension Kit to the Extension Header 1 (EXT1) of the SAM L11 Xplained Pro Evaluation Kit
- The SAM L11 Xplained Pro Evaluation Kit allows the Embedded Debugger (EDBG) to be used for debugging. Connect the Type-A male to micro-B USB cable to the micro-B DEBUG USB port to power and debug the SAM L11 Xplained Pro Evaluation Kit.

  <img src = "images/hardware_setup.jpg" width="600" height="650">

### Hardware Modification:
- IO1 Xplained Pro features Microchip’s AT30TSE758 temperature sensor chip with an 8 kbit serial EEPROM.
	  The temperature sensor has two TWI addresses: one for the temperature sensor and one for the EEPROM.
	  The A2 address line of TWI must be soldered to 0. This is done to modify the address of the EEPROM
	  on the I/O1 Xplained Pro Extension Kit so that it does not conflict with the address of EEPROM on
	  SAM E70 Xplained Evaluation Kit. The modification changes the address of temperature sensor to 0x4B
	  and EEPROM to 0x50. These modified addresses are used in this demo application.  
    <img src = "images/hardware_modification.png" width="300" height="200" align="middle">

## Programming hex file:
The pre-built hex file can be programmed by following the below steps

### Steps to program the hex file
- Open MPLAB X IDE
- Close all existing projects in IDE, if any project is opened
- Go to File -> Import -> Hex/ELF File
- In the "Import Image File" window, Step 1 - Create Prebuilt Project, click the "Browse" button to select the prebuilt hex file.
- Select Device has "ATSAML11E16A"
- Ensure the proper tool is selected under "Hardware Tool"
- Click on "Next" button
- In the "Import Image File" window, Step 2 - Select Project Name and Folder, select appropriate project name and folder
- Click on "Finish" button
- In MPLAB X IDE, click on "Make and Program Device" Button. The device gets programmed in sometime.
- Follow the steps in "Running the Demo" section below

## Programming/Debugging Application Project:
- The Trustzone project can be opened in two ways.  
  - Procedure 1:
	- Open MPLAB X IDE
	- Close all existing projects in IDE (if any project is opened)
	- Go to File -> Open Project
	- Select project path "../reference_apps/apps/sam_l11_xpro/saml11_trustzone_getting_started"
	- Select "firmware" folder, enable "Open Required Projects" and click on "Open Project" button  
    <img src = "images/group_project_path.png" width="700" height="400" align="middle">  

	  <img src = "images/opened_group_project.png" width="700" height="500" align="middle">  

	- Once the project opens, set the "trustzone_sam_l11_xpro_NonSecure" project as Main Project by right clicking on the project.  
	<img src = "images/set_as_main_project.png" width="500" height="600" align="middle">
  - Procedure 2:
	- Open MPLAB X IDE
	- Close all existing projects in IDE (if any project is opened)
	- Open the project (../saml11_trustzone_getting_started/firmware/NonSecure/firmware/sam_l11_xpro_NonSecure.X) in MPLAB X IDE.  
    <img src = "images/opened_non_secure_project.png" width="700" height="500" align="middle">      
- Ensure "SAML11 Xplained Pro" is selected as hardware tool to program/debug the application.
- Build the code and program the device by clicking on the "Make and Program Device" button in MPLAB X IDE tool bar
- Follow the steps in "Running the Demo" section below.  

## Running the Demo:
- Open the Tera Term terminal application on your PC (from the Windows® Start menu by pressing the Start button)
- Change the baud rate to 115200
- You should see the temperature values (in °F) being displayed on the terminal every 500 milliseconds, as shown below  

  <img src = "images/result1.png" width="425" height="235" align="middle">  
- Also, notice the LED0 blinking at 500 millisecond rate
- You may vary the temperature by placing your finger on the temperature sensor (for a few seconds)  
<img src = "images/temp_sensor_placement.png" width="600" height="650" align="middle">  
- Press the switch SW0 on SAM L11 Xplained Pro Evaluation Kit to change the default sampling rate to 1 second.  
  <img src = "images/user_button_placement.png" width="600" height="650" align="middle">  
  <img src = "images/result2.png" width="345" height="165" align="middle">  
- Every subsequent pressing of switch SW0 on SAM L11 Xplained Pro Evaluation Kit changes the default sampling
  rate to 2 seconds, 4 seconds, and 500 ms and back to 1 second in cyclic order as shown below.  
  <img src = "images/result3.png" width="315" height="440" align="middle">  
- While the temperature sampling rate changes on every switch SW0 press, notice the LED0 toggling at the same sampling rate
- Press any character on the terminal to display the last five values written to the EEPROM  
<img src = "images/eeprom_values_display.png" width="600" height="285" align="middle">  

## Comments:
- Reference Training Module: [Arm TrustZone Getting Started Application on SAM L11 MCUs](https://microchipdeveloper.com/harmony3:saml11-trustzone-getting-started-training-module)
- This application demo builds and works out of box by following the instructions above in "Running the Demo" section. If you need to enhance/customize this application demo, you need to use the MPLAB Harmony v3 Software framework. Refer links below to setup and build your applications using MPLAB Harmony.
	- [How to Setup MPLAB Harmony v3 Software Development Framework](https://ww1.microchip.com/downloads/en/DeviceDoc/How_to_Setup_MPLAB_%20Harmony_v3_Software_Development_Framework_DS90003232C.pdf)
	- [How to Build an Application by Adding a New PLIB, Driver, or Middleware to an Existing MPLAB Harmony v3 Project](http://ww1.microchip.com/downloads/en/DeviceDoc/How_to_Build_Application_Adding_PLIB_%20Driver_or_Middleware%20_to_MPLAB_Harmony_v3Project_DS90003253A.pdf)  
	- <span style="color:blue"> **MPLAB Harmony v3 is also configurable through MPLAB Code Configurator (MCC). Refer to the below links for specific instructions to use MPLAB Harmony v3 with MCC.**</span>
		- [Create a new MPLAB Harmony v3 project using MCC](https://microchipdeveloper.com/harmony3:getting-started-training-module-using-mcc)
		- [Update and Configure an Existing MHC-based MPLAB Harmony v3 Project to MCC-based Project](https://microchipdeveloper.com/harmony3:update-and-configure-existing-mhc-proj-to-mcc-proj)
		- [Getting Started with MPLAB Harmony v3 Using MPLAB Code Configurator](https://www.youtube.com/watch?v=KdhltTWaDp0)
		- [MPLAB Code Configurator Content Manager for MPLAB Harmony v3 Projects](https://www.youtube.com/watch?v=PRewTzrI3iE)


## Revision:
- v1.6.0 - Regenerated and Tested the application.
- v1.5.0 - Removed MHC support, regenerated and tested application.
- v1.4.0 - Added MCC support, regenerated and tested application.
- v1.3.0 - Regenerated and tested application.
- v1.2.0 - Regenerated and tested application.
- v1.1.0 - Released demo application
