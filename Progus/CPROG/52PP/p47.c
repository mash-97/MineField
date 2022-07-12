#include <stdio.h>
#include <math.h>
int main()
{
	int t, a, b, c;
	double area, s;
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d%d", &a, &b, &c);
		s = (a+b+c*1.0)/2;
		area = sqrt(s*(s-a)*(s-b)*(s-c));
		
		printf("Area = %.3lf\n", area);
	}
	
	return 0;
}
