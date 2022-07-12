#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int main()
{
	int n;
	int *numbers;
	
	printf("Total number : ");
	scanf("%d", &n);
	
	numbers = (int *) malloc(sizeof(int)*n);
	
	printf("Enter %d number(s): ", n);
	for(int i=0; i<n; i++) scanf("%d", &(*(numbers+i)));
	
	qsort(numbers, n, sizeof(int), &compare);
	
	printf("Numbers you've entered: ");
	for(int i=0; i<n; i++) printf("%d ", *(numbers+i));
	puts("");
	
	int key;
	while(printf("Enter a number: ") && scanf("%d", &key) && key >= 0)
	{
		
		if((int *)bsearch(&key, numbers, n, sizeof(int), &compare) != NULL) printf("The number %d is in the array\n", key);
		else printf("The number %d isn't found!!!\n", key);
	}
	
	return 0;
}
