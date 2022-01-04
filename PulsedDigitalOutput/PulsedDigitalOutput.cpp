//
// Created by rick_ on 11/19/2021.
//
/**
 * @TODO - rename class to PulsedDigitalOutput
 */
#include "PulsedDigitalOutput.h"

#include <Arduino.h>

PulsedDigitalOutput::PulsedDigitalOutput(int pin): Device::Device(pin)
{
    init();
}

void PulsedDigitalOutput::init() {

    String tmp = String(_pin);
    _device_name = String("PulsedDigitalOutput_" + tmp);
    //Serial.println("in init(" + tmp + ") device_name=" + _device_name);
    pinMode(_pin,OUTPUT);
    digitalWrite(_pin,_default_state); // relay is low to enable so default off
}

String PulsedDigitalOutput::name() {
    return _device_name;
}

/**
 * command_check is passed the target device name and an additional command. If it is for us
 * the command should be an integer greater than 0 and less than 10,001.
 *
 * @TODO - maybe allow for a max time to be defined externally
 */
String PulsedDigitalOutput::command_check(String target, String command) {
    //  Serial.print("command_check Name:");Serial.print(_device_name);Serial.print("  target:");Serial.println(target);
    if ( target == _device_name ) {
        int cmd = command.toInt();
        if (cmd > 0 && cmd <= _maximum_duration) {
            digitalWrite(_pin, _enabled_state);
            delay(cmd);
            digitalWrite(_pin, _default_state);
            String command_actual = String(cmd);
            return String(",\"Command Status\":\"" + _device_name + " was enabled for " + command_actual + " milliseconds.\"");
        }
        return String(",\"Command Status\":\"Parameter error for device " + _device_name + ".\"");
    }
    return "";
}

String PulsedDigitalOutput::device_status() {
    return "";  // is a command only device

}
