#!/usr/bin/env python3
from functools import reduce
import sys
class color:
  BOLD = '\033[1m'
  END = '\033[0m'

"""--------------------------------------Ex1---------------------------------"""
def SumNumbersFor(list_number):
  sum = 0
  for num in list_number:
    sum += num
  return sum

def SumNumbersReduce(list_number):
   return reduce(lambda x, y: x + y, list_number)
 
def SumNumbersSum(list_number):
  return sum(list_number)

"""--------------------------------------Ex2---------------------------------"""
def ListOdd(num):
  return [i if i % 2 == 0 else 'odd' for i in range(num)]
  pass

"""--------------------------------------Ex3---------------------------------"""

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

"""--------------------------------------Ex5-------------------------------"""
def CountArgs(*args, **kwarg):
  return len(args)+len(kwarg)
"""--------------------------------------Ex6-------------------------------"""
def PrintNamed(*args, **kwarg):
  name = kwarg.get('name')
  print(name)
  """print(kwarg)"""
"""--------------------------------------Ex7-------------------------------"""
def MakeAdder(add_this):
  def AddNum(source):
    return source + add_this
  return AddNum 
  
"""--------------------------------------main-------------------------------"""     
def main():
  list_numbers = [i for i in range(101)]
  print(color.BOLD + "Ex1.CountNumbersThreeWays"+color.END)
  print(color.BOLD + " (1)for\t  "+color.END, SumNumbersFor(list_numbers))
  print(color.BOLD + " (2)reduce"+color.END, SumNumbersReduce(list_numbers))
  print(color.BOLD + " (3)sum\t  "+color.END, SumNumbersSum(list_numbers))
  print(color.BOLD + "Ex2.ListOdd"+color.END)
  print(ListOdd(10))
  print(color.BOLD + "Ex3.SevenBoomRange"+color.END)
  print(SevenBoomRange(50))
  print(color.BOLD + "Ex3.SevenBoomComp"+color.END)
  print(SevenBoomComp(50))
  print(color.BOLD + "Ex3.SevenBoomMap"+color.END)
  print(SevenBoomMap(50))
  print(color.BOLD + "Ex5.CountArgs"+color.END)
  print(CountArgs("hello" , 4,5,6,7,8 ,name = "hello" ,y = "world"))
  print(color.BOLD + "Ex6.PrintNamed"+color.END)
  PrintNamed("hello" ,name = "hello" ,y = "world")
  print(color.BOLD + "Ex7.MakeAdder"+color.END)
  add5 = MakeAdder(5)
  add7 = MakeAdder(7)
  print(add5(10))
  print(add7(-3))
  
  
if __name__ == "__main__":
  main()