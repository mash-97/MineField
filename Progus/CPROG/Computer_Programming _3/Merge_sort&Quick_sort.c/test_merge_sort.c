#include <stdio.h>

void merge(int *array, int left, int mid, int right);
void merge_sort(int *array, int left, int right);

void display(int *array, int length)
{
	for(int i=0; i<length; i++) printf("%d ", array[i]);
	puts("");
}


int main()
{
	int n;
	scanf("%d", &n);
	int array[n];
	for(int i=0; i<n; i++) scanf("%d", &array[i]);
	
	merge_sort(array, 0, n-1);
	
	display(array, n);
	return 0;
}


void merge(int * A, int left, int mid, int right)
{
	int index_a, index_l, index_r;
	int size_l = (mid-left)+1; int L[size_l];
	int size_r = (right-mid); int R[size_r];
	
	int i;
	
	for(i=0; i<size_l; i++) L[i] = A[left+i];
	for(i=0; i<size_r; i++) R[i] = A[mid+1+i];
	
	index_a = index_l = index_r = 0;
	
	while(index_l < size_l && index_r < size_r)
	{
		if(L[index_l] < R[index_r]) A[left+index_a++] = L[index_l++];
		else A[left+index_a++] = R[index_r++];
	}
	
	while(index_l < size_l)
		A[left+index_a++] = L[index_l++];
	while(index_r < size_r)
		A[left+index_a++] = R[index_r++];
}


void merge_sort(int *array, int left, int right)
{
	if(left>=right) return;
	
	int mid = left+((right-left)/2);
	
	// calling merge_sort for left..mid
	merge_sort(array, left, mid);
	
	// calling merge_sort for mid+1..right
	merge_sort(array, mid+1, right);
	
	// merging array parts from left..mid..right
	merge(array, left, mid, right);
}
