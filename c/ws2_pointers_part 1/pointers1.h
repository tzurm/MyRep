#ifndef __POINTERS1_H__
#define __POINTERS1_H__

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <pointers1.h>
#include "pointers1.c"


void Swap(int *a, int *b);


void printArray(int arr[], int length);


int Copy(int arr[] ,int arrcopy[],int n);


int StrLen(const char *str);


int StrCmp(const char* str1, const char* str2);


void Swap_Size_t(size_t *num1, size_t *num2);


void Swap_Ptr(size_t **num1, size_t **num2);

#endif
