#include <stdio.h>
#include <stdlib.h>
int main()
{
	long long int l;
	char s[10001];


	printf("Enter numbers in one line with spaces: ");
	scanf(" %[^\n]", s);
	printf("Entered string is %s\nNumbers are:\n", s);

	int count = 0;
	char *n, *e;

	for(n=s;;n=e)
	{

		l = strtoll(n, &e, 10);
		if(n==e) break;
		count ++;
		printf("%lld\n", l);
	}

	printf("total: %d\n", count);


	return 0;
}
