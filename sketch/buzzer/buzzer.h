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

#ifndef BUZZER_H
#define BUZZER_H

#include <stdbool.h>

#include "buzzer_config.h"

enum BUZZER_Note
{
	BUZZER_Note_Rest        = 0,

	BUZZER_Note_C0          = (unsigned int)(16.351 * 1000.0),
	BUZZER_Note_CsDf0       = (unsigned int)(17.324 * 1000.0),
	BUZZER_Note_D0          = (unsigned int)(18.354 * 1000.0),
	BUZZER_Note_DsEf0       = (unsigned int)(19.445 * 1000.0),
	BUZZER_Note_E0          = (unsigned int)(20.601 * 1000.0),
	BUZZER_Note_F0          = (unsigned int)(21.827 * 1000.0),
	BUZZER_Note_FsGf0       = (unsigned int)(23.124 * 1000.0),
	BUZZER_Note_G0          = (unsigned int)(24.499 * 1000.0),
	BUZZER_Note_GsAf0       = (unsigned int)(25.956 * 1000.0),
	BUZZER_Note_A0          = (unsigned int)(27.500 * 1000.0),
	BUZZER_Note_AsBf0       = (unsigned int)(29.135 * 1000.0),
	BUZZER_Note_B0          = (unsigned int)(30.868 * 1000.0),

	BUZZER_Note_C1          = (unsigned int)(32.703 * 1000.0),
	BUZZER_Note_CsDf1       = (unsigned int)(34.648 * 1000.0),
	BUZZER_Note_D1          = (unsigned int)(36.708 * 1000.0),
	BUZZER_Note_DsEf1       = (unsigned int)(38.891 * 1000.0),
	BUZZER_Note_E1          = (unsigned int)(41.203 * 1000.0),
	BUZZER_Note_F1          = (unsigned int)(43.654 * 1000.0),
	BUZZER_Note_FsGf1       = (unsigned int)(46.249 * 1000.0),
	BUZZER_Note_G1          = (unsigned int)(48.999 * 1000.0),
	BUZZER_Note_GsAf1       = (unsigned int)(51.913 * 1000.0),
	BUZZER_Note_A1          = (unsigned int)(55.000 * 1000.0),
	BUZZER_Note_AsBf1       = (unsigned int)(58.270 * 1000.0),
	BUZZER_Note_B1          = (unsigned int)(61.735 * 1000.0),

	BUZZER_Note_C2          = (unsigned int)(65.406 * 1000.0),
	BUZZER_Note_CsDf2       = (unsigned int)(69.296 * 1000.0),
	BUZZER_Note_D2          = (unsigned int)(73.416 * 1000.0),
	BUZZER_Note_DsEf2       = (unsigned int)(77.782 * 1000.0),
	BUZZER_Note_E2          = (unsigned int)(82.407 * 1000.0),
	BUZZER_Note_F2          = (unsigned int)(87.307 * 1000.0),
	BUZZER_Note_FsGf2       = (unsigned int)(92.499 * 1000.0),
	BUZZER_Note_G2          = (unsigned int)(97.999 * 1000.0),
	BUZZER_Note_GsAf2       = (unsigned int)(103.826 * 1000.0),
	BUZZER_Note_A2          = (unsigned int)(110.000 * 1000.0),
	BUZZER_Note_AsBf2       = (unsigned int)(116.541 * 1000.0),
	BUZZER_Note_B2          = (unsigned int)(123.471 * 1000.0),

	BUZZER_Note_C3          = (unsigned int)(130.813 * 1000.0),
	BUZZER_Note_CsDf3       = (unsigned int)(138.591 * 1000.0),
	BUZZER_Note_D3          = (unsigned int)(146.832 * 1000.0),
	BUZZER_Note_DsEf3       = (unsigned int)(155.563 * 1000.0),
	BUZZER_Note_E3          = (unsigned int)(164.814 * 1000.0),
	BUZZER_Note_F3          = (unsigned int)(174.614 * 1000.0),
	BUZZER_Note_FsGf3       = (unsigned int)(184.997 * 1000.0),
	BUZZER_Note_G3          = (unsigned int)(195.998 * 1000.0),
	BUZZER_Note_GsAf3       = (unsigned int)(207.652 * 1000.0),
	BUZZER_Note_A3          = (unsigned int)(220.000 * 1000.0),
	BUZZER_Note_AsBf3       = (unsigned int)(233.082 * 1000.0),
	BUZZER_Note_B3          = (unsigned int)(246.942 * 1000.0),

	BUZZER_Note_C4          = (unsigned int)(261.626 * 1000.0),
	BUZZER_Note_CsDf4       = (unsigned int)(277.183 * 1000.0),
	BUZZER_Note_D4          = (unsigned int)(293.665 * 1000.0),
	BUZZER_Note_DsEf4       = (unsigned int)(311.127 * 1000.0),
	BUZZER_Note_E4          = (unsigned int)(339.628 * 1000.0),
	BUZZER_Note_F4          = (unsigned int)(349.228 * 1000.0),
	BUZZER_Note_FsGf4       = (unsigned int)(369.994 * 1000.0),
	BUZZER_Note_G4          = (unsigned int)(391.995 * 1000.0),
	BUZZER_Note_GsAf4       = (unsigned int)(415.305 * 1000.0),
	BUZZER_Note_A4          = (unsigned int)(440.000 * 1000.0),
	BUZZER_Note_AsBf4       = (unsigned int)(466.164 * 1000.0),
	BUZZER_Note_B4          = (unsigned int)(493.883 * 1000.0),

