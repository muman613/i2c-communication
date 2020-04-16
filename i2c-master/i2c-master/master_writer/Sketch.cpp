/************************************************************************/
/* i2c_master                                                           */
/************************************************************************/

#include <Arduino.h>
#include <Wire.h>

#define SLAVE_ADDRESS 8

/************************************************************************/
/* Write data to i2c slave.						                        */
/************************************************************************/
void writeRegister(uint8_t addr, uint8_t reg, uint8_t value) {
    Wire.beginTransmission(addr); // transmit to device #8
    Wire.write(reg);
    Wire.write(value);
    Wire.endTransmission();    // stop transmitting
}

/************************************************************************/
/* Read data value from i2c slave @ addr register                       */
/************************************************************************/
uint8_t readRegister(uint8_t addr, uint8_t reg) {
    Wire.beginTransmission(addr); // transmit to device #8
    Wire.write(reg);
    Wire.endTransmission();    // stop transmitting

    /* Read value back from slave */
    Wire.requestFrom((int)addr, 1);
    uint8_t val = Wire.read();
    
    return val;
}

void setup() {
    Serial.begin(9600);
    Serial.println("I2C MASTER");
    Wire.begin(); // join i2c bus (address optional for master)
}

byte x = 0;


void loop() {
    int val = readRegister(SLAVE_ADDRESS, 0x0a);

    Serial.print("value ");
    Serial.println(val, HEX);
    
    writeRegister(SLAVE_ADDRESS, 0x0a, val + 1);

    x++;
    delay(250);
}
