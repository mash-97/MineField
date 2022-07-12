#include <stdio.h>
#include <stdlib.h>

int main()
{
	int * marks;
	int n, i;
	
	printf("Please enter the number of students: ");
	scanf("%d", &n);
	
	marks = (int *) malloc(sizeof(marks) * n);
	
	printf("Enter %d values: ", n);
	for(i=0; i<n; i++) scanf("%d", &marks[i]);
	
	printf("Showing values:\n");
	for(i=0; i<n; i++)printf("%d\n", marks[i]);
	
	return 0;
}
