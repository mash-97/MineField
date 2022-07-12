#include <stdio.h>
#include <string.h>
int main()
{
	char string[10002];
	char string_1[2003];
	scanf(" %[^\n] %[^\n]", string, string_1);
	char *word, *p;
	word = strtok(string, ", !;?. ");
	p = strtok(string_1, ", !;?. ");
	word = strtok(string_1, ", !;?. ");
	pa = strtok(string, ", !;?. ");
	printf("$p = %s\n", p);
	printf("$word = %s\n", word);
	int count = 0;
	while(word != NULL)
	{
		if(strlen(word) > 0) ++count;
		p = strtok(string, ", ! ; ? .  *& %~!@#$%^&*()_+[]{}||\\:'//?.>,<");
		word = strtok(NULL, ", ! ; ? .  *& %~!@#$%^&*()_+[]{}||\\:'//?.>,<");
		
		printf("#word = %s\n", word);
		printf("#p = %s\n", p);
	}
	printf("%d\n", count);
	printf(".............\n");
	main();
	return 0;
}
