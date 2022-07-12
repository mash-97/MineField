#include <stdio.h>
#include <string.h>

int main()
{
	char s[100];
	scanf(" %[^\n]", s);
	
	int count = 0 ,sp =0, fst = 0;
	for( int i=0; i<strlen(s); i++ ){
			if( s[i]==' ' )sp++;
			else if( s[i]=='.' ) fst++;
		
		
	}
	char *f = strtok(s, " , .");
	
	while(f != NULL)
	{
		if(strlen(f)>0)
		count++;
		puts(f);
		f = strtok(NULL, " , .");
	}
	
	
	printf("Word: %d\n", count);
	printf("Full Stop: %d\n", fst);
	printf("Full Space: %d\n", sp);
	return 0;
}
