#include <stdio.h>
#include <string.h>

void sortA(int length, char strings[length][10001])
{
	int i, j;
	char temp[10001];
	for(i=0; i<length; i++)
	for(j=i; j<length; j++)
	{
		if(strcmp(strings[i], strings[j]) > 0)
		{
			strcpy(temp, strings[i]);
			strcpy(strings[i], strings[j]);
			strcpy(strings[j], temp);
		}
	}
}

int main()
{
	int T, N, i;
	char strings[21][10001];
	
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		for(i=0; i<N; i++)scanf("%s", strings[i]);
		puts("");
		sortA(N, strings);
		for(i=0; i<N; i++)printf("%s\n", strings[i]);
		puts("");
	}
	return 0;
}
