#include <stdio.h>
#include <string.h>

int IsRot( char *str1 , char *str2)
{
    if(strlen(str1) != strlen(str2))
    {  
        return 1;
    }  
    strcat(str1, str1);  
    printf("s1: %s \n" ,str1) ;
    printf("s2: %s \n" ,str2) ;
    return (NULL != strstr(str1, str2)) ? 0 : 1   ;
 
}

int main()  
{  
    char str1[] = "deabc", str2[] = "abcde";  
          
    if (0 == IsRot(str1,str2))
        printf("s2 is rotation of s1");
    else
        printf("s2 is not rotation of s1");
   
    return 0;  
}  
