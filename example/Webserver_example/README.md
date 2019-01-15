# Webserver using Clouduino Stratus ##

Create a simple standalone webserver that can remotely toggle two LEDs using Clouduino. This Web server is mobile, responsive and it can be accessed with any device that as a browser in your local network. 

This tutorial is based on [ESP822 Webserver with Arduino IDE](https://randomnerdtutorials.com/esp8266-web-server-with-arduino-ide/). Check [here](https://github.com/RuiSantosdotme/Random-Nerd-Tutorials) for more related projects.

### Follow these steps:

1.  Assemble the circuit based on the Fritzing [schematic](Clouduino_Webserver_LEDs_fritzing_Schem.PNG) or [breadboard](Clouduino_Webserver_LEDs_fritzing_Breadboard.PNG) provided.
2.  Upload the Clouduino_Webserver_LEDs sketch to Clouduino Stratus. 
3. Open the Arduino serial monitor at a baud rate of 115200.
4. Press Reset button. After a few seconds your IP address should appear in the serial monitor - This is the IP address of your webserver.
  
![ip-address](/docs/images/clouduino-ip-address.png)

### Demonstration
 Open any browser from a device that is connected to the same router as your Clouduino. Then type in the IP address of your webserver and click Enter!

 Click the buttons on the webserver and observe the LEDs turning on or off. 

![webserver_pc](/docs/images/clouduino-web-server-browser.png)

From your smartphone browser:

![webserver_cp](/docs/images/clouduino-web-server-smartphone.png)

If the experiment worked, well done! You can now control your Clouduino's GPIO remotely.