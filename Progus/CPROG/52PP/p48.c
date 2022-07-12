#include <stdio.h>

int main()
{
	int T, N, array[100001], number, missing_number, flag;
	scanf("%d", &T);
	
	while(T--)
	{	
		scanf("%d", &N);
		for(int i=0; i<=N; i++)array[i]=0;

		for(int i=0; i<N-1; i++)
		{
			scanf("%d", &number);
			array[number]=1;
		}
		flag=0;
		for(int i=1; i<=N; i++)
		{
			if(array[i]==0)
			{
				missing_number = i;
				flag=1;
				break;
			}
		}
		if(flag==1)printf("Missing number: %d\n", missing_number);
		else printf("There is no missing number.\n");
	}
	return 0;
}
