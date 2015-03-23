//Marc Hebert
//260574038
#define BLOCKSIZE_ 512
#define NUM_BLOCKS_ 4096
#define NUM_INODES_ 101

#include "types.h"
#include "diskemu.h"
#include "superblock.h"

//int blocksize, numblocks, numinodes dirindex;
//cached super block
sblock sb;

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
	int nextfile = 1;
	//some call to directory
	//possible some global variable that 
	//keeps track of current position in the directory
	// this will probably be relegated to directory.h
	return nextfile;
}
int sfs_GetFileSize(const char* path);
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