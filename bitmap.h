//Marc Hebert
//260574038
#include "constants.h"
#include <stdlib.h>
#include <math.h>

typedef unsigned char* bitmap_t;

typedef struct 
{
	bitmap_t mp;
	int numbits;
	int lastfreebit;
}Bitmap;

void b_set(Bitmap* b, int i);
void b_unset(Bitmap* b, int i);
int b_getbit(Bitmap* b, int i);
Bitmap* b_init(int n);
int b_getfreebit(Bitmap* b);
