#include <stdio.h>
#include <string.h>


int main()
{
	char *name, *name1;
	
	printf("Enter string to duplicate: ");
	gets(name);
	
	if(name1 = name)
		printf("Duplicated string: %s\n", name1);
	else 
		printf("Error: there is an error!\n");
	
	return 0;
}
