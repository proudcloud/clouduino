# Webserver with Clouduino Stratus ##

In this project you’ll create a standalone web server with Clouduino Stratus that can toggle two LEDs using Arduino IDE. This Web server is mobile responsive and it can be accessed with any device that as a browser in your local network. This tutorial is derived from [ESP822 Webserver with Arduino IDE](https://randomnerdtutorials.com/esp8266-web-server-with-arduino-ide/).

### Follow these steps:

-  Assemble the circuit based from the Fritzing schematic or breadboard.
-  Upload the Clouduino_Webserver_LEDs sketch to Clouduino. 
-  Open the Arduino serial monitor at a baud rate of 115200.
-  Press Reset button. After a few seconds your IP address should appear.
-  
![ip-address](/docs/images/clouduino-ip-address.png)

### Demonstration
For the final demonstration open any browser from a device that is connected to the same router that your ESP is. Then type the IP address and click Enter!

![webserver_pc](/docs/images/clouduino-web-server-browser.png)

From your smartphone browser:

![webserver_cp](/docs/images/clouduino-web-server-smartphone.png)

Now when you press the buttons in your web server you can control both LEDs remotely.