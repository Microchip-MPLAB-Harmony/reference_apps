/*******************************************************************************
  Grid-EYE click Header File

  Company:
    Microchip Technology Inc.

  File Name:
    grid_eye_click.h

  Summary:
    This header file provides prototypes and definitions for grid_eye_click.

  Description:
    This header file provides function prototypes and data type definitions for
    the grid_eye_click.
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

#ifndef GRID_EYE_CLICK_H
#define	GRID_EYE_CLICK_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "config/default/definitions.h"

#define GRID_EYE_SLAVE_ADDRESS 0b1101000
       
#define GRID_EYE_POWER_MODE_REG                 0x00
#define GRID_EYE_POWER_MODE_NORMAL_MODE_COMMAND 0x00  
    
#define GRID_EYE_RESET_REG                      0x01  
#define GRID_EYE_RESET_FLAG_RESET_COMMAND       0x30
#define GRID_EYE_RESET_INITIAL_RESET_COMMAND    0x3F   
    
#define GRID_EYE_FRAME_RATE_REG                 0x02
#define GRID_EYE_FRAME_RATE_1FPS                0x01
#define GRID_EYE_FRAME_RATE_10FPS               0x00
    
#define GRID_EYE_INTC_REG                       0x03
#define GRID_EYE_INTC_INTMODE_SET               0x01
#define GRID_EYE_INTC_INTMODE_CLEAR             0x00
#define GRID_EYE_INTC_INTEN_SET                 0x01
#define GRID_EYE_INTC_INTEN_CLEAR               0x00
    
#define GRID_EYE_INTHL_REG                      0x08
#define GRID_EYE_INTHL_VALUE                    0x30
    
#define GRID_EYE_INTHH_REG                      0x09
#define GRID_EYE_INTHH_VALUE                    0x00
    
#define GRID_EYE_INTLL_REG                      0x0A
#define GRID_EYE_INTLL_VALUE                    0x15
    
#define GRID_EYE_INTLH_REG                      0x0B
#define GRID_EYE_INTLH_VALUE                    0x00
    
#define GRID_EYE_INTSL_REG                      0x0C
#define GRID_EYE_INTSL_VALUE                    0x20
    
#define GRID_EYE_INTSH_REG                      0x0D
#define GRID_EYE_INTSH_VALUE                    0x00
    
#define GRID_EYE_TEMP_REG                       0x80
    
#define GRID_EYE_I2C_TRANSFER_SIZE                 1
    
#define GRID_EYE_FRAMEBUFFER_SIZE                128
    
#define GRID_EYE_SAMPLES_NUMBER (GRID_EYE_FRAMEBUFFER_SIZE/2)
#define GRID_EYE_SAMPLES_PER_ROW                   8
#define GRID_EYE_SAMPLES_PER_COLUMN GRID_EYE_SAMPLES_PER_ROW
    
    
#define GRID_EYE_RED_COLOR_UPPER_LIMIT            30
    
#define GRID_EYE_ORANGE_COLOR_UPPER_LIMIT         28
    
#define GRID_EYE_YELLOW_COLOR_UPPER_LIMIT         26
    
#define GRID_EYE_BLUE_COLOR_UPPER_LIMIT           24
    
#define GRID_EYE_GREEN_COLOR_UPPER_LIMIT          22
    
    
typedef enum{
    
    GRID_EYE_GET_RAW_DATA = 0,
    GRID_EYE_WAIT_TRANSACTION_TO_FINISH,
    GRID_EYE_PROCESS_RAW_DATA

}GRID_EYE_STATES;

typedef struct{
    
    DRV_HANDLE i2c_handle;
    DRV_I2C_TRANSFER_HANDLE transferHandle;

    uint8_t grid_eye_slave_addr;

    uint8_t tx_buffer[10];
    uint8_t rx_buffer[10];

    bool i2c_transaction_done;

    bool get_data_start;

    bool update_display;

    uint8_t state;

}GRID_EYE;

    
extern SYS_TIME_HANDLE sys_time_handle;

extern GRID_EYE grid_eye_obj;


/* Function:
    void GRID_EYE_Initialize(GRID_EYE* _grid_eye_obj);

  Summary:
    Initializes the I2C instance used to communicate with Grid-EYE click. Initializes the Grid-EYE click and the variables.
  Description:
    Initializes the I2C instance used to communicate with Grid-EYE click. Initializes the Grid-EYE click and the variables.

  Precondition:
   Functions SYS_Initialize() and SYS_Tasks() needs to be called.

  Parameters:
    _grid_eye_obj - pointer to the GRID_EYE object.


  Returns:
   None.

  Example:
    

  Remarks:
    
*/
void GRID_EYE_Initialize(GRID_EYE* _grid_eye_obj);


