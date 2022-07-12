#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void clear(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}
void clrscr()
{
    system("@cls||clear");
}
int isbalanced(char input[])
{
	char last_character, stack[100];
	int len, top;
	
	len = strlen(input);
	top = 0;
	
	for(int i=0; i<len; i++)
	{
		if(input[i]=='(') stack[top++] = '(';
		else if(input[i]==')')
		{
			if(top==0) return 0;		//Stack empty.
			last_character = stack[--top];
			if(last_character!='(') return 0;
		}
	}
	
	if(top==0) return 1;
	return 0;
}

int main()
{
	char string[100];
	while(~scanf("%s", string))
	{
		clrscr();
		//clear();
		if(isbalanced(string)) printf("%s is balanced\n", string);
		else printf("%s is not balanced\n", string);
	}
	
	return 0;
}
