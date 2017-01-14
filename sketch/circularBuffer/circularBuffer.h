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

#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#define CIRCULAR_BUFFER "1.0.00"

#include <stdbool.h>

#ifndef NULL
#define NULL  (void*)0
#endif

// -----------------------------------------------------------------------------
/**
 *  Defines, enumerations, and structure definitions
 */

///**
// *  sCircularBufferCriticalRegion - represents a circular buffer critical
// *  region. This area must be performed in an "atomic" instruction (cannot be
// *  interrupted). Enter represents disabling interrupts, while Exit represents
// *  reissuing the state that the system was in prior to disabling interrupts.
// */
//struct sCircularBufferCriticalRegion
//{
//  unsigned int(*const Enter)(void);
//  void(*const Exit)(unsigned int);
//};

/**
 *  sCircularBuffer - represents a circular buffer.
 */
struct sCircularBuffer
{
//  const struct sCircularBufferCriticalRegion *criticalRegion;
	unsigned char *start;
	unsigned char *end;
	unsigned char *write;
	unsigned char *read;
};

// -----------------------------------------------------------------------------
/**
 *  Global data
 */

// -----------------------------------------------------------------------------
/**
 *  Public Interface
 */

/**
 * This routine checks if the circular buffer is empty.
 *
 *@param  cb :Specifies the circular buffer to check.
 *@return This routine returns true if the cb parameter is empty.
 */
#define CircularBuffer_IsEmpty(cb) ((cb->write == cb->read) ? true : false)

/**
 * This routine checks if the circular buffer is full.
 *
 *@param  cb :Specifies the circular buffer to check.
 *@return This routine returns true if the cb parameter is full.
 */
bool CircularBuffer_IsFull(struct sCircularBuffer *cb);

/**
 * This routine will get the count of items currently stored in the circular buffer.
 *
 * @param cb :Specifies the circular buffer to check.
 * @return This routine returns count of items in the circular buffer.
 */
#define CircularBuffer_Count(cb) ((cb->write >= cb->read) ? (cb->write - cb->read) : (cb->end - cb->read + cb->write - cb->start + 1))

/**
 * This routine will get the count of slots currently available in the buffer for items to be stored to.
 *
 * @param cb :Specifies the circular buffer to check.
 * @return This routine returns a count of how many items can be written to the circular buffer.
 */
#define CircularBuffer_Available(cb) ((cb->read > cb->write) ? (cb->read - cb->write - 1) : (cb->end - cb->write + cb->read - cb->start))

/**
 * This routine will initialize a circular buffer instance.
 *
 * @details NOTE: This implementation of a circular buffer keeps one slot open. It is assumed that the buffer used to create a circular buffer is one byte bigger than what is actually needed. This last byte becomes "wasted" and is used to differentiate between empty and full states.
 *
 * @param cb :Specifies the circular buffer to check.
 * @param buffer :Specifies the buffer to be used as a circular buffer. The last byte in the buffer is used to differentiate between empty and full states.
 * @param size :Specifies the size of the usable buffer.
 * @return None.
 */
void CircularBuffer_Init(struct sCircularBuffer *cb,
						 unsigned char *buffer,
						 unsigned char size);

/**
 * This routine will write a byte to the circular buffer.
 *
 * @param cb :Specifies the circular buffer to check.
 * @param writeByte :Specifies the byte to be written to the circular buffer.
 * @return This routine returns "true" when the CircularBufferWrite is full, indicating that a new byte could not be written.
 */
bool CircularBuffer_Write(struct sCircularBuffer *cb,
						  unsigned char writeByte);

/**
 * This routine will read a byte from the circular buffer.
 *
 * @details NOTE: ... For additional information
 *
 * @param cb :Specifies the circular buffer to check.
 * @param readByte :Specifies the byte to be read from the circular buffer.
 * @return This routine returns "true" when the CircularBufferRead is empty, indicating that a byte could not be read.
 */
bool CircularBuffer_Read(struct sCircularBuffer *cb,
						 unsigned char *readByte);
#endif  /* CIRCULAR_BUFFER_H */
