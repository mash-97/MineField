#include <stdio.h>
#define swap(a,b) {\
		a^=b; b^=a; a^=b;\
}

void sSort(int array[], int n)
{
	int i, j, index_min;
	
	for(i=0; i<n-1; i++)
	{
		index_min = i;
		for(j=i+1; j<n; j++) if(array[j] > array[index_min]) index_min = j;
		
		if(i!=index_min) swap(array[index_min], array[i]);
	}
}


void display(int array[], int n)
{
	for(int i=0; i<n; i++)  printf("%d ", array[i]);
	puts("");
}

int main()
{
	int n; scanf("%d", &n);
	printf("Enter %d numbers: ", n);
	int numbers[n];
	for(int i=0; i<n; i++) scanf("%d", &numbers[i]);
	
	//Selection sort.
	sSort(numbers, n);
	printf("Displaying in sorted: ");
	display(numbers, n);
	
	return 0;
}
