#include <stdio.h>
#define MAX_SIZE 10
typedef struct
{
	int head;
	int tail;
	int data[MAX_SIZE];
} Queue;

void enqueue(Queue *q, int item)
{
	if((q->tail+1)%(MAX_SIZE+1) == q->head) printf("Queue is full!\n");
	//if(q->tail==q->head) printf("Queue is full!\n");
	else 
	{
		q->data[q->tail] = item;
		q->tail = (q->tail+1)%(MAX_SIZE+1);
	}
}

int dequeue(Queue *q)
{
	int item = -1;
	if(q->head==q->tail) printf("Queue is empty!\n");
	else
	{
		item = q->data[q->head];
		q->head = (q->head+1)%(MAX_SIZE+1);
	}
	return item;
}

void displayQueue(Queue que)
{
	for(int i=que.head; i<que.tail; i++) printf("%d ", que.data[i]);
	puts("");
}

int main()
{
	int item;
	Queue q;
	q.head = 0, q.tail = 0;
	
	enqueue(&q, 1);
	printf("tail = %d\n", q.tail);
	enqueue(&q, 2);
	printf("tail = %d\n", q.tail);
	enqueue(&q, 3);
	printf("tail = %d\n", q.tail);
	enqueue(&q, 4);
	printf("tail = %d\n", q.tail);
	enqueue(&q, 5);
	printf("tail = %d\n", q.tail);
	enqueue(&q, 6);
	printf("tail = %d\n", q.tail);
	puts("");
	displayQueue(q);
	puts("");
	printf("begining head = %d\n", q.head);
	item = dequeue(&q);
	printf("item = %d, head = %d\n", item, q.head);
	item = dequeue(&q);
	printf("item = %d, head = %d\n", item, q.head);
	item = dequeue(&q);
	printf("item = %d, head = %d\n", item, q.head);
	item = dequeue(&q);
	printf("item = %d, head = %d\n", item, q.head);
	item = dequeue(&q);
	printf("item = %d, head = %d\n", item, q.head);
	item = dequeue(&q);
	printf("item = %d, head = %d\n", item, q.head);
	
	return 0;
}

		
	
