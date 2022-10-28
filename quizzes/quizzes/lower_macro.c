
#include <stdio.h>
#define LOWER(char) (char > 'a' && char < 'z') ? (char) : ((char +'a')-'A')


int main() {
    
    printf("%c" , LOWER('b'));

    return 0;
}
