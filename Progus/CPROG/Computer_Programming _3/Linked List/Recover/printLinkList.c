#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define p printf
#define pll print_linked_list

typedef struct Node
{
	int data;
	struct Node * next;
} Node;

Node * createNode(int data, Node *next)
{
	Node *new_node = (Node *) malloc(sizeof(Node));
	
	if(new_node == NULL) { p("Error! on creating new node!\n"); exit(1);}
	
	new_node->data = data;
	new_node->next = next;
	
	return new_node;
}

Node *prepend(int data, Node *head)
{
	Node *new_node = createNode(data, head);
	
	return new_node;
}

Node *append(int data, Node *head)
{
	Node *new_node = createNode(data, NULL);
	
	if(head==NULL) return new_node;
	
	Node *current_node = head;
	
	while(current_node->next != NULL) current_node = current_node->next;
	
	current_node->next = new_node;
	
	return head;
}

Node *joinAt(int pos, int data, Node * head)
{
	if(pos==0 || head == NULL)	return createNode(data, head);
	
	Node * before_node = head;
	Node * current_node = head->next;
	
	int i=1;
	while(current_node != NULL )	
	{
		if(i==pos)	break;
		before_node = current_node;
		current_node = current_node->next;
		++i;
	}
	
	Node * new_node = createNode(data, current_node);
	before_node->next = new_node;
	
	return head;
}

void print_linked_list(Node *head)
{
	Node *node = head;
	
	while(node!=NULL){ p("%d ", node->data); node = node->next;}
	puts("");
}

int count(Node *head)
{
	Node *node = head;
	int total_nodes;
	
	for(total_nodes = 0; node != NULL; node = node->next, ++total_nodes);
	
	return total_nodes;
}

Node * search(int data, Node *head)
{
	Node * current_node = head;
	
	while(current_node != NULL)
	{
		if(current_node->data == data) break;
		current_node = current_node-> next;
	}
	
	return current_node;
}

int main()
{
	clock_t s, e;
	Node *n1 = NULL, *head = NULL;
	
	n1 = createNode(10, NULL);
	
	head = n1;
	head = append(20, head);
	head = prepend(5, head);
	head = joinAt(2, 15, head);
	head = append(60, head);
	for(int i=1; i<=100000; i++) head = append(i, head);
	s = clock();
	Node *searched_node = search(99999, head);
	e = clock();
	
	if(searched_node != NULL) p("%d is found in the node! time: %.6lf\n", searched_node->data, (double)((e-s)/CLOCKS_PER_SEC));
	
	p("Total nodes: %d\n", count(head));
	//pll(head);
	return 0;
}
