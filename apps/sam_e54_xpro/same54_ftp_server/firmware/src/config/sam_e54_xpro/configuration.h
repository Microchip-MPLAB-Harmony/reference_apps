/*******************************************************************************
  System Configuration Header

  File Name:
    configuration.h

  Summary:
    Build-time configuration header for the system defined by this project.

  Description:
    An MPLAB Project may have multiple configurations.  This file defines the
    build-time options for a single configuration.

  Remarks:
    This configuration header must not define any prototypes or data
    definitions (or include any files that do).  It only provides macro
    definitions for build-time configuration options

*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/*  This section Includes other configuration headers necessary to completely
    define this configuration.
*/

#include "user.h"
#include "device.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: System Configuration
// *****************************************************************************
// *****************************************************************************



// *****************************************************************************
// *****************************************************************************
// Section: System Service Configuration
// *****************************************************************************
// *****************************************************************************
/* TIME System Service Configuration Options */
#define SYS_TIME_INDEX_0                            (0)
#define SYS_TIME_MAX_TIMERS                         (5)
#define SYS_TIME_HW_COUNTER_WIDTH                   (32)
#define SYS_TIME_HW_COUNTER_PERIOD                  (4294967295U)
#define SYS_TIME_HW_COUNTER_HALF_PERIOD             (SYS_TIME_HW_COUNTER_PERIOD>>1)
#define SYS_TIME_CPU_CLOCK_FREQUENCY                (120000000)
#define SYS_TIME_COMPARE_UPDATE_EXECUTION_CYCLES    (232)

#define SYS_CONSOLE_INDEX_0                       0





#define SYS_CMD_ENABLE
#define SYS_CMD_DEVICE_MAX_INSTANCES       SYS_CONSOLE_DEVICE_MAX_INSTANCES
#define SYS_CMD_PRINT_BUFFER_SIZE          2056U
#define SYS_CMD_BUFFER_DMA_READY



#define SYS_DEBUG_ENABLE
#define SYS_DEBUG_GLOBAL_ERROR_LEVEL       SYS_ERROR_DEBUG
#define SYS_DEBUG_BUFFER_DMA_READY
#define SYS_DEBUG_USE_CONSOLE



/* File System Service Configuration */

#define SYS_FS_MEDIA_NUMBER               (1U)
#define SYS_FS_VOLUME_NUMBER              (1U)

#define SYS_FS_AUTOMOUNT_ENABLE           true
#define SYS_FS_CLIENT_NUMBER              1U
#define SYS_FS_MAX_FILES                  (10U)
#define SYS_FS_MAX_FILE_SYSTEM_TYPE       (1U)
#define SYS_FS_MEDIA_MAX_BLOCK_SIZE       (512U)
#define SYS_FS_MEDIA_MANAGER_BUFFER_SIZE  (2048U)
#define SYS_FS_USE_LFN                    (1)
#define SYS_FS_FILE_NAME_LEN              (255U)
#define SYS_FS_CWD_STRING_LEN             (1024)


#define SYS_FS_FAT_VERSION                "v0.15"
#define SYS_FS_FAT_READONLY               false
#define SYS_FS_FAT_CODE_PAGE              437
#define SYS_FS_FAT_MAX_SS                 SYS_FS_MEDIA_MAX_BLOCK_SIZE





#define SYS_FS_MEDIA_TYPE_IDX0 				SYS_FS_MEDIA_TYPE_SD_CARD
#define SYS_FS_TYPE_IDX0 					FAT
					
#define SYS_FS_MEDIA_IDX0_MOUNT_NAME_VOLUME_IDX0 			"/mnt/myDrive1"
#define SYS_FS_MEDIA_IDX0_DEVICE_NAME_VOLUME_IDX0			"/dev/mmcblka1"
								

#define SYS_CONSOLE_DEVICE_MAX_INSTANCES   			(1U)
#define SYS_CONSOLE_UART_MAX_INSTANCES 	   			(1U)
#define SYS_CONSOLE_USB_CDC_MAX_INSTANCES 	   		(0U)
#define SYS_CONSOLE_PRINT_BUFFER_SIZE        		(200U)




