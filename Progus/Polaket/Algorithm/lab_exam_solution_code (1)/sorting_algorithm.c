#include <stdio.h>

//** WITH FREEWORLD's LICENCE
/* \
 *  \
 * 	YO whazzup dude!
 * /
 */
  // Remember: The original writer isn't responsible for any inconvenience
void display_array(int length,  int array[])
{
	for(int i=0; i<length; i++)
		printf("%d ", array[i]);
	printf("\n");
}

void insertion_sort(int array_length, int array[array_length])
{
	int i, j, key;
	for(i=1; i<array_length; i++)
	{
		key = array[i];
		j = i-1;
		while(j>=0 && array[j]>key)
		{
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = key;
	}
}


// Function for merging array sortingly.
void merge(int A[], int left, int mid, int right)
{
	int left_length = mid-left+1;
	int left_array[left_length];
	for(int i=0; i<left_length; i++)
		left_array[i] = A[left+i];
		
		
	int right_length = right-mid;
	int right_array[right_length];
	for(int i=0; i<right_length; i++)
		right_array[i] = A[mid+1+i];

	int left_index = 0;
	int right_index = 0;
	int main_index = left;
	
	while(left_index<left_length && right_index<right_length)
	{
		if(left_array[left_index] <= right_array[right_index])
		{
			A[main_index] = left_array[left_index];
			left_index++;
		}
		else
		{
			A[main_index] = right_array[right_index];
			right_index++;
		}
		main_index++;
	}
	
	// If any of the left or right array is still not taken
	while(left_index<left_length)
		A[main_index++] = left_array[left_index++];
		
	while(right_index<right_length)
		A[main_index++] = right_array[right_index++];

}

void merge_sort(int left, int right, int A[])
{
	if(left>=right) return;					// Array's length is 1 or 0. already sorted.
	
	int mid = left+(right-left)/2;
	
	merge_sort(left, mid, A);				// sort the left array
	
	merge_sort(mid+1, right, A);			// sort the right array
	
	merge(A, left, mid, right);				// merging the two arrays
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
		
	merge_sort(0, array_length-1, array);
	
	display_array(array_length, array);
	puts("");
	
	return 0;
}
