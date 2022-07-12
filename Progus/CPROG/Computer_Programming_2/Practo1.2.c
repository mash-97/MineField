#include <stdio.h>

int main()
{
	char c = 'A';
	char *p, **q, *k;
	
	p = &c;
	k = &c;
	q = &p;
	
	printf("%c, %c\n", **q, &(*p));
	
	return 0;
}
