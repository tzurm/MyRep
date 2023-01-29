#!/usr/bin/env python3

import sys
import socket

def main():

    host = "192.168.0.198"
    port = 4446
    if len(sys.argv) < 2:
        print("Usage: ./echo.py [port]")
        sys.exit()

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((host, port))
        s.sendall(b"hello world")
        data = s.recv(1024)
    print(f"Recvied", data)


if __name__ == "__main__":
    main()

