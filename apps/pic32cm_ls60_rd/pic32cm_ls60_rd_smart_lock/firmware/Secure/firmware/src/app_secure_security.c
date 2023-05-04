/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

// DOM-IGNORE-BEGIN
/*******************************************************************************************
* Copyright (C) 2023 Microchip Technology Inc. and its subsidiaries.

 * Subject to your compliance with these terms, you may use this Microchip software
 * and any derivatives exclusively with Microchip products. You are responsible for
 * complying with third party license terms applicable to your use of third party
 * software (including open source software) that may accompany this Microchip software.

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
 *******************************************************************************************/
// DOM-IGNORE-END

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */
#include "cryptoauthlib.h"
#include "host/atca_host.h"
#include "atca_iface.h"
#include "atca_devtypes.h"
#include "definitions.h" 
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h> 
#include <stdio.h> 
#include "app_secure_security.h"
#include"../src/simpleMAP/simpleMAP_library.h"


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */
/** Descriptive Data Item Name

  @Summary
    Brief one-line summary of the data item.
    
  @Description
    Full description, explaining the purpose and usage of data item.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
  @Remarks
    Any additional remarks
 */
const uint32_t nvm_data_flash_user_start_address[(DATAFLASH_PAGE_SIZE * 4)] __attribute__((address(DATAFLASH_ADDR)))= {0};
ATCAIfaceCfg *cfg3;

volatile bool temp_key_active = false;
volatile bool security_active = true;
//volatile uint8_t *passkey_send;
uint8_t revision[4];
uint8_t serial_number[9];
ATCADeviceType device_type;
ATCA_STATUS status = !ATCA_SUCCESS;
char displaystr[200];
size_t displaylen;
uint8_t* passkey;
uint8_t sha_digest[32];
uint8_t signature[64];
atca_io_decrypt_in_out_t io_dec_params;
//uint8_t kdf_defaultkey[32] = {0x6b, 0xd5, 0x4c, 0x8f, 0xb0, 0x41, 0x77, 0x85, 0x46, 0xd9, 0x97, 0x6c, 0x13, 0x52, 0x47, 
//         0x35, 0xe4, 0x5b, 0xc8, 0xc4, 0x26, 0x50, 0xb5, 0x94, 0x52, 0xd9, 0x42, 0xa8, 0xaa, 0x96, 0xa1, 0xc5};

/*default passkey 00000*/
uint8_t kdf_defaultkey[32]={0xA2, 0x7C,0x7C, 0x76, 0x5B, 0x91, 0xA7, 0xE3, 0xAF, 0x3A, 0xE0, 0x63, 0x0A, 0x75, 0xFC, 
        0x50, 0xB1, 0x2E, 0x51, 0x5E, 0x37, 0x6D, 0xE0, 0x0D, 0x7F, 
        0x9B, 0x4C, 0xAA, 0xD2, 0x0A, 0xBA, 0x8B};


uint8_t temp_passkey_slot = 1;
uint8_t volatile passkey_slot=0;
    
uint8_t temp_passkey[32];    

uint8_t rand_out[RANDOM_NUM_SIZE];

volatile uint32_t temp_Address;

volatile bool default_key_store = false;

const uint8_t io_protection_key[32] = {
        0x7D, 0xF0, 0x8B, 0x62, 0xBA, 0xAB, 0x3F, 0xF2,
        0x7F, 0x53, 0xA4, 0xBB, 0x98, 0xB6, 0x5A, 0x0C,
        0x4F, 0x88, 0x17, 0xC6, 0x7C, 0x58, 0x30, 0xEE,
        0x32, 0x7E, 0x25, 0xCD, 0x6F, 0x30, 0x78, 0x99
    };

atca_temp_key_t temp_key;
uint8_t Key_digest[32];
uint8_t out_nonce[32];
uint8_t out_validate_kdf[32];
uint8_t store_kdf_userkey[32] = {0};
    
volatile uint8_t User_key_fetch[32] = {0};
uint8_t User_key_fetch_temp[32] = {0};
uint8_t key_check[32] = {0xff};
uint8_t key_compare[32] = {0};

