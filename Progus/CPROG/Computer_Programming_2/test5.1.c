#include <stdio.h>


int main()
{

	for(int i=91; i<=96; i++)printf("%d:: %c\n", i, i);
	printf("\n\n...........................\n\n");
	for(int i=65, j=91; i<=90; i++, j++)printf("%d\t\t", j-i);


	return 0;
}
