#include <stdint.h>

#define BLAKE3_KEY_LEN 32
#define BLAKE3_OUT_LEN 32

/* for compatibility with libblake3 */
typedef struct blake3 blake3_hasher;
#define blake3_init blake3_hasher_init
#define blake3_update blake3_hasher_update
#define blake3_out blake3_hasher_finalize

struct blake3 {
    uint32_t key[8];
	unsigned char input[64];      /* current input bytes */
	unsigned bytes;               /* bytes in current input block */
	unsigned block;               /* block index in chunk */
	uint64_t chunk;               /* chunk index */
	uint32_t *cv, cv_buf[54 * 8]; /* chain value stack */
};

void blake3_init(struct blake3 *);
void blake3_update(struct blake3 *, const void *, size_t);
void blake3_out(struct blake3 *, unsigned char *restrict, size_t);
