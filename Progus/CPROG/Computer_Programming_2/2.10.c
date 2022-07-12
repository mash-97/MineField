#include <stdio.h>

int main()
{
	int x = 100;
	int *p;
	printf("Value of x is %d\n", x);
	p = &x;
	printf("Value of *p is %d\n", *p);
	
	return 0;
}

