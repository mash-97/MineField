#include <stdio.h>

int a1[] = {1,2,3};
int a2[] = {4,5,6};
int a3[] = {7,8,9};

void copy(int *a, int *b, int length)
{
	for(int i=0; i<length; i++)
		a[i] = b[i];
}

void display(int *a, int length)
{
	for(int i=0; i<length; i++)
		printf("%d ", a[i]);
	puts("");
}

void array()
{
	static int i=1;
	int ar[3];
	
	if(i==1) copy(ar, a1, 3);
	else if(i==2) copy(ar, a2, 3);
	else if(i==3) copy(ar, a3, 3);
	else if(i==4)
	{i=0;return;}
	
	i++;
	array();
	printf("i: %d\n", i);
	display(ar, 3);
}

int main()
{
	int array[2] = {1,2};
	printf("&array: %p\n", &array);
	printf("array: %p\n", array);
	return 0;
}
