/**
 * \file
 * \brief  Example Configuration
 *
 * \copyright (c) 2023 Microchip Technology Inc. and its subsidiaries.
 *            You may use this software and any derivatives exclusively with
 *            Microchip products.
 *
 * \page License
 *
 * (c) 2023 Microchip Technology Inc. and its subsidiaries. You may use this
 * software and any derivatives exclusively with Microchip products.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIPS TOTAL LIABILITY ON ALL CLAIMS IN
 * ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
 * TERMS.
 */

#ifndef CLOUD_WIFI_CONFIG_H_
#define CLOUD_WIFI_CONFIG_H_

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "drv/driver/m2m_ssl.h"
#include "../../../../project_config.h"



#define WLAN_AUTH_WPA_PSK

#if defined(CLOUD_CONFIG_AWS)
#include "../../../../aws_connect.h"
#define SSL_CIPHER_SUITE_SELECTION           SSL_ECC_ONLY_CIPHERS
#else
     #error Project Configuration is not selected correctly. cloud_connect \
            configuration is only for configuring Harmony 3 components! \
            Navigate to Production -> Set Project Configuration to select \
            correct one based on Cloud Platform. Select one with FIRM_VALID \
            prefix only if using the project for firmware validation.
#endif

#define PUBLISH_INTERVAL            10000
#define CLOUD_PORT                  (8883)

/** Period used to update the timer/counter callbacks */
#define TIMER_UPDATE_PERIOD         (1000)

#define WIFI_UPDATE_PERIOD          TIMER_UPDATE_PERIOD
#define CLIENT_UPDATE_PERIOD        TIMER_UPDATE_PERIOD


/* Functions to retrieve configuration data */
int config_get_ssid(char* buf, size_t buflen);
int config_get_password(char* buf, size_t buflen);
int config_get_client_id(char* buf, size_t buflen);
int config_get_client_username(char* buf, size_t buflen);
int config_get_client_password(char* buf, size_t buflen);
int config_get_client_pub_topic(char* buf, size_t buflen);
int config_get_client_sub_topic(char* buf, size_t buflen);
int config_set_thing_id(void);


#endif /* CLOUD_WIFI_CONFIG_H_ */