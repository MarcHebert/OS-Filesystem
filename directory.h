//Marc Hebert
//260574038



struct d_entry
{
	int inode;
	char* fname;
	char* fext;
}typedef dent;

struct directory
{
	dent list[100];
}typedef dr;

deleteFile();
newFile();