// *****************************************************************************
// *****************************************************************************
// Section: Driver Configuration
// *****************************************************************************
// *****************************************************************************
/* SDSPI Driver Instance 0 Configuration Options */
#define DRV_SDSPI_INDEX_0                       0
#define DRV_SDSPI_CLIENTS_NUMBER_IDX0           1
#define DRV_SDSPI_QUEUE_SIZE_IDX0               4
#define DRV_SDSPI_CHIP_SELECT_PIN_IDX0          SYS_PORT_PIN_PB28
#define DRV_SDSPI_SPEED_HZ_IDX0                 5000000
#define DRV_SDSPI_POLLING_INTERVAL_MS_IDX0      1000

#define DRV_SDSPI_DMA_MODE
#define DRV_SDSPI_XMIT_DMA_CH_IDX0              SYS_DMA_CHANNEL_0
#define DRV_SDSPI_RCV_DMA_CH_IDX0               SYS_DMA_CHANNEL_1



/* SDSPI Driver Common Configuration Options */
#define DRV_SDSPI_INSTANCES_NUMBER              (1U)

/*** MIIM Driver Configuration ***/
#define DRV_MIIM_ETH_MODULE_ID_0                GMAC_BASE_ADDRESS
#define DRV_MIIM_DRIVER_INDEX_0                 0
#define DRV_MIIM_INSTANCES_NUMBER           1
#define DRV_MIIM_INSTANCE_OPERATIONS        4
#define DRV_MIIM_INSTANCE_CLIENTS           2
#define DRV_MIIM_CLIENT_OP_PROTECTION   false
#define DRV_MIIM_COMMANDS   true
#define DRV_MIIM_DRIVER_OBJECT              DRV_MIIM_OBJECT_BASE_Default            





// *****************************************************************************
// *****************************************************************************
// Section: Middleware & Other Library Configuration
// *****************************************************************************
// *****************************************************************************


/*** DNS Client Configuration ***/
#define TCPIP_STACK_USE_DNS
#define TCPIP_DNS_CLIENT_SERVER_TMO					60
#define TCPIP_DNS_CLIENT_TASK_PROCESS_RATE			200
#define TCPIP_DNS_CLIENT_CACHE_ENTRIES				5
#define TCPIP_DNS_CLIENT_CACHE_ENTRY_TMO			0
#define TCPIP_DNS_CLIENT_CACHE_PER_IPV4_ADDRESS		5
#define TCPIP_DNS_CLIENT_CACHE_PER_IPV6_ADDRESS		1
#define TCPIP_DNS_CLIENT_ADDRESS_TYPE			    IP_ADDRESS_TYPE_IPV4
#define TCPIP_DNS_CLIENT_CACHE_DEFAULT_TTL_VAL		1200
#define TCPIP_DNS_CLIENT_LOOKUP_RETRY_TMO			2
#define TCPIP_DNS_CLIENT_MAX_HOSTNAME_LEN			64
#define TCPIP_DNS_CLIENT_MAX_SELECT_INTERFACES		4
#define TCPIP_DNS_CLIENT_DELETE_OLD_ENTRIES			true
#define TCPIP_DNS_CLIENT_CONSOLE_CMD               	true
#define TCPIP_DNS_CLIENT_USER_NOTIFICATION   false



/*** ICMPv4 Server Configuration ***/
#define TCPIP_STACK_USE_ICMP_SERVER
#define TCPIP_ICMP_ECHO_ALLOW_BROADCASTS    false

/*** ICMPv4 Client Configuration ***/
#define TCPIP_STACK_USE_ICMP_CLIENT
#define TCPIP_ICMP_ECHO_REQUEST_TIMEOUT        500
#define TCPIP_ICMP_TASK_TICK_RATE              33
#define TCPIP_STACK_MAX_CLIENT_ECHO_REQUESTS   4
#define TCPIP_ICMP_COMMAND_ENABLE              false


