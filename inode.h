//Marc Hebert
//260574038
#include "constants.h"
#include "bitmap.h"


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

}typedef icache;

int i_deleteEntry();
int i_newEntry();
void i_setIcache( icache tmp);
icache* i_getIcache();
int i_getSize(int index);
int i_getPointer(int index, int pointerNum);
int i_getIndPointer(int index);
int i_isActive(int index);