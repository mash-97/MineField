#include <stdio.h>

int main()
{
	int t; scanf("%d", &t);
	while(t--)
	{
		int otr, cr, rb; 
		scanf("%d %d %d", &otr, &cr, &rb);
		printf("%.2lf %.2lf\n", cr/((300-rb)/(double)6), (otr-cr+1)/((rb)/(double)6));
	}
	return 0;
}
