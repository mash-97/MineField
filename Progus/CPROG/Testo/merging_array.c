#include <stdio.h>
#define swap(a,b) {int c=a; a=b; b=c;}

void push_injection(int * array, int l, int r)
{
	if(l+1 > r || array[l] < array[l+1])
	{
		return;
	}
	swap(array[l], array[l+1]);
	push_injection(array, ++l, r);
}

void merge(int * array, int l, int m, int r)
{
	if(l==r || l>r) return;
	if(l+1==m && m==r)
	{
		if(array[l] > array[m])
			swap(array[l], array[m]);
		return;
	}
	
	int rm = m+1;
	while(l<=m)
	{	
		if(array[l] > array[rm]) 
		{
			swap(array[l], array[rm]);
			push_injection(array, rm, r);
		}
		l++;
	}
}

void display_p(int *array, int l, int r)
{
	for(int i=l; i<=r; i++) printf("%d ", array[i]);
	puts("");
}

void merge_sort(int * array, int l, int r)
{
	if(l>=r) return;
	int mid = l + (r-l)/2;

	merge_sort(array, l, mid);
	merge_sort(array, mid+1, r);

	merge(array, l, mid, r);
	//display_p(array, l, r-1);
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
	for(int i=0; i<n; i++)
		scanf("%d", &array[i]);
	
	merge_sort(array, 0, n);
	display(array, n);
	
	return 0;
}


	
