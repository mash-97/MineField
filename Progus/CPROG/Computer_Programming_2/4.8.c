#include <stdio.h>

void recurse(int c)
{
	if(c>5) return;
	printf("%d\n", c);
	recurse(c+1);
	printf("%d\n", c);
}

int main()
{
	recurse(1);
	return 0;
}
