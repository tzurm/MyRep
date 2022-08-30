#include "strings.h"
int main() 
{

	const char linestring[] = "the lion sleeps tonight";
	const char ch1 = 'l', ch2 = 'e';
	char strpali[]="AAAAAAAAAAAA";
	char *p="";
	char *pstr1 = "s";
	char *pstr2 = "lion";
	char strcat1[100] = "the lion", strcat2[] = " sleeps tonight";
	char str[] = "test1";
	char strabc[] = "ABcde";
	char strABC[] = "ABCDE";
    char str_genric[]="tzur",one_letter[]="a" ,empty_str[]="",
    empty_str1[]="", empty_str2[]="";	
    printf("****** TESTS  StrLen function ******* \n");
    printf("str: %s , leng: %lu \n", str_genric,StrLen(str_genric));
    printf("str: %s , leng: %lu \n", one_letter,StrLen(one_letter));
	printf("str: %s , leng: %lu \n", empty_str,StrLen(empty_str));
    
    printf("\n****** TESTS  StrCmp function ******* \n");
    if (StrCmp(str_genric,str_genric)==strcmp(str_genric,str_genric))
   	 {
   		 printf("str1: %s , str2: %s \n", str_genric, str_genric);
	   	 if(0==StrCmp(str_genric,str_genric))
	   	 	printf("strings are equal \n");
	   	 else 
	   		printf("strings are NOT equal \n");
   	 } 
    
      if (StrCmp(str_genric,one_letter)==strcmp(str_genric,one_letter))
   	 {
   		 printf("string1: %s , string2: %s \n", str_genric, one_letter);
	   	 if(0==StrCmp(str_genric,one_letter))
	   	 	printf("strings are equal  \n");
	   	 else 
	   		printf("strings are NOT equal \n");
   	 }
        
 	printf("\n****** TESTS StrCpy function *******\n");
 	puts(StrCpy(empty_str1,str));
 	puts(StrCpy(empty_str1,one_letter));
 	puts(StrCpy(empty_str1,""));
 
 	printf("\n****** TESTS StrNCpy function *******\n");
 	printf("string copied ,N lim: %s \n" ,StrNCpy(empty_str2,"test2",6));
 	printf("string copied ,N lim: %s \n" ,StrNCpy(empty_str2,"test2",1));
 	printf("string copied ,N lim: %s \n" ,StrNCpy(empty_str2,"test2",0));
 	
 	printf("\n****** TESTS  StrNCmp function ******* \n");
	printf("string : %d \n" ,StrNCmp(strabc,strABC,2));
	printf("string : %d \n" ,strncmp(strabc,strABC,2));
	if(StrNCmp(strabc,strABC,2)==0)
		printf("strings are equal");
	if(StrNCmp(strabc,strABC,2)!=0)
		printf("strings are NOT equal");
	
	printf("\n****** TESTS  StrChr function ******* \n");
	printf("String after '%c' is - '%s'\n", ch1, StrChr(linestring, ch1));
	printf("String after '%c' is - '%s'\n", ch2, StrChr(linestring, ch2));
	
	printf("\n****** TESTS  StrDup function ******* \n");
	p = StrDup(linestring);
	puts(p);
	free(p);
	
	printf("\n****** TESTS  StrCat function ******* \n");
   	puts(StrCat(strcat1, strcat2));
   	puts(strcat(strcat1, ""));
   	
   	printf("\n****** TESTS  StrStr function ******* \n");
   	printf("%s\n", StrStr(linestring, pstr1));
   	printf("%s\n", StrStr(linestring, pstr2));
   	 
   	printf("\n****** TESTS  StrSpn function ******* \n");
   	printf("Length str matching : %lu\n", StrSpn("sleep","the lion sleeps") ); 
	printf("Length str matching : %lu\n", strspn("sleep","the lion sleeps") ); 
   
   	printf("\n****** TESTS  Reverse function ******* \n");
   	printf("before: %s\n", strcat1);
   	reverseString(strcat1);
    printf("reverse: %s\n", strcat1);
   	
   	
	printf("\n****** TESTS  Pali function ******* \n");
 	IsPalindrome(strpali);


   	
    return 0;
    
    
}

