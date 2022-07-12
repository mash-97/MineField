#include <stdio.h>
#define swap(a,b){a=(a+b)-(b=a);}
int main()
{
	int T, kase, n1, n2, n3;
	scanf("%d", &T);
	for(kase=1; kase<=T; kase++)
	{
		scanf("%d %d %d", &n1, &n2, &n3);

		if(n1 > n2) swap(n1, n2);
        if(n1 > n3) swap(n1, n3);
        if(n2 > n3) swap(n2, n3);

		printf("Case %d: %d %d %d\n", kase, n1, n2, n3);
	}
	return 0;
}


