
/*  function return the length of the string */

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

int StrCmp(const char* str1, const char* str2) /* read only  */
{
    while(*str1 && (*str1 == *str2)) /*  continue until *str1 is pointer to value & str1=str2  */
    {
        str1++;
        str2++;
    }
    return (const unsigned char)*str1 - (const unsigned char)*str2;
}

int StrNCmp( char* str1,  char* str2, int max) 
{
	int i=0;
    while((*str1 || *str2) && i<max  )
    {
        str1++;
        str2++;
    }
    return (const unsigned char)*str1 - (const unsigned char)*str2;
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



