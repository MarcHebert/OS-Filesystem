//Marc Hebert
//260574038

#define MAX_FILE_NAME 16
#define MAX_FILE_EXT 3
struct d_entry
{
	int active;
	int inode;
	char* fname[MAX_FILE_NAME+MAX_FILE_EXT+1];
}typedef dent;

typedef struct
{
	dent list[101];//should be NUM_INDODES_ as defined in sfs_api.c
} directory;
