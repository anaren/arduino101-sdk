#include <Arduino.h>
#line 1 "/home/kgillespie/Arduino/uno101_test/uno101_test.ino"
#line 1 "/home/kgillespie/Arduino/uno101_test/uno101_test.ino"

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
#include "callbacks.h"
#include "helper.h"

BLEPeripheral atmosphereBLEPeripheral;
BLEService atmospherePrimaryService("33152b22-555a-48cd-8cf4-32cf6bc6072e");
BLECharacteristic atmosphereNotifyEvent("33152b22-555a-48cd-8cf4-32cf6bc6072f", BLERead | BLEWrite | BLEWriteWithoutResponse | BLENotify, 128);
BLECharacteristic GPIOToggle1Characteristic("33152b22-555a-48cd-8cf4-32cf6bc60730", BLERead | BLEWriteWithoutResponse | BLEWrite, 0x1);

#line 21 "/home/kgillespie/Arduino/uno101_test/uno101_test.ino"
void characteristicSubscribed(BLECentral& central, BLECharacteristic& characteristic);
#line 26 "/home/kgillespie/Arduino/uno101_test/uno101_test.ino"
void characteristicUnsubscribed(BLECentral& central, BLECharacteristic& characteristic);
#line 31 "/home/kgillespie/Arduino/uno101_test/uno101_test.ino"
void setup();
#line 50 "/home/kgillespie/Arduino/uno101_test/uno101_test.ino"
void loop();
#line 21 "/home/kgillespie/Arduino/uno101_test/uno101_test.ino"
void characteristicSubscribed(BLECentral& central, BLECharacteristic& characteristic) {
  // characteristic subscribed event handler
  //Serial.println(F("Characteristic event, subscribed"));
}

void characteristicUnsubscribed(BLECentral& central, BLECharacteristic& characteristic) {
  // characteristic unsubscribed event handler
  //Serial.println(F("Characteristic event, unsubscribed"));
}

void setup() {

	atmosphereBLEPeripheral.setLocalName("Atmo101");
	atmosphereBLEPeripheral.setAdvertisedServiceUuid(atmospherePrimaryService.uuid());
	atmosphereBLEPeripheral.setDeviceName("Atmosphere Test");
	// add service and characteristics
	atmosphereBLEPeripheral.addAttribute(atmospherePrimaryService);
	atmosphereBLEPeripheral.addAttribute(atmosphereNotifyEvent);
	
	atmosphereNotifyEvent.setEventHandler(BLESubscribed, characteristicSubscribed);
	atmosphereNotifyEvent.setEventHandler(BLEUnsubscribed, characteristicSubscribed);

	GPIOToggle1Characteristic.setValue((const unsigned char[]){0x0}, 0x1);
	atmosphereBLEPeripheral.addAttribute(GPIOToggle1Characteristic);

	atmosphereBLEPeripheral.begin();
	atmosphere::setup();
}

void loop() {
	// poll peripheral
	atmosphereBLEPeripheral.poll();

	if(GPIOToggle1Characteristic.written()) {
		anaren_return_bool(&GPIOToggle1Characteristic, atmosphere::GPIOToggle1(anaren_make_bool(GPIOToggle1Characteristic.value())), 0x1);
	}

	atmosphere::interval();
}


