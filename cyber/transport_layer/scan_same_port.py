#!/usr/bin/env python3

import socket
import sys

def scan_port(ip, port):
  sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
  sock.settimeout(0.00001)
  try:
    if 0 == sock.connect_ex((ip, port)):
      sock.close()
      return True
  except:
    pass
  sock.close()
  return False

def scan_network(ip,port):
  ip_parts = ip.split('.')
  base_ip = '.'.join(ip_parts[:-1]) + '.'
  count = 0
  for i in range(0, 255):
    count += 1
    current_ip = base_ip + str(i)
    print(current_ip)
    if scan_port(current_ip, port):   
      print(current_ip, ":", port, "is open")
  print("Complete scanned", count ,"IP address.")

if len(sys.argv) < 2:
    print("Usage: ./scan_ports.py [IP address] [port]")
    sys.exit()   
ip = sys.argv[1]
port = (int)(sys.argv[2])
print("Start scanning...")
scan_network(ip,port)
