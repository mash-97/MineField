#include <stdio.h>

void plusTen1(int a)
{
	a += 10;
}

void plusTen2(int * a)
{
	*a += 10;
}

int main()
{
	int a = 5;

	plusTen1(a);
	
	printf("a = %d\n", a);
	
	plusTen2(&a);
	
	printf("a = %d\n", a);
	
	return 0;
}
