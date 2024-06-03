#!/usr/bin/env python3
import os
import time

def delete_old_files(directory, age_limit_minutes):
    # Get the current time
    now = time.time()
    
    # Calculate the age limit in seconds
    age_limit_seconds = age_limit_minutes * 60
    
    # Walk through all files in the directory
    for root, dirs, files in os.walk(directory):
        for filename in files:
            file_path = os.path.join(root, filename)
            # Get the last modification time of the file
            file_mtime = os.path.getmtime(file_path)
            # If the file is older than the age limit, delete it
            if now - file_mtime > age_limit_seconds:
                print(f"Deleting {file_path}")
                os.remove(file_path)

if __name__ == "__main__":
    # For Windows, use a path like this:
    # directory = "C:\\path\\to\\your\\directory"

    # For Unix-like systems, use a path like this:
    # directory = "/home/user/Desktop"

    directory = "/path/to/your/directory"  # Replace with your directory path
    age_limit_minutes = 60
    delete_old_files(directory, age_limit_minutes)

