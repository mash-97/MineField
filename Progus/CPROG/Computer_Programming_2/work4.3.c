#include <stdio.h>
#include <time.h>

//#define ARRAY_LENGTH 3
#define swap(a,b) {int c=a; a=b; b=c;}

//int array[ARRAY_LENGTH];
int total = 0;
void displayArray(int array[], int length)
{
	int i;
	for(i=0; i<length-1; i++) printf("%d ", array[i]);
	printf("%d\n", array[i]);
}

void displayState(int static_function_calls, int in_pos, int array_length, int function_array[])
{
	printf("Called Function No: %d\n", static_function_calls);
	printf("in_pos value: %d\n", in_pos);
	printf("Function array: ");
	displayArray(function_array, array_length);
	puts("");
}

void permute(int arg_array[], int in_pos, int array_length) // in_pos 0 base index, array_length is normal base.
{
	int funct_array[array_length], i;
	
	for(i=0; i<array_length; i++) funct_array[i] = arg_array[i];
	
	if(in_pos == array_length-1)
	{
		displayArray(funct_array, array_length); ++total;
		return;
	}
	
	for(i=in_pos; i<array_length; i++)
	{
		swap(funct_array[in_pos], funct_array[i]);
		permute(funct_array, in_pos+1, array_length);
	}
}

int main()
{
	total = 0;
	
	int length;
	printf(":: "); scanf("%d", &length);
	int array[length];
	
	for(int i = 0; i<length; i++) array[i] = i+1; 
//	printf("Initial Array: "); displayArray(array, length);
//	puts("");
	
	clock_t s = clock();
	permute(array, 0, length);
	clock_t e = clock();
	printf("Execution time for (n:%d): %.6f\n", length, (double)(e-s)/CLOCKS_PER_SEC);
	printf("\nTotal = %d\n", total);
	
	main();
	return 0;
}
