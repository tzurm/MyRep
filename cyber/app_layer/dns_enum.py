#!/usr/bin/env python3
import requests
import threading


# Function to make a request to a URL
def make_request(full_url):
    try:
        r = requests.get(full_url, timeout = 0.5)
        return True
    except:
        return False
    
    
def main():
    count = 0
    url = "wikipedia.org/wiki"
    try:
        with open("ISO_639-1_Code.txt", "r") as file:
            words = file.read().splitlines()
    except EnvironmentError:
        print("Error: cant open file")
    for word in words:
        full_url = "https://" + word[0:2] + "." + url
        if make_request(full_url):
            print(full_url)
            count += 1
    print("Found", count , "urls")
        
if __name__ == "__main__":
    main()