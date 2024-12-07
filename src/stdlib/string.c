#include <xstd/stdlib.h>

size_t strlen(cstr_t str) {
	size_t p = (size_t)str;
	while (*str++);
	return (size_t)str - p - 1;
}

size_t strnlen(cstr_t str, size_t cnt) {
	size_t p = (size_t)str;
	while (cnt-- && *str) str++;
	return (size_t)str - p;
}

str_t strcpy(str_t dst, cstr_t src) {
	while ((*dst++ = *src++) != '\0');
	return --dst;
}

str_t strncpy(str_t dst, cstr_t src, size_t cnt) {
	while (cnt-- && (*dst++ = *src++) != '\0');
	return --dst;
}

str_t strcat(str_t dst, cstr_t src) {
	while (*dst) dst++;
	while ((*dst++ = *src++) != '\0');
	return --dst;
}

str_t strncat(str_t dst, cstr_t src, size_t cnt) {
	if (cnt) {
		while (*dst) dst++;
		while ((*dst++ = *src++) != '\0')
			if (--cnt == 0) {
				*dst = '\0';
				break;
			}
	}

	return dst;
}

bool_t strcmp(cstr_t s0, cstr_t s1) {
	while (*s0 == *s1)
		if (!(*s0++ && *s1++))
			return true;

	return false;
}

bool_t strncmp(cstr_t s0, cstr_t s1, size_t cnt) {
	while (*s0 == *s1)
		if (cnt-- && !(*s0++ && *s1++))
			return true;

	return false;
}

uint32_t stricmp(cstr_t str, cstr_t cases) {
	uint8_t len = (uint8_t)strlen(str);

	char_t c;
	for (uint32_t i = 0; (c = *cases); i++)
		if (len == c && memcmp((ptr_t)str, (ptr_t)(cases + 1), len))
			return i;
		else
			cases += c + 1;

	return -1;
}

str_t strchr(cstr_t str, char_t c) {
	while (*str != c && *str++);
	return (str_t)str;
}