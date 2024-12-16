#ifndef USE_S3
#include <XKCP/KeccakHash.h>
#else
#include <s3.h>
#endif
#include <sys/types.h>
#include <stdint.h>

#define KECCAK256_BLOCK_LENGTH		64
#define KECCAK256_DIGEST_LENGTH		32
#define KECCAK256_DIGEST_STRING_LENGTH	(KECCAK256_DIGEST_LENGTH * 2 + 1)
#define KECCAK512_BLOCK_LENGTH		128
#define KECCAK512_DIGEST_LENGTH		64
#define KECCAK512_DIGEST_STRING_LENGTH	(KECCAK512_DIGEST_LENGTH * 2 + 1)

#ifndef USE_S3
typedef Keccak_HashInstance KECCAK_CTX;
#else
typedef struct sha3_ctx KECCAK_CTX;
#endif

void KECCAK256_Init(KECCAK_CTX *);
void KECCAK256_Transform(uint32_t state[8], const uint8_t [KECCAK256_BLOCK_LENGTH]);
void KECCAK256_Update(KECCAK_CTX *, const uint8_t *, size_t);
void KECCAK256_Pad(KECCAK_CTX *);
void KECCAK256_Final(uint8_t [KECCAK256_DIGEST_LENGTH], KECCAK_CTX *);
char *KECCAK256_End(KECCAK_CTX *, char *);
char *KECCAK256_Fd(int fd, char *buf);
char *KECCAK256_File(const char *, char *);
char *KECCAK256_FileChunk(const char *, char *, off_t, off_t);
char *KECCAK256_Data(const uint8_t *, size_t, char *);

void KECCAK512_Init(KECCAK_CTX *);
void KECCAK512_Transform(uint64_t state[8], const uint8_t [KECCAK512_BLOCK_LENGTH]);
void KECCAK512_Update(KECCAK_CTX *, const uint8_t *, size_t);
void KECCAK512_Pad(KECCAK_CTX *);
void KECCAK512_Final(uint8_t [KECCAK512_DIGEST_LENGTH], KECCAK_CTX *);
char *KECCAK512_End(KECCAK_CTX *, char *);
char *KECCAK512_Fd(int fd, char *buf);
char *KECCAK512_File(const char *, char *);
char *KECCAK512_FileChunk(const char *, char *, off_t, off_t);
char *KECCAK512_Data(const uint8_t *, size_t, char *);
