#include <stdio.h>
#include <string.h>
/*
int countWords(char string[], int length)
{
	int total_words = 0;
	length = strlen(string);
	
	int flag = 0;
	for(int i=0; i<length; i++)
	{
		if((string[i]>='A' && string[i]<='Z') || (string[i]>='a' && string[i]<='z'))
		{
			if(flag==0)
			{
				flag=1; 
				++total_words;}
		}
		else{ flag=0;}
	}
	return total_words;
}
*/
long long unsigned int factorialOf(int number)
{
	long long unsigned int factorial = 1;
	for(int i=2; i<=number; i++)factorial*=i;
	return factorial;
}

int checkUniqueness(int k, char words[k][22], char word[])
{
	for(int i=0; i<k; i++)if(strcmp(words[i], word)==0) return 0;
	return 1;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--) 
	{
		char string[300];
		scanf(" %[^\n]", string);
		int length = strlen(string);
		string[length] = ' ';
		string[length+1] = 0;
		length++;
		//int total_words = countWords(string);
		char words[11][22];
		int k=0, m=0, flag = 0;
		char unique_words[11][22];
		int p=0;
		for(int i=0; i<length; i++)
		{
			if((string[i]>='A'&&string[i]<='Z') || (string[i]>='a'&&string[i]<='z'))
			{
				if(flag==0)flag=1;
				words[k][m] = string[i];
				++m;
			}
			else
			{
				if(flag==1)
				{
					words[k][m] = 0;
					if(checkUniqueness(k, words, words[k])==1)
					{
						strcpy(unique_words[p], words[k]);
						++p;
					}
					++k;
					m=0;
					flag = 0;
				}
			}
		}
		int uwteita[p];
		
		
		//finding total existence of each words in the string.
		for(int j=0; j<p; j++)
		{
			uwteita[j]=0;
			for(int y=0; y<k; y++)if(strcmp(unique_words[j], words[y])==0)++uwteita[j];
		}
		
		//test//
		//display all words
		printf("Displaying all words\n");
		for(int i = 0; i<k; i++)printf("#%d. %s\n", i+1, words[i]);
		printf("\n\nDisplaying all unique words\n");
		for(int i = 0; i<p; i++)printf("#%d. %s\n", i+1, unique_words[i]);
		printf("\n\nDisplaying all uwteita value\n");
		for(int i = 0; i<p; i++)printf("#%d. %d\n", i+1, uwteita[i]);
		printf("\n\n");
		
		int permutation = factorialOf(k);
		for(int j=0; j<p; j++)
		{
			permutation /= factorialOf(uwteita[j]);
		}
		printf("1/%d\n", permutation);
	}
	return 0;
}