uint8_t default_kdf_userkey[32] = {0xa2,0x7c,0x7c,0x76,0x5b,0x91,0xa7,0xe3,
                                    0xaf,0x3a,0xe0,0x63,0xa,0x75,0xfc,0x50,
                                    0xb1,0x2e,0x51,0x5e,0x37,0x6d,0xe0,0xd,
                                    0x7f,0x9b,0x4c,0xaa,0xd2,0xa,0xba,0x8b};
    
uint8_t nonce[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a,
                        0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05,
                        0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f}; 

atca_nonce_in_out_t nonce_params;
extern uint8_t passkey_handle;

volatile bool set_new_passkey = false;

bool current_passkey_validated = false;

//extern APP_DB_MOTOR_DATA app_db_motorData;

//extern APP_BLE_DATA bleData;
enum user {User1=1, User2, User3, User4, User5};
uint8_t rand_number[NONCE_NUMIN_SIZE];  

void APP_Random_Generation(void)
{
uint8_t i=0,j=0,shift=0;
for(i=0;i<20;i+=4)
    {
        shift=0;
        for(j=0;j<4;j++)
        {
            rand_number[i+j]=(uint8_t)((TRNG_ReadData()>>shift)&0xff);
            shift+=8;
        }
    }
}

void APP_WritePasskey_Dataflash(uint32_t * passkey, uint8_t User_ID)
{
    
    temp_Address = (uint32_t)(nvm_data_flash_user_start_address + (0x100*User_ID));
            
    while(NVMCTRL_IsBusy());
    NVMCTRL_RowErase((uint32_t)(nvm_data_flash_user_start_address + (0x100*User_ID)));
    while(NVMCTRL_IsBusy());
    
    NVMCTRL_PageWrite((uint32_t *) passkey ,(uint32_t) (nvm_data_flash_user_start_address+(0x100*User_ID)));
    while(NVMCTRL_IsBusy());

    NVMCTRL_PageWrite((uint32_t *) &passkey[16] ,(uint32_t) (&nvm_data_flash_user_start_address[16]+(0x100*User_ID)));
    while(NVMCTRL_IsBusy());    
}

void APP_SECURITY_DefaultPasskeyStore (void)
{
    /*Erase respective data flash region for storing io_protection key*/
    while(NVMCTRL_IsBusy());
    NVMCTRL_RowErase((uint32_t)(nvm_data_flash_user_start_address));
    
    while(NVMCTRL_IsBusy());
    
    NVMCTRL_PageWrite((uint32_t *) io_protection_key,(uint32_t) nvm_data_flash_user_start_address);
    while(NVMCTRL_IsBusy());   
    
    for(uint8_t user=2; user<=5; user++)
    {
        APP_WritePasskey_Dataflash ((uint32_t *) default_kdf_userkey, user);
    }
}

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */


/* 
* function to reverse a string  
*/
void reverse(char str[], int len)
{
    int start, end;
    char temp;
    for(start=0, end=len-1; start < end; start++, end--) {
        temp = *(str+start);
        *(str+start) = *(str+end);
        *(str+end) = temp;
    }
}
 
char* itoa(int num, char* str, int bas)
{
    int i = 0;
    bool isNegative = false;
  
    /* A zero is same "0" string in all base */
    if (num == 0) {
        str[i] = '0';
        str[i + 1] = '\0';
        return str;
    }
  
    /* negative numbers are only handled if base is 10 
       otherwise considered unsigned number */
    if (num < 0 && bas == 10) {
        isNegative = true;
        num = -num;
    }
  
    while (num != 0) {
        int rem = num % bas;
        str[i++] = (rem > 9)? (rem-10) + 'A' : rem + '0';
        num = num/bas;
    }
  
    /* Append negative sign for negative numbers */
    if (isNegative){
        str[i++] = '-';
    }
  
    str[i] = '\0';
 
    reverse(str, i);
  
    return str;
}

/* ************************************************************************** */

