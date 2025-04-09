#!/bin/bash


#To create our program, we first need to compile each file:

g++ -c LED.cpp
g++ -c main.cpp

# Then we can link them together to create a program:

g++ LED.o main.o -o led_program

