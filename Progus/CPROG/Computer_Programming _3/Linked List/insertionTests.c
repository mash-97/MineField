#include <stdio.h>


void isort(int n, int array[])
{
	int i, j, item;
	
	for(i=1; i<n; i++)
	{
		item = array[i];
		j = i-1;
		while(j>=-0 && array[j] > item)
		{
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = item;
	}
}


void d(int n, int *array)
{
	for(int i=0; i<n; i++) printf("%d ", array[i]);
	puts("");
}

int main()
{
	int n;
	scanf("%d", &n);
	
	int array[n];
	for(int i=0; i<n; i++) scanf("%d", &array[i]);
	
	isort(n, array);
	d(n, array);
	
	return 0;
}
