#include<stdio.h>
#include <stdalign.h>
#include <limits.h>

int main(int argc, char **argv)
{
	typedef struct person
	{
		int a;
		char name[1];
	} Person;
	
	printf("Alignment of char = %zu\n", alignof(char));
	printf("Alignment of short = %zu\n", alignof(short));
	printf("Alignment of int = %zu\n", alignof(int));
	printf("Alignment of float = %zu\n", alignof(float));
	printf("Alignment of long = %zu\n", alignof(long));
	printf("Alignment of double = %zu\n", alignof(double));
	printf("Alignment of struct person = %zu\n", alignof(Person));
	printf("Word size = %d\n", WORD_BIT);
	printf("Size of void pointer = %zu\n", sizeof(void *));
	printf("%s\n",__FILE__);
	printf("Alignment of unsigned long long = %llu\n", alignof(unsigned long long));
	return 0;
}
