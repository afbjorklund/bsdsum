#include <sha2.h>

#ifdef SHA224_BLOCK_LENGTH
typedef SHA2_CTX SHA224_CTX;

#define SHA224_Init		SHA224Init
#define SHA224_Update		SHA224Update
#define SHA224_Final		SHA224Final
#define SHA224_End		SHA224End
#define SHA224_File		SHA224File
#define SHA224_FileChunk	SHA224FileChunk
#define SHA224_Data		SHA224Data

#define HAVE_SHA224
#endif