/*** TCP Configuration ***/
#define TCPIP_TCP_MAX_SEG_SIZE_TX		        	1460
#define TCPIP_TCP_SOCKET_DEFAULT_TX_SIZE			512
#define TCPIP_TCP_SOCKET_DEFAULT_RX_SIZE			512
#define TCPIP_TCP_DYNAMIC_OPTIONS             			true
#define TCPIP_TCP_START_TIMEOUT_VAL		        	1000
#define TCPIP_TCP_DELAYED_ACK_TIMEOUT		    		100
#define TCPIP_TCP_FIN_WAIT_2_TIMEOUT		    		5000
#define TCPIP_TCP_KEEP_ALIVE_TIMEOUT		    		10000
#define TCPIP_TCP_CLOSE_WAIT_TIMEOUT		    		0
#define TCPIP_TCP_MAX_RETRIES		            		5
#define TCPIP_TCP_MAX_UNACKED_KEEP_ALIVES			6
#define TCPIP_TCP_MAX_SYN_RETRIES		        	3
#define TCPIP_TCP_AUTO_TRANSMIT_TIMEOUT_VAL			40
#define TCPIP_TCP_WINDOW_UPDATE_TIMEOUT_VAL			200
#define TCPIP_TCP_MAX_SOCKETS		                10
#define TCPIP_TCP_TASK_TICK_RATE		        	5
#define TCPIP_TCP_MSL_TIMEOUT		        	    0
#define TCPIP_TCP_QUIET_TIME		        	    0
#define TCPIP_TCP_COMMANDS   true
#define TCPIP_TCP_EXTERN_PACKET_PROCESS   false
#define TCPIP_TCP_DISABLE_CRYPTO_USAGE		        	    false



/*** DHCP Configuration ***/
#define TCPIP_STACK_USE_DHCP_CLIENT
#define TCPIP_DHCP_TIMEOUT                          10
#define TCPIP_DHCP_TASK_TICK_RATE                   5
#define TCPIP_DHCP_HOST_NAME_SIZE                   20
#define TCPIP_DHCP_CLIENT_CONNECT_PORT              68
#define TCPIP_DHCP_SERVER_LISTEN_PORT               67
#define TCPIP_DHCP_CLIENT_CONSOLE_CMD               true

#define TCPIP_DHCP_USE_OPTION_TIME_SERVER           0
#define TCPIP_DHCP_TIME_SERVER_ADDRESSES            0
#define TCPIP_DHCP_USE_OPTION_NTP_SERVER            0
#define TCPIP_DHCP_NTP_SERVER_ADDRESSES             0
#define TCPIP_DHCP_ARP_LEASE_CHECK_TMO              1000
#define TCPIP_DHCP_WAIT_ARP_FAIL_CHECK_TMO          10



/*** ARP Configuration ***/
#define TCPIP_ARP_CACHE_ENTRIES                 		5
#define TCPIP_ARP_CACHE_DELETE_OLD		        	true
#define TCPIP_ARP_CACHE_SOLVED_ENTRY_TMO			1200
#define TCPIP_ARP_CACHE_PENDING_ENTRY_TMO			60
#define TCPIP_ARP_CACHE_PENDING_RETRY_TMO			2
#define TCPIP_ARP_CACHE_PERMANENT_QUOTA		    		50
#define TCPIP_ARP_CACHE_PURGE_THRESHOLD		    		75
#define TCPIP_ARP_CACHE_PURGE_QUANTA		    		1
#define TCPIP_ARP_CACHE_ENTRY_RETRIES		    		3
#define TCPIP_ARP_GRATUITOUS_PROBE_COUNT			1
#define TCPIP_ARP_TASK_PROCESS_RATE		        	2000
#define TCPIP_ARP_PRIMARY_CACHE_ONLY		        	true
#define TCPIP_ARP_COMMANDS false



