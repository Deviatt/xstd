#pragma once

#include <xstd/stdlib.h>

typedef uint8_t 	bitmap8_t;
typedef uint16_t 	bitmap16_t;
typedef uint32_t 	bitmap32_t;
typedef uint64_t 	bitmap64_t;

typedef bitmap8_t 	bitmap_t;

#define XBITALIGN(bits)		((size_t)(((bits) + 7) & -8ULL))
#define XBITS2OCTETS(bits)	(XBITALIGN((bits)) >> 3)

#define XBitMapInit(bitmap, def, size) do { \
	if (XLIKE((bitmap))) \
		memset((ptr_t)(bitmap), (def) ? 0xFF : 0x00, XBITS2OCTETS((size))); \
} while (0)

#define XBitMapSet(bitmap, idx, set) do { \
	if (XLIKE((bitmap))) \
		((bitmap_t*)(bitmap))[idx ? XBITS2OCTETS(idx) - 1 : 0] ^= (-(!!(set)) ^ ((bitmap_t*)(bitmap))[idx ? XBITS2OCTETS(idx) - 1 : 0]) & (1 << ((idx) & 0x7)); \
} while (0)
#define XBitMapGet(bitmap, idx) \
	(((bitmap_t*)(bitmap))[idx ? XBITS2OCTETS(idx) - 1 : 0] & (1 << ((idx) & 0x7)))