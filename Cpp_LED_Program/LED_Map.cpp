#include "LED.h"

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <vector>
#include <map>
using namespace std;

LED::LED(std::string device_filename){
    //initialise variable
    std::string binary_output;
    for(int i = 1; i <=8; i++){
        binary_map_[i] = "0";
    }

    device_file_;
    device_file_.open(device_filename);
    device_file_ << "11111111" << std::endl;
    usleep(2000000);

    for (int j = 1; j <=8; j++){
        binary_output += binary_map_[j];
    }
    std::cout << binary_output << std::endl;

    device_file_ << binary_output << std::endl;
    device_file_.flush();

    usleep(2000000);
    // open the file.
}

LED::~LED(){
    // This is called at the end of the scope of LED so is not called in this order
    // Close the file.
}

void LED::write_binary_state(int led_input){
    std::string check_string;

    if(binary_map_[led_input] == "0"){
        binary_map_[led_input] = "1";
    }
    else if(binary_map_[led_input] == "1"){
        binary_map_[led_input] = "0";
    }

    for (int j = 1; j <=8; j++){
        check_string += binary_map_[j];
    }
    device_file_ << check_string << std::endl;
    device_file_.flush();
    std::cout << "Updated LED" << std::endl;
}

void LED::turn_on(){
    int x;
    std::string check_string;
    
    std::cout << "Please enter LED number (1-8) to turn on/off LED: " << std::endl;
    cin >> x;

    while((x >= 1) && (x <= 8)){
        write_binary_state(x);
        std::cout << "Please enter LED number (1-8): " << std::endl;
        cin >> x;
    }
    
    //take in the user input from here and change the state of the vector depending on input
}

void LED::turn_all_off(){
    device_file_ << "00000000" << std::endl;
    device_file_.flush();
    std::cout << "Ran turn all off function..." << std::endl;

}
