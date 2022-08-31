#include "strings.h"
#include <assert.h>

/*  function return the length of the string */

/* date: 27.8
writer: Tzur
review: michael
Status: approved
*/

size_t StrLen(const char *str)
{
    const char *runner = str;
    assert (NULL != str);
 	while( '\0' != *runner)
    {
        ++runner;
    }
    return (size_t)(runner - str);
}

/*  function to compare two strings (return 0 if equal) */

/* date: 27.8
writer: Tzur
review: michael
Status: approved
*/

int StrCmp(const char* str1, const char* str2) 
{
	assert (NULL != str1);
	assert (NULL != str2);
    while(*str1 && (*str1 == *str2))
    {
        ++str1;
        ++str2;
    }
    return (*str1 - *str2);
}

/* date: 29.8
writer: Tzur
review: Andrey
Status: approved
*/
int StrNCmp(const char* str1,const char* str2, size_t max) 
{
	size_t i=1;
    while((*str1 || *str2) && (i < max))
    {
        ++str1;
        ++str2;
        ++i;
    }
    return ((unsigned char)*str1 - (unsigned char)*str2);
}
/* date: 30.8
writer: Tzur
review: Alex
Status: approved
*/
int StrCaseCmp (char *str1, char *str2)
{
	
    while(*str1 && (tolower(*str1) == tolower(*str2))) 
    {
        ++str1;
        ++str2;
    }
    return ((unsigned char)*str1 - (unsigned char)*str2);
}

/* date: 30.8
writer: Tzur
review: Alex
Status: approved
*/
char *StrCpy (char *dest,  char *src) 
{
	char *temp=dest;
    while ( *src ) 
    {
    	*dest = *src;
        dest++;
        src ++;
    }
    *dest='\0';
    return temp;
}

/* date: 30.8
writer: Tzur
review: Alex
Status: approved
*/
char *StrNCpy( char *dest, char *src, size_t length) 
{
	size_t i=0;
	char *temp=dest;
	
    while (*src && (i < length)) 
    {
    	*dest=*src;
        ++dest;
        ++src;
        ++i;
    }
    *dest='\0';
    return temp;
}

/* date: 30.8
writer: Tzur
review: Alex
Status: approved
*/
char *StrChr(const char *str1, int ch) 
{
    while (*str1 != (char) ch) 
    {
        if (!*str1++) 
        {
            return NULL;
        }
    }
    return (char*)str1;
}

/* date: 30.8
writer: Tzur
review: Alex
Status: approved
*/
/* create dynamic on heap at size of the original  */
char *StrDup(const char *src)
{
    char *dest = malloc(StrLen(src) + 1);  
    if (NULL == dest )
    {
        return NULL;          
    }
    strcpy(dest, src); 
    return (char*)dest;                            
}
/* date: 30.8
writer: Tzur
review: Alex
Status: approved
*/
char *StrCat(char *dest, const char *src)
{
    char *temp=dest;
    while (*dest)
      ++dest;
    while (*dest += *src)
    {
        ++src;
        ++dest;
    }
    return temp;
}

char *StrNCat(char *dest, const char *src, size_t n)
{
	size_t i = 0;
    char *temp=dest;
    while (*dest)
    {
      ++dest;
    }
    while ((*dest += *src) && (i < n))
    {
        ++src;
        ++dest;
        ++i;
    }
    return temp;
}

/* date: 30.8
writer: Tzur
review: Alex
Status: approved
*/

char *StrStr(const char *str1, const char *str2)
{
    while (*str1)
    {
        if ((*str1 == *str2) && StrCmp(str1, str2)) 
        {
            return (char*)str1;
        }
        ++str1;
    }
    return NULL;
}
/* date: 30.8
writer: Tzur
review: Andrey
Status: approved
*/
size_t StrSpn(const char *str1, const char *str2)
{
	size_t size = 0;
	if((NULL == str1) || (NULL == str2))
    {
    	return size;
    }
    while(*str1 && StrChr(str2,*str1++))
	{
		++size;
	}	
	return size;	
}



/* date: 30.8
writer: Tzur
review: Mark
Status: approved
*/

void IsPalindrome(char *str1)
{   
	int i=0 , ispali=1;
	int length=strlen(str1);
	while (( i < (length/2)) &&  (*(str1 + i) == *(str1 + length -(i + 1))))
	{
		ispali=0;
		++i;
	}
	if (0 == ispali)
	{
		printf("'%s' is Palindrome", str1);
	}
	else
	{
	    printf("'%s' is not Palindrome", str1);
	}
}





