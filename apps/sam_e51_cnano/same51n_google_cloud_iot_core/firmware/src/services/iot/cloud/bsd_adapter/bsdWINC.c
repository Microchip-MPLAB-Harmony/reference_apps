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
 *                           bsdWinc.c
 *
 * About:
 *
 * 
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "bsdWINC.h"
#include "../../../../iot_config/IoT_Sensor_Node_config.h"
#include "socket.h"
#include "../../../../debug_print.h"

#define MAX_SUPPORTED_SOCKETS		2
/**********************BSD (WINC) Enumerator Translators ********************************/
typedef enum
{
	WINC_AF_INET = 2,		
}wincSupportedDomains_t;

typedef enum
{
	WINC_STREAM = 1,
	WINC_DGRAM = 2,
}wincSupportedTypes_t;

typedef enum
{
	WINC_NON_TLS = 0,
	WINC_TLS = 0x01,
}wincSupportedProtocol_t;

typedef enum
{
	WINC_SOCK_ERR_NO_ERROR = 0,
	WINC_SOCK_ERR_INVALID_ADDRESS = -1,
	WINC_SOCK_ERR_ADDR_ALREADY_IN_USE = -2,
	WINC_SOCK_ERR_MAX_TCP_SOCK = -3,
	WINC_SOCK_ERR_MAX_UDP_SOCK = -4,
	WINC_SOCK_ERR_INVALID_ARG = -6,
	WINC_SOCK_ERR_MAX_LISTEN_SOCK = -7,
	WINC_SOCK_ERR_INVALID = -9,
	WINC_SOCK_ERR_ADDR_IS_REQUIRED = -11,
	WINC_SOCK_ERR_CONN_ABORTED = -12,
	WINC_SOCK_ERR_TIMEOUT = -13,
	WINC_SOCK_ERR_BUFFER_FULL = -14,
}wincSocketResponses_t;

typedef enum
{
	WINC_SO_SSL_BYPASS_X509_VERIF = 1,
	WINC_SO_SSL_SNI = 2,
	WINC_SO_SSL_ENABLE_SESSION_CACHING = 3,
	WINC_SO_SSL_ENABLE_SNI_VALIDATION = 4,	
}wincSupportedSockOptions;

typedef enum
{
	WINC_SOL_SOCKET = 1,
	WINC_SOL_SSL_SOCKET = 2,
}wincSupportedSockLevel;

/*******************WINC specific socket address structure***************************/
typedef struct {
    uint16_t		sa_family;		//Socket address
    uint8_t		sa_data[14];	// Maximum size of all the different socket address structures.
}wincSupported_sockaddr;

/**********************BSD (Private) Global Variables ********************************/
static bsdErrno_t bsdErrorNumber;

static packetReceptionHandler_t *packetRecvInfo;

/**********************BSD (Private) Function Prototypes *****************************/
static void bsd_setErrNo (bsdErrno_t errorNumber);

/**********************BSD (Private) Function Implementations ************************/
static void bsd_setErrNo (bsdErrno_t errorNumber)
{
	bsdErrorNumber = errorNumber;
}

/**********************BSD (Public) Function Implementations **************************/
bsdErrno_t BSD_GetErrNo(void)
{
	return bsdErrorNumber;
}

packetReceptionHandler_t* getSocketInfo(uint8_t sock)
{   
   uint8_t i = 0;
   if (sock >= 0)
   {
      packetReceptionHandler_t *bsdSocketInfo = BSD_GetRecvHandlerTable();
      for(i = 0; i < MAX_SUPPORTED_SOCKETS; i++)
      {
         if(bsdSocketInfo)
         {
            if(*(bsdSocketInfo->socket) == sock)
            {
               return bsdSocketInfo;
            }
         }
         bsdSocketInfo++;
      }
   }
   return NULL;
}

