#include <stdio.h>

int main()
{
	int n1, n2;
	
	
	while(scanf("%d%d", &n1, &n2)!=EOF)	printf("%d & %d = %d\n", n1, n2, n1&n2);
	
	return 0;
}
