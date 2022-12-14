#!/usr/bin/env python3
import sys
class color:
  BOLD = '\033[1m'
  END = '\033[0m'
  
global_var1 = 6

"""--------------------------------------q1---------------------------------"""
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
"""--------------------------------------q2---------------------------------"""
print(color.BOLD + "Q2"+color.END)
def fooQ2():
  x = 5
x = 50
x+=1
fooQ2()
print(x)
"""-------------------------------------"""
"""-------------------------------------"""

"""--------------------------------------ex1---------------------------------"""
def IsGlobal():
  return 'global_var1' in globals()

"""--------------------------------------main-------------------------------"""     
def main():
  
  print(color.BOLD + "EX1"+color.END)
  print(global_var1,"is global", IsGlobal())


if __name__ == "__main__":
    main()
    
