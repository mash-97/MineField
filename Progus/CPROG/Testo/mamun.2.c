#include <stdio.h>


int main()
{
	int number_of_year;
	scanf("%d", &number_of_year);
	
	int seconds = number_of_year * 365 * 24 * 60 * 60;
	printf("%d\n", seconds);
	
	return 0;
}
