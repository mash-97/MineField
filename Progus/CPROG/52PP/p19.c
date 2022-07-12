#include <stdio.h>
int main()
{
	int T; 
	scanf("%d", &T);
	while(T--)
	{
		char s[10001];
		scanf(" %[^\n]", s);
		int count = 0;
		int i;
		for(i=0; s[i]!=0; i++)if(s[i]==' ')++count;
		printf("Count = %d\n", ++count);
	}
	return 0;
}
		
