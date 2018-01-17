#ifndef CRYPTO_H
#define CRYPTO_H
#if defined(__cplusplus)
extern "C" {
#endif

#include "common.h"

bool
crpt_keypair(cchar **public_key, cchar **secret_keys, const cchar *seed);

cchar*
crpt_sign(cchar *message, clong message_length, cchar **secret_key);

int
crpt_verify(cchar *signature, cchar *message, clong message_length, cchar *public_key);

cchar*
crpt_hash(hash_fn_t fn, cchar *message, clong message_length);

void
crpt_rand_bytes(void ** const sbuffer, cint size);

cchar*
crpt_discovery_key(hash_fn_t fn, cchar *key, clong key_length);

cchar*
crpt_encode_big_endian(unsigned long long num);

#if defined(__cplusplus)
}
#endif
#endif