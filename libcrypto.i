#ifndef MDX
#error
#endif

#define join(x, y) x##y
#define JOIN(x, y) join(x, y)

#define CHUNK_SIZE 8192

char *JOIN(MDX,_End)(JOIN(MDX,_CTX) *ctx, char *buf)
{
	uint8_t digest[JOIN(MDX,_DIGEST_LENGTH)];

	JOIN(MDX,_Final)(digest, ctx);
        tohex(digest, sizeof(digest), buf);
        return buf;
}

char *JOIN(MDX,_Data)(const void *data, unsigned int len, char *buf)
{
        JOIN(MDX,_CTX) ctx;

        JOIN(MDX,_Init)(&ctx);
        JOIN(MDX,_Update)(&ctx, (uint8_t*)data, (size_t)len);
        JOIN(MDX,_End)(&ctx, buf);
        return buf;
}

char *JOIN(MDX,_Fd)(int fd, char *buf)
{
        JOIN(MDX,_CTX) ctx;
        char tmp[CHUNK_SIZE];
        int n;

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
