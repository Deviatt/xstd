#include <xstd/Socket.h>
#include <xstd/Process.h>

XNORET void _start(void) {
	sock_t sock;
	if (XSocketInit(&sock, AF_INET, SOCK_STREAM, 0)) {
		XSocketBind(sock, NULL, 0);
		XSocketListen(sock, 8);

		XSleep(5000);
	}

	XExit(0);
}