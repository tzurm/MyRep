#ifndef __FILES_H__
#define __FILES_H__

#include <stdio.h>		/* use for  printf */
#include <stdlib.h>		/* use for  malloc */
#include <string.h>



void Print (int a);

void Ex1 ();

void Remove(char *file);

int Count(char *file);
 
void Append (char *file , char *str);
  
void TopLine(const char *filename, const char *str);


#endif
