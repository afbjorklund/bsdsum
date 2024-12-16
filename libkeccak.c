/* Generic XKCP wrappers to match the semantics of libmd. */

#include "libkeccak.h"

#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#ifdef USE_S3
typedef sha3_ctx_t Keccak_HashInstance;

// For compatibility with libXKCP
#define Keccak_HashInitialize_SHA3_224(hi) sha3_init(hi, 224 / 8)
#define Keccak_HashInitialize_SHA3_256(hi) sha3_init(hi, 256 / 8)
#define Keccak_HashInitialize_SHA3_384(hi) sha3_init(hi, 384 / 8)
#define Keccak_HashInitialize_SHA3_512(hi) sha3_init(hi, 512 / 8)
#define Keccak_HashUpdate(hi, data, len) sha3_update(hi, data, len / 8)
#define Keccak_HashFinal(hi, hashval) sha3_final(hashval, hi)
#endif

static void tohex(uint8_t *digest, size_t length, char *buf) {
	static const char hex[] = "0123456789abcdef";
	size_t i;
	for (i = 0; i < length; i++) {
		buf[i+i] = hex[digest[i] >> 4];
		buf[i+i+1] = hex[digest[i] & 0x0f];
	}
	buf[i+i] = '\0';
}

#define MDX KECCAK256
#define LEN 256
#include "libkeccak.i"
#undef LEN
#undef MDX

#define MDX KECCAK512
#define LEN 512
#include "libkeccak.i"
#undef LEN
#undef MDX
