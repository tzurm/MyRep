#!/usr/bin/env python3

import sys
class color:
  BOLD = '\033[1m'
  END = '\033[0m'

"""--------------------------------------ex1---------------------------------"""

"""--------------------------------------ex3---------------------------------"""

def SevenBoomRange(num):
  seven_boom_list = []
  for i in range(num):
    if(i % 7 == 0) or ('7' in str(i)):
      seven_boom_list.append(i)
  return seven_boom_list

def SevenBoomComp(num):
  return [i for i in range(num) if i % 7 == 0 or  '7' in str(i)] 
  
def SevenBoomMap(num):
  def seven_boom(i):
    """ return i if i % 7 == 0 or '7' in str(i) else None"""
    if i % 7 == 0 or '7' in str(i):
      return i
    else:
      not None
  return [i for i in map(seven_boom, range(num)) if i is not None]
  
def MakeAdder(num):
  def AddNum(i):
    pass 
  
"""--------------------------------------main-------------------------------"""     
def main():
  print(color.BOLD + "Ex3.SevenBoomRange"+color.END)
  print(SevenBoomRange(50))
  print(color.BOLD + "Ex3.SevenBoomComp"+color.END)
  print(SevenBoomComp(50))
  print(color.BOLD + "Ex3.SevenBoomMap"+color.END)
  print(SevenBoomMap(50))
  
  
if __name__ == "__main__":
  main()