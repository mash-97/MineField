#include <stdio.h>
#include <string.h>
int main()
{
	typedef struct student 
	{
		int id;
		char name[40];
	}o;
	
	//struct s one;
	o one;
	one.id = 1;
	strcpy(one.name, "Tahmid Rafi");
	
	printf("ID: %d\n", one.id);
	printf("Name: %s\n", one.name);
	
	return 0;
}
