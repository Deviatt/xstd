#pragma once

#include <xstd/stdafx.h>

void		(memset)	(ptr_t, uint8_t, size_t);
void 		(memcpy) 	(ptr_t, ptr_t, size_t);
bool_t 		(memcmp)	(ptr_t, ptr_t, size_t);
ptr_t 		(memchr)	(ptr_t, uint8_t, size_t);

size_t 		(strlen) 	(cstr_t);
size_t 		(strnlen) 	(cstr_t, size_t);
str_t 		(strcpy) 	(str_t, cstr_t);
str_t 		(strncpy)	(str_t, cstr_t, size_t);
str_t 		(strcat)	(str_t, cstr_t);
str_t 		(strncat)	(str_t, cstr_t, size_t);
bool_t 		(strcmp) 	(cstr_t, cstr_t);
bool_t 		(strncmp)	(cstr_t, cstr_t, size_t);
uint32_t 	(stricmp) 	(cstr_t, cstr_t);
str_t 		(strchr)	(cstr_t, char_t);