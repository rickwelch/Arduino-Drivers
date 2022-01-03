//
// Created by rick_ on 12/11/2021.
//

#ifndef WEBBRICKS_DIGITALOUT_H
#define WEBBRICKS_DIGITALOUT_H

#include "../Device/Device.h"

class DigitalOut: public Device{

private:
    String _device_name;
    String _LOW_STATE = "ON";
    String _HIGH_STATE = "OFF";
    int _current_state = HIGH;

public:
    DigitalOut(int _pin);
    void init(void);
    String name();
    String command_check(String target_device, String command);
    String device_status(void);
};

#endif //WEBBRICKS_DIGITALOUT_H
