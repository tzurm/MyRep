#include "funcs.h"
#include <assert.h>
#define ESC 27

void pressed()
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


