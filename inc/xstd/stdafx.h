#pragma once

/* determine arch */
#if defined(__x86_64__) || defined(__x86_64) || defined(__amd64__) || defined(__amd64) || defined(_M_X64) || defined(_M_IX64) || defined(_M_AMD64)
	#define __ARCH_x86__
	#define __ARCH_x64__
#elif defined(i386) || defined(__i386) || defined(__i386__) || defined(__i486__) || defined(__i586__) || defined(__i686__) || defined(__IA32__) || defined(_M_IX86) || defined(__X86__) || defined(_X86_) || defined(__THW_INTEL__) || defined(__I86__) || defined(__INTEL__) || defined(__386)
	#define __ARCH_x86__
	#define __ARCH_x32__
#elif defined(__aarch64__) || defined(_M_ARM64)
	#define __ARCH_ARM__
	#define __ARCH_ARM64__
#elif defined(__arm__) || defined(__thumb__) || defined(__TARGET_ARCH_ARM) || defined(__TARGET_ARCH_THUMB) || defined(__ARM) || defined(_M_ARM) || defined(_M_ARM_T) || defined(__ARM_ARCH)
	#define __ARCH_ARM__
	#define __ARCH_ARM32__
#elif defined(mips) || defined(__mips__) || defined(__mips)
	#define __ARCH_MIPS__
#elif defined(__PPC64__) || defined(__ppc64__) || defined(_ARCH_PPC64)
	#define __ARCH_PPC__
	#define __ARCH_PPC64__
#elif defined(__powerpc) || defined(__powerpc__) || defined(__powerpc64__) || defined(__POWERPC__) || defined(__ppc__) || defined(__PPC__) || defined(_ARCH_PPC)
	#define __ARCH_PPC__
	#define __ARCH_PPC32__
#elif defined(__sparc__) || defined(__sparc)
	#define __ARCH_SPARC__
#endif

/* determine standard */
#if defined(__STDC__) && defined(__STDC_VERSION__)
	#if __STDC_VERSION__ >= 202311L
		#define __STDC23__
	#endif

	#if __STDC_VERSION__ >= 201710L
		#define __STDC17__
	#endif

	#if __STDC_VERSION__ >= 201112L
		#define __STDC11__
	#endif
		
	#if __STDC_VERSION__ >= 199901L
		#define __STDC99__
	#endif

	#if __STDC_VERSION__ >= 199409L
		#define __STDC89__
	#endif
#endif

#if defined(__GNUC__) && defined(__GNUC_MINOR__)
	#define __GNUC_PREREQ(maj, min)		((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min))
#else
	#define __GNUC_PREREQ(maj, min)		(0)
#endif

#if defined(__clang_major__) || defined(__clang_minor__)
	#define __CLANG_PREREQ(maj, min)	((__clang_major__ << 16) + __clang_minor__ >= ((maj) << 16) + (min))
#else
	#define __CLANG_PREREQ(maj, min)	(0)
#endif

#if defined(_MSC_VER)
	#if _MSC_VER >= 1400
		#define __MSVC_PREREQ(maj, min)	(_MSC_FULL_VER >= (maj * 10000000 + min * 100000))
	#elif _MSC_VER >= 1200
		#define __MSVC_PREREQ(maj, min)	(_MSC_FULL_VER >= (maj * 1000000 + min * 10000))
	#else
		#define __MSVC_PREREQ(maj, min)	(_MSC_VER >= (maj * 100 + min))
	#endif
#else
	#define __MSVC_PREREQ(maj, min)		(0)
#endif

/* determine wordsize */
#if (defined(__ARCH_X64__) || defined(__ARCH_ARM64__) || defined(__ARCH_PPC64__)) && !defined(__ILP32__)
	#define __WORDSIZE (64)
#else
	#define __WORDSIZE (32)
#endif

/* determine types */
#if __GNUC_PREREQ(5, 1) || defined(__clang__)
	typedef __INT8_TYPE__ 		char_t;
	typedef __UINT8_TYPE__ 		uchar_t;

	typedef __INT16_TYPE__ 		short_t;
	typedef __UINT16_TYPE__ 	ushort_t;

	typedef __INT32_TYPE__		int_t;
	typedef __UINT32_TYPE__		uint_t;

	typedef __INT64_TYPE__ 		long_t;
	typedef __UINT64_TYPE__		ulong_t;

	typedef __SIZE_TYPE__ 		size_t;
	typedef __PTRDIFF_TYPE__ 	ptrdiff_t;

	typedef __INTPTR_TYPE__ 	intptr_t;
	typedef __UINTPTR_TYPE__	uintptr_t;

	typedef long_t 				int64_t;
	typedef ulong_t 			uint64_t;
