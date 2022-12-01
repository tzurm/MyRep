#include <stdio.h>
#include <string.h>

int IsRot(char *str1, char *str2)
{
    if (strlen(str1) != strlen(str2))
    {
        return 1;
    }
    strcat(str1, str1);

    return (NULL != strstr(str1, str2)) ? 0 : 1;
}

int main()
{
    char str1[] = "deabc", str2[] = "abcde", str3[] = "ab";
    printf("s1: %s \n", str1);
    printf("s2: %s \n", str2);
    printf("s3: %s \n", str3);
    (0 == IsRot(str1, str2)) ? 
        printf("s2 is rotation of s1\n") :
        printf("s2 is not rotation of s1\n");
    (0 == IsRot(str1, str3)) ? 
        printf("s3 is rotation of s1\n") : 
        printf("s3 is not rotation of s1\n");
    return 0;
}
