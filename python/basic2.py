#!/usr/bin/env python3

import sys
class color:
  BOLD = '\033[1m'
  END = '\033[0m'


"""--------------------------------------ex1---------------------------------"""
def ListSquared():
  squares = []
  for i in range(101):
    squares.append(i**2)
  print(squares)
  
def ListSquaredWhile():
  squares = []
  i = 0
  while i<=100:
    squares.append(i**2)
    i += 1
  print(squares)
"""--------------------------------------ex2---------------------------------"""
def EvenForRange():
  evens = [i for i in range(11) if i % 2 == 0]
  print (evens)
  
def EvenForRange1():
  evens = [i for i in range(0,101,2)]
  print (evens)
  
def EvenWhile():
  evens = []
  i = 0
  while i<=100:
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
    
def PrintDictItems(dict):
    for index, (key, element) in enumerate(dict.items()):
      print(f"{index}: {key}: {element}")

"""--------------------------------------ex5---------------------------------"""
def Intersection(list1,list2):
  return [val for val in list1 if val in list2]
"""--------------------------------------ex6---------------------------------"""
def RotateLeft(list1,num_rot):
  return list1[num_rot:] + list1[:num_rot]

"""--------------------------------------main-------------------------------"""     
def main():
  
  dict = {'Tzur': ("28","RGC"), 'Andrey': ("25","PTC"), 'dummy' : ("0","IL")}
  list1 = ["value", "more value", "other value"] 
  list2 = ["first value", "sec value", "other value", "value"]
  list3 = [1,2,3,4,5] 
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
  PrintDictItems(dict)
  print(color.BOLD + "Ex5.UnionSamesValuesInTwoLists"+color.END)
  newlist = Intersection(list1,list2)
  print("list1 =\t",list1,"\n","list2 =\t",list2,"\n","new ls = ",newlist,sep="")
  print(color.BOLD + "Ex6.RotateLeft"+color.END)
  print("before:\t",list3,"\n","after:\t",RotateLeft(list3,2),sep="")
  

  
  
if __name__ == "__main__":
  main()