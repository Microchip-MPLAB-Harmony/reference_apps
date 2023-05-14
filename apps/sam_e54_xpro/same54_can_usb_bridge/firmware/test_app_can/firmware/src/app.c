/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************


//#include <stddef.h>                     // Defines NULL
//#include <stdbool.h>                    // Defines true
//#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "app.h"
#include "definitions.h"                // SYS function prototypes

//#include "peripheral/can/plib_can1.c"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

#define BTL_TRIGGER_PATTERN (0x5048434DUL)

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;

static uint32_t *ramStart = (uint32_t *)BTL_TRIGGER_RAM_START;

uint8_t Can1MessageRAM[CAN1_MESSAGE_RAM_CONFIG_SIZE] __attribute__((aligned (32)));

/* Standard identifier id[28:18]*/
#define WRITE_ID(id) (id << 18)
#define READ_ID(id)  (id >> 18)

/* Application's state machine enum */
typedef enum
{
    APP_STATE_CAN_RECEIVE,
    APP_STATE_CAN_TRANSMIT,
    APP_STATE_CAN_IDLE,
    APP_STATE_CAN_XFER_SUCCESSFUL,
    APP_STATE_CAN_XFER_ERROR,
    APP_STATE_CAN_USER_INPUT
} APP_CAN_STATES;

/* Variable to save Tx/Rx transfer status and context */
static uint32_t status = 0;
static uint32_t xferContext = 0;
/* Variable to save Tx/Rx message */
static uint8_t loop_count = 0;
static uint8_t user_input = 0,nominal_value=0,data_value=0;
/* Variable to save application state */
volatile static APP_CAN_STATES state = APP_STATE_CAN_USER_INPUT;

static uint8_t txFiFo[CAN1_TX_FIFO_BUFFER_SIZE];
static uint8_t rxFiFo0[CAN1_RX_FIFO0_SIZE];
static uint8_t rxFiFo1[CAN1_RX_FIFO1_SIZE];
static uint8_t rxBuffer[CAN1_RX_BUFFER_SIZE];

CAN_TX_BUFFER *txBuffer = NULL;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/

/* Message Length to Data length code */
static uint8_t CANLengthToDlcGet(uint8_t length)
{
    uint8_t dlc = 0;

    if (length <= 8U)
    {
        dlc = length;
    }
    else if (length <= 12U)
    {
        dlc = 0x9U;
    }
    else if (length <= 16U)
    {
        dlc = 0xAU;
    }
    else if (length <= 20U)
    {
        dlc = 0xBU;
    }
    else if (length <= 24U)
    {
        dlc = 0xCU;
    }
    else if (length <= 32U)
    {
        dlc = 0xDU;
    }
    else if (length <= 48U)
    {
        dlc = 0xEU;
    }
    else
    {
        dlc = 0xFU;
    }
    return dlc;
}

/* Data length code to Message Length */
static uint8_t CANDlcToLengthGet(uint8_t dlc)
{
    uint8_t msgLength[] = {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 12U, 16U, 20U, 24U, 32U, 48U, 64U};
    return msgLength[dlc];
}

/*CAN bitrate change*/
void CAN_change_speed(uint32_t nominal, uint32_t data)
{
uint64_t can_clock = 60000000;

uint8_t NBRP=5,DBRP=0;
uint32_t NTq=0,NTseg1=0,NTseg2=0,NSJW=0;
uint32_t DTq=0,DTseg1=0,DTseg2=0,DSJW=7;

if(data == 1000)
{
    DBRP=5;
}



NTq = can_clock/((nominal*1000)*(NBRP+1));
NTseg1 = ((NTq)*(75) )/100;
NTseg2 = NTq-NTseg1-1;
NTseg1=NTseg1-2;
NSJW=NTseg2;    
NTseg1=NTseg1+1;
NTseg2=NTseg2+1;



DTq = can_clock/((data * 1000)*(DBRP+1));
DTseg1 = (DTq*75)/100;
DTseg2 = DTq-DTseg1-1;
DTseg1 = DTseg1-2;
DSJW = DTseg2;
DTseg1=DTseg1+1;
DTseg2=DTseg2+1;



/* Start CAN initialization */
    CAN1_REGS->CAN_CCCR = CAN_CCCR_INIT_Msk;
    while ((CAN1_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) != CAN_CCCR_INIT_Msk)
    {
        /* Wait for initialization complete */
    }



   /* Set CCE to unlock the configuration registers */
    CAN1_REGS->CAN_CCCR |= CAN_CCCR_CCE_Msk;



   /* Set Data Bit Timing and Prescaler Register */
    CAN1_REGS->CAN_DBTP = CAN_DBTP_DTSEG2(DTseg2-1) | CAN_DBTP_DTSEG1(DTseg1-1) | CAN_DBTP_DBRP(DBRP) | CAN_DBTP_DSJW(DSJW);



   /* Set Nominal Bit timing and Prescaler Register */
    CAN1_REGS->CAN_NBTP  = CAN_NBTP_NTSEG2(NTseg2-1) | CAN_NBTP_NTSEG1(NTseg1-1) | CAN_NBTP_NBRP(NBRP) | CAN_NBTP_NSJW(NSJW-1);


   CAN1_REGS->CAN_CCCR &= ~CAN_CCCR_INIT_Msk;
    while ((CAN1_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) == CAN_CCCR_INIT_Msk)
    {
        /* Wait for initialization complete */
    }

}

