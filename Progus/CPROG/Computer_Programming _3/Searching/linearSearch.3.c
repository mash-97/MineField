#include <stdio.h>

int linearSearch(int A[], int m, int n, int x)
{
	int i;
	for(i=m-1; i<n; i++) if(A[i]==x) return i;
	return -1;
}


int main()
{
	int array_size;
	printf("Enter Array size and its elements: ");
	scanf("%d", &array_size);
	
	int A[array_size];
	for(int i=0; i<array_size; i++) scanf("%d", &A[i]);

	again:
	printf("Enter the start and last positions and the number you want to check: ");
	int m, n, x;
	scanf("%d %d %d", &m, &n, &x);
	
	int pos = linearSearch(A, m, n, x);
	
	if(pos > -1) printf("The number %d is found in %d position between %d to %d delimeter.\n", x, pos+1, m, n);
	else printf("The number %d isn't found between %d to %d delimeter.\n", x, m, n);
	goto again;
	return 0;
}
