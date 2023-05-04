/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "unsecure_interface.h"
#include "simpleMAP_HAL.h"
//#include "ble_manager.h"
#include "../atca_basic.h"

/* typedef for non-secure callback functions */
typedef void (*funcptr_void) (void) __attribute__((cmse_nonsecure_call));
bool PREVIOUS_TIMER_HANDLER_PROCESSING;

//-- Initialize ECC608 and simpleMAP Library
    uint32_t flash_addresses[3] = {0x00020000,0x00020100,TZ_START_NS};

/* ************************************************************************** */
/** TIMER 0 INTERRUPT HANDLER
 */
void TC0_CH0_TimerInterruptHandler(TC_TIMER_STATUS status, uintptr_t context)
{
    //--- ENSURE ONLY ONE INSTANCE OF TIMER INTERRUPT IS RUNNING AT A TIME
    if(PREVIOUS_TIMER_HANDLER_PROCESSING) return;
    PREVIOUS_TIMER_HANDLER_PROCESSING = true;
    
    //--- MANGE BLE MODULE
    ble_module_management_task();
    
    //--- MANAGE SIMPLEMAP LIBRARY
    simpleMAP_Task();
    
    //--- ENSURE ONLY ONE INSTANCE OF TIMER INTERRUPT IS RUNNING AT A TIME
    PREVIOUS_TIMER_HANDLER_PROCESSING = false;
}

/* ************************************************************************** */
/** JUMP TO UNSECURE (->start USER APPLICATION)
 */
void jump_to_unsecure(){
    uint32_t msp_ns = *((uint32_t *)(TZ_START_NS));
    volatile funcptr_void NonSecure_ResetHandler;

    
    if (msp_ns != 0xFFFFFFFF)
    {
        //--- Set non-secure main stack (MSP_NS) 
        __TZ_set_MSP_NS(msp_ns);

        //--- Get non-secure reset handler 
        NonSecure_ResetHandler = (funcptr_void)(*((uint32_t *)((TZ_START_NS) + 4U)));

        //--- Start non-secure state software application 
        NonSecure_ResetHandler();
    }
}

//--- BLE COM : DMA TX INTERRUPT
static void ble_transmitted_data(DMAC_TRANSFER_EVENT event, uintptr_t contextHandle)
{
    simpleMAP_TRANSFER_NEXT_IN_TX_QUEUE();
}

//--- BLE COM : DMA RX INTERRUPT
static void ble_received_data(DMAC_TRANSFER_EVENT event, uintptr_t contextHandle)
{
    simpleMAP_INSERT_IN_RX_QUEUE();
}

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
ATCAIfaceCfg *cfg;
ATCA_STATUS status;
uint8_t pubkey[64];
uint8_t serial_number[9];   
char displaystr[200];
size_t displaylen;


uint8_t io_protection_key2[32]={0x7D, 0xF0, 0x8B, 0x62, 0xBA, 0xAB, 0x3F, 0xF2,
        0x7F, 0x53, 0xA4, 0xBB, 0x98, 0xB6, 0x5A, 0x0C,
        0x4F, 0x88, 0x17, 0xC6, 0x7C, 0x58, 0x30, 0xEE,
        0x32, 0x7E, 0x25, 0xCD, 0x6F, 0x30, 0x78, 0x99};
    
uint8_t master_secret[32]={
    0xd1, 0xc, 0x6, 0x82, 0x8f ,0x38, 0xf2, 0x73, 0x33, 0x72 ,0x55, 0x71, 0xe ,0x37, 0x68 ,0x1, 0x3 ,
    0xe3, 0xaa, 0x62, 0x59, 0x5f ,0x6b ,0x0, 0xd4 ,0x82 ,0x99 ,0x72, 0x3, 0xfa ,0x79 ,0x2a};

//uint8_t ROOTCA_PUBLIC[64] = {
//        0x95, 0x46, 0x54, 0x54, 0x7C, 0x94, 0x0E, 0xC6,   0x35, 0x06, 0x7E, 0xB8, 0xE5, 0xD5, 0x0F, 0x71,
//        0xC9, 0x2C, 0xC8, 0x08, 0x17, 0x6C, 0xAD, 0x3E,   0xE2, 0x5D, 0x2C, 0x34, 0xF8, 0x4F, 0x07, 0x57,
//        0x2E, 0x07, 0x42, 0xC7, 0x5B, 0x50, 0x8F, 0xF3,   0x01, 0xF5, 0x47, 0xD5, 0x3D, 0x0E, 0x77, 0x39,
//        0x82, 0xF0, 0xED, 0xAE, 0xF4, 0xBF, 0x1F, 0x25,   0x49, 0x74, 0x91, 0x72, 0xCF, 0x67, 0x10, 0x54
//    };


#if defined(__XC32__)
extern ATCAIfaceCfg atecc608_0_init_data;
#endif

uint8_t rand_number[NONCE_NUMIN_SIZE];