/* Menu */
static void display_menu(void)
{
	printf("Menu :\r\n"
	       "  -- Select the action:\r\n"
	       "  0: Send FD standard message with ID: 0x44A and 64 byte data 0 to 63. \r\n"
	       "  1: Send FD standard message with ID: 0x469 and 64 byte data 128 to 191. \r\n"
	       "  2: Send FD extended message with ID: 0x100000A5 and 64 byte data 0 to 63. \r\n"
	       "  3: Send FD extended message with ID: 0x10000096 and 64 byte data 128 to 191. \r\n"
	       "  4: Send normal standard message with ID: 0x469 and 8 byte data 0 to 7. \r\n"
           "  5: Change CAN bit rates \r\n"
           "  b: Trigger the bootloader \r\n"
	       "  m: Display menu \r\n\r\n");
}

/* Print Rx Message */
static void print_message(uint8_t numberOfMessage, CAN_RX_BUFFER *rxBuf, uint8_t rxBufLen, uint8_t rxFifoBuf)
{
    uint8_t length = 0;
    uint8_t msgLength = 0;
    uint32_t id = 0;

    if (rxFifoBuf == 0)
        printf(" Rx FIFO0 :");
    else if (rxFifoBuf == 1)
        printf(" Rx FIFO1 :");
    else if (rxFifoBuf == 2)
        printf(" Rx Buffer :");

    for (uint8_t count = 0; count < numberOfMessage; count++)
    {
        /* Print message to Console */
        printf(" New Message Received\r\n");
        id = rxBuf->xtd ? rxBuf->id : READ_ID(rxBuf->id);
        msgLength = CANDlcToLengthGet(rxBuf->dlc);
        length = msgLength;
        printf(" Message - Timestamp : 0x%x ID : 0x%x Length : 0x%x ", (unsigned int)rxBuf->rxts, (unsigned int)id, (unsigned int)msgLength);
        printf("Message : ");
        while(length)
        {
            printf("0x%x ", rxBuf->data[msgLength - length--]);
        }
        printf("\r\n");
        rxBuf += rxBufLen;
    }
}

/* This function will be called by CAN PLIB when transfer is completed from Tx FIFO */
void APP_CAN_TxFifoCallback(uintptr_t context)
{
    xferContext = context;

    /* Check CAN Status */
    status = CAN1_ErrorGet();

    if (((status & CAN_PSR_LEC_Msk) == CAN_ERROR_NONE) || ((status & CAN_PSR_LEC_Msk) == CAN_ERROR_LEC_NC))
    {
        switch ((APP_CAN_STATES)context)
        {
            case APP_STATE_CAN_TRANSMIT:
            {
                state = APP_STATE_CAN_XFER_SUCCESSFUL;
                break;
            }
            default:
                break;
        }
    }
    else
    {
        state = APP_STATE_CAN_XFER_ERROR;
    }
}

