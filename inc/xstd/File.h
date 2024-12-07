#pragma once

#include <xstd/stdafx.h>

#ifdef _WIN32
	#define XSTDIN 	((dev_t)(0x100000000U - 10))
	#define XSTDOUT ((dev_t)(0x100000000U - 11))
	#define XSTDERR ((dev_t)(0x100000000U - 12))

	dev_t 		(CreateFileA)	(str_t, uint32_t, uint32_t, ptr_t, uint32_t, uint32_t, dev_t);
	bool_t		(ReadFile)		(dev_t, ptr_t, uint32_t, uint32_t*, ptr_t);
	bool_t		(WriteFile)		(dev_t, ptr_t, uint32_t, uint32_t*, ptr_t);
	bool_t 		(CloseHandle)	(dev_t);

	/* Access Flags */
	#define XFILE_ACCESS_RD 		(0x80000000)
	#define XFILE_ACCESS_WR 		(0x40000000)
	#define XFILE_ACCESS_RDWR		(XFILE_ACCESS_RD | XFILE_ACCESS_WR)
	#define XFILE_ACCESS_EXEC		(0x20000000)
	#define XFILE_ACCESS_ALL		(0x10000000)

	/* Aux Flags */
	#define XFILE_BUFFER_RD			(0x80000000)
	#define XFILE_BUFFER_NO			(0x20000000)

	/* Mode */
	#define XFILE_MODE_CREATE		(0x4)
	#define XFILE_MODE_EXCL			(0x1)
	#define XFILE_MODE_TRUNC		(XFILE_MODE_CREATE | XFILE_MODE_EXCL)

	#define XFileOpen(fp, flags, mode)		(CreateFileA((fp), (flags), 0x0, NULL, (mode) ?: 0x3, 0x80, (dev_t)NULL))
	#define XFileClose(fd) 					(CloseHandle((fd)))

	#define XFileRead(fd, buf, cnt, cnto) 	((void)ReadFile((fd), (buf), (cnt), (uint32_t*)(cnto), NULL))
	#define XFileWrite(fd, buf, cnt, cnto)	((void)WriteFile((fd), (buf), (cnt), (uint32_t*)(cnto), NULL))
#else
	#include <xstd/System/SystemCall.h>

	#define XSTDIN	((dev_t)(0x0))
	#define XSTDOUT	((dev_t)(0x1))
	#define XSTDERR	((dev_t)(0x2))

	/* Access Flags */
	#define XFILE_ACCESS_RD 		(0x0)
	#define XFILE_ACCESS_WR 		(0x1)
	#define XFILE_ACCESS_RDWR		(0x2)
	#define XFILE_ACCESS_EXEC		(0x0)
	#define XFILE_ACCESS_ALL		(XFILE_ACCESS_RDWR)

	/* Aux Flags */
	#define XFILE_BUFFER_RD			(0x0)
	#define XFILE_BUFFER_NO			(0x0)

	/* Mode */
	#define XFILE_MODE_CREATE		(0x40)
	#define XFILE_MODE_EXCL			(0x128)
	#define XFILE_MODE_TRUNC		(0x400)

	#define XFileOpen(fp, flags, mode)		((dev_t)syscall3(SYS_OPEN, (fp), (flags) | (mode), 0666))
	#define XFileClose(fd)					(syscall1(SYS_CLOSE, (fd)))

	#define XFileRead(fd, buf, cnt, cnto) do { \
		size_t __ret = (size_t)syscall3(SYS_READ, (fd), (buf), (cnt)); \
		size_t *out = (size_t*)(cnto); \
		if (__ret && out) \
			*out = __ret; \
	} while (0)

	#define XFileWrite(fd, buf, cnt, cnto) do { \
		size_t __ret = (size_t)syscall3(SYS_WRITE, (fd), (buf), (cnt)); \
		size_t *out = (size_t*)(cnto); \
		if (__ret && out) \
			*out = __ret; \
	} while (0)
#endif