#define TCPIP_STACK_USE_ICMPV6_SERVER


#define TCPIP_IPV6_NDP_MAX_RTR_SOLICITATION_DELAY 	1
#define TCPIP_IPV6_NDP_RTR_SOLICITATION_INTERVAL 	4
#define TCPIP_IPV6_NDP_MAX_RTR_SOLICITATIONS 		3
#define TCPIP_IPV6_NDP_MAX_MULTICAST_SOLICIT 		3
#define TCPIP_IPV6_NDP_MAX_UNICAST_SOLICIT 			3
#define TCPIP_IPV6_NDP_MAX_ANYCAST_DELAY_TIME 		1
#define TCPIP_IPV6_NDP_MAX_NEIGHBOR_ADVERTISEMENT 	3
#define TCPIP_IPV6_NDP_REACHABLE_TIME 				30
#define TCPIP_IPV6_NDP_RETRANS_TIMER 				1
#define TCPIP_IPV6_NDP_DELAY_FIRST_PROBE_TIME 		5
#define TCPIP_IPV6_NDP_VALID_LIFETIME_TWO_HOURS 	(60 * 60 * 2)
#define TCPIP_IPV6_MTU_INCREASE_TIMEOUT 			600
#define TCPIP_IPV6_NDP_TASK_TIMER_RATE 				32


/* Network Configuration Index 0 */
#define TCPIP_NETWORK_DEFAULT_INTERFACE_NAME_IDX0 "GMAC"
#define TCPIP_IF_GMAC  

#define TCPIP_NETWORK_DEFAULT_HOST_NAME_IDX0              "MCHPBOARD_S"
#define TCPIP_NETWORK_DEFAULT_MAC_ADDR_IDX0               "00:04:25:1C:A0:02"

#define TCPIP_NETWORK_DEFAULT_IP_ADDRESS_IDX0         "192.168.1.12"
#define TCPIP_NETWORK_DEFAULT_IP_MASK_IDX0            "255.255.255.0"
#define TCPIP_NETWORK_DEFAULT_GATEWAY_IDX0            "192.168.100.1"
#define TCPIP_NETWORK_DEFAULT_DNS_IDX0                "192.168.100.1"
#define TCPIP_NETWORK_DEFAULT_SECOND_DNS_IDX0         "0.0.0.0"
#define TCPIP_NETWORK_DEFAULT_POWER_MODE_IDX0         "full"
#define TCPIP_NETWORK_DEFAULT_INTERFACE_FLAGS_IDX0            \
                                                    TCPIP_NETWORK_CONFIG_DHCP_SERVER_ON |\
                                                    TCPIP_NETWORK_CONFIG_DNS_SERVER_ON |\
                                                    TCPIP_NETWORK_CONFIG_IP_STATIC
                                                    
#define TCPIP_NETWORK_DEFAULT_MAC_DRIVER_IDX0         DRV_GMAC_Object



	/*** tcpip_cmd Configuration ***/
	#define TCPIP_STACK_COMMAND_ENABLE


#define DRV_KSZ8091_PHY_CONFIG_FLAGS       ( 0 \
                                                    | DRV_ETHPHY_CFG_RMII \
                                                    )
                                                    
#define DRV_KSZ8091_PHY_LINK_INIT_DELAY            500
#define DRV_KSZ8091_PHY_ADDRESS                    0
#define DRV_KSZ8091_PHY_PERIPHERAL_ID              GMAC_BASE_ADDRESS
#define DRV_ETHPHY_KSZ8091_NEG_INIT_TMO            1
#define DRV_ETHPHY_KSZ8091_NEG_DONE_TMO            2000
#define DRV_ETHPHY_KSZ8091_RESET_CLR_TMO           500