/** 
  @Function
    int ExampleLocalFunctionName ( int param1, int param2 ) 

  @Summary
    Brief one-line description of the function.

  @Description
    Full description, explaining the purpose and usage of the function.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

  @Precondition
    List and describe any required preconditions. If there are no preconditions,
    enter "None."

  @Parameters
    @param param1 Describe the first parameter to the function.
    
    @param param2 Describe the second parameter to the function.

  @Returns
    List (if feasible) and describe the return values of the function.
    <ul>
      <li>1   Indicates an error occurred
      <li>0   Indicates an error did not occur
    </ul>

  @Remarks
    Describe any special behavior not described above.
    <p>
    Any additional remarks.

  @Example
    @code
    if(ExampleFunctionName(1, 2) == 0)
    {
        return 3;
    }
 */

ATCADeviceType APP_SECURITY_GetDeviceType(uint8_t revision_byte)
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

ATCA_STATUS APP_SECURITY_CheckDeviceType(ATCAIfaceCfg* cfg, bool overwrite)
{

    
    do
   {
      if ((status = atcab_init(cfg)) != ATCA_SUCCESS)
      {
      //   printf("atcab_init() failed with ret=0x%08X\r\n", status);
         break;
      }
      
                  
      // Request the Revision Number
      if ((status = atcab_info(revision)) != ATCA_SUCCESS)
      {
         printf("atcab_info() failed with ret=0x%08X\r\n", status);
         break;
      }
      

      displaylen = sizeof(displaystr);
      atcab_bin2hex(revision, sizeof(revision), displaystr, &displaylen);
     // printf("\nDevice revision: %s\r\n", displaystr);

      // Request the Serial Number
      if ((status = atcab_read_serial_number(serial_number)) != ATCA_SUCCESS)
      {
         printf("atcab_info() failed with ret=0x%08X\r\n", status);
         break;
      }
      displaylen = sizeof(displaystr);
      atcab_bin2hex(serial_number, sizeof(serial_number), displaystr, &displaylen);
      printf("\nDevice serial number: %s\r\n\r\n", displaystr);

      //Selecting the right device based on the revision
      device_type = APP_SECURITY_GetDeviceType(revision[2]);
      if (cfg->devtype != device_type)
      {
         printf("Selected device id: %d, Identified device id: %d\r\n", cfg->devtype, device_type);
         if (overwrite)
         {
            printf("Device type updated!\r\n");
            cfg->devtype = device_type;
         }
         else
         {
            printf("Selected device is not found on the bus!\r\n");
            status = ATCA_GEN_FAIL;
         }
      }
   } while (0);

   (void)atcab_release();

   return status;
}


SE_PASSKEY_STATUS APP_SECURITY_ValidatePasskey()
{
   SE_PASSKEY_STATUS stat;
    if (security_active == false)
    {
        atcab_wakeup();
        security_active = true;
    }
   printf ("Passkey validation in progress...\r\n");
           
  //  passkey_send = (uint8_t *)passkey; //typecasting before sending to avoid compiler warning
    atcac_sw_sha2_256(passkey, 32, sha_digest);
                
    // Setup nonce command
    if(ATCA_SUCCESS != (status  = atcab_nonce(nonce)))
    {
         // problem in writing nonce to tempkey
        return SE_VALIDATE_FAILED;
    }                
                         
    if(ATCA_SUCCESS != (status = atcab_kdf(KDF_MODE_ALG_HKDF  | KDF_MODE_SOURCE_SLOT | KDF_MODE_TARGET_OUTPUT_ENC,
       0x0005,KDF_DETAILS_HKDF_MSG_LOC_INPUT |((uint32_t)sizeof(sha_digest) << 24),
       sha_digest,out_validate_kdf,out_nonce)))
        {  
          // KDF failed
            return SE_VALIDATE_FAILED;
        }
    else
        {
                    // KDF Passed
        }   
            
    memset(&io_dec_params, 0, sizeof(io_dec_params));
    io_dec_params.io_key = io_protection_key;
    io_dec_params.out_nonce = out_nonce;
    io_dec_params.data = out_validate_kdf;
    io_dec_params.data_size = 32;
    status = atcah_io_decrypt(&io_dec_params);
                
                
    NVMCTRL_Read ((uint32_t *)User_key_fetch, sizeof(User_key_fetch),(uint32_t)(nvm_data_flash_user_start_address+(0x100*passkey_slot)));                        
    while(NVMCTRL_IsBusy());
    
    for (uint8_t j=0;j<32;j++)
        User_key_fetch_temp[j] = User_key_fetch[j];
                
    if (memcmp(User_key_fetch_temp,out_validate_kdf,32) == 0)
        {
            /* Passkey verification successful */
                    
         if (set_new_passkey == true) // Current passkey verified, proceed to receive new key
                    {
                        current_passkey_validated = true;

                        stat= SE_SET_NEW_PASSKEY;
                        
                    }
                    else  // Current passkey verified, Open Door
                    {
                        stat= SE_ONLY_VALIDATE;
                        printf ("Passkey Valid! Access Granted\r\n");
                        //app_db_motorData.state = APP_DB_MOTOR_STATE_OPEN;
                    }
                }
                      
                else
                {
    //#                APP_Backlight(false);
    //#                APP_Backlight_FalseBlink ();
                    #if DEBUG_PRINT
                    printf("\n\r Wrong Passkey ! Access Denied");
                    #endif
                  //  memset (passkey, 0, sizeof passkey);
                    printf ("Wrong Passkey! Access Denied");
                    stat= SE_VALIDATE_FAILED;
                }
                
          
          memset (passkey, 0, 32);// Reset passkey received from touchpad
          return stat;
} 


