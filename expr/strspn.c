#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	const char seps[] = ",.;!?";
	char foo[] = ";ball call, .fall gall hall!?.,";
	char *s;
	int n;

	for(s = foo; *s != '\0';)
	{
		n = (int) strspn(s, seps);
		if(n > 0)
		{
			printf("skipping separators << %.*s >> (length = %d)\n",n,s,n);
		}
		s += n;
		n = (int) strcspn(s, seps);
		if(n > 0)
		{
			printf("token found << %.*s >> (length = %d)\n",n,s,n);
		}
		s += n;
	}
}