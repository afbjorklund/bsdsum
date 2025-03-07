#include <openssl/crypto.h>
#define USE_LC3 OPENSSL_VERSION_NUMBER >= 0x30000000
#if USE_LC3
#include <openssl/evp.h>
typedef EVP_MD_CTX MD5_CTX;
typedef EVP_MD_CTX RIPEMD160_CTX;
typedef EVP_MD_CTX SHA_CTX;
typedef EVP_MD_CTX SHA1_CTX;
typedef EVP_MD_CTX SHA224_CTX;
typedef EVP_MD_CTX SHA256_CTX;
typedef EVP_MD_CTX SHA384_CTX;
typedef EVP_MD_CTX SHA512_CTX;
#else
#include <openssl/md5.h>
#include <openssl/ripemd.h>
#include <openssl/sha.h>

#define SHA1_DIGEST_LENGTH SHA_DIGEST_LENGTH
typedef SHA_CTX SHA1_CTX;
typedef SHA256_CTX SHA224_CTX;
typedef SHA512_CTX SHA384_CTX;
#endif

#define HAVE_SHA224
#define HAVE_SHA384

#if USE_LC3
int MD5_Init(MD5_CTX *c);
int RIPEMD160_Init(RIPEMD160_CTX *c);
int SHA1_Init(SHA1_CTX *c);
int SHA224_Init(SHA224_CTX *c);
int SHA256_Init(SHA256_CTX *c);
int SHA384_Init(SHA384_CTX *c);
int SHA512_Init(SHA512_CTX *c);

int MD5_Update(MD5_CTX *c, const void *data, size_t len);
int RIPEMD160_Update(RIPEMD160_CTX *c, const void *data, size_t len);
int SHA1_Update(SHA1_CTX *c, const void *data, size_t len);
int SHA224_Update(SHA224_CTX *c, const void *data, size_t len);
int SHA256_Update(SHA256_CTX *c, const void *data, size_t len);
int SHA384_Update(SHA384_CTX *c, const void *data, size_t len);
int SHA512_Update(SHA512_CTX *c, const void *data, size_t len);
#endif

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
