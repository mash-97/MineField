#include <stdio.h>
#include <string.h>
int main()
{
	int n, m, x;
	char l_r[2];
	char ll_rr[8];
	while(1)
	{
		printf("Please enter your number (0 to exit): ");
		scanf("%d", &n);
		
		if(n==0) break;
		printf("Left or Right Shift (l/r): ");
		scanf("%s", l_r);
		if(l_r[0]=='l') strcpy(ll_rr, "left");
		else if(l_r[0]=='r') strcpy(ll_rr, "right");
		
		printf("How many bits you want to shift %s? ", ll_rr);
		scanf("%d", &x);
		
		if(l_r[0]=='l') m = n << x;
		else if(l_r[0]=='r') m = n >> x;
		
		printf("Result is %d\n\n", m);
	}
	
	return 0;
}
