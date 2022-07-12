#include <stdio.h>

int main()
{
	FILE *fp;
	char filename[] = "my_file.txt";
	
	fp = fopen(filename, "r");
	fprintf(fp, "HELLO WORLD!\n");
	
	int r = fclose(fp);
	if(r==0)printf("The file was closed successfully.\n");
	else if(r==EOF)printf("The file wasn't closed successfully.\n");
	return 0;
}
