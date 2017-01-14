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

#ifndef AIR_GATT_H
#define AIR_GATT_H

/*
 * GAP Service API
 */

/**
 * This routine will set the device's GATT name to the name parameter.
 *
 * @param name :Specifies the string which will be set to the Device Name.
 * @return None.
 */
void AIR_GATT_GAP_SetDeviceName(char *name);

void AIR_GATT_GAP_GetDeviceName(char *buffer, unsigned int length);

/*
 * Battery Service API
 */

/**
 * This routine will set the level of the GATT Battery to the level parameter.
 *
 * @param level :Specifies the characters which the GATT Battery will be set to.
 * @return None.
 */
void AIR_GATT_BATTERY_SetLevel(char level);

/**
 * This routine will retrieve the current GATT Battery level.
 *
 * @param None.
 * @return This routine returns the current GATT Battery level.
 */
char AIR_GATT_BATTERY_GetLevel();

/**
 * This routine will set the GATT Battery level to the level parameter and notify the device on the update.
 *
 * @param level :Specifies the characters which the GATT Battery will be set to.
 * @return None.
 */
void AIR_GATT_BATTERY_SetAndNotifyLevel(char level);

/**
 * This routine will notify the device as if the GATT Battery level is set to level parameter.
 *
 * @param level :Specifies the characters which the GATT Battery will be set to.
 * @return None.
 */
void AIR_GATT_BATTERY_NotifyLevel(char level);

/**
 * This routine will notify the device about the current GATT Battery level.
 *
 * @param None.
 * @return None.
 */
void AIR_GATT_BATTERY_NotifyCurrentLevel();

/*
 * Immediate Alert Service API
 */
typedef enum
{
	AIR_GATT_IMMEDIATE_ALERT_NO_ALERT = 0,
	AIR_GATT_IMMEDIATE_ALERT_MILD_ALERT = 1,
	AIR_GATT_IMMEDIATE_ALERT_HIGH_ALERT = 2,
	AIR_GATT_IMMEDIATE_ALERT_RESERVED = 255
} AIR_GATT_IMMEDIATE_ALERT_Type;

typedef void (*air_immediate_alert_callback_func_ptr)(AIR_GATT_IMMEDIATE_ALERT_Type);

/**
 * This routine will register a user-defined callback function. Whenever the AIR_GATT_IMMEDIATE_ALERT_Type changes, the user's callback function will be called with the parameter of the AIR_GATT_IMMEDIATE_ALERT_Type that has been changed to.
 *
 * @param func :A function that is to be called whenever the AIR_GATT_IMMEDIATE_ALERT_Type changes that returns as void and takes an AIR_GATT_IMMEDIATE_ALERT_Type as its single argument. Example: void myGATTCallback(AIR_GATT_IMMEDIATE_ALERT_Type Alert) { }.
 * @return None.
 */
void AIR_GATT_IMMEDIATE_ALERT_RegisterCallback(air_immediate_alert_callback_func_ptr func);

/**
 * This routine will execute a user-defined callback function with the parameter of the AIR_GATT_IMMEDIATE_ALERT_Type associated with the data parameter.
 *
 * @param data :A char of 0,1,2,255 that associate with the AIR_GATT_IMMEDIATE_ALERT_Type that you want to trigger.
 * @return None.
 */
void AIR_GATT_IMMEDIATE_ALERT_ExecuteCallback(unsigned char data);

/*
 * Blood Pressure Service API
 */

// typedef enum {
//      AIR_GATT_BLOOD_PRESSURE_FEATURE_BODY_MOVEMENT_DETECTION = 1,
//      AIR_GATT_BLOOD_PRESSURE_FEATURE_CUFF_FIT_DETECTION = 2,
//      AIR_GATT_BLOOD_PRESSURE_FEATURE_IRREGULAR_PULSE_DETECTION = 4,
//      AIR_GATT_BLOOD_PRESSURE_FEATURE_PULSE_RATE_DETECTION = 8,
//      AIR_GATT_BLOOD_PRESSURE_FEATURE_MEASUREMENT_POSITION_DETECTION = 16,
//      AIR_GATT_BLOOD_PRESSURE_FEATURE_MULTIPLE_BOND_SUPPORT = 32
// } AIR_GATT_BLOOD_PRESSURE_FEATURES;
//
// typedef enum {
//      AIR_GATT_BLOOD_PRESSURE_FLAG_UNITS_kPa = 1,
//      AIR_GATT_BLOOD_PRESSURE_FLAG_TIME_STAMP_ENABLE = 2,
//      AIR_GATT_BLOOD_PRESSURE_FLAG_PULSE_RATE_ENABLE = 4,
//      AIR_GATT_BLOOD_PRESSURE_FLAG_USER_ID_ENABLE = 8,
//      AIR_GATT_BLOOD_PRESSURE_FLAG_MEASUREMENT_STATUS_ENABLE = 16
// } AIR_GATT_BLOOD_PRESSURE_FLAGS;
//
//
// void AIR_GATT_BLOOD_PRESSURE_IndicateBloodPressureMeasurement(uint16_t flags, uint8_t *data);
//
// void AIR_GATT_BLOOD_PRESSURE_NotifyIntermediateCuffPressure(uint16_t flags, uint8_t *data);
//
// void AIR_GATT_BLOOD_PRESSURE_SetBloodPressureFeature(uint16_t flags);
#endif /* AIR_GATT_H */
