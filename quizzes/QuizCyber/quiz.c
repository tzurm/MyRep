/*Hack the following code! (on your computer) */
/*1. Change the value of x to 666, by changing code only instead of AREA1 */
/*2. Same as 1, but do not use the letter x in the code you add */
/*3. Change code only instead of AREA2, so that the output of the program will be only:  */
/*  */
/*x=1 */
/*Enter func1 */
/*Enter func2 */
/*Exit func2 */
/*Exit main */
 
#include <stdio.h>
void func2(void *arg) 
{
    long f2;
    printf("Enter func2\n");
    /* Area2 */
    
    /* Area2 */
    printf("Exit func2\n");
}
void func1() 
{
    long f1;
    printf("Enter func1\n");
    func2(&f1);
    printf("Exit func1\n");
}
 
int main() {
    const long x=1;
    long y=5;
    /* Area1 */
    
    /* Area1 */
    printf("x=%lu\n",x);
    func1();
 
    printf("Exit main\n");
    return 0;
}
