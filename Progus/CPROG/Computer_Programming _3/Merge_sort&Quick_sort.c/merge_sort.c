#include <stdio.h>

void merge(int * A, int left, int mid, int right)
{
	int index_a, index_l, index_r;
	int size_l, size_r;
	
	size_l = mid-left+1;
	size_r = right-mid;
	
	int L[size_l], R[size_r];
	
	for(int i=0; i<size_l; i++)
		L[i] = A[left+i];
	for(int i=0; i<size_r; i++)
		R[i] = A[mid+i+1];
	
	index_l = 0;
	index_r = 0;
	index_a = 0;
	
	while( index_l < size_l && index_r < size_r)
	if(L[index_l] > R[index_r])
		A[left+index_a++] = R[index_r++];
	else
		A[left+index_a++] = L[index_l++];
	
	while(index_l<size_l) A[left+index_a++] = L[index_l++];
	while(index_r<size_r) A[left+index_a++] = R[index_r++];
}


void merge_sort(int * array, int left, int right)
{
	if(left>=right) return;
	int mid = left+(right-left)/2;
	
	merge_sort(array, left, mid);
	merge_sort(array, mid+1, right);
	
	merge(array, left, mid, right);
}


void display(int *a, int length)
{
	for(int i=0; i<length; i++)
		printf("%d ", a[i]);
	puts("");
}

int main()
{
	int n;
	scanf("%d", &n);
	int array[n];
	for(int i=0; i<n; i++) scanf("%d", &array[i]);
	
	merge_sort(array, 0, n);
	display(array, n);
	
	return 0;
}
	
