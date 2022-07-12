#include <stdio.h>

#define parent(index) index/2
#define left(index)   index*2
#define right(index)  index*2+1
#define swap(a,b) 	  {int c=a;a=b;b=c;}

void max_heapify(int *heap, int heap_size, int index)
{
	int l = left(index);
	int r = right(index);
	int largest = index;
	
	if(l<=heap_size && heap[l] > heap[largest]) largest = l;
	if(r<=heap_size && heap[r] > heap[largest]) largest = r;
	
	if(largest == index) return;
	swap(heap[largest], heap[index]);
	max_heapify(heap, heap_size, largest);
}

void build_max_heap(int *heap, int heap_size)
{
	for(int i=heap_size/2; i>=1; i--)
		max_heapify(heap, heap_size, i);
}

void heap_sort(int *heap, int heap_size)
{
	int heap_s = heap_size;
	for(int i=1; i<=heap_size; i++)
	{
		swap(heap[1], heap[heap_s]);
		max_heapify(heap, --heap_s, 1);
	}
}

void display(int *heap, int heap_size)
{
	for(int i=1; i<=heap_size; i++) 
		printf("%d ", heap[i]);
	puts("");
}
	
int main()
{
	int heap[] = {0,3,53,2,55,232,6,2};
	int heap_size = 7;
	display(heap, heap_size);
	
	build_max_heap(heap, heap_size);
	display(heap, heap_size);
	
	heap_sort(heap, heap_size);
	
	display(heap, heap_size);
	
	return 0;
}
