#ifndef USE_B3
#include <blake3.h>
#else
#include <b3.h>
#endif
#include <stdbool.h>

#define BLAKE3_DIGEST_LENGTH BLAKE3_OUT_LEN
typedef blake3_hasher BLAKE3_CTX;

bool BLAKE3Context(BLAKE3_CTX *);
void BLAKE3Init(BLAKE3_CTX *);
void BLAKE3Update(BLAKE3_CTX *, const uint8_t *, size_t);
void BLAKE3Final(uint8_t [BLAKE3_DIGEST_LENGTH], BLAKE3_CTX *);
char *BLAKE3End(BLAKE3_CTX *, char *);
char *BLAKE3Fd(int, char *);
char *BLAKE3File(const char *, char *);
char *BLAKE3Data(const void *data, unsigned int len, char *buf);
