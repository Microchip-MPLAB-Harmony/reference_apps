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
 *                           bsdWINC.h
 *
 * About:
 *
 * 
 ******************************************************************************/
#ifndef BSD_WINC_H
#define	BSD_WINC_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/***************** BSD Generic Defines **********************/
#define		BSD_SUCCESS		0
#define		BSD_ERROR		-1

/************* (END) BSD Generic Defines (END) *****************/

/***************** BSD Type Defined Enumerators **********************/
// ToDo Check whether this enum can be moved to some other appropriate location
// This enum currently uses the same values as the TCPIPLite stack
typedef enum
{
	NOT_A_SOCKET = 0,           // This is not a socket
	SOCKET_CLOSED,              // Socket closed
	SOCKET_IN_PROGRESS,         // The TCP listen or initiate a connection
	SOCKET_CONNECTED,           // The TCP is in established state user can send/receive data
	SOCKET_CLOSING              // The user initiate the closing procedure for this socket
} socketState_t;

typedef enum
{
	PF_UNIX = 0,		
	PF_LOCAL,
	PF_INET,		// IPv4
	PF_INET6,
	PF_IPX,	
	PF_NETLINK,		// Kernel UI
	PF_X25,			
	PF_AX25,
	PF_ATMPVC,
	PF_APPLETALK,
	PF_PACKET,
}bsdDomain_t;

typedef enum
{
	BSD_SOCK_STREAM = 1,
	BSD_SOCK_DGRAM,
	BSD_SOCK_SEQPACKET,
	BSD_SOCK_RAW,
	BSD_SOCK_RDM,
	BSD_SOCK_PACKET,
}bsdTypes_t;

/************** (END) BSD Type Defined Enumerators (END) *******************/

/***************** Error Number Defined Enumerators **********************/
typedef enum
{
	ERROR0 = 0,
	EPERM,
	ENOENT,
	ESRCH,
	EINTR,
	EIO,
	ENXIO,
	E2BIG,
	ENOEXEC,
	EBADF,
	ECHILD,
	EDEADLK,
	ENOMEM,
	EACCES,
	EFAULT,
	ENOTBLK,
	EBUSY,
	EEXIST,
	EXDEV,
	ENODEV,
	ENOTDIR,
	EISDIR,
	EINVAL,
	ENFILE,
	EMFILE,
	ENOTTY,
	ETXTBSY,
	EFBIG,
	ENOSPC,
	ESPIPE,
	EROFS,
	EMLINK,
	EPIPE,
	EDOM,				// C99 
	ERANGE,				// C99 
	EAGAIN,
	EINPROGRESS,
	EALREADY,
	ENOTSOCK,
	EDESTADDRREQ,
	EMSGSIZE,
	EPROTOTYPE,
	ENOPROTOOPT,
	EPROTONOSUPPORT,
	ESOCKTNOSUPPORT,
	EOPNOTSUPP,
	EPFNOSUPPORT,
	EAFNOSUPPORT,
	EADDRINUSE,
	EADDRNOTAVAIL,
	ENETDOWN,
	ENETUNREACH,
	ENETRESET,
	ECONNABORTED,
	ECONNRESET,
	ENOBUFS,
	EISCONN,
	ENOTCONN,
	ESHUTDOWN,
	ETIMEDOUT,
	ECONNREFUSED,
	ELOOP,
	ENAMETOOLONG,
	EHOSTDOWN,
	EHOSTUNREACH,
	ENOTEMPTY,
	EPROCLIM,
	EUSERS,
	EDQUOT,
	ESTALE,
	EBADRPC,
	ERPCMISMATCH,
	EPROGUNAVAIL,
	EPROGMISMATCH,
	EPROCUNAVAIL,
	ENOLCK,
	ENOSYS,
	EFTYPE,
	EAUTH,
	ENEEDAUTH,
	EIDRM,
	ENOMSG,
	EOVERFLOW,
	ECANCELED,
	EILSEQ,			// C99 
	ENOATTR,
	EDOOFUS,
	EBADMSG,
	EMULTIHOP,
	ENOLINK,
	EPROTO,
	ENOTCAPABLE,
	ECAPMODE,
	ENOTRECOVERABLE,
	EOWNERDEAD,
}bsdErrno_t;

