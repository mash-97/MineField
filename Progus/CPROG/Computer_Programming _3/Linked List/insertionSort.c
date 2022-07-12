#include <stdio.h>
#include <stdlib.h>
#define swap(a,b){a^=b; b^=a; a^=b;}

void iSort(int n, int array[])
{
	for(int i=1; i<n; i++)
	{
		int j = i-1;
		while(j>=0 && array[j] > array[j+1])
		{
			swap(array[j], array[j+1]);
			j--;
		}
	}
}

void shellSort(int n, int array[])
{
	for(int gap = n/2; gap>0; gap/=2)
	{
		for(int i=gap; i<n; i++)
		{
			for(int j=i-gap; j>=0 && array[j] > array[j+gap]; j-=gap) swap(array[j], array[j+gap]);
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int array[n];
	for(int i=0; i<n; i++) scanf("%d", &array[i]);
	
	//iSort(n, array);
	shellSort(n, array);
	puts("");
	for(int i=0; i<n; i++) printf("%d ", array[i]);
	puts("");
	
	return 0;
}
