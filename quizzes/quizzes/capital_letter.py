#!/usr/bin/env python3
import os

def to_capital(file_path):
  if os.path.exists(file_path):
    with open(file_path, 'r') as file:
      contents = file.read()
    capitalized_contents = contents.upper()
    with open(file_path, 'w') as file:
      file.write(capitalized_contents)
  else:
    print(f"Error: file '{file_path}' does not exist")
    
# Test the function
file_path = "test_file.txt"
to_capital(file_path)