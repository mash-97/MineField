#include <stdio.h>
#define MAX_SIZE 3
#define FULL_QUE 0
#define ENQUED	1
#define EMPTY_QUE -2147483648

typedef struct q Que;
struct q
{
	int head;
	int tail;
	int count;
	int data[MAX_SIZE];
};

int menqueue(Que *que, int data)
{
	if(que->count < MAX_SIZE)
	{
		que->data[que->tail++] = data;
		que->count++;
		
		if(que->tail == MAX_SIZE) que->tail = 0;
		return ENQUED;
	}
	else 
	{
		printf("The queue is full!!!\n");
		return FULL_QUE;
	}
}

int mdequeue(Que *que)
{
	if(que->count == 0)
	{
		printf("Queue is empty!!!\n");
		return EMPTY_QUE;
	}
	else
	{
		int item = que->data[que->head++];
		que->count--;
		if(que->head == MAX_SIZE) que->head = 0;
		return item;
	}
}

int enqueue(Que *queue, int data)
{
	if(queue->tail+1 == queue->head)
	{
		printf("The queue is full!\n");
		return  FULL_QUE;
	}
	
	else 
	{	
		queue->data[queue->tail] = data;
		queue->tail = (queue->tail+1) % (MAX_SIZE+1);
	}
	
	return ENQUED;
}

int dequeue(Que *queue)
{
	int data;
	
	if(queue->head == queue->tail) 
	{
		printf("The queue is empty!\n");
		return EMPTY_QUE;
	}
	else
	{
		data = queue->data[queue->head];
		queue->head = (queue->head+1) % MAX_SIZE+1;
	}
	return data;
}


int main()
{
	Que que;
	
	que.head = 0;
	que.tail = 0;
	que.count = 0;
	
	int number;
	char act;
	
	while(printf("Enter action:(e | d): ") && scanf(" %c", &act))
	{
		if(act == 'e') 
		{
			printf("Data:: ");	scanf("%d", &number);
			if(enqueue(&que, number) == ENQUED) printf("%d is enqueued\n", number);
		}
		else
		{
			if((number = dequeue(&que))!=EMPTY_QUE) printf("Dequeued data:: %d\n", number);
			else printf("Warning:: ");
		}
		printf("\nque.head: %d, que.tail: %d\n\n\n", que.head, que.tail);
	}
	
	return 0;
}
	
	
	