/* This function will be called by CAN PLIB when Message received in Rx Buffer */
void APP_CAN_RxBufferCallback(uint8_t bufferNumber, uintptr_t context)
{
    xferContext = context;

    /* Check CAN Status */
    status = CAN1_ErrorGet();

    if (((status & CAN_PSR_LEC_Msk) == CAN_ERROR_NONE) || ((status & CAN_PSR_LEC_Msk) == CAN_ERROR_LEC_NC))
    {
        switch ((APP_CAN_STATES)context)
        {
            case APP_STATE_CAN_RECEIVE:
            {
                memset(rxBuffer, 0x00, CAN1_RX_BUFFER_ELEMENT_SIZE);
                if (CAN1_MessageReceive(bufferNumber, (CAN_RX_BUFFER *)rxBuffer) == true)
                {
                    print_message(1, (CAN_RX_BUFFER *)rxBuffer, CAN1_RX_BUFFER_ELEMENT_SIZE, 2);
                    state = APP_STATE_CAN_XFER_SUCCESSFUL;
                }
                else
                {
                    state = APP_STATE_CAN_XFER_ERROR;
                }
                break;
            }
            default:
                break;
        }
    }
    else
    {
        state = APP_STATE_CAN_XFER_ERROR;
    }
}

/* This function will be called by CAN PLIB when Message received in Rx FIFO0 */
void APP_CAN_RxFifo0Callback(uint8_t numberOfMessage, uintptr_t context)
{
    xferContext = context;

    /* Check CAN Status */
    status = CAN1_ErrorGet();

    if (((status & CAN_PSR_LEC_Msk) == CAN_ERROR_NONE) || ((status & CAN_PSR_LEC_Msk) == CAN_ERROR_LEC_NC))
    {
        switch ((APP_CAN_STATES)context)
        {
            case APP_STATE_CAN_RECEIVE:
            {
                memset(rxFiFo0, 0x00, (numberOfMessage * CAN1_RX_FIFO0_ELEMENT_SIZE));
                if (CAN1_MessageReceiveFifo(CAN_RX_FIFO_0, numberOfMessage, (CAN_RX_BUFFER *)rxFiFo0) == true)
                {
                    print_message(numberOfMessage, (CAN_RX_BUFFER *)rxFiFo0, CAN1_RX_FIFO0_ELEMENT_SIZE, 0);
                    state = APP_STATE_CAN_XFER_SUCCESSFUL;
                }
                else
                {
                    state = APP_STATE_CAN_XFER_ERROR;
                }
                break;
            }
            default:
                break;
        }
    }
    else
    {
        state = APP_STATE_CAN_XFER_ERROR;
    }
}

/* This function will be called by CAN PLIB when Message received in Rx FIFO1 */
void APP_CAN_RxFifo1Callback(uint8_t numberOfMessage, uintptr_t context)
{
    xferContext = context;

    /* Check CAN Status */
    status = CAN1_ErrorGet();

    if (((status & CAN_PSR_LEC_Msk) == CAN_ERROR_NONE) || ((status & CAN_PSR_LEC_Msk) == CAN_ERROR_LEC_NC))
    {
        switch ((APP_CAN_STATES)context)
        {
            case APP_STATE_CAN_RECEIVE:
            {
                memset(rxFiFo1, 0x00, (numberOfMessage * CAN1_RX_FIFO1_ELEMENT_SIZE));
                if (CAN1_MessageReceiveFifo(CAN_RX_FIFO_1, numberOfMessage, (CAN_RX_BUFFER *)rxFiFo1) == true)
                {
                    print_message(numberOfMessage, (CAN_RX_BUFFER *)rxFiFo1, CAN1_RX_FIFO1_ELEMENT_SIZE, 1);
                    state = APP_STATE_CAN_XFER_SUCCESSFUL;
                }
                else
                {
                    state = APP_STATE_CAN_XFER_ERROR;
                }
                break;
            }
            default:
                break;
        }
    }
    else
    {
        state = APP_STATE_CAN_XFER_ERROR;
    }
}


