/* date: 24.8
writer: Tzur
review: Mark
Status: approved
*/

/*  swap function between two pointers */
 
void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}



/*  sub function to print array */
/* date: 24.8
writer: Tzur
review: Mark
Status: approved
*/
void printArray(int arr[], int length)
    {
    	int i;
        for (i=0; i<length;i++)  
            printf("%d " , arr[i]);
        printf("\n");
    }


/*  copy array function */
/* date: 24.8
writer: Tzur
review: Michael
Status: approved
*/

void Copy(int arr[] ,int arrcopy[],size_t n)
{
	assert(  NULL ! = arr)
	assert( NULL ! = arrcopy)
	while(0<len--)
	{
		*(arr++) = *(arrcopy++);
	}
}

/*  function return the length of the string */
/* date: 25.8
writer: Tzur
review: Michael
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

/*  function to compare two strings (return 0 if equal) , limit to 300 chars */
/* date: 25.8
writer: Tzur
review: Michael
Status: approved
*/

int StrCmp(const char* str1, const char* str2) /* read only  */
{
    while(*str1 && (*str1 == *str2)) /*  continue until *str1 is pointer to value & str1=str2  */
    {
        str1++;
        str2++;
    }
    return (const unsigned char)*str1 - (const unsigned char)*str2;
}

/* date: 28.8
writer: Tzur
review: Andrey
Status: approved
*/

void Swap_Size_t(size_t *num1, size_t *num2)
{
    size_t temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

/* date: 28.8
writer: Tzur
review: Andrey
Status: approved
*/


void Swap_Ptr(size_t num1, size_t num2)
{
    Swap_Size_t((size_t*),(size_t*) num2);
}
