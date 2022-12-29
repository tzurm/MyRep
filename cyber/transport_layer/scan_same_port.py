#!/usr/bin/env python3

import socket
import sys

def scan_port(ip, port):
  sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
  sock.settimeout(0.00001)
  if 0 == sock.connect_ex((ip, port)):
    sock.close()
    return True
  sock.close()
  return False

def scan_network(ip,port):
  ip_parts = ip.split('.')
  base_ip = '.'.join(ip_parts[:-1]) + '.'
  for i in range(0, 255):
    current_ip = base_ip + str(i)
    if scan_port(current_ip, port):   
      print(current_ip, ":", port, "is open")
      
ip = sys.argv[1]
port = (int)(sys.argv[2])
print("Start scanning...")
scan_network(ip,port)
print("Scanning complete.")