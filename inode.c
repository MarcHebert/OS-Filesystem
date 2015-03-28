//Marc Hebert
//260574038
#include "inode.h"

icache* ic;
//inode_cache.i[DIR_INODE_] will point to directory number
icache* i_initCache()
{
	
	int x;
	for (x = 1; x<MAX_FILES_;x++)
	{
		ic->i[x].active = 0;
		ic->i[x].size = 0;
	}
	ic->iFree= b_init(NUM_INODES_);
	
	//setup directory inode
	b_set(ic->iFree, 0);
	ic->i[0].active  = 1;
	return ic; 
}

icache* i_getIcache()
{
	return ic;
}

void i_setIcache(icache* tmp)
{
	ic = tmp;
}



int i_newEntry()
{
	int index = b_getfreebit(ic->iFree);
	if(index <0)//no more free inodes
		return -1;
	b_set(ic->iFree, index);
	ic->i[index].active = 1;
	return index;
}

void i_deleteEntry(int index)//TODO error handling
{
	b_unset(ic->iFree, index);
	ic->i[index].active = 0;
	ic->i[index].size = 0;
	//TODO set pointers to null
}

int i_getSize(int index)//TODO error handling
{
	return ic->i[index].size;
}

void i_setSize(int index, int sz)//TODO error handling
{
	ic->i[index].size = sz;
}

void i_incdecSize(int index, int incdec)
{
	i_setSize(index, i_getSize(index)+incdec);
}

int i_getPointer(int index, int pointerNum)//TODO error handling
{
	return ic->i[index].pointers[pointerNum];
}

int i_getIndPointer(int index) //TODO error handling
{
	return ic->i[index].indPointer;
}

int i_isActive(int index)//TODO error handling
{
	return ic->i[index].active;
}
