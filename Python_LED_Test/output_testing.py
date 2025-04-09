import time
import syslog
import random

port = '/home/rcrs/Documents/output_test.txt'

f = open(port, "w")
f.write("00000000\n")
f.write("11111111\n")
time.sleep(2)

f.close()
