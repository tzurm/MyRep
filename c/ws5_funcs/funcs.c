#include "funcs.h"
#include <assert.h>
#define ESC 27

void Spress()
{
 	char c='\0';
    system("stty  -icanon -echo");
    
    printf("Print A  or T  , Esc to exit");
   	scanf("%c", &c);
   	
    while(c != ESC) 
    {
    	
		switch(c)
		{

			case 'A':
					printf("A-pressed \n");
			break;
					
			case 'T':
					printf("T-pressed \n");
			break;
		   
			default:
		        printf("Error! \n");
		}
		scanf("%c", &c);
    }
 	system("stty icanon echo");
}


void Ipress()
{
 	char c='\0';
    system("stty  -icanon -echo");
    
    printf("Print A  or T  , Esc to exit");
   	scanf("%c", &c);
   	
    while(c != ESC) 
    {
    	
		if ('A' == c)
		{ 
					printf("A-pressed \n");
		}
		
		if ('T' == c)
		{ 		
					printf("T-pressed \n");
		}
		scanf("%c", &c);
    }
 	system("stty icanon echo");
}


