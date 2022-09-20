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
	
	strcpy(str1,"*********************");
	strcpy(str2,"*********************");
	strcpy(str3,"*********************");
	strcpy(str4,"*********************");
	
	printf("Test_1 n=30 \n");
	printf("my Memset \n");
	printf("Before:	");
	puts(str1);
	Memset(str1,'1',30);
	printf("After:	");
	puts(str1);
	puts("");
	
	printf("original memset \n");
	printf("Before:	");
	puts(str2);
	memset(str2,'1',30);
	printf("After:	");
	puts(str2);
	
	printf("\n*****************\nTest_2 n=10 \n");
	printf("my Memset \n");
	printf("Before:	");
	puts(str3);
	Memset(str3,'1',10);
	printf("After:	");
	puts(str3);
	puts("");
	
	printf("original memset \n");
	printf("Before:	");
	puts(str4);
	memset(str4,'1',10);
	printf("After:	");
	puts(str4);
	
	
}

void Ex1_Memcpy()
{
	const char src1[50] = "1234567891011";
    char dest1[50] = {0};
    char dest2[50] = {0};
    
    printf("Test_1 n=3\n");
    printf("my memcpy \n");
    strcpy(dest1,"$$$$$$$$$$$$$$$$$$$");
    printf("Before:	%s\n", dest1);
    Memcpy(dest1, src1, 3);
    printf("After:	%s\n", dest1);
    
    printf("\noriginal memcpy \n");
    strcpy(dest2,"$$$$$$$$$$$$$$$$$$$");
    printf("Before:	%s\n", dest2);
    memcpy(dest2, src1, 3);
    printf("After:	%s\n", dest2);
    
    
    printf("\n*****************\nTest_3 n=17\n");
    printf("my memcpy \n");
    strcpy(dest1,"$$$$$$$$$$$$$$$$$$$");
    printf("Before:	%s\n", dest1);
    Memcpy(dest1, src1, 17);
    printf("After:	%s\n", dest1);
    
    printf("\n*****************\nTest_5 n=0 \n");
    printf("my memcpy \n");
    strcpy(dest1,"$$$$$$$$$$$$$$$$$$$");
    printf("Before:	%s\n", dest1);
    Memcpy(dest1, src1, 0);
    printf("After:	%s\n", dest1);
    
    printf("\n*****************\nTest_4 n=9\n");
    printf("my memcpy \n");
    strcpy(dest1,"$$$$$$$$$$$$$$$$$$$");
    printf("Before:	%s\n", dest1);
    Memcpy(dest1, src1, 9);
    printf("After:	%s\n", dest1);
    
    printf("\n*****************\nTest_4 n=8 \n");
    printf("my memcpy \n");
    strcpy(dest1,"$$$$$$$$$$$$$$$$$$$");
    printf("Before:	%s\n", dest1);
    Memcpy(dest1, src1, 8);
    printf("After:	%s\n", dest1);
    
    
    
	
}

void Ex1_Memmove()
{
    char dest1[50] = {0};
    char dest2[50] = {0};
    const char src3[15] = "123456789";
    char dest3[50] = {0};
    char dest4[50] = {0};
    
    printf("Test_1 (overlap) \n");
    printf("my memcpy \n");
    strcpy(dest1,"123456789");
    printf("Before:	%s\n", dest1);
    Memmove(dest1, dest1+3, 4);
    printf("After:	%s\n", dest1);
    
    printf("\noriginal memcpy \n");
    strcpy(dest2,"123456789");
    printf("Before:	%s\n", dest2);
    memmove(dest2, dest2-3, 4);
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




   