/* Function:
    void GRID_EYE_I2c_write_blocking(GRID_EYE _grid_obj, uint8_t grid_eye_reg_addr, uint8_t write_data,uint8_t size );

  Summary:
    Initiate an I2C write command. This function is blocking.
 
  Description:
    Initiate an I2C write command. This function is blocking.

  Precondition:
   Functions GRID_EYE_Initialize() needs to be called.

  Parameters:
    _grid_eye_obj     - grid eye object obtained after the GRID_EYE_Initialize() was called.
    grid_eye_reg_addr - Grid-EYE register address
    write_data        - data to be send
    size              - number of bytes to be send


  Returns:
   None.

  Example:
    

  Remarks:
    
*/

void GRID_EYE_I2c_write_blocking(GRID_EYE _grid_obj, uint8_t grid_eye_reg_addr, uint8_t write_data,uint8_t size );


/* Function:
    void GRID_EYE_I2c_write_read_nonblocking(GRID_EYE _grid_obj,uint8_t grid_eye_reg_addr, void* read_data);

  Summary:
    Initiate an I2C write and read command. This function is non-blocking.
 
  Description:
    Initiate an I2C write and read command. This function is non-blocking.

  Precondition:
   Functions GRID_EYE_Initialize() needs to be called.

  Parameters:
    _grid_eye_obj     - grid eye object obtained after the GRID_EYE_Initialize() was called.
    grid_eye_reg_addr - Grid-EYE register address
    read_data        - data to be read
    size              - number of bytes to be send


  Returns:
   None.

  Example:
    

  Remarks:
    
*/

void GRID_EYE_I2c_write_read_nonblocking(GRID_EYE _grid_obj,uint8_t grid_eye_reg_addr, void* read_data);

/* Function:
    void GRID_EYE_Process_temp_raw_data(uint8_t* raw_data,float* temp_table_64_buffer);

  Summary:
    Process the data measured by Grid-EYE click and store it into a buffer. 
 * 
  Description:
    Process the data measured by Grid-EYE click and store it into a buffer. 

  Precondition:
   Functions GRID_EYE_Initialize() needs to be called.

  Parameters:
    raw_data - pointer to the raw data buffer that will be processed 
    temp_table_64_buffer - pointer to buffer in which the processed data will be stored


  Returns:
   None.

  Example:
    

  Remarks:
    
*/

void GRID_EYE_Process_temp_raw_data(uint8_t* raw_data,float* temp_table_64_buffer);


/* Function:
    void GRID_EYE_Sys_time_callback(uintptr_t context);

  Summary:
    Timer callback used for the Grid-EYE task.
 * 
  Description:
    Timer callback used for the Grid-EYE task.

  Precondition:
    None.

  Parameters:
    context


  Returns:
   None.

  Example:
    

  Remarks:
    
*/

void GRID_EYE_Sys_time_callback(uintptr_t context);


/* Function:
    void GRID_EYE_Display_draw_data();

  Summary:
    Function that draws the rectangles with color that correspond with the temperature data measured fro the Grid-EYE click.
 * 
  Description:
    Function that draws the rectangles with color that correspond with the temperature data measured fro the Grid-EYE click.

  Precondition:
  The SYS_Initialize() function needs to be called once and SYS_Tasks() needs to be called periodically.

  Parameters:
   None.


  Returns:
   None.

  Example:
    

  Remarks:
    
*/

void GRID_EYE_Display_draw_data();


/* Function:
    void GRID_EYE_Display_task();

  Summary:
   The task function for displaying the Grid-Eye click data on the OLED C click.
  
  Description:
    The task function for displaying the Grid-Eye click data on the OLED C click.

  Precondition:
  The SYS_Initialize() function needs to be called once and SYS_Tasks() needs to be called periodically.

  Parameters:
   None.


  Returns:
   None.

  Example:
    

  Remarks:
    
*/

void GRID_EYE_Display_task();


/* Function:
    void GRID_EYE_Sensor_task();

  Summary:
    The task function for measuring and processing the data from the Grid-EYE click.
  
  Description:
    The task function for measuring and processing the data from the Grid-EYE click.

  Precondition:
  The SYS_Initialize() function needs to be called once and SYS_Tasks() needs to be called periodically.

  Parameters:
   None.


  Returns:
   None.

  Example:
    

  Remarks:
    
*/

void GRID_EYE_Sensor_task();
    
    
    
#ifdef	__cplusplus
}
#endif

#endif	/* GRID_EYE_CLICK_H */

