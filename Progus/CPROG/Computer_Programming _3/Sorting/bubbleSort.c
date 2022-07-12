#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(a,b){a^=b;b^=a;a^=b;}
void display(int array[], int n);
void bsort(int array[], int n)
{
	int flag = 0;
	for(int i=0; i<n; i++)
	{
		flag = 0;
		for(int j=0; j<n-i-1; j++)
		{
			
			if(array[j]>array[j+1])
			{
				flag = 1;
				swap(array[j], array[j+1]);
			}
			
			
		}
		display(array, n);
		if(flag==0) break;
	}
		
}

void display(int array[], int n)
{
	for(int i=0; i<n; i++) printf("%d ", array[i]);
	puts("");
}

int main()
{
	printf("Bubble sort:\n\n");
	clock_t s, e;
	double time;
	int n; int *numbers;
	//printf("How much number do you want to insert: ");
	scanf("%d", &n);
	numbers = (int *) malloc(sizeof(int)*n);
	for(int i=0; i<n; i++) scanf("%d", &numbers[i]);
	
	s = clock();
	bsort(numbers, n);
	e = clock();
	time = (double)(e-s)/CLOCKS_PER_SEC;
	printf("sorted: execution time: %0.6lf\n", time);
	display(numbers, n);
	main();
	return 0;
}
	
