/********************************************************************
 *
 (c) [2018] Microchip Technology Inc. and its subsidiaries.

   Subject to your compliance with these terms, you may use Microchip software  
 * and any derivatives exclusively with Microchip products. It is your 
 * responsibility to comply with third party license terms applicable to your 
 * use of third party software (including open source software) that may 
 * accompany Microchip software.
   THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER  
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A PARTICULAR 
 * PURPOSE.
 * 
   IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN 
 * ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY, 
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *************************************************************************
 *
 *                           mqtt_packetTransfer_interface.c
 *
 * About:
 *  Interface layer between MQTT core and application. The aim of this file is 
 *  provide information about the user application to the MQTT core while 
 *  keeping the MQTT core independent of the details specified in the user 
 *  application.
 *
 * 
 ******************************************************************************/

#include <stdint.h>
#include <string.h>
#include "mqtt_packetTransfer_interface.h"
#include "../debug_print.h"



/**********************MQTT Interface layer variables**************************/

/** \brief Publish handler table information.
 *
 * This information obtained is used by the MQTT core to determine whether 
 * PUBLISH packet payload received for a particular topic needs to be sent to 
 * the application for further processing.
 */
publishReceptionHandler_t *publishRecvInfo;
/*******************MQTT Interface layer variables*(END)***********************/

/**********************Function implementations********************************/

void MQTT_SetPublishReceptionHandlerTable(publishReceptionHandler_t *appPublishReceptionInfo) 
{
    publishRecvInfo = appPublishReceptionInfo;
}

publishReceptionHandler_t *MQTT_GetPublishReceptionHandlerTable()
{
    return publishRecvInfo;
}


/**********************Function implementations*(END)**************************/
