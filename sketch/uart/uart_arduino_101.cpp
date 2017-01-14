#include "uart.h"
#include <string.h>
#include <SPI.h> // Need to include this for some reason to get the arduino API

#ifdef __cplusplus
extern "C"{
#endif

#define DEFAULT_BAUD_RATE 115200

void AIR_UART_Init()
{

#ifdef AIR_UART_BAUD_460800
	Serial.begin(460800);

#elif defined AIR_UART_BAUD_230400
	Serial.begin(230400);

#elif defined AIR_UART_BAUD_115200
	Serial.begin(115200);

#elif defined AIR_UART_BAUD_57600
	Serial.begin(57600);

#elif defined AIR_UART_BAUD_38400
	Serial.begin(38400);

#elif defined AIR_UART_BAUD_19200
	Serial.begin(19200);

#elif defined AIR_UART_BAUD_9600
	Serial.begin(9600);

#else
	Serial.begin(9600);
#endif

	Serial.setTimeout( 1000 );

}

void AIR_UART_SetBaudRate(unsigned int baudrate)
{
	Serial.begin( baudrate );
}

unsigned int AIR_UART_SynchronousWrite(unsigned char* pBuffer, unsigned int count)
{
	uint32_t bytesWritten = Serial.write( pBuffer, count );
	Serial.flush();
	return bytesWritten;
}

unsigned int AIR_UART_Write(unsigned char* pBuffer, unsigned int count)
{
	return Serial.write( pBuffer, count );
}

unsigned int AIR_UART_Print(const char * pBuffer)
{
	return Serial.print( (const char*)pBuffer );
}

unsigned int AIR_UART_Read(unsigned char* pBuffer, unsigned int count)
{
	return Serial.readBytes( (char*)pBuffer, count );
}

unsigned int AIR_UART_StrnRead(unsigned char* pBuffer, unsigned int count )
{
	// Arduino's readString function doesn't let you specify the max number of characters
	// This should do the same thing
	// Read until the null termination character
	return Serial.readBytesUntil( 0, pBuffer, count );
}

unsigned int AIR_UART_AvailableRX()
{
	return Serial.available();
}

unsigned int AIR_UART_AvailableTX()
{
	return Serial.availableForWrite();
}

void AIR_UART_FlushTX()
{
	Serial.flush();
}

void AIR_UART_FlushRX()
{
	char buff[ AIR_UART_AvailableRX() ];
	AIR_UART_Read( (unsigned char*)(&buff[0]), sizeof(buff) );
}

void AIR_UART_RegisterRXCallback(air_uart_callback_func_ptr func)
{
	// unavailable for chipset	
}

void AIR_UART_RegisterTXCallback(air_uart_callback_func_ptr func)
{
	// unavailable for chipset
}


#ifdef __cplusplus
}
#endif