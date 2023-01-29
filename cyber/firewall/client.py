#!/usr/bin/env python3

import socket
import rsa

HOST = "192.168.0.168"  
PORT = 4567


with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    
    # Receive the public key from the server
    pubkey = rsa.PublicKey.load_pkcs1(s.recv(1024))
    
    file_name = "top_secret.txt"
    # Send the name of the file
    s.sendall(file_name.encode())               
    with open(file_name, "rb") as f:
        file_contents = f.read()
        # Encrypt the file contents using the public key
        encrypted_file_contents = rsa.encrypt(file_contents, pubkey)
        s.sendall(encrypted_file_contents)
        print(f"File sent: {file_name}")