#include "Thumbstick.h"


struct Thumbstick thumbstick;

void Thumbstick_Task()
{
  Thumbstick_GetXTask();
  Thumbstick_GetYTask();
  Thumbstick_GetFinalDirectionTask();
}


void Thumbstick_Initialize()
{
   SS1_Set();
   thumbstick.X_task_state = X_task_transfer_start;
   thumbstick.Y_task_state = Y_task_transfer_waiting_X_task;
   
   thumbstick.X_axis_sampled_first = false;
   thumbstick.Y_axis_sampled_first = false;
   
   thumbstick.X_axis_sample_done = false;
   thumbstick.Y_axis_sample_done = false;
   
   thumbstick.LEFT_RIGHT_state = LEFT_RIGHT_DEFAULT_POSITION;
   thumbstick.UP_DOWN_state    = UP_DOWN_DEFAULT_POSITION;
           
   thumbstick.button_pressed = false;
   
   thumbstick.spiHandle = DRV_SPI_Open( DRV_SPI_INDEX_0, DRV_IO_INTENT_READWRITE );

        if( DRV_HANDLE_INVALID == thumbstick.spiHandle )
        {
            // Unable to open the driver
            while(1);
        }
   
}


void Thumbstick_GetXTask()
{
    
    switch(thumbstick.X_task_state)
    {
        case X_task_transfer_start:
        {
    
            thumbstick.cmd[0] = byte_1;
            thumbstick.cmd[1] = channel_1;
            thumbstick.cmd[2] = byte_3;
            
             SS1_Clear();

            DRV_SPI_WriteReadTransferAdd(thumbstick.spiHandle, thumbstick.cmd, 3, thumbstick.RxBuffer, 3, &thumbstick.transferHandle);

                 if(thumbstick.transferHandle == DRV_SPI_TRANSFER_HANDLE_INVALID)
                    {
                     while(1);
                        // Error handling here
                    }
            
            thumbstick.X_task_state = X_task_transfer_pending;
            break;
            
        }
        
        case X_task_transfer_pending:
        {
                        
           if(DRV_SPI_TransferStatusGet(thumbstick.transferHandle) == DRV_SPI_TRANSFER_EVENT_COMPLETE)
           {
               SS1_Set();
               
              thumbstick.X_axis_sampled_first = true;
              thumbstick.X_axis_sample_done = true;
              thumbstick.X_task_state = X_task_transfer_waiting_Y_task;
              thumbstick.Y_task_state = Y_task_transfer_start;            
              thumbstick.X_voltage_value = (float)(((float)Thumbstick_GetXRawValue() * 3.3)/4096);
              Nop();
           }
           
           break;
        }
        
        case X_task_transfer_waiting_Y_task:
        {           
          //wait to finish the get_Y_task())
            if(thumbstick.X_axis_sampled_first == true)
            {

            }
  
            break;
        }
    
    }

}


void Thumbstick_GetYTask()
{

  switch(thumbstick.Y_task_state)
          
  {
         case Y_task_transfer_start:
        {
    
            thumbstick.cmd[0] = byte_1;
            thumbstick.cmd[1] = channel_0;
            thumbstick.cmd[2] = byte_3;
            
           SS1_Clear();

            DRV_SPI_WriteReadTransferAdd(thumbstick.spiHandle, thumbstick.cmd, 3, thumbstick.RxBuffer, 3, &thumbstick.transferHandle);

                 if(thumbstick.transferHandle == DRV_SPI_TRANSFER_HANDLE_INVALID)
                        {
                            // Error handling here
                        }
            
            thumbstick.Y_task_state = Y_task_transfer_pending;
            
            break;
            
        }
         
         case Y_task_transfer_pending:
            {
               if(DRV_SPI_TransferStatusGet(thumbstick.transferHandle) == DRV_SPI_TRANSFER_EVENT_COMPLETE)
               {
                  SS1_Set();  
                  
                  thumbstick.Y_axis_sampled_first = true;
                  thumbstick.Y_axis_sample_done = true;
                  thumbstick.Y_task_state = Y_task_transfer_waiting_X_task;
                  thumbstick.X_task_state = X_task_transfer_start;
                  thumbstick.Y_voltage_value = (float)(((float)Thumbstick_GetYRawValue() * 3.3)/4096);
               }

               break;
            }
         
         
         case Y_task_transfer_waiting_X_task:
            {
              //wait to finish the get_X_task())
                
                if(thumbstick.Y_axis_sampled_first == true)
                {
                    
                }

                break;
            }
     }
}


