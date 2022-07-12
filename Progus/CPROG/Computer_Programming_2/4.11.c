#include <stdio.h>

int count;

int factorialOf(int n)
{
	++count;
	if(n==0) return 1;
	return n*factorialOf(n-1);
}

int main()
{
	count = 0;
	int number;
	scanf("%d", &number);
	if(number<0) printf("Undefined for factorialOf(%d)!\n", number);
	else if(number>12) printf("The factorial of %d is too big.\n", number);
	else printf("The factorial of %d is %d\n", number, factorialOf(number));
	printf("And the factorial function was called %d times\n", count);
	main();
}
