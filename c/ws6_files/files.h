#ifndef __FILES_H__
#define __FILES_H__

#include <stdio.h>		/* printf */
#include <stdlib.h>		/* remove  */
#include <string.h>		/* strcmp  */

struct unit		
{
	char *str;
	int (*cmp_fun)(char *);
	int (*operation_fun)(char * , char *);  
};

enum change 
{
	SUCCESS = 0,
	ERROR = 1,
	USER_INPUT_EXIT = -1
};


void Print (int a);

void Ex1 ();

int Remove(char *file ,char *dummy);
 
int Count(char *file , char *dummy);
  
int Exit(char *file , char *str);
 
int Append(char *file , char *str);
 
int AppendBegin(char *filename, char *str);
  
int RemoveCmp(char *str);
   
int CountCmp(char *str);
    
int ExitCmp(char *str);
     
int AppendBeginCmp(char *str);
      
int AppendCmp(char *str);
 
void ex2 ( char *filename);
 


#endif
