#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>


int main(int argc, char **argv) 
{
	typedef struct Example {
		int x;   // 4 bytes
		char y;  // 1 byte
		int z;   // 4 bytes 
	} Ex;

	Ex x;

	printf("sizeof (x) = %lu\n", sizeof(x));
	printf("offset of y = %llu\n", offsetof(Ex,y));
	return 0;
}
