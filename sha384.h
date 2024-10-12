#include <sha2.h>

#ifdef SHA384_BLOCK_LENGTH
typedef SHA2_CTX SHA384_CTX;

#define SHA384_Init		SHA384Init
#define SHA384_Update		SHA384Update
#define SHA384_Final		SHA384Final
#define SHA384_End		SHA384End
#define SHA384_File		SHA384File
#define SHA384_FileChunk	SHA384FileChunk
#define SHA384_Data		SHA384Data

#define HAVE_SHA384
#endif
