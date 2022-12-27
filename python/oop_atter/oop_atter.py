#!/usr/bin/env python3
import math
import sys
class color:
  BOLD = '\033[1m'
  END = '\033[0m'

"""--------------------------------------SomeQuestion---------------------------------"""

class Dog:
    def __init__(self, breed, name):
        self.breed = breed
        self.name = name
        
    def __getattr__(self, name):
        if name == 'age':
            return 'Age not specified'
          
    def __getattribute__(self, name):
        if name == 'breed':
            print('Accessing breed attribute')
        return object.__getattribute__(self, name)
    
class Vehicle(object):
  
  kind = 'car'
  
  def __init__(self, manufacture, model):
    self.manufacture = manufacture
    self.model = model
  
  def __repr__(self):
    return "<{manu}, {model}>".format(manu=self.manufacture, modle=self.model)

"""--------------------------------------Ex1---------------------------------"""

class X(object):
  def __init__(self, a):
    self.a = a
  
  def __getattr__(self, attr):
    print(f"Attribute '{attr}' does not exist")


"""--------------------------------------Ex2---------------------------------"""

class X2(object):
  def __init__(self, a):
    self.a = a
  
  """def __setattr__(self, name ,value):
    raise AttributeError("Cannot set attribute")"""

class X3(object):
  __slots__ = ['a']
  
  def __init__(self, a):
    self.a = a
    raise AttributeError("Cannot set attribute")
    

""" for test
class X3(object):
  __slots__ = ['a','b']
  
  def __init__(self, a, b=None):
    self.a = a
    self.b = b"""

"""--------------------------------------main--------------------------------"""     
  
def main():
  """dog1 = Dog('Labrador', 'Max')
  print(dog1.name)
  print(dog1.breed)
 
  car = Vehicle("Toyota", "Corrola")
  
  print(Vehicle.__dict__)
  print("new line")
  print(car.__dict__)
  car.x = 3
  print(car.__dict__)"""
  print(color.BOLD + "Ex1"+color.END)
  print(X(1).a)
  X(1).b
  print(color.BOLD + "Ex2"+color.END)
  x = X3(1)
  print(x.a)
  x.b = 2
  print(x.b)
  
if __name__ == "__main__":
  main()