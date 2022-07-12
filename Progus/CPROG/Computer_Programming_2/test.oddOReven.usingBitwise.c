#include <stdio.h>

int main()
{
	int number;
	
	while(scanf("%d", &number)!=EOF)
	{
		if((number & 1) == 1) printf("%d is odd.\n\n", number);
		else if((number & 1) == 0) printf("%d is even.\n\n", number);
	}
	
	return 0;
}
