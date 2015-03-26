//Marc Hebert
//260574038

#include "constants.h"
#include "bitmap.h"

typedef struct 
{
	Bitmap dbFree;
}FDB;

FDB* FDB_init();
FDB* FDB_get();
void FDB_set(FDB* tmp);
void FDB_setbit(int i);
void FDB_unsetbit(int i);
int FDB_getbit(int i);
int FDB_getfreeblock();

