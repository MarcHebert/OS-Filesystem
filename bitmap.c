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
	double exactbytes = (bits / 8.0);
	int bytes = (int) ceil(exactbytes);//to properly size map in terms of bytes
	Bitmap* b = (Bitmap*)malloc(sizeof(b));
	b->mp = (bitmap_t)malloc(bytes);
	b->numbits = bits;
	b->lastfreebit = 0;
	return b;
}

int b_getfreebit(Bitmap* b)
{
	int x;
	for(x = 0;x<b->numbits;x++)//iterate until free bit found
	{
		if (b_getbit(b,(b->lastfreebit+x)%b->numbits) == 0)//found free bit
		{
			b->lastfreebit = (b->lastfreebit+x)%b->numbits);
			return b->lastfreebit;
		}
	}
	//else no free bits
	return -1;
}