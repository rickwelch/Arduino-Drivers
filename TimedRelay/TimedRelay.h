//
// Created by rick_ on 11/19/2021.
//

#ifndef WEBBRICKS_TIMEDRELAY_H
#define WEBBRICKS_TIMEDRELAY_H

#include "../Device/Device.h"

class TimedRelay: public Device
{

private:
    String _device_name;

public:
    TimedRelay(int pin); // : device(pin);
    void init(void);
    String name();
    bool command_check(String target, String Command);
    String device_status(void);
};


#endif //WEBBRICKS_TIMEDRELAY_H