int BSD_socket(int domain, int type, int protocol)
{
	wincSupportedDomains_t wincDomain;
	wincSupportedTypes_t wincType;
	wincSupportedProtocol_t wincProtocol;
   int8_t wincSocketReturn;
    
	switch ((bsdDomain_t)domain)
	{
		case PF_INET:
			wincDomain = WINC_AF_INET;
		break;
		default:	// Domain Not Implemented by WINC
			bsd_setErrNo(EAFNOSUPPORT);
			return BSD_ERROR;
	}
	
	switch ((bsdTypes_t)type)
	{
		case BSD_SOCK_STREAM:
			wincType = WINC_STREAM;
		break;
		case BSD_SOCK_DGRAM:
			wincType = WINC_DGRAM;
		break;
		default:	// Type Not Implemented by WINC
			bsd_setErrNo(EAFNOSUPPORT);
			return BSD_ERROR;
	}
	
	switch ((wincSupportedProtocol_t)protocol)
	{
		case WINC_NON_TLS:
		case WINC_TLS:
			wincProtocol = protocol;
		break;
		default:	// Protocol Not Implemented by WINC
			bsd_setErrNo(EINVAL);
			return BSD_ERROR;
	}

   wincSocketReturn = socket((uint16_t)wincDomain, (uint8_t)wincType, (uint8_t)wincProtocol);
   if (wincSocketReturn < 0)			   // WINC Socket Access Denied always returns -1 for failure to get socket
	{
      debug_printError("BSD: wincSocketReturn (%d)", wincSocketReturn);
		bsd_setErrNo(EACCES);
		return BSD_ERROR;
	}       
   
   return wincSocketReturn;		// >= 0 represents SUCCESS
}

int BSD_connect(int socket, const struct bsd_sockaddr *name, socklen_t namelen)
{ 
   int returnValue = BSD_ERROR;
	wincSocketResponses_t wincConnectReturn = WINC_SOCK_ERR_INVALID;	
	wincSupported_sockaddr winc_sockaddr;

    packetReceptionHandler_t *bsdSocket = getSocketInfo(socket);
    if(!bsdSocket)
    {
        debug_printError("BSD: connect error unknown socket number");
    }
    else
    {
	    winc_sockaddr.sa_family = name->sa_family;
	    memcpy(winc_sockaddr.sa_data, name->sa_data, sizeof(winc_sockaddr.sa_data));
	
      if(winc_sockaddr.sa_family == PF_INET)
      {
            winc_sockaddr.sa_family = AF_INET;
            wincConnectReturn = connect(socket, (struct sockaddr*)&winc_sockaddr, (uint8_t)namelen);	
            if(wincConnectReturn != WINC_SOCK_ERR_NO_ERROR)
            {
               debug_printError("BSD: connect error %d",wincConnectReturn);
               switch(wincConnectReturn)
               {
                  case WINC_SOCK_ERR_INVALID_ARG:
                     if(socket < 0)
                     {
                        bsd_setErrNo(ENOTSOCK);
                     }
                     else if(name == NULL)
                     {
                        bsd_setErrNo(EADDRNOTAVAIL);
                     }
                     else if(namelen == 0)
                     {
                        bsd_setErrNo(EINVAL);
                     } else
                     {
                        bsd_setErrNo(ENOTSOCK);
                     }
                     break;                   	    
                  case WINC_SOCK_ERR_INVALID:
                     bsd_setErrNo(EIO);
                     break;
                  default:
                     break;
               }
            }
            else
            {
               debug_printGOOD("BSD: socket (%d) in progress",*bsdSocket->socket);
               bsdSocket->socketState = SOCKET_IN_PROGRESS;
               returnValue = BSD_SUCCESS;
            }
		}
      else
      {
			    bsd_setErrNo(EAFNOSUPPORT);
      }
    }
    return returnValue; 
}

void BSD_SetRecvHandlerTable(packetReceptionHandler_t *appRecvInfo)
{
	packetRecvInfo = appRecvInfo;
}

packetReceptionHandler_t *BSD_GetRecvHandlerTable()
{
	return packetRecvInfo;
}

