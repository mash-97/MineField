#include <stdio.h>
#include <stdlib.h>

int parent(int index) 
{return index/2;}

int left(int index)   
{return index*2;} 

int right(int index)  
{return index*2+1;}

typedef struct Heap H;
struct Heap
{
	int *h_data;
	int h_size;
	int h_msize;
};

H * create_heap(int max_heap_size)
{
	H * new_heap = (H *) malloc(sizeof(H));
	
	new_heap->h_data = (int *) calloc(max_heap_size+1, sizeof(int));
	new_heap->h_size = 0;
	new_heap->h_msize = max_heap_size;
	
	return new_heap;
}

void write_heap(H * heap, int * data, int size)
{
	int lim = (heap->h_msize >= size ) ? size : heap->h_msize;
	for(int i=1; i<=lim; i++)
		heap->h_data[i] = data[i-1];
	heap->h_size = lim;
}

void print_heap(H * heap)
{
	for(int i=1; i<=heap->h_size; i++)
		printf("%d ", heap->h_data[i]);
	puts("");
}


void max_heapify(H * heap, int index)
{
	int l = left(index), r = right(index);
	int largest = index;
	
	if(l<=heap->h_size && heap->h_data[largest] < heap->h_data[l]) largest = l;
	if(r<=heap->h_size && heap->h_data[largest] < heap->h_data[r]) largest = r;
	
	if(largest == index) return;
	
	int temp = heap->h_data[index];
	heap->h_data[index] = heap->h_data[largest];
	heap->h_data[largest] = temp;
	
	max_heapify(heap, largest);
}

void build_max_heap(H * heap)
{
	int lim = heap->h_size/2;
	for(int i=lim; i>=1; i--)
		max_heapify(heap, i);
}

void insert_heap_data(H * heap, int data)  // O(nlogn)
{
	if(heap->h_size > heap->h_msize)
	{
		printf("The heap is full!!!\n");
		return;
	}
	heap->h_data[++heap->h_size] = data;
	build_max_heap(heap);					// O(nlogn)
}

void inset_print(H * heap, int data)
{
	insert_heap_data(heap, data);
	printf("After calling insert_heap_data with data: %d\n", data);
	print_heap(heap);
	puts("\n");
}

// Priority Queue
int get_max(H * heap)
{
	return heap->h_data[1];
}

int extract_max(H * heap)
{
	if(heap->h_size == 0) return 0;
	int max_item = get_max(heap);
	int * size = &heap->h_size;
	heap->h_data[1] = heap->h_data[(*size)--];
	max_heapify(heap, 1);
	return max_item;
}

void outset_print(H * heap)
{
	if(heap->h_size == 0) 
	{
		printf("The heap is empty !!!\n");
		return;
	}
	int extracted_item = extract_max(heap);
	printf("After calling extract_max with data: %d          ::Heap_size: %d\n", extracted_item,
	heap->h_size);
	print_heap(heap);
	puts("\n");
}

void insert_heap_data2(H *heap, int data)
{
	if(heap->h_size > heap->h_msize) return;
	int i, p, t;
	int * s = &heap->h_size;
	
	heap->h_data[++*s] = data;
	
	i = *s;
	p = parent(i);
	
	while(i>1 && heap->h_data[i] > heap->h_data[p])
	{
		t = heap->h_data[i];
		heap->h_data[i] = heap->h_data[p];
		heap->h_data[p] = t;
			
		i = p;
		p = parent(i);
	}
}


void inset_print1(H * heap, int data)
{
	insert_heap_data2(heap, data);
	printf("After calling insert_heap_data2 with data: %d\n", data);
	print_heap(heap);
	puts("\n");
}


int main()
{
	H * aheap = create_heap(100);
	int array[] = {1,2,3,4,5};
	write_heap(aheap, array, 5);
	printf("Heap before calling build_max_heap: ");
	print_heap(aheap);
	puts("");
	
	build_max_heap(aheap);
	printf("Heap after calling build_max_heap: ");
	print_heap(aheap);
	puts("");
	
	inset_print(aheap, 6);
	inset_print(aheap, 10);
	for(int i=100; i<=1000; i+=85)
		inset_print(aheap, i);
	printf("\nHeap_size: %d, Extracted data: %d\n", aheap->h_size, extract_max(aheap));
	for(int i=1; i<=20; i++)
		outset_print(aheap);
	puts("");
	for(int i=1; i<=100; i+=2+i)
		inset_print1(aheap, i);
	return 0;
}
