
#include "helper.h"		
		
void anaren_return_char(BLECharacteristic *characteristic, char value, unsigned int length)
{
	char buf[1];
	
	buf[0] = value;
	
	characteristic->setValue((const unsigned char*)buf, 1);
}

void anaren_return_bool(BLECharacteristic *characteristic, char value, unsigned int length)
{
	char buf[1];
	
	buf[0] = value;
	
	characteristic->setValue((const unsigned char*)buf, 1);
}

void anaren_return_int(BLECharacteristic *characteristic, int value, unsigned int length)
{
	union {
		int variable;
		unsigned char temp_array[4];
	} u;
	
	u.variable = value;
	
	characteristic->setValue((const unsigned char*)u.temp_array, 4);
}

void anaren_return_float(BLECharacteristic *characteristic, float value, unsigned int length)
{
	union {
		float variable;
		unsigned char temp_array[4];
	} u;
	
	u.variable = value;
	
	characteristic->setValue((const unsigned char*)u.temp_array, 4);
}

void anaren_return_double(BLECharacteristic *characteristic, double value, unsigned int length)
{
	union {
		double variable;
		unsigned char temp_array[8];
	} u;
	
	u.variable = value;
	
	characteristic->setValue((const unsigned char*)u.temp_array, 8);
}

void anaren_return_string(BLECharacteristic *characteristic, char *data, unsigned int length)
{

}
	
void anaren_return_json(BLECharacteristic *characteristic, char *jsonData, unsigned int length)
{

}

bool anaren_make_bool(const unsigned char *attrPtr)
{
	return (bool)attrPtr[0];
}

char anaren_make_char(const unsigned char *attrPtr)
{
	return (char)attrPtr[0];
}

int anaren_make_int(const unsigned char *attrPtr)
{
	union {
		int variable;
		unsigned char temp_array[4];
	} u;
	
	memcpy(u.temp_array, attrPtr, 4);
	
	return u.variable;
}

float anaren_make_float(const unsigned char *attrPtr)
{
	union {
		float variable;
		unsigned char temp_array[4];
	} u;
	
	memcpy(u.temp_array, attrPtr, 4);
	
	return u.variable;
}

double anaren_make_double(const unsigned char *attrPtr)
{
	union {
		double variable;
		unsigned char temp_array[8];
	} u;
	
	memcpy(u.temp_array, attrPtr, 8);
	
	return u.variable;
}
