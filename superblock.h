//Marc Hebert
//260574038
#include "constants.h"

typedef struct
{
	int magic, blocksize, fsSize, itablelength, rtdir;
}sblock;

sblock* s_init();
//void s_set(sblock* sb);
