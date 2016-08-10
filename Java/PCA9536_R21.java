// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// PCA9536_R21
// This code is designed to work with the PCA9536_I2CR_R21 I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/products

import com.pi4j.io.i2c.I2CBus;
import com.pi4j.io.i2c.I2CDevice;
import com.pi4j.io.i2c.I2CFactory;
import java.io.IOException;

public class PCA9536_R21
{
	public static void main(String args[]) throws Exception
	{
		// Create I2C bus
		I2CBus Bus = I2CFactory.getInstance(I2CBus.BUS_1);
		// Get I2C device, PCA9536_R11 I2C address is 0x41(65)
		I2CDevice device = Bus.getDevice(0x41);

		// Select configuration register
		// Set all pins as OUTPUT
		device.write(0x03, (byte)0x00);
		Thread.sleep(500);

		// Select output port register
		// Set pin-1 as HIGH
		device.write(0x01, (byte)0x01);
		Thread.sleep(1000);
		
		// Output data to screen
		System.out.printf("Pin-1 state is : HIGH %n");
		
		// Select output port register
		// Set pin-1 as LOW
		device.write(0x01, (byte)0x00);
		Thread.sleep(1000);
		
		// Output data to screen
		System.out.printf("Pin-1 state is : LOW %n");
		
		// Select output port register
		// Set pin-2 as HIGH
		device.write(0x01, (byte)0x02);
		Thread.sleep(1000);
		
		// Output data to screen
		System.out.printf("Pin-2 state is : HIGH %n");
		
		// Select output port register
		// Set pin-2 as LOW
		device.write(0x01, (byte)0x00);
		Thread.sleep(1000);
		
		// Output data to screen
		System.out.printf("Pin-2 state is : LOW %n");
	}
}
