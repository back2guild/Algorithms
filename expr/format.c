#include<stdio.h>

int main()
{
	char buffer[20];
	double PI=3.1415920;
	sprintf(buffer,"PI = %0.7f",PI);
	printf("%s\n",buffer);
	return 0;
}
