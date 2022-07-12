#include <stdio.h>

int main()
{
	char s[] = "Bangladesh";
	char *p;
	
	p = &s;
	
	printf("Name of our country : %c\n", *(p+3));
	
	return 0;
}
