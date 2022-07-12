#include <stdio.h>
#include <stdlib.h>
#define li long int

int main(int total_argument, char *argument_vectors[])
{
	li sum=0;
	for(int i=1; i<total_argument; i++) sum+=atol(argument_vectors[i]);
	
	printf("Program name: %s\n\n", argument_vectors[0]);
	printf("The sum is %ld\n", sum);
	return 0;
	
}
