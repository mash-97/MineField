#include <stdio.h>
#define swap(a,b) {int c=a;a=b;b=c;}
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

int is_max_heap(int *heap, int heap_length)
{
	for(int i=heap_length; i>1; i--)
		if(heap[i] > heap[parent(i)]) return 0;
	return 1;
}


void max_heapify(int *heap, int heap_length, int index)
{
	int l = left(index), r = right(index), largest = index;
	
	if(l<=heap_length && heap[l] > heap[index]) largest = l;
	if(r<=heap_length && heap[r] > heap[largest]) largest = r;
	
	if(largest == index) return;
	
	swap(heap[index], heap[largest]);
	max_heapify(heap, heap_length, largest);
}

void print_heap(int *heap, int heap_length)
{
	for(int i=1; i<=heap_length; i++)
		printf("%d ", heap[i]);
	puts("");
}

void build_max(int *heap, int heap_size)
{
	for(int i=heap_size/2; i>=1; i--) max_heapify(heap, heap_size, i);
}

int main()
{
	//~ int heap_size = 9;
	//~ int heap[] = {0, 19, 7, 12, 3, 5, 17, 10, 1, 2};
	
	int hheap[] = {0, 3, 6, 5, 1, 4, 8};
	int hhl = 6;
	
	//~ print_heap(heap, heap_size);
	//~ is_max_heap(heap, heap_size) ? printf("Max\n") : printf("Not Max\n");
	//~ max_heapify(heap, heap_size, 3);
	
	//~ print_heap(heap, heap_size);
	//~ is_max_heap(heap, heap_size) ? printf("Max\n") : printf("Not Max\n");
	print_heap(hheap, hhl);
	is_max_heap(hheap, hhl) ? printf("Max\n") : printf("Not Max\n");
	
	build_max(hheap, hhl);
	print_heap(hheap, hhl);
	is_max_heap(hheap, hhl) ? printf("Max\n") : printf("Not Max\n");
	return 0;
}
