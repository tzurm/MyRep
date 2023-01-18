#!/usr/bin/env python3


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

