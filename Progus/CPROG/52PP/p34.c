#include <stdio.h>

int lcd(int a, int b)
{
	int temp, A=a, B=b;
	while(b!=0)
	{
		temp = b;
		b = a%b;
		a = temp;
	}
	return a*A*B;
}

int main()
{
	int T, A, B, l;
	long long int C, i;
	
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%lld", &A, &B, &C);
		l = lcd(A,B);
		for(i=l; i<=C; i+=l)printf("%lld\n", i);
	}
	return 0;
}
