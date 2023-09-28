/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_cam.c

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

#include "app_cam.h"


// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_CAM_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_CAM_DATA app_camData;

static char outputMessage[16];
static char errorMessage[16] = " Scan Again...! ";


static leChar legatoCharBuffer[8] = {0};
static leFixedString OutputString;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

static void SPI_Event_Handler (
    DRV_SPI_TRANSFER_EVENT event,
    DRV_SPI_TRANSFER_HANDLE transferHandle,
    uintptr_t context
)
{
    if (event == DRV_SPI_TRANSFER_EVENT_COMPLETE)
    {
        app_camData.isTransferComplete = true;
    }
    else
    {
        app_camData.isTransferComplete = false;
        app_camData.state = APP_CAM_STATE_ERROR;
    }
}


// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

static bool Camera_Write_Reg(uint8_t reg, uint8_t data) 
{
    app_camData.writeReg[0] = reg | 0x80; 
    app_camData.writeReg[1] = data;
    
    app_camData.isTransferComplete = false;
    
    DRV_SPI_WriteTransferAdd(app_camData.spiHandle, 
            app_camData.writeReg,2, &app_camData.transferHandle);
    
    SYSTICK_DelayMs(1);
    
    while (!app_camData.isTransferComplete);
    
    return true;
}

static uint8_t Camera_Read_Reg(uint8_t reg) 
{
    app_camData.writeReg[0] = reg & 0x7F;
    
    app_camData.isTransferComplete = false;
        
    DRV_SPI_WriteReadTransferAdd(app_camData.spiHandle, 
            app_camData.writeReg, 1, app_camData.readReg, 3, &app_camData.transferHandle);
    
    SYSTICK_DelayMs(1);
    
    while (!app_camData.isTransferComplete);
    
    return app_camData.readReg[2];
}

static bool Camera_Is_Ready(void)
{
    uint8_t timeout = 50;
    
    while (timeout != 0)
	{
        Camera_Read_Reg(CAM_REG_SENSOR_STATE);
        
        if ((app_camData.readReg[2] & 0x03) == CAM_REG_SENSOR_STATE_IDLE)
        {
            timeout = 0;           
            app_camData.status = true;
        }
        
        else
        {
            timeout--;
            app_camData.status = false;
        }
        
		SYSTICK_DelayMs(2);
	}
    
    return app_camData.status;
}

uint32_t Camera_Read_Image_Size(void)
{
    uint32_t len1, len2, len3, length = 0;
    
    len1   = Camera_Read_Reg(FIFO_SIZE1);
    len2   = Camera_Read_Reg(FIFO_SIZE2);
    len3   = Camera_Read_Reg(FIFO_SIZE3);
    
    length = ((len3 << 16) | (len2 << 8) | len1) & 0xffffff;
    
    return length;
}

static void Camera_Read_Image(uint8_t* buf, uint32_t length)
{    
    app_camData.writeReg[0] = BURST_FIFO_READ; // Address to read
    app_camData.writeReg[1] = 0x00;            // Send a dummy byte

    app_camData.isTransferComplete = false;

    app_camData.isTransferComplete = false;

    DRV_SPI_WriteReadTransferAdd(app_camData.spiHandle, app_camData.writeReg, 
            1, buf, length, &app_camData.transferHandle);
    
    while (!app_camData.isTransferComplete);
   
}


