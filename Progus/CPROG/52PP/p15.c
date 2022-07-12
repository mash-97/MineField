#include <stdio.h>
#include <string.h>
int main()
{
	int t; scanf("%d", &t);
	while(t--)
	{
		char string[1001];
		scanf(" %[^\n]", string);
		int length = strlen(string);
		int i, count[26];
		for(i = 0; i<26; i++) count[i]=0;
		for(i = 0; i<length; i++) if(string[i] >= 'a' && string[i] <= 'z')++count[string[i]-'a'];
		for(i = 0; i<26; i++) if(count[i]!=0)printf("%c = %d\n", 'a'+i, count[i]);
	}
	return 0;
}
		
