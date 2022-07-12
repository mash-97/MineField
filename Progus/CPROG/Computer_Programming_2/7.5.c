#include <stdio.h>

int main()
{
	int ar[] = {100, 300, 500, 700, 900};
	int *p;
	
	p = ar;
	
	for(int i=0; i<5; printf("*(p+%d) : %d\n", i, *(p+i)), i++);
	for(int i=0; i<5; printf("p[%d] = %d\n", i, p[i]), i++);
	return 0;
}
