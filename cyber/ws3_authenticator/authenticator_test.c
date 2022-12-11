
#include <stdio.h>
#include <stdlib.h>

static void AuthenticateTest(const char *user_name, const char *password);
static void AddUserTest(const char *user_name, const char *password);
static void DeleteUserTest(const char *user_name);

int AddUser(const char *user_name, const char *password);
int Authenticate(const char *user_name, const char *password);
int DeleteUser(const char *user_name);

int main()
{

    char *username = "tzur";
    char *password = "123456";
    char *notusername = "pop";
    char *notpass = "12345";

    printf("user\tstatus\n-------------------------\n");
    /*--------------------------------------------------------Test AddUser----*/
    AddUserTest(username, password);
    AddUserTest("tzur111", "mypass123");
    AddUserTest("tzu", "mypass123");
    AddUserTest("t", "mypass123");
    AddUserTest("t", "mypass123");
    AddUserTest("user0", "mypass123");
    AddUserTest("user1", "12345678");

    /*---------------------------------------------------Test Authenticate----*/

    AuthenticateTest(username, password);   /*found*/
    AuthenticateTest(username, password);   /*found*/
    AuthenticateTest("tzur", "123456");     /*found*/
    AuthenticateTest("user0", "mypass123"); /*found*/
    AuthenticateTest("joo", notpass);       /*not found*/
    AuthenticateTest(notusername, notpass); /*not found*/   

    /*-----------------------------------------------------Test DeleteUser----*/

    DeleteUserTest(username); 
    AddUserTest(username, password);

    return 1;
}

static void AuthenticateTest(const char *user_name, const char *password)
{
    (1 == Authenticate(user_name, password)) ? printf("%s\tverified\n", user_name) : printf("%s\tnot found\n", user_name);
}
static void AddUserTest(const char *user_name, const char *password)
{
     (1 == AddUser(user_name, password)) ? printf("%s\tadd successfully\n", user_name) : printf("%s\tfail to add\n", user_name);
}
static void DeleteUserTest(const char *user_name)
{
     (1 == DeleteUser(user_name)) ? printf("%s\tdelete successfully\n", user_name) : printf("%s\tfail to delete\n", user_name);
}