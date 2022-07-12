#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	int *array = (int *) calloc(1000000, sizeof(int));
	
	int max=0;
	int numb;
	for(int i=0; i<n; i++)
	{
		scanf("%d", &numb);
		array[numb]++;
		if(max<numb) max = numb;
	}
	
	for(int i=0; i<=max; i++)
	{
		int c = array[i];
		for(int j=1; j<=c; j++)
			printf("%d ", i);
	}
	puts("");
	return 0;
}
