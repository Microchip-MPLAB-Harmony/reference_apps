/* ************************************************************************** */
/** Descriptive File Name

  @Company
  Microchip Technology Inc

  @File Name
    security.c

  @Summary
  This file contains the functions related to symmetric authentication protocols

  @Description
  This file includes the functions to initialize the crypto element and MAC calculation for the symmetric authentication.
 */
/* ************************************************************************** */

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

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

#include "cryptoauthlib.h"
#include "host/atca_host.h"
#include "atca_iface.h"
#include "atca_devtypes.h"
#include "definitions.h" 
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h> 
#include "security.h"

#define SYMMETRIC_KEY_SLOT  (0x05)

uint8_t revision[4];
uint8_t serial_number[9];
ATCADeviceType device_type;
ATCA_STATUS status = !ATCA_SUCCESS;

atca_io_decrypt_in_out_t io_dec_params;
atca_nonce_in_out_t nonce_params;
uint8_t rand_out[RANDOM_NUM_SIZE];
uint8_t num_in[NONCE_NUMIN_SIZE];
uint8_t device_mac[MAC_SIZE];
volatile bool mac_stat=0;

uint8_t slot_5_secret_key[] = 
{
0x4A, 0x3B, 0xA0, 0x4F, 0x05, 0xF6, 0x01, 0xA4, 0xE2, 0x16, 0x37, 0x8D, 0xDD, 0x72, 0xB7, 0x3B, 
0xC5, 0x0E, 0x22, 0xB9, 0x30, 0x34, 0x4C, 0xC7, 0x9E, 0x7E, 0x12, 0x21, 0xDC, 0x90, 0x60, 0x33, 
};

uint8_t io_protect_secret_key[] = 
{
0x4A, 0x3B, 0xA0, 0x4F, 0x05, 0xF6, 0x01, 0xA4, 0xE2, 0x16, 0x37, 0x8D, 0xDD, 0x72, 0xB7, 0x3B, 
0xC5, 0x0E, 0x22, 0xB9, 0x30, 0x34, 0x4C, 0xC7, 0x9E, 0x7E, 0x12, 0x21, 0xDC, 0x90, 0x60, 0x33, 
};

/*Checks the type of secure device*/
ATCADeviceType get_device_type_id(uint8_t revision_byte)
{
    ATCADeviceType dev_type;

    switch (revision_byte)
    {
    case 0x00:
    case 0x02:
        dev_type = ATSHA204A;
        break;

    case 0x10:
        dev_type = ATECC108A;
        break;

    case 0x50:
        dev_type = ATECC508A;
        break;

    case 0x60:
        dev_type = ATECC608A;
        break;

    default:
        dev_type = ATCA_DEV_UNKNOWN;
        break;
    }

    return dev_type;
}

/*Get device details*/
ATCA_STATUS check_device_type_in_cfg(ATCAIfaceCfg* cfg, bool overwrite)
{   
    do
   {
      if ((status = atcab_init(cfg)) != ATCA_SUCCESS)
      {
        //atcab_init() failed 
         break;
      }
      
                  
      // Request the Revision Number
      if ((status = atcab_info(revision)) != ATCA_SUCCESS)
      {
        //atcab_info() failed 
         break;
      }

      // Request the Serial Number
      if ((status = atcab_read_serial_number(serial_number)) != ATCA_SUCCESS)
      {
        //atcab_info() failed 
         break;
      }

      //Selecting the right device based on the revision
      device_type = get_device_type_id(revision[2]);
      if (cfg->devtype != device_type)
      {
       if (overwrite)
         {
          //Device type updated
            cfg->devtype = device_type;
         }
         else
         {
           //Selected device is not found on the bus
            status = ATCA_GEN_FAIL;
         }
      }
   } while (0);

   (void)atcab_release();

   return status;
}

/*Generates device MAC*/
uint8_t generate_device_mac(){

   ATCA_STATUS status =ATCA_SUCCESS;
    if (ATCA_SUCCESS== (status = atcab_nonce_rand(num_in, rand_out)))
    {
        if (ATCA_SUCCESS == (status = atcab_mac(MAC_MODE_BLOCK2_TEMPKEY, 
                                                SYMMETRIC_KEY_SLOT, NULL, device_mac)))
        
        {
            //MAC from accessory device success
        }
        else
        {
           //Device mac calculation failed
        }
    }
    else
    {
      //Device nonce generation is failed 
    }
    mac_stat =1;
    return status;

}

uint8_t slot_write(uint8_t slot_num)
{
    ATCA_STATUS status;
    if(slot_num==6){
    if(ATCA_SUCCESS !=(status =atcab_write_bytes_zone(ATCA_ZONE_DATA,slot_num,0,io_protect_secret_key,32))){
        printf("\r\n Write failed in slot 6\r\n");
        return true;
    }
    else
        return false;
    }
    else if(slot_num==5){
        if(ATCA_SUCCESS !=(status =atcab_write_enc(slot_num,0,slot_5_secret_key,io_protect_secret_key,6,num_in))){
        printf("\r\n Write failed in slot 5\r\n");
        return true;
    }
    else
        return false;
        
    }
    return true;
}
/* *****************************************************************************
 End of File
 */
