#!/usr/bin/env python3

import sys

def mac_exists(mac_address, filename='your/path'):
    with open(filename, 'r') as file:
        lines = file.readlines()
        return any(mac_address in line for line in lines)

def add_mac_to_file(nickname, mac_address, filename='mac_list.txt'):
    if not mac_exists(mac_address, filename):
        with open(filename, 'a') as file:
            file.write(f"\n#{nickname}\n{mac_address} Cleartext-Password := \"{mac_address}\"\n")
        print(f"Done")
    else:
        print(f"MAC address {mac_address} already exists")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: ./add_mac.py <nickname> <mac_address>")
    else:
        nickname = sys.argv[1]
        mac_address = sys.argv[2]
        add_mac_to_file(nickname, mac_address)

#Example Usage:
# ./add_mac.py mynick 12-34-56-67-89-AA
