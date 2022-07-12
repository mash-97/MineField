#include <stdio.h>
#include <stdlib.h>

#define newl puts("")

typedef struct Node
{
	int data;
	struct Node *next;
} Node;

void displayNode(Node *head)
{
	while(head)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	newl;
}

Node * createNode(int data, Node *next)
{
	Node *new_node = (Node *) malloc(sizeof(Node));
	
	new_node->data = data;
	new_node->next = next;
	
	return new_node;
}

Node * prependNode(Node *node, Node *head)
{
	if(head==NULL) return node;
	node->next = head;
	
	return node;
}

Node * appendNode(Node *node, Node *head)
{
	if(head==NULL) return node;
	
	Node *current_node = head;
	while(current_node->next) current_node = current_node->next;
	
	current_node->next = node;
	node->next = NULL;
	
	return head;
}

Node * beforeNode(Node *head, Node *node)
{
	if(node==head) return NULL;
	
	Node * current_node = head;
	while(current_node)
	{
		if(current_node->next==node) return current_node;
		current_node = current_node->next;
	}
	return NULL;
}

Node * swapNode(Node *head, Node *a, Node *b)
{
	if(a==NULL || b==NULL || a==b) return head;
	
	Node *aprev = beforeNode(head, a);
	Node *anext = a->next;
	Node *bprev = beforeNode(head, b);
	Node *bnext = b->next;
	
	if(anext==b)
	{
		b->next = a;
		a->next = bnext;
		if(aprev) aprev->next = b;
	}
	else if(bnext==a)
	{
		a->next = b;
		b->next = anext;
		if(bprev) bprev->next = a;
	}
	else 
	{
		if(aprev) aprev->next = b;
		if(bprev) bprev->next = a;
		
		b->next = anext;
		a->next = bnext;
	}
	if(a==head) return b;
	else if(b==head) return a;
	return head;
}

Node * reverseList(Node *head)
{
	Node *a, *b;
	a = head;
	b = beforeNode(a, NULL);
	
	while(b!=a->nex
	return head;
}

int main()
{
	Node *a, *b, *c, *head;
	a = createNode(10, NULL);
	head = a;
	
	b = createNode(20, NULL);
	head = prependNode(b, head);
	
	c = createNode(30, NULL);
	head = prependNode(c, head);
	
	head = prependNode(createNode(40, NULL), head);
	
	displayNode(head);
	
	head = reverseList(head);
	displayNode(head);
	
	return 0;
}
	
