#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
   char *buffer = calloc(64, sizeof(*buffer));

   if (!buffer) {
       printf("Allocation failed\n");
       return -1;
   }

   strcpy(buffer, argv[1]);
   printf("%s\n", buffer);
   return 0;

}