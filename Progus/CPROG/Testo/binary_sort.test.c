#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b)
{
	return ( *(int *)a > *(int *)b ) ? 1 : 0;
}

int * binary_search(int *array, int length, int number);

void display(int *a, int length)
{
	for(int i=0; i<length; i++)
		printf("%d ", a[i]);
	puts("");
}


int main()
{
	int length;
	scanf("%d", &length);
	int array[length];
	for(int i=0; i<length; i++) scanf("%d", &array[i]);
	
	clock_t sort_start = clock();
	qsort(&array, length, sizeof(int), &compare);
	clock_t sort_end = clock();
	printf("Sorting time for %d length: %.6lf\n", length, (double)(sort_end-sort_start)/CLOCKS_PER_SEC);
	printf("Sorted array: ");
	display(array, length);
	puts("");
	
	int number;
	printf("Enter the number you want to search: ");
	scanf("%d", &number);
	
	clock_t search_start = clock();
	int * numb = binary_search(array, length, number);
	clock_t search_end = clock();
	printf("Searching time for %d length: %.6lf\n", length, (double)(search_end-search_start)/CLOCKS_PER_SEC);
	if(numb == NULL) printf("Number not found: ");
	else printf("Number found: %d\n", *numb);
	
	return 0;
}
	
	
int * binary_search(int *array, int length, int number)
{
	int left = 0;
	int right = length-1;
	int mid = left+(right-left)/2;
	
	while(left >= right)
	{
		if(array[mid] == number) return &array[mid];
		else if(array[mid] > number) right = mid;
		else left = mid;
		mid = left + (right-left)/2;
	}
	
	return NULL;
}
	
	
