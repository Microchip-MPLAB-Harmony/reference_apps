---
grand_parent: Reference Applications
parent: PIC32MZ Embedded Connectivity with FPU (EF) Starter Kit + MEB-II
title: SD Card Player/Reader series
nav_order: 1
---
<img src = "images/microchip_logo.png">
<img src = "images/microchip_mplab_harmony_logo_small.png">

# SD Card Audio Player/Reader Application on PIC32MZ Embedded Connectivity with FPU Starter Kit + Multimedia Expansion Board II
-----
## Description

>  This folder contains a series of applications which uses MPLAB Harmony v3 framework
   for Quick Audio Prototyping, and in the process creates an SD card Audio Player/Reader.

- The Application **audio_player_lab1** is the basic audio application that generates an audio tone using a lookup table
- The Application **audio_player_lab2** is an extension of application **audio_player_lab1**, it generates an audio tone using
  a text file stored in an SD Card
- The Application **audio_player_lab3** is an extension of application **audio_player_lab2**, it also generates an audio tone
  using a text file stored in an SD Card. Additionally, it adds the SD card reader support to load audio files
- The Application **audio_player_lab4** is an extension of application **audio_player_lab3**, implements an audio player by reading
  ".wav" audio files from the SD card
- The Application **audio_player_lab5** is an extension of application **audio_player_lab4**, implements graphical user interface
  to the audio reader (storing audio files in the SD card) and player (playing ".wav" audio files from the SD card)


## Modules/Technology Used:
- Refer the documentation in individual application folder

## Hardware Used:

- [PIC32MZ Embedded Connectivity with FPU (EF) Starter Kit](http://www.microchip.com/Developmenttools/ProductDetails.aspx?PartNO=DM320007)
- [PIC32 Multimedia Expansion Board II](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320005-5)

**Note:** This application is a reference only to the existing users of Multimedia Expansion Board II (MEB II) to port/develop their
application(s) using MPLAB Harmony v3 as the Multimedia Expansion Board II (MEB II) is now a matured product and the same is not
available for purchase from Microchip Direct.

## Software/Tools Used:
<span style="color:blue"> *This project has been verified to work with the following versions of software tools:*</span>

 - [MPLAB Harmony v3 "csp" repo v3.7.1](https://github.com/Microchip-MPLAB-Harmony/csp/releases/tag/v3.7.1)
 - [MPLAB Harmony v3 "dev_packs" repo v3.7.0](https://github.com/Microchip-MPLAB-Harmony/dev_packs/releases/tag/v3.7.0)
 - [MPLAB Harmony v3 "bsp" repository v3.7.0](https://github.com/Microchip-MPLAB-Harmony/bsp/releases/tag/v3.7.0)
 - [MPLAB Harmony v3 "audio" repository v3.5.0](https://github.com/Microchip-MPLAB-Harmony/audio/releases/tag/v3.5.0)
 - [MPLAB Harmony v3 "gfx" repository v3.6.0](https://github.com/Microchip-MPLAB-Harmony/gfx/releases/tag/v3.6.0)
 - [MPLAB Harmony v3 "touch" repository v3.6.0](https://github.com/Microchip-MPLAB-Harmony/touch/releases/tag/v3.6.0)
 - [MPLAB Harmony v3 "usb" repository v3.5.0](https://github.com/Microchip-MPLAB-Harmony/usb/releases/tag/v3.5.0)
 - [MPLAB Harmony v3 "mhc" repo v3.4.0](https://github.com/Microchip-MPLAB-Harmony/mhc/releases/tag/v3.4.0)
 -  MPLAB Harmony Configurator Plugin v3.5.0
 - [MPLAB X IDE v5.40](https://www.microchip.com/mplab/mplab-x-ide)
 - [MPLAB XC32 Compiler v2.41](https://www.microchip.com/mplab/compilers)

<span style="color:blue"> *Because Microchip regularly update tools, occasionally issue(s) could be discovered while using the newer versions of the tools. If the project doesn’t seem to work and version incompatibility is suspected, It is recommended to double-check and use the same versions that the project was tested with.* </span>

## Setup:
- Connect the PIC32MZ Embedded Connectivity with FPU (EF) Starter Kit to the Host PC as a USB Device
  through a Type-A male to micro-B USB cable connected to Micro-B USB (Debug USB) port.
- Connect the USB Type-A male to Micro-B male cable for SD card reader functionality
- Insert Micro SD card containing audio files in waveform audio format (WAV)
- Connect the wired stereo headphone to the audio jack
<img src = "images/hardware_setup.png" width="700" height="525" align="middle">

**Note:**
It is not necessary to have an MPLAB Real ICE™ to program/debug the code. The PIC32MZ EF Starter Kit
includes a PICkit™ on-board (PKOB) debugger. The PKOB debugger can be connected to a host PC through
the USB Mini-B connector on the PIC32MZ EF Starter Kit for programming/debugging
(see the red cable in the hardware setup).

## Programming binary/hex file:
- Refer the documentation in individual application folder

## Programming/Debugging Application Project:
- Refer the documentation in individual application folder

## Running the Demo:
- Refer the documentation in individual application folder

## Comments:
- Reference Training Module: [MPLAB® Harmony v3 SD Card Audio Player/Reader Tutorial](https://microchipdeveloper.com/harmony3:audio-player)

## Revision:
- v1.0 released demo application