/***************** (END) BSD Type Defined Enumerators (END) **********************/

/***************** BSD Typedefs and Structures **********************/

typedef int socklen_t;

typedef uint16_t sa_family_t;

typedef uint32_t in_addr_t;

typedef uint16_t in_port_t;

struct bsd_in_addr{
	in_addr_t s_addr;
};

struct bsd_sockaddr{							/* Socket address structure */
	sa_family_t	sa_family;		/* address family */
	char		sa_data[14];	/* actually longer; address value */	
};

struct bsd_sockaddr_in{							/* Socket address internet style */
	sa_family_t	sin_family;
	in_port_t	sin_port;
	struct	bsd_in_addr sin_addr;
	char	sin_zero[8];
};

struct pollfd {
	 int	fd;	  /* file descriptor */
	 short	events;	  /* events to look for	*/
	 short	revents;  /* events returned */
};

/***************** (END) BSD Typedefs and Structures (END) **************************************/

/*********************** BSD Adapter Definitions ********************************/
/** \brief Function pointer for interaction between the WINC1500 BSD library  
 * and user application to transfer the information received over a socket to   
 * the application.
 **/
typedef void (*bsdRecvFuncPtr)(uint8_t *data, uint8_t length); 

// The call back table prototype for sending the packet received over a socket
// to the correct reception handler function defined in the user application.
// An instance of this table needs to be initialized by the user application to 
// to specify the recv callback function for each socket. 
typedef struct
{
   int8_t *socket;
   bsdRecvFuncPtr recvCallBack;
	socketState_t socketState;
} packetReceptionHandler_t;


/*********************** (END) BSD Adapter definitions (END) **************************/

/***************** BSD Public Functions **************************************/
void BSD_SetRecvHandlerTable(packetReceptionHandler_t *appRecvInfo);

packetReceptionHandler_t *BSD_GetRecvHandlerTable();

bsdErrno_t BSD_GetErrNo(void);

int BSD_socket(int domain, int type, int protocol);

int BSD_connect(int socket, const struct bsd_sockaddr *name, socklen_t namelen);

int BSD_send(int socket, const void *msg, size_t len, int flags);

int BSD_recv(int socket, const void *msg, size_t len, int flags);

int BSD_close(int socket);

uint32_t BSD_htonl(uint32_t hostlong);

uint16_t BSD_htons(uint16_t hostshort);

uint32_t BSD_ntohl(uint32_t netlong);

uint16_t BSD_ntohs(uint16_t netshort);

int BSD_bind(int socket, const struct bsd_sockaddr *addr, socklen_t addrlen);

int BSD_recvfrom(int socket, void *buf,	size_t len, int flags, struct bsd_sockaddr *from, socklen_t *fromlen);

int BSD_listen(int socket, int backlog);

int BSD_accept(int socket, struct bsd_sockaddr * addr, socklen_t * addrlen);

int BSD_getsockopt(int socket, int level, int optname, void * optval, socklen_t * optlen);

int BSD_setsockopt(int socket, int level, int optname, const void *optval, socklen_t optlen);

int BSD_write(int fd, const void *buf, size_t nbytes);

int BSD_read(int fd, void *buf, size_t nbytes);

int BSD_poll(struct pollfd *ufds, unsigned int nfds, int timeout);

int BSD_sendto(int socket, const void *msg, size_t len,	int flags, const struct bsd_sockaddr *to, socklen_t tolen);

void BSD_SocketHandler(int8_t sock, uint8_t msgType, void *pMsg);

// ToDo This is not a true BSD_poll(). The actual BSD_poll() requires a 
// structures and returns values which are not currently supported by WINC1500.
socketState_t BSD_GetSocketState(int sock);

/************ (END) BSD Public Functions (END) *********************************/

#endif	/* BSD_WINC */

