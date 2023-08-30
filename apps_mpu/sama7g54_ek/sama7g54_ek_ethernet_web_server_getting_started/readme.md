---
grand_parent: 32-bit MPU Reference Applications
parent: SAMA7G54-EK Evaluation Kit
title: Ethernet Web Server Getting Started
nav_order: 1
---

<img src = "images/microchip_logo.png">

<img src = "images/microchip_mplab_harmony_logo_small.png">

# Ethernet Web Server Getting Started Application on SAMA7G54-EK Evaluation Kit
<h2 align="center"> <a href="https://github.com/Microchip-MPLAB-Harmony/reference_apps/releases/latest/download/sama7g54_ek_ethernet_web_server_getting_started.zip" > Download </a> </h2>

-----
## Description

>   This application demonstrates the ability of the MPLAB Harmony to configure demo board as TCP IP web server. The demo board configured as web server will host webpage stored in SDCARD. The Webpage will be accessed through IP Address provided in debug window. From the webpage, LEDs on the demo board will be controlled. Temperature is read from the temp sensor on a Thermo 3 Click connected to the board using TWI/I2C protocol. The temperature value is also displayed on the webpage.

## Key Highlights of [SAMA7G54-EK Evaluation Kit](https://www.microchip.com/en-us/development-tool/EV21H18A):

