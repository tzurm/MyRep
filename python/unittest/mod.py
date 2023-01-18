#!/usr/bin/env python3

def is_even(number):
  try:
      return number % 2 == 0
  except TypeError:
        raise TypeError, "number needs to be a number"