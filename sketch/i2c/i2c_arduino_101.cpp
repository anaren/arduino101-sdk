#include "i2c.h"
#include <Wire.h>

#ifdef __cplusplus
  extern "C"{
#endif


void AIR_I2C_Init()
{
	Wire.begin();
}

void AIR_I2C_ComboRead(unsigned char slaveAddr, unsigned char* writeBytes, unsigned int numWriteBytes, unsigned char* readBytes, unsigned int numReadBytes)
{
		AIR_I2C_Read( slaveAddr, readBytes, numReadBytes );
		AIR_I2C_Write( slaveAddr, writeBytes, numWriteBytes );
}

void AIR_I2C_Write(unsigned char slaveAddr, unsigned char* writeBytes, unsigned int numBytes)
{
	Wire.beginTransmission( slaveAddr );
	Wire.write( writeBytes, numBytes );
	Wire.endTransmission();
}


void AIR_I2C_Read(unsigned char slaveAddr, unsigned char *readBytes, unsigned int numBytes)
{
	Wire.requestFrom( slaveAddr, numBytes );
	int currentByte = 0;
	while( Wire.available() )
	{
		readBytes[currentByte] = Wire.read();
		currentByte++;
	}
}

#ifdef __cplusplus
  }
#endif

