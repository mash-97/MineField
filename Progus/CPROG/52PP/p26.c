#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		double c;
		int total_days = 0;
		scanf("%lf", &c);
		while(c>=1.0)
		{
			c*=0.5;
			++total_days;
		}
		printf("%d days\n", total_days);
	}
	return 0;
}
