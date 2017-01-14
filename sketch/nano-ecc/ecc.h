#ifndef _MICRO_ECC_H_
#define _MICRO_ECC_H_

#include <stdint.h>

/* Define as 1 to enable ECDSA functions, 0 to disable.
 */
#define ECC_ECDSA 1

/* Optimization settings. Define as 1 to enable an optimization, 0 to disable it.
   ECC_SQUARE_FUNC - If enabled, this will cause a specific function to be used for (scalar) squaring instead of the generic
                  multiplication function. Improves speed by about 8% .
 */
#define ECC_SQUARE_FUNC 1

/* Inline assembly options.
   Currently we do not provide any inline assembly options. In the future we plan to offer
   inline assembly for AVR and 8051.

   Note: You must choose the appropriate option for your target architecture, or compilation will fail
   with strange assembler messages.
 */
#define ecc_asm_none   0
#ifndef ECC_ASM
#define ECC_ASM ecc_asm_none
#endif

/* Curve selection options. */
#define secp128r1 16
#define secp192r1 24
#define secp256r1 32
#define secp384r1 48
#ifndef ECC_CURVE
#define ECC_CURVE secp192r1
#endif

#if (ECC_CURVE != secp128r1 && ECC_CURVE != secp192r1 && ECC_CURVE != secp256r1 && ECC_CURVE != secp384r1)
#error "Must define ECC_CURVE to one of the available curves"
#endif

#define NUM_ECC_DIGITS ECC_CURVE

typedef struct EccPoint
{
	uint8_t x[NUM_ECC_DIGITS];
	uint8_t y[NUM_ECC_DIGITS];
} EccPoint;


/**
 * This routine will create a public/private key pair.
 *
 * @details Note: You must use a new non-predictable random number to generate each new key pair.
 *
 * @param p_publicKey :Specifies the pointer that will be filled with the point representing the public key.
 * @param p_publicKey :Specifies the pointer that will be filled in with the private key.
 * @param p_random :Specifies the random number to use to generate the key pair.
 * @return This routine returns a 1 if the key pair was generated successfully, else an error occurred the value 0 is return. Try again with a different random number.
 */
int ecc_make_key(EccPoint * p_publicKey, uint8_t p_privateKey[NUM_ECC_DIGITS], uint8_t p_random[NUM_ECC_DIGITS]);

/**
 * This routine will determine whether or not a given point is on the chosen elliptic curve (ie, is a valid public key).
 *
 * @param p_publicKey :Specifies the point to check.
 * @return This routine returns a 1 if the given point is valid, else it returns a 0 which means that the given point is invalid.
 */
int ecc_valid_public_key(EccPoint *p_publicKey);

/**
 * This routine will compute a shared secret given your secret key and someone else's public key.
 *
 * @details Note: Optionally, you may provide a random multiplier for resistance to DPA attacks. If so the random multiplier should probably be different for each invocation of this routine. It is recommended that you hash the result of ecdh_shared_secret before using it for symmetric encryption or HMAC. If you do not hash the shared secret, you must call ecc_valid_public_key() to verify that the remote side's public key is valid. If this is not done, an attacker could create a public key that would cause your use of the shared secret to leak information about your private key.
 *
 * @param p_secret :Specifies the pointer that will be filled in with the shared secret value.
 * @param p_publicKey :Specifies the public key of some remote party.
 * @param p_privateKey :Specifies your private key.
 * @param p_random :Specifies an optional random number to resist DPA attacks. Pass in NULL if DPA attacks are not a concern.
 * @return This routine returns a 1 if the shared secret was computed successfully, else a 0 if the shared secret was computed unsuccessfully.
 */
int ecdh_shared_secret(uint8_t p_secret[NUM_ECC_DIGITS], EccPoint * p_publicKey, uint8_t p_privateKey[NUM_ECC_DIGITS], uint8_t p_random[NUM_ECC_DIGITS]);

#if ECC_ECDSA
/**
 * This routine will generate an ECDSA signature for a given hash value.
 *
 * @details Note: Compute a hash of the data you wish to sign (SHA-2 is recommended) and pass it in to this function along with your private key and a random number. You must use a new non-predictable random number to generate each new signature.
 *
 * @param r, s :Specifies pointers that will be filled in with the signature values.
 * @param p_privateKey :Specifies your private key.
 * @param p_random :Specifies the random number to use to generate the signature.
 * @param p_hash :Specifies the message hash to sign.
 * @return This routine returns 1 if the signature generated successfully, else a 0 if an error accord. Try again with a different random number if an error did accord.
 */
int ecdsa_sign(uint8_t r[NUM_ECC_DIGITS], uint8_t s[NUM_ECC_DIGITS], uint8_t p_privateKey[NUM_ECC_DIGITS],
			   uint8_t p_random[NUM_ECC_DIGITS], uint8_t p_hash[NUM_ECC_DIGITS]);

/**
 * This routine will verify an ECDSA signature.
 *
 * @details Note: Compute the hash of the signed data using the same hash as the signer and
   pass it to this function along with the signer's public key and the signature values (r and s).
 *
 * @param p_publicKey :Specifies the signer's public key.
 * @param p_hash :Specifies the hash of the signed data.
 * @param r, s :Specifies pointers that will be filled in with the signature values.
 * @return This routine returns 1 if the signature is valid, 0 if it is invalid.
 */
int ecdsa_verify(EccPoint * p_publicKey, uint8_t p_hash[NUM_ECC_DIGITS], uint8_t r[NUM_ECC_DIGITS], uint8_t s[NUM_ECC_DIGITS]);
#endif /* ECC_ECDSA */

/**
 * This routine will convert an integer into standard octet representation to the native format.
 *
 * @param p_native :Specifies the pointer that will be filled in with the native integer value.
 * @param p_bytes :Specifies the standard octet representation of the integer to convert.
 * @return None.
 */
void ecc_bytes2native(uint8_t p_native[NUM_ECC_DIGITS], uint8_t p_bytes[NUM_ECC_DIGITS * 4]);

/**
 * This routine will convert an integer into native format to the standard octet representation.
 *
 * @param p_bytes :Specifies the standard octet representation of the integer to convert.
 * @param p_native :Specifies the native integer value to convert.
 * @return None.
 */
void ecc_native2bytes(uint8_t p_bytes[NUM_ECC_DIGITS * 4], uint8_t p_native[NUM_ECC_DIGITS]);
#endif /* _MICRO_ECC_H_ */
