#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	int a2 = 0;
	int a1 = 0;
	int x;
	
	for(int i=0; i<n; i++)
	{
		scanf("%d", &x);
		(x==100) ? a1++ : a2++;
	}

	int r = (n&1 && a2&1 && !(a1&1) && a1!=0);
	r |= (!(n&1) && (!(a2&1) && (a2==a1 || a2==0 || a1==0) ));
	
	if(r) puts("YES");
	else puts("NO");
	
	return 0;
}
	
