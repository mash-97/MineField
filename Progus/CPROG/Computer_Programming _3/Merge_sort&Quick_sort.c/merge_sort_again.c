#include <stdio.h>

#define SORT_CHECK <=
#define SWAP(a,b) {int c=a; a=b;b=c;}

void thurst(int A[], int start_index, int last_index)
{
	if(start_index >= last_index) return;

	if(A[start_index] >= A[start_index+1])	{SWAP(A[start_index], A[start_index+1]);}
	else return;

	thurst(A, start_index+1, last_index);
}

void merge_1(int A[], int left, int mid, int right)
{
	int l_index = left, r_index = mid+1;
	int thurst_lim = right;

	if(mid-left+1 < right-mid) 
	{
		SWAP(l_index, r_index);
		thurst_lim = mid;
	}

	while(l_index<=mid)
	{
		if(A[l_index] >= A[r_index]) 
		{
			SWAP(A[l_index], A[r_index]);
			thurst(A, r_index, thurst_lim);
		}
		l_index++;
	}

}

// Merge function to merge two parts of the array
// As they have to be sorted.
// left, mid and right are 0 based index.
void merge(int A[], int left, int mid, int right)
{
	int size_l = mid-left+1;
	int size_r = right-(mid+1)+1;					// As the second part starts from 
													// mid+1 to right.
	int L[size_l];	for(int i=0; i<size_l; i++) L[i] = A[left+i];
	int R[size_r]; 	for(int i=0; i<size_r; i++) R[i] = A[mid+i+1];
	
	for(int index_a = 0, index_l = 0, index_r = 0; index_l < size_l || index_r < size_r; index_a++)
	{
		if(index_l < size_l && index_r < size_r)
		{
			if(L[index_l] SORT_CHECK R[index_r]) A[left+index_a] = L[index_l++];
			else A[left+index_a] = R[index_r++];
		}
		else if(index_l < size_l) A[left+index_a] = L[index_l++];
		else if(index_r < size_r) A[left+index_a] = R[index_r++];
		else break;
	}
}


// Merge Sort function to sort an array A from left to right.
// left and right index are 0 based.
void merge_sort(int A[], int left, int right)
{
	// If A has 0 or one element then the array A is already sorted.
	// left > right means A has 0 element and
	// left == right means A has only one element.
	if(left >= right) return;
	
	// As merge sort is an divide and conquer algorithm.
	// So it will divide the array A into 2 parts.
	// That's why we have to know mid point of the array A from 
	// The left and right index (0 based).
	int mid = left+(right-left)/2;
	
	// Now we know the mid point of the array.
	// So the first part of the array is left to mid.
	// We have to apply merge sort on this part.
	merge_sort(A, left, mid);
	
	// Same to the second part.
	// Starts from mid+1 to right.
	merge_sort(A, mid+1, right);
	
	// Now we have merge these two sorted parts.
	merge_1(A, left, mid, right);
}

void disp(int *a, int l)
{
	for(int i=0; i<l; i++) printf("%d%c", a[i], " \n"[i==l-1]);
}

int main()
{
	int A[] = {9,6,5,1, 2, 5, 6, 9,8,4,3};
	
	printf("Before merge: "); disp(A, 11);
	merge_sort(A, 0, 10);
	printf("After Merge Sort: "); disp(A, 11);
	return 0;
}
