#include <stdio.h>
#include <stdlib.h>

#define newl puts("")
#define d displayNode

typedef struct Node
{
	int data;
	struct Node *next;
} Node;

Node * createNode(int data, Node *next)
{
	Node *new_node = (Node *) malloc(sizeof(Node));
	
	new_node->data = data;
	new_node->next = next;
	
	return new_node;
}

Node * prepend(int data, Node *head)
{
	if(head == NULL) return createNode(data, NULL);
	
	return createNode(data, head);
}

Node * prependNode(Node *node, Node *head)
{
	if(head==NULL || node==NULL) return node;
	node->next = head;
	
	return node;
}

Node * lastNode(Node *head)
{
	Node *current_node = head;
	while(current_node->next) current_node = current_node->next;
	return current_node;
}

Node * beforeNode(Node *head, Node *node)
{
	if(node==head || node==NULL) return NULL;
	
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

Node * isortOnNode(Node *head)
{
	Node *i, *j, *temp;
	
	i = head->next;
	while(i!=NULL)
	{
		temp = i;
		
		j = beforeNode(head, i); printf("%d -> %d\n", j->data, i->data);
		i = i->next;			 printf("i->next : %d\n", i->data);
		
		while(beforeNode(head, j)!=NULL && j->data > temp->data)
		{
			head = swapNode(head, j, j->next);
			j = beforeNode(head, j);
		}
		if(j->data > j->next->data) head = swapNode(head, j, j->next);
		head = swapNode(head, j->next, temp);
	}
	return head;
}

int main()
{
	Node *n1, *n2, *head, *n3, *n4;
	
	n1 = createNode(10, NULL);
	head = n1;
	
	n4 = createNode(30, NULL);
	head = prependNode(n4, head);
	head = prepend(40, head);
	
	n2 = createNode(20, NULL);
	
	head = prependNode(n2, head);
	n3 = createNode(50, NULL);
	head = prependNode(n3, head);
	d(head, 1);
	
	head = swapNode(head, n4, n1);
	d(head, 1); printf("......\n");
	
	head = isortOnNode(head);
	d(head, 1);
	return 0;
}
