#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *marks[5], num[5];
	
	for(int i=0; i<5; i++)
	{
		printf("Enter total student of class %d: ", i+1);
		scanf("%d", &num[i]);
		marks[i] = (int *)malloc(sizeof(marks)*num[i]);
		
		printf("Enter marks for class %d:\n", i+1);
		for(int j=0; j<num[i]; j++) scanf("%d", &marks[i][j]);
	}
	
	printf("Marks from class 1 to 5: \n");
	for(int i=0; i<5; i++)
	{
		printf("Marks for class %d: ", i+1);
		for(int j=0; j<num[i]; j++) printf("%d ", marks[i][j]);
		puts("\n");
	}
	
	return 0;
}
