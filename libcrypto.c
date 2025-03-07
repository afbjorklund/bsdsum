/* Generic OpenSSL wrappers to match the semantics of libmd. */

#include "libcrypto.h"

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
#if USE_LC3
#define mdx md5
#include "libcrypto3.i"
#undef mdx
#else
#include "libcrypto.i"
#endif
#undef MDX

#define MDX RIPEMD160
#if USE_LC3
#define mdx ripemd160
#include "libcrypto3.i"
#undef mdx
#else
#include "libcrypto.i"
#endif
#undef MDX

#define MDX SHA1
#if USE_LC3
#define mdx sha1
#include "libcrypto3.i"
#undef mdx
#else
#include "libcrypto.i"
#endif
#undef MDX

#define MDX SHA224
#if USE_LC3
#define mdx sha224
#include "libcrypto3.i"
#undef mdx
#else
#include "libcrypto.i"
#endif
#undef MDX

#define MDX SHA256
#if USE_LC3
#define mdx sha256
#include "libcrypto3.i"
#undef mdx
#else
#include "libcrypto.i"
#endif
#undef MDX

#define MDX SHA384
#if USE_LC3
#define mdx sha384
#include "libcrypto3.i"
#undef mdx
#else
#include "libcrypto.i"
#endif
#undef MDX

#define MDX SHA512
#if USE_LC3
#define mdx sha512
#include "libcrypto3.i"
#undef mdx
#else
#include "libcrypto.i"
#endif
#undef MDX
