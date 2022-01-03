cmake_minimum_required(VERSION 3.17)
project(Arduino_Drivers)

set(CMAKE_CXX_STANDARD 14)

include_directories(Device)
include_directories(DigitalIn)
include_directories(DigitalOut)
include_directories(Moisture)
include_directories(TimedRelay)

add_executable(Arduino_Drivers
        Device/Device.cpp
        Device/Device.h
        DigitalIn/DigitalIn.cpp
        DigitalIn/DigitalIn.h
        DigitalOut/DigitalOut.cpp
        DigitalOut/DigitalOut.h
        Moisture/Moisture.cpp
        Moisture/Moisture.h
        TimedRelay/TimedRelay.cpp
        TimedRelay/TimedRelay.h)