bool APP_SECURITY_SetNewPasskey()
{
    if (security_active == false)
    {
        atcab_wakeup();
        security_active = true;
    }
            
    APP_Random_Generation();

    atcac_sw_sha2_256(passkey, 32, sha_digest);        

    if(ATCA_SUCCESS != (status  = atcab_nonce(nonce)))
    {
       /* Problem in writing nonce to tempkey */
        return 0;
    }
            
    if(ATCA_SUCCESS != (status = atcab_kdf(KDF_MODE_ALG_HKDF  | KDF_MODE_SOURCE_SLOT | KDF_MODE_TARGET_OUTPUT_ENC,
      0x0005,KDF_DETAILS_HKDF_MSG_LOC_INPUT |((uint32_t)sizeof(sha_digest) << 24),
      sha_digest,store_kdf_userkey,out_nonce)))
    {
                /* KDF encrypt Out Failed */
        return 0;
    }
                 
    else 
    {
                /* KDF Encrypt out success */
    }                                       
            
        memset(&io_dec_params, 0, sizeof(io_dec_params));
        io_dec_params.io_key = io_protection_key;
        io_dec_params.out_nonce = out_nonce;
        io_dec_params.data = store_kdf_userkey;
        io_dec_params.data_size = 32;
        status = atcah_io_decrypt(&io_dec_params);

        if (default_key_store == true)
            {
                for(uint8_t user=2; user<=5; user++)
                {
                    APP_WritePasskey_Dataflash ((uint32_t *) store_kdf_userkey, user);
                }
                printf("Passkeys encrypted and stored successfully!\r\n");
                default_key_store = false;
            }
        else
            {
                APP_WritePasskey_Dataflash ((uint32_t *) store_kdf_userkey, passkey_slot);
                printf("Passkey encrypted and stored successfully!\r\n");
            }

           
        memset (passkey, 0, 32); // Reset passkey received from touchpad
        
        return true;
           
}

