#!/usr/bin/env python3

import sys
class color:
  BOLD = '\033[1m'
  END = '\033[0m'


"""--------------------------------------ex1---------------------------------"""
def ListSquared():
  squares = []
  for i in range(11):
    squares.append(i**2)
  print(squares)
  
def ListSquaredWhile():
  squares = []
  i = 0
  while i<=10:
    squares.append(i**2)
    i += 1
  print(squares)
"""--------------------------------------ex2---------------------------------"""
def EvenForRange():
  evens = [i for i in range(11) if i % 2 == 0]
  print (evens)
  
def EvenForRange1():
  evens = [i for i in range(0,11,2)]
  print (evens)
  
def EvenWhile():
  evens = []
  i = 0
  while i<=11:
    evens.append(i)
    i += 2
  print(evens)
"""--------------------------------------ex3---------------------------------"""
def CountOccurrence(mystr):
  mystr = mystr.lower()
  counts = {} 
  for c in mystr:
    if c in counts:
      counts[c] += 1
    else:
      counts[c] = 1
  print(counts)
"""--------------------------------------ex4---------------------------------"""
def PrintListItems(mylist):
  for i, item in enumerate(mylist):
    print(i, item)
"""--------------------------------------ex5---------------------------------"""
def Intersection(list1,list2):
  return [val for val in list1 if val in list2]
"""--------------------------------------ex6---------------------------------"""
def RotateLeft(list1):
  return list1[1:] + [list1[0]]

"""--------------------------------------main-------------------------------"""     
def main():
  
  list1=["value", "more value", "other value"] 
  list2=["first value", "sec value", "other value", "value"]
  newlist=()
  print(color.BOLD + "Ex1.ListSquared"+color.END)
  ListSquared()
  ListSquaredWhile()
  print(color.BOLD + "Ex2.EvenForRange"+color.END)
  EvenForRange()
  EvenWhile()
  EvenForRange1()
  print(color.BOLD + "Ex3.CountOccurrence"+color.END)
  CountOccurrence("ttttzzzuur")
  print(color.BOLD + "Ex4.PrintListItems"+color.END)
  PrintListItems(list1)
  print(color.BOLD + "Ex5.UnionSamesValuesInTwoLists"+color.END)
  newlist = Intersection(list1,list2)
  print("list1 =\t",list1,"\n","list2 =\t",list2,"\n","new list = ",newlist,sep="")
  print(color.BOLD + "Ex6.RotateLeft"+color.END)
  print(RotateLeft(list1))
if __name__ == "__main__":
  main()