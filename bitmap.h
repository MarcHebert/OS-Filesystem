//Marc Hebert
//260574038
#include "constants.h"
#include <stdlib.h>

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

/*Marc Hebert
//260574038


typedef unsigned char* bitmap_t;
void b_set(bitmap_t b, int i)
{
	b[i / 8] |= 1 << (i & 7);	
}

void b_unset(bitmap_t b, int i)
{
	b[i / 8] &= ~(1 << (i & 7));
}

int b_getBit(bitmap_t b, int i)
{
	return b[i / 8] & (1 << (i & 7)) ? 1 : 0;
}

bitmap_t b_init(int n)
{
	return malloc((n + 7) / 8);
}

int main()
{
	bitmap_t b = b_init(128);
	printf("Bit 0 before: %d", b_getBit(b,0));
	b_set(b,0);
	printf("Bit 0 after set: %d", b_getBit(b,0));
	b_unset(b,0);
	printf("Bit 0 after unset: %d", b_getBit(b,0));

}
*/