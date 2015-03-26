//Marc Hebert
//260574038

FDB* fd;

FDB* FDB_init()
{
	fd->dbFree = b_init(NUM_BLOCKS_);
	return fd;
}
FDB* FDB_get()
{
	return fd;
}
void FDB_set(FDB* tmp)
{
	fd = tmp;
}
void FDB_setbit(int i)
{
	b_set(fd->dbFree, i);
}
void FDB_unsetbit(int i)
{
	b_unset(fd->dbFree, i);
}
int FDB_getbit(int i)
{
	return b_getbit(fd->dbFree, i);
}

int FDB_getfreeblock()
{
	return b_getfreebit(fd->dbFree);
}