int deleteEntry();
int newEntry();
int get_inode(char* name);
int get_inode_from_dir(char* path);
inode get_dir();

struct i_node
{
	int mode,
		linkcnt,
		uid,
		gid,
		size;
	int pointers[12];
	int indPointer;
}typedef inode;

typedef struct 
{
	inode i[101];

}typedef inode_cache;