#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp = fopen("image1.jpg", "rb");
	if(fp==NULL){perror("Failed to open to the file 'image1.jpg':: "); return EXIT_FAILURE;}
	
	fseek(fp, 0, SEEK_END);
	printf("File size: %ld bytes\n", ftell(fp));
	printf("File size: %0.1lf kilo bytes\n", (ftell(fp)*1.0)/1024);
	
	fclose(fp);
	return 0;
}
