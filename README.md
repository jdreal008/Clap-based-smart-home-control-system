# Clap-based-smart-home-control-system

Introduction

The Smart Clap Switch is an Arduino-based electronic project that controls electrical devices using sound signals. It uses a KY-038 sound sensor to detect claps and a two-channel relay module to control an LED light and a DC fan.

Objective

To design and implement a clap-controlled switching system using Arduino UNO that can control multiple devices without physical switches.

Components Required

1. Arduino UNO R3
2. KY-038 Sound Sensor
3. 2-Channel 5V Relay Module
4. LED Light
5. 12V DC Fan
6. 220Ω Resistor
7. 12V DC Power Supply
8. Breadboard
9. Jumper Wires
10. USB Cable

Circuit Connections

Component| Arduino Connection
Sound Sensor DO| D2
Sound Sensor VCC| 5V
Sound Sensor GND| GND
Relay IN1| D8
Relay IN2| D9
Relay VCC| 5V
Relay GND| GND

Load Connections

LED Light:

- Relay Channel 1 COM → 5V
- Relay Channel 1 NO → LED Anode (+)
- LED Cathode (−) → 220Ω Resistor → GND

DC Fan:

- Relay Channel 2 COM → 12V Supply Positive
- Relay Channel 2 NO → Fan Positive
- Fan Negative → 12V Supply Negative

Working Principle

The KY-038 sound sensor detects sound signals and sends digital signals to the Arduino UNO.

The Arduino processes these signals and counts the number of claps within a specified time interval.

Based on the number of detected claps, the Arduino activates or deactivates the relay channels.

Clap Control Operations

- 1 Clap: Light ON/OFF
- 2 Claps: Fan ON/OFF
- 3 Claps: Both Light and Fan ON/OFF

The relay module allows the Arduino to control the connected devices electronically.

Software Requirements

- Arduino IDE
- Embedded C/C++ Programming

Advantages

- Hands-free operation
- Low-cost implementation
- Simple circuit design
- Easy to construct
- Suitable for basic home automation

Applications

- Smart Home Automation
- Clap-Controlled Lighting
- Fan Control Systems
- Educational Electronics Projects
- Assistive Switching Systems

Future Scope

- Integration with IoT technology
- Wireless device control
- Mobile application connectivity
- Improved sound recognition
- Voice-controlled automation

Project Files

- "smart_clap_switch.ino" — Arduino source code
- "circuit_diagram.png" — Circuit diagram
- "README.md" — Project documentation

Important Notes

The Arduino program assumes an active-LOW relay module. Clap detection may require sensor calibration and software improvements for reliable operation.

The 12V fan must use a separate suitable 12V supply. Do not connect 12V directly to the Arduino 5V pin.

Conclusion

The Smart Clap Switch demonstrates how Arduino and sound sensors can be used to control electrical devices through sound-based commands. This project provides a simple introduction to embedded systems, relay interfacing, and home automation.
