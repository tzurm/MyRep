
#include <stdio.h>  /*function file*/
#include <string.h> /*strlen*/
#include <assert.h> /*assert*/
#include <crypt.h>  /*crypt*/
#include "authenticator.h"

#define PATH_SPIDER "/home/tzur/git/tzur.mantzur/cyber/authenticator"
#define MAX_USERNAME_LEN 32
#define MAX_PASSWORD_LEN 64

/*
 * Adds a new user to the user file with the given user name and password.
 * Returns 1 on success, -1 on failure.
 */

int AddUser(const char *user_name, const char *password)
{

    int status = 0;
    char *hashed_password = "0";
    FILE *file = NULL;

    assert(strlen(user_name) < MAX_USERNAME_LEN);
    assert(strlen(password) < MAX_PASSWORD_LEN);

    file = fopen("mydatabase", "a");
    if (NULL == file)
    {
        return -1;
    }

    hashed_password = crypt(password, "spider");

    status = fprintf(file, "%s:%s\n", user_name, hashed_password);
    if (status < 0)
    {
        return -1;
    }

    fclose(file);

    return 1;
}

/*
 * check if the user have authenticate by given user name and password.
 * Returns 1 on success, -1 on failure.
 */
int Authenticate(const char *user_name, const char *password)
{

    char line[256] = "";        /*to read the current line and keep scan*/
    char *hashed_password = ""; /*to compare hash to hash*/
    FILE *file = NULL;

    assert(strlen(user_name) < MAX_USERNAME_LEN);
    assert(strlen(password) < MAX_PASSWORD_LEN);

    file = fopen("mydatabase", "r");
    if (NULL == file)
    {
        return -1;
    }

    /* Read each line of the file */
    while (NULL != fgets(line, sizeof(line), file))
    {
        /* Check if the line contains the user name */
        if (strstr(line, user_name))
        {
            /* If the user name was found, check if the password matches */
            hashed_password = crypt(password, "spider");
            if (strstr(line, hashed_password)) /*check the hash password*/
            {
                fclose(file);
                return 1;
            }
        }
    }

    fclose(file);
    return -1; /*user not found or password not correct*/
}
