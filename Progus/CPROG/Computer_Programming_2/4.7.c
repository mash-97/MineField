#include <stdio.h>

void recurse(int count)
{
	if(count>=5)
	{
		 printf("%d\n", count);
		 recurse(--count);
	}
	else if(count<=1)
	{
		printf("%d\n", count);
		recurse(++count);
	}
	else
	{
		 recurse(0);
	}
	return;
}

int main()
{
	recurse(1);
	return 0;
}
