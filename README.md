# Clouduino

![Logo](/docs/images/logo.png)

Clouduino is a fully open-source, WiFi mesh-enabled embedded development platform.

This project is still in its infancy. At the moment, the circuit design and PCB layout for the initial prototype version is available for building the initial iteration of the board: Clouduino Stratus. We also included sample code to get you started. We will be producing limited quantities of the board soon. In the meantime, let's build our own boards, send us your feed back and help this project grow.

## Specs

- CPU: 160 MHz
- L106 32-bit RISC Tensilica Xtensa Diamond Standard 106Micro
- 3.3V supply power
- Flash Memory: 4MB
- 16 GPIO pins
- 8 analog input channels with 12-bit resolution (programmable as single-ended or pseudo-differential pairs)
- SPI
- I2C support
- 12-bit SAR ADC support
- IEEE 802.11 b/g/n WiFi (w/ WEP, WPA, WPA2)

## Getting Started
Check out our Get Started Guide [here](https://github.com/proudcloud/clouduino/tree/master/getStarted).

## Quickstart Guide

1. Download and install [Arduino IDE](https://www.arduino.cc/en/Main/Software)
2. Follow [this guide](https://github.com/proudcloud/clouduino/tree/master/getStarted) to configure the IDE and upload your first sketch
3. Follow our [examples](https://github.com/proudcloud/clouduino/tree/master/example)

## Build Your Own Board

Schematic diagrams and breadboard prototype can be found in [this folder](https://github.com/proudcloud/clouduino/tree/master/schematics)

### Materials Needed
#### MCU
- 1 x ESP12F


#### Peripherals
- 1 x MCP23S17 GPIO Expander (SOIC)
-  1 x MCP3208 ADC (SOIC)

#### Connectors and Interfacing
- 1 x FT230XS-R USB to Serial (SSOP)
- 1 x USB-B Mini Connector
- 2 x 16-pin Female/Male headers

#### Power
 - 1 x AMS1117 - 3.3 Regulator (SOT-223-3)


#### Others
 - 1 x ECQ10A04-F Dual Schottky Barrier (TO-252)
 - 2 x BC847W (SOT323)
 - 7 x 10K 1% SMD 0603 Resistors
 - 2 x 27 ohm 1% SMD 0603 Resistors
 - 3 x 270 ohm 1% SMD 0603 Resistors
 - 2 x 470 ohm 1% SMD 0603 Resistors
 - 3 x 0.1uF 50V SMD 0603 Capacitor
 - 2 x 10uF 50V SMD 0603 Capacitor
 - 1 x 1uF 50V SMD 0603 Capacitor
 - 2 x 47pF 50V SMD 0603 Capacitor
 - 1 x SMD LED 0603 Green
 - 1 x SMD LED 0603 Yellow
 - 1 x SMD LED 0603 Blue
 - 2 x OMRON BF-3 1000 THT Tact Switch 
 - 1 x Ferrite Bead 600/100mhz SMD 0603
