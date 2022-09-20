#include "boundary.h"


void Ex1_Memset();
void Ex1_Memcpy();
void Ex1_Memmove();


int main() 

{
	printf("\n***** TESTS  Memset ************************************* \n\n");
  
 	Ex1_Memset();
 	
 	printf("\n***** TESTS  Memcpy ************************************* \n\n");
  
 	Ex1_Memcpy();
 
 	printf("\n***** TESTS  Memmove ************************************ \n\n");
  
 	Ex1_Memmove();
 
	return(0);
}	
 	

void Ex1_Memset()
{
	
	char str1[50] = {0} ;
	char str2[50] = {0} ;
	char str3[50] = {0} ;
	char str4[50] = {0} ;
	
	strcpy(str1,"abcdefeg");
	strcpy(str2,"abcdefeg");
	strcpy(str3,"abcdefeg");
	strcpy(str4,"abcdefeg");
	
	printf("Test_1 \n");
	printf("my Memset \n");
	printf("Before:	");
	puts(str1);
	Memset(str1,'*',3);
	printf("After:	");
	puts(str1);
	puts("");
	
	printf("original memset \n");
	printf("Before:	");
	puts(str2);
	memset(str2,'*',3);
	printf("After:	");
	puts(str2);
	
	printf("\n*****************\nTest_2 \n");
	printf("my Memset \n");
	printf("Before:	");
	puts(str3);
	Memset(str3,'*',5);
	printf("After:	");
	puts(str3);
	puts("");
	
	printf("original memset \n");
	printf("Before:	");
	puts(str4);
	memset(str4,'*',5);
	printf("After:	");
	puts(str4);
	
	
}

void Ex1_Memcpy()
{
	const char src1[4] = "123";
    char dest1[50] = {0};
    char dest2[50] = {0};
    
    printf("Test_1 \n");
    printf("my memcpy \n");
    strcpy(dest1,"abcdefeg");
    printf("Before:	%s\n", dest1);
    Memcpy(dest1, src1, 3);
    printf("After:	%s\n", dest1);
    
    printf("\noriginal memcpy \n");
    strcpy(dest2,"abcdefeg");
    printf("Before:	%s\n", dest2);
    memcpy(dest2, src1, 3);
    printf("After:	%s\n", dest2);
	
}

void Ex1_Memmove()
{
	const char src1[4] = "123";
    char dest1[50] = {0};
    
    char dest2[50] = {0};
    const char src3[15] = "123456789";
    char dest3[50] = {0};
    char dest4[50] = {0};
    
    printf("Test_1 \n");
    printf("my memcpy \n");
    strcpy(dest1,"abcdefeg");
    printf("Before:	%s\n", dest1);
    Memmove(dest1, src1, 3);
    printf("After:	%s\n", dest1);
    
    printf("\noriginal memcpy \n");
    strcpy(dest2,"abcdefeg");
    printf("Before:	%s\n", dest2);
    memmove(dest2, src1, 3);
    printf("After:	%s\n", dest2);
	
	
	printf("\n*****************\nTest_2 \n");
    printf("my memcpy \n");
    strcpy(dest3,"abcdefeg");
    printf("Before:	%s\n", dest3);
    Memmove(dest3, src3, 9);
    printf("After:	%s\n", dest3);
    
    printf("\noriginal memcpy \n");
    strcpy(dest4,"abcdefeg");
    printf("Before:	%s\n", dest4);
    memmove(dest4, src3, 9);
    printf("After:	%s\n", dest4);
	
}




   

