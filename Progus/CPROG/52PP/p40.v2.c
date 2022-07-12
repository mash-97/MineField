#include <stdio.h>
#include <math.h>

int main()
{
	int T, x, k;
	int res;
	
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &x, &k);
		res = (1-pow(x,k+1))/(1-x);
		printf("Result = %d\n", res);
	}
	return 0;
}
