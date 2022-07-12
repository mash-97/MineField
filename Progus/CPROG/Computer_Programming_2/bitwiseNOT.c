#include <stdio.h>

int main()
{
	char a;
	
	while(scanf("%hhd", &a)!=EOF) printf("~%d = %d\n\n", a, ~a);
	
	return 0;
}
