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

void calculateGrade(Studenttype * s, int mark)
{
	if(mark >= 80) strcpy(s->grade, "A+");
	else if(mark >= 70) strcpy(s->grade, "A");
	else if(mark >= 60) strcpy(s->grade, "A-");
	else if(mark >= 50) strcpy(s->grade, "B");
	else if(mark >= 40) strcpy(s->grade, "C");
	else strcpy(s->grade, "F");
}

int main()
{
	Studenttype student[5];
	int i, n=5;
	int marks[] = {72, 82, 60, 20, 50};
	
	for(i=0; i<n; i++)
	{
		printf("Enter the ID for student %d: ", i+1);
		scanf("%d", &student[i].id);
		printf("Enter the first name for student %d: ", i+1);
		scanf("%s", student[i].name.first);
		printf("Enter the last name for student %d: ", i+1);
		scanf("%s", student[i].name.last);
		strcpy(student[i].grade, "");
		printf("\n");
	}
	
	for(i=0; i<n; i++) calculateGrade(&student[i], marks[i]);
	
	printf("Output:\n\n");
	for(i=0; i<n; i++)
	{
		printf("ID: %d\n", student[i].id);
		printf("Name: %s %s\n", student[i].name.first, student[i].name.last);
		printf("Grade: %s\n", student[i].grade);
	}
	
	return 0;
}
