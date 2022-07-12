#include <stdio.h>

int main()
{
	int k;
	scanf("%d", &k);
	if(k>36) printf("-1\n");
	
	else
	while(k>0)
	{
		if(k>=2){ printf("8"); k-=1; }
		else printf("0");
		k--;
	}
	
	return 0;
}
