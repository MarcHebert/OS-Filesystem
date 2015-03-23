//Marc Hebert
//260574038
#define BLOCKSIZE 512
#include "types.h"

int sfs_open(char* filename)
{
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
	buf = malloc(BLOCKSIZE*sizeof(char));
	

}