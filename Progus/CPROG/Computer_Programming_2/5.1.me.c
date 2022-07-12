#include <stdio.h>

int main()
{
	char a, b;
	
	a=1;
	b=~a;
	printf("a = %d, b = %d\n", a, b);
	
	a=2;
	b=~a;
	printf("a = %d, b = %d\n", a, b);
	while(scanf("%hhd", &a)!=EOF) printf("a = %d, ~a = %d\n", a, ~a);
	return 0;
}
