#include "spi.h"
#include <SPI.h>

#ifdef __cplusplus
extern "C"{
#endif

static air_spi_conf_t currentConfiguration;

void AIR_SPI_Init()
{
	SPI.begin();
}

void AIR_SPI_Configure(const air_spi_conf_t* const spiConf)
{
	currentConfiguration = *spiConf;
	SPISettings settings( spiConf->speed, ( spiConf->msbFirst ) ? MSBFIRST : LSBFIRST, spiConf->mode );
	SPI.beginTransaction( settings );
}


void AIR_SPI_SetCSPin(int cspin)
{
	pinMode(cspin, OUTPUT);
}


void AIR_SPI_AssertCSPin(int cspin)
{
	digitalWrite(cspin, HIGH);
}


void AIR_SPI_DeassertCSPin(int cspin)
{
	digitalWrite(cspin, LOW);
}


void AIR_SPI_Write(int cspin, unsigned char *writeBytes, unsigned int numWriteBytes)
{
	AIR_SPI_Exchange( cspin, NULL, writeBytes, numWriteBytes );
}


void AIR_SPI_Read(int cspin, unsigned char *readBytes, unsigned int numReadBytes)
{
	AIR_SPI_Exchange( cspin, readBytes, NULL, numReadBytes );
}


void AIR_SPI_Exchange(int cspin, unsigned char *readBytes, unsigned char *writeBytes, unsigned int numberOfBytes)
{
	// Select slave
	if( currentConfiguration.ssActiveLow )
	{
		AIR_SPI_DeassertCSPin( cspin );
	}
	else
	{
		AIR_SPI_AssertCSPin( cspin );
	}

	// Transfer data
	for( uint32_t currentByte = 0; currentByte < numberOfBytes; currentByte++ )
	{
		uint8_t byteToWrite = (writeBytes) ? writeBytes[currentByte] : 0xFF;
		uint8_t tmpRead = SPI.transfer( byteToWrite );

		if( readBytes )
		{
			readBytes[currentByte] = tmpRead;
		}
	}

	// Reassert CS pin
	if( currentConfiguration.ssActiveLow )
	{
		AIR_SPI_AssertCSPin( cspin );
	}
	else
	{
		AIR_SPI_DeassertCSPin( cspin );
	}
}

#ifdef __cplusplus
}
#endif

