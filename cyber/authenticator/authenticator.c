
#include <stdio.h>  /*function file*/
#include <string.h> /*strlen*/
#include <assert.h> /*assert*/
#include <crypt.h>  /*crypt*/
#include "authenticator.h"

#define MAX_USERNAME_LEN 32
#define MAX_PASSWORD_LEN 64
#define FOUND 1
#define NOT_FOUND -1

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
        fclose(file);
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

    while (NULL != fgets(line, sizeof(line), file))
    {

        if (strstr(line, user_name)) /* Check if user name in line */
        {
            /* Check if the password matches by find the hahs in line */
            hashed_password = crypt(password, "spider");
            if (strstr(line, hashed_password))
            {
                fclose(file);
                return FOUND;
            }
        }
    }

    fclose(file);
    return NOT_FOUND;
}

/*
 * Delet user by password
 * Returns 1 on success, -1 on failure.
 */
int DeleteUser(const char *user_name)
{
    FILE *file = NULL;
    FILE *tmp = NULL;
    char line[256] = "";
    int user_found = 0;

    file = fopen("mydatabase", "r");
    if (NULL == file)
    {
        return -1;
    }

    while (NULL != fgets(line, sizeof(line), file))
    {
        if (strstr(line, user_name))
        {
            user_found = FOUND;
            continue; /*start over and check next line*/
        }

        /* If the user was not found, write the current line to a temporary file */
        tmp = fopen("mydatabase.tmp", "a");
        fputs(line, tmp);
        fclose(tmp);
    }

    /* When done to check every line,
    this tmp file contains only lines without the selected user name */

    fclose(file);

    if (FOUND == user_found)
    {
        rename("mydatabase.tmp", "mydatabase");
        return 1;
    }
    
    return -1;
}