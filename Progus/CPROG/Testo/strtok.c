#include <stdio.h>
#include <string.h>
int main()
{
	char s[10000];
	printf("Enter your string: ");
	scanf(" %[^\n]", s);
	
	int count = 0;
	char *word;
	char deli[] = ",.;!? ";
	word = strtok(s,deli );
	printf("Words:\n%s\n", word);
	
	while(1)
	{
		if(strlen(word) > 0) count++;
		word = strtok(NULL, deli);
		if(word != NULL && count < 5) printf("%s\n", word);
		else break;
	}
	printf("total words: %d\n", count);
	return 0;
}



