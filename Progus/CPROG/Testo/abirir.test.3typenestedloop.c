#include <stdio.h>

int main()
{
	int n, x;
	int total = 0;
	
	scanf("%d%d", &n, &x);
	
	//for(int i=1; i<=n; i++) mark[i] = 1;
	
	for(int i=1; i<=n; i++)
	if(!(i>(x-2)))
	{
		for(int j=i+1; j<=n; j++)
		{
			if((j> x-1 || i+j > x) && i!=j) break;
			for(int k=j+1; k<=n; k++)
			if(i!=k && k!=j)
			{
				if(i+j+k > x) break;
				if(i+j+k == x)
				{
					//mark[i] = mark[k] = mark[j] = 0;
					++total;
					break;
				}
			}
		}
	}
	
	printf("%d\n", total);
	main();
	return 0;
}
				
