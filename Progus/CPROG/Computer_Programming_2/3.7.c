#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp = fopen("in.txt", "r");
	if(fp==NULL)
	{
		perror("Can't open file: ");
		return EXIT_FAILURE;
	}
	
	int ch;
	
	ch = fgetc(fp);
	printf("%c\n", (char)ch);
	ch = fgetc(fp);
	printf("%c\n", (char)ch);
	fseeko(fp, sizeof(char)*0, SEEK_END);
	//fseek(fp, 1, SEEK_END);
	ch = fgetc(fp);
	printf("%c\n", (char)ch);
	
	fclose(fp);
	
	return 0;
}
