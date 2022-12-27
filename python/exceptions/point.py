#!/usr/bin/env python3
import math
import sys
class color:
  BOLD = '\033[1m'
  END = '\033[0m'


"""
class X(object):
	def __init__(self):
		self.a = 1 
		self._a = 2
		self.__a = 3
		
	def get_the_hidden_attribute(self):
		return self.__a

	def set_the_hidden_attribute(self, value):
		self.__a = value
  
	def del_the_hidden_attribute(self):
  		del self.__a
"""
"""Approved by Arie"""

"""--------------------------------------Ex1---------------------------------"""
class Point:
    """Represent a point."""

    """Initialize the point with coordinates (x, y)."""
    def __init__(self, x = 0.0, y = 0.0):
      if type(x) not in (int, float) or type(y) not in (int, float):
            print("Error: Point coordinates must be numbers.")
            raise TypeError
      self.__x = x
      self.__y = y
    
    def Get_x(self):
      return self.__x
          
    def Get_y(self):
      return self.__y
      
    def Set_x(self, value):
      if not isinstance(value, (int,float)):
            raise TypeError("Name must be a num")
      self.__x = value
      
    def Set_y(self, value):
      if not isinstance(value, (int,float)):
            raise TypeError("Name must be a num")
      self._y = value
    
    x = property(Get_x, Set_x)
    y = property(Get_y, Set_y)
    
"""--------------------------------------Ex2---------------------------------"""
class Property:
  def __init__(self, fget=None, fset=None, fdel=None):
    self.fget = fget
    self.fset = fset
    self.fdel = fdel

  def __get__(self, instance, owner):
    if instance is None:
      return self
    if self.fget is None:
      raise AttributeError("unreadable attribute")
    return self.fget(instance)

  def __set__(self, instance, value):
    if self.fset is None:
      raise AttributeError("can't set attribute")
    self.fset(instance, value)

  def __delete__(self, instance):
    if self.fdel is None:
      raise AttributeError("can't delete attribute")
    self.fdel(instance)
    
  def Setter(self, fset):
      self.fset = fset
      return self

  def Deleter(self, fdel):
    self.fdel = fdel
    return self
    
class X(object):
  def __init__(self, val):
    self.__x = int(val)
    
  @Property
  def x(self):
    return self.__x
  
  @x.Setter
  def x(self, val):
    self.__x = int(val)
    
  @x.Deleter
  def x(self):
    del self.__x
    
 
"""--------------------------------------main--------------------------------"""     
  
def main():

  print(color.BOLD + "Ex1.PointClassAtter"+color.END)
  p1 = Point()
  print(p1.x)
  p1.x = 10
  print(p1.x)
  
  print(color.BOLD + "Ex2.ClassX"+color.END)
  a = X(0)
  print (a.x)
  a.x = 1
  print (a.x)
  del a.x
  
"""
  x= X()
  print(x.a)
  print(x._a)
  print(x._X__a)
  x._X__a = 4
  print(x._X__a)
  print(x.get_the_hidden_attribute())
  x.set_the_hidden_attribute(5)
  print(x.get_the_hidden_attribute())
  x.del_the_hidden_attribute()
  print(x.a)
  print(x._a)"""
 
  
if __name__ == "__main__":
  main()