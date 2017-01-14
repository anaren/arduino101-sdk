#ifndef TI_AES
#define TI_AES

/**
 * This routine will encrypt the state parameter with the key parameter.
 * @param state :Specifies the data which is going to be encrypted.
 * @param key :Specifies the key to access the data with.
 * @return None.
 */
void AES128_encrypt(unsigned char *state, unsigned char *key);

/**
 * This routine will decrypt the state parameter if the key parameter is correct.
 * @param state :Specifies the pointer for the decrypted data to be stored.
 * @param key :Specifies the key to decrypt the data with.
 * @return None.
 */
void AES128_decrypt(unsigned char *state, unsigned char *key);
#endif