int deleteEntry();
int newEntry();
int get_inode(char* name);
int get_inode_from_dir(char* path);

struct i-node
{
	int mode,
		linkcnt,
		uid,
		gid,
		size;
	void pointers[12];
	void indPointer;
}typedef inode;