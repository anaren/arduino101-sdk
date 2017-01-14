#include "callbacks.h"

//END


void atmosphere::interval() {

}


void atmosphere::connected() {

}


void atmosphere::disconnected() {

}


void atmosphere::setup() {
	AIR_GPIO_Init();
	AIR_UART_Init();
	AIR_I2C_Init();
	AIR_SPI_Init();
}


bool atmosphere::GPIOToggle1(bool data)
{

	
	if(AIR_GPIO_GetMode(13) != AIR_GPIO_OUTPUT_PUSH_PULL)
	{
		AIR_GPIO_SetMode(13, AIR_GPIO_OUTPUT_PUSH_PULL);
	}
	
	AIR_GPIO_Write(13, !AIR_GPIO_Read(13));
	
	return true;
	
}

