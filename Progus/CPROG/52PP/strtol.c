#include <stdio.h>
#include <stdlib.h>

int main()
{
    char line[]="11 -1 2 23 3 4";
    char *p, *e;
    long input;
    int count = 0;
    p = line;
    printf("1#p = %s, line = %s\n", p, line);
    
    for(p = line; ; p = e)
    {
		input = strtol(p, &e, 10);
		if(p == e)
		{
			break;
		}
		
		count++;
		printf("2#input = %ld, p =%s, e =%s\n", input, p, e);
	}
	printf("%d\n", count);
	
    return 0;

}
