---
grand_parent: 32-bit MCU Reference Applications
parent: PIC32MK MCM Control Board
title: Multi Motor FOC
nav_order: 1
---

<img src = "images/microchip_logo.png">
<img src = "images/microchip_mplab_harmony_logo_small.png">



# Encoder-based Field Oriented Control for Three Permanent Magnet Synchronous Motors on PIC32MK MCM Multi-Motor Control Platform
<h2 align="center"> <a href="https://github.com/Microchip-MPLAB-Harmony/reference_apps/releases/latest/download/pic32mk_mcm_multi_motor_foc.zip"> Download </a> </h2>

---

## Description:

The application implements an encoder-based Field Oriented Control (FOC) for up to three Permanent Magnet Synchronous Motors (PMSMs) on PIC32MK MCM multi-motor control platform. The key features include:
- Quadrature encoder signal and HALL signal based FOC for each PMSM.
- Easily configurable PMSM parameters, the number of PMSM to drive, and PWM period.
- PI gains can be automatically calculated by the SW.
- Alternative HALL-based start-up or alignment start-up.
- Alternative rotor angle HALL-based calibration, index-capture-based calibration, or index-reset-based calibration.


## Modules/Technology Used:
- Peripheral Modules
    - ADC
    - PWM
    - UART
- Driver Modules
    - X2C (virtual oscilloscope support driver) 


## Hardware Used:
- [Hurst motor DMA0204024B101](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNo/AC300022)
- [MCP2200 isolated USB to UART demo board](https://www.microchip.com/en-us/development-tool/adm00276)
- DC 24V power supply
- (PIC32MK MCM multi-motor) control board (version 2.0) 
- (Multi-motor) driver board (version 2.0)  
 
<span style="color:blue"> *Please contact Microchip sales for details on procuring the control board and driver board*</span>



## Software/Tools Used:
<span style="color:blue"> This project has been verified to work with the following versions of software tools:</span>

Refer [Project Manifest](./firmware/src/config/mclv2_pic32_mk_mcm_pim/harmony-manifest-success.yml) present in harmony-manifest-success.yml under the project folder *firmware/src/config/mclv2_pic32_mk_mcm_pim*
- Refer the [Release Notes](../../../release_notes.md#development-tools) to know the **MPLAB X IDE** and **MCC** Plugin version. Alternatively, [Click Here](https://github.com/Microchip-MPLAB-Harmony/reference_apps/blob/master/release_notes.md#development-tools)
- Any Serial Terminal application like Tera Term terminal application.




<span style="color:blue"> Because Microchip regularly update tools, occasionally issue(s) could be discovered while using the newer versions of the tools. If the project doesn’t seem to work and version incompatibility is suspected, It is recommended to double-check and use the same versions that the project was tested with. </span> To download original version of MPLAB Harmony v3 packages, refer to document [How to Use the MPLAB Harmony v3 Project Manifest Feature](https://ww1.microchip.com/downloads/en/DeviceDoc/How-to-Use-the-MPLAB-Harmony-v3-Project-Manifest-Feature-DS90003305.pdf)

## Hardware Setup
- Control board configuration
    - Short jumpers J4, J6. This is necessary for the DC/DC converter on the board to work properly.
    - Short jumpers J28, J29, J30, J34, J35, J36, J40, J41, J42. This is necessary for the board to receive quadrature encoded signals from the Hurst motors.
- Connection
    - Plug the DC power into the connector CN1 or CN2 on each driver board.
    - Plug the motor power lines into the connector CON1 on each driver board.
    - Plug each driver board into the connector J13, J14, J15 on the PIC32MK MCM control board.
    - Connect position sensor pins of each motor with the connector CN1, CN2, CN3 respectively on the control board.

## Software configurations
- Open files hal_motor_channel_x.h, where x equals 1, 2, 3. The macros of motor parameters are defined in the files.
- For the Hurst motor, the macros are already configured properly. However, make sure that the macro LONG_HURST is defined. 

## Programming
- Connect ICD4 with the connector P1 on the control board.
- Power on.
- Make sure that the LEDs D1, D2, D3 are all on, indicating the 12V, 5V, 3.3V are being supplied.
- Open the demo project( pic32mk_mcm_ multi_motor_foc/firmware/pic32mk_mcm_control_board.X) in MPLAB X IDE and set it as the main project.
- Click "make and program device main project".

## Running/Tuning The Demo 
- To start the motor, click the SWx button on the control board, where x equals 1, 2, 3.
- The motor shall spin after the click. Otherwise, power off and check the hardware setup, then power on.
- To change the speed reference, spin the POTx potentiometer on the control board. Observe the speed of the motor, it shall change according to the angle position of the potentiometer.
- To stop the motor, click the SWx Button again.
- Power off.

# Comments:
- This application demo builds and works out of box by following the instructions above in "Running the Demo" section. If you need to enhance/customize this application demo, you need to use the MPLAB Harmony v3 Software framework. Refer links below to setup and build your applications using MPLAB Harmony.
	- [How to Setup MPLAB Harmony v3 Software Development Framework](https://ww1.microchip.com/downloads/en/DeviceDoc/How_to_Setup_MPLAB_%20Harmony_v3_Software_Development_Framework_DS90003232C.pdf)
	- [How to Build an Application by Adding a New PLIB, Driver, or Middleware to an Existing MPLAB Harmony v3 Project](http://ww1.microchip.com/downloads/en/DeviceDoc/How_to_Build_Application_Adding_PLIB_%20Driver_or_Middleware%20_to_MPLAB_Harmony_v3Project_DS90003253A.pdf)
	- <span style="color:blue"> **MPLAB Harmony v3 is also configurable through MPLAB Code Configurator (MCC). Refer to the below links for specific instructions to use MPLAB Harmony v3 with MCC.**</span>
		- [Create a new MPLAB Harmony v3 project using MCC](https://microchipdeveloper.com/harmony3:getting-started-training-module-using-mcc)
		- [Update and Configure an Existing MHC-based MPLAB Harmony v3 Project to MCC-based Project](https://microchipdeveloper.com/harmony3:update-and-configure-existing-mhc-proj-to-mcc-proj)
		- [Getting Started with MPLAB Harmony v3 Using MPLAB Code Configurator](https://www.youtube.com/watch?v=KdhltTWaDp0)
		- [MPLAB Code Configurator Content Manager for MPLAB Harmony v3 Projects](https://www.youtube.com/watch?v=PRewTzrI3iE)    

## Revision:
- v1.7.0 - Released demo application