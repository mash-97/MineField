#include <stdio.h>
#define swap(a,b) {int c=a; a=b; b=c;}


void permute(int arg_array[], int in_pos, int array_length) 
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
