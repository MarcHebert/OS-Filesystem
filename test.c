#include <stdlib.h>
#include <stdio.h>
#include "types.h"

int main (int argc, char* args[])
{
	char x = x;
	short int y = 12;
	long z = 65;
	printf("byte : %zu\n".sizeof(x));
	printf("half : %zu\n".sizeof(y));
	printf("word : %zu\n",sizeof(z));

	return 0;


}