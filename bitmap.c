//Marc Hebert
//260574038

#include <stdint.h>
#include <stdlib.h>
#include "bitmap.h"


void b_set(Bitmap* b, int i)
{
	b->mp[i / 8] |= 1 << (i & 7);
}

void b_unset(Bitmap* b, int i)
{
	b->mp[i/8] &= ~(1 << (i & 7));
}

int b_getbit(Bitmap* b, int i)
{
	return b->mp[i/8] & (1 << (i & 7)) ? 1: 0;
}

Bitmap* b_init(int bits)
{
	int bytes = bits / 8;
	Bitmap* b = (Bitmap*)malloc(sizeof(b));
	b->mp = (bitmap_t)malloc(bytes);
	return b;
}