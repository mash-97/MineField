#include <iostream>
#include <stdio.h>

using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
int parent(int i)
{
	return i/2;
}
int left(int i)
{
	return i*2;
}
int right(int i)
{
	return i*2+1;
}

void maxHeapify(int i, int length, int array[], int compare_mode)
{
	int max_index = i;
	
	max_index = ((left(i)<=length) && (array[left(i)] > array[i])==compare_mode) ? left(i) : max_index;
	max_index = ((right(i)<=length) && (array[right(i)] > array[max_index])==compare_mode)  ?  right(i) : max_index;
	
	if(max_index==i) return;
	swap(array[i], array[max_index]);
	maxHeapify(max_index, length, array, compare_mode);
}

void max_heapify(int index, int heap_size, int *array)
{
	int l, r, largest = index;
	l = left(index);
	r = right(index);
	
	if(l<=heap_size && array[l]>array[largest])	
		largest = l;
	
	if(r<=heap_size && array[r]>array[largest])
		largest = r;
	
	if(largest != index)
	{
		swap(array[largest], array[index]);
		max_heapify(largest, heap_size, array);
	}
}

void buildHeap(int length, int array[], void (*max_h)(int , int , int *, int), int compare_mode=1)
{
	for(int i=length/2; i>=1; i--)
		max_h(i, length, array, compare_mode);
}

bool isMaxHeap(int length, int array[])
{
	for(int i=length; i>1; i--)
		if(array[parent(i)] < array[i]) return false;
	return true;
}

bool isHeapByCompareMode(int length, int *array, int compare_mode)
{
	for(int i=length; i>1; i--)
		if((array[parent(i)] <= array[i]) == compare_mode) return false;
	return true;
}

void heap_sort(int length, int array[], void (*max_h)(int , int , int *))
{
	for(int i=length; i>1; i--)
	{
		swap(array[1], array[i]);
		length -= 1;
		max_h(1, length, array);
	}
}

bool match(int length, int *array, int *barray)
{
	for(int i=1; i<=length; i++)
		if(array[i] != barray[i])
			return false;
	return true;
}

void disp(int length, int *array)
{
	for(int i=1; i<=length; i++)
		printf("%d ", array[i]);
	puts("");
}

int top(int heap_size, int *heap)
{
	if(heap_size<=0) return -(int)__builtin_inf();
	return heap[1];
}

int extract(int &heap_size, int *heap, int compare_mode)
{
	if(heap_size<=0) return -(int)__builtin_inf();
	swap(heap[1], heap[heap_size]);
	heap_size -= 1;
	maxHeapify(1, heap_size, heap, compare_mode);
	return heap[heap_size+1];
}

void insert(int &heap_size, int *heap, int new_data, int compare_mode)
{
	heap_size += 1;
	heap[heap_size] = new_data;
	int i = heap_size;
	while(parent(i)>=1 && (heap[parent(i)]<heap[i])==compare_mode)
	{
		swap(heap[parent(i)], heap[i]);
		i = parent(i);
	}
}

void increaseKey(int *heap, int i, int new_value, int compare_mode)
{
	heap[i] = new_value;
	
	while(parent(i)>=1 && (heap[parent(i)]<heap[i])==compare_mode)
	{
		swap(heap[parent(i)], heap[i]);
		i = parent(i);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int array[n+5];
	//int barray[n+1];
	for(int i=1; i<=n; i++) 
	{
		scanf("%d", &array[i]);
		//barray[i] = array[i];
	}
	int compare_mode = 0;
	buildHeap(n, array, &maxHeapify, compare_mode);
	insert(n, array, 9, compare_mode);
	insert(n, array, 5, compare_mode);
	insert(n, array, 8, compare_mode);
	increaseKey(array, 5, 111, compare_mode);
	printf("The heap is: heap_size: %d:: ", n);
	disp(n, array);
	if(isHeapByCompareMode(n, array, compare_mode))
		printf("Yeah! it's a heap by compare_mode: %d\n", compare_mode);
	else
		printf("Nooh! it's not a heap by compare_mode: %d\n", compare_mode);
	
	printf("Top data is: %d\n", top(n, array));
	printf("\nExtracting data from the heap: %d\n", extract(n, array, compare_mode));
	
	return 0;
}
