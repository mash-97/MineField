#include <stdio.h>

int main()
{
	int T, N;
	scanf("%d", &T);
	for(int i=0; i<T; i++)
	{
		scanf("%d", &N);
		long long int factoriaOf_N = 1;
		for(int i=2; i<=N; i++)factoriaOf_N *= i;
		printf("%lldde\n", factoriaOf_N);
	}
	return 0;
}
