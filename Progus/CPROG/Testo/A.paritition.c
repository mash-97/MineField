#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	int sum = 0, number;
	for(int i=1; i<=n; i++)
	{
		scanf("%d", &number);
		sum += (number<0) ? -number : number;
	}
	
	printf("%d\n", sum);
	
	return 0;
}
