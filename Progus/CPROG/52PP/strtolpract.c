#include <stdio.h>
#include <stdlib.h>

int main()
{
	char numbers[100002];
	scanf(" %[^\n]", numbers);
	char *p, *e;
	long long sum = 0;
	int count = 0;
	for(p = numbers; ; p = e)
	{
		sum+=strtol(p, &e, 10);
		if(p == e) break;
		++count;
	}
	printf("sum = %lld and total numbers = %d, numbers are %s\n", sum, count, numbers);
	main();
	return 0;
}

