# Uploading Sketches to Clouduino #
1. Connect your Clouduino to a USB port on your computer.
    - For Windows: Find the COM Port number in the Device Manager
    - For MAC: Open terminal and type: "ls /dev/*"
    - For Linux: Open terminal and type: "ls /dev/tty*"
2. Choose Tools Menu -> Board -> "Generic ESP8266 Module" under ESP8266 Modules
    ![Tools_Settings](Tools_Settings.png)
3. Suggested Tools settings:
    - Flash Mode -> "DIO"
    - Flash Size -> “512K (no SPIFFS)”
    - Debug port -> “Disabled” 
    - Debug Level -> “None”
    - IwIP Variant -> “v2 Lower Memory”
    - Reset Method -> “ck”
    - Crystal Frequency -> “26MHz”
    - Flash Frequency -> “40MHz”
    - CPU Frequency -> “80 MHz”
    - Builtin Led -> “2”
    - Upload Speed -> “921600” (Optional, for fastest upload speed)
    - Erase Flash -> “Only Sketch”
4. Choose the correct serial port for your board.
    - Choose Tools -> Port -> comX or /dev/tty.usbmodemXXXXX. (where X marks a sequentially or randomly assigned number.
5. Click the Upload button.



