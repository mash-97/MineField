#include <stdio.h>

int main()
{
	int t, x, y;
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%d%d", &x, &y);
		
		double voc = 3.14159 * (x*x) * y;       // voc = volume of the cylinder
		
		printf("%.3lf\n", (voc - (voc/3)));
	}
	return 0;
}
