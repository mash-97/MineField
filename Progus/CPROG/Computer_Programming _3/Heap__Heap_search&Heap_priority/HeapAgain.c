#include <stdio.h>
#define swap(a,b) {int c=a;a=b;b=c;}

int heap[] = {0, 7, 33, 11, 8, 9, 6, 19, 21, 1};
int heap_size = 9;

void display_heap(int *heap, int heap_size)
{
	for(int i=1; i<=heap_size; i++)
		printf("%d ", heap[i]);
	puts("");
}

int parent(int index)
{
	return index/2;
}

int left(int index)
{
	return index*2;
}

int right(int index)
{
	return index*2+1;
}

int is_max_heap(int *heap, int heap_size)
{
	for(int i=heap_size; i>1; i--)
		if(heap[i] > heap[parent(i)])
		{
			//printf("heap[%d]: %d, p:: heap[%d]: %d\n", i, heap[i], parent(i), heap[parent(i)]);
			return 0;
		}
	return 1;
}


void max_heapify(int *heap, int heap_size, int index)
{
	int l, r, largest = index;
	
	l = left(index);
	r = right(index);
	
	if(l<=heap_size && heap[largest] < heap[l]) largest = l;
	if(r<=heap_size && heap[largest] < heap[r]) largest = r;
	
	if(largest == index) return;
	
	swap(heap[largest] , heap[index]);
	max_heapify(heap, heap_size, largest);
}

void build_max_heap(int *heap, int heap_size)
{
	for(int i=heap_size/2; i>=1; i--)
		max_heapify(heap, heap_size, i);
}

void heap_sort(int *heap, int heap_size)
{
	int h=heap_size;
	printf("Inside of the heap_sort:\n");
	display_heap(heap, h);
	puts("");
	
	for(int i=heap_size; i>1; i--)
	{
		printf("::");
		display_heap(heap, h);
		swap(heap[1], heap[i]);
		display_heap(heap, h);
		heap_size--;
		max_heapify(heap, heap_size, 1);
	}
}

int main()
{
	display_heap(heap, heap_size);
	
	if(is_max_heap(heap, heap_size)) printf("Max\n");
	else printf("Non Max\n");
	
	build_max_heap(heap, heap_size);
	printf("After building max heap:\n");
	display_heap(heap, heap_size);
	puts("");
	heap_sort(heap, heap_size);
	
	display_heap(heap, heap_size);
	
	if(is_max_heap(heap, heap_size)) printf("Max\n");
	else printf("Non Max\n");
	return 0;
}
