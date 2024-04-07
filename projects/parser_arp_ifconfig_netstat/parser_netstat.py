import os
from datetime import datetime

# Function to process netstat.txt and write to output file
def process_folder(main_folder, output_file):
    with open(output_file, 'a') as output_all:
        output_all.write("Time Insert,File Name,FW Name,Proto,RefCnt,Flags,Type,State,I-Node,Path\n")
        for item in os.listdir(main_folder):
            fw_folder = os.path.join(main_folder, item)
            if os.path.isdir(fw_folder) and item.startswith("fw_"):
                netstat_file_path = os.path.join(fw_folder, "netstat.txt")
                if os.path.exists(netstat_file_path):
                    fw_name = item  # Extract FW name from folder name
                    with open(netstat_file_path, 'r') as netstat_file:
                        next(netstat_file)  # Skip header line
                        for line in netstat_file:
                            fields = line.split()
                            if len(fields) >= 7:
                                proto = fields[0]
                                refcnt = fields[1]
                                flags = fields[2]
                                type_ = fields[3]
                                state = fields[4]
                                inode = fields[5]
                                if len(fields) > 7:
                                    path = " ".join(fields[6:])
                                else:
                                    path = "None"
                                current_time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
                                output_all.write(f"{current_time};netstat.txt;{fw_name};{proto};{refcnt};{flags};{type_};{state};{inode};{path}\n")
                #else:
                #    print(f"No netstat.txt found in folder: {fw_folder}")

# Main function
def main():
    input_folder = '/home/guest/main_folder'                                    # change to main_folder (holdes the sub folders)
    output_folder = '/home/guest/main_folder/output_parser'                     # change where to save
    output_file = os.path.join(output_folder, "netstat_output_all.txt")
    
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)

    process_folder(input_folder, output_file)

if __name__ == "__main__":
    main()
