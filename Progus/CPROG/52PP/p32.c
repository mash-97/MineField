#include <stdio.h>

int main()
{
	int T, N, X, i;
	
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &X, &N);
		if(X>N)printf("Invalid!\n");
		else
		{
			for(i=X; i<=N; i+=X)printf("%d\n", i);
		}
	}
	return 0;
}


