#!/usr/bin/env python3

import subprocess
import random
import string

# List of input generation strategies
strategies = [
    lambda: random.choice(['', '\x00']),
    lambda: ''.join(random.sample(string.printable.replace('\x00', ''), random.randint(0, 100))),
    lambda: 'A' * random.randint(0, 100),
    lambda: ' ' * random.randint(0, 100),
    lambda: ''.join(random.choice(['A', ' ']) for _ in range(random.randint(0, 100))),
]

for i in range(5):
    strategy = random.choice(strategies)
    s = strategy()
    subprocess.call(['./makecrash', s])
    
    
