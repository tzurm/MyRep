#ifndef __ATOI__
#define __ATOI__

#include <stdio.h>		/* printf */
#include <stdlib.h>		/* sprintf */
#include <string.h>		/* strcpy */
#define	CHECK_ENDIAN(c)	(0 == *c ) ? \
	printf("Big endian\n") : printf("Little endian\n")



void CheckAtoi(char **str, int n);

void CheckItoa(int num , char *buffer, int base);

int Atoi(char* str);

char *Itoa(int num, char *buffer, int base);

void CheckEndian(char *c);

void IsChInArr(char *arr1, char *arr2, char *arr3, int len1, int len2, int len3);


#endif
