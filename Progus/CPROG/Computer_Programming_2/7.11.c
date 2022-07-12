#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareFunc(const void *a, const void *b)
{
	return -(*(int *)a - *(int *)b);
}

int main()
{
	int i, n=2;
	int values[] = {65, 6};
	
	qsort(values, n, sizeof(int), compareFunc);
	
	for(i=0; i<n; i++) printf("%d ", values[i]);
	
	printf("\n");
	printf("\n");

	printf("%d\n", strcmp("bb", "ba"));
	return 0;
}
	
