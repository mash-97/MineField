#include <stdio.h>

int main()
{
	int t; scanf("%d", &t);
	while(t--)
	{
		int number; scanf("%d", &number);
		int total_zero = 0;
		for(int divider = 5; divider<=number; divider *= 5)total_zero += number/divider;
		printf("%d\n", total_zero);
	}
	return 0;
}
