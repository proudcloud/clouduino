# Getting Started with Clouduino Stratus #
This document explains how to connect your Clouduino board to the computer and upload your first sketch. 

- Clone or download the Clouduino Github repository 
- Use your Clouduino Stratus on the Arduino Desktop IDE
- Install the board drivers and other library dependencies
- Open your first sketch
- Select the board type and port
- Upload the program
- Sample Projects and Tutorials

## Clone or download the Clouduino Github repository ##
To get started, you must first clone or download then unzip the [Clouduino repository](https://github.com/proudcloud/clouduino).
    ![clouduino_repo](/docs/images/github.PNG)

## Use your Clouduino Stratus on the Arduino Desktop IDE ##
If you want to program your Clouduino Stratus then you will need to install the [Arduino Desktop IDE](https://www.arduino.cc/en/Main/Software). To connect the Clouduino Stratus to your computer, you’ll need a Mini-B USB cable. This also provides power to the board. 

## Install the board drivers and other library dependencies ##

Let's start with installing the ESP8266 board driver with boards manager in Arduino IDE. 

1. Start Arduino. Click on File menu then select Preferences.
2. Enter `http://arduino.esp8266.com/stable/package_esp8266com_index.json` into Additional Board Manager URLs field. You can add multiple URLs, separating them with commas. 
    
3. Open Boards Manager from Tools > Board menu and install the latest stable esp8266 platform 
    ![boards_manager](/docs/images/boards_manager.png)
4. Go to Tools again >  Board > Select Generic ESP8266 Module.
    ![choosing_board](/docs/images/choosing_board.png)
    - ESP8266 Arduino core documentation [link](https://arduino-esp8266.readthedocs.io/en/2.4.2/).
    - ESP8266 Arduino core github [link](https://github.com/esp8266/Arduino)
 
There are two essential libraries you must install for Clouduino: [MCP23S17](https://github.com/n0mjs710/MCP23S17) for controlling GPIO pins and [MCP3208](https://github.com/labfruits/mcp3208) for controlling ADC pins. 
You have to import these libraries to Arduino IDE by simply following the steps below:

1. First download these libraries as ZIP file. No need to unzip, leave it as it is.
    - [MCP23S17](https://github.com/n0mjs710/MCP23S17)  - GPIO Expander
    - [MCP3208](https://github.com/labfruits/mcp3208)   - ADC Expander
2. In the Arduino IDE, navigate to Sketch menu > Include Library > Add .ZIP Library > Select Add .ZIP Library > Find and open MCP3208-master ZIP file.
3. Repeat step 2 for MCP23S17-master ZIP file.
   
Note that you only have to install the ESP8266 board driver and the two essential libraries once. Do, however, check for library updates often at the library manager

## Open your first sketch ##
You are now ready to try out your first sketch in Arduino IDE.
 1.  Open File menu > Go to Clouduino folder directory > example folder > Blink folder > Open Blink.ino
 2.  Under example/Blink folder, you will see a breadboard and schematic for Blink, showing a circuit with Clouduino connected to an LED - Assemble the circuit.

Blink LED circuit - Breadboard:
    ![Blink_Breadboard](/example/Blink/Blink_fritzing_Breadboard.PNG)
Blink LED circuit - Schematics:
    ![Blink_Schematics](/example/Blink/Blink_fritzing_Schem.PNG)

## Upload your first sketch 

1. Enter Flash mode by toggling the switch to "Flash mode" for the first 3 seconds of connecting Clouduino to a USB port on your device. This mode allows sketches to be uploaded to your Clouduino. (For testers: Toggle switch for perfboard prototype, OMRON switch for PCB)
2. Check the Port number designated to your Clouduino.
    - For Windows: Find the COM Port number in the Device Manager
    - For MAC: Open terminal and type: "ls /dev/*"
    - For Linux: Open terminal and type: "ls /dev/tty*"
3. Choose Tools Menu -> Board -> "Generic ESP8266 Module" under ESP8266 Modules
    ![choosing_board](/docs/images/choosing_board.png)
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

    ![tools_settings](/docs/images/tools_settings.png)
5. Choose the correct serial port for your board.
    - Choose Tools -> Port -> comX or /dev/tty.usbmodemXXXXX. (where X marks a sequentially or randomly assigned number.
6. Click the Upload icon.

Note: Enter Normal mode by toggling the switch to "Normal mode" then press Reset button.  This is to run your program after flashing a program on your clouduino.

##  Debugging and Troubleshooting ##
Failed upload is a common issue with programming ESP8266, (eg: "espcomm_sync failed" error), when encountered please try the following methods:
 - Toggle switch to Flash mode then press reset button.
 - Check if powersupply is sufficient. VCC pin should receive a stable 3.3V. Any lower than 2.9V supplied power causes upload to fail nor would the Clouduino function properly even on normal mode.
 - Use a very short USB cable as much as possible. Very long cables to tend fail UART communication due to delay induced by excess cable length.
  
 Double-check your code:
 - Make sure to always include SPI.h for anything involving GPIO or ADC pin applications to enable slave select on ESP.
 - Don't forget to include MCP23S17.h if utilizing GPIO pins, and MCP3208.h for analog reading and conversion using analog pins.

## Sample Projects and Tutorials ##
Now that you have set up and programmed your Clouduino Stratus, you may learn more ideas on how to control your Stratus by trying other sample sketches at [example](https://github.com/proudcloud/clouduino/tree/master/example) folder such as controlling GPIO pins and doing analog reading using ADC pins. Hopefully these would give you insights and inspiration while exploring possibilities with Stratus.
 - Blinky - A sketch that uses all 16 available GPIO pins of Clouduino Stratus to blink LEDs.
 - ADC test LDR - A sketch that demonstrates Analog reading and analog to digital conversion using LDR (Light Dependent Resistor). 
- Clouduino Webserver LEDs - A sketch for creating a webserver on Clouduino to control two LEDs remotely.
- Painless Mesh - A sketch that demonstrates pseudo-mesh networking with Clouduino. (Requires two or more ESP’s or Clouduino boards)