/*** IPv6 Configuration ***/
#define TCPIP_IPV6_DEFAULT_ALLOCATION_BLOCK_SIZE 		64
#define TCPIP_IPV6_MINIMUM_LINK_MTU 					1280
#define TCPIP_IPV6_DEFAULT_LINK_MTU 					1500
#define TCPIP_IPV6_DEFAULT_CUR_HOP_LIMIT 				64
#define TCPIP_IPV6_DEFAULT_BASE_REACHABLE_TIME 			30
#define TCPIP_IPV6_DEFAULT_RETRANSMIT_TIME 				1000
#define TCPIP_IPV6_QUEUE_NEIGHBOR_PACKET_LIMIT 			1
#define TCPIP_IPV6_NEIGHBOR_CACHE_ENTRY_STALE_TIMEOUT 	600
#define TCPIP_IPV6_QUEUE_MCAST_PACKET_LIMIT 			4
#define TCPIP_IPV6_QUEUED_MCAST_PACKET_TIMEOUT 			10
#define TCPIP_IPV6_TASK_PROCESS_RATE 					1000
#define TCPIP_IPV6_INIT_TASK_PROCESS_RATE 				32
#define TCPIP_IPV6_ULA_GENERATE_ENABLE 					false
#define TCPIP_IPV6_ULA_NTP_ACCESS_TMO 					12000
#define TCPIP_IPV6_ULA_NTP_VALID_WINDOW 				1000
#define TCPIP_IPV6_FRAGMENT_PKT_TIMEOUT 				60
#define TCPIP_IPV6_RX_FRAGMENTED_BUFFER_SIZE 			1514
#define TCPIP_IPV6_EXTERN_PACKET_PROCESS   false


/*** IPv4 Configuration ***/
#define TCPIP_IPV4_ARP_SLOTS                        10
#define TCPIP_IPV4_EXTERN_PACKET_PROCESS   false

#define TCPIP_IPV4_COMMANDS false

#define TCPIP_IPV4_FORWARDING_ENABLE    false 





/*** DHCP Server Configuration ***/
#define TCPIP_STACK_USE_DHCP_SERVER
#define TCPIP_DHCPS_TASK_PROCESS_RATE                     	200
#define TCPIP_DHCPS_MAX_NUMBER_INSTANCES					1
#define TCPIP_DHCPS_LEASE_ENTRIES_DEFAULT                   15
#define TCPIP_DHCPS_LEASE_SOLVED_ENTRY_TMO                  1200
#define TCPIP_DHCPS_LEASE_REMOVED_BEFORE_ACK                5
#define TCPIP_DHCP_SERVER_DELETE_OLD_ENTRIES              	true
#define TCPIP_DHCPS_LEASE_DURATION	TCPIP_DHCPS_LEASE_SOLVED_ENTRY_TMO

/*** DHCP Server Instance 0 Configuration ***/
#define TCPIP_DHCPS_DEFAULT_IP_ADDRESS_RANGE_START_IDX0             "192.168.1.100"

#define TCPIP_DHCPS_DEFAULT_SERVER_IP_ADDRESS_IDX0                  "192.168.1.12"

#define TCPIP_DHCPS_DEFAULT_SERVER_NETMASK_ADDRESS_IDX0             "255.255.255.0"

#define TCPIP_DHCPS_DEFAULT_SERVER_GATEWAY_ADDRESS_IDX0             "192.168.1.1"

#define TCPIP_DHCPS_DEFAULT_SERVER_PRIMARY_DNS_ADDRESS_IDX0         "192.168.1.1"

#define TCPIP_DHCPS_DEFAULT_SERVER_SECONDARY_DNS_ADDRESS_IDX0       "192.168.1.1"

#define TCPIP_DHCP_SERVER_INTERFACE_INDEX_IDX0                      0

#define TCPIP_DHCP_SERVER_POOL_ENABLED_IDX0                         true

#define TCPIP_DHCP_SERVER_POOL_INDEX_IDX0								0





/*** TCPIP Heap Configuration ***/
#define TCPIP_STACK_USE_INTERNAL_HEAP
#define TCPIP_STACK_DRAM_SIZE                       39250
#define TCPIP_STACK_DRAM_RUN_LIMIT                  2048

