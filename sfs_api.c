//Marc Hebert
//260574038
#define BLOCKSIZE_ 16384 //large block size means one structure per block
#define NUM_BLOCKS_ 150
#define NUM_INODES_ 101

#include <string.h>
#include "types.h"
#include "diskemu.h"
#include "superblock.h"
#include "filedescriptortable.h"
#include "directory.h"

//cached items
sblock sb;
fbitmap fbm;
inode_cache icache;
FTDentry FDTtable[NUM_INODES_];

//directory setup
	directory d;
	int x;
	for(x = 0; x<NUM_INODES_; x++)//initialize all slots to empty
	{
		d.list[x].active = 0;
	}
	int dirIterIndx = 0; //current directory index (necessary for GetNextFileName() )


char defaultname[] = "MarcFS";
int errorstatus = 0;


int sfs_open(char* filename)
{
	//check FDT or inodes to see if file exists
	//if DNE, create file & set size to 0
	// else open in append mode ( set file pointer to EOF using sfs_seek)
	//

	int inode = get_inode(filename);
	int nextfile = find_next_free_slot(open_file_table);
	make_open_file_table_entry(nextfile, inode);
	int filedesc = find_next_free_slot(file_desc_table);
	int read_pointer = 0;
	int write_pointer = 0;
	make_file_desc_entry(filedesc, nextfile, read_pointer, write_pointer)

	return filedesc;
}

int sfs_fwrite(int fileID, const char *buf, int length)
{
	//writes length*bytes of buffered data in buf onto the open file
	//starting from read/write pointer

	//increases the size of the file by length*bytes

	//will obviously use diskemu.write_blocks()

	buf = malloc(BLOCKSIZE*sizeof(char));
}

int sfs_fread(int fileID, char *buf, int length);
int sfs_fseek(int fileID, int offset)
{

	//moves read/write pointer to given location
}

int sfs_remove(char *file);
{
	//removes file from directory.h
	//remove entry from inode table
	//release data blocks used by the file
}

int sfs_get_next_filename(char* filename)
{
	int nextfile = d.list[dirIterIndx].active//check if next entry has file
	if (nextfile !=0)
	{
		strcpy(filename, d.list[dirIterIndx].fname);
		dirIterIndx++;
		if (dirIterIndx>=NUM_INODES_)//if last file possible
		{
			dirIterIndx = 0;
			nextfile = 0;
		}
	}
	else
	{
		dirIterIndx = 0;//if no more files, reset directory index to 0
	}
	return nextfile;
}
int sfs_GetFileSize(const char* path)
{
	//assuming path is name? otherwise will have to come back and fix
	char* name = null;
	int brk = 0;
	while(strcmp(path,name)!=0)
	{
		if(sfs_get_next_filename(name)==0)
			//file doesn't exist
			return 0;
	}
	//fetch inode from dir and then pull size from cache
	return icache.i[d.list[dirIterIndx-1].inode].size
}

int sfs_fclose(int fileID);
{
	//remove entry from OFT
}

int mksfs(int fresh)
{
	if(fresh==0)//new file system
	{
		errorstatus = init_fresh_disk(defaultname, BLOCKSIZE, NUM_BLOCKS);

		//setup superblock
		sb.magic = 0xAABB0005;
		sb.blksz = BLOCKSIZE_;
		sb.fsSize = NUM_BLOCKS_;
		sb.rtdir = //TO BE DETERMINED

		//write superblock to disk
		write_blocks(0,1,(void*)&sb);

	}

	else//existing file system
	{
		errorstatus = init_disk(defualtname, BLOCKSIZE, NUM_BLOCKS);
		
		//read superblock
		void buf;
		read_blocks(0,1, (void*)&sb);
	}
	return errorstatus;
}