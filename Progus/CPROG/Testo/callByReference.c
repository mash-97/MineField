#include <stdio.h>

void swap(int *a, int *b=NULL)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	int a = 5, b = 10;
	
	printf("Before swap:: a: %d  b: %d\n", a, b);
	
	swap(&a, &b);
	
	printf("After swap:: a: %d   b: %d\n", a, b);

	return 0;
}
