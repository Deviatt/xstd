#pragma once

#include <xstd/stdafx.h>

#ifdef _WIN32
	void (ExitProcess) 	(uint32_t);
	void (Sleep)		(uint32_t);

	#define XExit(code) do { \
			ExitProcess((code)); \
			XUNREACH(); \
		} while (0);

	#define XSleep(ms) (Sleep((ms)))
#else
	#include <xstd/System/SystemCall.h>

	#if defined(__linux__)
		#define XExit(code) do { \
			(void)syscall1(SYS_EXIT_GROUP, (code)); \
			XUNREACH(); \
		} while (0);

		struct __timespec {
			time_t 		sec;
			long_t 		nsec;
		};

		static XFINL void XSleep(uint32_t ms) {
			struct __timespec ts = {(time32_t)(ms / 1000), (time32_t)(ms % 1000) * 1000UL};
			syscall2(SYS_NANOSLEEP, &ts, NULL);
		}
	#endif
#endif