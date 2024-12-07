#pragma once

#include <xstd/stdafx.h>

#ifdef _WIN32
	typedef dev_t heap_t;

	heap_t		(HeapCreate)	(uint32_t, size_t, size_t);
	bool_t 		(HeapDestroy)	(heap_t);

	ptr_t		(HeapAlloc)		(heap_t, uint32_t, size_t);
	bool_t 		(HeapFree)		(heap_t, uint32_t, ptr_t);

	#define XHeapInit(heap, init, max)	do { \
		if (XLIKE((heap))) \
			*(heap_t*)(heap) = XHeapCreate((init), (max)); \
	} while (0)
	#define XHeapCreate(init, max)		(HeapCreate(0x0, (size_t)(init), (size_t)(max)))
	#define XHeapDestroy(heap)			(HeapDestroy(*(heap_t*)(heap)))

	#define XHeapAlloc(heap, size)		(HeapAlloc(*(heap_t*)(heap), 0x0, (size_t)(size)))
	#define XHeapFree(heap, ptr)		((void)HeapFree(*(heap_t*)(heap), 0x0, (size_t)(size)))
#else
	/* TODO: Implement */
#endif