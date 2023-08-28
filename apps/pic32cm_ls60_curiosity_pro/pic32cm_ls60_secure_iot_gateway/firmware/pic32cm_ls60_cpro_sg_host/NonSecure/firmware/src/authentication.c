/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Microchip Technology Inc.

  @File Name
    authentication.c

  @Summary
    This file contains the symmetric authentication related functions.

  @Description
    This file contains the API calls for MAC generation for the symmetric authentication process of the client device.
 */
/* ************************************************************************** */

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2023 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
//DOM-IGNORE-END

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

#include "host/atca_host.h"
#include "click_routines/oled_c/oled_c_example.h"
#include "click_routines/oled_c/oled_c.h"
#include "definitions.h" 
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h> 
#include "authentication.h"
#include "common/cloud_wifi_task.h"


uint8_t revision[4];
uint8_t serial_number[9];
ATCADeviceType device_type;
ATCA_STATUS status = !ATCA_SUCCESS;
char displaystr[200];
size_t displaylen;
atca_io_decrypt_in_out_t io_dec_params;
atca_nonce_in_out_t nonce_params;   


uint8_t host_mac[MAC_SIZE];
volatile int authenticDevice=0;


volatile bool RandomGen =0;
uint8_t num_in[NONCE_NUMIN_SIZE];
uint8_t rand_out[RANDOM_NUM_SIZE];
uint8_t device_mac[MAC_SIZE];

extern APP_DATA appData;

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


/*Generates random number*/
ATCA_STATUS RNG(uint8_t *dest, size_t size)
{
    ATCA_STATUS status = ATCA_GEN_FAIL;
    uint8_t random[RANDOM_NUM_SIZE];

    if (ATCA_SUCCESS == (status = atcab_random(random)))
    {
        memcpy(dest, random, size);
    }
    return status;
}

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
    ATCA_STATUS status = !ATCA_SUCCESS;
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
        // atcab_info() failed 
         break;
      }   

      
      
      // Request the Serial Number
      if ((status = atcab_read_serial_number(serial_number)) != ATCA_SUCCESS)
      {
         printf("atcab_info() failed with ret=0x%08X\r\n", status);
         break;
      }
           
      
      //Selecting the right device based on the revision
      device_type = get_device_type_id(revision[2]);
      if (cfg->devtype != device_type)
      {
         //printf("Selected device id: %d, Identified device id: %d\r\n", cfg->devtype, device_type);
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

/*Generates random number at host*/
uint8_t generate_RNG(){

   ATCA_STATUS status =ATCA_SUCCESS;
   status = RNG(num_in, NONCE_NUMIN_SIZE);             
   RandomGen =1;
   return status;

}

/*Calculates the MAC value at host*/
uint8_t calculate_host_mac(void)
{
    ATCA_STATUS status;
    atca_temp_key_t temp_key;
    atca_nonce_in_out_t nonce_params;
    atca_mac_in_out_t mac_params;
    uint8_t sernum[ATCA_SERIAL_NUM_SIZE];
    char displaystr[400];
    size_t displaylen;

    // Setup nonce command
    memset(&temp_key, 0, sizeof(temp_key));
    memset(&nonce_params, 0, sizeof(nonce_params));
    nonce_params.mode = NONCE_MODE_SEED_UPDATE;  
    nonce_params.zero = 0;
    nonce_params.num_in = num_in;
    nonce_params.rand_out = rand_out;
    nonce_params.temp_key = &temp_key;
    if (ATCA_SUCCESS == (status = atcah_nonce(&nonce_params)))
    {
        if (ATCA_SUCCESS == (status = atcab_read_serial_number(sernum)))
        {
            // Setup MAC command
            memset(&mac_params, 0, sizeof(mac_params));
            mac_params.mode = MAC_MODE_BLOCK2_TEMPKEY ;//| MAC_MODE_INCLUDE_SN;
            mac_params.key_id = SYMMETRIC_KEY_SLOT;
            mac_params.challenge = NULL;
            mac_params.key = slot_5_secret_key;
            mac_params.otp = NULL;
            mac_params.sn = sernum;
            mac_params.response = host_mac;
            mac_params.temp_key = &temp_key;
            if (ATCA_SUCCESS == (status = atcah_mac(&mac_params)))
            {
                                
            }
            else
            {
                 console_print_message("Host mac calculation is failed with status");
            }
        }
        else
        {
             console_print_message("Reading serial number is failed with status");
        }
    }
    else
    {
         console_print_message("Host nonce generation is failed with status");
    }

    return status;
}

/*Compares the MAC received from client with the MAC generated at host*/
ATCA_STATUS mac_compare(void)
{
    if (memcmp(device_mac, host_mac, 32) != 0)
    {
        status = ATCA_CHECKMAC_VERIFY_FAILED;
    }
    else
        status = ATCA_SUCCESS;
        
    if(status == ATCA_SUCCESS)      
    {
        authenticDevice=1;
        console_print_message("Accessory device authenticated successfully"); 
        oled_c_Image_secure_visible();
    }
    else{
        authenticDevice=-1;       
        console_print_message("Accessory device not authenticated");
        oled_c_Image_nonsecure_visible();
    }    
    return status;

}

/*Writes data to the data zone slots*/
uint8_t slot_write(uint8_t slot_num)
{
    ATCA_STATUS status;
    if(slot_num==6){
    if(ATCA_SUCCESS !=(status =atcab_write_bytes_zone(ATCA_ZONE_DATA,slot_num,0,io_protect_secret_key,32))){
      //  printf("\r\n Write failed in slot 6\r\n");
        console_print_message("Write failed in slot 6");
        return true;
    }
    else
        return false;
    }
    else if(slot_num==5){
        if(ATCA_SUCCESS !=(status =atcab_write_enc(slot_num,0,slot_5_secret_key,io_protect_secret_key,6,num_in))){
       //Write failed in slot 5
         console_print_message("Write failed in slot 5");   
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
