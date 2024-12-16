#ifndef MDX
#error
#endif

#define join(x, y) x##y
#define JOIN(x, y) join(x, y)

#define CHUNK_SIZE 8192

void JOIN(MDX,_Init)(KECCAK_CTX *ctx)
{
	JOIN(Keccak_HashInitialize_SHA3_, LEN)(ctx);
}

void JOIN(MDX,_Update)(KECCAK_CTX *ctx, const uint8_t *data, size_t len)
{
	Keccak_HashUpdate(ctx, data, len * 8);
}

void JOIN(MDX,_Final)(uint8_t digest[JOIN(MDX, _DIGEST_LENGTH)], KECCAK_CTX *ctx)
{
	Keccak_HashFinal(ctx, digest);
}

char *JOIN(MDX,_End)(KECCAK_CTX  *ctx, char *buf)
{
	uint8_t digest[JOIN(MDX,_DIGEST_LENGTH)];

	JOIN(MDX,_Final)(digest, ctx);
	tohex(digest, sizeof(digest), buf);
	return buf;
}

char *JOIN(MDX,_Fd)(int fd, char *buf)
{
	KECCAK_CTX ctx;
	char tmp[CHUNK_SIZE];
	long n;

	JOIN(MDX,_Init)(&ctx);
	while ((n = read(fd, tmp, CHUNK_SIZE)) > 0) {
		JOIN(MDX,_Update)(&ctx, (uint8_t*)tmp, (size_t)n);
	}
	if (n == -1) {
		return NULL;
	}
	JOIN(MDX,_End)(&ctx, buf);
	return buf;
}

char *JOIN(MDX,_File)(const char *filename, char *buf)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0) {
		return NULL;
	}
	buf = JOIN(MDX,_Fd)(fd, buf);
	close(fd);
	return buf;
}

char *JOIN(MDX,_Data)(const unsigned char *data, unsigned long len, char *buf)
{
	KECCAK_CTX ctx;

	JOIN(MDX,_Init)(&ctx);
	JOIN(MDX,_Update)(&ctx, (const uint8_t*)data, (size_t)len);
	JOIN(MDX,_End)(&ctx, buf);
	return buf;
}
