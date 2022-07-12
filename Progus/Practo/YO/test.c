#include <stdio.h>

void display(int length, int array[])
{
	printf("Inside display function: ");
	for(int i=0; i<length; i++)
		printf("%d ", array[i]);
	printf("\n");
}

int main()
{
	int length; 
	scanf("%d", &length);
	
	int a[length];
	for(int i=0; i<length; i++)
		scanf("%d", &a[i]);
	
	display(length, a);
	return 0;
	
	
	return 0;
}

