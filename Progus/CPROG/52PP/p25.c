#include <stdio.h>

int gcd(int a, int b)
{
	int temp;
	while(b!=0)
	{
		temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}

int main()
{
	int T, a, b;
	
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &a, &b);
		printf("LCM = %d\n", (a*b)/gcd(a,b));
	}
	return 0;
}
