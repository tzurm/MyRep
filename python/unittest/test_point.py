#!/usr/bin/env python3
import unittest
import math
import point as Point

class TestPoint(unittest.TestCase):
  def test_initialization(self):
    # Test that a point can be initialized with valid coordinates
    p1 = Point(1, 2)
    self.assertEqual(p1.x, 1)
    self.assertEqual(p1.y, 2)

    # Test that a point cannot be initialized with invalid coordinates
    with self.assertRaises(TypeError):
        p2 = Point("a", "b")
        
  def test_distance_from_origin(self):
      # Test that the distance from the origin is calculated correctly
      p1 = Point(1, 1)
      self.assertAlmostEqual(p1.DistanceFromOrigin(), math.sqrt(2))

      # Test that the distance from the origin is calculated correctly for negative coordinates
      p2 = Point(-1, -1)
      self.assertAlmostEqual(p2.DistanceFromOrigin(), math.sqrt(2))

  def test_print_point(self):
      # Test that the PrintPoint method prints the correct output
      p1 = Point(1, 2)
      self.assertEqual(p1.PrintPoint(), "( 1 , 2 )")
  
  def test_failure(self):
      # This test is meant to fail
      p = Point(3, 4)
      self.assertEqual(p.x, 4)

if __name__ == "__main__":
  unittest.main()