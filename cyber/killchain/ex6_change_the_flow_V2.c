#include <stdio.h>

void finish(int a, int b) 
{
  if (42 == a) {
    printf("That's an interesting value for a.\n");
  }
  if (0 == b) {
    printf("How mundane.\n");
  }
  if (32767 == a * b) {
    printf("Keep in mind that neither success not failure is ever final.\n");
  }
  if (8001 == a * b || 9001 == a * b) {
    printf("Realize that while the first 90 percent of code accounts for 90 "
           "percent of the development time, so does the last 10 percent of "
           "the code.");
  }

  printf("You've successfully finished this part of the exercise.\n");
}

void func() 
{
	int a;
	
	printf(".");
	/* rip of finish  =  back to main after calling func	*/
	/* *0x7fffffffdf60  = 0x401273							*/
	*(int*)((char*)(&a) + 28) = *(&a + 5);
	
	/* rip of func = go to finish func 						*/
	/* 0x7fffffffdf58 = 0x401176							*/
	*(&a + 5) = &finish;
}

int main() 
{
  func();

  return 0;
}


/*
gcc -Wall -Wextra -g3 ex6.c -o ex6 
to 
gcc -Wall -Wextra -g3 -no-pie ex6.c -o ex6

the diff with no-pie
pie-  position independent executeable
type of executable that can be loaded at any memory address to making harder to exploit memory related security vulnerabilities.
Disabling PIE with the "no-pie" option can sometimes be useful for debugging purposes or for running legacy applications that do not work with PIE.
*/
