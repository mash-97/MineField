#include <stdio.h>

int main()
{
	char s[] = "Bangladesh";
	
	printf("Name of our country : %s\n", s);
	printf("Address of s: %p\n", s);
	printf("Address of s[0]: %s\n", &s[0]);
	
	return 0;
}