int main ( void )
{
    uint32_t msp_ns = *((uint32_t *)(TZ_START_NS));
    volatile funcptr_void NonSecure_ResetHandler;
   
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    
    cfg = &atecc608_0_init_data;
    
    
    /*Initialize CAL*/
    if ((status = atcab_init(cfg)) != ATCA_SUCCESS)
		printf("atcab_init() failed with ret=0x%08X\r\n", status);
    else
        printf("Initialization successful \r\n");
	
    
    /* Request the Serial Number*/
    if ((status = atcab_read_serial_number(serial_number)) != ATCA_SUCCESS)
        printf("atcab_info() failed with ret=0x%08X\r\n", status);
    else{      
        displaylen = sizeof(displaystr);
        atcab_bin2hex(serial_number, sizeof(serial_number), displaystr, &displaylen);
        printf("\nDevice serial number: %s\r\n\r\n", displaystr);
    }
    
    
    /*Get the 64-byte public key from slot 0*/
    if(ATCA_SUCCESS != (status = atcab_get_pubkey(0,pubkey)))
        printf("\n\r pubkey not read");
    else
    {
        printf("\n\r pubkey  0 read\n\r");
        for(uint8_t i=0;i<64;i++)
             printf("0x%x,",pubkey[i]);
    }
    
    /*Generate private key in slot 2 and read corresponding public key
      This API is used before storing the public key in simpleMAP cloud database*/
//    if(ATCA_SUCCESS != (status = atcab_genkey(2,pubkey)))
//        printf("\n\r pubkey not read");
//    else
//    {
//        printf("\n\r pubkey  2 read\n\r");
//        for(uint8_t i=0;i<64;i++)
//             printf("0x%x,",pubkey[i]);
//    }
    
    /*Get public key from slot 2. Used after the key is stored in database*/
    if(ATCA_SUCCESS != (status = atcab_get_pubkey(2,pubkey)))
        printf("\n\r pubkey not read");
    else
    {
        printf("\n\r pubkey  0 read\n\r");
        for(uint8_t i=0;i<64;i++)
             printf("0x%x,",pubkey[i]);
    }
//    
    /*Write the IO protect encryption key into slot 6*/
    if(ATCA_SUCCESS != (status = atcab_write_bytes_zone(ATCA_ZONE_DATA,6,0,io_protection_key2,32)))
        printf("\r\nIO Protect write Fail");        
    else
        printf("\r\n Successful IO Protect Key Write");
    
    
    /*Generate Random number for encrypt write using TRNG*/   
    APP_Random_Generation();
    
    
    /*Write Master secret into slot 5 for KDF operations*/
    if(ATCA_SUCCESS != (status = atcab_write_enc(5,0,master_secret,io_protection_key2,6,rand_number)))
        printf("\r\n Write fail, status code : %x",status);
    else
        printf("\r\n Master secret set");
    
    
    /*Write Root CA public key into slot 13*/
    if(ATCA_SUCCESS != (status = atcab_write_pubkey(13,ROOTCA_PUBLIC)))
        printf("\n\r Root CA public key not written");
    else
        printf("\r\n RootCA written successfully");
    
    
    /*Jumps to non-secure code*/
//    if (msp_ns != 0xFFFFFFFF)
//    {
//        /* Set non-secure main stack (MSP_NS) */
//        __TZ_set_MSP_NS(msp_ns);
//
//        /* Get non-secure reset handler */
//        NonSecure_ResetHandler = (funcptr_void)(*((uint32_t *)((TZ_START_NS) + 4U)));
//
//        /* Start non-secure state software application */
//        NonSecure_ResetHandler();
//    }

    while ( true )
    {
    }

    /* Execution should not come here during normal operation */
    return ( EXIT_FAILURE );
}

#if 0

int main ( void )
{
     /* Initialize all modules */
    SYS_Initialize ( NULL );
 
    //-- Initialize simpleMAP Hardware Abstraction Layer
    simpleMAP_HAL_init();
    
    
    //-- Reset BLE  BM70 module
    ble_module_reset();
    
    printf("SMART Door Lock v1.3 \r\n");
             
    //-- Initialize timer TC0 and start
    PREVIOUS_TIMER_HANDLER_PROCESSING = false;
    TC0_TimerCallbackRegister(TC0_CH0_TimerInterruptHandler, (uintptr_t)NULL);
    TC0_TimerStart();

    //-- Initialize BLE UART DMA for receiving 16bytes
    DMAC_ChannelCallbackRegister(DMAC_CHANNEL_0, ble_received_data,0);
    MCU_START_RECEIVE_ON_CHANNEL();
    
    //-- Initialize BLE UART DMA for transmitting 16bytes
    DMAC_ChannelCallbackRegister(DMAC_CHANNEL_1, ble_transmitted_data,0);
    

    simpleMAP_ASSERT_BOOL(simpleMAP_Library_init(ECC_I2C_7BIT_ADDRESS,I2C_BAUDRATE_1M,flash_addresses,(uint8_t *)default_IOPROTECTIONKEY,(uint8_t *)ROOTCA_PUBLIC),"INIT FAIL");

 
    PRESENT_FW_VER[0]    = 0x01;
    PRESENT_FW_VER[1]   = 0x01;  
    
    jump_to_unsecure();
    
    while ( true )
    {
    }

    /* Execution should not come here during normal operation */
    return ( EXIT_FAILURE );
}

#endif
/*******************************************************************************
 End of File
*/

