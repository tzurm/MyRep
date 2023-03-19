#!/usr/bin/env python3
import time
from hashlib import *
from timeit import default_timer as timer
from datetime import timedelta
import itertools
import threading

def init_sha256(password):
    encode_crackme = password.encode('utf-8')   # encoded before hashing
    hash_crackme = sha256(encode_crackme)       # hashing
    hex_crackme = hash_crackme.hexdigest()      # hash value
    return hex_crackme

def init_sha1(password):
    encode_crackme = password.encode('utf-8')   # encoded before hashing
    hash_crackme = sha1(encode_crackme)         # hashing
    hex_crackme = hash_crackme.hexdigest()      # hash value
    return hex_crackme

def bruteforce_sha256():
    for i in range(1, 87654321):
        guess = str(i)
        hex_guess = init_sha256(guess)
        if hex_guess == hex_crackme:
            print(f"Found:\t", guess)
            break

def bruteforce_sha1():
    for i in range(1, 87654321):
        guess = str(i)
        hex_guess = init_sha1(guess)
        if hex_guess == hex_crackme:
            print(f"Found:\t", guess)
            break
        
def bruteforce_sha256_lowercase():
    for combination in itertools.product(range(97, 123), repeat=5):
        guess = bytes(combination).decode('utf-8')
        # print(guess)
        hex_guess = init_sha256(guess)
        if hex_guess == hex_crackme:
            print(f"Found:\t", guess)
            break
        
def bruteforce_sha256_string():
    for combination in itertools.product(list(range(48, 58)) + list(range(97,123)), repeat=5):
        guess = bytes(combination).decode('utf-8')
        # print(guess)
        hex_guess = init_sha256(guess)
        if hex_guess == hex_crackme:
            print(f"Found:\t", guess)
            break

"""found = False

def check_combination(combination):
    global found
    guess = bytes(combination).decode('utf-8')
    # print(guess)
    hex_guess = init_sha256(guess)
    if hex_guess == hex_crackme:
        print(f"Found:\t", guess)
        found = True


def bruteforce_sha256_any():
    global found
    for combination in itertools.product(list(range(48, 58)) + list(range(97, 123)), repeat=5):
        if found:
            break
        t = threading.Thread(target=check_combination, args=(combination,))
        t.start()"""
    

        
def check_time(func):
    start = timer()
    func()
    end = timer()
    print((func.__name__), ":", timedelta(seconds=end-start))

"""--------------------------------TEST--------------------------------------"""
hex_crackme = init_sha256("12345")
check_time(bruteforce_sha256)

hex_crackme = init_sha1("12345")
check_time(bruteforce_sha1)

hex_crackme = init_sha256("azurm")
check_time(bruteforce_sha256_lowercase)

hex_crackme = init_sha256("0zz2z")
check_time(bruteforce_sha256_string)

"""hex_crackme = init_sha256("012aa")
check_time(bruteforce_sha256_any)"""