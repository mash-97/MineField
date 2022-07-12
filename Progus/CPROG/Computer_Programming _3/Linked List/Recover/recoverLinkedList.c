#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} Node;

Node * createNode(int data, Node *next)
{
	Node *new_node = (Node *) malloc(sizeof(Node));
	
	//printf("new_node: %p, &new_node: %p\n", new_node, &new_node);
	if(new_node == NULL) 
	{
		printf("Error! on creating a new node!\n");
		exit(1);
	}
	
	new_node->data = data;
	new_node->next = next;
	
	return new_node;
}

Node * prependNode(Node *head, Node *node)
{
	//printf("2.head: %p\n", (&head));
	node->next = head;
	//printf("pre:: node->data: %d, head->data: %d, node->next->data: %d\n", node->data, (head)->data, node->next->data);
	return node;
	//printf("head->data: %d\n", (head)->data);
	//printf("3.head: %p\n", (&head));
}

Node * prependItem(Node *head, int item)
{
	Node *new_node = createNode(item, head);
	
	return new_node;
}

void loopLize(Node *head)
{
	Node *i;
	i = head;
	
	while(i->next!=NULL) i = i->next;
	
	i->next = head;
}

void displayLinkedList(Node *head, int max)
{
	Node *i;
	i = head;
	
	int count = 0;
	while(i->next != NULL && (count <= max || max == -1))
	{
		printf("%d ", i->data);
		count++;
		i = i->next;
	}
	printf("%d\n", i->data);
	//puts("");
}
/*
Node * revertize(Node *head)
{
	
}
*/
int main()
{
	Node *n1, *n2, *head, *n3;
	
	n1 = createNode(10, NULL);
	//printf("n1: %p, &n1: %p\n", n1, &n1);
	head = n1;
	//printf("1.head: %p\n", &head);
	head = prependNode(head, createNode(20, NULL));
	
	//printf("4.head: %p\n", &head);
	n2 = head;
	printf("first data = %d\n", n2->data);
	
	n3 = n2->next;
	printf("second data = %d, %d\n", n2->next->data, n3->data);
	
	printf("....................\n");
	printf("Before looplize: ");
	displayLinkedList(head, -1);
	printf("....................\n");
	loopLize(head);
	printf("After looplize: ");
	displayLinkedList(head, 5);
	
	
	return 0;
}

