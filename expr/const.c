#include <stdio.h>

#define BUFFER_SIZE 10

int main(int argc, char **argv)
{
	printf("address of BUFFER_SIZE = %p", &BUFFER_SIZE);
	return 0;
}
