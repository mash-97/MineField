#include <stdio.h>
#include <stdlib.h>

#define newl puts("")
#define null NULL
#define d display

typedef struct Node
{
	int data;
	struct Node * next;
} Node;

Node * createNode(int data, Node *next)
{
	Node * new_node = (Node *) malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = next;
	return new_node;
}

void insertNode(int data, Node *front_node)
{
	Node *new_node = createNode(data, front_node->next);
	front_node->next = new_node;
}

void display(Node *head)
{
	Node *current_node = head;
	
	while(current_node != NULL) 
	{
		printf("%d ", current_node->data);
		current_node = current_node->next;
	}
	
	newl;
}

int compare(const void *a, const void *b)
{
	if(((Node *)a)->data > ((Node *)b)->data) return -1;
	return 0;
}

int main()
{
	Node *n1, *head, *n2, *n3;
	
	n1 = createNode(10, null);
	head = n1;
	
	n1 = createNode(20, n1);	n2 = n1;
	n1 = createNode(30, n1);	n3 = n1;
	
	insertNode(40, n1);
	insertNode(50, n1);
	insertNode(60, n1);
	insertNode(70, n1);
	insertNode(80, n1);
	insertNode(90, n1);
	insertNode(100, n1);
	
	
	
	d(n1);
	newl;
	
	qsort(n1, 10, sizeof(Node), compare);
	d(head);
	d(n2);
	d(n3);
	d(n1);
	return 0;
}
