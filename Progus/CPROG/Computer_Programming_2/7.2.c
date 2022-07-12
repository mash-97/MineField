#include <stdio.h>
#include <stdlib.h>

int main()
{
	int * marks;
	int i, n;
	int ar[5], *nn;
	printf("sizeof an ind: %ld, total: %ld\nsizeof *n : %ld\n", sizeof(ar[0]), sizeof(ar), sizeof(nn));
	printf("Size of marks before memory allocation %ld, address: %d\n", sizeof(marks), &marks);
	
	printf("Enter the number of students: ");
	scanf("%d", &n);
	
	marks = (int *) malloc(sizeof(marks)*n);
	
	printf("Size of marks after memory allocation %ld, address: %d\n", sizeof(marks), &marks);
	
	if(marks==NULL)
	{
		 printf("Memory allocation failed for marks!\n");
		 return 1;
	}
	
	printf("Enter the marks for each student: \n");
	for(i=0; i<n; i++) scanf("%d", &marks[i]);
	
	printf("Now here I can see the values:\n");
	for(i=0; i<n; i++) printf("%d\n", marks[i]);
	
	//now free the memory.
	free(marks);
	printf("Size of marks after memory free %ld, address: %d\n", sizeof(marks), &marks);
	return 0;
}
