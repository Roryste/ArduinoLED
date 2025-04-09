#ifndef __LED_FILE_H_
#define __LED_FILE_H_

#include <string>
#include <fstream>
#include <vector>
#include <map>

class LED {
public:
    LED() = delete;
    
    /// @brief Constructor, opens the file 
    /// @param device_filename 
    LED(std::string device_filename);
    
    /// @brief Destructor, closes the file.
    ~LED();

    void turn_on();

    void write_binary_state(int led_input);

    /// @brief turn of leds
    void turn_all_off(); // This needs a definition.

private:
    std::ofstream device_file_;
    std::vector<std::string> binary_state_;
    std::map<int, std::string> binary_map_;
    //variable for LED State
};


#endif