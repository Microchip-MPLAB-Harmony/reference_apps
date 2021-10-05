/*
\file   wifi_service.h

\brief  Wifi service header file.

(c) 2018 Microchip Technology Inc. and its subsidiaries.

Subject to your compliance with these terms, you may use Microchip software and any
derivatives exclusively with Microchip products. It is your responsibility to comply with third party
license terms applicable to your use of third party software (including open source software) that
may accompany Microchip software.

THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY
IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS
FOR A PARTICULAR PURPOSE.

IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP
HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO
THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL
CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT
OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS
SOFTWARE.
*/ 

#ifndef WIFI_SERVICE_H_
#define WIFI_SERVICE_H_

#include <stdint.h>
#include <stdbool.h>

#define MAX_WIFI_CRED_LENGTH 31
#define DEFAULT_CREDENTIALS 0
#define NEW_CREDENTIALS     1
#define WIFI_SOFT_AP  0
#define WIFI_DEFAULT  1

struct wifi_params {
   char wifi_ssid[MAX_WIFI_CRED_LENGTH];
   char wifi_password[MAX_WIFI_CRED_LENGTH];
   char wifi_authType[2];
};
extern struct wifi_params wifi_params;

// If you pass a callback function in here it will be called when the AP state changes. Pass NULL if you do not want that.
void wifi_init(void (*funcPtr)(uint8_t), uint8_t  mode);
bool wifi_connectToAp(uint8_t passed_wifi_creds);
bool wifi_disconnectFromAp(void);
void WiFi_ConStateCb(tenuM2mConnState status);
void WiFi_HostLookupCb(void);
void WiFi_ProvisionCb(uint8_t sectype, uint8_t *SSID, uint8_t *password);
void wifi_sched(void);
#endif /* WIFI_SERVICE_H_ */