void CAN_Task()
{
    bool static can_initialize=1;
    
    if(can_initialize)
    {
    printf(" ------------------------------ \r\n");
    printf("        CAN FD Demo            \r\n");
    printf(" ------------------------------ \r\n");
    
    /* Set Message RAM Configuration */
    CAN1_MessageRAMConfigSet(Can1MessageRAM);

    CAN1_RxFifoCallbackRegister(CAN_RX_FIFO_0, APP_CAN_RxFifo0Callback, APP_STATE_CAN_RECEIVE);
    CAN1_RxFifoCallbackRegister(CAN_RX_FIFO_1, APP_CAN_RxFifo1Callback, APP_STATE_CAN_RECEIVE);
    CAN1_RxBuffersCallbackRegister(APP_CAN_RxBufferCallback, APP_STATE_CAN_RECEIVE);

    display_menu();
    can_initialize=0;
    }
    
    if (state == APP_STATE_CAN_USER_INPUT)
        {
            /* Read user input */
        scanf("%c", (char *) &user_input);
         
            switch (user_input)
            {
				case '0':
                    memset(txFiFo, 0x00, CAN1_TX_FIFO_BUFFER_ELEMENT_SIZE);
                    txBuffer = (CAN_TX_BUFFER *)txFiFo;
                    txBuffer->id = WRITE_ID(0x44A);
                    txBuffer->dlc = CANLengthToDlcGet(64);
                    txBuffer->fdf = 1;
                    txBuffer->brs = 1;
					for (loop_count = 0; loop_count < 64; loop_count++){
						txBuffer->data[loop_count] = loop_count;
					}                
					printf("  0: Send FD standard message with ID: 0x44A and 64 byte data 0 to 63.\r\n");
                    CAN1_TxFifoCallbackRegister( APP_CAN_TxFifoCallback, (uintptr_t)APP_STATE_CAN_TRANSMIT );
                    state = APP_STATE_CAN_IDLE;
                    if (CAN1_MessageTransmitFifo(1, txBuffer) == false)
                    {
                        printf(" Failed \r\n");
                    }             
                    break;
				case '1':
                    memset(txFiFo, 0x00, CAN1_TX_FIFO_BUFFER_ELEMENT_SIZE);
                    txBuffer = (CAN_TX_BUFFER *)txFiFo;
                    txBuffer->id = WRITE_ID(0x469);
                    txBuffer->dlc = CANLengthToDlcGet(64);
                    txBuffer->fdf = 1;
                    txBuffer->brs = 1;
					for (loop_count = 128; loop_count < 192; loop_count++){
						txBuffer->data[loop_count - 128] = loop_count;
					}                
 					printf("  1: Send FD standard message with ID: 0x469 and 64 byte data 128 to 191.\r\n");
					CAN1_TxFifoCallbackRegister( APP_CAN_TxFifoCallback, (uintptr_t)APP_STATE_CAN_TRANSMIT );
                    state = APP_STATE_CAN_IDLE;
					if (CAN1_MessageTransmitFifo(1, txBuffer) == false)
                    {
                        printf(" Failed \r\n");
                    }             
                    break;
				case '2':
                    memset(txFiFo, 0x00, CAN1_TX_FIFO_BUFFER_ELEMENT_SIZE);
                    txBuffer = (CAN_TX_BUFFER *)txFiFo;
                    txBuffer->id = 0x100000A5;
                    txBuffer->dlc = CANLengthToDlcGet(64);
                    txBuffer->xtd = 1;
                    txBuffer->fdf = 1;
                    txBuffer->brs = 1;
					for (loop_count = 0; loop_count < 64; loop_count++){
						txBuffer->data[loop_count] = loop_count;
					}
					printf("  2: Send FD extended message with ID: 0x100000A5 and 64 byte data 0 to 63.\r\n");
                    CAN1_TxFifoCallbackRegister( APP_CAN_TxFifoCallback, (uintptr_t)APP_STATE_CAN_TRANSMIT );
                    state = APP_STATE_CAN_IDLE;
                    if (CAN1_MessageTransmitFifo(1, txBuffer) == false)
                    {
                        printf(" Failed \r\n");
                    }
                    break;
				case '3':
                    memset(txFiFo, 0x00, CAN1_TX_FIFO_BUFFER_ELEMENT_SIZE);
                    txBuffer = (CAN_TX_BUFFER *)txFiFo;
                    txBuffer->id = 0x10000096;
                    txBuffer->dlc = CANLengthToDlcGet(64);
                    txBuffer->xtd = 1;
                    txBuffer->fdf = 1;
                    txBuffer->brs = 1;
					for (loop_count = 128; loop_count < 192; loop_count++){
						txBuffer->data[loop_count - 128] = loop_count;
					}
					printf("  3: Send FD extended message with ID: 0x10000096 and 64 byte data 128 to 191.\r\n");
                    CAN1_TxFifoCallbackRegister( APP_CAN_TxFifoCallback, (uintptr_t)APP_STATE_CAN_TRANSMIT );
                    state = APP_STATE_CAN_IDLE;
                    if (CAN1_MessageTransmitFifo(1, txBuffer) == false)
                    {
                        printf(" Failed \r\n");
                    }
                    break;
				case '4':
                    memset(txFiFo, 0x00, CAN1_TX_FIFO_BUFFER_ELEMENT_SIZE);
                    txBuffer = (CAN_TX_BUFFER *)txFiFo;
					txBuffer->id = WRITE_ID(0x469);
                    txBuffer->dlc = 8;
					for (loop_count = 0; loop_count < 8; loop_count++){
						txBuffer->data[loop_count] = loop_count;
					}                
 					printf("  4: Send normal standard message with ID: 0x469 and 8 byte data 0 to 7.\r\n");
					CAN1_TxFifoCallbackRegister( APP_CAN_TxFifoCallback, (uintptr_t)APP_STATE_CAN_TRANSMIT );
                    state = APP_STATE_CAN_IDLE;
					if (CAN1_MessageTransmitFifo(1, txBuffer) == false)
                    {
                        printf(" Failed \r\n");
                    }             
                    break;
                case '5':
                    {   
                        uint32_t nominal_v=0,data_v=0;
                        printf("CAN Nominal bit rate available options \r\n 1.250 \r\n 2.500 \r\n");
                        scanf("%c", (char *) &nominal_value);
                        printf("CAN Data bit rate available options\r\n 1.1000 \r\n"
                                " 2.2000 \r\n 3.3000 \r\n 4.4000 \r\n");
                        scanf("%c", (char *) &data_value);
                        
                        if(nominal_value=='1')
                            nominal_v=250;
                        else if(nominal_value=='2')
                            nominal_v=500;
                        else 
                        {
                            printf("\r\n You have entered wrong nominal bit rate value\r\n");
                            break; 
                        }
                        
                        if(data_value=='1')
                            data_v=1000;
                        else if(data_value=='2')
                            data_v=2000;
                        else if(data_value=='3')
                            data_v=3000;
                        else if(data_value=='4')
                            data_v=4000;
                        else
                        {   
                           printf("\r\n You have entered wrong data bit rate value\r\n");
                            break; 
                        }
                        //scanf("%u",data_v); 
                        CAN_change_speed(nominal_v,data_v);
                        printf("CAN bit rate changed successfully");
                    }
                    break;
				case 'm':
				case 'M':
					display_menu();
					break;
                
                case 'b':
                case 'B':
                {
                    appData.state = APP_TRIGGER_BOOTLOADER;
                    break; 
				}	
				default:
					printf(" Invalid Input \r\n");
					break;
            }
        }

        /* Check the application's current state. */
        switch (state)
        {
            case APP_STATE_CAN_IDLE:
            {
          
                /* Application can do other task here */
                break;
            }
            case APP_STATE_CAN_XFER_SUCCESSFUL:
            {
                if ((APP_CAN_STATES)xferContext == APP_STATE_CAN_TRANSMIT)
                {
                    printf(" Success\r\n");
                }                
                state = APP_STATE_CAN_USER_INPUT;//APP_STATE_CAN_IDLE;
                break;
            }
            case APP_STATE_CAN_XFER_ERROR:
            {
                if ((APP_CAN_STATES)xferContext == APP_STATE_CAN_RECEIVE)
                {
                    printf(" Error in received message\r\n");
                }
                else
                {
                    printf(" Failed\r\n");
                }
                state = APP_STATE_CAN_USER_INPUT;
                break;
            }
            default:
            {
                break;
            }
        }
    

}


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    appData.state = APP_INIT;

    APP_TIMER_START();
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_INIT:
        {
            printf("\r\n####### Application loaded from Bootloader #######\r\n");
            appData.state = APP_EXECUTION;
            break;
        }

        case APP_EXECUTION:
        {

            CAN_Task();
            break;
        }

        case APP_TRIGGER_BOOTLOADER:
        {
            printf("####### Bootloader Triggered #######\r\n");

            ramStart[0] = BTL_TRIGGER_PATTERN;
            ramStart[1] = BTL_TRIGGER_PATTERN;
            ramStart[2] = BTL_TRIGGER_PATTERN;
            ramStart[3] = BTL_TRIGGER_PATTERN;

            DCACHE_CLEAN_BY_ADDR(ramStart, 16);

            APP_SystemReset();
        }

        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
