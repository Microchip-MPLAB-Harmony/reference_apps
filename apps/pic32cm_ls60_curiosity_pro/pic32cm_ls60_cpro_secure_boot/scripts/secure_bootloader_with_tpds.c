
// PIC32CM5164LS60100 Configuration Bit Settings

// 'C' source line config statements

// Config Source code for XC32 compiler.
// USER_WORD_0
#pragma config NVMCTRL_SULCK = 0x6 // Enter Hexadecimal value
#pragma config NVMCTRL_NSULCK = 0x6 // Enter Hexadecimal value
#pragma config BOD33USERLEVEL = 0x6 // Enter Hexadecimal value
#pragma config BOD33_DIS = CLEAR
#pragma config BOD33_ACTION = 0x1 // Enter Hexadecimal value
#pragma config WDT_RUNSTDBY = CLEAR
#pragma config WDT_ENABLE = CLEAR
#pragma config WDT_ALWAYSON = CLEAR
#pragma config WDT_PER = 0xB // Enter Hexadecimal value

// USER_WORD_1
#pragma config WDT_WINDOW = 0xB // Enter Hexadecimal value
#pragma config WDT_EWOFFSET = 0xB // Enter Hexadecimal value
#pragma config WDT_WEN = CLEAR
#pragma config BOD33_HYST = CLEAR
#pragma config IDAU_RXN = CLEAR
#pragma config NVMCTRL_DXN = SET

// USER_WORD_2
#pragma config IDAU_AS = 0x7FF // Enter Hexadecimal value
#pragma config IDAU_ANSC = 0x0 // Enter Hexadecimal value
#pragma config IDAU_DS = 0x40 // Enter Hexadecimal value

// USER_WORD_3
#pragma config IDAU_RS = 0x1FF // Enter Hexadecimal value
#pragma config NVMCTRL_URWEN = SET

// USER_WORD_4
#pragma config NONSECA_PAC = CLEAR
#pragma config NONSECA_PM = CLEAR
#pragma config NONSECA_MCLK = CLEAR
#pragma config NONSECA_RSTC = CLEAR
#pragma config NONSECA_OSCCTRL = CLEAR
#pragma config NONSECA_OSC32KCTRL = CLEAR
#pragma config NONSECA_SUPC = CLEAR
#pragma config NONSECA_GCLK = CLEAR
#pragma config NONSECA_WDT = CLEAR
#pragma config NONSECA_RTC = CLEAR
#pragma config NONSECA_EIC = CLEAR
#pragma config NONSECA_FREQM = CLEAR
#pragma config NONSECA_PORT = CLEAR
#pragma config NONSECA_AC = CLEAR

// USER_WORD_5
#pragma config NONSECB_IDAU = CLEAR
#pragma config NONSECB_DSU = SET
#pragma config NONSECB_NVMCTRL = CLEAR
#pragma config NONSECB_DMAC = CLEAR
#pragma config NONSECB_USB = CLEAR

// USER_WORD_6
#pragma config NONSECC_EVSYS = CLEAR
#pragma config NONSECC_SERCOM0 = CLEAR
#pragma config NONSECC_SERCOM1 = CLEAR
#pragma config NONSECC_SERCOM2 = CLEAR
#pragma config NONSECC_SERCOM3 = CLEAR
#pragma config NONSECC_SERCOM4 = CLEAR
#pragma config NONSECC_SERCOM5 = CLEAR
#pragma config NONSECC_TC0 = CLEAR
#pragma config NONSECC_TC1 = CLEAR
#pragma config NONSECC_TC2 = CLEAR
#pragma config NONSECC_TCC0 = CLEAR
#pragma config NONSECC_TCC1 = CLEAR
#pragma config NONSECC_TCC2 = CLEAR
#pragma config NONSECC_TCC3 = CLEAR
#pragma config NONSECC_ADC = CLEAR
#pragma config NONSECC_DAC = CLEAR
#pragma config NONSECC_PTC = CLEAR
#pragma config NONSECC_TRNG = CLEAR
#pragma config NONSECC_CCL = CLEAR
#pragma config NONSECC_I2S = CLEAR
#pragma config NONSECC_OPAMP = CLEAR
#pragma config NONSECC_TRAM = CLEAR

