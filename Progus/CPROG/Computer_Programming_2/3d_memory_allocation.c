
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int ***marks;
	int total_school, total_class, total_student;
	
	printf("Total schools: ");
	scanf("%d", &total_school);
	
	marks = (int ***) malloc(sizeof(int *)*total_school);
	
	if(marks==NULL)
	{
		printf("Memory allocation failed!\n");
		return 1;
	}
	
	for(int i=0; i<total_school; i++)
	{
		printf("    %d. Total class: ", i+1);
		scanf("%d", &total_class);
		
		marks[i] = (int **) malloc(sizeof(int*)*(total_class+1));
		if(marks[i]==NULL) 
		{
			printf("Memory allocation failed!!\n");
			return 1;
		}
		
		marks[i][0] = (int *) malloc(sizeof(int));
		marks[i][0][0] = total_class;
		//printf("Enter number of students for every class for school %d:\n", i+1);
		
		for(int j=1; j<=total_class; j++)
		{
			printf("        %d. Total students: ", j);
			scanf("%d", &total_student);
			
			marks[i][j] = (int *) malloc(sizeof(int)*(total_student+1));
			if(marks[i][j]==NULL)
			{
				printf("Memory allocation failed!!!\n");
				return 1;
			}
			
			marks[i][j][0] = total_student;
			
			printf("            Marks %d: ", total_student);
			for(int k=1; k<=total_student; k++) scanf("%d", &marks[i][j][k]);
		}
			
	}
	
	puts("\n");
	puts("\n");
	printf("Showing all marks for all classes from all schools:\n");
	for(int i=0; i<total_school; i++)
	{
		printf("School %d\n", i+1);
		for(int j=1; j<=marks[i][0][0]; j++)
		{
			printf("    Class %d: ", j);
			for(int k=1; k<=marks[i][j][0]; k++)	printf("%d ", marks[i][j][k]);
		}
	}
	
	free(marks);
	return 0;
}
			
