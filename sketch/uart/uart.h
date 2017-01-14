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

#ifndef AIR_UART_H
#define AIR_UART_H

#ifdef __cplusplus
extern "C"{
#endif
#include <stdbool.h>

#include "uart_config.h"

typedef void (*air_uart_callback_func_ptr)(char);

/**
 * This routine will initializes all required UART subsystems of the board.
 *
 * @details NOTE: This routine must be called before any other peripheral UART function.
 *
 * @param None.
 * @return None.
 */
void AIR_UART_Init();

/**
 * This routine will changes the baud rate of the UART subsystem.
 *
 * @param baudrate :Specifies the pulses per second which UART will be set to.
 * @return None.
 */
void AIR_UART_SetBaudRate(unsigned int baudrate);

unsigned int AIR_UART_SynchronousWrite(unsigned char* pBuffer, unsigned int count);

/**
 * This routine will writes a string of characters out to the UART Tx buffer to the number of bytes then the UART driver is told to start shifting those bytes out the serial port.
 *
 * @param pBuffer :Specifies the string of characters for the routine to write.
 * @param count :Specifies the length of character string to write.
 * @return This routine returns the number of characters actually written.
 */
unsigned int AIR_UART_Write(unsigned char* pBuffer, unsigned int count);

/**
 * This routine will writes a string of characters out to the UART Tx buffer until it has reached a NULL '\0' character, or until the count parameter is meet.
 *
 * @param pBuffer :Specifies the string of characters for the routine to write.
 * @param count :Specifies the length of character string to write.
 * @return This routine returns the number of characters actually written.
 */
// unsigned char AIR_UART_StrnPrint(unsigned char*, unsigned int);

/**
 * This routine will writes a string of characters out to the UART Tx buffer until it has reached a NULL '\0' character, or until the buffer overflow pass its memory bounds.
 *
 * @param pBuffer :Specifies a null terminated character string to be transmitted via UART.
 * @return This routine returns the number of characters placed onto the Tx buffer.
 */
unsigned int AIR_UART_Print(const char * pBuffer);


unsigned int AIR_UART_SynchronousRead(unsigned char* pBuffer, unsigned int count);

/**
 * This routine will insert the contents of the Rx buffer into the pBuffer parameter, up to the limit of the count parameter.
 *
 * @details NOTE: If there are bytes that exceed the value of the count parameter, then those bytes will remain in the Rx buffer until another read function is performed.
 *
 * @param pBuffer :Specifies the buffer to store the returning data from UART.
 * @param count :Specifies the maximum number of characters to be read in.
 * @return This routine returns the number of characters actually read.
 */
unsigned int AIR_UART_Read(unsigned char* pBuffer, unsigned int count);

/**
 * This routine will insert the contents of the Rx buffer into the buffer parameter, up to one less than the limit of the count parameter. The buffer will be NULL terminated.
 *
 * @details NOTE: If there are bytes that exceed or are equal to the count parameter, then those bytes will remain in the Rx buffer until another read function is performed.
 *
 * @param pBuffer :Specifies the buffer to store the returning data from UART.
 * @param count :Specifies the size of the buffer, and one less than the maximum number of characters to be read in.
 * @return This routine returns the number of characters actually read.
 */
unsigned int AIR_UART_StrnRead(unsigned char*, unsigned int);

/**
 * This routine will return the number of bytes currently in the Rx buffer.
 *
 * @param None.
 * @return This routine returns the number of bytes currently in the buffer.
 */
unsigned int AIR_UART_AvailableRX();

/**
 * This routine will return the number of slots currently available in the Tx buffer for items to be stored to.
 *
 * @param None.
 * @return This routine returns the number of items that can be written to the Tx buffer
 */
unsigned int AIR_UART_AvailableTX();

/**
 * This routine will empty the contents of the Tx buffer of the peripheral UART.
 *
 * @param None.
 * @return None.
 */
void AIR_UART_FlushTX();

/**
 * This routine will empty the contents of the Rx buffer of the peripheral UART.
 *
 * @param None.
 * @return None.
 */
void AIR_UART_FlushRX();

/**
 * This routine will register or unregister a user-defined callback function. Whenever a byte is received into the Rx buffer, the user's callback function will be called with the parameter of byte that was received.
 *
 * @param func :Specifies a function that is to be called during the UART Rx interrupt that returns as void and takes a char as its single argument, or NULL to unregister a previously-registered, user-defined callback function. Example: void myRXCallback(char c) { }.
 * @return None.
 */
void AIR_UART_RegisterRXCallback(air_uart_callback_func_ptr func);

/**
 * This routine will register or unregister a user-defined callback function. Whenever a byte is transmitted into the Tx buffer, the user's callback function will be called with the parameter of that byte that was sent to the Tx buffer.
 *
 * @param func :Specifies a function that is to be called during the UART Tx interrupt that returns as void and takes a char as its single argument, or NULL to unregister a previously-registered, user-defined callback function. Example: void myTXCallback(char c) { }.
 * @return None.
 */
void AIR_UART_RegisterTXCallback(air_uart_callback_func_ptr func);

#ifdef __cplusplus
}
#endif

#endif
