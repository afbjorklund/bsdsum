/* Generic BLAKE3 wrappers to match the semantics of libmd. */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include "libblake3.h"

#define CHUNK_SIZE 65536

// from blake3_impl.h
static const uint32_t IV[8] = {0x6A09E667UL, 0xBB67AE85UL, 0x3C6EF372UL,
                               0xA54FF53AUL, 0x510E527FUL, 0x9B05688CUL,
                               0x1F83D9ABUL, 0x5BE0CD19UL};

bool BLAKE3Context(BLAKE3_CTX *ctx)
{
	return memcmp(ctx->key, IV, 32) == 0;
}

void BLAKE3Init(BLAKE3_CTX *ctx)
{
	blake3_hasher_init(ctx);
}

void BLAKE3Update(BLAKE3_CTX *ctx, const uint8_t *data, size_t len)
{
	blake3_hasher_update(ctx, data, len);
}

void BLAKE3Final(uint8_t out[BLAKE3_DIGEST_LENGTH], BLAKE3_CTX *ctx)
{
	blake3_hasher_finalize(ctx, out, BLAKE3_DIGEST_LENGTH);
}

char *BLAKE3End(BLAKE3_CTX *ctx, char *buf)
{
	uint8_t digest[BLAKE3_DIGEST_LENGTH];
	size_t i;

	BLAKE3Final(digest, ctx);
	for (i = 0; i < BLAKE3_DIGEST_LENGTH; i++) {
		sprintf(&buf[i*2], "%02x", (uint32_t)digest[i]);
	}
	buf[BLAKE3_DIGEST_LENGTH*2] = '\0';
	return buf;
}

char *BLAKE3Fd(int fd, char *buf)
{
	BLAKE3_CTX ctx;
	uint8_t tmp[CHUNK_SIZE];
	ssize_t n;

	BLAKE3Init(&ctx);
	while ((n = read(fd, tmp, CHUNK_SIZE)) > 0) {
		BLAKE3Update(&ctx, tmp, (size_t)n);
	}
	if (n == -1) {
		return NULL;
	}
	BLAKE3End(&ctx, buf);
	return buf;
}

char *BLAKE3File(const char *filename, char *buf)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0) {
		return NULL;
	}
	buf = BLAKE3Fd(fd, buf);
	close(fd);
	return buf;
}

char *BLAKE3Data(const void *data, unsigned int len, char *buf)
{
	BLAKE3_CTX ctx;

	BLAKE3Init(&ctx);
	BLAKE3Update(&ctx, data, len);
	BLAKE3End(&ctx, buf);
	return buf;
}
