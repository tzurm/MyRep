#!/usr/bin/env python3

import socket
import rsa

HOST = "192.168.0.168"  
PORT = 4567

# Generate a public/private key pair
(pubkey, privkey) = rsa.newkeys(512)

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    conn, addr = s.accept()
    with conn:
        print(f"Connected by {addr}")
        
        # Send the public key to the client
        conn.sendall(pubkey.save_pkcs1())
        # Receive the file name
        file_name = conn.recv(1024).decode()
        
        with open(file_name, "wb") as f:
            while True:
                data = conn.recv(1024)
                if not data:
                    break
                # Decrypt the data using the private key
                decrypted_data = rsa.decrypt(data, privkey)
                f.write(decrypted_data)
        print(f"File received: {file_name}")
