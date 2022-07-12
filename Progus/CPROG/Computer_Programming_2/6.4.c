#include <stdio.h>

struct student 
{
	int id;
	char name[40];
};

int main()
{
	struct student one;
	
	scanf("%d %[^\n]", &one.id, one.name);
	//scanf("%d", &one.id);
	//scanf("%s", one.name);
	
	printf("ID: %d\n", one.id);
	printf("Name: %s\n", one.name);
	
	return 0;
}