// USER_WORD_7
#pragma config BOOTROM_CDIROFFSET = 0x0 // Enter Hexadecimal value

// USER_WORD_8
#pragma config BOOTROM_USERCRC = 0x44DED29 // Enter Hexadecimal value

// BOCOR_WORD_0
#pragma config IDAU_BNSC = 0x0 // Enter Hexadecimal value

// BOCOR_WORD_1
#pragma config BOOTROM_BOOTOPT = 0x5 // Enter Hexadecimal value
#pragma config IDAU_BOOTPROT = 0x10 // Enter Hexadecimal value
#pragma config BOOTROM_SECCFGLOCK = SET
#pragma config BOOTROM_DICEEN = CLEAR
#pragma config NVMCTRL_BCWEN = SET
#pragma config NVMCTRL_BCREN = SET

// BOCOR_WORD_2
#pragma config BOOTROM_BOCORCRC = 0xEBCCC98E // Enter Hexadecimal value

// BOCOR_WORD_4
#pragma config BOOTROM_CEKEY0_0 = 0xFFFFFFFF // Enter Hexadecimal value

// BOCOR_WORD_5
#pragma config BOOTROM_CEKEY0_1 = 0xFFFFFFFF // Enter Hexadecimal value

// BOCOR_WORD_6
#pragma config BOOTROM_CEKEY0_2 = 0xFFFFFFFF // Enter Hexadecimal value

// BOCOR_WORD_7
#pragma config BOOTROM_CEKEY0_3 = 0xFFFFFFFF // Enter Hexadecimal value

// BOCOR_WORD_8
#pragma config BOOTROM_CEKEY1_0 = 0xFFFFFFFF // Enter Hexadecimal value

// BOCOR_WORD_9
#pragma config BOOTROM_CEKEY1_1 = 0xFFFFFFFF // Enter Hexadecimal value

// BOCOR_WORD_10
#pragma config BOOTROM_CEKEY1_2 = 0xFFFFFFFF // Enter Hexadecimal value

// BOCOR_WORD_11
#pragma config BOOTROM_CEKEY1_3 = 0xFFFFFFFF // Enter Hexadecimal value

// BOCOR_WORD_12
#pragma config BOOTROM_CEKEY2_0 = 0xFFFFFFFF // Enter Hexadecimal value

// BOCOR_WORD_13
#pragma config BOOTROM_CEKEY2_1 = 0xFFFFFFFF // Enter Hexadecimal value

// BOCOR_WORD_14
#pragma config BOOTROM_CEKEY2_2 = 0xFFFFFFFF // Enter Hexadecimal value

// BOCOR_WORD_15
#pragma config BOOTROM_CEKEY2_3 = 0xFFFFFFFF // Enter Hexadecimal value

// BOCOR_WORD_16
#pragma config BOOTROM_CRCKEY_0 = 0xFFFFFFFF // Enter Hexadecimal value

// BOCOR_WORD_17
#pragma config BOOTROM_CRCKEY_1 = 0xFFFFFFFF // Enter Hexadecimal value

// BOCOR_WORD_18
#pragma config BOOTROM_CRCKEY_2 = 0xFFFFFFFF // Enter Hexadecimal value

// BOCOR_WORD_19
#pragma config BOOTROM_CRCKEY_3 = 0xFFFFFFFF // Enter Hexadecimal value

// BOCOR_WORD_20
#pragma config BOOTROM_BOOTKEY_0 = 0xABABABAB // Enter Hexadecimal value

// BOCOR_WORD_21
#pragma config BOOTROM_BOOTKEY_1 = 0xABABABAB // Enter Hexadecimal value

// BOCOR_WORD_22
#pragma config BOOTROM_BOOTKEY_2 = 0xABABABAB // Enter Hexadecimal value

// BOCOR_WORD_23
#pragma config BOOTROM_BOOTKEY_3 = 0xABABABAB // Enter Hexadecimal value

