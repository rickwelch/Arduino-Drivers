//
// Created by rick_ on 11/19/2021.
//

#include "Moisture.h"

#include <Arduino.h>

Moisture::Moisture(int pin) : Device::Device(pin)
{
    init();
}

void Moisture::init() {
    String tmp = String(_pin);
    _device_name = String("moisture_" + tmp);
}

String Moisture::name() {
    return _device_name;
}

bool Moisture::command_check(String target, String command) {
    return false;  // this device is read only
}

String Moisture::device_status() {
    int A = analogRead(_pin);
    return String(",\"" + _device_name + "\":\"" + String(A) + "\"");
}
