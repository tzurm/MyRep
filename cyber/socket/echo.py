#!/usr/bin/env python3


import sys
import socket

def main():
    
    if len(sys.argv) < 3:
        print("Usage: ./echo.py [ip server] [port]")
        sys.exit()
                                                                    # create a socket (endpoint for send or recvie data )
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:    # ipv4 / tcp socket 

        host = sys.argv[1]                                          # get arguments by command line
        port = int(sys.argv[2])
                                                                    
        s.bind((host, port))                                        # bind the socket to a public host, and a port                                 
        s.listen(1)                                                 # set the socket to listen only 1 incoming connection
        while True:                                                                                                   
            s_client,addr = s.accept()                              # unpack to s_client - socket opject, addr contain (ip of the cleint, port)
            print("Got a connection from", addr)                    
                                                                
            while True:
                data = s_client.recv(1024).decode()                 # received data from client (1024 bytes max)
                if data is not None:                                # decoded from bytes to data       
                    print("Received:", data)
                    s_client.send(data.encode())                    # sends the data back to the client
                else:
                    break
                                               
if __name__ == "__main__":
    main()

    
    """
    pseudo - TCP socket flow (source https://realpython.com/python-sockets/)
    
    
                                server sending, client recveing data
                                                ---------
                                                |       |                 
    Server                                      v       |  
    sockt -> bind -> listen -> accept -------> recv -> send -> recv -> close
                                        ^       ^       |       ^  
                    Establish (3way)    |       |       |       |
                                        v       |       v       |
    Client  socket -> connenct --------------> send -> recv -> close
    (telent or ncat)                            ^       |           
                                                |       |
                                                ---------
                                client sending, server recveing data
    """     