#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display(int array[], int n);

void isort(int array[], int n)
{
	int item;
	for(int i=1; i<n; i++)
	{
		item = array[i];
		
		int j = i-1;
		
		while(j>=0 && array[j]>item)
		{
			array[j+1] = array[j];
			j--;
		}
		
		array[j+1] = item;
		display(array, n);
	}
}


void display(int array[], int n)
{
	for(int i=0; i<n; i++) printf("%d ", array[i]);
	puts("");
}

int main()
{
	printf("Insertion sort:\n\n");
	clock_t s, e;
	double time;
	int n; int *numbers;
	//printf("How much number do you want to insert: ");
	scanf("%d", &n);
	numbers = (int *) malloc(sizeof(int)*n);
	for(int i=0; i<n; i++) scanf("%d", &numbers[i]);
	
	s = clock();
	isort(numbers, n);
	e = clock();
	time = (double)(e-s)/CLOCKS_PER_SEC;
	printf("sorted: execution time: %0.6lf\n", time);
	display(numbers, n);
	main();
	return 0;
}
	

