#include <stdio.h>

int main()
{
	int T, N, num, sum, s_sum;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		sum = 0;
		s_sum = (N*1.0/2)*(N+1);
		for(int i=1; i<N; i++)
		{
			scanf("%d", &num);
			sum+=num;
		}
		if(sum==s_sum)printf("There is no missing.\n");
		else printf("Missing number: %d\n", s_sum-sum);
	}
	
	return 0;
}