#define TCPIP_STACK_MALLOC_FUNC                     malloc

#define TCPIP_STACK_CALLOC_FUNC                     calloc

#define TCPIP_STACK_FREE_FUNC                       free



#define TCPIP_STACK_HEAP_USE_FLAGS                   TCPIP_STACK_HEAP_FLAG_ALLOC_UNCACHED

#define TCPIP_STACK_HEAP_USAGE_CONFIG                TCPIP_STACK_HEAP_USE_DEFAULT

#define TCPIP_STACK_SUPPORTED_HEAPS                  1




// *****************************************************************************
// *****************************************************************************
// Section: TCPIP Stack Configuration
// *****************************************************************************
// *****************************************************************************

#define TCPIP_STACK_USE_IPV4
#define TCPIP_STACK_USE_IPV6
#define TCPIP_STACK_USE_TCP
#define TCPIP_STACK_USE_UDP

#define TCPIP_STACK_TICK_RATE		        		5
#define TCPIP_STACK_SECURE_PORT_ENTRIES             10

#define TCPIP_STACK_ALIAS_INTERFACE_SUPPORT   false

#define TCPIP_PACKET_LOG_ENABLE     0

/* TCP/IP stack event notification */
#define TCPIP_STACK_USE_EVENT_NOTIFICATION
#define TCPIP_STACK_USER_NOTIFICATION   false
#define TCPIP_STACK_DOWN_OPERATION   true
#define TCPIP_STACK_IF_UP_DOWN_OPERATION   true
#define TCPIP_STACK_MAC_DOWN_OPERATION  true
#define TCPIP_STACK_INTERFACE_CHANGE_SIGNALING   false
#define TCPIP_STACK_CONFIGURATION_SAVE_RESTORE   true
#define TCPIP_STACK_EXTERN_PACKET_PROCESS   false
#define TCPIP_STACK_RUN_TIME_INIT   false

#define TCPIP_STACK_INTMAC_COUNT           1





/*** GMAC Configuration ***/
#define DRV_GMAC
#define TCPIP_GMAC_TX_DESCRIPTORS_COUNT_DUMMY    1
#define TCPIP_GMAC_RX_DESCRIPTORS_COUNT_DUMMY    1
#define TCPIP_GMAC_RX_BUFF_SIZE_DUMMY            64
#define TCPIP_GMAC_TX_BUFF_SIZE_DUMMY            64
/*** QUEUE 0 TX Configuration ***/
#define TCPIP_GMAC_TX_DESCRIPTORS_COUNT_QUE0            8
#define TCPIP_GMAC_MAX_TX_PKT_SIZE_QUE0                 1536
/*** QUEUE 0 RX Configuration ***/
#define TCPIP_GMAC_RX_DESCRIPTORS_COUNT_QUE0            8
#define TCPIP_GMAC_RX_BUFF_SIZE_QUE0                    1536
#define TCPIP_GMAC_RX_DEDICATED_BUFFERS_QUE0            8
#define TCPIP_GMAC_RX_ADDL_BUFF_COUNT_QUE0              2
#define TCPIP_GMAC_RX_BUFF_COUNT_THRESHOLD_QUE0         1
#define TCPIP_GMAC_RX_BUFF_ALLOC_COUNT_QUE0             2
#define TCPIP_GMAC_RX_FILTERS                       \
                                                        TCPIP_MAC_RX_FILTER_TYPE_BCAST_ACCEPT |\
                                                        TCPIP_MAC_RX_FILTER_TYPE_MCAST_ACCEPT |\
                                                        TCPIP_MAC_RX_FILTER_TYPE_UCAST_ACCEPT |\
                                                        TCPIP_MAC_RX_FILTER_TYPE_CRC_ERROR_REJECT |\
                                                          0
       
#define TCPIP_GMAC_SCREEN1_COUNT_QUE        0 
#define TCPIP_GMAC_SCREEN2_COUNT_QUE        0  

