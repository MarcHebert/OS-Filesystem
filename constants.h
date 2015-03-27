//Marc Hebert
//260574038

#define BLOCKSIZE_ 512 //large block size means one structure per block
#define NUM_BLOCKS_ BLOCKSIZE_ * 7 //free data block bitmap restriction (max is more but playing it it safe)
#define NUM_INODES_ 101
#define MAX_FILES_ 100
#define MAX_FILE_NAME_ 16
#define MAX_FILE_EXT_ 3
#define DIR_INODE_ 100
#define NUM_DIR_DATABLOCKS_ 12
#define NUM_PTRS_INDIR_ BLOCKSIZE_/6 //pts are 4 byte ints but I am being cautious because of packing & padding
#define MAX_FILE_DATABLOCKS_ = (NUM_DIR_DATABLOCKS_ + NUM_PTRS_INDIR_)
#define MAX_FILE_SIZE_ MAX_FILE_DATABLOCKS_ * BLOCKSIZE_
#define MAX_ICACHE_SIZE_ 8192 //[(NUM_DIR_DATABLOCKS_ + 3)*4] * NUM_INODES_] raised to the nearest power of 2
							//haven't figured out how to do this dynamically pre compilation
#define ICACHE_BLOCKCOUNT_ MAX_ICACHE_SIZE_ / BLOCKSIZE_
#define MAX_DIR_SIZE_ 4096 //(MAX_FILE_NAME_+MAX_FILE_EXT_+10) * MAX_FILES_ + 4 raised to next power of 2
#define DIR_BLOCKCOUNT_ MAX_DIR_SIZE_ / BLOCKSIZE_
#define SB_MAGIC_ 0xAABB0005

#define SB_BLOCK_ 0
#define ICACHE_BLOCK_START_ 1
#define ICACHE_BLOCK_END_ 31
#define FBM_BLOCK_ 32
#define FIRST_DATABLOCK_ 33
#define LAST_DATABLOCK_ 3583
#define DATA_BLOCKS_AVAIL_ LAST_DATABLOCK_ - FBM_BLOCK_ //3551

#include <stdlib.h>
#include <string.h>
#include <stdio.h>