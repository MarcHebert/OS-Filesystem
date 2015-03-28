
int mksfs(int fresh);
int sfs_fopen(char *name);
int sfs_fclose(int fileID);
int sfs_fwrite(int fileID, const char *buf, int length);
int sfs_fread(int fileID, char *buf, int length);
int sfs_fseek(int fileID, int offset);
int sfs_remove(char *file);
int sfs_get_next_filename(char* filename);
int sfs_GetFileSize(const char* path);

//new functions
int write_1block(int block, char* buffer);
int read_1block(int block, char* buffer);
int write_superblock();
int write_icache();
int write_FDB();
int init_superblock();
int init_icache();
int init_FDB();
int init_directory();
int num_new_blocks_needed(int inode, int newBytes, int numUsedDataBlocks);
int write_partblock(int block, const char* buffer, int byteOffset, int numBytes);
int num_indptrs(int inode);
int load_indblock(int inode, char* buffer);
int load_blocknums(int inode, int* blockNums);
int write_helper(const char* buffer, int numBytes, int* blockNums, int offset);
int read_partblock(int block, char* buffer, int offset, int numBytes);
int read_helper(char* buffer, int numBytes, int* blockNums, int offset);