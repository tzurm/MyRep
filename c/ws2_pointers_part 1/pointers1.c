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
        for (int i=0; i<length;i++)  
            printf("%d " , arr[i]);
        printf("\n");
    }


/*  copy array function */
/* date: 24.8
writer: Tzur
review: Michael
Status: approved
*/

int Copy(int arr[] ,int arrcopy[],int n)
{
    for(int i=0;i<n;i++)
      arrcopy[i]=arr[i];
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


void Swap_Size_t(size_t *num1, size_t *num2)
{
    size_t temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void Swap_Ptr(size_t *num1, size_t *num2)
{
    
    size_t temp_num1 = *num1;
    size_t temp_num2 = *num2;   
    *num1 = temp_num2;
    *num2 = temp_num1;
}
