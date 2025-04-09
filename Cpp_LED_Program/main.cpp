#include <iostream>
#include "LED.h"


int main(int argc, char** argv){

    LED led("/dev/ttyACM1");
    // it will open the file it needs to.
    // ask it to turn on or off certain LED(s).#
    // e.g: led.turn_on(2);

    led.turn_on();

    led.turn_all_off();
    // test some of things you fixed.
    // when the LED object goes out of scope, it should close the.
    // file (put a close call in the destructor).

}

