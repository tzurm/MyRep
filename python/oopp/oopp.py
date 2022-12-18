#!/usr/bin/env python3
import math
import sys
class color:
  BOLD = '\033[1m'
  END = '\033[0m'



class X(object):
	"""Example class"""
	def __init__(self):
		"""init function for class X"""
		self.a = 1 
		self._a = 2
		self.__a = 3
		
	def get_the_hidden_attribute(self):
		return self.__a

	def set_the_hidden_attribute(self, value):
		self.__a = value
  
	def del_the_hidden_attribute(self):
  		del self.__a

"""--------------------------------------Ex1-3-------------------------------"""
class Point:
    """Represent a point."""

    """Initialize the point with coordinates (x, y)."""
    def __init__(self, x=0.0, y=0.0):
      if type(x) not in (int, float) or type(y) not in (int, float):
            print("Error: Point coordinates must be numbers.")
            raise TypeError
      self.x = x
      self.y = y
    
    def DistanceFromOrigin(self):
        return math.hypot(self.x, self.y)
    
    def PrintPoint(self):
      print("(", self.x, ",", self.y,")")  


"""--------------------------------------main--------------------------------"""     
def main():
  
  print(color.BOLD + "Ex1.PointClass"+color.END)
  p1 = Point()
  p2 = Point(1.9, 2.9)
  p3 = Point(3,4)
  p4 = Point(20, 55)
  
  p1.PrintPoint()
  p2.PrintPoint()
  print(p3.DistanceFromOrigin())
  print(p4.DistanceFromOrigin())
  
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
  print(x._a)
  print(x._X__a)
  
if __name__ == "__main__":
  main()