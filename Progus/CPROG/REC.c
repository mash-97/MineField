#include <stdio.h>

int power2(int n, int i, int base)
{
	if(i==base)return n;
	return power2(n, i+1, base) + n;
}

int power4(int number)
{
	return power2(number, 1, power2(number, 1, power2(number, 1, number)));
}

int main()
{
	int number;

	scanf("%d", &number);

	printf("%d\n", power4(number));

	return 0;
}
