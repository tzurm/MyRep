#ifndef __ARRAY_POINTER_H__
#define __ARRAY_POINTER_H__

#include <stdio.h>		/* use for  printf */
#include <stdlib.h>		/* use for  malloc */
#include <stddef.h>		/* use for  size t */
#include <string.h>		/* string lib */
#include <ctype.h>		/* use for tolower */


void PrintDataTypes();

size_t Yosefr(size_t n);

size_t Yosef(size_t n , size_t *p);

void Print2d(int arr[2][4], int i, int j);

void SumRows(int arr[2][4], int i, int j);

char *ToLow(char *src);

void PrintEnv();

#endif
