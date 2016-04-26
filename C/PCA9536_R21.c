// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// PCA9536_R21
// This code is designed to work with the PCA9536_I2CR_R21 I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/products

#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>

void main() 
{
	// Create I2C bus
	int file;
	char *bus = "/dev/i2c-1";
	if((file = open(bus, O_RDWR)) < 0) 
	{
		printf("Failed to open the bus. \n");
		exit(1);
	}
	// Get I2C device, PCA9536_R21 I2C address is 0x41(65)
	ioctl(file, I2C_SLAVE, 0x41);

	// Select configuration register(0x03)
	// Set all pins as OUTPUT(0x00)
	char config[2] = {0};
	config[0] = 0x03;
	config[1] = 0x00;
	write(file, config, 2);
	// Select output port register(0x01)
	// Set both Pins HIGH(0x03)
	config[0] = 0x01;
	config[1] = 0x03;
	write(file, config, 2);
	sleep(1);
	
	// Read 1 byte from  register(0x01)
	char reg[1] = {0x01};
	write(file, reg, 1);
	char data[1] = {0};
	if(read(file, data, 1) != 1)
	{
		printf("Erorr : Input/output Erorr \n");
	}
	else
	{
		// Output to screen
		if((int)data & 0x01)
		{
			printf("Pin 1 : HIGH");
		}
		else
		{
			printf("Pin 1 : LOW");
		}
		if((int)data & 0x02)
		{
			printf("Pin 2 : HIGH");
		}
		else
		{
			printf("Pin 2 : LOW");
		}
	}
}
