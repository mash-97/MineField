#include <stdio.h>
#include <stdlib.h>
#define p printf
typedef struct Node
{
	int data;
	struct Node * next;
} Node;

Node createNode(int item, Node *next)
{
	Node * new_node = (Node *) malloc(sizeof(Node));
	if(new_node == NULL) { p("Error happend when creating new node!\n"); exit(1);}
	
	new_node->data = item;
	new_node->next = next;
	
	return *new_node;
}

Node * prepend(Node * head, int item)
{
	Node new_node = createNode(item, head);
	Node *n = &new_node;
	
	return n;
}

int main()
{
	Node n1, *n2, *head, *n3;
	
	n1 = createNode(10, NULL);
	head = &n1;
	
	head = prepend(head, 20);
	
	n2 = head;
	p("first data = %d\n", n2->data);
	
	n3 = n2->next;
	p("second data = %d\n", n3->data);
	
	return 0;
}
