#include <stdio.h>
#include <stdlib.h>

#define newl puts("")
#define d	 displayNode
#define getName(x) #x

typedef struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
} Node;

Node * createNode(int data, Node *prev, Node *next)
{
	Node * new_node = (Node *) malloc(sizeof(Node));
	
	new_node->data = data;
	new_node->prev = prev;
	new_node->next = next;

	return new_node;
}

void displayNode(Node *head, int lim)
{
	int i=0;
	Node *current_node = head;
	
	while(current_node != NULL && i<lim)
	{
		printf("%d ", current_node->data);
		current_node = current_node->next;
		if(current_node==head) ++i;
	}
	newl;
}

Node * lastNode(Node *head)
{
	Node *current_node = head;
	while(current_node->next != NULL) current_node = current_node->next;
	return current_node;
}

void insertNode(Node *forth_node, Node *current_node)
{
	current_node->next = forth_node->next;
	if(forth_node->next!=NULL)	forth_node->next->prev = current_node;
	forth_node->next = current_node;
	current_node->prev = forth_node;
}

Node * swapNode(Node *head, Node *a, Node *b)
{
		Node *aprev = a->prev, *anext = a->next;
		Node *bprev = b->prev, *bnext = b->next;
		
		a->next = bnext;	if(bnext) bnext->prev = a;
		b->next = anext;	if(anext) anext->prev = b;
		
		a->prev = bprev;	if(bprev) bprev->next = a;
		b->prev = aprev;	if(aprev) aprev->next = b;
		
		if(head==a) return b;
		else if(head==b) return a;
		
		return head;
}

Node * loopLize(Node *head)
{
	Node *current_node = head;
	while(current_node->next) current_node=current_node->next;
	current_node->next = head;
	head->prev = current_node;
	
	return head;
}

Node * loopNize(Node *head)
{
	if(head==NULL) return head;
	head = loopLize(head);
	head->prev->next = NULL;
	head->prev = NULL;
	
	return head;
}

int main()
{
	Node *n1, *n2, *n3, *n4, *n5, *head;
	
	n1 = createNode(10, NULL, NULL);
	head = n1;
	
	n2 = createNode(20, NULL, NULL);
	n3 = createNode(30, NULL, NULL);
	n4 = createNode(40, NULL, NULL);
	n5 = createNode(50, NULL, NULL);
	
	insertNode(n1, n2);
	insertNode(n2, n3);
	insertNode(n3, n4);
	insertNode(n4, n5);
	d(head, 1);
	
	head = loopLize(head);
	d(head, 3);
	
	
	//d(head);
	return 0; 
}