// BOCOR_WORD_24
#pragma config BOOTROM_BOOTKEY_4 = 0xABABABAB // Enter Hexadecimal value

// BOCOR_WORD_25
#pragma config BOOTROM_BOOTKEY_5 = 0xABABABAB // Enter Hexadecimal value

// BOCOR_WORD_26
#pragma config BOOTROM_BOOTKEY_6 = 0xABABABAB // Enter Hexadecimal value

// BOCOR_WORD_27
#pragma config BOOTROM_BOOTKEY_7 = 0xABABABAB // Enter Hexadecimal value

// BOCOR_WORD_28
#pragma config BOOTROM_UDS_0 = 0xFFFFFFFF // Enter Hexadecimal value

// BOCOR_WORD_29
#pragma config BOOTROM_UDS_1 = 0xFFFFFFFF // Enter Hexadecimal value

// BOCOR_WORD_30
#pragma config BOOTROM_UDS_2 = 0xFFFFFFFF // Enter Hexadecimal value

// BOCOR_WORD_31
#pragma config BOOTROM_UDS_3 = 0xFFFFFFFF // Enter Hexadecimal value

// BOCOR_WORD_32
#pragma config BOOTROM_UDS_4 = 0xFFFFFFFF // Enter Hexadecimal value

// BOCOR_WORD_33
#pragma config BOOTROM_UDS_5 = 0xFFFFFFFF // Enter Hexadecimal value

// BOCOR_WORD_34
#pragma config BOOTROM_UDS_6 = 0xFFFFFFFF // Enter Hexadecimal value

// BOCOR_WORD_35
#pragma config BOOTROM_UDS_7 = 0xFFFFFFFF // Enter Hexadecimal value

// BOCOR_WORD_36
#pragma config BOOTROM_IOPROTKEY_0 = 0xD2C56F12 // Enter Hexadecimal value

// BOCOR_WORD_37
#pragma config BOOTROM_IOPROTKEY_1 = 0xCBD830FE // Enter Hexadecimal value

// BOCOR_WORD_38
#pragma config BOOTROM_IOPROTKEY_2 = 0x34E1DCB2 // Enter Hexadecimal value

// BOCOR_WORD_39
#pragma config BOOTROM_IOPROTKEY_3 = 0x29A86694 // Enter Hexadecimal value

// BOCOR_WORD_40
#pragma config BOOTROM_IOPROTKEY_4 = 0x3E4DB210 // Enter Hexadecimal value

// BOCOR_WORD_41
#pragma config BOOTROM_IOPROTKEY_5 = 0x449DF53D // Enter Hexadecimal value

// BOCOR_WORD_42
#pragma config BOOTROM_IOPROTKEY_6 = 0x4EA5EE34 // Enter Hexadecimal value

// BOCOR_WORD_43
#pragma config BOOTROM_IOPROTKEY_7 = 0x3135EA7E // Enter Hexadecimal value

// BOCOR_WORD_56
#pragma config BOOTROM_BOCORHASH_0 = 0x3C1062FD // Enter Hexadecimal value

// BOCOR_WORD_57
#pragma config BOOTROM_BOCORHASH_1 = 0x1380AE5E // Enter Hexadecimal value

// BOCOR_WORD_58
#pragma config BOOTROM_BOCORHASH_2 = 0x3F592D62 // Enter Hexadecimal value

// BOCOR_WORD_59
#pragma config BOOTROM_BOCORHASH_3 = 0x428A2382 // Enter Hexadecimal value

// BOCOR_WORD_60
#pragma config BOOTROM_BOCORHASH_4 = 0x643FCCEF // Enter Hexadecimal value

// BOCOR_WORD_61
#pragma config BOOTROM_BOCORHASH_5 = 0x15D27A72 // Enter Hexadecimal value

// BOCOR_WORD_62
#pragma config BOOTROM_BOCORHASH_6 = 0x1E29DD23 // Enter Hexadecimal value

// BOCOR_WORD_63
#pragma config BOOTROM_BOCORHASH_7 = 0x643A9596 // Enter Hexadecimal value

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>


