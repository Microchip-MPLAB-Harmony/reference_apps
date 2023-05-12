---
grand_parent: 32-bit MPU Reference Applications
parent: SAM9x60 Curiosity Development Board
title: Graphics Getting Started
nav_order: 1
---

<img src = "images/microchip_logo.png">

<img src = "images/microchip_mplab_harmony_logo_small.png">

# Graphics Getting Started  Application on SAM9X60 Curiosity Development Board
<h2 align="center"> <a href="https://github.com/Microchip-MPLAB-Harmony/reference_apps/releases/latest/download/sam9x60_cu_graphics_getting_started.zip" > Download </a> </h2>

-----
## Description

>  This graphics application demonstrates how to display the Microchip Graphics Quick Start project template to the Maxtouch 5-inch display on the SAM9X60 Curiosity Development board.

## Key Highlights of [SAM9X60 Curiosity Development Board](https://www.microchip.com/en-us/development-tool/EV40E67A):

* LCD Interface.
* External Non-Volatile Memories like NAND, SD, and MicroSD card interfaces.
* Additional sensors can be interfaced using "click boards" through an on-board [mikroBUS connector](https://www.mikroe.com/click).
* Two mechanical programmable buttons.
* One User Input Switch and one RGB LED.
* UART, USB and CAN Interfaces.
* Raspberry pi connectors.


## Modules/Technology Used:

- Peripheral Modules
    - Flexcom
    - LCDC Interface
    - TC0 (TWI/I2C)
    - MAXTOUCH Controller interface  <br>
<img src = "images/project_graph.png" align="middle">

## Hardware Used:  

- [SAM9X60 Curiosity development board](https://www.microchip.com/en-us/development-tool/EV40E67A)
- [High-Performance WVGA LCD Display Module with maXTouch ® Technology](https://www.microchip.com/en-us/development-tool/AC320005-5)
- Micro SD Card

## Software/Tools Used:
- [MPLAB® X IDE](https://microchipdeveloper.com/mplabx:installation)
- [MPLAB® XC32 Compiler](https://microchipdeveloper.com/install:xc32)
- [MPLAB® Code Configurator (MCC)](https://microchipdeveloper.com/install:mcc)

<span style="color:blue"> This project has been verified to work with the following versions of software tools:</span>

Refer [Project Manifest](./firmware/src/config/lcdc_rgba8888_mxt_9x60_wvga/harmony-manifest-success.yml) present in harmony-manifest-success.yml under the project folder *firmware/src/config/lcdc_rgba8888_mxt_9x60_wvga* to know the **MPLAB® X IDE**, **MCC** Plugin, **libraries**  version

## Hardware Setup : <span id="Setup1"><span>
- Connect the ribbon cable from the display to the J13 connector of the SAM9X60 Curiosity Development Board.
- Power up the board by connecting the USB cable to the USB port J1 on the SAM9X60 curiosity development board.
- Connect external debugger to J12.    <br>
 
<img src = "images/hardware_setup1.png">

## Developing a graphics getting started demo
<details>
  <summary><B>Details</B></summary>
- Launch MPLAB® X IDE- From the main menu, click on File, then New Project. Under "Projects" choose `32-bit MCC  Harmony Project`, click Next- For `Framework Path` choose the location on your PC where you want to download the Harmony 3 framework- Click Next.  <br>
<img src = "images/step1.png"> <br>
<img src = "images/step2.png">  <br>
- Enter `Location` , `Folder` and `Name` of the project. Click Next.  <br>
<img src = "images/step3.png">  <br>
- In the `Configuration Settings` window, for `Name`  enter `lcdc_rgba8888_mxt_9x60_wvga`, for `Device Family` select `SAM`, for `Target Device` select `SAM9X60D1G`. Click Finish.  <br>  
This creates an empty project and set this project as `main project` if there are other projects open in the project explorer window.  <br>
<img src = "images/step4.png">  <br>
- From main menu, click on `Tools` -> `Embedded` -> `MPLAB® Code Configurator` or click MCC button in the MPLAB® X IDE tool bar. It will launch Content manger Wizard. Then select MPLAB® Harmony.  <br>
<img src = "images/step5.png">  <br>
- In addition to the required packages, download the optional packages gfx_sam9x60, bsp, csp, core, gfx, dev_packs  and then click Finish. Content download will take some time. Please wait till all the contents are downloaded.  <br>
<img src = "images/step7.png">  <br>
- Now project graph will be displayed. From device resource add `Board Support Packages`  for `SAM9X60 Curiosity Kit BSP` to `Project Graph`.  <br>
<img src = "images/step8.png">  <br>
- From device resource add Graphics -> Templates -> `Legato Graphics w/PDA TM5000 Display` to `Project Graph`. You will be prompted to allow auto-connection and auto-activation  of several components- Click on Yes for all of them except “FreeRTOS".  <br>
<img src = "images/step9.png">  <br>
- Choosing the `Legato Graphics w/PDA TM5000 Display` template automatically populates rest of the project components. This can be seen in the way the project graph is setup and connected.  <br>
- In the project graph, click on `Flexcom6`. In the `Configuration Options` window, select clock speed as 100,000 (100KHz).    <br>
<img src = "images/step10.png">  <br>
- In the project graph, click on `LE LCDC Driver`. In the `Configuration Options` window, select output color mode  as 18BPP.  <br>
<img src = "images/step11.png">  <br>
- From the project graph window, plugins menu select `Pin Configuration`.  <br>
<img src = "images/step12.png">  <br>
- You can see that PA30 and PA31 are set to FLEXCOM6. Enable pullups for those pins. Ensure  all the pins are configured as below:  <br>
<img src = "images/step13.png">  <br>
- Now Save all. Then click generate code. This will generate code for all the peripherals that have been added in the project graph.  <br>
<img src = "images/step14.png">  <br>
- Now let us use Microchip Graphics Composer(MGC) to design the graphics to be displayed on the LCD screen and generate the legato library. From the Project graph -> plugin, launch Legato Graphics Composer. (From next software update, this plugin will be renamed to Microchip Graphics Composer)  <br>
<img src = "images/step15.png">  <br>
- From the window that pops-up, click on `Create a new project` using the new project wizard.  <br>
<img src = "images/step16.png">  <br>
- In the `Display Configuration` window, choose `WVGA (800x480)` for `Presets` and click on Apply. You will see that the Width and Height are updated. Click Next.  <br>
<img src = "images/step17.png">  <br>
- For `Color Mode` -> select RGBA_8888. Click Next. For `Memory Profile` -> select `MPU`. Click Next. In the `Project Template` window, select the `Start with a basic quickstart project template` checkbox. Click Next. Click Finish  <br>
- You will see the following screen generated by the composer.  <br>
<img src = "images/step18.png">  <br>
- After the graphics display is composed, you can generate the design files by clicking the `Generate Code` from the File option in the main menu .  <br>
<img src = "images/step19.png">  <br>
- You can save the design files by clicking on File from the main menu and selecting `Save As`. Provide a filename with <configuration_name>_design and save it in the <configuration folder>( That way the next time MGC is launched, the design file is automatically opened) and click Save.  <br>
<img src = "images/step20.png">  <br>
- You can now exit Microchip Graphics Composer by clicking on Exit from File option in the main menu.  <br>
- From MCC, click on Generate Code. This will generate code for the quickstart template designed using Microchip Graphics Composer.  <br>
<img src = "images/step14.png">  <br>
- Lastly change the following code. In Legato -> renderer -> legato_renderer.c, add proper section for no cache attribute as shown below:  <br>
The `.region_nocache` memory location is defined in the linker file and lets the linker know which memory region is to be used for scratch buffers.  <br>
<img src = "images/step24.png">  <br>
- Now right click on the project and click `Properties`. For `Connected Hardware Tool` -> select connected hardware debugger used, for `Compiler Toolchain` -> select XC32 and click Apply.  <br>
<img src = "images/step25.png">  <br>
- From J-32 , `Option categories` choose `Communication` and for `JTAG Method`, select `4-wire JTAG`.  <br>
<img src = "images/step21.png">  <br>
- Select Bootstrap for Categories and select the `Use Bootstrap` checkbox. For `bootstrap file` -> select the at91bootstrap elf file from [here](./firmware/sam9x60_cu.X/)- Click on Apply and OK.  <br>
<img src = "images/step22.png">  <br>
- Clean and build the project. You should see a message on the output console that the project was successfully built. This completes the development of the basic graphics quickstart getting started  application.  <br>
</details>  

## Debugging Application Project on MPLAB® X IDE:  
- Open the project (sam9x60_cu_graphics_getting_started/firmware/sam9x60_cu.X) in MPLAB® X IDE.  
- Ensure "SAM9X60D1G" is selected as hardware tool to program/debug the application.  
- Build the code and Debug the code by clicking on the "Debug" button in MPLAB® X IDE tool bar.   
- Run the application by clicking "run" button in MPLAB® X IDE tool bar.  
- Now the below legato quickstart template application will get displayed on the LCD connected with SAM9X60 Curiosity development board.  

<img src = "images/step26.png">  

## Running the pre-built harmony application from SD Card:
The pre-built application bin file can be programmed by following the below steps

### Steps to program the bin file on SD card
- Take a micro-SD Card formatted with FAT32 file system.  
- Copy the boot.bin and harmony.bin files from this [location](./hex) to the micro-SD card using your PC.  
- Insert the SD card to J3 on the SAM9X60 Curiosity development board.  

### Steps to run the bin file from SD card 
- Press the reset button.
- It will display the  below graphics getting started demo -a legato quickstart template application on the display connected with SAM9X60 Curiosity development board.

<img src = "images/step26.png">

## Comments:
- This application demo builds and works out of box by following the instructions above in "Running the Demo" section- If you need to enhance/customize this application demo, you need to use the MPLAB® Harmony v3 Software framework- Refer links below to setup and build your applications using MPLAB® Harmony.
    - [How to Setup MPLAB® Harmony v3 Software Development Framework](https://ww1.microchip.com/downloads/en/DeviceDoc/How_to_Setup_MPLAB_%20Harmony_v3_Software_Development_Framework_DS90003232C.pdf)
    - [How to Build an Application by Adding a New PLIB, Driver, or Middleware to an Existing MPLAB® Harmony v3 Project](https://microchipdeveloper.com/32mpu:sam9x60-ek-h3-csp-app)
	- [Click Here for more graphics demos](https://github.com/Microchip-MPLAB-Harmony/gfx_apps_sam_9x60)  
    - <span style="color:blue"> **MPLAB® Harmony v3 is also configurable through MPLAB® Code Configurator (MCC)- Refer to the below links for specific instructions to use MPLAB® Harmony v3 with MCC.**</span>
    - [Getting Started with MPLAB® Harmony v3 Using MPLAB® Code Configurator](https://www.youtube.com/watch?v=KdhltTWaDp0)
    - [MPLAB® Code Configurator Content Manager for MPLAB® Harmony v3 Projects](https://www.youtube.com/watch?v=PRewTzrI3iE)

## Revision:
- v1.6.0 - Released demo application
