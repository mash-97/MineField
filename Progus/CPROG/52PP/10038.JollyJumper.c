#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, a, flag, i, count;
	int array[3001];
	int mark[3001];
	
	while(scanf("%d", &n)!=EOF)
	{
		for(i=1; i<n; i++)mark[i]=0;
		flag=0;
		count=0;
		scanf("%d", &array[0]);
		for(i=1; i<n; i++)
		{
			scanf("%d", &array[i]);
			a = abs(array[i-1] - array[i]);
			if(a>=1 && a<=n-1 && mark[a]==0)mark[a]=1;
			if(flag==0 && !(a>=1 && a<=n-1))flag=1;
		}
		for(i=1; i<n; i++)
		{
			if(mark[i]==1)++count;
			else break;
		}
		if(flag==0 && count==n-1)printf("Jolly\n");
		else printf("Not jolly\n");
	}
	
	return 0;
}
		
