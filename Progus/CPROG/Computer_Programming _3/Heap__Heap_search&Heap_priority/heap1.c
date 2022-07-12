#include <stdio.h>
#define p(a) puts(a)

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

int isMaxHeap(int *array, int length)
{
	//p("Before");
	for(int i=length; i>1; i--) if(array[parent(i)] < array[i]) return 0;
	//p("After");
	return 1;
}

int heap[] = {0, 3, 6, 5, 1, 4, 8};

#define swap(a,b) {int c=a;a=b;b=c;}

void maxheafy(int *array, int index, int length)
{
	int l = left(index), r = right(index), largest = index;
	
	if(l <= length && array[l] > array[index]) largest = l;
	if(r <= length && array[r] > array[largest]) largest = r;
	
	if(largest == index) return;
	swap(array[index], array[largest]);
	maxheafy(array, length, largest);
}

void display(int *array, int length)
{
	for(int i=1; i<=length; i++) printf("%d ", array[i]);
	p("");
}

int main()
{
	isMaxHeap(heap, 6) ? printf("Max\n") : printf("Not Max\n");
	maxheafy(heap, 1, 6);
	isMaxHeap(heap, 6) ? printf("Max\n") : printf("Not Max\n");
	display(heap, 6);
	return 0;
}
