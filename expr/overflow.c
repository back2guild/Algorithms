#include <stdio.h>
#include <limits.h>


void overflow() {
	int i = INT_MAX + 1;
	printf("Max Int1 = %d\n",i);
}

void uninitialized() {
	int a;
	printf("Max Int2 = %d\n",a);
}

int main() {
	overflow();
	uninitialized();
	return 0;
}