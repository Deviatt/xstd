#pragma once

#include <xstd/stdafx.h>

typedef dev_t socket_t, sock_t;
typedef uint32_t socklen_t;

typedef struct {
	uint16_t	family;
	char_t		data[/* 14 */];
} sockaddr_t;

typedef struct {
	uint16_t	family;
	uint16_t	port;
	uint32_t	addr;
} sockaddr_srv_t, sockaddr_srv4_t;

typedef struct {
	uint16_t 	family;
	uint16_t	port;
	uint32_t	flow;
	union {
		uint8_t		addr[16];
		uint16_t	words[8];
		uint32_t	dwords[4];
		uint64_t	qwords[2];
	};
	uint32_t	scope;
} sockaddr_srv6_t;

/* Address Families */
enum {
	/* Supported address families */
	AF_UNSPEC,	AF_UNIX,		AF_INET,	AF_AX25,	AF_IPX,			AF_APPLETALK,	AF_NETROM,		AF_BRIDGE,	AF_ATMPVC,	AF_X25,
	AF_INET6,	AF_ROSE,		AF_DECNET,	AF_NETBEUI,	AF_SECURITY,	AF_KEY,			AF_NETLINK,		AF_PACKET,	AF_ASH,		AF_ECONET,
	AF_ATMSVC,	AF_RDS,			AF_SNA,		AF_IRDA,	AF_PPPOX,		AF_WANPIPE,		AF_LLC,			AF_IB,		AF_MPLS,	AF_CAN,
	AF_TIPC,	AF_BLUETOOTH,	AF_IUCV,	AF_RXRPC,	AF_ISDN,		AF_PHONET,		AF_IEEE802154,	AF_CAIF,	AF_ALG,		AF_NFC,
	AF_VSOCK,	AF_KCM,			AF_QIPCRTR,	AF_SMC,		AF_XDP,			AF_MCTP,
	/* Specific address families */
	AF_LOCAL = AF_UNIX, AF_ROUTE = AF_NETLINK
};

/* Socket types */
enum {
	/* Connection-based */
	/*
		* AF_IPX		->	IPX
		* AF_INET		->	TCP
		* AF_INET6		->	TCP
		* AF_APPLETALK	->	ADSP
		* AF_BLUETOOTH	->	RFCOMM
		* AF_IRDA		->	IrTTP
	*/
	SOCK_STREAM 	= 0x1,
	/* Datagram-based */
	/*
		* AF_IPX		->	SPX
		* AF_INET		->	UDP
		* AF_INET6		->	UDP
		* AF_APPLETALK	->	DDP
		* AF_BLUETOOTH	->	L2CAP (?)
		* AF_IRDA		->	IrLMP
	*/
	SOCK_DGRAM 		= 0x2,
	/* Raw */
	/*
		* AF_INET		->	IP
		* AF_INET6		->	IP6
	*/
	SOCK_RAW 		= 0x3,
	/* Reliably-Delivered Message */
	/*
		* AF_INET		->	RUDP/PGM (?)
		* AF_INET6		->	RUDP/PGM (?)
	*/
	SOCK_RDM		= 0x4,
	/* Sequenced, reliable and unduplicated packets */
	/* Not supported on Windows! */
	/*
		* AF_INET		->	SCTP
		* AF_INET6		->	SCTP
	*/
	SOCK_SEQPACKET	= 0x5,
	/* Only supported on Linux! */
	SOCK_DCCP		= 0x6,
	SOCK_PACKET		= 0xA
};

enum {
	/* Dummy protocol for TCP */		/* Internet Control	Message	*/		/* Internet Group Management */		/* IPI tunnels */
	IPPROTO_IP 			= 0x000,		IPPROTO_ICMP		= 0x001,		IPPROTO_IGMP		= 0x002,		IPPROTO_IPIP		= 0x004,
	/* Transmission Control */			/* Exterior Gateway Protocol */		/* PARC Universal Protocol */		/* User Datagram Protocol */
	IPPROTO_TCP			= 0x006,		IPPROTO_EGP			= 0x008,		IPPROTO_PUP			= 0x00C,		IPPROTO_UDP			= 0x011,
	/* XNS Internet Datagram */			/* ISO-TP */						/* Datagram Congestion Control */	/* IPv6-in-IPv4 tunnels */
	IPPROTO_IDP			= 0x016,		IPPROTO_TP			= 0x01D,		IPPROTO_DCCP		= 0x021,		IPPROTO_IPV6		= 0x029,
	/* Resource ReserVation */			/* Cisco GRE tunnels */				/* Encapsulation Security Payload *//* Authentication Header */
	IPPROTO_RSVP		= 0x02E,		IPPROTO_GRE			= 0x02F,		IPPROTO_ESP			= 0x032,		IPPROTO_AH			= 0x033,
	/* Multicast Transport Protocol */	/* IP header for BEET */			/* Encapsulation header */			/* Protocol Independent Multicast */
	IPPROTO_MTP			= 0x05C,		IPPROTO_BEETPH		= 0x05E,		IPPROTO_ENCAP		= 0x062,		IPPROTO_PIM			= 0x067,
	/* Compression Header Protocol */	/* Layer 2 Tunneling Protocol */	/* Stream Control Transport */		/* UDP-Lite (RFC 3828) */
	IPPROTO_COMP		= 0x06C,		IPPROTO_L2TP		= 0x073,		IPPROTO_SCTP		= 0x084,		IPPROTO_UDPLITE 	= 0x088,
	/* MultiProtocol Label Switching */	/* Ethernet-within-IPv6 Encap */	/* Raw IP packets */				/* Shared Memory Communications */
	IPPROTO_MPLS		= 0x089,		IPPROTO_ETHERNET	= 0x08F,		IPPROTO_RAW			= 0x0FF,		IPPROTO_SMC 		= 0x100,
	/* Multipath TCP */
	IPPROTO_MPTCP 		= 0x106
};

