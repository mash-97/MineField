#include <stdio.h>
#include <string.h>

int countWordsType_2(char string[])
{
	char *word;
	int count = 0;
	word = strtok(string, ", ! ; ? . ");
	while(word != NULL)
	{
		if(strlen(word) > 0)++count;
		word = strtok(NULL, ",!;?. ");
	}
	
	return count;
}
