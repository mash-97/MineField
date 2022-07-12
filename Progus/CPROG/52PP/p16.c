#include <stdio.h>
#include <string.h>

void printReverse(char string[])
{
	int i;
	for(i = strlen(string)-1; i>=0; i--)printf("%c", string[i]);
}

int main()
{
	int T, i, k, s_len;
	char s[1002], word[1002];
	
	scanf("%d", &T);
	while(T--)
	{
		scanf(" %[^\n]", s);
		s_len = strlen(s);
		for(i = 0, k = 0; i<s_len; i++)
		{
			if(s[i] != ' ')
			{
				word[k] = s[i];
				k++;
			}
			else if(k>0)
			{
				word[k] = '\0';
				printReverse(word);
				printf(" ");
				k = 0;
			}
		}
		if(k>0){word[k] = '\0'; printReverse(word); printf("\n");}
	}
	return 0;
}
