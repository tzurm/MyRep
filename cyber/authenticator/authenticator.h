#ifndef __ILRD_CR02_Authenticator_H__
#define __ILRD_CR02_Authenticator_H__


int AddUser(const char *user_name, const char *password);

int DeleteUser(const char *user_name);

int Authenticate(const char *user_name, const char *password);

#endif
