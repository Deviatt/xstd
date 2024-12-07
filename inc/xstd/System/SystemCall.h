#pragma once

#define SYS(name) SYS_##name,

#if defined(__ARCH_x64__)
	#include "x64/SystemCall.h"
#elif defined(__ARCH_x32__)
	#include "x86/SystemCall.h"
#elif defined(__ARCH_ARM64__)
	#include "ARM64/SystemCall.h"
#elif defined(__ARCH_ARM32__)
	#include "ARM/SystemCall.h"
#elif defined(__ARCH_MIPS__)
	#include "MIPS/SystemCall.h"
#elif defined(__ARCH_PPC__)
	#include "PPC/SystemCall.h"
#elif defined(__ARCH_SPARC__)
	#include "SPARC/SystemCall.h"
#endif

#undef SYS

#define syscall0(n)						(__syscall0((uint32_t)(n)))
#define syscall1(n, x)					(__syscall1((uint32_t)(n), (intptr_t)(x)))
#define syscall2(n, x, y)				(__syscall2((uint32_t)(n), (intptr_t)(x), (intptr_t)(y)))
#define syscall3(n, x, y, z)			(__syscall3((uint32_t)(n), (intptr_t)(x), (intptr_t)(y), (intptr_t)(z)))
#define syscall4(n, x, y, z, w)			(__syscall4((uint32_t)(n), (intptr_t)(x), (intptr_t)(y), (intptr_t)(z), (intptr_t)(w)))
#define syscall5(n, x, y, z, w, u)		(__syscall5((uint32_t)(n), (intptr_t)(x), (intptr_t)(y), (intptr_t)(z), (intptr_t)(w), (intptr_t)(u)))
#define syscall6(n, x, y, z, w, u, v)	(__syscall6((uint32_t)(n), (intptr_t)(x), (intptr_t)(y), (intptr_t)(z), (intptr_t)(w), (intptr_t)(u), (intptr_t)(v)))