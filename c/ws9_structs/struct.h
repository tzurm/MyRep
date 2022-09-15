#ifndef __FILES_H__
#define __FILES_H__

#include <stdio.h>		/* printf */
#include <stdlib.h>		/* remove  */
#include <string.h>		/* strcmp  */
/*			ex5		 */
#define MAX3(a,b,c) MAX2(MAX2(a,b),MAX2(b,c))
#define MAX2(a,b) ((a)>(b)?(a):(b)) 
/*			ex6		 */
#define SIZEOF_TYPE(type) (char *)(&type+1)-(char*)(&type)

#define SIZEOF_VAR(var) ((size_t)(&(var)+1)-(size_t)(&(var))) 





#endif
