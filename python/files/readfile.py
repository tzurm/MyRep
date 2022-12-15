#!/usr/bin/env python3

import sys
class color:
  BOLD = '\033[1m'
  END = '\033[0m'

def PrintInUppercaseManger(file_name):
  with open(file_name, 'r') as file:
    contents = file.read()
    print(contents.upper())

def PrintContent(file_name):
  file = open(file_name, 'r')
  try:
    contents = file.read()
    print(contents.upper())
  finally:
    file.close()


def main():
  
  print(color.BOLD + "Ex1.PrintInUppercaseManger"+color.END)
  PrintInUppercaseManger('mybook.txt')
  print(color.BOLD + "Ex1.PrintContent"+color.END)
  PrintContent("mybook.txt")
   
if __name__ == "__main__":
  main()