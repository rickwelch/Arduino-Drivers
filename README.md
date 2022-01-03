## Included drivers

- Device
    - Base class for all device drivers.
    - Is instantiated with an argument _pin which usually means the IO pin but could really be anything
    - Derived classes must contain 4 methods
        - init() - initializes the device on powerup
        - name() - returns the name of the device, class + _pin  ie if _pin=1: device_1
        - status() - returns information from the device
        - command_check(device_name,command) - when a command is sent, the code loops through the array of devices and calls this method. If current device is the target_device, the action is taken.
        
- DigitalIn
    - Reads a digital input
    - Methods
        - init() - sets the _pin to INPUT mode with a pull-up resistor
        - name() - returns DigitalIn_{_pin}
        - status() - returns string "Digital_1":"1 for HIGH, 0 for LOW"
        - command_check() - returns empty string, read only device
        
- DigitalOut
    - Sets the state HIGH or LOW of an output pin
    - Methods
        - init() - sets the _pin to OUTPUT mode
        - name() - returns DigitalOut_{_pin}
        - status() - returns string "DigitalOut_1":"current state of the output, 1 or 0"
        - command_check(target_device,command) - If device is the target set _pin to HIGH if command=1 or to LOW if command=0

- AnalogIn
    - Reads input from an analog _pin
    - Methods
   
- AnalogOut
    - Performs an analogWrite to _pin

- Moisture
    - Returns an an        
        
## Writing your own drivers

