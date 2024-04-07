import os
from datetime import datetime

# Function to process arp.txt and write to output file
def process_folder(main_folder, output_file):
    with open(output_file, 'w') as output_all:
        output_all.write("Time Insert,File Name,FW Name,Address,HWtype,HWaddress,Flags,Mask,Iface\n")
        for item in os.listdir(main_folder):
            fw_folder = os.path.join(main_folder, item)
            if os.path.isdir(fw_folder) and item.startswith("fw_"):
                arp_file_path = os.path.join(fw_folder, "arp.txt")
                if os.path.exists(arp_file_path):
                    fw_name = item  # Extract FW name from folder name
                    with open(arp_file_path, 'r') as arp_file:
                        next(arp_file)  # Skip header line
                        for line in arp_file:
                            fields = line.split()
                            if len(fields) >= 4:
                                address = fields[0]
                                hwtype = fields[1]
                                hwaddress = fields[2]
                                flags = fields[3]
                                iface = fields[-1]
                                current_time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
                                output_all.write(f"{current_time};arp.txt;{fw_name};{address};{hwtype};{hwaddress};{flags};;{iface}\n")
                

# Main function
def main():
    input_folder = '/home/guest/main_folder'
    output_folder = '/home/guest/main_folder/output_parser'
    output_file = os.path.join(output_folder, "arp_output_all.txt")
    
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)

    process_folder(input_folder, output_file)

if __name__ == "__main__":
    main()
