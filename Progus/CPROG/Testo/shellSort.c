#include <stdio.h>


void display(int *array, int n)
{
	for(int i=0; i<n; i++) printf("%d ", array[i]);
	puts("");
}

void shellSort(int a[], int n)
{
	int i, j, gap, tmp;
	
	for(gap = n/2; gap > 0; gap = gap / 2)
	{
		for(i=gap; i<n; i++)
		{
			tmp = a[i];
			for(j = i; j >= gap; j = j - gap)
			{
				if(tmp < a[j-gap])
					a[j] = a[j-gap];
				else
					break;
			}
			
			a[j] = tmp;
		}
	}
}


int main()
{
	int i, n; 
	printf("Enter the number of elements :: ");
	scanf("%d", &n);
	
	int a[n];
	printf("Enter the elements :: ");
	for(i=0; i<n; i++)	scanf("%d", &a[i]);
	
	shellSort(a, n);
	printf("The sorted elements are :: ");
	for(i=0; i<n; i++)	printf("%d ", a[i]);
	
	printf("\n");
	
	return 0;
}
