
#include <stdio.h>
#include <stdlib.h>
#include <security/pam_appl.h> /* PAM */
#include <security/pam_misc.h>

static void PrintAuthenticateTest(const char *user_name);
int AddUser(const char *user_name, const char *password);
int Authenticate(const char *user_name);
int DeleteUser(const char *user_name);

int main()
{
    
    /*--------------------------------------------------------Test AddUser----*/
    
    /*---------------------------------------------------Test Authenticate----*/

    PrintAuthenticateTest("tzur");   /*found*/
 
    /*-----------------------------------------------------Test DeleteUser----*/

    return 1;
}


static void PrintAuthenticateTest(const char *user_name)
{
    (1 == Authenticate(user_name)) ? printf("%s verified\n", user_name) : printf("%s not found\n", user_name);
}



/*

PAM functions that need to be implemented:
pam_sm_authenticate()
pam_sm_setcred()
pam_sm_acct_mgmt()
pam_sm_open_session()
*/