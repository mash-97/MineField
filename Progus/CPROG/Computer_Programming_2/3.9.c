#include <stdio.h>

int main()
{
	int return_value;
	char *file_name = "in.txt";
	
	return_value = remove(file_name);
	if(return_value!=0){perror("File Remove Failed:: "); return 1;}
	printf("The File '%s' Removed Successfully.\n", file_name);
	
	//now try to remove again.
	return_value = remove(file_name);
	if(return_value!=0){perror("File Remove Failed:: "); return 1;}
	printf("The File '%s' Removed Successfully.\n", file_name);
	
	return 0;
}
