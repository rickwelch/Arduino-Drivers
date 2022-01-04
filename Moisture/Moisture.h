//
// Created by rick_ on 11/19/2021.
//

#ifndef WEBBRICKS_MOISTURE_H
#define WEBBRICKS_MOISTURE_H

#include "../Device/Device.h"

class Moisture: public Device
{
private:
    String _device_name;

public:
    Moisture(int pin);
    void init(void);
    String name();
    String command_check(String target, String command);
    String device_status();
};

#endif //WEBBRICKS_MOISTURE_H
