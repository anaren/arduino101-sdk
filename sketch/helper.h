
#ifndef HELPER_H
#define HELPER_H

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

void anaren_return_char(BLECharacteristic *characteristic, char value, unsigned int length);

void anaren_return_bool(BLECharacteristic *characteristic, char value, unsigned int length);

void anaren_return_int(BLECharacteristic *characteristic, int value, unsigned int length);

void anaren_return_float(BLECharacteristic *characteristic, float value, unsigned int length);

void anaren_return_double(BLECharacteristic *characteristic, double value, unsigned int length);

void anaren_return_string(BLECharacteristic *characteristic, char *data, unsigned int length);

void anaren_return_json(BLECharacteristic *characteristic, char *jsonData, unsigned int length);

bool anaren_make_bool(const unsigned char *attrPtr);

char anaren_make_char(const unsigned char *attrPtr);

int anaren_make_int(const unsigned char *attrPtr);

float anaren_make_float(const unsigned char *attrPtr);

double anaren_make_double(const unsigned char *attrPtr);

#endif
