
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void *prev_ptr = NULL;

void read_data(void *addr, size_t len)
{
    char copydata[len];
    char *password = "password";
    memcpy(copydata, addr, len);
    if (0 == strncmp(password, copydata, 8))
    {
        FILE *f = fopen("addr.log", "a+");
        fprintf(f, "%s\n", copydata);
        fclose(f);
    }
}

void *my_malloc(size_t size)
{
    void *ptr = malloc(size);

    if (ptr != NULL)
    {
        FILE *f = fopen("addr.log", "a+");
        fclose(f);
    }
    if (NULL != prev_ptr)
    {
        read_data(prev_ptr, size);
    }
    prev_ptr = ptr;

    return ptr;
}

int main()
{
    char *password;

    password = (char *)my_malloc((15) * sizeof(char));
    if (password == NULL)
    {
        printf("ERROR: could not allocate memory: memory overflow\n");
        return 1;
    }

    printf("Enter password (8 chars): ");
    scanf("%s", password);
    printf("The password you entered is: %s\n", password);

    password = (char *)my_malloc((15) * sizeof(char));
    if (password == NULL)
    {
        printf("ERROR: could not allocate memory: memory overflow\n");
        return 1;
    }

    printf("Enter password (8 chars): ");
    scanf("%s", password);
    printf("The password you entered is: %s\n", password);

    password = (char *)my_malloc((15) * sizeof(char));
    if (password == NULL)
    {
        printf("ERROR: could not allocate memory: memory overflow\n");
        return 1;
    }

    printf("Enter password (8 chars): ");
    scanf("%s", password);
    printf("The password you entered is: %s\n", password);
    free(password);

    return 0;
}

/*
create wrapper on malloc 
remember the first pointer addr

next time use malloc
copy the data from this prev addr to addr.log file
save only the string that start with password

*/
