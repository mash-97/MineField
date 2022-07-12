#include <stdio.h>

union u
{
	char ch;
	int x;
	int y;
} uv;

int main()
{
	uv.ch = 'A';
	printf("uv.ch = %c\n", uv.ch);
	
	uv.x = 17;
	printf("\nuv.x = %d\n", uv.x);
	printf("uv.ch = %c\n", uv.ch);
	
	uv.y = 21;
	printf("\nuv.y = %d\n", uv.y);
	printf("uv.x = %d\n", uv.x);
	printf("uv.ch = %c\n", uv.ch);
	
	for(int i=0; i>=-1222; i--) printf("%d-> %c\n", i, i);
	return 0;
}
