#include <stdio.h>

int main()
{
	int T;
	long long int A, B, C, i;
	
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld%lld%lld", &A, &B, &C);
		
		for(i=A; i%C!=0; i++);
		//printf("A=%d, C=%d, i=%d\n");
		while(i<=B)
		{
			printf("%lld\n", i);
			i+=C;
		}
	}
	return 0;
}
		
