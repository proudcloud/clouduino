
#		USING THE ADC PINS

Clouduino uses [Microchip 2.7V 8-Channel 12-Bit A/D Converters with SPI Serial Interface](https://github.com/labfruits/mcp3208) providing it the following features to perform analog to digital conversion:

  * 12-bit resolution
  * 8 input channels
  * Analog inputs programmable as single-ended or pseudo-differential pairs
  * Fixed 3.3V Single supply operation
  * Fixed 3.3V Reference voltage

## Cheatsheet for ADC pins on Clouduino: 
   * Channels
   * MCP3208()
   * pinMode()
   * digitalWrite()
   * digitalRead()
   * read()
   * testSplSpeed()
   * toAnalog()
   * toDigital()
   * getVref()
   * getAnalogRes()




### Channels      

    SINGLE_0 = 0b1000,      // single channel 0 
    SINGLE_1 = 0b1001,      // single channel 1 
    SINGLE_2 = 0b1010,      // single channel 2 
    SINGLE_3 = 0b1011,      // single channel 3 
    SINGLE_4 = 0b1100,      // single channel 4 
    SINGLE_5 = 0b1101,      // single channel 5 
    SINGLE_6 = 0b1110,      // single channel 6 
    SINGLE_7 = 0b1111,      // single channel 7 

    DIFF_0PN = 0b0000,      // differential channel 0 (input 0+,1-) 
    DIFF_0NP = 0b0001,      // differential channel 0 (input 0-,1+)
    DIFF_1PN = 0b0010,      // differential channel 1 (input 2+,3-) 
    DIFF_1NP = 0b0011,      // differential channel 1 (input 2-,3+) 
    DIFF_2PN = 0b0100,      // differential channel 2 (input 4+,5-) 
    DIFF_2NP = 0b0101,      // differential channel 2 (input 5-,5+) 
    DIFF_3PN = 0b0110,      // differential channel 3 (input 6+,7-) 
    DIFF_3NP = 0b0111       // differential channel 3 (input 6-,7+) 


### MCP3208() ###

Initiates MCP3208 object. The chip select pin must be already configured as output. The default SPI interface will be used for communication.

Syntax

    MCP3208(uint16_t vref, uint8_t csPin);

Parameters

    vref:   ADC reference voltage in mV. Fixed at 3.3V for Clouduino.
    csPin:  pin number to use for chip select. Fixed at GPIO pin 16 for Clouduino.

Returns    

    none

Example

    MCP3208 adc(3300, 16);    //3.3V Vref with SPI slave select at pin 16 




### read() ###

Reads the supplied channel. The SPI interface must be initialized and put in a usable state before calling this function.

Syntax

    read(Channel ch);

Parameter    

    ch: defines the channel to read from.

Returns

    The converted raw value.

Example 1

    sensor1_val = adc.read(MCP3208::SINGLE_0); //Read Single channel 0 of MCP3208

Example 2

    sensor2_val = adc.read(MCP3208::DIFF_0NP); //Read differential channel 0 (input 0+,1-)

Example 3

    sensor3_val = adc.read(MCP3208::0b0001);  // differential channel 0 (input 0-,1+))




### testSplSpeed() ###

Performs a sampling speed test. The SPI interface must be initialized and put in a usable state before calling this function.

Syntax

    testSplSpeed(Channel ch, uint16_t num);

Parameters

    ch:     the channel to use for the speed test.
    num:    the number of reads to perform.

Returns

    The average sampling time needed for one read in us.

Example

    uint16_t speed = testSplSpeed(SINGLE_0, 3);




### toAnalog() ###

Converts the supplied raw value to an analog value in mV based on the defined reference voltage.

Syntax

    toAnalog(uint16_t raw);

Parameter

    raw: the sampled ADC value.

Returns

    The converted analog value in mV.

Example

    uint16_t raw = adc.read(MCP3208::SINGLE_0);
    uint16_t val = toAnalog(raw);




### toDigital() ###

Converts the supplied analog value to the digital representation based on the defined reference voltage.

Syntax

    toDigital(uint16_t val);

Parameter

    val: the analog value in mV.

Returns

    The digital representation off the supplied analog value.

Example

    uint16_t raw = adc.read(MCP3208::SINGLE_0);
    uint16_t val = toAnalog(raw);
    uint16_t lvl = toDigital(val);




### getVref() ###

Returns the reference voltage.

Syntax

    getVref();

Parameters

    none

Returns 

    The configured reference voltage in mV.

Example

    ref = getVref();




### getAnalogRes() ###

    Returns the analog resolution in µV based on the defined reference voltage.

Syntax

    getAnalogRes();

Parameters

    none

Returns    

    The analog resolution in µV.

Example

    uint16_t res = getAnalogRes();
