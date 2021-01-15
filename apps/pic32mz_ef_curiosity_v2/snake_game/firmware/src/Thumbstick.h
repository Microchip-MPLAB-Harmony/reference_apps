/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    Thumbstick.h

  Summary:
    This header file provides prototypes and definitions for the application.
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

#ifndef THUMBSTICK_CLICK_H
#define	THUMBSTICK_CLICK_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "config/default/driver/spi/drv_spi.h"
    
    
#define byte_1                 0b00000110
#define channel_0              0x00000000
#define channel_1              0b01000000
#define byte_3                 0x00000000
    
#define X_DEFAULT_VALUE              1.56
#define Y_DEFAULT_VALUE              1.79
#define THUMBSTICK_TOLERANCE         0.7
    
    
#define THUMBSTICK_PRESSED  0
#define THUMBSTICK_PRESSED_NOT_PRESSED  1
    
    
typedef enum
{
    X_task_transfer_start = 0,
    X_task_transfer_pending,
    X_task_transfer_waiting_Y_task,
    X_task_transfer_error,
    Y_task_transfer_start,
    Y_task_transfer_pending,
    Y_task_transfer_waiting_X_task,
    Y_task_transfer_error,
            
}THUMBSTICK_STATES;

typedef enum
{
    UP = 0,
    DOWN,
    RIGHT,
    LEFT,
    UP_DOWN_DEFAULT_POSITION,
    LEFT_RIGHT_DEFAULT_POSITION,
    NO_CHANGE,
            
}THUMBSTICK_POSITION;


struct Thumbstick
{
  DRV_HANDLE  spiHandle;
  DRV_SPI_TRANSFER_HANDLE transferHandle;

  uint8_t cmd[3];
  uint8_t RxBuffer[3];

  uint8_t X_task_state;
  uint8_t Y_task_state;

  uint16_t X_raw_value;
  uint16_t Y_raw_value;

  float X_voltage_value;
  float Y_voltage_value;

  bool X_axis_sampled_first;
  bool Y_axis_sampled_first;

  bool X_axis_sample_done;
  bool Y_axis_sample_done;

  uint8_t UP_DOWN_state;
  uint8_t LEFT_RIGHT_state;

  uint8_t final_direction;

  bool button_pressed;

};
      
extern struct Thumbstick thumbstick;
        

/*******************************************************************************
 Function:
    void Thumbstick_Initialize();

  Summary:
    Thumbstick initialization routine.

  Description:
    This function initializes the variables and the SPI driver used to communicate with the Thumbstick.

  Precondition:
   

  Parameters:
    None.

  Returns:
    None.


  Remarks:
    This routine must be called once.
*/    

void Thumbstick_Initialize();


/*******************************************************************************
 Function:
    void Thumbstick_Task();

  Summary:
    Thumbstick initialization routine.

  Description:
    This function contains the state machine for the Thumbstick module.

  Precondition:
    The ("Thumbstick_Initialize") function should be called before calling this function.

  Parameters:
    None.

  Returns:
    None.


  Remarks:
    This routine should be called periodically in a loop.
*/ 

void Thumbstick_Task();


/*******************************************************************************
 Function:
    void Thumbstick_GetXTask();

  Summary:
    Thumbstick task routine for getting the X coordinate.

  Description:
    This function contains the state machine for retrieved the X coordinate of the Thumbstick.

  Precondition:
    The ("Thumbstick_Task") function should be called before calling this function.

  Parameters:
    None.

  Returns:
    None.


  Remarks:
    This routine should be called periodically in a loop.
*/ 

void Thumbstick_GetXTask();


/*******************************************************************************
 Function:
    void Thumbstick_GetYTask();

  Summary:
    Thumbstick task routine for getting the X coordinate.

  Description:
    This function contains the state machine for retrieved the Y coordinate of the Thumbstick.

  Precondition:
    The ("Thumbstick_Task") function should be called before calling this function.

  Parameters:
    None.

  Returns:
    None.


  Remarks:
    This routine should be called periodically in a loop.
*/

void Thumbstick_GetYTask();


/*******************************************************************************
 Function:
    uint16_t Thumbstick_GetXRawValue();

  Summary:
    The routine that will return the raw X coordinate of the Thumbstick.

  Description:
    This function will return the raw value for the X coordinate, measured by the ADC inside the Thumbstick.
    Shouldn't be used by the user. This function is used inside the ("Thumbstick_GetXTask") routine.

  Precondition:
    The ("Thumbstick_GetXTask") function should be called before calling this function.

  Parameters:
    None.

  Returns:
   Return a uint16_t value, that represent the raw value for the X coordinate.


  Remarks:
 
*/

uint16_t Thumbstick_GetXRawValue();


/*******************************************************************************
 Function:
    uint16_t Thumbstick_GetYRawValue();

  Summary:
    The routine that will return the raw Y coordinate of the Thumbstick.

  Description:
    This function will return the raw value for the Y coordinate, measured by the ADC inside the Thumbstick.
    Shouldn't be used by the user. This function is used inside the ("Thumbstick_GetYTask") routine.

  Precondition:
    The ("Thumbstick_GetYTask") function should be called before calling this function.

  Parameters:
    None.

  Returns:
   Return a uint16_t value, that represent the raw value for the X coordinate.


  Remarks:
    None.
*/

uint16_t Thumbstick_GetYRawValue();


/*******************************************************************************
 Function:
    uint8_t Thumbstick_GetUpLeftRightState();

  Summary:
    The routine that will return the raw Y coordinate of the Thumbstick.

  Description:
    This function will return the state for the horizontal position of the Thumbstick.

  Precondition:
    The ("Thumbstick_GetXTask") function should be called before calling this function.

  Parameters:
    None.

  Returns:
   Return a uint16_t value, that represent the raw value for the X coordinate.


  Remarks:
    None.
*/


uint8_t Thumbstick_GetUpLeftRightState();


/*******************************************************************************
 Function:
    bool Thumbstick_SamplingIsDone();

  Summary:
    The routine will return the status of the current transaction with the Thumbstick module.

  Description:
    This function return the status of the current SPI transaction with the Thumbstick.

  Precondition:
    

  Parameters:
    None.

  Returns:
 
   true  - if the SPI transaction was finished and the measured values were processed.
 
   false - if the transaction is still pending.


  Remarks:
    None.
*/

bool Thumbstick_SamplingIsDone();


/*This function return the vertical state of the Thumbstick*/
uint8_t Thumbstick_GetUpDownState();




/*This function return the horizontal state of the Thumbstick*/
uint8_t Thumbstick_GetLeftRightState();


/*******************************************************************************
 Function:
    void Thumbstick_GetFinalDirectionTask();

  Summary:
    The task routine for the Thumstick direction.

  Description:
    This function contains the state machine that will process the direction of the Thumbstick.

  Precondition:
    The ("Thumbstick_GetXTask") and ("Thumbstick_GetYTask") functions should be called before calling this function.

  Parameters:
    None.

  Returns:
    None.


  Remarks:
    None.
*/

void Thumbstick_GetFinalDirectionTask();

#ifdef	__cplusplus
}
#endif

#endif	/* THUMBSTICK_CLICK_H */

