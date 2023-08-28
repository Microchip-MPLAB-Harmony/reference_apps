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

#include "cloud_wifi_ecc_process.h"
#include "cloud_wifi_config.h"
#include "jwt/atca_jwt.h"
#include <stdio.h>
#include "definitions.h"
#include "IoT_Sensor_Node_config.h"
#if defined(CLOUD_CONFIG_AWS) || defined(CLOUD_CONFIG_AZURE)
#include "cloud_wifi_ecc_process.h"
#endif

char config_thing_id[130];

int config_set_thing_id()
{
    uint8_t serial_num[9];
    size_t hex_size;

    hex_size = sizeof(config_thing_id) - 1;
    ATCA_STATUS rv;

    rv = atcab_read_serial_number(serial_num);
    if (ATCA_SUCCESS != rv)
    {
        return rv;
    }
    rv = atcab_bin2hex_(serial_num, sizeof(serial_num), config_thing_id, &hex_size, false, false, true);

    if (ATCA_SUCCESS != rv)
    {
        return rv;
    }
        
    #ifdef CFG_ENABLE_CLI     
        set_deviceId(config_thing_id);
    #endif

    return ATCA_SUCCESS;
}

/** \brief Populate the buffer with the client id */
int config_get_client_id(char* buf, size_t buflen)
{
    if (buf && buflen)
    {
        int rv;

#if defined(CLOUD_CONFIG_AWS)
    #ifdef CLOUD_CONNECT_WITH_CUSTOM_CERTS
        extern uint8_t subject_key_id[20];

        for (int i = 0; i < 20; i++)
        {
            config_thing_id[i * 2 + 0] = "0123456789abcdef"[subject_key_id[i] >> 4];
            config_thing_id[i * 2 + 1] = "0123456789abcdef"[subject_key_id[i] & 0x0F];
        }
        config_thing_id[20 * 2] = 0; // Add terminating null
    #endif
        rv = snprintf(buf, buflen, "%s", config_thing_id);
#else
    #error "Cloud config should be defined"
#endif

        if (0 < rv && rv < buflen)
        {
            buf[rv] = 0;
            return 0;
        }
    }
    return -1;
}

/* Populate the buffer with the username */
int config_get_client_username(char* buf, size_t buflen)
{
    if (buf && buflen)
    {
        int rv = snprintf(buf, buflen, "unused");
        
        if (0 < rv && rv < buflen)
        {
            buf[rv] = 0;
            return 0;
        }
    }
    return -1;
}

/* Populate the buffer with the user's password */
int config_get_client_password(char* buf, size_t buflen)
{
    int rv = -1;

    if (buf && buflen)
    {
        rv = snprintf(buf, buflen, "unused");

        if (0 < rv && rv < buflen)
        {
            buf[rv] = 0;
            return 0;
        }
    }

    return rv;

}

/* Get the topic id  where the client will be publishing messages */
int config_get_client_pub_topic(char* buf, size_t buflen)
{
    int rv;

    if (buf && buflen)
    {
#if defined(CLOUD_CONFIG_AWS)
        rv = snprintf(buf, buflen, "$aws/things/%s/shadow/update", config_thing_id);
#endif

        if (0 < rv && rv < buflen)
        {
            buf[rv] = 0;
            return 0;
        }
    }
    return -1;
}

/* Get the topic id  where the client will be publishing messages */
int config_get_client_sub_topic(char* buf, size_t buflen)
{
    int rv;

    if (buf && buflen)
    {

#if defined(CLOUD_CONFIG_AWS)
        rv = snprintf(buf, buflen, "$aws/things/%s/shadow/update/delta", config_thing_id);
#endif

        if (0 < rv && rv < buflen)
        {
            buf[rv] = 0;
            return 0;
        }
    }
    return -1;
}