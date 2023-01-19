#!/usr/bin/env python3
import socket
import sys

def scan_ports(ip):
    print("Scanning all ports on IP:", ip)
    for port in range(1, 65535):                                     # change to 65535 to scan all ports
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)    # create a new socket object
        sock.settimeout(0.0001)
        result = sock.connect_ex((ip, port))                        # attempt to connect to the port on the IP address
        if result == 0:                                             # if the connection is successful
            print("Port", port, "is open for TCP connection")
        sock.close()
    print("complete scanned",port ,"ports.")

if len(sys.argv) < 2:
    print("Usage: python3 scan_ports.py [IP address]")
    sys.exit()

ip = sys.argv[1]
scan_ports(ip)