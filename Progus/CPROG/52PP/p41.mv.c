#include <stdio.h>
#define SIZE 200

unsigned long long int factorials[SIZE];

void initialize()
{
	factorials[0] = 1;
	int i;
	for(i=1; i<=SIZE; i++)factorials[i] = i*factorials[i-1];
}
int main()
{
	initialize();
	for(int i=0; i<SIZE; i++)printf("%d. %llu\n", i+1, factorials[i]);
	puts("");
	
	int T, n, i;
	double res;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		
		res = 0;
		for(i=1; i<=n; i++)res+=(double)i/factorials[i];
		
		printf("%.4lf\n", res);
	}
	return 0;
}
