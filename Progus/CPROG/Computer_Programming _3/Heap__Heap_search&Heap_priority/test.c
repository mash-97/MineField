#include <stdio.h>

void print_array(int *array)
{
	int array_size = (int) sizeof(array)/sizeof(int);
	printf("Total items in the array: %d\n", array_size);
	for(int i=0; i<array_size; i++)
		printf("%d ", array[i]);
	printf("\n");
}

int main()
{
	int a =10;
	int *pa = &a;
	--*pa;
	printf("%d\n", a);
	return  0;
}
