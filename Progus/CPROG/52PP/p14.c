#include <stdio.h>
#include <string.h>
int main()
{
	int T; scanf("%d", &T);	
	while(T--)
	{
		char first_line[10001];	scanf(" %[^\n]", first_line);
		char second_line[2];	scanf("%s", second_line);
		int length = strlen(first_line);
		int i, occurence = 0;
		for(i=0; i<length; i++)if(first_line[i] == second_line[0]-'a'+'A' || first_line[i] == second_line[0] || first_line[i] == second_line[0]-'A'+'a')++occurence;
		if(occurence == 0)printf("'%c' is not present\n", second_line[0]);
		else printf("Occurrence of '%c' in '%s' = %d\n", second_line[0], first_line, occurence);
	}
	return 0;
}
		
