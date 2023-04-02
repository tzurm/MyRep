#!/usr/bin/python3

import pam
import getpass

def authenticate(username, password):
    p = pam.pam()
    return p.authenticate(username, password)

username = input("Enter your username: ")
password = getpass.getpass(prompt="Enter your password: ")

if authenticate(username, password):
    print("Authentication successful")
else:
    print("Authentication failed")


# to see logs:
# tail -f -n 0 /var/log/auth.log