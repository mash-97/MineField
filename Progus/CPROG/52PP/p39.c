#include <stdio.h>
#include <string.h>

int isPalindrome(char string[])
{
	int j = strlen(string)-1;
	int i=0;
	while(i!=j)
	{
		if(string[i]!=string[j])return 0;
		i++;
		j--;
	}
	return 1;
}

int main()
{
	int T;
	char string[1001];
	
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", string);
		if(isPalindrome(string)==1)printf("Yes! It is Palindrome!\n");
		else printf("Sorry! It is not Palindrome\n");
	}
	return 0;
}