#define TCPIP_GMAC_ETH_OPEN_FLAGS                   \
                                                        TCPIP_ETH_OPEN_AUTO |\
                                                        TCPIP_ETH_OPEN_FDUPLEX |\
                                                        TCPIP_ETH_OPEN_HDUPLEX |\
                                                        TCPIP_ETH_OPEN_100 |\
                                                        TCPIP_ETH_OPEN_10 |\
                                                        TCPIP_ETH_OPEN_MDIX_AUTO |\
                                                        TCPIP_ETH_OPEN_RMII |\
                                                        0

#define TCPIP_GMAC_MODULE_ID                       GMAC_BASE_ADDRESS

#define TCPIP_INTMAC_PERIPHERAL_CLK                 120000000

#define DRV_GMAC_RX_CHKSM_OFFLOAD               (TCPIP_MAC_CHECKSUM_NONE)           
#define DRV_GMAC_TX_CHKSM_OFFLOAD               (TCPIP_MAC_CHECKSUM_NONE)       
#define TCPIP_GMAC_TX_PRIO_COUNT                1
#define TCPIP_GMAC_RX_PRIO_COUNT                1
#define DRV_GMAC_NUMBER_OF_QUEUES               1
#define DRV_GMAC_RMII_MODE                      0




/*** SNTP Configuration ***/
#define TCPIP_STACK_USE_SNTP_CLIENT
#define TCPIP_NTP_DEFAULT_IF		        	"GMAC"
#define TCPIP_NTP_VERSION             			4
#define TCPIP_NTP_DEFAULT_CONNECTION_TYPE   	IP_ADDRESS_TYPE_IPV4
#define TCPIP_NTP_EPOCH		                	2208988800ul
#define TCPIP_NTP_REPLY_TIMEOUT		        	6
#define TCPIP_NTP_MAX_STRATUM		        	15
#define TCPIP_NTP_TIME_STAMP_TMO				660
#define TCPIP_NTP_SERVER		        		"pool.ntp.org"
#define TCPIP_NTP_SERVER_MAX_LENGTH				30
#define TCPIP_NTP_QUERY_INTERVAL				600
#define TCPIP_NTP_FAST_QUERY_INTERVAL	    	14
#define TCPIP_NTP_TASK_TICK_RATE				1100
#define TCPIP_NTP_RX_QUEUE_LIMIT				2



/*** announce Configuration ***/
#define TCPIP_STACK_USE_ANNOUNCE
#define TCPIP_ANNOUNCE_MAX_PAYLOAD 	512
#define TCPIP_ANNOUNCE_TASK_RATE    333
#define TCPIP_ANNOUNCE_NETWORK_DIRECTED_BCAST             			false



/*** UDP Configuration ***/
#define TCPIP_UDP_MAX_SOCKETS		                	10
#define TCPIP_UDP_SOCKET_DEFAULT_TX_SIZE		    	512
#define TCPIP_UDP_SOCKET_DEFAULT_TX_QUEUE_LIMIT    	 	3
#define TCPIP_UDP_SOCKET_DEFAULT_RX_QUEUE_LIMIT			3
#define TCPIP_UDP_USE_POOL_BUFFERS   false
#define TCPIP_UDP_USE_TX_CHECKSUM             			true
#define TCPIP_UDP_USE_RX_CHECKSUM             			true
#define TCPIP_UDP_COMMANDS   false
#define TCPIP_UDP_EXTERN_PACKET_PROCESS   false



/*** FTP Configuration ***/
#define TCPIP_STACK_USE_FTP_SERVER
#define TCPIP_FTP_USER_NAME_LEN                 10
#define TCPIP_FTP_MAX_CONNECTIONS               1
#define TCPIP_FTP_DATA_SKT_TX_BUFF_SIZE         0
#define TCPIP_FTP_DATA_SKT_RX_BUFF_SIZE         0
#define TCPIP_FTPS_TASK_TICK_RATE               5000
#define TCPIP_FTP_TIMEOUT                       300

