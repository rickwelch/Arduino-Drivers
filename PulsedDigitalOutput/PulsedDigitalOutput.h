//
// Created by rick_ on 11/19/2021.
//

#ifndef WEBBRICKS_PulsedDigitalOutput_H
#define WEBBRICKS_PulsedDigitalOutput_H

#include "../Device/Device.h"

class PulsedDigitalOutput: public Device
{

private:
    String _device_name;
    int _default_state = HIGH;
    int _enabled_state = LOW;       // should be opposite of _default_state
    int _maximum_duration = 10000;  // 10 seconds in milliseconds

public:
    PulsedDigitalOutput(int pin); // : device(pin);
    void init(void);
    String name();
    String command_check(String target, String Command);
    String device_status(void);
};


#endif //WEBBRICKS_PulsedDigitalOutput_H
