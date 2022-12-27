#!/usr/bin/env python3

def get_file_name(file_path):
  # Split the file path by the '/' character and return the last element
  file_name = file_path.split('/')[-1]
  return file_name


file_name = get_file_name('/path/to/my/file.txt')
print(file_name)  # Output: 'file.txt'