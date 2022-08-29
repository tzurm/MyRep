#ifndef __STRING_H__
#define __STRING_H__

#include <stdio.h>
#include <stdlib.h>

#include <strings.h>
#include <string.h>

#include <assert.h>
#include <ctype.h>


int StrLen(const char *str);

int StrCmp(const char* str1, const char* str2);

int StrNCmp( char* str1,  char* str2, int max);

int StrCaseCmp( char* str1,  char* str2);

char *StrCpy( char *dest, char* src);

char *StrNCpy( char* dest, char* src, int length);

char *StrChr(const char *str1, int ch);

char *StrCat(char *dest, char *src);

const char* StrStr(const char* str1, const char* str2);

void reverseString(char* str);

/*
void isPalindrome(char *string);
*/
#endif
