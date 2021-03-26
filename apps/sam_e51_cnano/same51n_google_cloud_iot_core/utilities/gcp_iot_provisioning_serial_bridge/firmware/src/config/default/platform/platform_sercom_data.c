#include "definitions.h"
#include "platform_sercom_data.h"

const PLATFORM_USART_PLIB_INTERFACE platformUsartPlibAPI = {
    .initialize             = SERCOM5_USART_Initialize,
    .readCallbackRegister   = SERCOM5_USART_ReadCallbackRegister,
    .read                   = SERCOM5_USART_Read,
    .readIsBusy             = SERCOM5_USART_ReadIsBusy,
    .readCountGet           = SERCOM5_USART_ReadCountGet,
    .writeCallbackRegister  = SERCOM5_USART_WriteCallbackRegister,
    .write                  = SERCOM5_USART_Write,
    .writeIsBusy            = SERCOM5_USART_WriteIsBusy,
    .writeCountGet          = SERCOM5_USART_WriteCountGet,
    .errorGet               = SERCOM5_USART_ErrorGet,
    .serialSetup            = SERCOM5_USART_SerialSetup
};

	
const DRV_USART_INTERRUPT_SOURCES platformInterruptSources =
{	
    /* Peripheral has more than one interrupt vector */
    .isSingleIntSrc                        = false,
 
    /* Peripheral interrupt lines */
    .intSources.multi.usartTxCompleteInt   = SERCOM5_1_IRQn,
    .intSources.multi.usartTxReadyInt      = SERCOM5_0_IRQn,
    .intSources.multi.usartRxCompleteInt   = SERCOM5_2_IRQn,
    .intSources.multi.usartErrorInt        = SERCOM5_OTHER_IRQn,
};