#ifndef MDX
#error
#endif
#ifndef mdx
#error
#endif

#define join(x, y) x##y
#define JOIN(x, y) join(x, y)

#define CHUNK_SIZE 8192

int JOIN(MDX, _Init)(EVP_MD_CTX *ctx)
{
        return EVP_DigestInit(ctx, JOIN(EVP_, mdx)());
}

int JOIN(MDX, _Update)(EVP_MD_CTX *ctx, const void *data, size_t len)
{
        return EVP_DigestUpdate(ctx, (const uint8_t*)data, (size_t)len);
}

char *JOIN(MDX,_End)(EVP_MD_CTX *ctx, char *buf)
{
        uint8_t digest[EVP_MAX_MD_SIZE];
        unsigned int len = sizeof(digest);

        EVP_DigestFinal(ctx, digest, &len);
        tohex(digest, len, buf);
        return buf;
}

char *JOIN(MDX,_Data)(const void *data, unsigned int len, char *buf)
{
        EVP_MD_CTX *ctx = EVP_MD_CTX_new();

        JOIN(MDX,_Init)(ctx);
        JOIN(MDX,_Update)(ctx, (const uint8_t*)data, (size_t)len);
        JOIN(MDX,_End)(ctx, buf);
        return buf;
}

char *JOIN(MDX,_Fd)(int fd, char *buf)
{
        EVP_MD_CTX *ctx = EVP_MD_CTX_new();
        char tmp[CHUNK_SIZE];
        long n;

        JOIN(MDX,_Init)(ctx);
        while ((n = read(fd, tmp, CHUNK_SIZE)) > 0) {
                JOIN(MDX,_Update)(ctx, (uint8_t*)tmp, (size_t)n);
        }
        if (n == -1) {
                return NULL;
        }
        JOIN(MDX,_End)(ctx, buf);
        return buf;
}
