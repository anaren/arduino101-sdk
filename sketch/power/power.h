// Copyright (c) 2016, Anaren Inc.
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
// either expressed or implied.

#ifndef AIR_POWER_H
#define AIR_POWER_H

#include <stdbool.h>
#include <stdint.h>
#include "power_config.h"

typedef enum
{
	AIR_POWER_NOSLEEP = 0,
	AIR_POWER_SLEEPY,
	AIR_POWER_SLEEP,
	AIR_POWER_DEEPSLEEP,
	AIR_POWER_VERYDEEPSLEEP,
	AIR_POWER_OFF
} AIR_POWER_Mode;

typedef AIR_POWER_Mode (*air_power_callback_func_ptr)(AIR_POWER_Mode);

/**
 * This routine will enables the power management subsystem of the target micro-controller. This routine must be called before any other peripheral power function.
 *
 * @param None.
 * @return None.
 */
void AIR_POWER_Init();

/**
 * This routine will tells the micro-controller what power mode the user application would be set to run at.
 *
 * @details NOTE: In the event that the micro-controller is running a protocol (such as BLE) it is up to the lower level protocol to decide the sleeping behavior.
 *
 * @param mode :Specifies the mode of power saving you want the micro-controller to enter.
 * @return None.
 */
void AIR_POWER_SetMode(AIR_POWER_Mode mode);

/**
 * This routine will attempts to reset the chip set if this ability exists.
 *
 * @details NOTE: See chip set's individual information if this is available.
 *
 * @param None.
 * @return None.
 */
void AIR_POWER_Reset();

/**
 * This routine will sets how long the chip should stay in deepsleep while using the active internal clock it has to count the time in milliseconds.
 *
 * @details NOTE: See the chip set's individual information about limits to this value.
 *
 * @param value :Specifies the numbers of milliseconds you want the chip to sleep.
 * @return None.
 */
void AIR_POWER_SetDeepSleepInterval(unsigned int value);


/**
 * This routine will sets how long the chip should stay in deepsleep while using the active internal clock it has to count the time in seconds.
 *
 * @details NOTE: See the chip set's individual information about limits to this value.
 *
 * @param value :Specifies the numbers of seconds you want the chip to sleep.
 * @return None.
 */
void AIR_POWER_SetDeepSleepIntervalSeconds(uint32_t value);


#endif
