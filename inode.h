//Marc Hebert
//260574038
 #include "constants.c"



struct i_node
{
	int active;
	int size;
	int pointers[12];
	int indPointer;
}typedef inode;

typedef struct 
{
	inode i[101];

}typedef inode_cache;

int deleteEntry();
int newEntry();
int get_inode(char* name);
int get_inode_from_dir(char* path);