int BSD_recv(int socket, const void *buf, size_t len, int flags)
{
    wincSocketResponses_t wincRecvReturn;
	
	if (flags != 0)
	{	// Flag Not Support by WINC implementation
		bsd_setErrNo(EINVAL);
		return BSD_ERROR;		
	} 
	
   wincRecvReturn = recv((SOCKET)socket, (void*)buf, (uint16_t)len, (uint32_t)flags);
	if(wincRecvReturn != WINC_SOCK_ERR_NO_ERROR)
	{
		switch(wincRecvReturn)
		{
			case WINC_SOCK_ERR_INVALID_ARG:
				if(socket < 0)
				{
					debug_printError("BSD: ENOTSOCK");
					bsd_setErrNo(ENOTSOCK);
				}
				else if(buf == NULL)
				{
					debug_printError("BSD: EFAULT");
					bsd_setErrNo(EFAULT);
				}
				else if(len == 0)
				{
					debug_printError("BSD: EMSGSIZE");
					bsd_setErrNo(EMSGSIZE);
				}
				else
				{
					debug_printError("BSD: EINVAL");
					bsd_setErrNo(EINVAL);
				}
			break;
			case WINC_SOCK_ERR_BUFFER_FULL:
			    debug_printError("BSD: BSD: ERR_BUFFER_FULL");
				bsd_setErrNo(ENOBUFS);
			break;
            default:
				debug_printError("BSD: BSD: (%d)", wincRecvReturn);
            break;
		}
		return BSD_ERROR;
	} 
	else
	{
		// The socket.c send() API only returns (0) to indicate No Error
		// Current WINC implementation doesn't use returned value per BSD.
		// debug_printGOOD("BSD: Recv Success");
		 
		// TODO: Number of Bytes received should be returned in correct implementation.
		return BSD_SUCCESS;
	}
}

int BSD_close(int socket)
{
   wincSocketResponses_t wincCloseReturn;
   
   debug_printGOOD("BSD: BSD_close (%d) ",socket);
   packetReceptionHandler_t* sock = getSocketInfo(socket);
   if (sock != NULL)
   {
      sock->socketState = NOT_A_SOCKET;
   }
    
   wincCloseReturn = shutdown((SOCKET)socket);

	if (wincCloseReturn!= WINC_SOCK_ERR_NO_ERROR)
	{
		switch(wincCloseReturn)
		{
		   case WINC_SOCK_ERR_INVALID_ARG:
		       bsd_setErrNo(EBADF);
		   break;
		   case WINC_SOCK_ERR_INVALID:
		       bsd_setErrNo(EIO);
		   break;
		   default:
		   break;
		}
		return BSD_ERROR;
	} 
	else
	{
        return BSD_SUCCESS;
	}
}

uint32_t BSD_htonl(uint32_t hostlong)
{
	return _htonl(hostlong);
}

uint16_t BSD_htons(uint16_t hostshort)
{
	return _htons(hostshort);
}

uint32_t BSD_ntohl(uint32_t netlong)
{
	return _ntohl(netlong);
}

uint16_t BSD_ntohs(uint16_t netshort)
{
	return _ntohs(netshort);
}

int BSD_bind(int socket, const struct bsd_sockaddr *addr, socklen_t addrlen)
{
	wincSocketResponses_t wincBindReturn;
	static wincSupported_sockaddr winc_sockaddr;
	
	winc_sockaddr.sa_family = addr->sa_family;
	memcpy((void*)winc_sockaddr.sa_data, (const void *)addr->sa_data, sizeof(winc_sockaddr.sa_data));

	switch(winc_sockaddr.sa_family)
	{
		case PF_INET:
			winc_sockaddr.sa_family = AF_INET;
			wincBindReturn = bind((int8_t)socket, (struct sockaddr*)&winc_sockaddr, (uint8_t)addrlen);
		break;
		default:		//Address family not supported by WINC
			bsd_setErrNo(EAFNOSUPPORT);
			return BSD_ERROR;		
	} 
	
	if (wincBindReturn != WINC_SOCK_ERR_NO_ERROR)
	{
		switch(wincBindReturn)
		{
			case WINC_SOCK_ERR_INVALID_ARG:
				if(socket < 0)
				{
					bsd_setErrNo(ENOTSOCK);
				}
				else if(addr != NULL)
				{
					bsd_setErrNo(EFAULT);
				}
				else if(addrlen == 0)
				{
					bsd_setErrNo(EINVAL);
				}
				break;
			case WINC_SOCK_ERR_INVALID:
				bsd_setErrNo(EIO);
				break;
			default:
				break;
		}
		return BSD_ERROR;
	}
	else
	{
		return BSD_SUCCESS;
	}
}

