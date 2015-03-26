//Marc Hebert
//260574038

#include "constants.h"
#include "types.h"
#include "diskemu.h"
#include "superblock.h"
#include "filedescriptortable.h"
#include "directory.h"
#include "inode.h"

//cached items
sblock sb;
fbitmap fbm;
FTDentry FDTtable[NUM_INODES_];


char defaultname[] = "MarcFS";
int errorstatus = 0;


int sfs_open(char* filename)
{
	//check FDT or inodes to see if file exists
	//if DNE, create file & set size to 0
	// else open in append mode ( set file pointer to EOF using sfs_seek)
	
	
	//does file exist?
	int index = d_name2Index(filename);
	if(index<0)//file doesn't exist
	{
		//create the new file
		int id = i_newEntry(); //index is inode in this case
		if(id<0)//any open directory slots?
			return -1;
		d_addEntry(id, filename);
		f_activate(id);
		
	}
	else//file exists
	{
		int id = d_getInode(index)
		f_activate(id);
		f_setRW(id, i_getSize(id))//set RW pointer to end of file (append)
		
	}

	return id; //inode


	/*
	int inode = get_inode(filename);
	int nextfile = find_next_free_slot(open_file_table);
	make_open_file_table_entry(nextfile, inode);
	int filedesc = find_next_free_slot(file_desc_table);
	int read_pointer = 0;
	int write_pointer = 0;
	make_file_desc_entry(filedesc, nextfile, read_pointer, write_pointer)

	return filedesc;
	*/
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
	int index = d_name2Index(file);
	if(index<0)
		return -1;//file doesn't exist
	//will possibly change to not return error and instead do nothing
	int id = d_getInode(index);
	i_deleteEntry(id);// TODO error handle here
	//TODO release data blocks used by the file
	return d_removeEntry(index);
}

int sfs_get_next_filename(char* filename)
{
	if (d_getNextDirName(filename)<0)
	{
		return 0;
	}
	else
		return 1;
	/*
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
	*/
}
int sfs_GetFileSize(const char* path)
{
	//assuming path is name? otherwise will have to come back and fix
	/*char* name = null;
	while(strcmp(path,name)!=0)
	{
		if(sfs_get_next_filename(name)==0)
			//file doesn't exist
			return 0;
	}
	*/
	//fetch inode from dir and then pull size from cache
	int index = d_name2Index(path);
	if(index<0)//file doesn't exist
		return -1;
	return i_getSize(d_getInode(index));
}

int sfs_fclose(int fileID);
{
	f_deactivate(fileID);
}

int mksfs(int fresh)
{
	if(fresh==0)//new file system
	{
		errorstatus = init_fresh_disk(defaultname, BLOCKSIZE, NUM_BLOCKS);

		//setup directory
		d_initDir();

		//setup inodetable
		i_initCache();

		//setup superblock
		sb.magic = 0xAABB0005;
		sb.blksz = BLOCKSIZE_;
		sb.fsSize = NUM_BLOCKS_;
		sb.rtdir = MAX_FILES_//place root directory at the last inode index

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