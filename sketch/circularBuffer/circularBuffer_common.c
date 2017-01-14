/**
 *  circularbuffer.c - implementation of a simple ring buffer.
 *
 *  @version    2.0.00
 *  @date       26 Feb 2014
 *  @author     Kieron Gillespie, kgillespie@anaren.com
 *              B Blincoe, bblincoe@anaren.com
 *
 */
#include "circularBuffer.h"

bool CircularBuffer_IsFull(struct sCircularBuffer *cb)
{
	if (cb->write < cb->end)
	{
		return ((cb->write + 1) == cb->read) ? true : false;
	}
	else
	{
		return (cb->start == cb->read) ? true : false;
	}
}

void CircularBuffer_Init(struct sCircularBuffer *cb,
						 unsigned char *buffer,
						 unsigned char size)
{
	if (buffer != NULL)
	{
		cb->start = buffer;
		cb->end = buffer + size - 1; // Using "Keep One Slot Open" implementation
		cb->write = cb->start;
		cb->read = cb->start;
	}
}

bool CircularBuffer_Write(struct sCircularBuffer *cb,
						  unsigned char writeByte)
{
	bool full = true;

	full = CircularBuffer_IsFull(cb);

	if (!full)
	{
		*(cb->write) = writeByte;
		if (cb->write < cb->end)
		{
			cb->write += 1;
		}
		else
		{
			cb->write = cb->start;
		}
	}

	return full;
}

bool CircularBuffer_Read(struct sCircularBuffer *cb,
						 unsigned char *readByte)
{
	bool empty = false;

	empty = CircularBuffer_IsEmpty(cb);

	if (!empty)
	{
		*readByte = *(cb->read);   // Read the current byte value from buffer
		if (cb->read < cb->end)
		{
			cb->read += 1;
		}
		else
		{
			cb->read = cb->start;
		}
	}

	return empty;
}
