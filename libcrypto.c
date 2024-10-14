/* Generic OpenSSL wrappers to match the semantics of libmd. */

#include "libcrypto.h"

#define SHA1_DIGEST_LENGTH SHA_DIGEST_LENGTH

#include <stdint.h>
#include <unistd.h>

static void tohex(uint8_t *digest, size_t length, char *buf) {
	static const char hex[] = "0123456789abcdef";
	size_t i;
	for (i = 0; i < length; i++) {
		buf[i+i] = hex[digest[i] >> 4];
		buf[i+i+1] = hex[digest[i] & 0x0f];
	}
	buf[i+i] = '\0';
}

#define MDX MD5
#include "libcrypto.i"
#undef MDX
#define MDX RIPEMD160
#include "libcrypto.i"
#undef MDX
#define MDX SHA1
#include "libcrypto.i"
#undef MDX
#define MDX SHA224
#include "libcrypto.i"
#undef MDX
#define MDX SHA256
#include "libcrypto.i"
#undef MDX
#define MDX SHA384
#include "libcrypto.i"
#undef MDX
#define MDX SHA512
#include "libcrypto.i"
#undef MDX
