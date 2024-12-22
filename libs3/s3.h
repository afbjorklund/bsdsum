// sha3.h
// 19-Nov-11  Markku-Juhani O. Saarinen <mjos@iki.fi>

#include <stddef.h>
#include <stdint.h>

// state context
typedef struct sha3_ctx {
    union {                                 // state:
        uint8_t b[200];                     // 8-bit bytes
        uint64_t q[25];                     // 64-bit words
    } st;
    int pt, rsiz, mdlen;                    // these don't overflow
} sha3_ctx_t;

// OpenSSL-like interface
int sha3_init(sha3_ctx_t *c, int mdlen);    // mdlen = hash output in bytes
int sha3_update(sha3_ctx_t *c, const void *data, size_t len);
int sha3_final(void *md, sha3_ctx_t *c);    // digest goes to md
