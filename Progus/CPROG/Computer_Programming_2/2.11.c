#include <stdio.h>

int main()
{
	int x=10;
	int *p = NULL;
	p = &x;
	
	if(p==NULL)printf("Null\n");
	else printf("Not Null\n");
	
	return 0;
}
