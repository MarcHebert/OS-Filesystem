//Marc Hebert
//260574038
#include "constants.h"
#include "bitmap.h"

struct d_entry
{
	int active;
	int inode;
	char* fname[MAX_FILE_NAME_+MAX_FILE_EXT_+2];//two extra chars for period seperator and null terminator
}typedef dent;

typedef struct
{
	dent list[MAX_FILES];//should be NUM_INDODES_ as defined in sfs_api.c
	int numEntry;
} directory;

void d_setDir(directory* tmp);
directory* d_getDir();
void d_initDir();
int d_addEntry(int id, char* name);
void resetDirIter();
int d_getNextDirName(char* namebuf);
int d_name2Index(char* namebuf);
int d_getActive(int index);
int d_getInode(int index);
char* d_getName(int index);
int d_removeEntry(int index);