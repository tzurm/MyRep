#!/usr/bin/env python3

var2 = 5


"""--------------------------------------ex1---------------------------------"""
def IsGlobal(var):
  return var in globals()

"""--------------------------------------main-------------------------------"""     
def main():

  var1 = 5
  print(var1,"is global", IsGlobal(var1))
  print(var2,"is global", IsGlobal(var2))


if __name__ == "__main__":
    main()