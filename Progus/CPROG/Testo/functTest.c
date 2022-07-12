#include <stdio.h>

int add(int a, int b)
{
	return a+b;
}

int sub(int a, int b)
{
	return a-b;
}


int operation(int a, int b, int (*op)(int,int))
{
	return op(a,b);
}


int main()
{
	printf("%d\n", operation(5,6, &sub));
	return 0;
}

