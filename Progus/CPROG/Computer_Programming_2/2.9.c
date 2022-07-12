#include <stdio.h>

int main()
{
	int x = 100;
	int *p;
	*p = 2;
	printf("Value of x is %d\n", x);
	printf("Value of *p is %d\n", *p);
	
	return 0;
}
