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

#include "hal_command_input.h"
#include "mc_control_loop.h" 

void APP_ButtonResponse(MC_BUTTON_T * pButton, void (*buttonFunction)(MC_CONTROLLER_T * pMotorControl), MC_CONTROLLER_T * pMotorControl);
void APP_ButtonPolling(MC_CONTROLLER_T * pMotorControl);
void APP_SpeedReferenceCalc(MC_CONTROLLER_T * pMotorControl);
void APP_VbusCalc(MC_CONTROLLER_T * pMotorControl);


// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );      
        /* PMSM_FOC non-critical tasks */

        HAL_CHANNEL_ID_E id;
        MC_CONTROLLER_T * pMotorControl;
        for (id = channel_id_a; id < (NUM_OF_MOTOR + channel_id_a); id++)

        {
            pMotorControl = & g_mc_controller[id];  
       

            if(true == pMotorControl->one_ms_flag)
            {                
                APP_VbusCalc(pMotorControl); 

                APP_SpeedReferenceCalc(pMotorControl);         
                
                APP_ButtonPolling(pMotorControl);                                    
                               

                pMotorControl->one_ms_flag = false;
            }

        }   


        X2CScope_Communicate();


    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}



void APP_ButtonPolling(MC_CONTROLLER_T * pMotorControl)
{
    
    MC_BUTTON_T * pButton;
     
    HAL_CHANNEL_ID_E channel_id = pMotorControl->controller_id;

    pButton = &(pMotorControl->button);
    pButton->input = HAL_ButtonRead(channel_id);

    /* Check whether start/stop button is pressed */
    if( mc_fault == pMotorControl->state )
    {
        // need reset or restart to recover from fault;
    }
    else if( mc_idle == pMotorControl->state )
    {       

        APP_ButtonResponse(pButton, &MC_MotorStart, pMotorControl);            

    }
    else
    {
        APP_ButtonResponse(pButton, &MC_MotorStop, pMotorControl);
    }
    
 }


void APP_ButtonResponse(MC_BUTTON_T * pButton, void (*buttonFunction)(MC_CONTROLLER_T * pMotorControl), MC_CONTROLLER_T * pMotorControl)
{
    switch(pButton->state)
    {
        case mc_button_ready:
        {
            if( button_pressed == pButton->input)
            {
                buttonFunction(pMotorControl);
                pButton->debounce_counter = 0;
                pButton->state = mc_button_wait;
            }
        }
        break;

        case mc_button_wait:
        {
            if( SW_DEBOUNCE_DLY_MS <= pButton->debounce_counter)
            {
                pButton->state = mc_button_ready;
                pButton->debounce_counter = 0;
            }
            else
            {
                pButton->debounce_counter++;
            }
        }
        break;
        default:
        {
              /* Should never come here */
        }
        break;
    }
}


void APP_SpeedReferenceCalc(MC_CONTROLLER_T * pMotorControl)
{
 
    MC_FIRST_ODER_FILTER_T      *pSpeedCmdFilter;
    MC_FIRST_ODER_FILTER_T      *pPositionCmdFilter;
    HAL_MOTOR_PARAMETERS_T      *pMotorPara;       
    
    HAL_CHANNEL_ID_E channel_id = pMotorControl->controller_id;

    pMotorPara = hal_motor_control_channel[channel_id].pMotor;

    //filter potentiometer input        
    pSpeedCmdFilter = &(pMotorControl->speed_ref_filter);

    pPositionCmdFilter = &(pMotorControl->position_ref_filter);


    if(pMotorControl->state == mc_closed_loop)
    {
          
         

        if(pMotorControl->control_mode == speed_mode)
        {   
           
            //read speed ref, unit: PU
            pSpeedCmdFilter->input = HAL_PotRefRead(channel_id);              

            MC_FirstOrderLPFRun(pSpeedCmdFilter);
            
            pMotorControl->speed_ref_PU = pSpeedCmdFilter->output;
        }
        else if(pMotorControl->control_mode == position_mode)
        { 
            pPositionCmdFilter->input = HAL_PotRefRead(channel_id);   

            MC_FirstOrderLPFRun(pPositionCmdFilter);

            pMotorControl->position_ref_cnt_pre = pMotorControl->position_ref_cnt;

            pMotorControl->position_ref_cnt = (pPositionCmdFilter->output) * POS_POT_FULLSACLE * pMotorPara->encoder_PPR;  // mechanical pulse counts;
            
        }
        else
            ;

        pMotorControl->speed_ref_RPM = (pMotorControl->speed_ref_PU) * (pMotorPara->rated_speed_RPM); 
        
        pMotorControl->speed_feedback_RPM = (pMotorControl->speed_feedback_PU) * (pMotorPara->rated_speed_RPM);

    }
 }

void APP_VbusCalc(MC_CONTROLLER_T * pMotorControl)
{
 
    MC_FIRST_ODER_FILTER_T *pVbus_filter;
 
    HAL_CHANNEL_ID_E channel_id = pMotorControl->controller_id;

    //filter potentiometer input        
    pVbus_filter = &(pMotorControl->vbus_filter);
    
    //read speed ref, unit: PU
    pVbus_filter->input = HAL_VbusRead(channel_id);

    MC_FirstOrderLPFRun(pVbus_filter);

    pMotorControl->vbus_VOLT = pVbus_filter->output * HAL_VBUS_FULL_SCALE;
 }

/*******************************************************************************
 End of File
*/

