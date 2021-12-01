/*
 * cloud_service.h
 *
 * Created: 9/27/2018 2:25:12 PM
 *  Author: C14674
 */ 

#ifndef CLOUD_SERVICE_H_
#define CLOUD_SERVICE_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define CLOUD_PACKET_RECV_TABLE_SIZE	2
#define CLOUD_MAX_DEVICEID_LENGTH 30
#define PASSWORD_SPACE 456

void CLOUD_reset(void);
void CLOUD_subscribe(void);
void CLOUD_disconnect(void);
bool CLOUD_isConnected(void);
void CLOUD_publishData(uint8_t *data, unsigned int len);
void CLOUD_task(void);
void CLOUD_sched(void);
void dnsHandler(uint8_t * domainName, uint32_t serverIP);
void CLOUD_setdeviceId(char *id);

#endif /* CLOUD_SERVICE_H_ */