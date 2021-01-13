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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include "definitions.h"                // SYS function prototypes

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

#define TEMP_SENSOR_SLAVE_ADDR                         0x004F
#define TEMP_SENSOR_REG_ADDR                           0x00

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

/* Interrupt flags for ADC WindowMonitoring, SERCOM3_I2C, DMA Transfer and Sleep mode*/
volatile bool isADCWinMonitorEvent = false;
volatile bool isTemperatureRead = false;
volatile bool isDMATransferComplete = false;
volatile bool sleepMode = false;

static uint8_t temperatureVal;
static uint8_t i2cWrData = TEMP_SENSOR_REG_ADDR;
static uint8_t i2cRdData[2] = {0};
static uint8_t uartTxBuffer[100] = {0};
volatile uint8_t oledBootupTimerCnt = 0;

uint8_t adcResult = 0;
leFixedString startStr;
static leChar currTimeStr[15];

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* Handler for DMA channel transfer interrupt */
static void dmaChannel0Handler (DMAC_TRANSFER_EVENT event, uintptr_t contextHandle)
{
    /* Check the DMA transfer was completed before starting new transfer */
    if(event == DMAC_TRANSFER_EVENT_COMPLETE)
    {
        isDMATransferComplete = true;
    }
}

/* Handler for I²C interrupt */
static void i2cEventHandler (uintptr_t contextHandle)
{
    /* Check that there were no error during SERCOM3_I2C read for temperature */
    if(SERCOM2_I2C_ErrorGet() == SERCOM_I2C_ERROR_NONE)
    {
        isTemperatureRead = true;
    }
    
    else
    {
        /* Display message on terminal */
        printf ("\r\nThere were an error during I2C Transmit. Please ensure that the I/O1 Xplained Pro is connected to the board.\n\n\r\n");
    }
}

/* Handler for ADC Window Monitor Interrupt */
static void adcEventHandler (ADC_STATUS status, uintptr_t context)
{
    /* Set ADC WinMon flag after Window Monitoring Interrupt */
    isADCWinMonitorEvent = true;
    ADC0_LastConversionResultGet();
}

/* Handler for button switch interrupt using EIC peripheral */
static void EIC_User_Handler (uintptr_t context)
{
    /* Set sleepmode flag after interrupt from button pressure */
    sleepMode = true;
}

