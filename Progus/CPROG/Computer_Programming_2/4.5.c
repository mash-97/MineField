#include <stdio.h>
int count = 0;
void recurse()
{
	++count;
	char *s = "Hurrey, I am learning recursion!";
	printf("%d: %s\n", count, s);
	
	recurse();
}

int main()
{
	recurse();
	return 0;
}
