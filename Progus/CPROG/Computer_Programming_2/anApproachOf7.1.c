#include <stdio.h>

int main()
{
	int ** marks;
	int array[100];
	printf("Array size: %ld, loc %d\n", sizeof(array), &array);
	int i, n;
	printf("Enter n: ");
	scanf("%d", &n);
	for(i=0; i<n; i++) printf("array[%d] location %d\n", i, &array[i]);
	//for(i=0; i<n; i++) scanf("%d", &marks[i]);
	for(i=0; i<n; i++) array[i] = i+1;
	
	marks = &array;
	printf("marks loc %d\n", marks);
	printf("Values:\n");
	for(i=0; i<n; i++)
	printf("%d. %d\n", i+1, &(marks[i]));
	
	return 0;
}
