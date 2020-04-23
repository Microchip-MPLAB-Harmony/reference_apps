
![Microchip logo](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_logo.png)
![Harmony logo small](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_mplab_harmony_logo_small.png)
# WiFi based RGB LED Control Application on Curiosity PIC32MZ EF 2.0 Development Board
-----
## Description:

>  The WiFi RGB Easy Configuration demo showcases how to configure an embedded WiFi device that does not have a
    natural keyboard and screen. By using the internal Web server that accompanies the Microchip TCP/IP stack,
    end-users can use their browser to control the RGB(RedGreenBlue) Led.

> The Curiosity PIC32MZ EF 2.0 Development Board provides an XPRO connector. The XPRO connector is plugged with the
    ATWINC1500-XPRO board to configure WiFi connectivity. Also, the demo features changing the color of the on-board
    RGB LED using the webpage hosted by the Curiosity board.
    

## Modules/Technology Used:

- Peripheral Modules      
	- Output compare
	- Core Timer
	- NVM
- Driver Modules	
	- Memory Driver
- Middleware Libraries
	- TCP/IP Stack
- System Service Libraries	
	- File System	
	- SYS Console	
	- SYS Command
- STDIO Library
- WINC1500 Driver

## Hardware Used:

- [Curiosity PIC32MZ EF 2.0 Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320209)   
- [ATWINC1500-XPRO](https://www.microchip.com/DevelopmentTools/ProductDetails/ATWINC1500-XPRO)


## Software/Tools Used:
<span style="color:blue"> *This project has been verified to work with the following versions of software tools:*</span>  
 - [MPLAB Harmony v3 "csp" repo v3.5.2](https://github.com/Microchip-MPLAB-Harmony/csp/releases/tag/v3.5.2)
 - [MPLAB Harmony v3 "core" repo v3.5.2](https://github.com/Microchip-MPLAB-Harmony/core/releases/tag/v3.5.2)          
 - [MPLAB Harmony v3 "dev_packs" repo v3.5.0](https://github.com/Microchip-MPLAB-Harmony/dev_packs/releases/tag/v3.5.0)  
 - [MPLAB Harmony v3 "mhc" repo v3.3.3](https://github.com/Microchip-MPLAB-Harmony/mhc/releases/tag/v3.3.3)   
 - [MPLAB Harmony v3 "bsp" repository v3.5.0](https://github.com/Microchip-MPLAB-Harmony/bsp/releases/tag/v3.5.0)
 - [MPLAB Harmony v3 "wireless" repo v3.0.0](https://github.com/Microchip-MPLAB-Harmony/wireless/releases/tag/v3.0.0)
 - [MPLAB Harmony v3 "net" repo v3.5.1](https://github.com/Microchip-MPLAB-Harmony/net/releases/tag/v3.5.1)
 - MPLAB Harmony Configurator Plugin v3.4.0
 - [MPLAB X IDE v5.30](https://www.microchip.com/mplab/mplab-x-ide)
 - [MPLAB XC32 Compiler v2.30](https://www.microchip.com/mplab/compilers)
 - [MPLAB X IPE v5.30](https://www.microchip.com/mplab/mplab-integrated-programming-environment)  
 <span style="color:blue"> *Because Microchip regularly update tools, occasionally issue(s) could be discovered while using the newer versions of the tools. If the project doesn’t seem to work and version incompatibility is suspected, It is recommend to double-check and use the same versions that the project was tested with.* </span> 

## Setup:
 - Connect ATWINC1500-XPRO to Extension header (J501) on Curiosity PIC32MZ EF 2.0 Development Board
 - Power the Curiosity PIC32MZ EF 2.0 Development Board from a Host PC through a Type-A male to micro-B USB cable connected to Micro-B port (J700)  
<img src = "images/wifi_rgb_easy_configuration_demo_setup.png" width="650" height="300" align="middle">

## Programming binary/hex file:
- If you are not interested in installing development tools. The pre-built binary/hex file can be programmed to the target
	### Steps to program the hex file using MPLAB X IPE
	- Open MPLAB X IPE
	- Select Device has "PIC32MZ2048EFM144"
	- Power the Curiosity PIC32MZ EF 2.0 Development Board from a Host PC through a Type-A male to Micro-B USB cable connected to Micro-B port (J105)
	- Once Power cable is connected, "Curiosity/Starter Kits PKOB4" hardware tool is identified as a programmer
	- Browse to hex file (wifi_rgb_easy_configuration_hex_file.hex)
	- Click on program button. The device gets programmed in sometime
	- Follow the steps in "Running the Demo" section below

## Programming/Debugging Application Project:
- Open the project (wifi_rgb_easy_configuration\firmware\pic32mz_ef_curiosity_v2.X) in MPLAB X IDE
- Ensure "Curiosity/Starter Kits PKOB4" is selected as hardware tool to program/debug the application
- Build the code and program the device by clicking on the "make and program" button in MPLAB X IDE tool bar
- Follow the steps in "Running the Demo" section below

## Running the Demo:
- Open Tera Term, connect to serial console. If there is any connection issue on tera terminal, unplug the USB cable connected to Micro-B port, and reconnect it back.
- Change the baud rate to 115200
- Perform a reset by pressing the "RESET" switch
- The serial terminal displays the below message  
"TCP/IP Stack: Initialization Started  
TCP/IP Stack: Initialization Ended - success  
SYS_Initialize: The MPFS2 File System is mounted  
Interface WINC on host MCHPBOARD_W     - NBNS enabled  
WINC IP Address: 192.168.1.1"  
- When the demonstration runs, the WINC1500 goes into SoftAP mode (it behaves as an access point) and displays itself as "MCHPSoftAP" network		
- From a smartphone or personal computer, connect to the "MCHPSoftAP" network, which is the SoftAP network started by the demonstration. Then, bring up a web page by entering the IP address(e.g., 192.168.1.1) of the SoftAP network into the smartphone browser
- When the web page is displayed, On the right top corner of the page, there is a widget through which you can change the color of the RGB LED on the Curiosity board
- Click the text box to display a pop-up for selecting the color of the RGB LED. Click the Submit button to set the color of the RGB LED on the Curiosity board


## Comments:
- While formatting the SD card, change allocation unit size to 32K. This helps in reading the contents of the SD card faster.  
(To change allocation unit size, Right click on Drive > Select Format > change Allocation unit size)
- This application is developed by applying a patch (available in folder "wifi_rgb_easy_configuration\firmware\wifi_repo_patch") to MPLAB Harmony v3 "wireless" repository. 
If you need to reconfigure or regenerate this demo using MHC, please refer the "Notes.txt" file under "wifi_rgb_easy_configuration\firmware\wifi_repo_patch" folder.
- This application demo builds and works out of box by following the instructions above in "Running the Demo" section. If you need to enhance/customize this application demo, you need to use the MPLAB Harmony v3 Software framework. Refer links below to setup and build your applications using MPLAB Harmony. 
	- [How to Setup MPLAB Harmony v3 Software Development Framework](https://www.microchip.com/mymicrochip/filehandler.aspx?ddocname=en1000821) 
	- [How to Build an Application by Adding a New PLIB, Driver, or Middleware to an Existing MPLAB Harmony v3 Project](http://ww1.microchip.com/downloads/en/DeviceDoc/How_to_Build_Application_Adding_PLIB_%20Driver_or_Middleware%20_to_MPLAB_Harmony_v3Project_DS90003253A.pdf)  
- The application is available on MPLAB Harmony v3 GitHub repository [reference_apps](https://github.com/Microchip-MPLAB-Harmony/reference_apps/tree/master/apps/pic32mz_ef_curiosity_v2/wifi_rgb_easy_configuration)
              
## Revision: 
- v1.0 released demo application
