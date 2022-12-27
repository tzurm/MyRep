#!/usr/bin/env python3
import basic2 
import MyPackage
import module3
from MyPackage import _foo
import sys

class color:
  BOLD = '\033[1m'
  END = '\033[0m'
  
global_var1 = "66666"

"""--------------------------------------q1----------------------------------"""
print(color.BOLD + "Q1"+color.END)
def foo(n):
  n = 4
  print("print from func",n)
  print(id(n))
n = 3
foo(n)
print("print from main",n)
print(id(n))
"""-------------------------------------"""
def foo2(n):
  n[0] = 4
  print("print from func",n)
  print(id(n))
n = [3]
foo2(n)
print("print from main",n)
print(id(n))
"""-------------------------------------"""
"""def foo3(n):
  n[0] = 4
  print("print from func",n)
  print(id(n))
n = (3,)
foo3(n)
print("print from main",n)
print(id(n))"""
def foo4():
  if x == 42:
    print("{:d} is 42".format(x))
  else:
    print("x is not 42")
x = 42
foo4()
"""-------------------------------------"""
def foo5(a = []):
  a.append(1)
  print(a)
foo5()
foo5()
"""--------------------------------------q2----------------------------------"""
print(color.BOLD + "Q2"+color.END)
def fooQ2():
  x = 5
x = 50
x+=1
fooQ2()
print(x)
"""--------------------------------------q3----------------------------------"""
print(color.BOLD + "Q3"+color.END)
def fooQ3(y):
  global x
  print(locals())
  x = 5
x = 50
fooQ3(x)
print(x)
"""-------------------------------------"""

"""--------------------------------------ex1---------------------------------"""
def IsGlobal(var):
  """print(locals())
  print(globals())"""
  return var in globals()

def _foo():
  print("pop")

"""--------------------------------------main-------------------------------"""     
def main():
  
  print(color.BOLD + "EX1"+color.END)
  print(global_var1,"is global", IsGlobal("global_var1"))
  
  print(color.BOLD + "EX2.import basic2"+color.END)
  list3 = [1,2,3,4,5] 
  print(color.BOLD + "    Ex3.CountOccurrence from basic2"+color.END)
  basic2.CountOccurrence("ttttzzzuur")
  print(color.BOLD + "    Ex6.RotateLeft from basic2"+color.END)
  print("before:\t",list3,"\n","after:\t",basic2.RotateLeft(list3,2),sep="")

  print(color.BOLD + "EX3.CreateMyPackage"+color.END)
  MyPackage.foo()  
  MyPackage.bar()
  MyPackage._bar()
  print("try _foo")
  _foo()
  module3.__staticfunc()
  
if __name__ == "__main__":
    main()
    
