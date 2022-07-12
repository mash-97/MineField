#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	return *(int *) a  - *(int *) b;
}

void display(int n, int *array)
{
	for(int i=0; i<n; i++) printf("%d ", array[i]);
	puts("");
}

void minMax(int n, int *a)
{
	qsort(a, n, sizeof(int), compare); display(n, a);
	long long unsigned int sum = 0;
	for(int i=0; i<n-1; i++) sum+=a[i];
	printf("%llu ", sum);
	
	sum = 0;
	for(int i=n-1; i>=1; i--) sum+=a[i];
	printf("%llu\n", sum);
}


int main()
{
	int n;
	scanf("%d", &n);
	
	int array[n];
	
	for(int i=0; i<n; i++) scanf("%d", &array[i]);
	
	minMax(n, array);
	
	main();
	return 0;
}