#else
	typedef signed 		char 	char_t;
	typedef unsigned 	char 	uchar_t;

	typedef signed 		short 	short_t;
	typedef unsigned 	short 	ushort_t;

	typedef signed 		int 	int_t;
	typedef unsigned 	int 	uint_t;

	typedef signed 		long 	long_t;
	typedef unsigned 	long 	ulong_t;

	#if __WORDSIZE == 64
		typedef long_t 		int64_t;
		typedef ulong_t 	uint64_t;

		typedef long_t 		intptr_t;
		typedef ulong_t 	uintptr_t;

		typedef ulong_t 	size_t;
	#else
		#ifdef __STDC99__
			typedef signed 		long long 	int64_t;
			typedef unsigned 	long long 	uint64_t;
		#else
			typedef long_t 	int64_t;
			typedef ulong_t uint64_t;
		#endif

		typedef int64_t 	intptr_t;
		typedef uint64_t 	uintptr_t;

		typedef uint64_t 	size_t;
		typedef size_t 		ptrdiff_t;
	#endif
#endif

typedef char_t 			int8_t;
typedef uchar_t 		uint8_t;
	
typedef short_t 		int16_t;
typedef ushort_t 		uint16_t;
	
typedef int_t 			int32_t;
typedef uint_t 			uint32_t;

typedef void* 			ptr_t;
typedef char_t* 		caddr_t;

typedef caddr_t 		str_t;
typedef const char_t*	cstr_t;

/* os specific types */
typedef uint32_t 		pid_t;
typedef size_t 			dev_t;

typedef uint32_t 		time32_t;
typedef uint64_t 		time64_t, time_t;

/* aux */
#ifdef __cplusplus
	#define NULL (nullptr)

	typedef bool bool_t;

	#define XINL inline
#else
	#define NULL 	((ptr_t)0)

	#define true 	((bool_t)1)
	#define false 	((bool_t)0)

	#ifdef __STDC99__
		typedef _Bool 	bool_t;
	#else
		typedef char_t 	bool_t;
	#endif

	#ifdef __STDC99__
		#define XINL 		inline
	#else
		#if __GNUC_PREREQ(4, 3) || defined(__clang__)
			#define XINL 	__inline__
		#elif __MSVC_PREREQ(12, 0)
			#define XINL 	__inline
		#else
			#define XINL
		#endif

		#define inline 	XINL
	#endif
#endif

#if __GNUC_PREREQ(4, 3) || defined(__clang__)
	#define XFINL __attribute__((always_inline)) XINL
#elif defined(_MSC_VER)
	#define XFINL __forceinline
#else
	#define XFINL XINL
#endif

#if __GNUC_PREREQ(3, 0) || defined(__clang__)
	#define XLIKE(expr) 		(__builtin_expect(!!(expr), 1))
	#define XUNLIKE(expr)		(__builtin_expect(!!(expr), 0))
#else
	#define XLIKE(expr)			(!!(expr))
	#define XUNLIKE(expr)		(!!(expr))
#endif

#if __GNUC_PREREQ(4, 5) || defined(__clang__)
	#define XUNREACH() (__builtin_unreachable())
#elif defined(_MSC_VER)
	#define XUNREACH() (__assume(false))
#else
	#define XUNREACH()
#endif

#if __CLANG_PREREQ(3, 5)
	#define XASSUME(condition) (__builtin_assume((condition)))
#elif __GNUC_PREREQ(4, 5)
	#define XASSUME(condition) do { \
		if ((condition)) \
			XUNREACH(); \
	} while (0)
#elif defined(_MSC_VER)
	#define XASSUME(condition) 	(__assume((condition)))
#else
	#define XASSUME(condition)	()
#endif

#if defined(__STDC11__) || __GNUC_PREREQ(4, 6) || defined(__clang__)
	#define XASSERT(expr, str)	_Static_assert((expr), str)
#else
	#define XASSERT(expr, str)	()
#endif

#ifdef __STDC11__
	#define XNORET _Noreturn
#elif __GNUC_PREREQ(2, 5) || __CLANG_PREREQ(3, 3)
	#define XNORET __attribute__((noreturn))
#elif __MSVC_PREREQ(13, 10)
	#define XNORET __declspec(noreturn)
#else
	#define XNORET
#endif

#if __GNUC_PREREQ(2, 96) || defined(__clang__)
	#define XPURE __attribute__((pure))
#else
	#define XPURE
#endif

#if __GNUC_PREREQ(2, 5) || defined(__clang__)
	#define XCONST __attribute__((const))
#else
	#define XCONST
#endif

#ifdef __STDC99__
	#define XRESTRICT restrict
#elif __GNUC_PREREQ(3, 1) || defined(__clang__)
	#define XRESTRICT __restrict__
#elif __MSVC_PREREQ(14, 0)
	#define XRESTRICT __declspec(restrict)
#else
	#define XRESTRICT
#endif

#define XUNIQUEPTR(type)	type *XRESTRICT

#if __GNUC_PREREQ(3, 1) || defined(__clang__)
	#define XOFFSET(type, fld) 	(__builtin_offsetof(type, fld))
#else
	#define XOFFSET(type, fld)	((size_t)&(((type*)NULL)->fld))
#endif