uint16_t Thumbstick_GetXRawValue()
{
    thumbstick.X_raw_value = 0;
    thumbstick.X_raw_value = (uint16_t)thumbstick.RxBuffer[1];
    thumbstick.X_raw_value = (uint16_t)((thumbstick.X_raw_value<<12));
    thumbstick.X_raw_value = (uint16_t)(thumbstick.X_raw_value>>4);
    thumbstick.X_raw_value = (uint16_t)(thumbstick.X_raw_value | ((uint16_t)thumbstick.RxBuffer[2]));
  
    return thumbstick.X_raw_value;
}


uint16_t Thumbstick_GetYRawValue()
{
    thumbstick.Y_raw_value = 0;
    thumbstick.Y_raw_value = (uint16_t)thumbstick.RxBuffer[1];
    thumbstick.Y_raw_value = (uint16_t)((thumbstick.Y_raw_value<<12));
    thumbstick.Y_raw_value = (uint16_t)(thumbstick.Y_raw_value>>4);
    thumbstick.Y_raw_value = (uint16_t)(thumbstick.Y_raw_value | ((uint16_t)thumbstick.RxBuffer[2]));
  
    return thumbstick.Y_raw_value;
}


uint8_t Thumbstick_GetUpLeftRightState()
{
    if(thumbstick.X_voltage_value >= (X_DEFAULT_VALUE + THUMBSTICK_TOLERANCE))
    {
        return LEFT;    
    }
    
    if(thumbstick.X_voltage_value <= (X_DEFAULT_VALUE - THUMBSTICK_TOLERANCE))
    {
        return RIGHT;
    }
        
    return LEFT_RIGHT_DEFAULT_POSITION;
}

bool Thumbstick_SamplingIsDone()
{
    if((thumbstick.X_axis_sample_done == true)&&(thumbstick.Y_axis_sample_done == true))
    {
      thumbstick.X_axis_sample_done = false;
      thumbstick.Y_axis_sample_done = false;
      
      return true;
    }
    
    return false;
    
}


uint8_t Thumbstick_GetUpDownState()
{
    return thumbstick.UP_DOWN_state;
}

uint8_t Thumbstick_GetLeftRightState()
{
    return thumbstick.LEFT_RIGHT_state;
}


void Thumbstick_GetFinalDirectionTask()
{
    if(Thumbstick_SamplingIsDone() == true)
    {
        if(thumbstick.X_voltage_value  >= 3.0)
        {
          thumbstick.LEFT_RIGHT_state = LEFT;
          thumbstick.final_direction = LEFT;
          
        }else if(thumbstick.X_voltage_value  <= 0.5)
        {
          thumbstick.LEFT_RIGHT_state = RIGHT;
          thumbstick.final_direction = RIGHT;
          
        }else
        {
          thumbstick.LEFT_RIGHT_state = LEFT_RIGHT_DEFAULT_POSITION;
        }
        
        
        if(thumbstick.Y_voltage_value  >= 3.0)
        {
          thumbstick.UP_DOWN_state = UP;
          thumbstick.final_direction = UP;
          
        }else if(thumbstick.Y_voltage_value  <= 0.3)
        {
          thumbstick.UP_DOWN_state = DOWN;
          thumbstick.final_direction = DOWN;
          
        }else if(thumbstick.LEFT_RIGHT_state == LEFT_RIGHT_DEFAULT_POSITION)
        {
          thumbstick.UP_DOWN_state = UP_DOWN_DEFAULT_POSITION;
          thumbstick.final_direction = UP_DOWN_DEFAULT_POSITION;
        }     
    }
}