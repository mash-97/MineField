#include <stdio.h>

int main()
{
	int x = 10, y;
	int *p, *q;
	
	p = &x; 
	y = *p;
	*p = 15;
	*q = 20;
	
	printf("Value of x: %d\n", x);
	printf("Value of y: %d\n", y);
	printf("Value of *p: %d\n", *p);
	printf("value of *q: %d\n", *q);
	
	return 0;
}
