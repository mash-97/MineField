#include <stdio.h>
int main()
{
	int a, b, x,y;
	scanf("%d %d", &a, &b);
	x=a-b;
	y=x%10;
	x-=y;
	if(y!=9)
		y++;
	else
		y--;
	printf("%d\n",x+y);
	return 0;
}
