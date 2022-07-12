#include <stdio.h>

int mark[101];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	
	int l, r, total = m;
	int i, j;
	for(int i=1; i<=n; i++)
	{
		scanf("%d%d", &l, &r);
		for(int i=l; i<=r; i++) if(!mark[i]){ mark[i] = 1; --total;}
	}
	
	printf("%d\n", total);
	for(i=1, j=1; j<=total; i++)
	if(!mark[i])
	{
		printf("%d", i);
		if(j!=total) printf(" ");
		j++;
	}
	
	printf("\n");
	return 0;
}
	
