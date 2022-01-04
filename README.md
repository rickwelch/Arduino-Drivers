Built within the PlatformIO framework, this development library of Arduino device drivers is part of an
Arduino web (html) service provider project. Each device class supports a specific I/O device or I/O function
and requires four methods described below.

## Included drivers

- Device
    - Base class for all device drivers.
    - Is instantiated with an argument _pin which usually means the IO pin but could really be anything
    - Derived classes must contain 4 methods
        - init() - initializes the device on powerup
        - name() - returns the name of the device, usually class name plus the pin, ie pump_3 or tank_1
        - status() - returns information from the device
        - command_check(device_name,command) - when a command is sent, the code loops through the array of devices and calls this method. If current device is the target_device, the action is taken.
        
- DigitalIn
    - Reads a digital input
    - To be used as a starting point for your device, copy and rename to reflect device
    - Abstracts device status in each state, on, off, OK, fault, etc.
    - Methods
        - init() - sets the _pin to INPUT mode with a pull-up resistor
        - name() - returns DigitalIn_{_pin}
        - status() - returns string "Digital_1":"1 for HIGH, 0 for LOW"
        - command_check() - returns empty string, read only device
        
- DigitalOut
    - Sets the state HIGH or LOW of an output pin
    - To be used as a starting point for your device, copy and rename to reflect device
    - Abstracts device status in each state, on, off, OK, fault, etc.
    - Methods
        - init() - sets the _pin to OUTPUT mode
        - name() - returns DigitalOut_{_pin}
        - status() - returns string "DigitalOut_1":"current state of the output, 1 or 0"
        - command_check(target_device,command) - If device is the target set _pin to HIGH if command=1 or to LOW if command=0

- AnalogIn _(planned)_
    - Reads input from an analog _pin
    - Methods
   
- AnalogOut _(planned)_
    - Performs an analogWrite to _pin

- Moisture
    - Returns analog value (0-1023) from Capacitive Soil Moisture Sensors. 
    - Will be the basis for the AnalogIn driver.   
    
- PulsedDigitalOut
    - Sets a digital output for a passed period of time in milliseconds    
        
## Writing your own drivers

If you can use one of the above drivers you should copy it and name it something the driver represents, like Tank or Pump.

If you need something custom, your driver should use Driver as a base class and must containe the four methods described above.

Both status() and command_check() methods return a String. This string must be proper JSON and start with a comma. In the project's include folder an array of drivers is set up and these methods are called in sequence. Output from each method concatenated on to the return JSON string

The command_check(target,arguments) method should check target and if it is your devices name, then parse the arguments and do some action. Return any success or failure information in proper JSON format. 

should return a string in the following format
```
, "Command Status":" < your success or error message or data goes here> "
``` 
The status() command should return a string in the following format
```
, " < your device name > ":" < whatever status in proper JSON format > "
```
