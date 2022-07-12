#include <stdio.h>
#include <stdbool.h>


bool v(int *array, int n, int x)
{
	int *left = array;
	int *right = array+n-1;
	
	while(left!=right)
	{
		printf("left: %d, right: %d\n", *left, *right);
		if(*left+*right==x) return 1;
		else if(*left+*right > x) right--;
		else left++;
	}
	return 0;
}

int main()
{
	int array[] = {1,2,2,3,4,9};
	printf("%d\n", v(array, 6, 7));
	return 0;
}
