#include <stdio.h>
#include <string.h>
int main()
{
	char s[102];
	int T;
	int l;
	
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", s);
		l = strlen(s);
		for(int i=0; i<l; i++)printf("%d", (s[i]-'A')+1);
		printf("\n");
	}
	return 0;
}
