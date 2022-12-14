#!/usr/bin/env python3




"""--------------------------------------ex1---------------------------------"""
def IsGlobal(var):
  return var in globals()


"""--------------------------------------main--------------------------------"""   
var1 = 5
def main():

  print(var1,"is global", IsGlobal(var1))

if __name__ == "__main__":
    main()