int BSD_recvfrom(int socket, void *buf,	size_t len, int flags, struct bsd_sockaddr *from, socklen_t *fromlen)
{
    wincSocketResponses_t wincRecvFromReturn;
	wincSupported_sockaddr winc_sockaddr;
	
	if (flags != 0)
	{	// Flag Not Support by WINC implementation
		bsd_setErrNo(EINVAL);
		return BSD_ERROR;		
	} 
	
	winc_sockaddr.sa_family = from->sa_family;
	memcpy((void*)winc_sockaddr.sa_data, (const void *)from->sa_data, sizeof(winc_sockaddr.sa_data));
	
	switch(winc_sockaddr.sa_family)
	{
		case PF_INET:
			winc_sockaddr.sa_family = AF_INET;
			wincRecvFromReturn = recvfrom((SOCKET)socket, buf, (uint16_t)len, (uint32_t)flags);
		break;
		default:		//Address family not supported by WINC
			bsd_setErrNo(EAFNOSUPPORT);
			return BSD_ERROR;		
	} 
	
	if(wincRecvFromReturn != WINC_SOCK_ERR_NO_ERROR)
	{
		switch(wincRecvFromReturn)
		{
			case WINC_SOCK_ERR_INVALID_ARG:
				if(socket < 0)
				{
					bsd_setErrNo(ENOTSOCK);
				}
				else if(buf == NULL)
				{
					bsd_setErrNo(EFAULT);
				}
				else if(len == 0)
				{
					bsd_setErrNo(EMSGSIZE);
				}
				else
				{
					bsd_setErrNo(EINVAL);
				}
			break;
			case WINC_SOCK_ERR_BUFFER_FULL:
				bsd_setErrNo(ENOBUFS);
			break;
            default:
            break;
		}
		return BSD_ERROR;
	} 
	else
	{
		// The socket.c send() API only returns (0) to indicate No Error
		// Current WINC implementation doesn't use returned value per BSD.
		
		// TODO: Number of Bytes received should be returned in correct implementation.
		return BSD_SUCCESS;
	}
}

int BSD_listen(int socket, int backlog)
{
	wincSocketResponses_t wincListenResponse;
	
	wincListenResponse = listen ((SOCKET)socket, (uint8_t)backlog);
	
	if (wincListenResponse != WINC_SOCK_ERR_NO_ERROR)
	{
		switch(wincListenResponse)
		{
			case SOCK_ERR_INVALID_ARG:
			if (socket < 0)
			{
				bsd_setErrNo(ENOTSOCK);
			}
			else
			{
				bsd_setErrNo(EINVAL);
			}
			break;
			case SOCK_ERR_INVALID:
				bsd_setErrNo(EIO);
			break;
			default:
			break;
		}
		return BSD_ERROR;
	}
	else
	{
		return BSD_SUCCESS;
	}
}

int BSD_accept(int socket, struct bsd_sockaddr * addr, socklen_t * addrlen)
{
	wincSocketResponses_t wincAcceptReturn;
	wincSupported_sockaddr winc_sockaddr;
	
	winc_sockaddr.sa_family = addr->sa_family;
	memcpy((void*)winc_sockaddr.sa_data, (const void *)addr->sa_data, sizeof(winc_sockaddr.sa_data));
	
	switch(winc_sockaddr.sa_family)
	{
		case PF_INET:
			winc_sockaddr.sa_family = AF_INET;
			wincAcceptReturn = accept((SOCKET)socket, (struct sockaddr*)&winc_sockaddr, (uint8_t *)addrlen);
		break;
		default:		//Address family not supported by WINC
			bsd_setErrNo(EAFNOSUPPORT);
			return BSD_ERROR;		
	} 
	
	if (wincAcceptReturn != WINC_SOCK_ERR_NO_ERROR)
	{
		if (socket < 0)
		{
			bsd_setErrNo(ENOTSOCK);
		}
		else
		{
			bsd_setErrNo(EINVAL);
		}
		return BSD_ERROR;
	}
	else
	{
		return BSD_SUCCESS;
    }
}

int BSD_getsockopt(int socket, int level, int optname, void * optval, socklen_t * optlen)
{
	bsd_setErrNo(ENOSYS);
	return BSD_ERROR;
}