	BUZZER_Note_C5          = (unsigned int)(523.251 * 1000.0),
	BUZZER_Note_CsDf        = (unsigned int)(554.365 * 1000.0),
	BUZZER_Note_D5          = (unsigned int)(587.330 * 1000.0),
	BUZZER_Note_DsEf        = (unsigned int)(622.254 * 1000.0),
	BUZZER_Note_E5          = (unsigned int)(659.255 * 1000.0),
	BUZZER_Note_F5          = (unsigned int)(698.456 * 1000.0),
	BUZZER_Note_FsGf        = (unsigned int)(739.989 * 1000.0),
	BUZZER_Note_G5          = (unsigned int)(783.991 * 1000.0),
	BUZZER_Note_GsAf        = (unsigned int)(830.609 * 1000.0),
	BUZZER_Note_A5          = (unsigned int)(880.000 * 1000.0),
	BUZZER_Note_AsBf        = (unsigned int)(932.328 * 1000.0),
	BUZZER_Note_B5          = (unsigned int)(987.767 * 1000.0),

	BUZZER_Note_C6          = (unsigned int)(1046.502 * 1000.0),
	BUZZER_Note_CsDf6       = (unsigned int)(1108.731 * 1000.0),
	BUZZER_Note_D6          = (unsigned int)(1174.659 * 1000.0),
	BUZZER_Note_DsEf6       = (unsigned int)(1244.508 * 1000.0),
	BUZZER_Note_E6          = (unsigned int)(1318.510 * 1000.0),
	BUZZER_Note_F6          = (unsigned int)(1396.913 * 1000.0),
	BUZZER_Note_FsGf6       = (unsigned int)(1479.978 * 1000.0),
	BUZZER_Note_G6          = (unsigned int)(1567.982 * 1000.0),
	BUZZER_Note_GsAf6       = (unsigned int)(1661.219 * 1000.0),
	BUZZER_Note_A6          = (unsigned int)(1760.000 * 1000.0),
	BUZZER_Note_AsBf6       = (unsigned int)(1864.655 * 1000.0),
	BUZZER_Note_B6          = (unsigned int)(1975.533 * 1000.0),

	BUZZER_Note_C7          = (unsigned int)(2093.005 * 1000.0),
	BUZZER_Note_CsDf7       = (unsigned int)(2217.461 * 1000.0),
	BUZZER_Note_D7          = (unsigned int)(2349.318 * 1000.0),
	BUZZER_Note_DsEf7       = (unsigned int)(2489.016 * 1000.0),
	BUZZER_Note_E7          = (unsigned int)(2637.021 * 1000.0),
	BUZZER_Note_F7          = (unsigned int)(2793.826 * 1000.0),
	BUZZER_Note_FsGf7       = (unsigned int)(2959.955 * 1000.0),
	BUZZER_Note_G7          = (unsigned int)(3135.964 * 1000.0),
	BUZZER_Note_GsAf7       = (unsigned int)(3322.438 * 1000.0),
	BUZZER_Note_A7          = (unsigned int)(3520.000 * 1000.0),
	BUZZER_Note_AsBf7       = (unsigned int)(3729.310 * 1000.0),
	BUZZER_Note_B7          = (unsigned int)(3951.066 * 1000.0),

	BUZZER_Note_C8          = (unsigned int)(4186.009 * 1000.0),
	BUZZER_Note_CsDf8       = (unsigned int)(4434.922 * 1000.0),
	BUZZER_Note_D8          = (unsigned int)(4698.636 * 1000.0),
	BUZZER_Note_DsEf8       = (unsigned int)(4978.032 * 1000.0),
	BUZZER_Note_E8          = (unsigned int)(5274.042 * 1000.0),
	BUZZER_Note_F8          = (unsigned int)(5587.652 * 1000.0),
	BUZZER_Note_FsGf8       = (unsigned int)(5919.910 * 1000.0),
	BUZZER_Note_G8          = (unsigned int)(6271.928 * 1000.0),
	BUZZER_Note_GsAf8       = (unsigned int)(6644.876 * 1000.0),
	BUZZER_Note_A8          = (unsigned int)(7040.000 * 1000.0),
	BUZZER_Note_AsBf8       = (unsigned int)(7458.620 * 1000.0),
	BUZZER_Note_B8          = (unsigned int)(7902.132 * 1000.0),

	BUZZER_Note_C9          = (unsigned int)(8372.018 * 1000.0),
	BUZZER_Note_CsDf9       = (unsigned int)(8869.844 * 1000.0),
	BUZZER_Note_D9          = (unsigned int)(9399.272 * 1000.0),
	BUZZER_Note_DsEf9       = (unsigned int)(9956.064 * 1000.0),
	BUZZER_Note_E9          = (unsigned int)(10548.084 * 1000.0),
	BUZZER_Note_F9          = (unsigned int)(11175.304 * 1000.0),
	BUZZER_Note_FsGf9       = (unsigned int)(11839.820 * 1000.0),
	BUZZER_Note_G9          = (unsigned int)(12543.856 * 1000.0),
	BUZZER_Note_GsAf9       = (unsigned int)(13289.752 * 1000.0),
	BUZZER_Note_A9          = (unsigned int)(14080.000 * 1000.0),
	BUZZER_Note_AsBf9       = (unsigned int)(14917.240 * 1000.0),
	BUZZER_Note_B9          = (unsigned int)(15804.264 * 1000.0)
};

/**
 * This routine initializes the buzzer.
 *
 * @details Note this routine must be called before any other peripheral buzzer function.
 *
 * @param None.
 * @return None.
 */
void BUZZER_Init();

/**
 * This routine will have the buzzer play a note.
 *
 * @param Note :Specifies in hertz (Hz) per cycle that the buzzer should play.
 * @return None.
 */
void BUZZER_Start(unsigned int note);

/**
 * This routine will stop the buzzer from playing it's current note.
 *
 * @param None.
 * @return None.
 */
void BUZZER_Stop();;
#endif