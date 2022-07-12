#include <stdio.h>
#include <string.h>

typedef struct
{
	char first[20];
	char last[20];
} Nametype;

typedef struct
{
	int day;
	int month;
	int year;
} Datetype;

typedef struct
{
	Nametype name;
	Nametype name_of_father;
	Nametype name_of_mother;
	Datetype date_of_birth;
	char ID_no[20];
} NationalID;

int main()
{
	NationalID resident;
	
	printf("Enter Resident's First Name: ");
	scanf("%s", resident.name.first);
	printf("Enter Resident's Last Name: ");
	scanf("%s", resident.name.last);
	
	printf("Enter Resident's First Name of Father: ");
	scanf("%s", resident.name_of_father.first);
	printf("Enter Resident's Last Name of Father: ");
	scanf("%s", resident.name_of_father.last);
	
	printf("Enter Resident's First Name of Mother: ");
	scanf("%s", resident.name_of_mother.first);
	printf("Enter Resident's Last Name of Mother: ");
	scanf("%s", resident.name_of_mother.last);
	
	printf("Enter Resident's Date of Birth(dd/mm/yy): ");
	scanf("%d/%d/%d", &resident.date_of_birth.day, &resident.date_of_birth.month, &resident.date_of_birth.year);
	
	printf("Enter Resident's ID no: ");
	scanf("%s", resident.ID_no);
	
	puts("");
	printf("Output:\n");
	printf("				National ID		\n\n");
	printf("Name: %s %s\n", resident.name.first, resident.name.last);
	printf("Father's Name: %s %s\n", resident.name_of_father.first, resident.name_of_father.last);
	printf("Mother's Name: %s %s\n", resident.name_of_mother.first, resident.name_of_mother.last);
	printf("Date of Birth: %2d/%2d/%4d\n", resident.date_of_birth.day, resident.date_of_birth.month, resident.date_of_birth.year);
	printf("National ID no: %s\n", resident.ID_no);
	
	return 0;
}