int BSD_setsockopt(int socket, int level, int optname, const void *optval, socklen_t optlen)
{
	wincSocketResponses_t wincSockOptResponse;
	wincSupportedSockLevel wincSockLevel;
	wincSupportedSockOptions wincSockOptions;
	
	switch((wincSupportedSockLevel)level)
	{
		case WINC_SOL_SOCKET:
		case WINC_SOL_SSL_SOCKET:
			wincSockLevel = level;
		break;
		default:
			bsd_setErrNo(EIO);
		return BSD_ERROR;
		
	}
	switch((wincSupportedSockOptions)optname)
	{
		case WINC_SO_SSL_BYPASS_X509_VERIF:
		case WINC_SO_SSL_SNI:
		case WINC_SO_SSL_ENABLE_SESSION_CACHING:
		case WINC_SO_SSL_ENABLE_SNI_VALIDATION:
			wincSockOptions = optname;
		break;	
		default:
			bsd_setErrNo(EIO);
		return BSD_ERROR;
	}
    wincSockOptResponse = setsockopt((SOCKET)socket, (uint8_t) wincSockLevel, (uint8_t) wincSockOptions, optval, (uint16_t)optlen);
	if (wincSockOptResponse != WINC_SOCK_ERR_NO_ERROR)
	{
		switch(wincSockOptResponse)
		{
			case SOCK_ERR_INVALID_ARG:
				if (socket < 0)
				{
					bsd_setErrNo(ENOTSOCK);
				}
				else if (optval == NULL)
				{
					bsd_setErrNo(EFAULT);
				}
				else
				{
					bsd_setErrNo(EINVAL);
				}
				break;
			case SOCK_ERR_INVALID:
				bsd_setErrNo(EIO);
				break;
			default:
				break;
		}
		return BSD_ERROR;
	}
	else
	{
		return BSD_SUCCESS;
	}
}

int BSD_write(int fd, const void *buf, size_t nbytes)
{
	bsd_setErrNo(ENOSYS);
	return BSD_ERROR;
}

int BSD_read(int fd, void *buf, size_t nbytes)
{
	bsd_setErrNo(ENOSYS);
	return BSD_ERROR;
}

int BSD_poll(struct pollfd *ufds, unsigned int nfds, int timeout)
{
	bsd_setErrNo(ENOSYS);
	return BSD_ERROR;
}

socketState_t BSD_GetSocketState(int sock)
{
	socketState_t sockState;
	packetReceptionHandler_t *bsdSocketInfo;

	sockState = NOT_A_SOCKET;
	bsdSocketInfo = getSocketInfo(sock);

	if(bsdSocketInfo)
	{
	   sockState = bsdSocketInfo->socketState;
	}

	return sockState;
}

int BSD_send(int socket, const void *msg, size_t len, int flags)
{
   wincSocketResponses_t wincSendReturn;

   if (flags != 0)
   {	// Flag Not Support by WINC implementation
      bsd_setErrNo(EINVAL);
      return BSD_ERROR;
   }
   
   wincSendReturn = send((SOCKET)socket, (void*)msg, (uint16_t)len, (uint16_t)flags);
   if(wincSendReturn != WINC_SOCK_ERR_NO_ERROR)
   {
      debug_printError("BSD: wincSendReturn (%d)",wincSendReturn);
      // Most likely in this case we HAVE to update the socket state, especially if we get ENOTSOCK !!!
      switch(wincSendReturn)
      {
         case WINC_SOCK_ERR_INVALID_ARG:
         if(socket < 0)
         {
            bsd_setErrNo(ENOTSOCK);
         }
         else if(msg == NULL)
         {
            bsd_setErrNo(EFAULT);
         }
         else if(len > SOCKET_BUFFER_MAX_LENGTH)
         {
            bsd_setErrNo(EMSGSIZE);
         }
         else
         {
            bsd_setErrNo(EINVAL);
         }
         break;
         case WINC_SOCK_ERR_BUFFER_FULL:
         bsd_setErrNo(ENOBUFS);
         break;
         default:
         break;
      }
      return BSD_ERROR;
   }
   else
   {
      // The socket.c send() API either sends the entire packet or
      // does not send the packet at all. Therefore, if it does
      // successfully send the packet, 'len' number of bytes will
      // be transmitted. In this case, it is safe to return the
      // value of 'len' as the number of bytes sent.
      return len;
   }
}

