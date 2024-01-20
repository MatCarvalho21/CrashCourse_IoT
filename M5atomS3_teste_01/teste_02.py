import os, sys, io
import M5
from M5 import *

# declare the two variables of the code
label0 = None
i = None


def setup():
  global label0, i
  M5.begin()
  i = 0


def loop():
  global label0, i

  #change the color of the screen (actually that is a trick made for clean the screen)
  Widgets.fillScreen(0xff6600)

  #set a label, but with the width controled by the variable i
  label0 = Widgets.Label("Matheus", i, 51, 1.0, 0xffffff, 0xff6600, Widgets.FONTS.DejaVu18)
  
  #delay of 500ms
  time.sleep(0.5)
  
  #control of the value of the varible, that increase until 130 and after that become -80 and the loop continues
  i += 10
  if i > 130:
    i = -80

    #this simple code is my first contact with the M5AtomS3 and all the funcinalities around


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