#include <stdio.h>

int add(int n1, int n2)
{
	return n1+n2;
}

int sub(int n1, int n2)
{
	return n1-n2;
}

int operate(int (*operation)(int, int), int n1, int n2, int n3, int n4)
{
	return operation(operation(operation(n1, n2), n3), n4);
}

int main()
{
	int n1, n2, n3, n4;
	
	n1 = 50;
	n2 = 45;
	n3 = 5;
	n4 = 4;
	
	printf("add of %d and %d is %d\n", n1, n2, operate(add, n1, n2, n3, n4));
	printf("sub of %d and %d is %d\n", n1, n2, operate(sub, n1, n2, n3, n4));
	
	return 0;
}
