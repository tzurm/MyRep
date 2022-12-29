#!/usr/bin/env python3

import socket
import sys

if len(sys.argv) < 2:
    print("Usage: python3 scan_ports.py [IP address]")
    sys.exit()

ip = sys.argv[1]

print("Scanning all ports on IP:", ip)

for port in range(1, 65535):                # change to 65535 to scan all ports
                                            # create a new socket object
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
    result = sock.connect_ex((ip, port))    # attempt to connect to the port on the IP address
    if result == 0:                         # if the connection is successful
        print("Port", port, "is open for TCP connection")
    sock.close()

print("Scanning complete.")



"""
 sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
This line creates a new socket object using the socket module.
AF_INET: This specifies that we are using the IPv4 protocol to communicate.
SOCK_STREAM: This specifies that we are using a TCP connection.
The socket function returns a socket object that can be used to communicate over
the network using the specified protocol. In this case, we are using the IPv4 
protocol and a TCP connection.
    """