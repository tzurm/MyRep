#!/usr/bin/env python3

import socket
import sys

def scan_port(ip, port):
  s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
  s.settimeout(0.5)
  try:
    s.connect((ip, port))
    return True
  except:
    return False
  finally:
    s.close()

def scan_network(ip):
  ip_parts = ip.split('.')
  base_ip = '.'.join(ip_parts[:-1]) + '.'
  for i in range(1, 256):
    current_ip = base_ip + str(i)
    for port in range(1, 65535):
      if scan_port(current_ip, port):
        print(f"{current_ip}:{port} is open")

ip = input("Enter ip ") #change for argv  - ip = sys.argv[1]
print("scanning...")
scan_network(ip)
