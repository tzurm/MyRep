#include <stdio.h>  /*  printf	    */
#include <string.h> /*  strfuncs    */
#include <stdlib.h> /*  malloc      */
#include "recursion.h"

void Test_Fib();
void Test_Strlen();
void Test_Strcmp();
void Test_Strcpy();
void Test_Strcat();
void Test_Strstr();
void Test_FlipList();
static void TestStrcmp(const char *str1, const char *str2);
static void TestStrstr(char *haystack, char *needle);

int main()
{
    printf("\n---------Test_Fib-------------------------------\n");
    Test_Fib();
    printf("\n---------Test_Strlen----------------------------\n");
    Test_Strlen();
    printf("\n---------Test_Strcmp-----------------------------\n");
    Test_Strcmp();
    printf("\n---------Test_Strcpy-----------------------------\n");
    Test_Strcpy();
    printf("\n---------Test_Strcat-----------------------------\n");
    Test_Strcat();
    printf("\n---------Test_Strstr-----------------------------------\n");
    Test_Strstr();
    printf("\n---------Test_FlipList-----------------------------------\n");
    Test_FlipList();

    return 0;
}

void Test_Fib()
{
    int index[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 40};
    size_t len = sizeof(index) / sizeof(index[0]);
    size_t i = 0;

    printf("index: ");
    for (i = 0; i < len; ++i)
    {
        printf("%d\t", index[i]);
    }
    printf("\nvalue: ");
    for (i = 0; i < len; ++i)
    {
        printf("%d\t", Fibonacci(index[i]));
    }
}

void Test_Strlen()
{
    char str1[20] = "sample_one12";
    char str2[20] = {'s', 'a', 'm', 'p', 'l', 'e', ' ', '\0'};
    char *str3 = "test_third_13";
    char *str4 = " ";

    printf("string\t\tStrlen  strlen\n");
    printf("------------------------------------------------\n");
    printf("%s\t%ld\t%ld\n", str1, Strlen(str1), strlen(str1));
    printf("%s\t\t%ld\t%ld\n", str2, Strlen(str2), strlen(str2));
    printf("%s\t%ld\t%ld\n", str3, Strlen(str3), strlen(str3));
    printf("'%s'\t\t%ld\t%ld\n", str4, Strlen(str4), strlen(str4));
}

void Test_Strcmp()
{
    char *str1 = "hello";
    char *str2 = "hello";
    char *str3 = "hellob";
    char *str4 = "bye";
    char *str5 = " ";

    printf("string\tstring\t\tStrcmp\tstrcmp\t status\n");
    printf("-------------------------------------------------\n");
    TestStrcmp(str1, str2);
    TestStrcmp(str1, str3);
    TestStrcmp(str1, str4);
    TestStrcmp(str1, str5);
}

void Test_Strcpy()
{
    char src1[20] = "' '";
    char src2[20] = "hello world";
    char dest[20] = {0};

    Strcpy(dest, src1);
    puts(dest);
    Strcpy(dest, src2);
    puts(dest);
}

void Test_Strcat()
{
    char dest[100] = "hello ";
    char src[] = "cat";

    Strcat(dest, src);
    puts(dest);
}

void Test_Strstr()
{
    char *haystack = "hello world!";
    char *needle1 = "world";
    char *needle2 = "ld";
    char *needle3 = "z";

    printf("haystack\tneedle\t\tStrstr\tstrstr\t status\n");
    printf("-------------------------------------------------------\n");
    TestStrstr(haystack, needle1);
    TestStrstr(haystack, needle2);
    TestStrstr(haystack, needle3);
}

void Test_FlipList()
{

    node_t *node1 = (node_t *)malloc(sizeof(node_t));
    node_t *node2 = (node_t *)malloc(sizeof(node_t));
    node_t *node3 = (node_t *)malloc(sizeof(node_t));
    node_t *node4 = (node_t *)malloc(sizeof(node_t));
    node_t *runner = NULL;

    int x1 = 1;
    int x2 = 2;
    int x3 = 3;
    int x4 = 4;

    node1->data = &x1;
    node1->next = node2;

    node2->data = &x2;
    node2->next = node3;

    node3->data = &x3;
    node3->next = node4;

    node4->data = &x4;
    node4->next = NULL;

    runner = node1;
    printf("before:\t");
    printf("%d -> ", *(int *)runner->data);
    runner = runner->next;
    printf("%d -> ", *(int *)runner->data);
    runner = runner->next;
    printf("%d -> ", *(int *)runner->data);
    runner = runner->next;
    printf("%d ", *(int *)runner->data);

    printf("\nafter:\t");
    runner = (node_t *)FlipList(node1);

    runner = node4;
    printf("%d -> ", *(int *)runner->data);
    runner = runner->next;
    printf("%d -> ", *(int *)runner->data);
    runner = runner->next;
    printf("%d -> ", *(int *)runner->data);
    runner = runner->next;
    printf("%d \n", *(int *)runner->data);
}

static void TestStrcmp(const char *str1, const char *str2)
{
    printf("%s\t%s\t\t%d\t%d\t", str1, str2, Strcmp(str1, str2), strcmp(str1, str2));
    Strcmp(str1, str2) == strcmp(str1, str2) ? printf("Approved") : printf("Failure");
    printf("\n");
}

static void TestStrstr(char *haystack, char *needle)
{
    printf("%s\t%s\t\t%s\t%s\t", haystack, needle, Strstr(haystack, needle), strstr(haystack, needle));
    /*  strcmp(Strstr(haystack, needle), strstr(haystack, needle)) ? printf("Approved") : printf("Failure");*/
    printf("\n");
}
