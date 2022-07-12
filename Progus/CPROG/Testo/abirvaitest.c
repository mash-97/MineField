#include <stdio.h>


int main()
{o
	int w, h, x, y, r;
	scanf("%d%d%d%d%d", &w, &h, &x, &y, &r);
	
	if((x+r>w || x-r<0) || (y+r>h || y-r<0)) printf("No\n");
	else printf("Yes\n");
	
	
    return 0;
}
