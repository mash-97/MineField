#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void clrscr()
{
	#if (defined(__linux__) || defined(__unix__) || defined(__APPLE__)) 
		system("clear");
	#endif
	#if (defined(_WIN32) || defined(_WIN64)) 
		system("cls");
	#endif
}

void clear()
{
	system("cls||clear");
}

int isbalanced(char input[])
{
	char last_character, stack[100], bc;
	int len, top;
	
	len = strlen(input);
	top = 0;
	
	for(int i=0; i<len; i++)
	{
		if(input[i]=='(' || input[i]=='{' || input[i]=='[') stack[top++] = input[i];
		else if(input[i]==')' || input[i]=='}' || input[i]==']')
		{
			if(top==0) return 0;		//Stack empty.
			if(input[i]==')') bc = '(';
			else if(input[i]=='}') bc = '{';
			else if(input[i]==']') bc = '[';
			
			last_character = stack[--top];
			if(last_character!= bc) return 0;
		}
	}
	
	if(top==0) return 1;
	return 0;
}

int main()
{
	char string[100];
	char *s;
	s = strstr("helloworld", "oo");
	if(s==NULL) printf("not found!\n");
	else printf("%s\n", s);
	while(~scanf("%s", string))
	{
		clear();
		if(isbalanced(string)) printf("%s is balanced\n", string);
		else printf("%s is not balanced\n", string);
	}
	
	return 0;
}


//](({()][[]}))[

