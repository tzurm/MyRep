#include <stdio.h>
#include "string_m.h"
#include "string_m.c"
#include "string.h"


int main() 
{
/*StrLen */
    char str_genric[]="tzur" ,one_letter[]="a" ,empty_str[]=" " ;
    printf("str size function \n");
    if(StrLen(str_genric)==strlen(str_genric))
            printf("the string is - %s - and the length is %d \n", str_genric,StrLen(str_genric));
    else
        printf("error \n");
        
    if(StrLen(one_letter)==strlen(one_letter))
            printf("the string is - %s -  and the length is %d \n", one_letter,StrLen(one_letter));
    else
        printf("error \n");
        
    if(StrLen(empty_str)==strlen(empty_str))
            printf("the string is - %s - and the length is %d \n", empty_str,StrLen(empty_str));
    else
        printf("error \n");    
     
 /* StrCmp */
    printf("string compare function  \n");
    char str1[300];
    char str2[300];
    printf("Enter str1 \n");
    scanf("%s", str1);
    printf("Enter str2 \n");
    scanf("%s", str2);
    if (StrCmp(str1,str2)==strcmp(str1,str2))
   	 {
   		 printf("string1: - %s , string2: %s \n", str1, str2);
	   	 if(0==StrCmp(str1,str2))
	   	 	printf("test workd and they are the same \n");
	   	 else 
	   		printf("test workd and they are NOT the same \n");
   	 }
   else
        printf("error \n"); 

    return 0;
}
