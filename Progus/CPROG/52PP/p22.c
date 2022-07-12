#include <stdio.h>
#include <math.h>
#define size 100001

char array[size];

void sieve()
{
	int i, j, root;
	
	//marking all 1 for 2 to size..........1 indicates prime.
	for(i=2; i<size; i++)array[i]=1;
	
	root = sqrt(size);
	
	for(i=2; i<=root; i++)
	{
		if(array[i]==1)
		{
			for(j=2; i*j <= size; j++)
			{
				array[i*j] = 0;
			}
		}
	}
}

int main()
{
	int T, a, b, count;
	sieve();
	
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &a, &b);
		count = 0;
		
		for(int i=a; i<=b; i++)if(array[i]==1)++count;
		printf("%d\n", count);
	}
	return 0;
}
