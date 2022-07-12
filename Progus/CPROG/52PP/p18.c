#include <stdio.h>

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		char s[10001];
		scanf(" %[^\n]", s);
		int i;
		for(i=0; s[i]!= 0; i++)if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')printf("%c",s[i]);
		printf("\n");
		for(i=0; s[i]!= 0; i++)if(!(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') && s[i]!=' ')printf("%c", s[i]);
		printf("\n");
	}
	return 0;
}
