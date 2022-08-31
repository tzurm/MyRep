#ifndef __STRING_H__
#define __STRING_H__

#include <stdio.h>		/* use for  printf */
#include <stdlib.h>		/* use for  malloc */
#include <stddef.h>		/* use for  size t */
#include <string.h>		/* string lib */
#include <ctype.h>		/* use for tolower */


size_t StrLen(const char *str);

int StrCmp(const char* str1, const char* str2);

int StrNCmp(const char* str1,const char* str2, size_t max);

int StrCaseCmp (char *str1, char *str2);

char *StrCpy( char *dest, char* src);

char *StrNCpy( char *dest, char *src, size_t length);

char *StrChr(const char *str1, int ch);

char *StrDup(const char *src);

char *StrCat(char *dest, const char *src);

char *StrNCat(char *dest, const char *src, size_t n);

char *StrStr(const char *str1, const char *str2);

size_t StrSpn(const char *str1, const char *str2);

void IsPalindrome(char *str1);

#endif
