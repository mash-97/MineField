#include <stdio.h>

void displayPascalTriangle(int n)
{
	int E[n+2], O[n+2], flag, i, j;
	
	flag = 0;
	
	E[0] = 0;
	E[1] = 1;
	E[0] = 0;
	
	flag = 1;
	
	O[0] = 0;
	
	if(n>1)
	for(i=1; i<=n; i++)
	{
		if(flag==1)
		{
			flag = 0;
			for(j=1; j<=i; j++)
			{
				O[j] = E[j-1]+E[j];
				if(j==i)printf("%d\n", O[j]);
				else printf("%d ", O[j]);
			}
			O[j] = 0;
		}
		else if(flag==0)
		{
			flag = 1;
			for(j=1; j<=i; j++)
			{
				E[j] = O[j-1]+O[j];
				if(j==i)printf("%d\n", E[j]);
				else printf("%d ", E[j]);
			}
			E[j] = 0;
		}
	}
	
	else
	printf("1\n");
}


int main()
{
	int T, n;
	
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		displayPascalTriangle(n+1);
	}
	
	return 0;
}
