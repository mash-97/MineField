#include <stdio.h>

int main()
{
	char a, b;
	
	for(a=1, b = 26; a<=97; a++)
	printf("%d ^ %d = %d\n", a, b, a^b);

	return 0;
}
