#include <stdio.h>
#include "strings.h"
#include "strings.c"
#include "string.h"


int main() 
{
	int count1 = 0;
	int count2 = 0;
    char str_genric[]="tzur" ,one_letter[]="a" ,empty_str[]="" ;		/*StrLen */
    printf("******string length function ******* \n");
	count1 = StrLen(str_genric);
	count2 = strlen(str_genric);
    if(count1 == count2)
            printf("the string is - %s - and the length is %d \n", str_genric,StrLen(str_genric));
    else
        printf("error \n");
    count1 = StrLen(one_letter);
	count2 = strlen(one_letter);    
    if(count1==count2)
            printf("the string is - %s -  and the length is %d \n", one_letter,StrLen(one_letter));
    else
        printf("error \n");
    count1 = StrLen(empty_str);
	count2 = strlen(empty_str);     
    if(count1==count2)
            printf("the string is - %s - and the length is %d \n", empty_str,StrLen(empty_str));
    else
        printf("error \n");    
     
 /* StrCmp */
    printf("******string compare function ******* \n");

    if (StrCmp(str_genric,str_genric)==strcmp(str_genric,str_genric))
   	 {
   		 printf("string1: %s , string2: %s \n", str_genric, str_genric);
	   	 if(0==StrCmp(str_genric,str_genric))
	   	 	printf("test workd and they are the same \n");
	   	 else 
	   		printf("test workd and they are NOT the same \n");
   	 }
   else
        printf("error \n"); 
    
      if (StrCmp(str_genric,one_letter)==strcmp(str_genric,one_letter))
   	 {
   		 printf("string1: %s , string2: %s \n", str_genric, one_letter);
	   	 if(0==StrCmp(str_genric,one_letter))
	   	 	printf("test workd and they are the same \n");
	   	 else 
	   		printf("test workd and they are NOT the same \n");
   	 }
   else
        printf("error \n"); 
        

    return 0;
}
