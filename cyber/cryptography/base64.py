#!/usr/bin/env python3

import os
import sys 
import base64
"""pseudo
    char(divide by 3) -> ascii -> 8 bit -> 6 bit -> base 64 table
    """
BASE64_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

def encode(textplain):
    textplain_in_bytes = ""
    cipher_text = ""
    for index in range(0, len(textplain)):
        textplain_in_bytes += f'{ord(textplain[index]):08b}'

    six_bit_chunks = [textplain_in_bytes[i:i+6] for i in range(0,len(textplain_in_bytes),6)]
    six_bit_chunks[len(six_bit_chunks) - 1] = six_bit_chunks[len(six_bit_chunks) - 1].ljust(6,'0')
    for chunk in six_bit_chunks:
        cipher_text += BASE64_CHARS[int(chunk,2)]
        
    padding = len(textplain) % 3
    if padding == 1:
        cipher_text += "=="
    elif padding == 2:
        cipher_text += "="
    
    print(cipher_text)

def decode(ciphertext):
    padding = 0
    textplain = ''
    cipertext_to_binary=''
    
    if ciphertext[-2:] == "==":
        padding = 2
    elif ciphertext[-1:] == "=":
        padding = 1    
    
    for index in range(0, (len(ciphertext) - padding)):
        for LUT_index in range(0, len(BASE64_CHARS)):
            if ciphertext[index] == BASE64_CHARS[LUT_index]:
                cipertext_to_binary += f'{LUT_index:06b}'
    chunks=[cipertext_to_binary[i:i+8] for i in range(0,len(cipertext_to_binary),8)]
    for chunk in chunks:
        textplain += chr(int(chunk,2))
        
    print(textplain)



def main():

    if len(sys.argv) < 3:
        print("Usage: ./base64.py [enc/dec] [string]")
        sys.exit()   
    input_string = sys.argv[2]  
    mode = sys.argv[1]
    if(mode == "enc"):
        encode(input_string)        
    if(mode == "dec"):
        decode(input_string)

     
if __name__ == "__main__":
	main()