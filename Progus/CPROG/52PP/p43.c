#include <stdio.h>

int main()
{
	int T, temp, j, res, p, q, c;
	
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &p, &q, &c);
		temp = 1;
		for(j=1; j<=q; j++)temp=(temp*p)%c;
		
		res = temp%c;
		
		printf("Result = %d\n", res);
	}
	
	return 0;
}
		
