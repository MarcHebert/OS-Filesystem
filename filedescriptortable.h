//Marc Hebert
//260574038

#include "constants.c"

struct file_descriptor_table_entry
{
	int rw;
		active;
//inode = index
}typedef FTDentry;


struct file_descriptor_table
{
	FTDentry f[MAX_FILES_];//inode = index
}typedef FDT;

void f_activate(int inode);
int f_getRW(int inode);
void f_setRW(int inode, int newrw);
void f_incdecRW(int inode, int incdec);
void f_deactivate(int inode);