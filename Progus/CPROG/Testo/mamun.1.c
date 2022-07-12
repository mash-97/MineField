#include <stdio.h>

int main()
{
	int i, x = 1, y = 1;
	i = 1;
	while(i<6)
	{
		i++;
		if(x==5)
		{
			printf("Value of Y is: %d\n", y);
			continue;
		}
		
		else
		{
			x+=y;
			printf("Value of X is: %d\n", x);
		}
	}
	
	return 0;
}
