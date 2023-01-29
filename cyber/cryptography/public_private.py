#!/usr/bin/env python3
# Alice generates a pair of keys
p = 11
q = 3
n = p*q
phi = (p-1)*(q-1)
e = 7
d = 3

# Bob encrypts the message using Alice's public key
message = 32
ciphertext = (message**e) % n

# Bob sends the encrypted message to Alice

# Alice receives the message and decrypts it using her private key
plaintext = (ciphertext ** d) % n

# Alice can now read the message
print(plaintext)  # Output: 32
