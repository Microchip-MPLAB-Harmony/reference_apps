 /*******************************************************************************
  EEPROM 4 Example Source file

  Company:
    Microchip Technology Inc.

  File Name:
    eeprom4_example.c

  Summary:
  This file contains the "eeprom 4" example 
 * 
  Description:
 *******************************************************************************/
// DOM-IGNORE-BEGIN
/*
    (c) 2021 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/
// DOM-IGNORE-END
// ----------------------------------------------------------------------------

#include "eeprom4.h"
#include "string.h"

#define EEPROM_ADDRESS                      0x000000
#define EEPROM_DATA                         "WRITING AND READING DATA FROM EEPROM!"
#define EEPROM_DATA_LEN                     sizeof(EEPROM_DATA)

uint8_t  transmit_Data[(4 + EEPROM_DATA_LEN)];
uint8_t  receive_Data[(4 + EEPROM_DATA_LEN)];

void eeprom4_example(void)
{
    uint8_t read_status;
    
    eeprom4_Initialize();
    
    memcpy(transmit_Data, EEPROM_DATA, EEPROM_DATA_LEN);
    eeprom4_write_to_memory(EEPROM_ADDRESS,transmit_Data,EEPROM_DATA_LEN);
    
    read_status = eeprom4_read_status();
    
    while((read_status & 0x01))
    {
       read_status = eeprom4_read_status(); 
    }
    
    eeprom4_read_from_memory(EEPROM_ADDRESS,receive_Data,EEPROM_DATA_LEN);
    
    if(memcmp(EEPROM_DATA, &receive_Data[4], EEPROM_DATA_LEN) != 0)
    {
        printf("\r\nEEPROM TEST Failed\r\n");
    }else{
        printf("\r\nEEPROM TEST Passed\r\n");
    }
    
}