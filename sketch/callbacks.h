
//Dynamically generated header, do not edit the following.
#ifndef CALLBACKS_H
#define CALLBACKS_H

#include <BLEAttribute.h>
#include <BLECentral.h>
#include <BLECharacteristic.h>
#include <BLECommon.h>
#include <BLEDescriptor.h>
#include <BLEPeripheral.h>
#include <BLEService.h>
#include <BLETypedCharacteristic.h>
#include <BLETypedCharacteristics.h>
#include <BLEUuid.h>
#include <CurieBLE.h>
#include <Arduino.h>

#include "gpio/gpio.h"
#include "i2c/i2c.h"
#include "spi/spi.h"
#include "uart/uart.h"

namespace atmosphere
{
	void setup();

	void interval();

	void connected();

	void disconnected();

	#define ID_GPIOToggle1 0x0
	bool GPIOToggle1(bool data);
}
#endif
