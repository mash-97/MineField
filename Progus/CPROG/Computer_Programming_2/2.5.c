#include <stdio.h>

int main()
{
	int x = 10;
	int *p;
	
	printf("Value of x: %d\n", x);
	
	p = &x;
	*p = 20;
	
	printf("Value of x: %d\n", x);
	
	x = 15;
	
	printf("Value of x: %d\n", x);
	printf("Value stored at location %p is %d\n", p, *p);
	
	printf("Address of x: %p\n", &x);
	printf("Value of p: %p\n", p);
	
	int *k=&x;
	printf("*k = %d\n", *k);
	printf("k = %p\n", &k);
	
	return 0;
}
