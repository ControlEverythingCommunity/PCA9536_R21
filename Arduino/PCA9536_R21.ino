// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// PCA9536_R21
// This code is designed to work with the PCA9536_I2CR_R21 I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/products

#include<Wire.h>

// PCA9536_R21 I2C address is 0x41(65)
#define Addr 0x41

void setup()
{
  // Initialise I2C communication
  Wire.begin();
  // Initialise Serial Communication, set baud rate = 9600
  Serial.begin(9600);

  // Start I2C transmission
  Wire.beginTransmission(Addr);
  // Select configuration register
  Wire.write(0x03);
  // Set all pins as OUTPUT
  Wire.write(0x00);
  // Stop I2C transmission
  Wire.endTransmission();

  // Start I2C transmission
  Wire.beginTransmission(Addr);
  // Select output port register
  Wire.write(0x03);
  // Set both Pins HIGH
  Wire.write(0x03);
  // Stop I2C transmission
  Wire.endTransmission();
  delay(300);
}

void loop()
{
  unsigned int output1, output2;

  // Start I2C transmission
  Wire.beginTransmission(Addr);
  // Select data register
  Wire.write(0x01);
  // Stop I2C transmission
  Wire.endTransmission();

  // Request 1 byte of data
  Wire.requestFrom(Addr, 1);

  // Read 1 byte of data
  if (Wire.available() == 1)
  {
    output = Wire.read();
  }

  if ((output & 0x01))
  {
    Serial.println("Pin-1 : HIGH");
  }
  else
  {
    Serial.println("Pin-1 : LOW");
  }

  if ((output & 0x02))
  {
    Serial.println("Pin-2 : HIGH");
  }
  else
  {
    Serial.println("Pin-2 : LOW");
  }
  delay(500);
}
