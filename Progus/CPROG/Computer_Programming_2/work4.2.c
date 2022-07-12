#include <stdio.h>
#include <string.h>

char string[100];
int cycles;

void befS()
{
	--cycles;
	printf("%c", string[cycles]);
	if(cycles==0) return;
	else befS();
}

int main()
{
	printf("Enter a string: ");
	scanf(" %[^\n]", string);
	cycles = strlen(string);
	befS();
	puts("");
	main();
}
