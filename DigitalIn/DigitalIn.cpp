//
// Created by rick_ on 11/15/2021.
//

#include "DigitalIn.h"

#include <Arduino.h>

DigitalIn::DigitalIn(int pin): Device::Device(pin)
{
    init();
}

void DigitalIn::init() {
    String tmp = String(_pin);
    _device_name = String("DigitalIn_" + tmp);
    pinMode(_pin,INPUT_PULLUP);
}

String DigitalIn::name() {
    return _device_name;
}

String DigitalIn::command_check(String target, String command) {
    return "";    // read only device
}

String DigitalIn::device_status() {
    int state = digitalRead(_pin);
    if(state == LOW){
        return String(",\"" + _device_name + "\":\"" + _LOW_STATE + "\"");
    }
    return String(",\"" + _device_name + "\":\"" + _HIGH_STATE + "\"");
}
