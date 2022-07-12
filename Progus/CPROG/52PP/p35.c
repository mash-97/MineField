#include <stdio.h>
#include <math.h>

int distance(int x, int y, int xx, int yy)
{
	return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}

int main()
{
	int T;
	int x, y, xx, yy, r;
	
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &x, &y);
		scanf("%d", &r);
		scanf("%d%d", &xx, &yy);
		
		if(distance(x,y, xx,yy)<=r)printf("The point is inside the circle\n");
		else printf("The point is not inside the circle\n");
	}
	return 0;
}
