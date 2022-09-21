#ifndef __ATOI__
#define __ATOI__

#include <stdio.h>		/* printf */
#include <stdlib.h>		/* remove */
#include <string.h>		/* strcpy */

void CheckAtoi(char* str);

void CheckItoa(int num , char *buffer, int base);

int Atoi(char* str);

char *Itoa(int num, char *buffer, int base);




#endif
