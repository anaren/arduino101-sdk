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

#ifndef JSON_H
#define JSON_H

#include <stdbool.h>
#include "json_config.h"

enum JSON_ERROR_CODE
{
	JSON_NO_ERROR = 0,
	JSON_PARSING_ERROR,             /* Input with an internal pull-up resistor - use with devices that actively drive the signal low - e.g. button connected to ground */
	JSON_RETURN_TO_LARGE,
	JSON_MISSING_CAPABILITY,
};

/**
 * This routine initializes the JSON API so that it can be ready for use. It will allocate any memory it needs and reset the error flags.
 *
 * @param None.
 * @return None.
 */
void JSON_Init();

/**
 * This routine will return the last error that the JSON API encounter. The types of errors that can be returned are listed in the Constants section.
 *
 * @param None.
 * @return This routine returns a JSON error code from the API, please refer to Constants section.
 */
int JSON_GetError();

/**
 * This routine will read the given character array and parse it for a properly-formatted JSON char.
 *
 * @param jsonString :A pointer to a character array containing a null terminated string that is a JSON integer.
 * @return If the character array passed to JSON_ReadChar is a correctly-formatted JSON string/integer/float, then this function will return the first valid character in the JSON object.
 */
char JSON_ReadChar(char *jsonString);

/**
 * This routine will read the given character array and parse it for a properly-formatted JSON integer.
 *
 * @param jsonString :A pointer to a character array containing a null terminated string that is a JSON integer.
 * @return If the character array passed to JSON_ReadInt is a correctly-formatted JSON integer, then this function will return the integer value. If it is not, it will return zero and the user can then use JSON_GetError to determine why it was rejected.
 */
int JSON_ReadInt(char *jsonString);

/**
 * This routine will parse a properly-formatted JSON floating point value and return it as a standard floating point value.
 *
 * @param jsonString :A null terminated character string that contains the JSON floating point object.
 * @return On success this function will return the value of the JSON floating point object as a standard floating point value. If it fails this function will return 0.0f and the user can then use the JSON_GetError function to determine why the value was rejected.
 */
float JSON_ReadFloat(char *jsonString);

/**
 * This routine will parse a properly-formatted JSON string value and return it as a standard string value.
 *
 * @param jsonString :A null terminated character string that contains the JSON string object.
 * @return On success, this function will return the value of the JSON string object as a standard string value. If it fails, this function will return '\0' and the user can then use the JSON_GetError function to determine why the value was rejected.
 */
char *JSON_ReadString(char *jsonString);

/**
 * This routine will parse a properly-formatted JSON Boolean value and return it as a standard Boolean value.
 *
 * @param jsonString :A null terminated character string that contains the JSON Boolean object.
 * @return On success, this function will return the value of the JSON Boolean object as a standard Boolean value. If it fails, this function will return false and the user can then use the JSON_GetError function to determine why the value was rejected.
 */
bool JSON_ReadBoolean(char *jsonString);

/**
 * This routine will write a JSON object with the standard value parameter.
 *
 * @param value :A standard integer value.
 * @return On success, this function will return the value of the standard integer as a JSON object. If it fails, this function will return zero and the user can then use the JSON_GetError function to determine why the value was rejected.
 */
char *JSON_WriteInt(int value);

/**
 * This routine will write a JSON object with the standard value parameter.
 *
 * @param value :A standard float value.
 * @return On success, this function will return the value of the standard float as a JSON object. If it fails, this function will return 0.0F and the user can then use the JSON_GetError function to determine why the value was rejected.
 */
char *JSON_WriteFloat(float value);

/**
 * This routine will write a JSON object with the standard string parameter.
 *
 * @param string :A standard string value.
 * @return On success, this function will return the value of the standard string as a JSON object. If it fails, this function will return '\0' and the user can then use the JSON_GetError function to determine why the value was rejected.
 */
char *JSON_WriteString(char *string);

/**
 * This routine will write a JSON object with the standard value parameter.
 *
 * @param value :A standard Boolean value.
 * @return On success, this function will return the value of the standard Boolean as a JSON object. If it fails, this function will return false and the user can then use the JSON_GetError function to determine why the value was rejected.
 */
char *JSON_WriteBoolean(bool value);
#endif  /* JSON_H */