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
	char *pstr2 = "lion";
	char strcat1[100] = "the lion", strcat2[] = " sleeps tonight";
	char strcat3[100] = "t", strcat4[] = " ";
	char strncat1[100] = "first 8 letter: ", strncat2[] = "the lions";
	char strncat3[100] = "first 1 letter: ", strncat4[] = "the lion";
	char str[] = "test1";
	char strabc[] = "ABcde";
	char strABC[] = "ABCDE";
	char strCaseabc[] = "ABsc";
	char strCaseABC[] = "abc";
    char str_genric[]="tzur",one_letter[]="a" ,empty_str[]="",
    empty_str1[]="", empty_str2[]="";	
    
    
    printf("\n***************************************** ");
   	printf("\n****** TESTS  StrLen function *********** \n");
	printf("*****************************************\n");   	
    printf("str: %s , leng: %lu \n", strpali,StrLen(strpali));
    printf("str: %s , leng: %lu \n", one_letter,StrLen(one_letter));
	printf("str: %s , leng: %lu \n", empty_str,StrLen(empty_str));
    
    printf("\n***************************************** ");
   	printf("\n****** TESTS  StrCmp function *********** \n");
	printf("*****************************************\n"); 
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
    printf("\n***************************************** ");
   	printf("\n****** TESTS  StrNCmp function ********** \n");
	printf("*****************************************\n"); 
	
	printf("str1: 'ABcde' str2: 'ABCDE' n=3 \n"); 
	printf("%d \n" ,StrNCmp(strabc,strABC,3));
	printf("str1: 'ABcde' str2: 'ABCDE' n=2 \n"); 
	printf("%d \n" ,StrNCmp(strabc,strABC,2));		
		
	printf("\n***************************************** ");
   	printf("\n****** TESTS  StrCaseCmp function ******* \n");
	printf("*****************************************\n");   
 	printf("test1: str1: '%s' , str2: '%s' \n", strCaseabc,strCaseABC);
 	if(0==StrCaseCmp(strCaseabc,strCaseABC))
 	{
	   	 	printf("strings are equal  \n");
	   	 	printf("%d \n" ,StrCaseCmp(strCaseabc,strCaseABC));		
 	}
 	else 
	{
	   		printf("strings are NOT equal \n");
	   		printf("%d \n" ,StrCaseCmp(strCaseabc,strCaseABC));	
 	}
 	printf("\ntest2: str1: 'abc' , str2: 'ABC' \n");
 	if(0==StrCaseCmp("abc","ABC"))
 	{
	   	 	printf("strings are equal  \n");
	   	 	printf("%d \n" ,StrCaseCmp("abc","ABC"));	
 	}
 	else 
	{
	   		printf("strings are NOT equal \n");
	   		printf("%d \n" ,StrCaseCmp("abc","ABC"));	
 	}
 	
	
    printf("\n***************************************** ");
   	printf("\n****** TESTS  StrCpy function *********** \n");
	printf("*****************************************\n");   
 	printf("test strings are NOT equal");
 	puts(StrCpy(empty_str1,str));
 	puts(StrCpy(empty_str1,one_letter));
 	puts(StrCpy(empty_str1,""));
 	
 	
 	printf("\n***************************************** ");
   	printf("\n****** TESTS  StrNCpy function ********** \n");
	printf("*****************************************\n"); 
 	printf("string copied ,n=6 : %s \n" ,StrNCpy(empty_str2,"test1",6));
 	printf("string copied ,n=1 : %s \n" ,StrNCpy(empty_str2,"test2",1));
 	printf("string copied ,n=0 : %s \n" ,StrNCpy(empty_str2,"test3",0));
 	
 	
	printf("\n***************************************** ");
   	printf("\n****** TESTS  StrChr function *********** \n");
	printf("*****************************************\n"); 
	printf("String after '%c' is - '%s'\n", ch1, StrChr(linestring, ch1));
	printf("String after '%c' is - '%s'\n", ch2, StrChr(linestring, ch2));
	
	
	printf("\n***************************************** ");
   	printf("\n****** TESTS  StrDup function *********** \n");
	printf("*****************************************\n"); 
	p1 = StrDup(linestring1);
	p2 = StrDup(linestring2);
	puts(p1);
	free(p1);
	puts(p2);
	free(p2);

  	printf("\n***************************************** ");
   	printf("\n****** TESTS  StrCat function *********** \n");
	printf("*****************************************\n"); 	
	printf("str1: '%s' , str2: '%s' \n", strcat1,strcat2);
   	puts(StrCat(strcat1, strcat2));
   	printf("str1: '%s' , str2: '%s' \n", strcat3,strcat4);
   	puts(StrCat(strcat3, strcat4));
   	
   	
   	printf("\n***************************************** ");
   	printf("\n****** TESTS  StrNCat function ********** \n");
	printf("*****************************************\n"); 
   	printf("str1: '%s'\n", strncat2);
   	puts(StrNCat(strncat1, strncat2, 8));
   	printf("str2: '%s'\n", strncat4);
	puts(StrNCat(strncat3, strncat4, 1));
   	
   	
   	printf("\n***************************************** ");
   	printf("\n****** TESTS  StrStr function *********** \n");
	printf("*****************************************\n"); 
	printf("str1: '%s' , str2: '%s' \n", linestring,pstr1);
	printf("%s\n", StrStr(linestring, pstr1));
	printf("str1: '%s' , str2: '%s' \n", linestring,pstr2);	
   	printf("%s\n", StrStr(linestring, pstr2));
   	
   	printf("\n***************************************** ");
   	printf("\n****** TESTS  StrSpn function *********** \n");
	printf("*****************************************\n"); 
	printf("str1: 'sleep', str2: 'the lion sleeps' \n"); 
   	printf("Length str matching : %lu\n", StrSpn("sleep","the lion sleeps") );
   	printf("str1: 's', str2: 'the lion sleeps' \n");  
	printf("Length str matching : %lu\n", StrSpn("s","the lion sleeps") );
	printf("str1: '', str2: 'the lion sleeps' \n");  
	printf("Length str matching : %lu\n", StrSpn("","the lion sleeps") ); 

   	printf("\n***************************************** ");
	printf("\n****** TESTS  Palindrome function ******* \n");
	printf("*****************************************\n");
 	IsPalindrome("dad");
 	printf("\n");
	IsPalindrome("Dad");
	printf("\n");
	IsPalindrome("a");
	printf("\n");
	IsPalindrome("  ");
	printf("\n");
	IsPalindrome("\"live on time , emit no evil\"");
	printf("\n");
   	
   
 
     return 0;
}

