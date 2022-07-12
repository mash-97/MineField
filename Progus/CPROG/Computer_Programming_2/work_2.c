#include <stdio.h>

int x=1;

void funct(int x)
{
	int a = x, b;
	b = x = x+5;
	printf("a = %d, b = %d, x = %d\n", a, b, x);
}

int main()
{
	int y = 5;
	x = x+1;
	funct(y);
	printf("x = %d, y = %d\n", x, y);
	
	return 0;
}
