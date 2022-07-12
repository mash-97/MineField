#include <stdio.h>

int main()
{
	char s[] = "Bangladesh";
	long
	 p[] = {1,2,3};
	
	printf("%c, %c, %c, %c\n", *(s), *(s+1), *(s+2), *(s+3));
	printf("%c, %c, %c, %c\n", *s, *s+1, *s+2, *s+3);
	
	printf("%d, %d\n", p, p+1);
	return 0;
}
