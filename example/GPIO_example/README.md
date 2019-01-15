
#		USING THE GPIO PINS

Clouduino uses the [Microchip MCP23S17 SPI I/O Expander Class created by Cort Buffington & Keith Neufeld](https://github.com/n0mjs710/MCP23S17).

Their implementation provides a software interface that mimics the existing Arduino I/O functions such as:

  * pinMode(pin, mode)
  * digitalWrite(pin, value)
  * digitalRead(pin)

##  Cheatsheet for GPIO pins on Clouduino

   * MCP()
   * begin()
   * pinMode()
   * pullupMode()
   * inputInvert()
   * digitalWrite()
   * digitalRead()
   * wordWrite()
   * byteWrite()
   * byteRead()


### MCP() ###

Instantiates the MCP23S17 (GPIO expander chip) as an object.

Syntax

    MCP object_name(address, slave-select)

Parameters

    object_name: any arbitrary name given to create the object
    address: address (0-7) of the device configured with address (pins A0, A1, A2)
    slave-select: No range checking! Make sure you use one that makes sense.

Returns

    none

Example

    MCP IOchip(0,5);    // create an object at address 0 called "Iochip" with SlaveSelect at GPIO pin 5 of ESP 
				        // By default Clouduino's GPIO chip is addressed to 0.




### begin() ###

Enable the SPI bus and configure the slave select pin for this object. You must call this in the Arduino void setup()function.

Syntax

    object.name.begin();

Parameters

    None

Example

    void setup() {
        IOChip.begin();
    }




### pinMode() ###

Configure pin(s) as either input or output on the selected object (device specified by an address)
        
Syntax

    object.name.pinMode(pin, mode);
    or
    object.name.pinMode(mode);

Parameters

    object_name: the name given when this object was created
    pin: the pin number (1-16) on which to set as input or output
    mode: To specify whether the pin is either a "HIGH" (1) for input (default) or a "LOW" (0) for output. If a pin is not specified, mode should be a word indicating the mode of each of the 16 I/O pins on the chip. Or simply indicate - OUTPUT or INPUT.

Returns

    none

Example 1

    void setup() {
        IOChip.pinMode(1, INPUT); // sets pin 1 as input
        IOchip.pinMode(2, OUTPUT); // sets pin 2 as an output
        IOchip.pinMode(15, HIGH); // sets pin 15 as an input
        IOchip.pinMode(16, LOW); // sets pin 16 as an output
    }

Example 2

    void setup() {
        IOchip.pinMode(0B0000111100001111); // sets pins 1-4 and 9-12 as input, 5-8 and 13-16 as output
    }




### pullupMode() ###

Configure the weak pull-up resistors on pins defined as inputs
This has no effect on pins that are configured as outputs.

Syntax

    object_name.pullupMode(pin, mode);
    or
    object_name.pullupMode(mode);

Parameters

    object_name: the name given when this object was created
    pin: the pin number (1-16) on which to enable or disable the internal weak pull-up resistor
    mode: if a pin is specified, either "HIGH" (1) to enable or "LOW" (0) to disable (default) the weak pull-up resistor on the specified pin. If a pin is not specified, mode should be a word indicating the pull-up mode of each of the 16 pins on the chip. Configuring pull-up has no effect on pins while they are configured as output.

Returns

    none

Example 1

    void setup() {
        IOchip.pullupMode(4, HIGH); // enable the pull-up on pin 4
    }

Example 2

    void setup() {
        IOchip.pullupMode(0B0000111100000000); // enable the pull-ups on pins 9-12
    }




### inputInvert() ###

Configure inversion on pins configured as inputs.
This will cause an inverted input pin to read as "LOW" (0) when it is actually in a high state, or as "HIGH" (1) when it is actually in a low state. This has no effect on pins that are configured as outputs.

Syntax

    object_name.inputInvert(pin, inversion);
    or
    object_name.inputInvert(inversion);

Parameters

    object_name: the name given when this object was created
    pin: the pin number (1-16) on which to set or clear inversion
    inversion: if a pin is specified, either "HIGH" (1) is specified to enable, or "LOW" (0) to disable (default) inversion on the specified pin. If a pin is not specified, mode should be a word indicating the inversion state of each of the 16 pins on the chip. Configuring inversion has no effect on pins while they are configured as output.

Returns

    none

Example 1

    void setup() {
        IOchip.inputInvert(4, LOW); // disable inversion on pin 4
    }

Example 2

    void setup() {
        IOchip.inputInvert(0B0000000000001111); // enable inversion on pins 1-4
    }




### digitalWrite() ###

Write a "HIGH" or "LOW" value to a digital I/O pin(s)

Syntax

    object_name.digitalWrite(pin, value);
    or
    object_name.digitalWrite(value);

Parameters

    object_name: the name given when this object was created
    pin: the pin number (1-16) who's value will be set
    value: if a pin is specified, either a "HIGH" (1) or a "LOW" (0) value may be set on the specified pin. If a pin is not specified, value should be a word indicating the output state of all 16 pins on the device. Writing pins configured as inputs has no effect.

Returns

    none

Example 1

    void loop() {
        IOchip.digitalWrite(16, HIGH); // set pin 16 to "HIGH"
    }

Example 2

    void loop() {
        IOchip.digitalWrite(0B1100000000110000); // Set 5, 6, 15 & 16 to high, 7,8, 13 & 14 to low - inputs ignored
    }




### digitalRead() ###

Reads the value of input pin(s), either "HIGH" ("1") or "LOW" ("0)

Syntax

    object_name.digitalRead(pin);
    or
    object_name.digitalRead();

Parameters

    object_name: the name given when this object was created
    pin: the pin number (1-16) whose value will be read. If no pin number is supplied, a word will be read containing the input state of all pins. The values for pins configured as output should be disregarded if the "word-mode" version is used.

Returns

    "HIGH" (1) or "LOW" (0) if a pin is supplied. a word (16 bits) is returned if no pin argument is given.

Example 1

    void loop() {
        int val;
        val = IOchip.digitalRead(4); // assigns the value of pin4 to onevalue
    }

Example 2

    void loop() {
        int val;
        val = IOchip.digitalRead(); // assigns the value of all 16 I/O pins to twovalue
    }




### wordWrite() ###

This is an advanced method to write a register pair in the MCP23S17. This class operates the MCP23S17 in "BANK=0" mode. The intention is that a registers for both ports may be written by supplying a single word as an argument. The low byte is written to the register address supplied, and the high byte to the next higher register address.

Syntax

    object_name.wordWrite(base register, value);

Parameters

    object_name: the name given when this object was created
    base register: the beginning register address to write, for example, if 0x02 is given, the low byte of "value" will be written to 0x02 and the high byte of "value" to the register at 0x03
    value: a word (unsigned int) that will be broken into two bytes and written to two consecutive registers, starting with the "base register" address

Returns

    none

Example

    void loop() {
        IOchip.wordWrite(0x12, 0xFF00); // Set GPIOA to 0x00 and GPIOB to OxFF
    }



### byteWrite() ###

This is an advanced method to write any single register in the MCP23S17.

Syntax

    object_name.byteWrite(register, value);

Parameters

    object_name: the name given when this object was created
    register: the register address to write
    value: a byte (unsigned char) that will be written to the specified registers

Returns

    none

Example

    void loop() {
        IOchip.byteWrite(0x13, 0xF0); // Set GPIOB (portB) to 0xF0 (0B11110000) 
    }




### byteRead() ###

This is an advanced method to read any single register in the MCP23S17.

Syntax

    object_name.byteRead(register);

Parameters

    object_name: the name given when this object was created
    register: the register address to be read

Returns

    unsigned char (uint8_t)

Example

    void loop() {
        int val;
        val = IOchip.byteRead(0x12); // Read GPIOA (portA)
    }
