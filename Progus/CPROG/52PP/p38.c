#include <stdio.h>

void diamondShape(int n, int m)
{
	int i, j, di=1; 
	for(i=1; i>=1; i+=di)
	{
		for(j=1; j<=i; j++)
		{
			if(j==i)printf("%d\n", m);
			else printf("%d ", m);
		}
		if(i==n)di=-1;
	}
}

void diamondShapeM2(int n, int m)
{
	int i=1, j=1, di=1;
	while(j>=1)
	{
		if(i==j)
		{
			printf("%d\n", m);
			i=0;
			if(j==n)di=-1;
			j+=di;
		}
		else printf("%d ", m);
		
		i++;
	}
}
		
int main()
{
	int T, n, m;
	
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		diamondShapeM2(n, m);
		puts("");
	}
	
	return 0;
}
