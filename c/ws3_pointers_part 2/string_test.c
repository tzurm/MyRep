#include "strings.h"
int main() 
{
	const char linestring[] = "the lion sleeps tonight";
	const char linestring1[] = "the lion sleeps tonight";
	const char linestring2[] = "the lion";
	const char ch1 = 'l', ch2 = 'e';
	char *p1="";
	char *p2="";
	char *strpali = "dady";
	char *pstr1 = "s";
	char pstr2[] = {'l','i','o','n','\0'};
	char strcat1[100] = "the lion", strcat2[] = " sleeps tonight";
	char strcat3[100] = "the lion", strcat4[] = " sleeps tonight";
	char strncat1[100] = "first 8 letter: ", strncat2[] = "the lion";
	char strncat3[100] = "first 8 letter: ", strncat4[] = "the lion";
	char str[] = "test1";
	char strabc[] = "ABcde";
	char strABC[] = "ABCDE";
    char str_genric[]="tzur",one_letter[]="a" ,empty_str[]="",
    empty_str1[]="", empty_str2[]="";	
      
    printf("****** TESTS  StrLen function ******* \n");
    printf("str: %s , leng: %lu \n", strpali,StrLen(strpali));
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
	p1 = StrDup(linestring1);
	p2 = StrDup(linestring2);
	puts(p1);
	free(p1);
	puts(p2);
	free(p2);
	
	printf("\n****** TESTS  StrCat function ******* \n");
   	puts(StrCat(strcat1, strcat2));
   	puts(StrCat(strcat3, strcat4));
   	
   	printf("\n****** TESTS  StrNCat function ******* \n");
   	puts(StrNCat(strncat1, strncat2, 8));
	puts(StrNCat(strncat3, strncat4, 8));
   	printf("\n***************************************** ");
   	printf("\n****** TESTS  StrStr function *********** \n");
	printf("*****************************************\n"); 
   	printf("%s\n", StrStr(linestring, pstr1));
   	printf("%s\n", StrStr(linestring, pstr2));
   	
   	printf("\n***************************************** ");
   	printf("\n****** TESTS  StrSpn function *********** \n");
	printf("*****************************************\n"); 

   	printf("Length str matching : %lu\n", StrSpn("sleep","the lion sleeps") ); 
	printf("Length str matching : %lu\n", strspn("sleep","the lion sleeps") ); 

   	printf("\n***************************************** ");
	printf("\n****** TESTS  Palindrome function ******* \n");
	printf("*****************************************\n");
 	IsPalindrome("dad");
 	printf("\n");
	IsPalindrome("Dad");
	printf("\n");
	IsPalindrome("a");
	printf("\n");
	IsPalindrome("\"live on time , emit no evil\"");
	printf("\n");
   	
   
 
     return 0;
}

