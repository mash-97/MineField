#include <stdio.h>
#include <stdlib.h>

int main()
{
	int **marks;
	int total_class, total_student;
	
	printf("Total classses: ");
	scanf("%d", &total_class);
	
	marks = (int **) malloc(sizeof(int *)*total_class);
	
	if(marks==NULL)
	{
		printf("Memory allocation failed!\n");
		return 1;
	}
	
	for(int i=0; i<total_class; i++)
	{
		printf("Total students for class %d: ", i+1);
		scanf("%d", &total_student);
		
		marks[i] = (int *) malloc(sizeof(int)*(total_student+1));
		if(marks[i]==NULL) 
		{
			printf("Memory allocation failed for marks[%d]!!\n", i);
			return 1;
		}
		
		marks[i][0] = total_student;
		
		printf("Marks for class %d:: ", i+1);
		for(int j=1; j<=marks[i][0]; j++) scanf("%d", &marks[i][j]);
	}
	
	puts("\n");
	puts("\n");
	printf("Showing all marks for all classes:\n");
	for(int i=0; i<total_class; i++)
	{
		printf("For class %d: ", i+1);
		for(int j=1; j<=marks[i][0]; j++) printf("%d ", marks[i][j]);
		puts("\n");
	}
	
	free(marks);
	return 0;
}
			
