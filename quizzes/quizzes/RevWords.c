#include <stdio.h>
#include <string.h>

void swap(char *start,char*end)
{
    char temp;
    temp = *start;
    *start = *end;
	*end = temp;
}

void ReverseWords(char *str)
{
    size_t backspace_i[1000];
    size_t len=strlen(str);
    size_t count_backspace=0;
    
    size_t i=0;
    size_t j=0;
    size_t l=0;
    
/*	reverse all chars							*/
    for(i = 0; i < len/2; ++i)  
    {
    	swap(&str[i],&str[len-1-i]);
    }
    printf("%s\n" ,str);
/*	count backspace and save the index for each	*/
 	for(i = 0; i < len; ++i)
 	{
        if(' ' == str[i])
        {
		  backspace_i[count_backspace] = i;
		  ++count_backspace;
	    }
    }
    
    backspace_i[count_backspace] = i;
    
/*	reverse each word							*
*	i is num of words need to rev				*
*	j is index of the first letter				*
*	l is times we need to swap , half word		*/
	 
    for(i=0; i <= count_backspace; ++i)
	{
		len = backspace_i[i] - j;
	
		for(l = 0; l < len/2 ;++l)
		{
			swap(&str[l+j], &str[backspace_i[i]-1-l]);
		/*	printf("i: %d  j: %d l: %d\n" ,i , j , l);	*/
        }
        
	
		j = backspace_i[i] + 1;
	/*	printf("%s\n" ,str);	*/
	} 
	 
 }
int main()
{

    char str[1000]= "b str1 wordsss2 word3 a"; 
    /*char str2[1000]= "ab .";   
    ReverseWords(str2);
    printf("test2:	%s\n",str2);*/

    ReverseWords(str);
    printf("test1:	%s\n",str);

	return 0;     
     
}
