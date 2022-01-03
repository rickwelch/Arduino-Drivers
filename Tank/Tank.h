//
// Created by rick_ on 1/1/2022.
//

#ifndef WEBBRICKS_UNO_WIFI_TANK_H
#define WEBBRICKS_UNO_WIFI_TANK_H

#include "../Device/Device.h"

class Tank: public Device {
private:
    String _device_name;
    String _LOW_STATE = "OK";
    String _HIGH_STATE = "LOW";

public:
    Tank(int pin);
    void init(void);
    String name();
    String command_check(String target, String command);
    String device_status(void);
};


#endif //WEBBRICKS_UNO_WIFI_TANK_H
