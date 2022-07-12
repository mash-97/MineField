#include <stdio.h>
#include <string.h>

int countWordsType_1(char string[])
{
	int flag = 0, count = 0;
	int i;
	for(i = 0; string[i] != 0; i++)
	{
		if((string[i]>='a' && string[i]<='z') || (string[i]>='A' && string[i]<='Z') || !(string[i]==' ' || string[i]==',' || string[i]=='!' || string[i]==';' || string[i]=='?' || string[i]=='.')){if(flag==0){flag=1; ++count;}}
		else if(flag==1)flag=0;
	}
	return count;
}

int countWordsType_2(char string[])
{
	char *word;
	int count = 0;
	word = strtok(string, ", ! ; ? . ");
	while(word != NULL)
	{
		if(strlen(word) > 0)++count;
		word = strtok(NULL, ",!;?. ");
	}
	
	return count;
}

int main()
{
	int T; 
	scanf("%d", &T);
	while(T--)
	{
		char string[10001];
		scanf(" %[^\n]", string);
		printf("Count = %d\n", countWordsType_2(string));
	}
	return 0;
}
