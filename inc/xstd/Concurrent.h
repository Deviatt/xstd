#pragma once

#include <xstd/Atomic.h>

/* Spinlock */
typedef bool_t spinlock_t;

#ifdef __ARCH_x86__
	#define __ASM_PAUSE	__asm__ __volatile__("pause")
#else
	#define __ASM_PAUSE
#endif

#define XSpinLock(spin)		do { \
	while (XAtomicSet((spin))) \
		__ASM_PAUSE; \
} while (0)
#define XSpinUnlock(spin)	XAtomicReset((spin))

/* Readers-Writer Lock */
typedef uint8_t rwlock_t;

#define XRWAcquireReader(rwl)
#define XRWReleaseReader(rwl)

#define XRWAcquireWriter(rwl)
#define XRWReleaseWriter(rwl)

/* Semaphore */
typedef uint16_t sem_t, semaphore_t;

#define XSemAcquire(sem)
#define XSemRelease(sem)