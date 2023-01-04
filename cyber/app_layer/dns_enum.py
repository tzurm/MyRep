#!/usr/bin/env python3
import requests
import threading


# function to make a request to a URL
def make_request(full_url):
    try:
        r = requests.get(full_url, timeout = 3)
        print(full_url)
    except:
        pass
    
    
def main():
    
    url = "wikipedia.org/wiki"
    try:
        with open("common.txt", "r") as file:
            words = file.read().splitlines()
    except EnvironmentError:
        print("Error: cant open file")
    for word in words:
        full_url = "https://" + word[0:4] + "." + url
        thread = threading.Thread(target=make_request, args=(full_url,))
        thread.start()
        
if __name__ == "__main__":
    main()