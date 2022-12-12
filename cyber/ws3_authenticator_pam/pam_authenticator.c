
#include <stdio.h>             /* function file */
#include <string.h>            /* strlen */
#include <assert.h>            /* assert */
#include <crypt.h>             /* crypt */
#include <security/pam_appl.h> /* PAM */
#include <security/pam_misc.h>

#include "authenticator.h"

#define MAX_USERNAME_LEN 32
#define MAX_PASSWORD_LEN 64
#define FOUND 1
#define NOT_FOUND -1

const struct pam_conv conv = {
    misc_conv,
    NULL};

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
 * Check if the user have authenticate by given user name and password.
 * Returns 1 on success, -1 on failure.
 */
int Authenticate(const char *user_name)
{
    int return_val;
    pam_handle_t *pam_handle;

    printf("enter password for %s user\n", user_name);

    return_val = pam_start("spiderpig", user_name, &conv, &pam_handle);
    if (return_val != PAM_SUCCESS)
    {
        return -1;
    }

    return_val = pam_authenticate(pam_handle, 0);
    if (return_val != PAM_SUCCESS)
    {
        return NOT_FOUND;
    }

    return_val = pam_end(pam_handle, return_val);

    if (return_val != PAM_SUCCESS)
    {
        return -1;
    }
    if (return_val == PAM_SUCCESS)
    {
        return FOUND;
    }
    return -1;
}

/*
 * Delete user by name
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