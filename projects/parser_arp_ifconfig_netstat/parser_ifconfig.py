import os
import re
from datetime import datetime

# Function to extract information from each interface block
def extract_info(interface_block):
    ip_match = re.search(r'inet addr:(\d+\.\d+\.\d+\.\d+)', interface_block)
    bcast_match = re.search(r'Bcast:(\d+\.\d+\.\d+\.\d+)', interface_block)
    mask_match = re.search(r'Mask:(\d+\.\d+\.\d+\.\d+)', interface_block)
    mac_match = re.search(r'HWaddr (\w+:\w+:\w+:\w+:\w+:\w+)', interface_block)
    rx_match = re.search(r'RX bytes:\d+ \(([\d.]+ [PKMGT]?iB)\)', interface_block)
    tx_match = re.search(r'TX bytes:\d+ \(([\d.]+ [PKMGT]?iB)\)', interface_block)

    ip = ip_match.group(1) if ip_match else "None"
    bcast = bcast_match.group(1) if bcast_match else "None"
    mask = mask_match.group(1) if mask_match else "None"
    mac = mac_match.group(1) if mac_match else "None"
    rx = rx_match.group(1) if rx_match else "None"
    tx = tx_match.group(1) if tx_match else "None"

    return ip, bcast, mask, mac, rx, tx

# Function to process ifconfig.txt and write to ifconfig_output_all.txt
def process_folder(main_folder, output_file):
    with open(output_file, 'w') as output_all:
        output_all.write("Time Insert,File Name,FW Name,Interface Name,IP,BroadCast_IP,CIDR,MAC_Address,RX,TX\n")
        for item in os.listdir(main_folder):
            fw_folder = os.path.join(main_folder, item)
            if os.path.isdir(fw_folder) and item.startswith("fw_"):
                for subitem in os.listdir(fw_folder):
                    sub_folder = os.path.join(fw_folder, subitem)
                    if os.path.isfile(sub_folder) and subitem == "ifconfig.txt":
                        fw_name = item  # Extract FW name from folder name
                        with open(sub_folder, 'r') as ifconfig_file:
                            interface_blocks = ifconfig_file.read().split('\n\n')
                            for block in interface_blocks:
                                lines = block.split('\n')
                                if lines:
                                    interface_name = lines[0].split()[0]
                                    ip, bcast, mask, mac, rx, tx = extract_info(block)
                                    current_time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
                                    output_all.write(f"{current_time};ifconfig.txt;{fw_name};{interface_name};{ip};{bcast};{mask};{mac};{rx};{tx}\n")

# Main function
def main():
    input_folder = '/home/guest/main_folder'                                    # change to main_folder (holdes the sub folders)
    output_folder = '/home/guest/main_folder/output_parser'                     # change where to save
    output_file = os.path.join(output_folder, "ifconfig_output_all.txt")        
    
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)

    process_folder(input_folder, output_file)

if __name__ == "__main__":
    main()
