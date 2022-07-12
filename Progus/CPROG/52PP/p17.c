#include <stdio.h>
#include <string.h>
int main()
{
	int t, total_vowels, i, length;	
	char string[1002];
	
	scanf("%d", &t);
	while(t--)
	{
		scanf(" %[^\n]", string);
		total_vowels = 0;
		length = strlen(string);
		for(i = 0; i<length; i++)if(string[i]=='a' || string[i]=='e' || string[i]=='i' || string[i]=='o' || string[i]=='u')++total_vowels;
		printf("Number of vowels = %d\n", total_vowels);
	}
	return 0;
}
