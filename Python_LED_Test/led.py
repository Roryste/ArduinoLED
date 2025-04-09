#!/usr/bin/env python3

# 4. I'll need to get hold of a network receiver and give you some info on how to
# receive and understand the data on the network. The idea being that the state
# of a disk will be received from the network and this will be interpreted, then
# LEDs will be updated. We can have a chat if you get this far and specify how
# this works and look at where to start.

import time
import syslog
import random

port = '/dev/ttyACM0'
s = list("00000000")

#def errorHandle(bString):
#    if len(bString) >=9 or len(bString) <= 7:
#        print("The input given is too short/long\n")
#        return True
#    for x in bString:
#        if x != '0' and x != '1':
#            print("The input given contains one or more non binary characters\n")
#            return True
#    return False


for x in range(0,10):
    for i in range(len(s)):
        s[i] = '1'
        if (x % 2) == 1:
            a = "".join(reversed(s))
        elif (x % 2) == 0:
            a = "".join(s)
        f = open(port, "w")
        f.write(a)
        f.close()
        time.sleep(.02)
        s[i] = '0'

f = open(port, "w")
f.write("00000000")
f.close()

#Breaking Arduino code

#1 Any string longer than 9 characters
#2 Writing more than once to the file before closing

print("Break Test Start")
r = input("Enter the byte to display: \n")
#while errorHandle(r):
#    r = input("Enter the byte to display: \n")
f = open(port, "w")
f.write(r)
f.close()
time.sleep(2)
print("Break Test Finished")


#Test if broken
print("Test if still broken")
f = open(port, "w")
f.write("00100001")
f.write("00111111")
time.sleep(2)
f.close()
time.sleep(1)
f = open(port, "w")
f.write("00000000")
f.close()

for x in range(0,10):
    for i in range(len(s)):
        s[i] = '1'
        if (x % 2) == 1:
            a = "".join(reversed(s))
        elif (x % 2) == 0:
            a = "".join(s)
        f = open(port, "w")
        f.write(a)
        f.close()
        time.sleep(.02)
        s[i] = '0'

f = open(port, "w")
f.write("00000000")
f.close()

