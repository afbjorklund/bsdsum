#include <openssl/crypto.h>
#include <openssl/md5.h>
#include <openssl/ripemd.h>
#include <openssl/sha.h>

typedef SHA_CTX SHA1_CTX;
typedef SHA256_CTX SHA224_CTX;
typedef SHA512_CTX SHA384_CTX;

#define HAVE_SHA224
#define HAVE_SHA384

char *MD5_End(MD5_CTX *ctx, char *buf);
char *RIPEMD160_End(RIPEMD160_CTX *ctx, char *buf);
char *SHA1_End(SHA1_CTX *ctx, char *buf);
char *SHA224_End(SHA224_CTX *ctx, char *buf);
char *SHA256_End(SHA256_CTX *ctx, char *buf);
char *SHA384_End(SHA384_CTX *ctx, char *buf);
char *SHA512_End(SHA512_CTX *ctx, char *buf);

char *MD5_Data(const void *data, unsigned int len, char *buf);
char *RIPEMD160_Data(const void *data, unsigned int len, char *buf);
char *SHA1_Data(const void *data, unsigned int len, char *buf);
char *SHA224_Data(const void *data, unsigned int len, char *buf);
char *SHA256_Data(const void *data, unsigned int len, char *buf);
char *SHA384_Data(const void *data, unsigned int len, char *buf);
char *SHA512_Data(const void *data, unsigned int len, char *buf);

char *MD5_Fd(int fd, char *buf);
char *RIPEMD160_Fd(int fd, char *buf);
char *SHA1_Fd(int fd, char *buf);
char *SHA224_Fd(int fd, char *buf);
char *SHA256_Fd(int fd, char *buf);
char *SHA384_Fd(int fd, char *buf);
char *SHA512_Fd(int fd, char *buf);
