#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	int res = 0;
	for(int i=1; i<=n; i++)
	{
		 //printf("%d^%d = %d\n", i , res, (res ^= i));
		  printf("%d^%d = %d\n", i , res, (res ^ i));
		  res^=i;
	}
	printf("\nres = %d\n", res);
	
	int x=0;
	int number, coupled_number;
	printf("Enter %d numbers below:\n", n-2);
	
	for(int i=1; i<n-1; i++)
	{
		scanf("%d", &number);
		x ^= number;
	}
	
	printf("res = %d, x = %d, res^x = %d\n", res, x, res^x);
	if((res^x)&1) coupled_number = (res^x)-1;
	else coupled_number = (res^x)+1;
	printf("Coup = %d\n", coupled_number);
	return 0;
}
