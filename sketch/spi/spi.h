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

#ifndef AIR_SPI_H
#define AIR_SPI_H

#include <stdint.h>
#include "spi_config.h"

#include <stdbool.h>
#ifdef __cplusplus
extern "C"{
#endif

/**
 * SPI Configuration Structure
 */
typedef struct air_spi_conf_t
{
	uint8_t mode; //< Spi Mode (0 - 3)
	bool msbFirst; // true => MSB First, false => LSB First
	uint32_t speed; // Speed in hz
	bool ssActiveLow; // true => slave select active low, false => slave select active high
} air_spi_conf_t;

/**
 * This routine will initialize the micro controller's hardware to enable it for SPI communication.
 *
 * @details NOTE: This function must be executed before any other SPI function is used.
 *
 * @param None.
 * @return None.
 */
void AIR_SPI_Init();

/**
 * This routine will set the SPI transfer mode. Mode can be from 0 - 3
 *
 * @param spiConf - spi configuration structure
 */
void AIR_SPI_Configure(const air_spi_conf_t* const spiConf);

/**
 * This routine will enable the pin associated with the cspin parameter on the hardware to be used as the chip select pin.
 *
 * @details NOTE: In most cases this pin will be a standard GPIO output, but refer to your module's manual for more information.
 *
 * @param cspin :Specifies the pin number to enable.
 * @return None.
 */
void AIR_SPI_SetCSPin(int cspin);

/**
 * This routine will assert the pin associated with the cspin parameter so that communication over SPI to the target SPI device can begin.
 *
 * @details NOTE: You must use the function AIR_SPI_SetCSPin before you can use this function on the set pin.
 *
 * @param cspin :Specifies the pin number to assert.
 * @return None.
 */
void AIR_SPI_AssertCSPin(int cspin);

/**
 * This routine will remove (deassert) the corresponding pin associated with the cspin parameter so that communication over SPI to the target SPI device is stopped.
 *
 * @details NOTE: You must use AIR_SPI_SetCSPin before you can use this function on the set pin.
 *
 * @param cspin :Specifies the pin number to remove.
 * @return None.
 */
void AIR_SPI_DeassertCSPin(int cspin);

/**
 * This routine will assert the pin associated with the cspin parameter and will write bytes from the writeBytes parameter buffer up to the numWriteBytes parameter.
 *
 * @details NOTE: All reading information will be ignored. If a negative cspin parameter is given, then the associated pin will not be asserted or removed.
 *
 * @param cspin :Specifies the pin number to assert.
 * @param writeBytes :Specifies the string of characters for the routine to write.
 * @param numWriteBytes :Specifies the length of character string to write.
 * @return None.
 */
void AIR_SPI_Write(int cspin, unsigned char *writeBytes, unsigned int numWriteBytes);

/**
 * This routine will assert the pin associated with the cspin parameter and will read bytes up to the numReadBytes parameter then store them into the readBytes parameter buffer.
 *
 * @details NOTE: If a negative cspin parameter is given then the associated pin will not be asserted and deserted. The SPI bus will not be able to write to the device.
 *
 * @param cspin :Specifies the pin number to assert.
 * @param readBytes :Specifies the string of characters to store the returning data.
 * @param numReadBytes :Specifies the length of character string to read.
 * @return None.
 */
void AIR_SPI_Read(int cspin, unsigned char *readBytes, unsigned int numReadBytes);

/**
 * This routine will assert the pin associated with the cspin parameter and will read bytes up to the numberOfBytes parameter, and store them into the readBytes parameter buffer. Then it will write bytes from the writeBytes parameter buffer up to numberOfBytes parameter.
 *
 * @details NOTE: If a negative cspin parameter is given then the associated pin will not be asserted and deserted.
 *
 * @param cspin :Specifies the pin number to assert.
 * @param readBytes :Specifies the string of characters to store the returning data.
 * @param writeBytes :Specifies the string of characters for the routine to write.
 * @param numberOfBytes :Specifies the length of character string to read and write.
 * @return None.
 */
void AIR_SPI_Exchange(int cspin, unsigned char *readBytes, unsigned char *writeBytes, unsigned int numberOfBytes);

#ifdef __cplusplus
}
#endif

#endif /* AIR_SPI_H */
