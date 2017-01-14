// Copyright (c) 2014, Anaren Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
// ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// The views and conclusions contained in the software and documentation are those
// of the authors and should not be interpreted as representing official policies,
// either expressed or implied, of the FreeBSD Project.

#ifndef AIR_GPIO_H
#define AIR_GPIO_H

#ifdef __cplusplus
extern "C"{
#endif

#include <stdbool.h>
#include "gpio_config.h"



enum
{
	AIR_GPIO_INPUT_PULL_UP = 1,             /* Input with an internal pull-up resistor - use with devices that actively drive the signal low - e.g. button connected to ground */
	AIR_GPIO_INPUT_PULL_DOWN,           /* Input with an internal pull-down resistor - use with devices that actively drive the signal high - e.g. button connected to a power rail */
	AIR_GPIO_INPUT_HIGH_IMPEDANCE,      /* Input - must always be driven, either actively or by an external pullup resistor */
	AIR_GPIO_OUTPUT_PUSH_PULL,          /* Output actively driven high and actively driven low - must not be connected to other active outputs - e.g. LED output */
	AIR_GPIO_OUTPUT_OPEN_DRAIN_NO_PULL, /* Output actively driven low but is high-impedance when set high - can be connected to other open-drain/open-collector outputs. Needs an external pull-up resistor */
	AIR_GPIO_OUTPUT_OPEN_DRAIN_PULL_UP, /* Output actively driven low and is pulled high with an internal resistor when set high - can be connected to other open-drain/open-collector outputs. */
	AIR_GPIO_TRIGGER_RISING_EDGE,
	AIR_GPIO_TRIGGER_FALLING_EDGE,
	AIR_GPIO_TRIGGER_BOTH_EDGES
};

typedef void (*air_gpio_callback_func_ptr)(void);

/**
 * This routine initializes and configure the GPIO driver.
 *
 * @details NOTE: this function must be called before any GPIO functions are executed.
 *
 * @param None.
 * @return None.
 */
void AIR_GPIO_Init();

/**
 * This routine sets the GPIO mode for a selected pin
 *
 * @details NOTE: the available modes are as listed: AIR_GPIO_INPUT_PULL_UP: Input with an internal pull-up resistor - use with devices that actively drive the signal low - e.g. button connected to ground
   AIR_GPIO_INPUT_PULL_DOWN: Input with an internal pull-down resistor - use with devices that actively drive the signal high - e.g. button connected to a power rail
   AIR_GPIO_INPUT_HIGH_IMPEDANCE: Input - must always be driven, either actively or by an external pullup resistor
   AIR_GPIO_OUTPUT_PUSH_PULL: Output actively driven high and actively driven low - must not be connected to other active outputs - e.g. LED output
   AIR_GPIO_OUTPUT_OPEN_DRAIN_NO_PULL: Output actively driven low but is high-impedance when set high - can be connected to other open-drain/open-collector outputs. Needs an external pull-up resistor
   AIR_GPIO_OUTPUT_OPEN_DRAIN_PULL_UP: Output actively driven low and is pulled high with an internal resistor when set high - can be connected to other open-drain/open-collector outputs..
 *
 * @param pin :Specifies the pin to configure to the mode on the GPIO chip.
 * @param mode :Specifies the mode to set a pin on the GPIO chip.
 * @return None.
 */
void AIR_GPIO_SetMode(unsigned int pin, int mode);

/**
 * This routine retrieves the current GPIO mode of a pin.
 *
 * @details NOTE: The "GetMode" function can return combinations of the values (mode types). For example, if it returns a value that includes the bits for GPIO_PULL_UP and
 * GPIO_INPUT_ENABLE are set, that means that the pin is in high-impedance mode, and it has a pullup resistor connected. The return values are associated with the
 * following;
   AIR_GPIO_INPUT_PULL_UP: Input with an internal pull-up resistor - use with devices that actively drive the signal low (e.g. button connected to ground). Value is 1.
   AIR_GPIO_INPUT_PULL_DOWN: Input with an internal pull-down resistor - use with devices that actively drive the signal high (e.g. button connected to a power rail). Value is 2.
   AIR_GPIO_INPUT_HIGH_IMPEDANCE: Input - must always be driven, either actively or by an external pullup resistor. Value is 3.
   AIR_GPIO_OUTPUT_OPEN_DRAIN_NO_PULL: Output actively driven low but is high-impedance when set high - can be connected to other open-drain/open-collector outputs. Needs an external pull-up resistor. Value is 5.
   AIR_GPIO_OUTPUT_OPEN_DRAIN_PULL_UP: Output actively driven low and is pulled high with an internal resistor when set high - can be connected to other open-drain/open-collector outputs. Value is 6.
   AIR_GPIO_OUTPUT_PUSH_PULL: Output actively driven high and actively driven low - must not be connected to other active outputs (e.g. LED output). Value is 4.
   AIR_GPIO_TRIGGER_RISING_EDGE: Event driven when a signal transitions from low to high. Value is 7.
   AIR_GPIO_TRIGGER_FALLING_EDGE: Event driven when a signal transitions from high to low. Value is 8.
   AIR_GPIO_TRIGGER_BOTH_EDGES: Event driven when a signal transitions from either high or low. Value is 9.
 *
 * @param pin :Specifies the pin on the GPIO chip to return the mode.
 * @return This routine returns an integer value that indicates the state of the pin specified in the parameter.
 */
int AIR_GPIO_GetMode(unsigned int pin);

/**
 * This routine reads the current state of one of the pins on the device.
 *
 * @details NOTE: The pin should be configured in an appropriate input mode before attempting to use this function.
 *
 * @param pin :Specifies the pin on the GPIO chip to read.
 * @return This routine returns a boolean value that indicates the state of the pin specified in the parameter. True indicates that the pin was high. False indicates that the pin was low.
 */
bool AIR_GPIO_Read(unsigned int pin);

/**
 * This routine writes a signal on a pin.
 *
 * @details NOTE: The pin should be configured in an appropriate output mode before attempting to use this routine.
 *
 * @param pin :Specifies the pin on the GPIO chip to write the value specified in the value parameter. The range of values are 1-25.
 * @param value :Specifies the Boolean value to write to the pin specified in the parameters. True indicates that the pin is set to high. False indicates that the pin is set to low.
 * @return None.
 */
void AIR_GPIO_Write(unsigned int pin, bool value);

/**
 * This routine registers an interrupt routine for given pin.
 *
 * @details NOTE: This routine will set the current mode of the pin to an appropriate mode for registering an interrupt. The appropriate flags that can be set are list here: AIR_GPIO_TRIGGER_RISING_EDGE, AIR_GPIO_TRIGGER_FALLING_EDGE, and AIR_GPIO_TRIGGER_BOTH_EDGES
 *
 * @param pin :Specifies the pin on the GPIO to monitor for an interrupt.
 * @param func :Specifies the interrupt function to call when the GPIO matches the setting of the flags parameter.
 * @param flags :Specifies the pin setting that will cause the interrupt routine be called. The event that will initiate and interrupt.
 * @return None.
 */
void AIR_GPIO_RegisterInterrupt(unsigned int pin, air_gpio_callback_func_ptr func, int flags);

/**
 * This routine de-registers an interrupt routine for given pin.
 *
 * @details NOTE: 
 *
 * @param pin :Specifies the pin on the GPIO to monitor for an interrupt.
 * @return None.
 */
void AIR_GPIO_UnregisterInterrupt(unsigned int pin);

/**
 * This routine specifies the pin on the GPIO chip to enable Pulse Width Modulation (PWM).
 *
 * @details NOTE: This routine must be called before all of the other PWM routines. Not all pins are PWM capable. Please refer to the hardware manual for the particular board to determine which pins are available for PWM.
 *
 * @param pin : Specifies the pin to enable PWM for.
 * @return None.
 */
void AIR_PWM_Enable(unsigned int pin);

/**
 * This routine configures a pin on the GPIO chip for Pulse Width Modulation (PWM).
 *
 * @param pin :Specifies the pin on the GPIO chip to configure PWM.
 * @param toggleCount :Specifies the minimum value for the PWM on the specified pin.
 * @param initCount :Specifies the maximum value for the PWM on the specified pin.
 * @return None.
 */
void AIR_PWM_Configure(unsigned int pin, unsigned int toggleCount, unsigned int initCount);

/**
 * This routine disables Pulse Width Modulation (PWM) on a pin.
 *
 * @param pin :Specifies the pin on the GPIO chip to disable PWM.
 * @return None.
 */
void AIR_PWM_Disable(unsigned int pin);

/**
 * This routine sets the advanced settings for pulse width modulation on a pin on the GPIO chip.
 *
 * @details NOTE: For advanced control of the PWM. The PWM transitions are triggered off of a saw-tooth clock value. You set up two trigger bounds
 * for when you want the PWM hardware to transition the output pin to high, and when you want it to transition to low. When the clock reaches those
 * trigger values, the PWM hardware will transition the output pin selected.
 *
 * For the A20737 module the clock bounds runs from 0x0 to 0x3FF. This method will configure the duty cycle and period for the PWM.
 * A good example of this is the BUZZER_Start(uint32 note) function that will set up the PWM for a particular note that needs to be played.
 * @code{.c}
   void BUZZER_Start(uint32 note)
    {
        // Frequency of the note is multiplied by 1000 to make it an integer value
        uint32 pwmInitValue = 0x3FF - ((512000 * 1000) / note);
        // Set duty cycle to 50%
        uint32 pwmToggleValue = (0x3FF + pwmInitValue) / 2;

        AIR_PWM_SetAdv(BUZZER_PWM_PIN, pwmToggleValue, pwmInitValue);
    }
 * @endcode
 *
 * @param pin :Specifies the pin on the GPIO chip to set the PWM.
 * @param toggleCount :Specifies the minimum value for the PWM on the specified pin.
 * @param initCount :Specifies the maximum value for the PWM on the specified pin.
 * @return None.
 */
void AIR_PWM_SetAdv(unsigned int pin, int toggleCount, int initCount);

/**
 * This routine sets the value of a pin on the GPIO chip.
 *
 * @param pin :Specifies the pin on the GPIO chip to enable PWM.
 * @param toggleCount :Specifies the minimum value for the PWM on the specified pin.
 * @return None.
 */
void AIR_PWM_Set(unsigned int pin, int toggleCount);

/**
 * This routine will cause the PWM sub-system to change it's initially start clock value without resetting the PWM clocks.
 *
 * @param pin :Specifies the pin on the GPIO chip to change PWM.
 * @param toggleCount :Specifies the new value for the PWM on the specified pin.
 * @return None.
 */
void AIR_PWM_Change(unsigned int pin, int toggleCount);

/**
 * This routine will set the duty cycle for a pin on the GPIO chip
 *
 * @param pin :Specifies the pin on the GPIO chip to enable PWM
 * @param dutyCycle: Duty cycle between 0.0 and 100.0
 */
void AIR_PWM_SetDutyCycle( unsigned int pin, float dutyCycle );

/**
 * This routine will set the duty cycle for a pin on the GPIO chip
 *
 * @param pin :Specifies the pin on the GPIO chip to enable PWM
 * @param dutyCycle: Duty cycle between 0.0 and 100.0
 * @param frequency: Specifies the PWM frequency
 */
void AIR_PWM_SetDutyCycleAndFrequency( unsigned int pin, float dutyCycle, unsigned int frequency );

/**
 * This routine will enable analog-to-digital conversion input from the specified pin.
 *
 * @param pin :Specifies the pin on the GPIO chip to be enabled for analog-to-digital conversion on the analog setting of that pin.
 * @return None.
 */
void AIR_ADC_Enable(unsigned int pin);

/**
 * This routine is used to compute and set the conversion factor used by the AIR_ADC_Read to convert the raw ADC value into millivolts.
 * Once set, the conversion factor will be used for future calls to AIR_ADC_Read.
 *
 * @details NOTE: To see the raw ADC result, use AIR_ADC_ReadRaw.This routine does not effect AIR_ADC_ReadRaw.
 * There is a default conversion factor, so no call to AIR_ADC_SetReferenceVoltage is required. However, using it
 * may result in more accurate values from AIR_ADC_Read. To use the AIR_ADC_SetReferenceVoltage function, you must
 * first select an ADC-capable pin and apply a known voltage on it.Once called, the pin used can then be used for
 * other purposes, it is only used during the time to calculate the conversion factor.
 *
 * @param pin :Specifies the ADC input pin to be used as the reference for the conversion factor calculation.
 * @millivolts :Specifies the number of millivolts that the pin is set to.
 * @return None.
 */
void AIR_ADC_SetReferenceVoltage(unsigned int pin, unsigned int millivolts);

/**
 * This routine will reads an analog input pin and returns an integer value in millivolts that represents the input pin's voltage.
 *
 * @details NOTE :Internally, this method reads a raw ADC value, and then converts it to millivolts, using either the default conversion factor, or the conversion factor calculated by a prior call to AIR_ADC_SetReferenceVoltage.
 *
 * @param pin :Specifies the analog ADC input pin to read and perform analog-to-digital conversion (ADC) on.
 * @return This routine returns an integer value that indicates the analog state of the pin specified in the parameter. This is the digital representation of the analog signal on the specified pin in millivolts.
 */
unsigned int AIR_ADC_Read(unsigned int pin);

/**
 * This routine will reads the raw value of the ADC input pin and returns an integer value.
 *
 * @details NOTE: No conversion factor has been applied. It is up to the application to do any conversions into appropriate values for the data.
 *
 * @param pin :Specifies analog ADC input pin to read and perform analog-to-digital conversion on.
 * @return This routine returns an integer value that indicates the analog state of the pin specified in the parameter. This is the digital representation is a raw sample value from the ADC.
 */
int AIR_ADC_ReadRaw(unsigned int pin);

#ifdef __cplusplus
}
#endif


#endif
