#include <stdio.h>
#include <string.h>

int countNumbers(char string[])
{
	int count=0, flag=1;
	int length = strlen(string);
	for(int i=0; i<length; i++)
	{
		if((string[i]>='0' && string[i]<='9'))
		{
            if(flag!=0)
            {
                flag=0;
                count++;
            }
		}
		else flag=1;


	}
	return count;
}


int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		char numbers[100000];
		scanf(" %[^\n]", numbers);
		printf("%d\n", countNumbers(numbers));
	}
	return 0;
}
