#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *marks;
	
	int  n;
	printf("Enter the number of students: ");
	scanf("%d", &n);
	marks = calloc(n, sizeof(marks)*n);
	
	printf("Enter marks: ");
	for(int i=0; i<n; i++) scanf("%d", &marks[i]);
	printf("Now you can see: ");
	for(int i=0; i<n; i++) printf("%d ", marks[i]);
	
	free(marks);

	return 0;
}
