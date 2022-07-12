#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);
	
	while(T--)
	{
		char string[52];
		scanf("%s", string);
		for(int i=0; string[i]; i++)
		{
			if(string[i]=='L') string[i] = string[i-1];
			else if(string[i]=='R') string[i] = string[i+1];
		}
		
		printf("%s\n", string);
	}
	
	return 0;
}