* External Non-Volatile Memories like QSPI, e.MMC and SD card interfaces.
* Additional sensors can be interfaced using "click boards" through an on-board [mikroBUS connector](https://www.mikroe.com/click).
* Two mechanical programmable buttons.
* One User Input Switch and one RGB LED.
* UART, USB and CAN Interfaces.
* Raspberry pi connectors.

<img src = "images/sama7g54_ek.png">

## Modules/Technology Used:

- Peripheral Modules
    - FLEXCOM
    - TC0
    - SDMMC <br>
<img src = "images/project_graph.png" align="middle">

## Hardware Used:  

- [SAMA7G54-EK Evaluation Kit](https://www.microchip.com/en-us/development-tool/EV21H18A).
- SD Card.
- Thermo 3 Click.
- RJ45 Ethernet Cable.

## Jumper Settings:
<img src = "images/jumper_settings.png">

## Software/Tools Used:
- [MPLAB® X IDE](https://microchipdeveloper.com/mplabx:installation).
- [MPLAB® XC32 Compiler](https://microchipdeveloper.com/install:xc32).
- [MPLAB® Code Configurator (MCC)](https://microchipdeveloper.com/install:mcc).

<span style="color:blue"> This project has been verified to work with the following versions of software tools:</span>

Refer [Project Manifest](./firmware/src/config/default/harmony-manifest-success.yml) present in harmony-manifest-success.yml under the project folder *firmware/src/config/default* to know the **MPLAB® X IDE**, **MCC** Plugin, **libraries**  version.

## Hardware Setup: <span id="Setup1"><span>
- Connect RJ45 ethernet cable to the J5 Connector (Gigabit Ethernet port) of SAMA7G54-EK Evaluation Kit and to Router.
- Connect Thermo 3 click board to the J10 connector (mikroBUS socket) of SAMA7G54-EK Evaluation Kit.
- Power up the SAMA7G54-EK Evaluation Kit by connecting 5V/2A power adapter to J1 connector or by connecting micro-usb cable to J7 connector.
- Press the start (nSTART switch) button on the board.
- Connect the UART port (J24) on board to the computer using a micro-usb cable (to enable debug com port).
- Connect external JTAG debugger to J27 or Onboard debugger micro-usb cable to J24. J24 will work as CDC COM Port as well as Onboard debugger.<br>
 
<img src = "images/board.jpg">

## Developing a Ethernet Web Server demo application

<details>
  <summary> Details
</summary> 

1. Open **MPLAB® X IDE** from the main menu.
2. Create a New Project by clicking the New Project icon <img src = "images/step1_1.png"> or by selecting **File** -> **New Project**.
3. In the New Project window, under **Projects:** select **32-Bit MCC Harmony Project** and click **Next**.
<img src = "images/step1.png"> <br>
<img src = "images/step2_1.png"> <br>
 
4. In the Framework Path, enter the path of the folder where you would like to download the Harmony 3 framework packages and Click **Next**.  <br>
<img src = "images/step2.png">  <br>

5. In the **Project Settings** dialog window, fill in or select the information needed for below:<br>
  a. **Location:** Enter a valid path to store the application project.  <br>
  b. **Folder:** Enter Project Folder name. <br>
  c. **Name:** Enter Project Name.  <br>
  d. **Path:** Selecting the above fields auto populates the Path.  <br>
  e. Click **Next** <br>
<img src = "images/step3.png">  <br>

6. In the **Configuration Settings** dialog window, fill in or select the information for below:  
  a. **Name:** Fill configuration name as **default**.<br>
  b. **Device Family:** From drop down list select **SAM**.<br>
  c. **Target Device:** From drop down list select **SAMA7G54**.<br>
  d. Click **Finish**.<br>
<img src = "images/step4.png">  <br>

7. This creates an empty project and set this project as **main project**. If there are other projects open in the project explorer window, set this project as main project by right clicking on the project, choose **Set as Main Project**.  <br>
<img src = "images/step5.png">  <br>

8. Once the project is created, **MCC** will be automatically launched. (To launch **MCC** manually, from main menu, click on **Tools** -> **Embedded** -> **MPLAB® Code Configurator** or click **MCC** button <img src = "images/mcc.png"> in the **MPLAB® X IDE** tool bar.) It will launch Content manger Wizard. Then click **Select MPLAB Harmony**.  <br>
<img src = "images/step6.png">  <br>

9. In addition to the required packages(**csp**,**dev_packs**), download the optional packages **bsp**, **core**, **net**, **wolfssl**  and then click **Finish**. Content download will take some time. Please wait till all the contents are downloaded.  <br>
<img src = "images/step7.png">  <br>
<img src = "images/step7_1.png">  <br>
<img src = "images/step7_3.png">  <br>
<img src = "images/step7_4.png">  <br>

10. Once the download is complete, click **Save** in **Save MCC Configuration file** window.<br>
<img src = "images/step7_2.png">  <br>  

11. Now a project graph will be displayed. From **Device Resources** window, click add button <img src = "images/add.png"> to add Board Support Packages for **SAMA7G5 Evaluation kit BSP** to **Project Graph**.  <br>
<img src = "images/step8.png">  <br>

12. In **Project Graph**, Select **TCP/IP Configuration** from **plugins** drop-down list.
<img src = "images/step9.png">  <br>

13. Now **TCP/IP Configuration** window will be displayed. Click **Application** in TCP/IP Layers on the left side pane. 
<img src = "images/step13.png">  <br>

14. To add **DHCP CLIENT** to **Active Components** window, drag and drop it from **Available Components**. Click **Yes** for adding Harmony Core.<br>
<img src = "images/step14.png">  <br>

15. Click **No** for FreeRTOS component. This example is a Bare metal project.
<img src = "images/step15.png">  <br>

16. **DHCP CLIENT** is moved to **Active Components** window.
<img src = "images/step16.png">  <br>

17. Similarly add **DNS CLIENT**, **HTTPNET SERVER** and **SNTP** to **Active Components** window.<br>
<img src = "images/step17_1.png">  <br>

18. Click **Presentation** in TCP/IP Layers on the left side pane. <br>
<img src = "images/step18_1.png">  <br>
   a. Add **Presentation Layer** to **Active Components** window by dragging and dropping it from **Available Components** window. <br>
<img src = "images/step18_2.png">  <br>

19. Click **Transport** in TCP/IP Layers on the left side pane. <br>
<img src = "images/step18.png">  <br>

20. Add **TCP** to **Active Components** window by dragging and dropping it from **Available Components** window. This will add **Crypto Library** also to the project.<br>
   a. Click **Yes** to add **Crypto Library**. The **wolfCrypt Library** will be added to the project.<br>
<img src = "images/step19_1.png">  <br>
   b. Click **Yes** to add **wolfCrypt Library**.<br>
<img src = "images/step19_2.png">  <br>
   c. Click **Yes** to connect **Crypto Library** and **wolfCrypt Library** in project graph.
<img src = "images/step19_3.png">  <br>
   d. **TCP** added to project. <br>
<img src = "images/step19.png">  <br>

21. Add **UDP** to **Active Components** window by dragging and dropping from **Available Components** window.<br>
<img src = "images/step20.png">  <br>

22. Click **Network** in TCP/IP Layers on the left side pane.
<img src = "images/step21.png">  <br>

23. Add **IPv4**, **ARP** and **ICMPv4** to **Active Components** window by dragging and dropping them from **Available Components** window.<br>
<img src = "images/step22.png">  <br>

24. Click **Data Link** in TCP/IP Layers on the left side pane.<br>
<img src = "images/step23.png">  <br>

25. Click <img src = "images/step24_1.png"> next to **Network Interface** in **Active Components** window to add an Interface. This will add **NETCONFIG-0** to **Network Interface** section in **Active Components** window.<br>
<img src = "images/step24.png">  <br>

26. Add **GMAC0** to **MAC** section in **Active Components** window by dragging and dropping from **MAC Components** window. <br>
<img src = "images/step25.png">  <br>

27. Add **KSZ9131** and **MIIM Driver** to **PHY** section in **Active Components** window by drag and drop from **PHY Components** window. <br>
<img src = "images/step26.png">  <br>

28. Connect **NETCONFIG-0** with **GMAC0** and **GMAC0** with **KSZ9131** in **Active Components** window by clicking and dragging the <img src = "images/step27_1.png"> or <img src = "images/step27_2.png"> button. <br>  
<img src = "images/step27.png">  <br>

29. Click **Basic Config** in TCP/IP Layers on the left side pane.<br>
<img src = "images/step28.png">  <br>

30. Add **TCPIP CMD** to **Active Components** window by dragging and dropping from **Available Components** window.<br>
<img src = "images/step29.png">  <br>

31. Click **Overview** on the left side pane to see the complete configuration.
<img src = "images/step30.png">  <br>

32. Click **Config Summary** on the left side pane to see the summary of configuration. The missing mandatory and optional components will be listed here.
<img src = "images/step31.png">  <br>

33. Add Harmony components listed in **Unsatisfied Dependencies**. <br>
   a. Close **TCP/IP Configuration** window. <br>
   b. In **Project Graph**, Select **Root** in **View:** tab and add all **Unsatisfied Dependencies**. 

34. We need **SDCARD** to store webpages. To access **SDCARD**, we need to enable **SDMMC** module in project. <br>
   a. From **Device Resources** window, expand **Peripherals** and expand **SDMMC** to view **SDMMC** list.
   
35. Click add button <img src = "images/add.png"> to add **SDMMC1** to **Project Graph**.  <br>
<img src = "images/step37.png"> <br>

36. **SDMMC1** added to **Project Graph** window.
<img src = "images/step38.png"> <br>

37. From **Device Resources** window, expand **System Services** to view the list. 
38. Click add button <img src = "images/add.png"> to add **COMMAND**, **DEBUG**, **TIME** and **FILE SYSTEM** to **Project Graph**.  <br>
<img src = "images/step39.png"> <br>

39. **COMMAND**, **DEBUG**, **TIME** and **FILE SYSTEM** are added to **Project Graph** window.
<img src = "images/step41.png"> <br>

40. Add **SYS_CONSOLE** dependency.<br>
   a. Right Click on **SYS_CONSOLE** button <img src = "images/diamond.png"> on **TCP/IP STACK** box.<br>
   b. Select Satisfiers → **CONSOLE**.
   <img src = "images/step42.png"> <br>

41. Add COMMAND and DEBUG System Service to CONSOLE.<br>
   a. Right Click on **SYS_CONSOLE** button <img src = "images/diamond.png"> on **DEBUG** box.<br>
   b. Select Satisfiers → **CONSOLE**.<br>
   <img src = "images/step43_1.png"> <br>
   c. Right Click on **SYS_CONSOLE** button <img src = "images/diamond.png"> on **COMMAND** box.<br>
   d. Select Satisfiers → **CONSOLE**.<br>
   <img src = "images/step43_2.png"> <br>

42. Add **SDHC** consumers.<br>
   a. Right Click on **SDHC** button <img src = "images/diamond.png"> on **SDMMC1** box.<br>
   b. Select consumers → **SDMMC**.<br>
   <img src = "images/step44.png"> <br>
   
43. Add **SDMMC** consumers.<br>
   a. Right Click on **DRV_MEDIA** button <img src = "images/square.png"> on **SDMMC** box.<br>
   b. Select consumers → **FILE SYSTEM**.<br>
   <img src = "images/step45.png"> <br>
   
44. Add **TIME** satisfiers.<br>
   a. Right Click on **TMR** button <img src = "images/diamond.png"> on **TIME** box.<br>
   b. Select Satisfiers → **TC0**.<br>
   <img src = "images/step46.png"> <br>

45. From **Device Resources** window, expand **Peripherals** and expand **FLEXCOM** to view **FLEXCOM** list. <br>
   a. Click add button <img src = "images/add.png"> to add **FLEXCOM3** and **FLEXCOM9** to **Project Graph**.  <br>
   <img src = "images/step33.png"> <br>

46. **FLEXCOM3** and **FLEXCOM9** added to **Project Graph** window.
<img src = "images/step35.png"> <br>
   
47. In SAMA7G54-EK Evaluation Kit, Debug UART is connected to FLEXCOM3 peripheral module.<br>
   a. To add **UART** consumers, Right Click on **UART** button <img src = "images/diamond.png"> on **FLEXCOM3** box.<br>
   b. Select consumers → **CONSOLE**.<br>
   <img src = "images/step47.png"> <br>   
   
48. In SAMA7G54-EK Evaluation Kit, Thermo 3 click board is connected to MikroBUS 1 Slot. I2C communication Protocol is required to access Thermo 3 click board. The I2C/TWI lines of MikroBUS 1 Slot are connected to FLEXCOM9 peripheral module. <br>
   a. To add **I2C** consumers, Right Click on **I2C** button <img src = "images/diamond.png"> on **FLEXCOM9** box.<br>
   b. Select consumers → **I2C**.<br>
   <img src = "images/step48.png"> <br>      

49. Add **wolfCrypt Library** consumers.<br>
   a. Right Click on **LIB_WOLFCRYPT** button <img src = "images/square.png"> on **wolfCrypt Library** box.<br>
   b. Select consumers → **wolfSSL Library**.<br>
   <img src = "images/step49_1.png"> <br>   
   c. Right Click on **TLS Provider** button <img src = "images/diamond.png"> on **TCP/IP STACK** box.<br>
   d. Select Satisfiers → **wolfSSL Library**.<br>
   <img src = "images/step49_2.png"> <br>    
   
50. Update the System **Heap size** and all other **Stack Size**.<br>
   a. Select the **System** in the **Project Graph** window.<br>
   b. In **Configuration Options** window, update the System **Heap size** and all other **Stack Size** as shown in the image below.  <br>
<img src = "images/step49.png"> <br>     

51. Start **Clock Configuration** from **Plugins** drop-down menu.
<img src = "images/step50.png"> <br>  	

52. Verify the **clock configuration**. The application demo can work with default clock configuration.<br>
   a. Verify the **Processor Clock (CPU_CLK)** is 800,000,000 Hz. <br>
   b. Verify the **Master Clock (MCK0)** is 200,000,000 Hz.<br>
<img src = "images/step51.png"> <br>
<br>c. Verify the **Peripheral Clocks** are enabled for FLEXCOM3, FLEXCOM9, GMAC0, SDMMC1 and TC0. Select the **System** in the **Project Graph** window. In **Configuration Options**, expand **Clock** then expand **Peripheral Clocks**.<br>
<img src = "images/step51_1.png"> <br>    
   d. **GMAC0** requires 125,000,000 Hz clock frequency. We need to use **ETHPLL** as clock source. To Enable **ETHPLL**, select the **System** in the **Project Graph** window. In **Configuration Options**, expand **Clock** then expand **ETHPLL**. Now click on the check box of **Enable PLL** and update the value as shown below.<br>
<img src = "images/step51_2.png"> <br>    
   e. Enable **GMAC0** clock. Select the **System** in the **Project Graph** window. In **Configuration Options**, expand **Clock** then expand **Generic Clocks**. <br>
   f. Expand **GMAC0** and click on **Enable** check box. Update **GCLKCSS** as **ETHPLL**.<br>
<img src = "images/step51_3.png"> <br>  
   g. Enable **SDMMC1** clock. Select the **System** in the **Project Graph** window. In **Configuration Options**, expand **Clock** then expand **Generic Clocks**. <br>   
   h. Expand **SDMMC1** and Click on **Enable** check box. Update **GCLKCSS** as **MAINCK**.<br>
<img src = "images/step51_4.png"> <br>  
	
53. Start **interrupt Configuration** from Plugins drop-down menu.
<img src = "images/step52.png"> <br>
<br>a. Verify whether **FLEXCOM3**, **FLEXCOM9**, **GMAC0**, **SDMMC1** and **TC0_CH0** interrupt is enabled.
<img src = "images/step52_1.png"> <br>
<img src = "images/step52_2.png"> <br>
54. Start **Pin Configuration** from Plugins drop-down menu.
<img src = "images/step53.png"> <br>
<br>a. Refer to the SAMA7G54-EK User's Guide for the **UART** pins.
   <img src = "images/step53_2.png"> <br> 
<br>b. Configure the pins for **UART** as shown below. 
   <img src = "images/step53_1.png"> <br> 
<br>c. Refer to the SAMA7G54-EK User's Guide for **TWI** pins.
   <img src = "images/step53_3.png"> <br>
<br>d. Configure the pins for **TWI** as shown below.   
   <img src = "images/step53_4.png"> <br>
<br>e. Configure the pins for **SDMMC1** as shown below. 
   <img src = "images/step53_5.png"> <br>
<br>f. Refer to **Gigabit Ethernet Interface Schematic** in SAMA7G54-EK User's Guide for the **GMAC0** pins
   <img src = "images/step53_6.png"> <br>
<br>g. Configure the pins for **GMAC0** as shown below.
   <img src = "images/step53_7.png"> <br>

55. Update **HTTPNET SERVER** Listening port and default **HTTP NET** file.<br> 
   a. In **Project Graph** window, Select **APPLICATION LAYER** from the list in **view:** tab.<br> 
   b. Click on **HTTPNET SERVER** box in **Project Graph**.<br>
   c. In **Configuration Options**, in **HTTPNER SERVER** expand **Advanced Settings**. Update **Default HTTP NET file** as **index.html** and update **HTTP NET Listening Port** as 443.<br> 
   <img src = "images/step54_1.png"> <br>
   
56. Enable Encryption setting.<br>
   a. In **Project Graph** window, Select **PRESENTATION LAYER** from the list in **view:** tab.<br> 
   b. Click on **Presentation Layer** box in **Project Graph**.<br>
   c. In **Configuration Options** window, Enable **Support Encryption?** by clicking on the check box.
<img src = "images/step55_2.png"> <br>
   d. In **Configuration Options** window, expand **Support Encryption?** Update **Encryption Provider** as **WolfSSL** from list and enable **Support Server Encryption?** by clicking on the check box.<br>
<img src = "images/step55_3.png"> <br>

57. Update **TCP/IP stack Dynamic RAM Size** to **92160**. <br> 
   a. In **Project Graph** window, select **BASIC CONFIGURATION** from the list in **view:** tab.<br> 
   b. Click on **TCPIP CORE** box in **Project Graph**.<br>
   c. In **Configuration Options**, expand **Heap Configuration** and update **TCP/IP stack Dynamic RAM Size** to **92160**. 
    <img src = "images/step55_5.png"> <br>
	
58. Update **KSZ9131** PHY Address to **7**. <br> 
   a. In **Project Graph** window, select **DATA LINK LAYER** from the list in **view:** tab.<br> 
   b. Click on **KSZ9131** box in **Project Graph**.<br>
   c. In **Configuration Options** window, in **KSZ9131** Update **PHY Address** to **7**. 
    <img src = "images/ksz9131.png"> <br>
	
59. Now Save all. Then click generate code. This will generate code for all the Device Resource that have been added in the project graph.  <br>
<img src = "images/step55.png">  <br>

60. Up to this point in the project creation process, you used MPLAB Code Configurator (MCC) to configure and generate code to initialize the device (SAMA7G54). <br>
  Refer [initialization.c](./firmware/src/config/default/initialization.c) to find that all the device resource added in the project graph got initialized.  All that is left is for the user to write the application code in the app.c file.
  Documentation for each of the peripheral libraries or driver libraries can be accessed as follows:<br>
  a. Peripheral libraries APIs can be accessed as a HTML file (.html) from the Harmony 3 Framework path. (\<framework_path\>/csp/docs/index.html)<br>
  b. BSP libraries APIs can be found in bsp.h <br>
  c. TCP/IP Stack APIs can be accessed as a HTML file (.html) from the Harmony 3 Framework path. (\<framework_path\>/net/docs/index.html)<br>

61. APIs used for this application are as follows:
  * LED_GREEN_On
  * LED_GREEN_Off
  * LED_Red_On
  * LED_Red_Off
  * LED_Blue_On
  * LED_Blue_Off
  * FLEXCOM9_TWI_CallbackRegister
  * FLEXCOM9_TWI_Write
  * FLEXCOM9_TWI_IsBusy
  * FLEXCOM9_TWI_Read
  * SYS_FS_Mount
  * TCPIP_STACK_Status
  * SYS_CONSOLE_PRINT
  * SYS_CONSOLE_MESSAGE
  * TCPIP_STACK_NumberOfNetworksGet
  * TCPIP_STACK_NetAddress
  * TCPIP_STACK_NetNameGet
  * TCPIP_STACK_NetIsReady
  * TCPIP_STACK_IndexToNet
  
62. Sample code can be found here [app](./firmware/src/app.c), [http net app](./firmware/src/custom_http_net_app.c), [http net print](./firmware/src/http_net_print.c), [main](./firmware/src/main.c) and Its header file can be found here [app](./firmware/src/app.h), [http net print](./firmware/src/http_net_print.h).

63. Now right click on the project and click **Properties**. For **Connected Hardware Tool** -> select connected hardware debugger used, for **Compiler Toolchain** -> select **XC32** and click **Apply**.  <br>
<img src = "images/step59.png">  <br>

64. From J-32/J-Link, In **Option categories** choose **Communication** and for **JTAG Method**, select **4-wire JTAG**.  <br>
<img src = "images/step60.png">  <br>

65. Select **bootstrap** from **Categories** and select the **Use Bootstrap** checkbox. For **bootstrap file** -> select the **at91bootstrap.elf** file from [here](./firmware/sama7g54_ek.X)- Click on **Apply** and **OK**.  <br>
<img src = "images/step61.png">  <br>

66. By default, **MPLAB X** only produces **ELF** and **Hex** format output files.
    To generate application output in binary format, a post build step needs to be added to the project properties.
	To do this, right click on project and select **properties**, select **building**, click the check box **Execute this line after build**, then enter the below command. <br>

	***${MP_CC_DIR}/xc32-objcopy -O binary ${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.elf ${DISTDIR}/harmony.bin*** <br>

    Click on **Apply** and **OK**.
<img src = "images/step62.png" align="middle"> <br>

67. Clean and build the project. You should see a message on the output console that the project was successfully built. This completes the development of the ethernet web server getting started application.  <br>

68. The harmony.bin binaries will be available at ./firmware/sama7g54_ek.X/dist/default/production.
</details> 

## Debugging Application Project on MPLAB® X IDE:
- Open the project (sama7g54_ek_ethernet_web_server_getting_started/firmware/sama7g54_ek.X) in MPLAB® X IDE.  
- In the project properties, ensure **SAMA7G54** is selected as the **Device** and for **Connected Hardware Tool**, select the hardware debugger connected to the board to program/debug the application.    
- Build and debug the code by clicking on the **Debug** button in MPLAB® X IDE tool bar.   
- Run the application by clicking the **run** button in MPLAB® X IDE tool bar.
- Ensure Console Serial communications between the Host PC and the SAMA7G54-EK Evaluation Board take place through UART port J24. 
A terminal emulation program running on the Host PC communicates with the SAMA7G54-EK Evaluation Kit UART port.
Ensure the terminal emulation program (Eg: Tera term) is configured to the COM port and settings are:
  * Speed: 115200
  * Data: 8
  * Parity: None
  * Stop Bits: 1 

- Once the board is powered up, you will see the Blue LED turn ON.
  The following message is displayed on the console:<br>
 <img src = "images/DebugInfo.png" align="middle"> <br> 

## Running the pre-built harmony application from SD Card:
The pre-built application bin file can be programmed by following the below steps.

### Steps to program the bin file on SD card
- Take an SD Card formatted with FAT32 file system.  
- Copy the boot.bin, harmony.bin and webpage files from this [location](./hex) to the SD card.  
- Insert the SD card to J4 on the SAMA7G54-EK Evaluation Kit.  

### Steps to run the bin file from SD card 
- Press the reset button.
- The following debug messages will be displayed on the console. Note the IP Address.<br>
<img src = "images/DebugPrint.png" align="middle"> <br> 
- Enter the IP Address (Example: https://10.40.24.92) in web browser and press enter. The following webpage will be displayed on your browser.
<img src = "images/WebPage.png" align="middle"> <br> 
- Now control each LED from webpage and view LED status updated. View the temperature displayed on the webpage.

## Comments:
- This application demo builds and works out of the box by following the instructions above in "Running the Demo" section- If you need to enhance/customize this application demo, you need to use the MPLAB® Harmony v3 Software framework- Refer links below to setup and build your applications using MPLAB® Harmony.
    - [How to Setup MPLAB® Harmony v3 Software Development Framework](https://ww1.microchip.com/downloads/en/DeviceDoc/How_to_Setup_MPLAB_%20Harmony_v3_Software_Development_Framework_DS90003232C.pdf)
    - <span style="color:blue"> **MPLAB® Harmony v3 is also configurable through MPLAB® Code Configurator (MCC)- Refer to the below links for specific instructions to use MPLAB® Harmony v3 with MCC.**</span>	
	   - [Create a new MPLAB Harmony v3 project using MCC](https://microchipdeveloper.com/harmony3:getting-started-training-module-using-mcc)
	   - [Update and Configure an Existing MHC-based MPLAB Harmony v3 Project to MCC-based Project](https://microchipdeveloper.com/harmony3:update-and-configure-existing-mhc-proj-to-mcc-proj)
       - [Getting Started with MPLAB® Harmony v3 Using MPLAB® Code Configurator](https://www.youtube.com/watch?v=KdhltTWaDp0)
	   - [MPLAB® Code Configurator Content Manager for MPLAB® Harmony v3 Projects](https://www.youtube.com/watch?v=PRewTzrI3iE)
    
## Revision:
- v1.6.0 - Released demo application
