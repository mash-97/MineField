#include <stdio.h>

int binary_search(int num, int n, int A[])
{
	int left = 0;
	int right = n-1;
	int mid;
	
	while(left<=right)
	{
		mid = (right+left)/2;
		if(A[mid]==num) return mid;
		else if(A[mid] > num)
			right = mid-1;
		else 
			left = mid+1;
	}
	return -1;
}

int main()
{
	int n, i;
	printf("Enter number of elements in array\n");
	scanf("%d", &n);
	printf("Enter %d integer(s)\n", n);
	int array[n];
	for(i=0; i<n; i++)
		scanf("%d", &array[i]);
	
	printf("Enter 3 numbers that you want to search\n");
	int sarray[3];
	int sum = 0, result_i;
	for(i=0; i<3; i++)
		scanf("%d", &sarray[i]);
	
	for(i=0; i<3; i++)
	{
		result_i = binary_search(sarray[i], n, array);
		if(result_i<0) 
		{
			printf("Your searched element is not present in the array");
			break;
		}
		else
		{
			printf("%d is present at location %d.\n", sarray[i], result_i+1);
			sum += result_i+1;
		}
	}
	
	if(result_i==-1) return 0;
	printf("The sum of all location is %d\n", sum);
	return 0;
}
		
