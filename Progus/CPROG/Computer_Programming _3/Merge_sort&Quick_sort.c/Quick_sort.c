#include <stdio.h>
#define swap(a,b) {int c=a;a=b;b=c;}

int comparat(const void *a, const void *b)
{
	return *(int*)a-*(int*)b;
}

int partition(int A[], int low, int high, int (*comparator)(const void*, const void*))
{
	int i = low-1;
	int pivot = A[high];
	int comp;
	
	for(int j=low; j<high; j++)
	{
		comp = comparator(&A[j], &pivot);
		if(comp<0)
		{
			i++;
			swap(A[i], A[j]);
		}
	}
	i++;
	swap(A[i], A[high]);
	return i;
}


void qsort(int A[], int low, int high, int (*comparator)(const void *, const void*))
{
	if(low>=high) return;
	
	int partition_point = partition(A, low, high, comparator);
	qsort(A, low, partition_point-1, comparator);
	qsort(A, partition_point+1, high, comparator);
}

void disp(int *a, int l)
{
	for(int i=0; i<l; i++) printf("%d%c", a[i], " \n"[i==l-1]);
}

int main()
{
	int A[] = {1,5,6,3,8,4,7,2, 4};
	
	printf("Before qsort: "); disp(A, 9);
	qsort(A, 0, 8, comparat);
	printf("After qsort: "); disp(A, 9);
	
	return 0;
}
