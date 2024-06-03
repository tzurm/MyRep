#!/usr/bin/env python3
import os
import time

def delete_old_files(directory, age_limit_minutes):
    now = time.time()
    age_limit_seconds = age_limit_minutes * 60
    
    # List all files in the directory
    for filename in os.listdir(directory):
        file_path = os.path.join(directory, filename)
        
        if os.path.isfile(file_path):
            # Get the last modification time of the file
            file_mtime = os.path.getmtime(file_path)
            if now - file_mtime > age_limit_seconds:
                # print(f"Deleting {file_path}")
                os.remove(file_path)

if __name__ == "__main__":
    # syntax for windows:
    # directory = "C:\\path\\to\\your\\directory"
    directory = "/home/user/Desktop"    # Replace with your directory path
    age_limit_minutes = 30                  # Choose the min for delay
    delete_old_files(directory, age_limit_minutes)
