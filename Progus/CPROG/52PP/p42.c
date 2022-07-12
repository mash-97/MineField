#include <stdio.h>

int main()
{
	int T, n;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		while(1)
		{
			if(n<=1)
			{
				printf("%d + %d\n", 2, 1);
				break;
			}
			else printf("2^%d + ", n);
			n--;
		}
	}
	return 0;
}
