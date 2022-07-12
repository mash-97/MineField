#include <stdio.h>
#include <string.h>

int main()
{
	int T;
	scanf("%d", &T);
	
	while(T--)
	{
		char string1[1001], string2[1001];
		scanf("%s%s", string1, string2);
		int l1 = strlen(string1), l2 = strlen(string2);
		
		int i, j, count = 0;
		for(i=0; i<(l1-l2)+1; i++)
		{
			j = -5;
			if(string2[0]==string1[i])
			{
				for(j=1; j<l2; j++)	if(string2[j] != string1[i+j]) break;
			}
			if(j==l2)
			{
				printf("%d\n", i);
				++count;
			}
		}
		printf("total = %d\n", count);
	}
	return 0;
}
