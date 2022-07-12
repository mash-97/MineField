#include <stdio.h>

int main()
{
	int n,m;
	
	scanf("%d%d", &n, &m);
	
	if(n^m)printf("%d and  %d ain't equal.\n", n, m);
	else printf("%d and %d are equal.\n", n, m);
	
	return 0;
}
