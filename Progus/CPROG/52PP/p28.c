#include <stdio.h>

int isSortedA(int length, int array[])
{
	int i;
	for(i=1; i<length; i++)if(array[i]<array[i-1])return 0;
	return 1;
}

int isSortedD(int length, int array[])
{
	int i;
	for(i=1; i<length; i++)if(array[i]>array[i-1])return 0;
	return 1;
}
	
int main()
{
	int T, n, array[21], i;
	scanf("%d", &T);
	
	while(T--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)scanf("%d", &array[i]);
		
		if(isSortedA(n, array) || isSortedD(n, array))printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
	
