#!/usr/bin/env python3

import sys
class color:
  PURPLE = '\033[95m'
  CYAN = '\033[96m'
  DARKCYAN = '\033[36m'
  BLUE = '\033[94m'
  GREEN = '\033[92m'
  YELLOW = '\033[93m'
  RED = '\033[91m'
  BOLD = '\033[1m'
  UNDERLINE = '\033[4m'
  END = '\033[0m'

"""--------------------------------------q1----------------------------------"""
def PrintHelloWorld():
  print("Hello World!")

"""--------------------------------------q2----------------------------------"""
def MaxValue():
  max_int = sys.maxsize
  result = max_int
  print(result)

  
"""--------------------------------------q4----------------------------------"""
def CheckInRangeOneLine(num):
  print(num,"is in the range 1 to 10") if num in range(1, 10) else None


"""--------------------------------------ex1---------------------------------"""
def IsEven(num):
  if (num % 2) == 0:
    print(num , "is even")
  else:
    print(num , "not even")
"""--------------------------------------ex2---------------------------------"""
def PrintMultiString(string, num = 1):
  print(string * num)
"""--------------------------------------ex3---------------------------------"""
def IsYearLeap(year):
  if year % 4 == 0 and (year % 100 != 0 or year % 400 == 0):
    print(year , ",this year is leap")
  else:
    print(year , ",this year is not leap")
    
"""--------------------------------------ex4---------------------------------"""
def IsInt(num):
  return type(num) == int

"""--------------------------------------ex5---------------------------------"""
def FlipInt(num):
  print ((str(num)[::-1]))

"""--------------------------------------ex6---------------------------------"""
def GradeToLetter(grade):
    if grade >= 90:
        return "A"
    elif grade >= 70:
        return "B"
    elif grade >= 50:
        return "C"
    elif grade >= 10:
        return "D"
    else:
        return "F"

"""--------------------------------------ex7---------------------------------"""
def Factorial(num:int) -> int:
  if num == 0:
    return 1
  else:
    return num * Factorial(num-1)
  
"""--------------------------------------main-------------------------------"""     
def main():
  num1 = 10
  num2 = 13
  num3 = 5
  print(color.BOLD + "Q1"+color.END)
  PrintHelloWorld()
  print(color.BOLD + "Q4"+color.END)
  CheckInRangeOneLine(num1)
  CheckInRangeOneLine(num3)
  print(color.BOLD + "Q14"+color.END)
  MaxValue()
  print(color.BOLD + "Ex1.IsEven"+color.END)
  IsEven(num1)
  IsEven(num2)

  print(color.BOLD + "Ex2.PrintMultiString"+color.END)
  str_my_name = 'tzur '
  PrintMultiString(4,str_my_name)
  PrintMultiString(str_my_name)

  print(color.BOLD + "Ex3.IsYearLeap"+color.END)
  IsYearLeap(1994)
  IsYearLeap(2023)
  IsYearLeap(2024)

  print(color.BOLD + "Ex4.IsInt"+color.END)
  print(num1, "is",IsInt(num1))
  max_int = "pop"
  print(max_int, "is",IsInt(max_int))
  
  print(color.BOLD + "Ex6.Translate"+color.END)
  print("30 is", GradeToLetter(30))
  print("88 is", GradeToLetter(88))
  print("100 is", GradeToLetter(99))
  
  print(color.BOLD + "Ex7.Factorial"+color.END)
  print("Factorial of",num1,"is",Factorial(num1))
  
  print(color.BOLD + "Ex5.FlipInt"+color.END)
  FlipInt(123456)
  FlipInt("123456")
  
if __name__ == "__main__":
  main()