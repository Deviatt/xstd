#pragma once

#include <xstd/stdafx.h>

#ifdef _WIN32
	void (ExitProcess) 	(uint32_t);
	#define XExit(code) do { \
			ExitProcess((code)); \
			XUNREACH(); \
		} while (0);
#else
	#include <xstd/System/SystemCall.h>

	#if defined(__linux__)
		#define XExit(code) do { \
			(void)syscall1(SYS_EXIT_GROUP, (code)); \
			XUNREACH(); \
		} while (0);
	#endif
#endif