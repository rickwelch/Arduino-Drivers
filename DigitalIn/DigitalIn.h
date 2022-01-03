//
// Created by rick_ on 11/15/2021.
//

#ifndef WEBBRICKS_DIGITALIN_H
#define WEBBRICKS_DIGITALIN_H

#include "../Device/Device.h"

class DigitalIn: public Device
{
private:
    String _device_name;
    String _LOW_STATE = "OK";
    String _HIGH_STATE = "FAULT";

public:
    DigitalIn(int pin);
    void init(void);
    String name();
    String command_check(String target, String command);
    String device_status(void);
};


#endif //WEBBRICKS_DIGITALIN_H