#define TCPIP_FTPS_COMMAND_LISTEN_PORT          21
#define TCPIP_FTPS_DATA_LISTEN_PORT             20
#define TCPIP_FTP_MOUNT_POINT                   "/mnt/myDrive1"

/***Comment this line out to disable MPFS***/
#define TCPIP_FTP_PUT_ENABLED   

#define TCPIP_FTPS_OBSOLETE_AUTHENTICATION false
#define TCPIP_FTPS_AUTHENTICATION_CONN_INFO true



/*** wolfCrypt Library Configuration ***/
#define MICROCHIP_PIC32
#define MICROCHIP_MPLAB_HARMONY
#define MICROCHIP_MPLAB_HARMONY_3
#define HAVE_MCAPI
#define SIZEOF_LONG_LONG 8
#define WOLFSSL_USER_IO
#define NO_WRITEV
#define NO_FILESYSTEM
#define USE_FAST_MATH
#define NO_PWDBASED
#define HAVE_MCAPI
#define WOLF_CRYPTO_CB  // provide call-back support
#define WOLFCRYPT_ONLY
// ---------- FUNCTIONAL CONFIGURATION START ----------
#define WOLFSSL_AES_SMALL_TABLES
#define NO_MD4
#define WOLFSSL_SHA224
#define WOLFSSL_AES_128
#define WOLFSSL_AES_192
#define WOLFSSL_AES_256
#define WOLFSSL_AES_DIRECT
#define HAVE_AES_DECRYPT
#define HAVE_AES_ECB
#define HAVE_AES_CBC
#define WOLFSSL_AES_COUNTER
#define WOLFSSL_AES_OFB
#define HAVE_AESGCM
#define HAVE_AESCCM
#define NO_RC4
#define NO_HC128
#define NO_RABBIT
#define HAVE_ECC
#define NO_DH
#define NO_DSA
#define FP_MAX_BITS 4096
#define USE_CERT_BUFFERS_2048
#define NO_DEV_RANDOM
#define HAVE_HASHDRBG
#define WC_NO_HARDEN
#define SINGLE_THREADED
#define NO_SIG_WRAPPER
#define NO_ERROR_STRINGS
#define NO_WOLFSSL_MEMORY
// ---------- FUNCTIONAL CONFIGURATION END ----------

/* MPLAB Harmony Net Presentation Layer Definitions*/
#define NET_PRES_NUM_INSTANCE 1
#define NET_PRES_NUM_SOCKETS 10




/*** DNS Server Configuration ***/
#define TCPIP_STACK_USE_DNS_SERVER
#define TCPIP_DNSS_HOST_NAME_LEN		    	64
#define TCPIP_DNSS_REPLY_BOARD_ADDR				true
#define TCPIP_DNSS_CACHE_PER_IPV4_ADDRESS		2
#define TCPIP_DNSS_CACHE_PER_IPV6_ADDRESS		1
#define TCPIP_DNSS_TTL_TIME						600
#define TCPIP_DNSS_TASK_PROCESS_RATE			33
#define TCPIP_DNSS_DELETE_OLD_LEASE				true
#define TCPIP_DNSS_CONSOLE_CMD           false
/***Maximum DNS server Cache entries. It is the sum of TCPIP_DNSS_CACHE_PER_IPV4_ADDRESS and TCPIP_DNSS_CACHE_PER_IPV6_ADDRESS.***/
#define TCPIP_DNSS_CACHE_MAX_SERVER_ENTRIES     (TCPIP_DNSS_CACHE_PER_IPV4_ADDRESS + TCPIP_DNSS_CACHE_PER_IPV6_ADDRESS)


#define TCPIP_STACK_NETWORK_INTERAFCE_COUNT  	1







// *****************************************************************************
// *****************************************************************************
// Section: Application Configuration
// *****************************************************************************
// *****************************************************************************


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // CONFIGURATION_H
/*******************************************************************************
 End of File
*/
