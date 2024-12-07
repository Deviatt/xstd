#pragma once

#include <xstd/stdafx.h>

#ifdef __GNUC__
	#define XAtomicLoad(x)			(__atomic_load_n((x), 0))
	#define XAtomicLoadEx(x, ptr)	(__atomic_load((x), (ptr), 0))
	#define XAtomicStore(x, val)	(__atomic_store_n((x), (val), 0))
	#define XAtomicStoreEx(x, ptr)	(__atomic_store((x), (ptr), 0))

	#define XAtomicSet(x)			(__atomic_test_and_set((bool_t*)(x), 0))
	#define XAtomicReset(x)			(__atomic_clear((bool_t*)(x), 0))

	#define XAtomicAdd(x, y)		(__atomic_add_fetch((x), (y), 0))
	#define XAtomicSub(x, y)		(__atomic_sub_fetch((x), (y), 0))

	#define XAtomicAND(x, y)		(__atomic_and_fetch((x), (y), 0))
	#define XAtomicOR(x, y)			(__atomic_or_fetch((x), (y), 0))
	#define XAtomicXOR(x, y)		(__atomic_xor_fetch((x), (y), 0))
	#define XAtomicNAND(x, y)		(__atomic_nand_fetch((x), (y), 0))
#else
	#define XAtomicLoad(x)
	#define XAtomicLoadEx(x, ptr)
	#define XAtomicStore(x, val)
	#define XAtomicStoreEx(x, ptr)

	#define XAtomicSet(x)
	#define XAtomicReset(x)

	#define XAtomicAdd(x, y)
	#define XAtomicSub(x, y)

	#define XAtomicAnd(x, y)
	#define XAtomicOR(x, y)
	#define XAtomicXOR(x, y)
	#define XAtomicNAND(x, y)

	#warning "Atomic NYI!"
#endif