static void Resize_Image(uint16_t* originalImage, uint16_t* resizedImage) 
{
    int x_ratio = (IMG_ACT_WIDTH << 16) / IMAGE_WIDTH + 1;
    int y_ratio = (IMAGE_HEIGHT << 16) / IMAGE_HEIGHT + 1;

    for (int y = 0; y < IMAGE_HEIGHT; y++) 
    {
        for (int x = 0; x < IMAGE_WIDTH; x++) 
        {
            int px = (x * x_ratio) >> 16;
            int py = (y * y_ratio) >> 16;
            
            resizedImage[y * IMAGE_WIDTH + x] = originalImage[py * IMG_ACT_WIDTH + px];
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
    void APP_CAM_Initialize ( void )

  Remarks:
    See prototype in app_cam.h.
 */

void APP_CAM_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app_camData.state           = APP_CAM_STATE_INIT;
    app_camData.transferStatus  = false;    
}

/******************************************************************************
  Function:
    void APP_CAM_Tasks ( void )

  Remarks:
    See prototype in app_cam.h.
 */


void APP_CAM_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( app_camData.state )
    {
        /* Application's initial state. */
        case APP_CAM_STATE_INIT:
        {
            app_camData.spiSetup.baudRateInHz  = 8000000;
            app_camData.spiSetup.clockPhase    = DRV_SPI_CLOCK_PHASE_VALID_LEADING_EDGE;
            app_camData.spiSetup.clockPolarity = DRV_SPI_CLOCK_POLARITY_IDLE_LOW;
            app_camData.spiSetup.dataBits      = DRV_SPI_DATA_BITS_8;
            app_camData.spiSetup.chipSelect    = (SYS_PORT_PIN)SPI_CS_PIN;
            app_camData.spiSetup.csPolarity    = DRV_SPI_CS_POLARITY_ACTIVE_LOW;

            app_camData.spiHandle = DRV_SPI_Open( DRV_SPI_INDEX_0, DRV_IO_INTENT_READWRITE );

            if (app_camData.spiHandle != DRV_HANDLE_INVALID)
            {
                if(DRV_SPI_TransferSetup(app_camData.spiHandle, &app_camData.spiSetup) == true)
                {
                    DRV_SPI_TransferEventHandlerSet(app_camData.spiHandle, SPI_Event_Handler, (uintptr_t)0);
                    
                    app_camData.state = APP_CAM_STATE_CAMERA_RESET;

                    SYSTICK_TimerStart();

                    leFixedString_Constructor(&OutputString, legatoCharBuffer, 16);

                    OutputString.fn->setFont(&OutputString, 
                        leStringTable_GetStringFont(leGetState()->stringTable, stringID_Out_Str, 0));    

                    printf("\n\r APP_CAM_Task: ArduCAM Start!"); 
                }

                else
                {
                    app_camData.state = APP_CAM_STATE_ERROR;
                }
            }

            else
            {
                app_camData.state = APP_CAM_STATE_ERROR;
            }

            break;
        }
        
        
        case APP_CAM_STATE_CAMERA_RESET:
        {
            if (Camera_Write_Reg(CAM_REG_SENSOR_RESET, CAM_SENSOR_RESET_ENABLE))
            {               
                if( Camera_Is_Ready() == true)
                {
                    app_camData.state = APP_CAM_STATE_CHECK_CAMERA;
                }
                
                else
                {
                    app_camData.state = APP_CAM_STATE_ERROR;
                }
            }
            
            else
            {
                app_camData.state = APP_CAM_STATE_ERROR;
            }
            
            break;
        }
        
        case APP_CAM_STATE_CHECK_CAMERA:
        {
            if ((Camera_Read_Reg(CAM_REG_SENSOR_ID) == CAMERA_OV5640_ID) |
                    (Camera_Read_Reg(CAM_REG_SENSOR_ID) == CAMERA_OV3640_ID))
            {
                if( Camera_Is_Ready() == true)
                {
                    app_camData.state = APP_CAM_STATE_CAMERA_CONFIG;
                }

                else
                {
                    app_camData.state = APP_CAM_STATE_ERROR;
                }
            }

            else
            {
                app_camData.state = APP_CAM_STATE_CHECK_CAMERA;
            }

            break;
        }
        
        case APP_CAM_STATE_CAMERA_CONFIG:
        {
            if (Camera_Write_Reg(CAM_REG_DEBUG_DEVICE_ADDRESS, CAMERA_DEVICE_ADDRESS))
            {
                if( Camera_Is_Ready() == true)
                {
                    app_camData.state = APP_CAM_STATE_SET_BMP_FORMAT; 

                    printf("\n\r APP_CAM_Task: ArduCAM configuration is completed! ");
                    printf("\n\r APP_CAM_Task: Enter '0' to reset the device ");                      
                    printf("\n\r APP_CAM_Task: Enter '1' to capture the image ");

                }
                
                else
                {
                    app_camData.state = APP_CAM_STATE_ERROR;
                }
            }
            
            else
            {
                app_camData.state = APP_CAM_STATE_ERROR;
            }
            
            break;
        }
        
        case APP_CAM_STATE_SET_BMP_FORMAT:
        {
            if (Camera_Write_Reg(CAM_REG_FORMAT, CAM_IMAGE_PIX_FMT_RGB565))
            {
                if( Camera_Is_Ready() == true)
                {
                    app_camData.state = APP_CAM_STATE_SET_RESOLUTION;
                }
                
                else
                {
                    app_camData.state = APP_CAM_STATE_ERROR;
                }
            }
            break;
        }
        
        case APP_CAM_STATE_SET_RESOLUTION:
        {
            if (Camera_Write_Reg(CAM_REG_CAPTURE_RESOLUTION, 
                    CAM_SET_CAPTURE_MODE | CAM_IMAGE_MODE_FHD)) 
            {  
                if( Camera_Is_Ready() == true)
                {
                    app_camData.state = APP_CAM_STATE_USER_INPUT_READ;
                }

                else
                {
                    app_camData.state = APP_CAM_STATE_ERROR;
                }
            }
            break;
        }
        

        case APP_CAM_STATE_USER_INPUT_READ:
        {

            scanf("%c",&app_camData.userInput);

            if(app_camData.userInput != '\0')
            { 
                if (app_camData.userInput == '1')
                {
                    app_camData.userInput = ' ';
                    app_camData.state = APP_CAM_STATE_IMG_CAPTURE;                                       
                }

                else if (app_camData.userInput == '0')
                {              
                    app_camData.userInput = ' ';

                    SYSTICK_DelayMs(200);

                    NVIC_SystemReset();              
                }
            }
            
            SYSTICK_DelayMs(200);

            break;
        }
                
        case APP_CAM_STATE_IMG_CAPTURE:
        {
            if (Camera_Write_Reg(ARDUCHIP_FIFO, FIFO_CLEAR_MASK))
            {                
                if (Camera_Write_Reg(ARDUCHIP_FIFO, FIFO_CLEAR_MASK))
                {                    
                    if (Camera_Write_Reg(ARDUCHIP_FIFO, FIFO_START_MASK))
                    {
                        app_camData.state = APP_CAM_STATE_CAPTURE_WAIT;
                    }
                    
                    else
                    {
                        app_camData.state = APP_CAM_STATE_ERROR;
                    }
                }
                
                else
                {
                    app_camData.state = APP_CAM_STATE_ERROR;
                }
            }

            else
            {
                app_camData.state = APP_CAM_STATE_ERROR;
            }
           
            break;
        }
        
        case APP_CAM_STATE_CAPTURE_WAIT:
        {
            Camera_Read_Reg(ARDUCHIP_TRIG);
            
            if ((app_camData.readReg[2] & CAP_DONE_MASK) == CAP_DONE_MASK)
            {                
                app_camData.imageSize = Camera_Read_Image_Size();
                printf("\n\r\n\r APP_CAM_Task: Scanning...");
                
                app_camData.state = APP_CAM_STATE_IMG_READ; 
            }
            
            SYSTICK_DelayMs(2);
            break;
        }       
        
        case APP_CAM_STATE_IMG_READ:
        {
            if(app_camData.imageSize > 0)
            {
                LED0_Toggle();
                
                Camera_Read_Image(&app_camData.captureBuffer[0], 
                        sizeof(app_camData.captureBuffer));           
                
                app_camData.imageSize = app_camData.imageSize - CAP_BUF_SIZE - 1;
                               
                Resize_Image((uint16_t *)&app_camData.captureBuffer[1], 
                        (uint16_t *)&app_camData.scanBuffer[0]);

                if(Barcode_Scan((uint16_t *)&app_camData.scanBuffer[0]) == true)
                {                   
                    Get_Barcode((char *)outputMessage);

                    //convert the character string to leFixedString object
                    OutputString.fn->setFromCStr(&OutputString, outputMessage);    

                    //Set OutputString string to label
                    Screen0_LabelWidget_1->fn->setString(Screen0_LabelWidget_1, 
                            (leString*)&OutputString);

                    app_camData.state = APP_CAM_STATE_IDLE;

                    break;
                }
            }
            
            else
            {
                //convert the character string to leFixedString object
                OutputString.fn->setFromCStr(&OutputString, errorMessage);    

                //Set OutputString string to label
                Screen0_LabelWidget_1->fn->setString(Screen0_LabelWidget_1, 
                        (leString*)&OutputString);
                
                app_camData.state = APP_CAM_STATE_IDLE;
            }            
            
            break;
        }
        
        case APP_CAM_STATE_IDLE:
        {
            printf("\n\r APP_CAM_Task: Enter '0' to reset the device ");                      
            printf("\n\r APP_CAM_Task: Enter '1' to capture the image "); 
            
            app_camData.state = APP_CAM_STATE_USER_INPUT_READ;
            break;
        }
        
        
        case APP_CAM_STATE_ERROR:
        {
            printf("\n\r APP_CAM_Task: Task Error...! ");
            
            app_camData.state = APP_CAM_STATE_IDLE;
            break;
        }
        
        /* The default state should never be executed. */
        default:
        {
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
