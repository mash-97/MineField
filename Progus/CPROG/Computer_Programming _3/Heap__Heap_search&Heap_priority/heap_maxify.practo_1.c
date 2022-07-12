#include <stdio.h>
#include <stdlib.h>
#define swap(a,b) {int c=a;a=b;b=c;}


void simulate_heap(int *heap)
{
	printf("                          %2d            \n", heap[0]);
	printf("                           |            \n");
	printf("                           |            \n");
	printf("                          %2d            \n", heap[1]);
	printf("                          / \\           \n");
	printf("                        /     \\           \n");
	printf("                      /         \\           \n");
	printf("                    /             \\           \n");
	printf("                  /                 \\           \n");
	printf("                /                     \\           \n");
	printf("              /                         \\           \n");
	printf("             /                           \\           \n");
	printf("            %2d                          %2d            \n", heap[2], heap[3]);
	printf("          /    \\                       /   \\           \n");
	printf("        /        \\                   /       \\           \n");
	printf("      /            \\               /           \\           \n");
	printf("     /              \\             /             \\           \n");
	printf("     %2d            %2d            %2d            %2d\n", heap[4], heap[5], heap[6], heap[7]);
	printf("    /  \\          /  \\          /  \\          /  \\           \n");
	printf(" /        \\    /        \\    /        \\    /        \\           \n");
	printf("%2d        %2d  %2d        %2d  %2d        %2d  %2d        %2d\n", heap[8], heap[9], heap[10], heap[11], heap[12], heap[13], heap[14], heap[15]);
	puts("");
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

void print_heap(int *heap, int heap_size)
{
	for(int i=1; i<=heap_size; i++)
		printf("%d ", heap[i]);
	puts("");
}


void max_heapify(int *heap, int heap_size, int index)
{
	int largest = index;
	
	int l = left(index);
	int r = right(index);
	
	if(l<=heap_size && heap[l] > heap[largest]) largest = l;
	if(r<=heap_size && heap[r] > heap[largest]) largest = r;
	
	if(largest != index)
	{
		swap(heap[largest], heap[index]);
		max_heapify(heap, heap_size, largest);
	}
}

void build_max_heap(int *heap, int heap_size)
{
	for(int i=heap_size/2; i>=1; i--)
		max_heapify(heap, heap_size, i);
}

void copy_array(int *a, int *b, int size)
{
	for(int i=1; i<=size; i++)
		b[i] = a[i];
}

void heap_sort(int *heap, int heap_size)
{
	for(int i=heap_size; i>=1; i--)
	{
		simulate_heap(heap);
		swap(heap[0], heap[heap_size]);
		simulate_heap(heap);
		max_heapify(heap, --heap_size, 0);
	}
}


int main()
{
	int heap[]  = {0, 19, 7, 12, 3, 5, 17, 10, 1, 2, 8, 9, 18, 19, 21, 20};
	printf("Before max_heapify: "); print_heap(heap, 15);
	
	int *a_heap = (int *) malloc(sizeof(heap));
	int a;
	printf("sizeof(heap): %ld, sizeof(a): %ld, sizeof(a_heap): %ld\n", sizeof(heap), sizeof(a), sizeof(a_heap));
	copy_array(heap, a_heap, sizeof(heap)/sizeof(int));
	max_heapify(a_heap, 15, 3);
	printf("After max_heapify: ");  print_heap(a_heap, 15);
	
	build_max_heap(heap, 15);
	printf("After build_max_heap: ");
	print_heap(heap, 15);
	
	heap_sort(heap, 15);
	printf("After calling heap_sort: ");
	print_heap(heap, 15);
	puts("");
	puts("");
	printf("Simulating...\n");
	simulate_heap(heap);
	return 0;
}
