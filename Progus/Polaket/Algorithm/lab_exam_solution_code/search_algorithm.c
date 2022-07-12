#include <stdio.h>


//** WITH FREEWORLD's LICENCE
/* \
 *  \
 * 	YO whazzup dude!
 * /
 */
  // Remember: The original writer isn't responsible for any inconvenience
int linear_search(int number, int array_length, int array[array_length])
{
	for(int i=0; i<array_length; i++)
		if(array[i] == number)
			return i;				
	
	return -1;	// number is not found in the array
}

int binary_search(int number, int array_length, int array[array_length])
{
	int left = 0;
	int mid;
	int right = array_length-1;

	while(left<=right)
	{
		mid = (left+right)/2;
		if(array[mid] == number)
			return mid;
		else if(array[mid] > number)
			right = mid-1;
		else
			left = mid+1;
	}
	return -1;	// number is not found in the array
}

int main()
{
	int array_length;
	printf("Number of numbers: ");
	scanf("%d", &array_length);
	
	int array[array_length];
	printf("Enter %d numbers: ", array_length);
	for(int i=0; i<array_length; i++) 
		scanf("%d", &array[i]);
	
	int number, result;
	printf("Number that you want to search: ");
	scanf("%d", &number);
	
	result = binary_search(number, array_length, array);
	if(result == -1) 
		printf("%d is not found in the array\n", number);
	else
		printf("%d is found at the %d index in the array\n", number, result);
	
	return 0;
}
			
			
