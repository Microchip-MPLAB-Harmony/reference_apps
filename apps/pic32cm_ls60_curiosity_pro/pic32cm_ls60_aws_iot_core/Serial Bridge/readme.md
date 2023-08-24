# ATWINC1510 Firmware upgrade

## Description:

> The application's functioning requires the ATWINC1500 module to have firmware compatible with the WiFi software stack running on the PIC32CMLS60 microcontroller(EV76R77A Development Kit). To enable this compatibility, the  ATWINC1500 module is updated with the firmware compatible with WiFi software running in the latest released demo.  

## Running the utility

- Connect the WINC1500-Xpro to EXT3 of the PIC32CMLS60-Cpro(EV76R77A Development Kit).Flash the serial_bridge_ls60.hex 
  
  <img src = "./images/sb3.png">

- If LED0(Green) lights up it indicates the WINC has the latest firmware i.e Ver.19.7.7,In case of RED LED indication go ahead with below steps.

- Run the command prompt from **"utilities"** folder
  
  <img src = "./images/sb2.png">

- The following command line will generate a device programming file winc1500_19.7.7.prog.
  
  **image_tool.exe -c winc1500_19.7.7\config.txt -o winc1500_19.7.7.prog -of prog**  
  
  <img src = "./images/sb4.png">

- The following command line will program a WINC1500 device via the serial port   
    **winc_programmer -p COMxx -d winc1500 -i winc1500_19.7.7.prog -if prog -w -r -pfw winc1500_19.7.7\firmware\programmer_firmware.bin**
  
    **NOTE** : Replace the xx with the device COM PORT in the above command and all    other serial terminal application should be closed
  
  <img src = "./images/sb5.png">

- Wait till **verify passed** message comes up as shown below.After sucessful upgrade the Green LED (LED0) lights up.
  
  <img src = "./images/Verifiy complete.PNG">

### 
