#!/usr/bin/env python3
import math
import sys
class color:
  BOLD = '\033[1m'
  END = '\033[0m'


"""--------------------------------------Ex1---------------------------------"""
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

"""--------------------------------------Ex2---------------------------------"""

"""--------------------------------------ex3---------------------------------"""

"""--------------------------------------main-------------------------------"""     
def main():
  
  print(color.BOLD + "Ex1.PointClass"+color.END)
  p1 = Point()
  p2 = Point(1.9, 2.9)
  p3 = Point(3,4)
  p4 = Point(48, 55)
  assert p1.x == 0.0
  assert p1.y == 0.0
  p1.PrintPoint()
  p2.PrintPoint()
  print(p3.DistanceFromOrigin())
  print(p4.DistanceFromOrigin())

  
  
if __name__ == "__main__":
  main()