int BSD_sendto(int socket, const void *msg, size_t len,	int flags, const struct bsd_sockaddr *to, socklen_t tolen)
{
	wincSocketResponses_t wincSendToResponse;
	wincSupported_sockaddr winc_sockaddr;
	
	if (flags != 0)
	{	// Flag Not Support by WINC implementation
		bsd_setErrNo(EINVAL);
		return BSD_ERROR;		
	} 
	
	winc_sockaddr.sa_family = to->sa_family;
	memcpy((void*)winc_sockaddr.sa_data, (const void *)to->sa_data, sizeof(winc_sockaddr.sa_data));
	
	switch(winc_sockaddr.sa_family)
	{
		case PF_INET:
			winc_sockaddr.sa_family = AF_INET;

			wincSendToResponse = sendto((SOCKET)socket, (void *)msg, (uint16_t)(len), (uint16_t)flags, (struct sockaddr *)&winc_sockaddr, (uint8_t)tolen);
         debug_print("BSD: wincSendToResponse (%d)", wincSendToResponse);
		break;
		default:		//Address family not supported by WINC
			bsd_setErrNo(EAFNOSUPPORT);
			return BSD_ERROR;		
	} 

	if (wincSendToResponse != WINC_SOCK_ERR_NO_ERROR)
	{
		switch(wincSendToResponse)
		{
			case SOCK_ERR_INVALID_ARG:
				if(socket < 0)
				{
					bsd_setErrNo(ENOTSOCK);
				}
				else if(msg == NULL)
				{
					bsd_setErrNo(EFAULT);
				}
				else if(len > SOCKET_BUFFER_MAX_LENGTH)
				{
					bsd_setErrNo(EMSGSIZE);
				}
				else
				{
					bsd_setErrNo(EINVAL);
				}
			break;
			case SOCK_ERR_BUFFER_FULL:
				bsd_setErrNo(ENOBUFS);
			break;
			default:
			break;
		}
		return BSD_ERROR;
	}
	else
	{
		// The socket.c send() API either sends the entire packet or
		// does not send the packet at all. Therefore, if it does
		// successfully send the packet, 'len' number of bytes will
		// be transmitted. In this case, it is safe to return the
		// value of 'len' as the number of bytes sent.
		return len;
	}
}

void BSD_SocketHandler(int8_t sock, uint8_t msgType, void *pMsg)
{
	packetReceptionHandler_t *bsdSocketInfo;

	bsdSocketInfo = getSocketInfo(sock);
   if(bsdSocketInfo == NULL) {
      debug_printError("BSD: SH->socket not found");
      return;
   }   
	switch (msgType)
	{
		case SOCKET_MSG_CONNECT:
         debug_print("BSD: SOCKET_MSG_CONNECT");
         if(pMsg)
         {
            	tstrSocketConnectMsg *pstrConnect = (tstrSocketConnectMsg *)pMsg;
            if (pstrConnect->s8Error >= 0)
            {
               debug_printGOOD("BSD: MSG_CONNECT successful");
               bsdSocketInfo->socketState = SOCKET_CONNECTED;
            }
            else
            {
               debug_printError("BSD: Closing Socket in MSG_CONNECT error (%d)",pstrConnect->s8Error);
               BSD_close(sock);
            }
         }
		break;

		case SOCKET_MSG_SEND:
		   bsdSocketInfo->socketState = SOCKET_CONNECTED;
		break;

      case SOCKET_MSG_RECV:
         if(pMsg)
         {
          	tstrSocketRecvMsg *pstrRecv = (tstrSocketRecvMsg *)pMsg;
            debug_printInfo("BSD: SOCKET RECV SIZE %d", pstrRecv->s16BufferSize);
            debug_printInfo("BSD: SOCKET RECV SOCK ADDR %d ", pstrRecv->strRemoteAddr);
            
            if (pstrRecv->s16BufferSize > 0) 
            {
	            bsdSocketInfo->recvCallBack(pstrRecv->pu8Buffer, pstrRecv->s16BufferSize);
	            bsdSocketInfo->socketState = SOCKET_CONNECTED;
							   
            } else {
               debug_printError("BSD: SOCKET (%d) CLOSED", sock);
               BSD_close(sock);  
            }                                
         }
      break;
		
		case SOCKET_MSG_RECVFROM:
		{
         if(pMsg)
         {
			   tstrSocketRecvMsg *pstrRecv = (tstrSocketRecvMsg *)pMsg;
			   if (pstrRecv->pu8Buffer && pstrRecv->s16BufferSize)
			   {
				   bsdSocketInfo->recvCallBack(pstrRecv->pu8Buffer, pstrRecv->s16BufferSize);
				   bsdSocketInfo->socketState = SOCKET_CONNECTED;
			   }  else {
               debug_printError("BSD: SOCKET (%d) CLOSED", sock);
			      BSD_close(sock);
            }
         }
		}
		break;
		
		default:
         debug_printError("BSD: msgType (%d) default",msgType);
		break;
	}

}