/* Handler for Systick peripheral */
static void SYSTICK_TimerCallbackHandler (uintptr_t context)
{
    /* Set OLED Bootup time completed */
    oledBootupTimerCnt = oledBootupTimerCnt + 1;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

/***************************************************************************************
 * Convert the temperature value read from sensor to readable format (Degree Fahrenheit)
 * For demonstration purpise, temperature value is assumed to be positive
 * The maximum positive temperature measured by sensor is +257 °F (+125 °C) 
 **************************************************************************************/
static uint8_t getTemperature (uint8_t* rawTempValue)
{
    uint16_t temp;
    /* Convert measured value in Degree Fahrenheit (°F) */
    temp = (rawTempValue[0] << 8) | rawTempValue[1];
    temp = (temp >> 7) * 0.5;
    temp = (temp * 9/5) + 32;
    
    return (uint8_t)temp;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

//leFixedString startStr;
//static leChar currTimeStr[15];

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;

    leFixedString_Constructor(&startStr, currTimeStr, 4);
    startStr.fn->setFont(&startStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                              string_String.index,
                                                              0));
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
    static char lcl_currTimeStr[15];           

    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            /* Initialize the EIC callback register */
            EIC_CallbackRegister (EIC_PIN_15, EIC_User_Handler, 0);

            /* Initialize the SERCOM 2 I²C callback register */
            SERCOM2_I2C_CallbackRegister (i2cEventHandler, 0);

            /* Initialize the DMA channel 0 callback register */
            DMAC_ChannelCallbackRegister (DMAC_CHANNEL_0, dmaChannel0Handler, 0);

            /* Initialize the ADC0 callback register */
            ADC0_CallbackRegister (adcEventHandler, 0);

            /* Enable ADC */
            ADC0_Enable ();

            /* Start RTC counter */
            RTC_Timer32Start ();

            /* Display example title */
            printf ("\n\n\r---------------------------------------------------------");
            printf ("\n\r  Low-power Application on SAM E51 CNano Evaluation Kit  ");
            printf ("\n\r---------------------------------------------------------\n\n\r");

            SYSTICK_TimerStart();
            SYSTICK_TimerCallbackSet(SYSTICK_TimerCallbackHandler, 0);

//            sprintf( (char*)lcl_currTimeStr, "000F");
//            startStr.fn->setFromCStr(&startStr, (char*)lcl_currTimeStr);
//            Screen0_TextFieldWidget0->fn->setString(Screen0_TextFieldWidget0, (leString*)&startStr);
            /* Read the temperature sensor value from I/O1 Xplained Pro through SERCOM3 I²C */
            SERCOM2_I2C_WriteRead (TEMP_SENSOR_SLAVE_ADDR, &i2cWrData, 1, i2cRdData, 2);
            
            appData.state = APP_STATE_OLED_BOOT_STATE;
            break;
        }
        case APP_STATE_OLED_BOOT_STATE:
        {
            if (isTemperatureRead == true)
            {
                isTemperatureRead = false;
                /* Store the temperature sensor value on temperatureVal */
                temperatureVal = getTemperature (i2cRdData);
                
                sprintf( (char*)lcl_currTimeStr, "%03dF",temperatureVal);
                startStr.fn->setFromCStr(&startStr, (char*)lcl_currTimeStr);
                Screen0_TextFieldWidget0->fn->setString(Screen0_TextFieldWidget0, (leString*)&startStr);

                /* Fill uartTxBuffer variable with message containing temperature value to display on terminal */
                sprintf ((char*)uartTxBuffer, "\r\nTemperature = %02d F \r\n", temperatureVal);
                /* Check that the SERCOM3 USART is ready for new data */
                while (!SERCOM5_USART_TransmitterIsReady());
                /* Transmit the uartTxBuffer variable content to terminal through SERCOM3 USART peripheral */
                printf ("%s", (char*)uartTxBuffer);
            }
            if(3 == oledBootupTimerCnt)
            {
                SYSTICK_TimerStop();
                appData.state = APP_STATE_SERVICE_TASKS;
                
                printf ("\r\nEnter in Standby sleep mode\n\n\r\n");

                /* Put the device in Standby mode */
                PM_StandbyModeEnter ();
            }

            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {
            if (isADCWinMonitorEvent == true)
            {            
                isADCWinMonitorEvent = false;
                /* Switch on LED0 */
                LED0_Clear ();
                /* Display message on terminal */
                printf ("\r\nADC_WINMON Interrupt Detected. Wake-up from sleep mode.\r\n");
                /* Read the temperature sensor value from I/O1 Xplained Pro through SERCOM3 I²C */
                SERCOM2_I2C_WriteRead (TEMP_SENSOR_SLAVE_ADDR, &i2cWrData, 1, i2cRdData, 2);
            }

            if (isTemperatureRead == true)
            {
                isTemperatureRead = false;
                /* Store the temperature sensor value on temperatureVal */
                temperatureVal = getTemperature (i2cRdData);
                
                sprintf( (char*)lcl_currTimeStr, "%03dF",temperatureVal);
                startStr.fn->setFromCStr(&startStr, (char*)lcl_currTimeStr);
                Screen0_TextFieldWidget0->fn->setString(Screen0_TextFieldWidget0, (leString*)&startStr);

                /* Fill uartTxBuffer variable with message containing temperature value to display on terminal */
                sprintf ((char*)uartTxBuffer, "\r\nTemperature = %02d F \r\n", temperatureVal);
                /* Check that the SERCOM3 USART is ready for new data */
                while (!SERCOM5_USART_TransmitterIsReady());
                /* Transmit the uartTxBuffer variable content to terminal through SERCOM3 USART peripheral */
                DMAC_ChannelTransfer (DMAC_CHANNEL_0, uartTxBuffer, (const void*)&(SERCOM5_REGS->USART_INT.SERCOM_DATA), sizeof(uartTxBuffer));
            }

            if (isDMATransferComplete == true)
            {      
                isDMATransferComplete = false;
                /* Display message on terminal */
                printf("\r\nDMA transfer completed. Enter in Standby sleep mode.\r\n");
                /* Switch off LED0 */
                LED0_Set ();
                /* Put device in Standby mode */
                PM_StandbyModeEnter ();
            }

            if (sleepMode == true)
            {
                sleepMode = false;
                /* Display message on terminal */
                printf ("\r\nSW0 button pressed. Enter in Idle sleep mode.\r\n");
                /* Switch off LED0 */
                LED0_Set ();
                /* Put the device in Idle mode */
                PM_IdleModeEnter ();
            }
            break;
        }

        /* TODO: implement your application state machine.*/


        /* The default state should never be executed. */
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