bool APP_SECURITY_SaveTempPasskey()
{
    uint8_t passkey_send[33];
    
    if (security_active == false)
    {
         cfg3 = &atecc608_0_init_data;

        atcab_init(cfg3);

        atcab_wakeup();
        security_active = true;
    }
    APP_Random_Generation();
            // Setup nonce command
    memset(&temp_key, 0, sizeof(temp_key));
            memset(&nonce_params, 0, sizeof(nonce_params));
            nonce_params.mode = NONCE_MODE_SEED_UPDATE;
            nonce_params.zero = 0;
            nonce_params.num_in = rand_number;
            nonce_params.rand_out = rand_out;
            nonce_params.temp_key = &temp_key;
             
            // Create random nonce
            if ((status = atcab_nonce_rand(nonce_params.num_in, rand_out)) != ATCA_SUCCESS)
            {
                return 0;
            }
            
            
            // Calculate nonce in host
            if ((status = atcah_nonce(&nonce_params)) != ATCA_SUCCESS)
            {
                printf("Nonce failure\r\n");
                return 0;
            }
            
            memcpy(temp_passkey,nonce_params.temp_key->value,32);

            memset (passkey, 0, 32); // Reset passkey
            
            /* Extract 5 digit passkey */
                uint8_t i,j=0;
                for(i=0;i<30;i+=6)
                {
                    itoa((temp_passkey[i]% 10), (char*)(passkey+j), 10);
                    j++;
                }
           
            memcpy(&passkey_send[1], passkey, 32);
            passkey_send[0] = 0xAA; //First byte used as message type identifier in Android app
           
            simpleMAP_APPLICATION_SEND_MESSAGE(&passkey_send[0],32,false,false);
            
            
            APP_Random_Generation();

            //passkey_send = (uint8_t *)passkey; //typecasting before sending to avoid compiler warning
            atcac_sw_sha2_256(passkey, 32, sha_digest);              
            
            
            if(ATCA_SUCCESS != (status  = atcab_nonce(nonce)))
            {
                /* Problem in writing nonce to tempkey */
                return 0;
            }
                
            
            
            if(ATCA_SUCCESS != (status = atcab_kdf(KDF_MODE_ALG_HKDF  | KDF_MODE_SOURCE_SLOT | KDF_MODE_TARGET_OUTPUT_ENC,
            0x0005,
            KDF_DETAILS_HKDF_MSG_LOC_INPUT |((uint32_t)sizeof(sha_digest) << 24),
            sha_digest,
            store_kdf_userkey,
            out_nonce)))
            {
                /* KDF encrypt Out Failed */
                return 0;
            }
            
        
            else 
            {
                /* KDF Encrypt out success */
               
            }                                       
            
            memset(&io_dec_params, 0, sizeof(io_dec_params));
            io_dec_params.io_key = io_protection_key;
            io_dec_params.out_nonce = out_nonce;
            io_dec_params.data = store_kdf_userkey;
            io_dec_params.data_size = 32;
            status = atcah_io_decrypt(&io_dec_params);
           
    
            
            APP_WritePasskey_Dataflash ((uint32_t *) store_kdf_userkey, temp_passkey_slot);
            printf("Temporary Passkey encrypted and stored successfully!\r\n");
            
            temp_key_active = true;
   //#         SYS_TIME_CallbackRegisterMS(Tempkey_Expire_Callback, 0, 50000, SYS_TIME_SINGLE);

            memset (passkey, 0, 32); // Reset passkey received from touchpad
            return 1;
}    

void APP_SECURITY_Wait()
{
    if (security_active == true)
    {
        atcab_sleep();
        security_active = false;  
    }
   
}

bool APP_SECURITY_GetTempkeyStatus(void)
{
    return temp_key_active;
}

void APP_SECURITY_SetTempkeyStatus(bool status)
{
    temp_key_active = status;
}

void APP_SECURITY_SetPasskeySlot(uint8_t slot)
{
    passkey_slot = slot;
}

bool APP_SECURITY_GetPasskeyValidationStatus(void)
{
    return current_passkey_validated;
}

void APP_SECURITY_SetPasskeyValidationStatus(bool status)
{
    current_passkey_validated = status;
}

void APP_SECURITY_SetNewPasskeyStatus(bool status)
{
    set_new_passkey=status;
}

bool APP_SECURITY_GetNewPasskeyStatus(void)
{
    return set_new_passkey;
}

void APP_SECURITY_SetPasskeyData(uint8_t* passkey_data)
{
    passkey=passkey_data;
}

void APP_SECURITY_SetDefaultKeyStore(bool state)
{
    default_key_store = state;
}
/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

// *****************************************************************************

/** 
  @Function
    int ExampleInterfaceFunctionName ( int param1, int param2 ) 

  @Summary
    Brief one-line description of the function.

  @Remarks
    Refer to the example_file.h interface header for function usage details.
 */


/* *****************************************************************************
 End of File
 */
