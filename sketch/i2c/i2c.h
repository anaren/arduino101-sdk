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

#ifndef AIR_I2C_H
#define AIR_I2C_H

#ifdef __cplusplus
  extern "C"{
#endif


/**
 * This routine initializes the I2C.
 *
 * @param None.
 * @return None.
 */
void AIR_I2C_Init();

/**
 * This routine will read onto the slaveAddr parameter and place bytes up to the numReadBytes parameter into the readBytes parameter buffer. Then it will write onto the slaveAddr parameter from the writeBytes parameter up to the limit of numWriteBytes parameter.
 *
 * @param slaveAddr :The address of the target I2C device.
 * @param writeBytes :A pointer to a buffer that will be written out on the I2C line.
 * @param numWriteBytes :The number of bytes that will be written out from the writeBytes buffer.
 * @param readBytes :A pointer to a buffer for storing the bytes that will be read from the I2C line.
 * @param numReadBytes :The number of bytes that will be read from the readBytes buffer.
 * @return None.
 */
void AIR_I2C_ComboRead(unsigned char slaveAddr, unsigned char* writeBytes, unsigned int numWriteBytes, unsigned char* readBytes, unsigned int numReadBytes);

/**
 * This routine will write onto the slaveAddr parameter from a writeBytes parameter buffer up to the limit of numBytes parameter.
 *
 * @param slaveAddr :The address of the target I2C device, do not append the write/read bit to the end of this address.
 * @param writeBytes :A pointer to the bytes that should be written out on the I2C line.
 * @param numBytes :The number of bytes that will be written out from the writeBytes buffer.
 * @return None.
 */
void AIR_I2C_Write(unsigned char slaveAddr, unsigned char* writeBytes, unsigned int numBytes);

/**
 * This routine will read from the slaveAddr parameter and place bytes up to the numBytes parameter onto the readBytes parameter buffer.
 *
 * @param slaveAddr :The address of a target I2C device.
 * @param readBytes :A pointer to a buffer for storing the read in bytes from I2C.
 * @param numBytes :The number of bytes that should be read in and placed into the readBytes buffer.
 * @return None.
 */
void AIR_I2C_Read(unsigned char slaveAddr, unsigned char *readBytes, unsigned int numBytes);

#ifdef __cplusplus
  }
#endif

#endif /* AIR_I2C_H */
