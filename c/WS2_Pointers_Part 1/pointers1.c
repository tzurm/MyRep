/* date: 24.8
writer: Tzur
review: Mark
Status: approved
*/

//swap function between two pointers
 
void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//sub function to print array

void printArray(int arr[], int length)
    {
        for (int i=0; i<length;i++)  
            printf("%d " , arr[i]);
        printf("\n");
    }

// copy array function

int Copy(int arr[] ,int arrcopy[],int n)
{
    for(int i=0;i<n;i++)
      arrcopy[i]=arr[i];
}


