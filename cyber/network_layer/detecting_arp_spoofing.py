#!/usr/bin/env python3

import os
import sys                  #sys.argv
import time

def check_duplicate(list):
    my_set = set(list)
    if len(my_set) == len(list):        # set remove the duplicates from a list
        pass
    else:
        notify = 'notify-send "ALERT: Arp Spoofing!"'
        os.system(notify)
        
        os.system("arp -v > arp_cache.logs")    # overwrite
        os.system("date >> arp_cache.logs")     # append timestamp

def detect_arp_spoofing():
    while True:           
        os.system("arp -v > arp_cache.logs")    # overwrite
        os.system("date >> arp_cache.logs")     # append timestamp
        found_words = []                        # empty list
        words = open('arp_cache.logs','r').read().split(' ')
        for word in words:
            if len(word) == 17:
                found_words.append(word)
        check_duplicate(found_words)
        time.sleep(5)

"""----------------------------------------------------------------------main"""
def main():

    detect_arp_spoofing()
    
if __name__ == "__main__":
	main()


