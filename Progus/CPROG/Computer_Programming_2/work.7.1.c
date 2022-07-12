#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char name[16];
	int age;
} Person;

int compareFuncByAge(const void *a, const void *b)
{
	int a_age = (*(Person *)a).age;
	int b_age = (*(Person *)b).age;
	
	if(a_age > b_age) return 1;
	return 0;
}


int compareFuncByName(const void *a, const void *b)
{
	return strcmp((*(Person *)a).name, (*(Person *)b).name);
}

int main()
{
	int total_person;
	printf("Number of total person: ");
	scanf("%d", &total_person);
	Person persons[total_person];
	
	printf("Enter name and age for %d peoples: \n\n", total_person);
	for(int i=0; i<total_person; i++)
	{
		printf("%d::\n", i+1);
		printf("Name: ");
		scanf("%s", persons[i].name);
		printf("Age: ");
		scanf("%d", &persons[i].age);
		puts("\n");
	}
	
	qsort(&persons, total_person, sizeof(Person), &compareFuncByAge);
	
	printf("Showing persons by age (ascending): \n");
	for(int i=0; i<total_person; i++)
	{
		printf("%d::\n", i+1);
		printf("    Name: %s\n", persons[i].name);
		printf("    Age: %d\n", persons[i].age);
	}
	
	char name[16];
	char *np;
	int ag;
	int *a;
	again:
	printf("\n\n");
	printf("Enter a age you want to search: ");
	//scanf("%s", name);
	scanf("%d", &ag);
	a = (int *) bsearch(&ag, &persons, total_person, sizeof(Person), &compareFuncByAge);
	
	if(a != NULL) printf("The age %d is found in the persons list\n", *a);
	else printf("The age %d isn't found in the list!!\n", *a);
	
	if(getchar()!='n') goto again;
	
	return 0;
}
		
