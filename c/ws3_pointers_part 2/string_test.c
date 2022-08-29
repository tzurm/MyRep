#include "strings.h"

int main() 
{

	const char linestring[] = "the lion sleeps tonight";
	const char ch1 = 'l', ch2 = 'e';
	char *pstr1 = "s";
	char *pstr2 = "lion";
	char strcat1[100] = "the lion", strcat2[] = " sleeps tonight";
	int count1 = 0;
	int count2 = 0;
	char str[] = "test1";
	char strabc[] = "ABcde";
	char strABC[] = "ABCDE";
    char str_genric[]="tzur",one_letter[]="a" ,empty_str[]="",
    empty_str1[]="", empty_str2[]="";	
    printf("****** TESTS  StrLen function ******* \n");
	count1 = StrLen(str_genric);
	count2 = strlen(str_genric);
    assert(count1 == count2);
            printf("str: %s , leng: %d \n", str_genric,StrLen(str_genric));
    count1 = StrLen(one_letter);
	count2 = strlen(one_letter);    
    assert(count1==count2);
            printf("str: %s , leng: %d \n", one_letter,StrLen(one_letter));
    count1 = StrLen(empty_str);
	count2 = strlen(empty_str);     
    assert(count1==count2);
            printf("str: %s , leng: %d \n", empty_str,StrLen(empty_str));
    
     
/* StrCmp */
    printf("\n****** TESTS  StrCmp function ******* \n");

    if (StrCmp(str_genric,str_genric)==strcmp(str_genric,str_genric))
   	 {
   		 printf("str1: %s , str2: %s \n", str_genric, str_genric);
	   	 if(0==StrCmp(str_genric,str_genric))
	   	 	printf("strings are equal \n");
	   	 else 
	   		printf("strings are NOT equal \n");
   	 }
   else
        printf("error \n"); 
    
      if (StrCmp(str_genric,one_letter)==strcmp(str_genric,one_letter))
   	 {
   		 printf("string1: %s , string2: %s \n", str_genric, one_letter);
	   	 if(0==StrCmp(str_genric,one_letter))
	   	 	printf("strings are equal  \n");
	   	 else 
	   		printf("strings are NOT equal \n");
   	 }
   else
        printf("error \n"); 
        
        
        
/* StrCpy */
 	printf("\n****** TESTS StrCpy function *******\n");
 	assert(StrCpy(empty_str1,str)==strcpy(empty_str1,str));
 		puts(StrCpy(empty_str1,str));
	assert(StrCpy(empty_str1,one_letter)==strcpy(empty_str1,one_letter));
 		puts(StrCpy(empty_str1,one_letter));
 	assert(StrCpy(empty_str1,"")==strcpy(empty_str1,""));
 		puts(StrCpy(empty_str1,""));
 
 	
/* StrNCpy */
 printf("\n****** TESTS StrNCpy function *******\n");
 	printf("string copied ,N lim: %s \n" ,StrNCpy(empty_str2,"test2",6));
 	printf("string copied ,N lim: %s \n" ,StrNCpy(empty_str2,"test2",1));
 	printf("string copied ,N lim: %s \n" ,StrNCpy(empty_str2,"test2",0));
 	
/* StrNCmp */
 	printf("\n****** TESTS  StrNCmp function ******* \n");
	printf("string : %d \n" ,StrNCmp(strabc,strABC,2));
	printf("string : %d \n" ,strncmp(strabc,strABC,2));
	
	assert(StrNCmp(strabc,strABC,2)==strncmp(strabc,strABC,2));
	{
		if(StrNCmp(strabc,strABC,2)==0)
			printf("strings are equal");
		if(StrNCmp(strabc,strABC,2)!=0)
			printf("strings are NOT equal");
	}
	
	printf("\n****** TESTS  StrCat function ******* \n");
   	puts(StrCat(strcat1, strcat2));
   	puts(strcat(strcat1, ""));
   	
   	
 	printf("\n****** TESTS  StrChr function ******* \n");
	printf("String after '%c' is - '%s'\n", ch1, StrChr(linestring, ch1));
	printf("String after '%c' is - '%s'\n", ch2, StrChr(linestring, ch2));
   	
   	printf("\n****** TESTS  StrStr function ******* \n");
   	printf("%s\n", StrStr(linestring, pstr1));
   	printf("%s\n", StrStr(linestring, pstr2));
   	
   	printf("\n****** TESTS  reverse function ******* \n");
   	printf("before: %s\n", strcat1);
   	reverseString(strcat1);
    printf("reverse: %s\n", strcat1);
   	/*isPalindrome(spali);
   	
*/  	
   	
   	
    return 0;
    
    
}

