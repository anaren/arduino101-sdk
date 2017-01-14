#include <cstdint>
#include <SPI.h> // Needs to be here for arduino to find GPIO constants. don't ask me why.

#ifdef __cplusplus
extern "C"{
#endif

#include "gpio.h"

#define NUM_PINS 20
#define PWM_PINS_MASK ((1 << 3) | (1 << 5) | (1 << 6) | (1 << 9)) 
#define ANALOG_REFERENCE_MV 3300 // 101 is always 3.3v
#define MAX_COUNTS 1024
#define COUNTS_PER_MV 3.22265625 // ANALOG_REFERENCE_MV / MAX_COUNTS
static uint32_t gpioMode[NUM_PINS] = {INPUT};

static bool isPwmPin( uint32_t pin )
{
	return ( (PWM_PINS_MASK >> pin) & 0x1 );
}

static bool isAnalogPin( uint32_t pin )
{
	return ( pin >= A0 && pin <= A5 );
}

static uint32_t atmoMode2Arduino( uint32_t mode )
{
	switch( mode )
	{
		case AIR_GPIO_INPUT_PULL_UP:
		{
			return INPUT_PULLUP;
			break;
		}
		case AIR_GPIO_INPUT_PULL_DOWN:
		case AIR_GPIO_INPUT_HIGH_IMPEDANCE:
		{
			return INPUT;
			break;
		}
		case AIR_GPIO_OUTPUT_PUSH_PULL:
		case AIR_GPIO_OUTPUT_OPEN_DRAIN_NO_PULL:
		case AIR_GPIO_OUTPUT_OPEN_DRAIN_PULL_UP:
		{
			return OUTPUT;
			break;
		}
	}

	return 0;
}

static uint32_t atmoInterruptMode2Arduino( uint32_t mode )
{
	switch( mode )
	{
		case AIR_GPIO_TRIGGER_RISING_EDGE:
		{
			return RISING;
			break;
		}
		case AIR_GPIO_TRIGGER_FALLING_EDGE:
		{
			return FALLING;
			break;
		}
		case AIR_GPIO_TRIGGER_BOTH_EDGES:
		{
			return CHANGE;
			break;
		}
	}

	return 0;
}

void AIR_GPIO_Init(){}

void AIR_GPIO_SetMode(unsigned int pin, int mode)
{
	gpioMode[pin] = atmoMode2Arduino(mode);
	pinMode( pin, gpioMode[pin] );
}

int AIR_GPIO_GetMode(unsigned int pin)
{
	return gpioMode[pin];
}

bool AIR_GPIO_Read(unsigned int pin)
{
	return digitalRead(pin);
}


void AIR_GPIO_Write(unsigned int pin, bool value)
{
	return digitalWrite(pin, (value) ? HIGH : LOW );
}


void AIR_GPIO_RegisterInterrupt(unsigned int pin, air_gpio_callback_func_ptr func, int flags)
{
	attachInterrupt( pin, func, atmoInterruptMode2Arduino(flags) );
}


void AIR_GPIO_UnregisterInterrupt(unsigned int pin)
{
	detachInterrupt( pin );
}

void AIR_PWM_Enable(unsigned int pin)
{
}

void AIR_PWM_Configure(unsigned int pin, unsigned int toggleCount, unsigned int initCount)
{
	// Deprecated. Please use AIR_PWM_SetDutyCycle
}

void AIR_PWM_Disable(unsigned int pin)
{
	AIR_GPIO_SetMode( pin, AIR_GPIO_OUTPUT_PUSH_PULL );
	AIR_GPIO_Write( pin, false );
}

void AIR_PWM_SetAdv(unsigned int pin, int toggleCount, int initCount)
{
	// Deprecated. Please use AIR_PWM_SetDutyCycle
}

void AIR_PWM_Set(unsigned int pin, int toggleCount)
{
	// Deprecated. Please use AIR_PWM_SetDutyCycle
}

void AIR_PWM_Change(unsigned int pin, int toggleCount)
{
	// Deprecated. Please use AIR_PWM_SetDutyCycle
}

void AIR_PWM_SetDutyCycle( unsigned int pin, float dutyCycle )
{
	if( isPwmPin(pin) )
	{
		// Arduino expect value between 0 and 255 for duty cycle
		analogWrite( pin, (uint32_t)( (dutyCycle/100) * 0xFF ) );
	}
}

void AIR_ADC_Enable(unsigned int pin)
{
	// Nothing to do
}

void AIR_ADC_SetReferenceVoltage(unsigned int pin, unsigned int millivolts)
{
	// Always 3300
}

unsigned int AIR_ADC_Read(unsigned int pin)
{
	return AIR_ADC_ReadRaw( pin ) * COUNTS_PER_MV;
}

int AIR_ADC_ReadRaw(unsigned int pin)
{
	if( isAnalogPin(pin) )
	{
		return analogRead(pin);
	}

	return 0;
}

#ifdef __cplusplus
}
#endif

