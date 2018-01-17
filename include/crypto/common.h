#ifndef COMMON_H
#define COMMON_H
#if defined(__cplusplus)
extern "C" {
#endif

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <debug/debug.h>
#include <describe/describe.h>
#include <string.h>
#include <sodium.h> // v1.0.16 12/13/2017

#define n_elems(a) (unsigned int)(sizeof(a) / sizeof(a[0]))
#define HASH_BYTES 32// number of bytes in SHA256 + terminating byte

typedef unsigned int cint;
typedef unsigned long long clong;
typedef unsigned char cchar;

typedef enum hash_fn hash_fn_t;
enum hash_fn { 
  BLAKE2B 
};

#if defined(__cplusplus)
}
#endif
#endif
