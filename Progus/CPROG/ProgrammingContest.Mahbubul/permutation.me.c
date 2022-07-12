#include <stdio.h>
#define swap(a,b) {int c=a; a=b; b=c;}

void display(int *array, int length)
{
	for(int i=0; i<length; i++) printf("%d ", array[i]);
	puts("");
}

void permute(int *arg_array, int length, int at)
{
	int funct_array[length];	for(int i=0; i<length; i++) funct_array[i] = arg_array[i];
	
	if(at==length-1) 
	{
		display(funct_array, length);
		return;
	}
	
	for(int i=at; i<length; i++)
	{
		//printf("at = %d\n", at);
		//printf("funct_array: "); display(funct_array, length);
		//printf("\tfunct_array[%d] = %d, funct_array[%d] = %d\n", at, funct_array[at], i, funct_array[i]);
		swap(funct_array[at], funct_array[i]);
		//printf("\t\tfunct_array[%d] = %d, funct_array[%d] = %d\n", at, funct_array[at], i, funct_array[i]);
		permute(funct_array, length, at+1);
	}
}

int main()
{
	int n;
	printf("n:: "); scanf("%d", &n);
	int array[n];   for(int i=0; i<n; i++) array[i] = i+1;
	printf("Displaying Permutation of 1..%d:\n", n);
	permute(array, n, 0);
	
	main();
}
