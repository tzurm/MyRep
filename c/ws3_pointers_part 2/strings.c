#include "strings.h"

/*  function return the length of the string */

/* date: 27.8
writer: Tzur
review: Micael
Status: approved
*/

int StrLen(const char *str)
{
    int count = 0;
    while(*str!='\0')
    {
        count++;
        str++;
    }
    return count;
}

/*  function to compare two strings (return 0 if equal) */

/* date: 27.8
writer: Tzur
review: Micael
Status: approved
*/

int StrCmp(const char* str1, const char* str2) 
{
    while(*str1 && (*str1 == *str2)) /*  continue until *str1 is pointer to value & str1=str2  */
    {
        str1++;
        str2++;
    }
    return (const unsigned char)*str1 - (const unsigned char)*str2;
}
/* date: 29.8
writer: Tzur
review: Andrey
Status: approved
*/
int StrNCmp( char* str1,  char* str2, int max) 
{
	int i=1;
    while((*str1 || *str2) && (i < max))
    {
        str1++;
        str2++;
        i++;
    }
    return (const unsigned char)*str1 - (const unsigned char)*str2;
}

int StrCaseCmp( char* str1,  char* str2) 
{
	
    while(*str1=='\0' && (tolower(*str1) == tolower(*str2))) 
    {
        str1++;
        str2++;
    }
    return (unsigned char)*str1 - (unsigned char)*str2;
}


char *StrCpy( char *dest,  char* src) 
{
	char *temp=dest;
    while ( *src ) 
    {
    	*dest = *src;
        dest++;
        src ++;
    }
    *dest=0;
    return temp;
}

char *StrNCpy( char* dest, char* src, int length) 
{
	int i=0;
	char *temp=dest;
	
    while (*src && (i < length)) 
    {
    	*dest=*src;
        dest++;
        src++;
        i++;
    }
    *dest=0;
    return temp;
}

char *StrChr(const char *str1, int ch) 
{
    while (*str1 != (char) ch) 
    {
        if (!*str1++) 
        {
            return NULL;
        }
    }
    return (char *)str1;
}

char *StrCat(char *dest, char *src)
{
    char *temp=dest;
    while (*dest)
      dest++;
    while (*dest += *src)
    {
        src++;
        dest++;
    }
    return temp;
}





