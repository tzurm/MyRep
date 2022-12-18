#!/usr/bin/env python3
from functools import reduce
import sys
class color:
  BOLD = '\033[1m'
  END = '\033[0m'

"""--------------------------------------Q8---------------------------------"""
class DivisionError(Exception):
    def __init__(self, message):
        self.message = message

"""--------------------------------------Ex1,2---------------------------------"""
def div(a,b):
  try:
    return a / b
  except ZeroDivisionError:
    print("Error: Tried to divide by zero.")
    return None
  except TypeError:
    print("Error: Values are not suitable for the '/' operator.")
    raise TypeError
"""--------------------------------------Ex3---------------------------------"""
  
"""--------------------------------------main-------------------------------"""     
def main():
  print(div(5,0))
  print(div(5,2))
  """print(div("a","v"))"""
  
  
if __name__ == "__main__":
  main()