//Marc Hebert
//260574038

inode_cache ic;
//inode_cache.i[DIR_INODE_] will point to directory number
void i_initCache()
{
	int x;
	for (x = 0; x<MAX_FILES_;x++)
	{
		ic.i[x].active = 0;
		ic.i[x].size = 0;
	}
}

inode_cache d_getIcache()
{
	return ic;
}

void d_setIcache( inode_cache tmp)
{
	ic = tmp;
}

int newFile()
