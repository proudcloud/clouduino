# Uploading Sketches to Clouduino using Arduino IDE #
1. Enter Flash mode by toggling the switch to "Flash mode" the first 3 seconds upon connecting Clouduino to a USB port on your device. This mode allows sketches to be uploaded to your Clouduino. (For testers: Toggle switch for perfboard prototype, OMRON switch for PCB)
2. Check the Port number designated to your Clouduino.
    - For Windows: Find the COM Port number in the Device Manager
    - For MAC: Open terminal and type: "ls /dev/*"
    - For Linux: Open terminal and type: "ls /dev/tty*"
3. Choose Tools Menu -> Board -> "Generic ESP8266 Module" under ESP8266 Modules
    ![Tools_Settings](Tools_Settings.png)
4. Suggested Tools settings:
    - Flash Mode -> "DIO"
    - Flash Size -> “512K (no SPIFFS)”
    - Debug port -> “Disabled” 
    - Debug Level -> “None”
    - IwIP Variant -> “v2 Lower Memory”
    - Reset Method -> “ck”
    - Crystal Frequency -> “26MHz”
    - Flash Frequency -> “40MHz”
    - CP U Frequency -> “80 MHz”
    - Builtin Led -> “2”
    - Upload Speed -> “921600” (Optional, for fastest upload speed)
    - Erase Flash -> “Only Sketch”
5. Choose the correct serial port for your board.
    - Choose Tools -> Port -> comX or /dev/tty.usbmodemXXXXX. (where X marks a sequentially or randomly assigned number.
6. Click the Upload icon.

Note: Enter Normal mode by toggling the switch to "Normal mode" then press Reset button.  This is to run your program after flashing a program on your clouduino.

#  Debugging and Troubleshooting #
Failed upload is a common issue with programming ESP8266, (eg: "espcomm_sync failed" error), when encountered please try the following methods:
 - Toggle switch to Flash mode then press reset button.
 - Check if powersupply is sufficient, VCC pin should receive a stable 3.3V. Any lower than 2.9V supplied power causes upload to fail nor would the Clouduino function properly even on normal mode.
 - Use a very short USB cable as much as possible. Very long cables to tend fail UART communication due to delay induced by excess cable length.

Doublecheck your code:
 - Make sure to include SPI.h for anything involving GPIO or ADC pin applications
 - Don't forget to include MCP23S17.h if utilizing GPIO pins, and MCP3208.h for analog reading. 