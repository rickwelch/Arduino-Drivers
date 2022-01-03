//
// Created by rick_ on 11/19/2021.
//

#include "TimedRelay.h"

#include <Arduino.h>

TimedRelay::TimedRelay(int pin): Device::Device(pin)
{
    init();
}

void TimedRelay::init() {

    String tmp = String(_pin);
    _device_name = String("TimedRelay_" + tmp);
    //Serial.println("in init(" + tmp + ") device_name=" + _device_name);
    pinMode(_pin,OUTPUT);
    digitalWrite(_pin,HIGH); // relay is low to enable so default off
}

String TimedRelay::name() {
    return _device_name;
}

/**
 * command_check is passed the target device name and an additional command. If it is for us
 * the command should be an integer greater than 0 and less than 10,001.
 *
 * @TODO - maybe allow for a max time to be defined externally
 */
bool TimedRelay::command_check(String target, String command) {
    //  Serial.print("command_check Name:");Serial.print(_device_name);Serial.print("  target:");Serial.println(target);
    if ( target == _device_name ) {
        int cmd = command.toInt();
        if (cmd > 0 && cmd < 10001) {
            digitalWrite(_pin, LOW);
            delay(cmd);
            digitalWrite(_pin, HIGH);
            return true; //String("ok"); //String("{\"" + _device_name + " status\":\"Success\"}");
        }

        return false; //String("error"); //"{\"" + _device_name + " status\":\"parameter error\"}");

    }
    return false; //String("nada");
}

String TimedRelay::device_status() {
    return "";  // is a command only device

}
