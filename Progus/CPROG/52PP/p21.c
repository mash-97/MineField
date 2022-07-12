#include <stdio.h>
#include <string.h>
int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		char string[1002];
		scanf(" %[^\n]", string);
		int i;
		for(i=strlen(string)-1; i>=0; i--)printf("%c",string[i]);
		printf("\n");
	}
	return 0;
}
