/**
  The MySensors Arduino library handles the wireless radio link and protocol
  between your home built sensors/actuators and HA controller of choice.
  The sensors forms a self healing radio network with optional repeaters. Each
  repeater and gateway builds a routing tables in EEPROM which keeps track of the
  network topology allowing messages to be routed to nodes.

  Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
  Copyright (C) 2013-2015 Sensnology AB
  Full contributor list: https://github.com/mysensors/Arduino/graphs/contributors

  Documentation: http://www.mysensors.org
  Support Forum: http://forum.mysensors.org

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  version 2 as published by the Free Software Foundation.

*******************************

  DESCRIPTION
  The ArduinoGateway prints data received from sensors on the serial link.
  The gateway accepts input on seral which will be sent out on radio network.

  The GW code is designed for Arduino Nano 328p / 16MHz

  Wire connections (OPTIONAL):
  - Inclusion button should be connected between digital pin 3 and GND
  - RX/TX/ERR leds need to be connected between +5V (anode) and digital pin 6/5/4 with resistor 270-330R in a series

  LEDs (OPTIONAL):
  - To use the feature, uncomment any of the MY_DEFAULT_xx_LED_PINs
  - RX (green) - blink fast on radio message recieved. In inclusion mode will blink fast only on presentation recieved
  - TX (yellow) - blink fast on radio message transmitted. In inclusion mode will blink slowly
  - ERR (red) - fast blink on error during transmission error or recieve crc error

*/

#include <Arduino.h>

#define SKETCH_NAME "MyGateway Serial"
#define SKETCH_MAJOR_VER "1"
#define SKETCH_MINOR_VER "2.2"
#define SKETCH_RADIO "RFM69"

// Enable debug prints to serial monitor
//#define MY_DEBUG


// Enable and select radio type attached
#define MY_RADIO_RFM69
#define MY_RFM69_NEW_DRIVER   // ATC na RFM69 działa tylko z nowym sterownikiem (nie jest kompatybilny ze starym = domyślnym sterownikiem)
#define MY_RFM69_ATC_TARGET_RSSI_DBM  (-70)  // target RSSI -70dBm
#define MY_RFM69_MAX_POWER_LEVEL_DBM  (10)   // max. TX power 10dBm = 10mW
#define MY_RFM69_FREQUENCY RFM69_868MHZ
#define MY_RFM69_NETWORKID (101)
#define MY_RFM69_FSK_BR9_6_FD19_2
#define MY_SIGNAL_REPORT_ENABLED

// Enable serial gateway
#define MY_GATEWAY_SERIAL

// Define a lower baud rate for Arduino's running on 8 MHz (Arduino Pro Mini 3.3V & SenseBender)
#if F_CPU == 8000000L
#define MY_BAUD_RATE 38400
#endif

// Enable inclusion mode
#define MY_INCLUSION_MODE_FEATURE
// Enable Inclusion mode button on gateway
#define MY_INCLUSION_BUTTON_FEATURE

// Inverses behavior of inclusion button (if using external pullup)
//#define MY_INCLUSION_BUTTON_EXTERNAL_PULLUP

// Set inclusion mode duration (in seconds)
#define MY_INCLUSION_MODE_DURATION 60
// Digital pin used for inclusion mode button
#define MY_INCLUSION_MODE_BUTTON_PIN  3

// Set blinking period
#define MY_DEFAULT_LED_BLINK_PERIOD 300

// Inverses the behavior of leds
#define MY_WITH_LEDS_BLINKING_INVERSE

// Flash leds on rx/tx/err
// Uncomment to override default HW configurations
#define MY_DEFAULT_ERR_LED_PIN 4			// Error led pin
#define MY_DEFAULT_RX_LED_PIN  6			// Receive led pin
#define MY_DEFAULT_TX_LED_PIN  5			// the PCB, on board LED

#include <MySensors.h>

void setup()
{
  // Setup locally attached sensors
}

void presentation()
{
	// The sketch version information
	sendSketchInfo(SKETCH_NAME " " SKETCH_RADIO, SKETCH_MAJOR_VER "." SKETCH_MINOR_VER);
  // Present locally attached sensors
}

void loop()
{

}