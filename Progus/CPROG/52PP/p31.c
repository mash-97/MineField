#include <stdio.h>
#include <math.h>

int main()
{
	int T, sum, num, N, i, sqrt_n;
	
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		for(num=2; num<=N; num++)
		{
			sum=1;
			sqrt_n = sqrt(num);
			for(i=2; i<=sqrt_n; i++)
			{
				if(num%i==0)
				{
					sum+=i+(num/i);
				}
			}
			if(sum==num)printf("%d ", num);
		}
		printf("\n");
	}
	return 0;
}
