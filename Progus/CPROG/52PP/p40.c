#include <stdio.h>

int main()
{
	int T, X, K;
	int res, a, i;
	
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &X, &K);
		a = 1;
		res = a;
		for(i=1; i<=K; i++)
		{
			a *= X;
			res += a;
		}
		printf("Result = %d\n", res);
	}
	return 0;
}
