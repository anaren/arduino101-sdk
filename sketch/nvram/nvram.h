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

#ifndef AIR_NVRAM_H
#define AIR_NVRAM_H

/**
 * This routine will enables the NVRAM subsystem of the target micro-controller.
 *
 * @details NOTE: This routine must be executed before any other NVRAM function is used.
 *
 * @param None.
 * @return None.
 */
void AIR_NVRAM_Init();

/**
 * This routine will store the data parameter buffer, up to the length parameter, into the NVRAM page selected by the block parameter.
 *
 * @details NOTE: The block parameter must be an address from 0x11 to 0x6F inclusively. The length parameter must be an integer from 1 to 255 inclusively.
 *
 * @param block :Specifies the identifier for the location in NVRAM.
 * @param data :Specifies a pointer to the buffer where the input data is stored.
 * @param length :Specifies the length of bytes to write to the NVRAM.
 * @return This routine returns the number of bytes stored in NVRAM if the routine was successful, else returns 0 that indicates failure.
 */
unsigned int AIR_NVRAM_Write(unsigned int block, unsigned char *data, unsigned int length);

/**
 * This routine will retrieve the data previously stored up to the length parameter (based on the block parameter), and then store it into the data parameter.
 *
 * @details NOTE: The block parameter must be an address from 0x11 to 0x6F inclusively. The length parameter must be an integer from 1 to 255 inclusively.
 *
 * @param block :Specifies the identifier for the location in NVRAM.
 * @param data :Specifies a pointer to the buffer where the data read from NVRAM will be stored.
 * @param length :Specifies the length of bytes to read from the NVRAM.
 * @return This routine returns the number of bytes stored in NVRAM if the routine was successful, else returns 0 that indicates failure.
 */
unsigned int AIR_NVRAM_Read(unsigned int block, unsigned char *data, unsigned int length);

/**
 * This routine will remove the block associated with the block parameter from the NVRAM memory.
 *
 * @param block :Specifies the identifier for the location in NVRAM.
 * @return None.
 */
void AIR_NVRAM_Delete(unsigned int block);
#endif /* AIR_NVRAM_H */
