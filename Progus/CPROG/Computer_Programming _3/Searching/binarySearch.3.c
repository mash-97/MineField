#include <stdio.h>

int binarySearch(int A[], int n, int x)
{
	int l, r, m;
	
	l = 0;
	r = n-1;
	
	while(l <= r)
	{
		m = l + ((r-l)/2);
		
		if(A[m] == x) return m;
		else if(A[m] > x) r = m-1;
		else l = m+1;
	}
	
	return -1;
}

int binarySearchRec(int A[], int left, int right, int x)
{
	if(left>right) return -1;
	
	int mid = left+((right-left)/2);
	
	if(A[mid]==x) return mid;
	else if(A[mid] > x) right = mid-1;
	else left = mid+1;
	return binarySearchRec(A, left, right, x);
}
	
	
int main()
{
	printf("Enter n: ");
	int n; scanf("%d", &n);
	int A[n]; for(int i=0; i<n; A[i] = i+1, ++i);
	
	int x, pos;
	while(printf("Enter the number you want to search: ") && scanf("%d", &x) && x >= 0)
	{
		pos = binarySearchRec(A, 0, n-1, x);
		
		if(pos>=0) printf("The number %d is found at %d position.\n", x, pos);
		else printf("The number %d is not found!\n", x);
	}
	
	return 0;
}

