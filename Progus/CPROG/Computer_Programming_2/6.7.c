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

Studenttype student[3];

void calculateGrade(int i, int mark)
{
	if(mark >= 80) strcpy(student[i].grade, "A+");
	else if(mark >=70) strcpy(student[i].grade, "A");
	else if(mark >=60) strcpy(student[i].grade, "A-");
	else if(mark >=50) strcpy(student[i].grade, "B");
	else if(mark >=40) strcpy(student[i].grade, "C");
	else strcpy(student[i].grade, "F");
}

void scanDetails(int i, int mark)
{
	printf("Enter the ID for student %d: ", i+1);
	scanf("%d", &student[i].id);
	printf("Enter the first name for student %d: ", i+1);
	scanf("%s", student[i].name.first);
	printf("Enter the last name for student %d: ", i+1);
	scanf("%s", student[i].name.last);
	calculateGrade(i, mark);
	printf("\n");
}

void displayDetails(int i)
{
	printf("ID: %d\n", student[i].id);
	printf("Name: %s %s\n", student[i].name.first, student[i].name.last);
	printf("Grade: %s\n", student[i].grade);
}

int main()
{
	int i, n = 3;
	int marks[] = {72, 82, 60};
	
	for(i = 0; i<n; i++) scanDetails(i, marks[i]);
	
	printf("Output: \n\n");
	
	for(i = 0; i<n; i++) displayDetails(i);
	
	return 0;
}
