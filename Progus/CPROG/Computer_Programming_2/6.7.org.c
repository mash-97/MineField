
#include <stdio.h>
#include <string.h>

typedef struct 
{
	char first[20];
	char last[20];
} Nametype;

typedef struct
{
	int id;
	Nametype name;
	char grade[3];
} Studenttype;

void calculateGrade(Studenttype student, int mark)
{
	if(mark >= 80) strcpy(student.grade, "A+");
	else if(mark >=70) strcpy(student.grade, "A");
	else if(mark >=60) strcpy(student.grade, "A-");
	else if(mark >=50) strcpy(student.grade, "B");
	else if(mark >=40) strcpy(student.grade, "C");
	else strcpy(student.grade, "F");
}

int main()
{
	Studenttype student[3];
	int i, n=3;
	int marks[] = {72, 80, 60};
	
	for(i = 0; i<n; i++)
	{
		printf("Enter the ID for student %d: ", i+1);
		scanf("%d", &student[i].id);
		printf("Enter the first name for student %d: ", i+1);
		scanf("%s", student[i].name.first);
		printf("Enter the last name for student %d: ", i+1);
		scanf("%s", student[i].name.last);
		
		calculateGrade(student[i], marks[i]);
		printf("\n");
	}
	
	printf("Output:\n\n");
	
	for(i = 0; i<n; i++)
	{
		printf("ID: %d\n", student[i].id);
		printf("Name: %s %s\n", student[i].name.first, student[i].name.last);
		printf("Grade: %s\n", student[i].grade);
	}

	return 0;
}