#if defined(_WIN32)
	/* TODO: Implement */
#else
	#include <xstd/System/SystemCall.h>

	static XFINL sock_t XSocketCreate(uint32_t domain, uint32_t type, uint32_t protocol) {
		return (sock_t)syscall3(SYS_SOCKET, domain, type, protocol);
	}

	static XFINL bool_t XSocketInit(sock_t *dstsock, uint32_t domain, uint32_t type, uint32_t protocol) {
		sock_t sock = XSocketCreate(domain, type, protocol);
		if (sock != -1ULL) {
			*dstsock = sock;
			return true;
		}

		return false;
	}

	static XFINL bool_t XSocketBind(sock_t sock, sockaddr_t *addr, socklen_t addrlen) {
		return (bool_t)((uint32_t)syscall3(SYS_BIND, sock, addr, addrlen) == 0);
	}

	static XFINL bool_t XSocketListen(sock_t sock, uint32_t backlog) {
		return (bool_t)((uint32_t)syscall2(SYS_LISTEN, sock, backlog) == 0);
	}

	static XFINL bool_t XSocketConnect(sock_t sock, sockaddr_t *addr, socklen_t addrlen) {
		return (bool_t)((uint32_t)syscall3(SYS_CONNECT, sock, addr, addrlen) == 0);
	}

	static XFINL bool_t XSocketAccept(sock_t *dstsock, sock_t sock, sockaddr_t *addr, socklen_t *addrlen) {
		sock_t acsock = (sock_t)syscall3(SYS_ACCEPT, sock, addr, addrlen);
		if (acsock != -1ULL) {
			*dstsock = acsock;
			return true;
		}

		return false;
	}

	static XFINL bool_t XSocketSend(sock_t sock, ptr_t buf, size_t len, uint32_t flags, size_t *out) {
		size_t sent = (size_t)syscall6(SYS_SENDTO, sock, buf, len, flags, NULL, 0);
		if (sent != -1ULL) {
			if (out)
				*out = sent;

			return true;
		}

		return false;
	}

	static XFINL bool_t XSocketSendTo(sock_t sock, ptr_t buf, size_t len, uint32_t flags, sockaddr_t *dstaddr, socklen_t addrlen, size_t *out) {
		size_t sent = (size_t)syscall6(SYS_SENDTO, sock, buf, len, flags, dstaddr, addrlen);
		if (sent != -1ULL) {
			if (out)
				*out = sent;

			return true;
		}

		return false;
	}

	static XFINL bool_t XSocketRead(sock_t sock, ptr_t buf, size_t len, uint32_t flags, size_t *out) {
		size_t recv = (size_t)syscall6(SYS_RECVFROM, sock, buf, len, flags, NULL, NULL);
		if (recv != -1ULL) {
			if (out)
				*out = recv;

			return true;
		}

		return false;
	}

	static XFINL bool_t XSocketReadFrom(sock_t sock, ptr_t buf, size_t len, uint32_t flags, sockaddr_t *srcaddr, socklen_t *addrlen, size_t *out) {
		size_t recv = (size_t)syscall6(SYS_RECVFROM, sock, buf, len, flags, srcaddr, addrlen);
		if (recv != -1ULL) {
			if (out)
				*out = recv;

			return true;
		}

		return false;
	}

	static XFINL bool_t XSocketClose(sock_t sock) {
		return (bool_t)((uint32_t)syscall1(SYS_CLOSE, sock) == 0);
	}

	static XFINL bool_t XSocketGetName(sock_t sock, sockaddr_t *addr, socklen_t *addrlen) {
		return (bool_t)((uint32_t)syscall3(SYS_GETSOCKNAME, sock, addr, addrlen) == 0);
	}

	static XFINL bool_t XSocketGetPeerName(sock_t sock, sockaddr_t *addr, socklen_t *addrlen) {
		return (bool_t)((uint32_t)syscall3(SYS_GETPEERNAME, sock, addr, addrlen) == 0);
	}

	static XFINL bool_t XSocketSetOption(sock_t sock, uint32_t lvl, uint32_t opt, ptr_t val, size_t len) {
		return (bool_t)((uint32_t)syscall5(SYS_SETSOCKOPT, sock, lvl, opt, val, len) == 0);
	}

	static XFINL bool_t XSocketGetOption(sock_t sock, uint32_t lvl, uint32_t opt, ptr_t val, size_t *len) {
		return (bool_t)((uint32_t)syscall5(SYS_GETSOCKOPT, sock, lvl, opt, val, len) == 0);
	}
#endif