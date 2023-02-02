#include <stdio.h>

void func(long a, long b) 
{

  *(&a-1)+=16;
  return 0;
  printf("%ld\n", b);
  printf("%ld\n", a);
}

int main() {
  int num = 3;
  func(3, 1);
  num = 4;
  printf("num is now %d\n", num);

  return 0;
}
