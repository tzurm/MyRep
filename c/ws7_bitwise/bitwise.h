#ifndef __BITWISE_H__
#define __BITWISE_H__

#include <stdio.h>		/* use for  printf */
#include <stdlib.h>		/* use for  malloc */
#include <string.h>

/* Ex1 */
long Pow2 (unsigned int x, unsigned int y);

/* Ex2 */
int  Ex2Loop  (unsigned int num);
int  Ex2V2  (unsigned int num);

/* Ex3 */


/* Ex4  + Ex9 with loop*/
unsigned int CountBit( unsigned int num);
/* Ex4 */
void Bit3( unsigned int *arr , size_t len);

/*Ex5 */
unsigned char ByteMirror(unsigned char byte);

/* Ex7 */
int Div16 (unsigned int num);


/* Ex8 */
void SwapXor ( int *num1 , int *num2);


/* Ex9 without loop */
int CountCheckBit (unsigned int num);

#endif
