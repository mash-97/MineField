#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	//char array[n][n];
	for(int i=0; i<=n; i++)
	{
		for(int j=0; j<=n; j++)
		{
			if(i==j) break;
			else printf("*");
		}
		printf("\n");
	}
	
	
	
	
	
	return 0;
}
