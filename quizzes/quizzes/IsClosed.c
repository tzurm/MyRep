#include <string.h>
#include <stdio.h>
void IsClosed(char * str)
{
    size_t count = 0;
    size_t i = 0;
    size_t len = strlen(str);
    char check[len];
    if( 2 > len )
    {
        printf("not closed");
    }
    
    for(i = 0; i < len; ++i)
    {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            ++count;
            check[count] = str[i];
        }
        if((count >= 0) &&  (( str[i] == ')' && check[count] == '(' ) || ( str[i] ==']' && check[count] == '[' ) || (str[i] == '}' && check[count] == '{' ))) 
        {
            --count;
        }
    }
    (0 == count) ? printf("closed") : printf("not closed");
}
   
int main() {
    char *str="[[[({})[]]";
    IsClosed(s);

    return 0;
}
