#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h> /* Definition of SYS_* constants */
#include <unistd.h>
#include <fcntl.h>



int main()
{
	char *password;
	size_t i=0;
	while(i < 3)
	{
	    password = (char *)malloc((20) * sizeof(char));

	    printf("Enter password (8 chars): ");
	    scanf("%s", password);
	    ++i; 
	}
	    free(password);

	return 0;
}

