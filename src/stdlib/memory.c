#include <xstd/stdlib.h>

void memset(ptr_t ptr, uint8_t c, size_t cnt) {
	while (cnt--)
		*((caddr_t)ptr + cnt) = c;
}

void memcpy(ptr_t dst, ptr_t src, size_t cnt) {
	while (cnt--)
		*((caddr_t)dst++) = *((caddr_t)src++);
}

bool_t memcmp(ptr_t p0, ptr_t p1, size_t cnt) {
	while (cnt--)
		if (*((caddr_t)p0++) != *((caddr_t)p1++))
			return false;

	return true;
}

ptr_t memchr(ptr_t ptr, uint8_t c, size_t cnt) {
	if (cnt) {
		register uint8_t *cp = (uint8_t*)ptr;
		do {
			if (*cp++ == c)
				return (ptr_t)--cp;
		} while (--cnt);
	}

	return ptr;
}