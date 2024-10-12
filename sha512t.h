#include <sha2.h>

#ifdef SHA512_256_BLOCK_LENGTH
typedef SHA2_CTX SHA512_CTX;

#define SHA512_256_Init		SHA512_256Init
#define SHA512_256_Update	SHA512_256Update
#define SHA512_256_Final	SHA512_256Final
#define SHA512_256_End		SHA512_256End
#define SHA512_256_File		SHA512_256File
#define SHA512_256_FileChunk	SHA512_256FileChunk
#define SHA512_256_Data		SHA512_256Data

#define HAVE_SHA512_256
#endif
