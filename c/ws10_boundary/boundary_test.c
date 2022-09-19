#include "boundary.h"


void Ex1_Memset();
void Ex1_Memcpy();
/*void Ex1_Memmove();
*/

int main() 

{
	printf("\n***** TESTS  Memset ************************************* \n\n");
  
 	Ex1_Memset();
 	
 	printf("\n***** TESTS  Memcpy ************************************* \n\n");
  
 	Ex1_Memcpy();
 
 	printf("\n***** TESTS  Memmove ************************************ \n\n");
  /*
 	Ex1_Memmove();
 */
	return(0);
}	
 	

void Ex1_Memset()
{
	char str1[50];
	char str2[50];
	strcpy(str1,"$$$abcdefg");
	strcpy(str2,"$$$abcdefg");
	
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
	
	
}

void Ex1_Memcpy()
{
	const char src[50] = "*******";
    char dest[50] = {0};
    
    const char src2[50] = "*******";
    char dest2[50] = {0};
    
    printf("my memcpy \n");
    strcpy(dest,"random string");
    printf("Before:	%s\n", dest);
    Memcpy(dest, src, 6);
    printf("After:	%s\n", dest);
    
    printf("\noriginal memcpy \n");
    strcpy(dest2,"random string");
    printf("Before:	%s\n", dest2);
    memcpy(dest2, src2, 6);
    printf("After:	%s\n", dest2);
	
}



   

