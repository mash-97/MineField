#include <stdio.h>

int main()
{
	char a[2];
	
	while(scanf("%s", a)!=EOF) printf("%c\n", a[0]^32);
	
	return 0;
}
		
