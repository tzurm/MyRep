#include "funcs.h"
#include <assert.h>
#define ESC 27

/* date: 5.9
writer: Tzur
review: Arye
Status: approved
*/

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

/* date: 5.9
writer: Tzur
review: Arye
Status: approved
*/

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
		
		else if ('T' == c)
		{ 		
			printf("T-pressed \n");
		}
		else
		{
			printf("Press  again \n" );
		}
		
		scanf("%c", &c);
    }
 	system("stty icanon echo");
}


