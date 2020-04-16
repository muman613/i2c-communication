/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */

// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
//Beginning of Auto generated function prototypes by Atmel Studio
void receiveEvent(int howMany);
void requestEvent();
//End of Auto generated function prototypes by Atmel Studio

#define REGISTERS		16

uint8_t regBuffer[REGISTERS] = {
	0x10,
	0x29,
	0x33,
	0x19,
	0xfc,
	0x00,
	0x1a,
	0x22,
	0x10,
	0x29,
	0x33,
	0x19,
	0xfc,
	0x00,
	0x1a,
	0x22,
};

// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

void setup() {
	
	pinMode(LED_BUILTIN, OUTPUT);
	
	Wire.begin(8);                // join i2c bus with address #8

	Wire.onReceive(receiveEvent); // register event
	Wire.onRequest(requestEvent);

	Serial.begin(9600);           // start serial for output
}

int state = LOW;

void loop() {
	
	if (regBuffer[0x0a] & (1 << 3)) {
		state = HIGH;
	} else {
		state = LOW;
	}
	digitalWrite(LED_BUILTIN, state);
	delay(20);
}

volatile int reg = 0;
volatile int value = 0xa5;

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
	if (howMany == 1) {
		reg= Wire.read();    // receive byte as an integer
	} else if (howMany == 2) {
		reg = Wire.read();
		value = Wire.read();
		
		if ((reg >= 0) && (reg <= REGISTERS)) {
			regBuffer[reg] = value;
		}
	}
}

void requestEvent() {
	if ((reg >= 0) && (reg <= REGISTERS)) {	
		Wire.write(regBuffer[reg]);
	}
}
