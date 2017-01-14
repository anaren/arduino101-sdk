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

#ifndef AIR_BLE_H
#define AIR_BLE_H

#include <stdbool.h>

typedef enum
{
	AIR_BLE_DISCOVERABLE_NONE = 0,
	AIR_BLE_DISCOVERABLE_UNDIRECTED,
	AIR_BLE_DISCOVERABLE_DIRECTED,
} AIR_BLE_DiscoveryMode;

typedef enum
{
	AIR_BLE_PAIRING_NONE = 0,
	AIR_BLE_PAIRING_OPEN,
	AIR_BLE_PAIRING_OOB,
	AIR_BLE_PAIRING_PASSKEY,
} AIR_BLE_PairingMode;

/**
 * This routine initialize the BLE subsystem.
 *
 * @param None.
 * @return None.
 */
void AIR_BLE_Init();

/**
 * This routine will set if it is possible to discover the object.
 *
 * @param discoverable :Specifies the state if it can be discovered or not.
 * @return None.
 */
void AIR_BLE_SetDiscoverable(bool discoverable);

/**
 * This routine sets an address parameter to be discoverable or not.
 *
 * @param discoverable :Specifies the state if it can be discovered or not.
 * @param address :Specifies the BLE Address.
 * @return None.
 */
void AIR_BLE_SetDirectedDiscoverable(bool discoverable, unsigned char *address);

/**
 * This routine will get the current AIR_BLE_DiscoveryMode.
 *
 * @param None.
 * @return This routine returns one of the three states of AIR_BLE_DiscoveryMode.
 */
AIR_BLE_DiscoveryMode AIR_BLE_GetDiscoverable();

/**
 * This routine will set the AIR_BLE_PairingMode to the parameter mode.
 *
 * @param mode :Specifies the AIR_BLE_PairingMode that this routine will set it to.
 * @return None.
 */
void AIR_BLE_SetPairingMode(AIR_BLE_PairingMode mode);

/**
 * This routine will set the passkey to the key parameter, up to the length parameter.
 *
 * NOTE: To use the passkey, you must be in AIR_BLE_PAIRING_PASSKEY pairing mode.
 *
 * @param key :Specifies the key to be set as the passkey.
 * @param length :Specifies the maximum length of the key.
 * @return None.
 */
void AIR_BLE_SetPassKey(unsigned char *key, unsigned int length);

/**
 * This routine will set the temporary key to the tk parameter, up to the length parameter
 *
 * NOTE: To use the temporary key, you must be in AIR_BLE_PAIRING_OOB pairing mode.
 *
 * @param tk :Specifies the key to be set as the temporary key.
 * @param length :Specifies the maximum length of the key.
 * @return None.
 */
void AIR_BLE_SetOOBTk(unsigned char *tk, unsigned int length);

/**
 * This routine will return a MAC address as a formatted string and place it into addressBuf.
 *
 * @param addressBuf :Specifies the pointer to the buffer to store the MAC address.
 * @param length :Specifies the maximum length of the address.
 * @return None.
 */
void AIR_BLE_GetMacAddress(unsigned char *addressBuf, unsigned int length);
#endif /* AIR_BLE_H */
