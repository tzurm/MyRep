#include <stdio.h>
#define BASE 10

void PrintHello ()
{
	char hex[]={0x22,0x48,0x65,0x6c,0x6c,0x6f,0x20,0x57,0x6f,0x72,0x6c,0x64,
    			0x21,0x22,'\0'};
	puts(hex);
    
}
double Power(int n) 
{
    double pow = 1;
    double base = 10;
    int i=0;
    
    if(0 > n)
    {
    	n *= -n;
        base = 1/base;
    }
    for (i = 0; i < n; i++)
    {
    	pow *=  base;
    }
return pow;
}

int Flip (int n) 
{
    int reversed = 0;
    while(0 != n)
    {
        reversed *= BASE;
        reversed += n % BASE;
        n /= BASE; 
    }
    return reversed;
}

void Swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() 
{
    int num;
    int n;
    double z ;
    int flipped;
    int x,y;
  
    printf("Enter num to start function \n1:\"Hello World!\" \n2: pow \n3: flip \n4: swap\n");
    scanf("%d", &num);
    switch(num)
    {
    	case 1: 
    		PrintHello();
    		break;
        case 2:
        	printf("Enter num for n \n");
        	scanf("%d" , &n);
        	z=Power(n);
        	printf("10 power %d = %f \n" ,n,z);
        	break;
        case 3:
                printf("Enter num to flip\n");
                scanf("%d", &n);
                flipped=Flip(n);
                printf("%d",flipped);
                break;
        case 4:
        	printf("Enter num for x ");
        	scanf("%d",&x);
        	printf("Enter num for y ");
        	scanf("%d",&y);
        	printf("The values before swapping: \n");
        	printf("x: %d  y: %d \n", x, y);
        	Swap(&x,&y);
        	printf("The values after swapping: \n");
		printf("x: %d  y: %d \n", x, y);
            	break;
        default:
            printf("Error! the number is not correct");
    }
    return 0;
}
