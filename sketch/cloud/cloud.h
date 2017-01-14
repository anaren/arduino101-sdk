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

#ifndef CLOUD_H
#define CLOUD_H

#include "cloud_config.h"
#include <stdint.h>
#include <stdbool.h>

typedef struct CLOUD_Registration_t
{
	char uuid[64]; //Example "05a48cf8-0849-443c-aa67-4751450cbe15"
	char projectUuid[64];
	char token[64];
} CLOUD_Registration;

typedef struct
{
	char uuid[64]; //Example "05a48cf8-0849-443c-aa67-4751450cbe15"
	char projectUuid[64];
	char token[64];
} cloud_app_dct_t;

typedef enum cloud_err_t
{
	CLOUD_OK = 0,
	CLOUD_GEN_ERR = -1,
	CLOUD_CREATE_SOCKET = -2,
	CLOUD_ENABLE_TLS = -3,
	CLOUD_TCP_CONNECT = -4,
	CLOUD_TCP_SEND = -5,
	CLOUD_TCP_RECEIVE = -6,
	CLOUD_TCP_DISCONNECT = -7,
	CLOUD_DELETE_SOCKET = -8,
	CLOUD_SAVE_REGISTRATION = -9,
	CLOUD_LOAD_REGISTRATION = -10,
} cloud_err_t;


/**
 * CLOUD_Init will initialize any subsystems that
 * communicating with Cloud may require.
 * If the microcontroller supports it this will also
 * attmempt to load the current registration from NVRam and
 * then set it as the current registration value. If there
 * is not any, or it does not match the current firmware code
 * then it is ignored and registration will either have to be done
 * manually or with the registration.
   @param pin The pin to configure with the mode flags.
   @param mode The configuration mode flags.
 */
cloud_err_t CLOUD_Init();

bool CLOUD_IsRegistered();

cloud_err_t CLOUD_RegisterThing(char *name, char *owner, char *password, char *meta, char *postProvisionToken);

cloud_err_t CLOUD_SaveRegistration(CLOUD_Registration *registration);

cloud_err_t CLOUD_LoadRegistration(CLOUD_Registration *registration);

cloud_err_t CLOUD_SetCurrentRegistration(CLOUD_Registration *registration);

cloud_err_t CLOUD_GetCurrentRegistration(CLOUD_Registration *registration);

/**
 * Send event data to event element handle
 *
 * @param[in] eventName - which command to retrieve data for
 * @param[out] eventData - char buffer to be filled with command reply data
 *
 */
cloud_err_t CLOUD_SendEvent(const char *eventName, const char *eventData);

/**
 * Pop command data from specified command FIFO
 *
 * @param[in] commandName - which command to retrieve data for
 * @param[out] commandReply - char buffer to be filled with command reply data
 * @param[in] commandReplySize - size of cmdReplyBuffer
 *
 */
cloud_err_t CLOUD_PopCommand(const char* commandName, char* commandReply, uint32_t commandReplySize);

/**
 * Peek at next command from specified command FIFO, this will retrieve the value without removing it from the FIFO
 *
 * @param[in] commandName - which command to retrieve data for
 * @param[out] commandReply - char buffer to be filled with command reply data
 * @param[in] commandReplySize - size of cmdReplyBuffer
 *
 */
cloud_err_t CLOUD_PeekCommand(const char* commandName, char* commandReply, uint32_t commandReplySize);

/**
 *
 * Send meta data to thing  meta tag
 * @param[in] metaTag - meta Tag we want to update
 * @param[in] metaData - data we want to assign to this tag
 * @return - cloud_err_t based on success of send
 */

cloud_err_t CLOUD_SendMeta(const char * metaTag, const char* metaData);

#endif
