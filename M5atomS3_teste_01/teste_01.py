import os, sys, io
import M5
from M5 import *
import time

def setup():
  M5.begin()

def loop():
  M5.update()
  # change the display color
  Widgets.fillScreen(0xff6600)

  for i in range(0, 256, 10):
    # change the display brightness
    Widgets.setBrightness(i)

    # something like a "delay" of 1 sec
    time.sleep(1)


if __name__ == '__main__':
  try:
    setup()
    while True:
      loop()
  except (Exception, KeyboardInterrupt) as e:
    try:
      from utility import print_error_msg
      print_error_msg(e)
    except ImportError:
      print("please update to latest firmware")