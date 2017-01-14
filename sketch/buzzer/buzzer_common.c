#include "buzzer.h"
#include "../gpio/gpio.h"

void BUZZER_Init()
{
	AIR_PWM_Enable(BUZZER_PWM_PIN);
}

void BUZZER_Start(unsigned int note)
{
	// Frequency of the note is multiplied by 1000 to make it an integer value
	unsigned int pwmInitValue = 0x3FF - ((512000 * 1000) / note);
	// Set duty cycle to 50%
	unsigned int pwmToggleValue = (0x3FF + pwmInitValue) / 2;

	AIR_PWM_SetAdv(BUZZER_PWM_PIN, pwmToggleValue, pwmInitValue);
}

void BUZZER_Stop()
{
	AIR_PWM_SetAdv(BUZZER_PWM_PIN, 0x3FF, 0x3FF);
}
