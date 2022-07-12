#include <stdio.h>
#include <stdlib.h>

int countPiecesOfAString(char string[])
{
	char *p, *e;
	int count = 0;

	for(p = string;; p = e)
	{
		strtol(p, &e, 10);
		if(p==e)break;
		count++;
	}
	return count;
}

int main()
{
    char line[100000];
    int T; scanf("%d", &T);
    while(T--)
    {
		scanf(" %[^\n]", line);
		printf("%d\n", countPiecesOfAString(line));
	}
    return 0;
}
