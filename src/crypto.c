#include <crypto/crypto.h>

bool
crpt_keypair(cchar **public_key, cchar **secret_key, const cchar *seed) {

  if (sodium_init() >= 0) {
    *public_key = (cchar *) malloc(crypto_sign_PUBLICKEYBYTES);
    *secret_key = (cchar *) malloc(crypto_sign_SECRETKEYBYTES);

    if (seed) crypto_sign_seed_keypair(*public_key, *secret_key, seed);
    else crypto_sign_keypair(*public_key, *secret_key);

    return true;
  } else
    return false;
}

cchar*
crpt_sign(cchar *message, clong message_length, cchar **secret_key) {
  if (sodium_init() >= 0) {
    static cchar signature[crypto_sign_BYTES];
    crypto_sign_detached(signature, NULL, message, message_length, *secret_key);
    return signature;
  }
  return NULL;
}

int
crpt_verify(cchar *signature, cchar *message, clong message_length, cchar *public_key) {
  if (sodium_init() >= 0) {
    return crypto_sign_verify_detached(signature, message, message_length, public_key);
  }
  return 0;
}

cchar*
crpt_hash(hash_fn_t fn, cchar *message, clong message_length) {
  if (sodium_init() >= 0) {
    if (BLAKE2B == fn) {
      static cchar hash[crypto_generichash_BYTES];
      crypto_generichash(hash, sizeof hash, message, message_length, NULL, 0);
      return hash;
    }
  }
  return NULL;
}

void
crpt_rand_bytes(void ** const buffer, cint size) {
  if (sodium_init() >= 0) {
    *buffer = (void *) malloc(size);
    randombytes_buf(*buffer, size);
  }
}

cchar*
crpt_discovery_key(hash_fn_t fn, cchar *key) {
  if (sodium_init() >= 0) {
    if (BLAKE2B == fn) {
      
    }
  }
  // sodium.crypto_generichash //blake2b
}

cchar*
crpt_encode_big_endian(unsigned long long n) {
  static cchar bytes[8];

  bytes[0] = (n >> 56) & 0xFF;
  bytes[1] = (n >> 48) & 0xFF;
  bytes[2] = (n >> 40) & 0xFF;
  bytes[3] = (n >> 32) & 0xFF;
  bytes[4] = (n >> 24) & 0xFF;
  bytes[5] = (n >> 16) & 0xFF;
  bytes[6] = (n >> 8) & 0xFF;
  bytes[7] = n & 0xFF;

  return bytes;
}