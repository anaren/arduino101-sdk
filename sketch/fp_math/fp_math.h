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

#ifndef FP_MATH_H_
#define FP_MATH_H_

#include <stdint.h>

#define INFINITY (__builtin_inff())
#define NAN (__builtin_nanf(""))

/**
 * This routine will add two parameters together.
 *
 * @param a :Specifies the first value to add together.
 * @param b :Specifies the second value to add together.
 * @return This routine returns the sum of the two parameters.
 */
float fp_add(float a, float b);

/**
 * This routine will subtract two parameters together.
 *
 * @param a :Specifies the first value to subtract together.
 * @param b :Specifies the second value to subtract together.
 * @return This routine returns the difference of the two parameters.
 */
float fp_sub(float a, float b);

/**
 * This routine will multiply two parameters together.
 *
 * @param a :Specifies the first value to multiply together.
 * @param b :Specifies the second value to multiply together.
 * @return This routine returns the product of the two parameters.
 */
float fp_mult(float a, float b);

/**
 * This routine will divide the two parameters together.
 *
 * @param a :Specifies the first value to divide together.
 * @param b :Specifies the second value to divide together.
 * @return This routine returns the quotient of the two parameters.
 */
float fp_div(float a, float b);

/**
 * This routine will take a parameter and raise it to the power of n parameter.
 *
 * @param a :Specifies the base to be raised.
 * @param n :Specifies the exponent to be raised to.  Can be positive or negative.  
 * @return This routine returns the power of the two parameters.
 */
float fp_pow(float a, int16_t n);

/**
 * This routine will produce the square root of a parameter.
 *
 * @param a :Specifies the value to be square rooted.
 * @return This routine returns the square root of the parameter.
 */
float fp_sqrt(float a);

/**
 * This routine will compare the two parameters.
 *
 * @param a :Specifies the value that is going to be compared.
 * @param b :Specifies the value that is going to be compared.
 * @return This routine returns a 1 if a parameter is greater than b parameter, 0 if the two parameters are equal to each other, and -1 if a parameter is less than b parameter.
 */
int8_t fp_cmp(float a, float b);

/**
 * This routine calls fp_sqrt, which calculates the square root of the parameter
 *
 * NOTE: Parameter and return value are double to appease the WICED SDK's weird linking
 * If other types are used, the parameters aren't passed in correctly to the function
 * and you might end up with an infinite loop, crashing the system.
 *
 * @param a :Specifies the value to be square rooted
 * @return This routine returns the square root of the parameter
 */
double sqrt(double a);

/**
 * This routine will take a parameter and raise it to the power of n parameter.
 *
 *  NOTE: Parameters and return value are double to appease the WICED SDK's weird linking
 * If other types are used, the parameters aren't passed in correctly to the function and
 * you might end up with an infinite loop, crashing the system.
 *
 * @param a :Specifies the base to be raised.
 * @param n :Specifies the exponent to be raised to.  Can be positive or negative.  
 * @return This routine returns the power of the two parameters.
 */
double pow(double a, double n);

/**
 * This routine will take a parameter and raise it to the power of n parameter.
 *
 *  NOTE: Parameters and return value are double to appease the WICED SDK's weird linking
 * If other types are used, the parameters aren't passed in correctly to the function and
 * you might end up with an infinite loop, crashing the system.
 *
 * @param a :Specifies the base to be raised.
 * @param n :Specifies the exponent to be raised to.  Can be positive or negative.  
 * @return This routine returns the power of the two parameters.
 */
double ldexp(double a, int16_t n);

#endif

